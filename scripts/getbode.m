clc
clear all
close all

type = "strefa-martwa";
path = "graphs/data/lab3/chirp/stat_" + type + "_chirp_0-1_do_3_hz";

src = open (path + '.mat');

dec = 5;
fmin = 0.1;

u = src.PD_C.signals(4).values;
ve = src.PD_C.signals(2).values(:,1);
vt = 2*src.PD_C.signals(2).values(:,2);
t = src.PD_C.time;


%% Bode magnitude data

[vpeaks, i]  = findpeaks(ve);
di = diff(i);
fmax = 1/(t(end) - t(end - di(end)))

tpi = t(i);
fpi = (fmax-fmin)/(t(end))*tpi;

vt = decimate(vt, dec);
t = decimate(t, dec);

[vtacho, i] = findpeaks(vt);
tvt = t(i);
fvt = (fmax-fmin)/(t(end))*tvt;

figure(1);
Mp = 20*log10(vpeaks);
Mv = 20*log10(vtacho);

semilogx(fpi, Mp, 'k-')
hold on;
semilogx(fvt,Mv, 'b-')
grid;
xlim([fmin fmax]);
ylim([Mv(end)-5 55]);
xlabel("Frequency [Hz]");
ylabel("Magnitude [dB]");
title("Bode magnitude plot - " + type + " chirp");
legend("enc", "tacho");

saveas(1, "plots/bode2/" + type + '.png');

