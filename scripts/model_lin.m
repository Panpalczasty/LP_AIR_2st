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

dz_width = 0.2; %amps
a = 0.975;

%define dem matrices
A = [0  1  0    0;
     0 -5  4.5  0;
     0  0 -D/J  a/J;
     0  0 -ke/L -R/L];

B = [0;0;0;U/L];
C = [1 0 0 0];

%define smaller matrices
Aw = [-5  4.5  0;
       0 -D/J  a/J;
       0 -ke/L -R/L];
Bw = [0;0;U/L];
Cw = [1 0 0];

sysw = ss(Aw,Bw,Cw,0);
syslin = ss(A,B,C,0);
[Lw,Mw] = ss2tf(Aw,Bw,Cw,0)
Gwd = c2d(tf(Lw,Mw), 0.1)

[Lm,Mm] = ss2tf(A,B,C,0);
syscont = tf(Lm,Mm);

%proportional gain 
%PD is tuned to remove the biggest eigval from A
Kp = 0.01;

%deadbeat design 
Tp = 0.15;
Gd = c2d(syscont, Tp);
[Bm, Am] = tfdata(Gd,'v');
P = flipud(Am);
Q = -flipud(Bm);
Q(1) = sum(Bm);

%Triple root locus regulator 
%For simplification - 

%desired locus
l0  = 10;

%matrix params
a = 5
b = 4.5
c = 1/J(D + ke/R)
d = a/J*U/R 

K1 = 1/(b*d)*(l0^3);
K2 = 1/(b*d)*(-3*l0^2 + 3*l0*a - a^2);
K3 = 1;


%% get model response

% %get measurement data
% type = "0-2";
% path = "../data/data/lab2/sin" + type + "_resp";
% src = open (path + '.mat');
% 
% u = src.PD_C.signals(4).values;
% vs = src.PD_C.signals(2).values;
% x = src.PD_C.signals(1).values;
% t = src.PD_C.time;
% i = src.PD_C.signals(3).values;
% 
% %crop beginning
% bi = 50;
% x = x(bi:end,2);
% u = u(bi:end);
% v = vs(bi:end,1); %encoder
% v2 = vs(bi:end,3); %tacho
% t = t(bi:end) - t(bi);
% 
% x0 = x(1);
% v0 = v(1);
% vo0 = v2(1);
% i0 = i(bi,1);
% 

open ../models/model_linear.slx;
sim ../models/model_linear.slx;

t_mod = ans.tout;
y_mod = ans.output;
tw_mod = ans.input.time;
w_mod = ans.input.signals.values(:,:);

u_mod = ans.control.signals.values;
tu_mod = ans.control.time;

%% plots
f = figure(1);
%f.Position = [600 0 1000 900];

%TODO
%velocity plots
subplot(2,1,1);
hold on;
plot(t_mod, y_mod, 'b-', "LineWidth", 1.5);
plot(tw_mod, w_mod, 'k--');
%plot(t, v2, 'r')
grid;
title("Model output");
xlabel("Time [s]");
ylabel("Position [rad]");
legend("model output", "input signal");

%input plots
subplot(2,1,2);
plot(tu_mod, u_mod, 'k');
hold on;
grid;
title("Control");
%yticks([0,0.2,0.4,0.6,0.8,1])
%yticklabels(["0%", "20%", "40%", "60%", "80%", "100%"])
xlabel("Time [s]");
ylabel("Value");
%xlim([0 floor(t(end))]);
  
