clc 
clear all
close all

name = "sin0-5_resp";
path = "graphs/data/lab2/" + name + ".mat";

src = open (path);

endf = 3;

u = src.PD_C.signals(4).values;
vs = src.PD_C.signals(2).values;
t = src.PD_C.time;

bi = 100;
u = u(bi:end);
v = vs(bi:end,1);
t = t(bi:end);
vt = vs(bi:end,3);

figure(1);
%velocity
plot(t,v,'k');
hold on;
plot(t,vt,'b');
legend("enc", "tacho");