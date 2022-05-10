clc
clear all
close all

%get measurement data
type = "silnik";
path = "data/data/lab3/chirp/stat_" + type + "_chirp_0-1_do_3_hz";
src = open (path + '.mat');




u = src.PD_C.signals(4).values;
v = src.PD_C.signals(2).values;
t = src.PD_C.time;


%calculate meas params
T = t(end);             %time
sfreq = 1/(t(2)-t(1));  %sampling frequency

%unfilter output
g_filt = tf([1],[0.02 1]);
%v(:,1) = lsim(g_filt, v(:,1), t);

[mag, phm, w] = bode(g_filt);
L = 20*log(mag);
fc = w/pi/2;

%frequency of chirp at the beginning and end of test
[upeaks, i]  = findpeaks(u(:,1));
di = diff(i);
fmax = 1/(t(end) - t(end - di(end)))-0.15;
fmin = 0.1;

%time window - Tukey 
win = tukeywin(T*sfreq+1,0.5);

%Perform FFT
uf = fft(u.*win);
vf = fft(v(:,1).*win);

%get frequency vector
w0 = linspace(0,sfreq, T*sfreq+1);

%drop values at frequencies outside chirp
uf = uf(fmin*T:fmax*T);
vf = vf(fmin*T:fmax*T);
w = w0(fmin*T:fmax*T);

%response over input
d = vf./uf;
%get magnitude
M = 20*log10(abs(d));
%get phase
ph = 180/pi*angle(d);

%show window
%plotWin(win,t);

plotChirpFFT(u, win, w0);

plotNyquist(d, type);

plotBode(M, ph, w, type);

function plotWin(win,t)
    figure(21)
    plot(t,win,'k-');
    grid;
    ylim([0 1.1]);
    xlabel("Time [s]");
    ylabel("Window value");
    title("Tukey window");
    
    saveas(21,"plots/tukey.png");
end

function plotChirpFFT(chirp, win, w)

    uraw = fft(chirp);
    uwin = fft(chirp.*win);
    
    uraw = uraw(1:end/2);
    uwin = uwin(1:end/2);
    w = w(1:end/2);

    Mu = abs(uraw);
    Mw = abs(uwin);

    figure(22);
    semilogx(w , Mu,'r--');
    hold on;
    semilogx(w, Mw, 'k-', 'LineWidth', 2);
    grid;
    title("Chirp signal FFT");
    xlabel("Frequency [Hz]");
    ylabel("Absolute value");
    legend("raw", "Tukey windowed");
    xlim([0.001 25]);
    xticks([0.001 0.002 0.005 0.01 0.02 0.05 0.1 0.2 0.5 1 2 5 10 20]);

end

function plotNyquist(d, type)

    figure(23)
    plot(d,'k-');
    hold on;
    plot(d(1), 'ro');
    plot(d(end), 'rx');
    grid;
    title("Nyquist fragment");
    xlabel("Real part");
    ylabel("Imaginary part");

    saveas(23, "plots/nyquist/" + type + '.png');
end

function plotBode(M, ph, w, type)

    
    figure(4);
    subplot(2,1,1);
    hold on;
    semilogx(w, M, 'k-');
    grid on;
    title("Magnitude plot - " + type);
    xlabel("Frequency [Hz]");
    ylabel("Magnitude [dB]");
    xticks([0.1 0.2 0.5 1 2 5 10]);
    xlim([0.05 3])

    subplot(2,1,2);
    hold on;
    semilogx(w, ph,'k-');
    grid on;
    title("Phase plot - " + type);
    xlabel("Frequency [dB]");
    ylabel("Phase shift [deg]");
    yticks([-180 -135 -90 -45 0 45 90]);
    xticks([0.1 0.2 0.5 1 2 5 10]);
    xlim([0.05 3])

    saveas(4, "plots/bode2/" + type + '.png');
end