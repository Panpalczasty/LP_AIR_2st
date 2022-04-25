clc 
clear all
close all

name = "sin0-5_resp";
path = "../data/data/lab2/" + name + ".mat";

src = open (path);

endf = 3;

u = src.PD_C.signals(4).values;
vs = src.PD_C.signals(3).values;
t = src.PD_C.time;

bi = 100;
u = u(bi:end);
v = vs(bi:end,1);
t = t(bi:end);
vt = vs(bi:end,2);

v = decimate(v,10);
vt = decimate(vt,10);

figure(1);
%velocity
plot(v,'k');
hold on;
plot(vt,'b');
legend("i1", "i2");