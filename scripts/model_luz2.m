clc
clear all
close all

%% get model response

K1 = 20
K2 = 0

%get measurement data
type = "10";
path = "../data/data/lab2/sin" + type + "_resp";
src = open (path + '.mat');

u = src.PD_C.signals(4).values;
vs = src.PD_C.signals(2).values;
x = src.PD_C.signals(1).values;
t = src.PD_C.time;
i = src.PD_C.signals(3).values;

%crop beginning
bi = 200;
x = x(bi:end,2);
u = u(bi:end);
v = vs(bi:end,1);
v2 = vs(bi:end,3);
t = t(bi:end) - t(bi);

x0 = x(1);
v0 = v(1);
v20 = v2(1);
e0 = (v(1+1)-v(1))/(t(end)-t(end-1));
i0 = i(bi,1);

T = t(end);
velocity_in = [t v2];

open ../models/model_luz.slx;
sim ../models/model_luz.slx;

x_mod = ans.position.signals.values;
v_mod = ans.velocity.signals.values;
t_mod = ans.tout;

figure(1);

subplot(3,1,1);
hold on;
plot(t, x, 'k');
plot(t_mod, x_mod, 'b--');
grid;
title("Position");
xlabel("Time [s]");
ylabel("Position [rad]");
legend("object", "model");

subplot(3,1,2);
hold on;
plot(t, v, 'k');
plot(t, v2, 'r')
plot(t_mod, v_mod, 'b--');
grid;
title("Velocity");
xlabel("Time [s]");
ylabel("Velocity [rad/s]");
legend("object","tacho", "model");

subplot(3,1,3);
plot(t, u, 'r');
hold on;
grid;
title("Input");
xlabel("Time [s]");
ylabel("Value");

%% plot modelling error

errx = abs(x_mod - x);
errv = abs(v_mod - v);

figure(2)
subplot(2,1,1);
plot(t,errx, "r-");
xlabel("Time[s]");
ylabel("Error value [%]");
title("Position error");

subplot(2,1,2);
plot(t, errv, "r-");
xlabel("Time[s]");
ylabel("Error value [%]");
title("Velocity error");







