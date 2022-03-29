clc
clear all
close all

%get measurement data
type = "walec";
path = "data/data/lab4/chirp_silnik_" + type + "_0-01_1_10minut";
src = open (path + '.mat');

u = src.PD_C.signals(4).values;
v = src.PD_C.signals(2).values;
t = src.PD_C.time;

%calculate meas params
T = t(end);             %time
sfreq = 1/(t(2)-t(1));  %sampling frequency

%frequency of chirp at the beginning and end of test
[upeaks, i]  = findpeaks(u(:,1));
di = diff(i);
fmax = 1/(t(end) - t(end - di(end)))-0.15;
fmin = 0.01;

%time window - Tukey 
win = tukeywin(T*sfreq+1,0.15);

%Perform FFT
uf = fft(u.*win);
vf = fft(v(:,3).*win);

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


%% get frequency of -45 phase shift

[phase45, ind45] = min(abs(ph+45));
f45 = w(ind45);
m45 = M(ind45);

%%
%show window
%plotWin(win,t);
 
plotChirpFFT(u, win, w0);

plotNyquist(d, type, ind45);

plotBode(M, ph, w, type, ind45);


function plotWin(win,t)
    figure(21)
    plot(t,win,'k-');
    grid;
    ylim([0 1.1]);
    xlabel("Time [s]");
    ylabel("Window value");
    title("Tukey window");
    
    %saveas(21,"plots/tukey.png");
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

function plotNyquist(d, type, ind45)
    
    nmax = abs(d(1)); 

    figure(23)
    plot(d,'k-');
    hold on;
    plot(d(1), 'bo');
    plot(d(end), 'bx');
    plot(d(ind45), 'rx');
    grid;
    title("Nyquist fragment");
    xlabel("Real part");
    ylabel("Imaginary part");
    legend("nyquist","begin point", "end point", "point - 45 deg")
    xlim([-nmax nmax]);
    ylim([-nmax nmax]);


    saveas(23, "plots/nyquist/" + type + '.png');
end

function plotBode(M, ph, w, type, ind45)

    figure(4);
    subplot(2,1,1);
    semilogx(w, M, 'k-');
    hold on;
    plot(w(ind45), M(ind45), "rx");
    grid;
    title("Magnitude plot - " + type);
    xlabel("Frequency [Hz]");
    ylabel("Magnitude [dB]");
    legend("magnitude", "point - 45 deg");
    xticks([0.1 0.2 0.5 1 2 5 10]);

    subplot(2,1,2);
    semilogx(w, ph,'k-');
    hold on;
    semilogx(w(ind45), ph(ind45), "rx");
    grid;
    legend("phase", "point - 45 deg");
    title("Phase plot - " + type);
    xlabel("Frequency [Hz]");
    ylabel("Phase shift [deg]");
    yticks([-180 -135 -90 -45 0 45 90]);
    xticks([0.1 0.2 0.5 1 2 5 10]);

    saveas(4, "plots/bode2/" + type + '.png');
end