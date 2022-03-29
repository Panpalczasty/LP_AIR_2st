clc
clear all
close all

type = "strefa-martwa";
path = "graphs/data/lab3/ramp/stat_" + type + "_ramp_0-2_";

up = open (path + "up.mat");
down = open (path + "down.mat");

u_up = 100*up.PD_C.signals(4).values;
v_up = up.PD_C.signals(2).values;
t_up = up.PD_C.time;

u_down = 100*down.PD_C.signals(4).values;
v_down = down.PD_C.signals(2).values;
t_down = down.PD_C.time;

%intensity filtration?

%drop inital values
u_up = u_up(t_up > 5);
v_up = v_up(t_up > 5);

u_down = u_down(t_down > 5);
v_down = v_down(t_down > 5);

%make the goddamn static char plot
figure(1);
hold on;
grid;
plot(u_up, v_up(:,1), 'k-');
plot(u_down, v_down(:,1), 'r-');
xlabel("Input [%]");
ylabel("Angular velocity [rad/s]");
title("Static - " + type);

saveas(1, "plots/ramp/" + type + ".png");

s0 = 254.89;
V0 = 12;
R = 1.977;
s = getSlope(u_up, v_up);
Ki = V0/R*(1/s - 1/s0);

saveSlope(Ki, type);

function slope = getSlope(u, v)
    us = u(u > 20 & u < 99);
    vs = v(u >20 & u < 99);
    du = diff(us);
    dv = diff(vs);
    slope = 100*mean(dv./du);
end

function saveSlope(slope, name)
    f = fopen("stats/ramp_ks.txt", 'a');
    fprintf(f,"-------------------\n");
    fprintf(f,"Slope - %s - ", name);
    fprintf(f,"%.5f \n", slope);
    fclose(f);
end