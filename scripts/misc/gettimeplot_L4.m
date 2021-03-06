clc 
clear all
close all

name = "pwm_low_freq_silnik_walec";
path = "../data/data/lab4/" + name + ".mat";

src = open (path);

R = 3.964
ke = 1.4e-3

u = src.PD_C.signals(4).values;
vs = src.PD_C.signals(2).values;
is = src.PD_C.signals(3).values;
t = src.PD_C.time;

bi = 450;
u = u(bi:end);
v = vs(bi:end,1);
t = t(bi:end);

[bf, af] = butter(5, 0.7);
[bf2, af2] = butter(5, 0.1);

i = is(bi:end,1);
i = filtfilt(bf,af,i)

sfreq = 1/(t(end)-t(end-1))
fi = fft(i(1:500));
mag = abs(fi(1:end/2));

figure(2);
plot(mag);

di = diff(i)*sfreq;
di = [0; di];
di = filtfilt(bf2,af2,di);

figure(1);
%velocity
subplot(2,1,1);
hold on;
plot(v,'k');
plot(u,'b--');
grid;
legend("velocity","input");
subplot(2,1,2);
hold on;
plot(i,"r");
plot(di,'r--');
legend("intensity", "intensity deriv");

ia = i - ke/R*v 


figure(3);
hold on;
grid;
plot(ia)

% for i = 1:9
%     
%     Lpacket = L(640*i-620:640*i-540);
%     plot(Lpacket);
%     Lf(i) = mean(Lpacket)
% end
