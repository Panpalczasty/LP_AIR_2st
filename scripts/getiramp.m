clc
clear all
close all

type = "silnik";
path = "graphs/data/lab3/ramp/stat_" + type + "_ramp_0-2_";

up = open (path + "up.mat");
down = open (path + "down.mat");

%get filter
filt = fir1(200, 0.01, 'low');

u_up = 100*up.PD_C.signals(4).values;
i_up = up.PD_C.signals(3).values;
t_up = up.PD_C.time;

u_down = 100*down.PD_C.signals(4).values;
i_down = down.PD_C.signals(3).values;
t_down = down.PD_C.time;

%intensity filtration?
i_up = filtfilt(filt, 1, i_up);
i_down = filtfilt(filt, 1, i_down);

%drop inital values
u_up = u_up(t_up > 5);
i_up = i_up(t_up > 5);

u_down = u_down(t_down > 5);
i_down = i_down(t_down > 5);

%make the goddamn static char plot
figure(1);
hold on;
grid;
plot(u_up, i_up(:,1), 'k-');
plot(u_down, i_down(:,1), 'k-')
xlabel("Input [%]");
ylabel("Intensity [A]");
title("Static intensity- " + type);

saveas(1, "plots/ramp/" + type + "_int.png");

K = getSlope(u_up, i_up)
saveSlope(K, type);

figure(2);
semilogy(abs(fi),'k-');

function slope = getSlope(u, v)
    us = u(u > 20 & u < 99);
    vs = v(u > 20 & u < 99);
    du = diff(us);
    dv = diff(vs);
    slope = 100*mean(dv./du);
end

function saveSlope(slope, name)
    f = fopen("stats/iramp_slopes.txt", 'a');
    fprintf(f,"-------------------\n");
    fprintf(f,"Slope - %s - ", name);
    fprintf(f,"%.2f \n", slope);
    fclose(f);
end

