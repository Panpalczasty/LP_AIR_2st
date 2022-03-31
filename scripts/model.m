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

G = tf(Lo,Mo)

dz_width = 0.2; %amps
b_width = 1.9*pi; %rads

%% get model response

%get measurement data
type = "20";
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
e0 = (v(1+1)-v(1))/(t(end)-t(end-1));
i0 = i(bi,1);

T = t(end);
u_tosim = [t u];

open ../models/model_full.slx;
sim ../models/model_full.slx;

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












