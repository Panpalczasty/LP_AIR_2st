clc
clear all
close all
%% define model

% calc your D's
si = [253.74 254.89 212.46 251.93 253.74];
c2 = 0.155; 
R = 2.02;
ke = (1 - c2*R)/si(2);
L = 0.5e-3;
U = 12.95;

Di = (1./si - ke/U)*U/R;

% and then your J's
f45s = [0.6568 0.6270 0.5747 0.1065 0.5044];
w45s = 2*pi*f45s;

Ji = 1./w45s .* (ke./(R+L*w45s) + (R-L*w45s)./(R+L*w45s).*Di);

% calc other params
J = sum(Ji) - 4*Ji(2);
D = sum(Di) - 4*Di(2);

Lo = U;
Mo = [L*J L*D+R*J R*D+ke];

G = tf(Lo,Mo);

dz_width = 0.2; %amps
dz_lin = 0.975;

%% get model response

%get measurement data
type = "0-2";
path = "../data/data/lab2/sin" + type + "_resp";
src = open (path + '.mat');

u = src.PD_C.signals(4).values;
vs = src.PD_C.signals(2).values;
x = src.PD_C.signals(1).values;
t = src.PD_C.time;
i = src.PD_C.signals(3).values;

figure(3);
plot(t, i(:,1));
grid;

%crop beginning
bi = 50;
x = x(bi:end,2);
u = u(bi:end);
v = vs(bi:end,1); %encoder
v2 = vs(bi:end,3); %tacho
t = t(bi:end) - t(bi);

x0 = x(1);
v0 = v(1);
vo0 = v2(1);
i0 = i(bi,1);

T = t(end);
u_tosim = [t u];
v_tosim = [t v];

open ../models/model_full.slx;
sim ../models/model_full.slx;

x_mod = ans.position.signals.values;
v_mod = ans.velocity.signals.values;
t_mod = ans.tout;
err = ans.error;
vref = ans.vref;

%% calcs
%TODO
N = length(err);

% mean relative error - says nothing here 
% mre = 1/N*sum(abs(err+1)./abs(vref+1));

% mean abs err
mabs = 1/N*sum(abs(err))

% mean error
merr = N*mabs* 1./sum(abs(vref))

acc = 100*(1-merr)

% root mean square error 
rms = sqrt(1/N*sum(err.^2))

%% plots
f = figure(1);
f.Position = [600 0 1000 900];

%TODO
%velocity plots
subplot(3,1,1);
hold on;
plot(t_mod, v_mod, 'b-', "LineWidth", 1.5);
plot(t, v, 'k--');
%plot(t, v2, 'r')
grid;
title("Velocity");
xlabel("Time [s]");
ylabel("Velocity [rad/s]");
legend("object", "model");
xlim([0 floor(t(end))])

%input plots
subplot(3,1,2);
plot(t, u, 'k');
hold on;
grid;
title("Input");
xlabel("Time [s]");
ylabel("Value");
xlim([0 floor(t(end))])
ylim([-1.2 1.2]);

%velocity error plot
subplot(3,1,3);
plot(t_mod, err, 'k')
hold on;
title("Error");
xlabel("Time [s]");
ylabel("Value");
grid;
xlim([0 floor(t(end))])
%ylim([-50 50]);
%%

txt = sprintf('Mean absolute error: %.2f', mabs) + " rad/s";
txt2 = sprintf('RMS: %.2f', rms) + " rad/s";

%text(1,45,txt, "FontSize", 12);
%text(4,45,txt2, "FontSize", 12);

saveas(1,"../plots/model/model_" + type + ".png");

f = fopen("../stats/stats_model.txt", 'a');
fprintf(f,"-------------------\n");
fprintf(f,"type,mabs,rms,merr,acc\n");
fprintf(f,"%s,%.2f,%.2f,%.2f,%.2f\n", type, mabs, rms, merr, acc);
fclose(f);




