clc
clear all
close all

% get regulator quality assessment
% % regtypes PD/LQR/MPC/DB/LOC3/LOC4
%regtype = "LOC3";
%enable = true;
%regtype = "PD";
%enable = false;
regtype = "DB";
enable = true;

%% get object signals

name = regtype + "_resp";
path = "../../data/data/lab6/" + name + ".mat";
src = open (path);

% get & crop signals
bi = 200;
ei = 600;
u = src.PD_C.signals(4).values(bi:ei);     %control
xref = src.PD_C.signals(1).values(bi:ei,1);%reference position
x = src.PD_C.signals(1).values(bi:ei,2);   %output position
ve = src.PD_C.signals(2).values(bi:ei,1);  %enc velocity
vt = src.PD_C.signals(2).values(bi:ei,3);  %tacho velocity
i = src.PD_C.signals(3).values(bi:ei,1);   %intensity 
t = src.PD_C.time(bi:ei);                  %time vector

bi = 100;
u = src.PD_C.signals(4).values(bi:end);     %control
xref = src.PD_C.signals(1).values(bi:end,1);%reference position
x = src.PD_C.signals(1).values(bi:end,2);   %output position
ve = src.PD_C.signals(2).values(bi:end,1);  %enc velocity
vt = src.PD_C.signals(2).values(bi:end,3);  %tacho velocity
i = src.PD_C.signals(3).values(bi:end,1);   %intensity 
t = src.PD_C.time(bi:end);                  %time vector

t = t - t(1);

err = xref-x;

%% choose model for simulation & get model response

%propagate output signal thru simulation 
xsim = [t xref];
T = t(end);

simpath = "../../models/regmodels/model_" + regtype + ".slx";

%simulate 
open (simpath);
sim (simpath);

tmod = ans.time;
umod = ans.control;
xmod = ans.output;

%% calculate regulation QA params

% regulation time (2%)
%[~, locs] = findpeaks(-abs(err-0.02*x(end)));
%regtime = t(locs(end));
%regerr = err(locs(end));
[peaks, locs] = findpeaks(-abs(err-0.02*x(end)));
regtime = t(locs(end));
regerr = peaks(end);

% energy coefficient
dt = t(2)-t(1);
intu = dt*sum(u.^2);

% int of square of error
err2 = err(1:locs(end));
intx = dt*sum(err2.^2);
% int of square of error 
intx = dt*sum(err.^2)/(xref(end)^2);

%% regulation params of model

% regulation time (2%)
%[~, locs] = findpeaks(-abs(err-0.02*x(end)));
%regtime = t(locs(end));
%regerr = err(locs(end));
[peaks, locs] = findpeaks(-abs((xref-xmod)-0.02*xmod(end)));
regtimem = t(locs(end));
regerrm = peaks(end);

% energy coefficient
dt = t(2)-t(1);
intum = dt*sum(umod.^2);

% int of square of error
err2 = err(1:locs(end));
% int of square of error 
intxm = dt*sum((xmod-xref).^2)/(xref(end)^2);

%% plot comparison plot
f = figure(1);
f.Position = [0 0 1200 600];

% Position & error plots
subplot(2,2,1);
hold on;
grid;
plot(t, x, 'b-', "LineWidth", 1.5);
plot(tmod, xmod, 'k-');
plot(t, xref, 'k--');
plot(t, err, 'r-');
plot(regtime, regerr, "kx")
title("Model output");
xlabel("Time [s]");
ylabel("Position [rad]");
legend("object output","model output", "input signal","error","regpoint");
%ylim([-1 180]);

% velocity
subplot(2,2,3);
hold on;
grid;
plot(t, vt, 'r-', "LineWidth", 1.5);
plot(t, ve, 'b-', "LineWidth", 1.5);
title("Velocity");
xlabel("Time [s]");
ylabel("Position [rad/s]");
legend("Velocity - motor", "Velocity - encoder");

% intensity
subplot(2,2,2);
hold on;
grid;
plot(t, i, 'k-', "LineWidth", 1.5);
title("Current");
xlabel("Time [s]");
ylabel("Current [A]");

%input plots
subplot(2,2,4);
hold on;
grid;
plot(t, u, 'k-', 'LineWidth', 1.5);
title("Control");
xlabel("Time [s]");
ylabel("Value");
ylim([-0.6 0.6]);

%% save outputs

if enable
    saveStats(regtype, intu, intx, regtime);
    plotpath = "../plots/Regulator analysis/" + regtype + "_QA_plot.png";
    plotpath = regtype + "_QA_plot.png";
    saveas(1, plotpath, "png");
end

function saveStats(regtype, intu, intx, regtime)
    path = "../../stats/regstats/" + regtype + ".txt";
    g = fopen(path, 'a');
    fprintf(g,"-------------------\n");
    fprintf(g, regtype);
    fprintf(g, "\n");
    fprintf(g,"Regulation time (0.02) = ");
    fprintf(g,"%.2f [s]\n", regtime);

    fprintf(g,"Integral of square of error = ");
    fprintf(g,"%.3f \n", intx);

    fprintf(g,"Integral of square of control = ");
    fprintf(g,"%.3f \n", intu);

    fclose(g);
    path = "../../stats/regstats/" + regtype + ".txt"
    f = fopen(path, 'a');
    fprintf(f,"-------------------\n");
    fprintf(f, regtype);
    fprintf(f, "\n");
    fprintf(f,"Regulation time (0.02) = ");
    fprintf(f,"%.2f [s]\n", regtime);

    fprintf(f,"Integral of square of error");
    fprintf(f,"%.3f \n", intx);

    fprintf(f,"Integral of square of control");
    fprintf(f,"%.3f \n", intu);

    fclose(f);
end



