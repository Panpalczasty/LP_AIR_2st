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
J = (sum(Ji) - 4*Ji(2))/2;
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
Tp = 1;
Gd = c2d(syscont, Tp);
[Bm, Am] = tfdata(Gd,'v');
P = flipud(Am);
Q = -flipud(Bm);
Q(1) = sum(Bm);

%Triple root locus regulator 
%For simplification - 

%desired locus
l0  = 5;

%big version non-viable -- large intensity feedback
%using ackermann formula

%controllability matrix 
C = [B A*B A^2*B A^3*B];
%desired polynomial
P = A^4 + 4*A^3*l0 + 6*A^2*l0^2 + 4*A*l0^3 + l0^4*eye(4,4);

Kack = [0 0 0 1]*C^(-1)*P

%loci for small version 
a = 5;
b = 4.5;
c = 1/J*(ke/R+D);
d = a/J*U/R;
K1 = 1/(b*d)*(l0^3);
K2 = 1/(b*d)*(3*l0^2-3*l0*a+a^2);
K3 = 1/d*(-a-c+3*l0);
K = [K1 K2 K3]

Ar = [0 1 0; 0 -a b; 0 0 -c];
Br = [0;0;d];

% Cr = [Br Ar*Br Ar^2*Br];
% Pr = Ar^3 + 3*Ar^2*l0 + 3*Ar*l0^2 + l0^3*eye(3,3);
% Ksmul = [0 0 1]*Cr^(-1)*Pr

smallsys = ss(Ar, Br, [1 0 0], 0);

%% get model response

open ../models/model_locreg.slx;
sim ../models/model_locreg.slx;

t_mod = ans.tout;
y_mod = ans.output;
tw_mod = ans.input.time;
w_mod = ans.input.signals.values(:,:);

u_mod = ans.control.signals.values;
tu_mod = ans.control.time;

x_mod = ans.state;

%% plots
f = figure(1);
f.Position = [0 0 1200 600];

subplot(2,2,1);
hold on;
grid;
plot(t_mod, y_mod, 'b-', "LineWidth", 1.5);
plot(tw_mod, w_mod, 'k--');
title("Model output");
xlabel("Time [s]");
ylabel("Position [rad]");
legend("model output", "input signal");
ylim([-1 180]);

subplot(2,2,3);
hold on;
grid;
plot(t_mod, x_mod(:,3), 'r-', "LineWidth", 1.5);
plot(t_mod ,x_mod(:,2), 'b-', "LineWidth", 1.5);
title("Velocity");
xlabel("Time [s]");
ylabel("Position [rad/s]");
legend("Velocity - motor", "Velocity - encoder");

subplot(2,2,2);
hold on;
grid;
plot(t_mod, x_mod(:,4), 'k-', "LineWidth", 1.5);
title("Intensity");
xlabel("Time [s]");
ylabel("Intensity [A]");

%input plots
subplot(2,2,4);
hold on;
grid;
plot(tu_mod, u_mod, 'k', 'LineWidth', 1.5);
title("Control");
%yticks([0,0.2,0.4,0.6,0.8,1])
%yticklabels(["0%", "20%", "40%", "60%", "80%", "100%"])
xlabel("Time [s]");
ylabel("Value");
ylim([-0.6 0.6]);
%xlim([0 floor(t(end))]);
  




