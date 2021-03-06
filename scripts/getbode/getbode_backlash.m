clc
clear all
close all

%get measurement data
type = "strefa-martwa";
path = "../data/data/lab3/chirp/stat_" + type + "_chirp_0-1_do_3_hz";
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
fmin = 0.1;

%time window - Tukey 
win = tukeywin(T*sfreq+1,0.15);

%Perform FFT
uf = fft(u.*win);
vf = fft(v(:,3).*win);
vt = fft(v(:,1).*win);

%get frequency vector
w0 = linspace(0,sfreq, T*sfreq+1);

%drop values at frequencies outside chirp
uf = uf(fmin*T:fmax*T);
vf = vf(fmin*T:fmax*T);
vt = vt(fmin*T:fmax*T);
w = w0(fmin*T:fmax*T);

%response over input
d = vf./uf;
dt = vt./uf;
%get magnitude
M = 20*log10(abs(d));
Mt = 20*log10(abs(dt));

%get phase
ph = 180/pi*angle(d);
pht = 180/pi*angle(dt);


%% get linear filter

Lf = [0.9]
Mf = [0.2 1]

G = tf(Lf,Mf);

[Mf, phasef] = bode(G, w*6.28);
Mf = 20*log10(Mf(:,:));
phasef = phasef(:,:);
%%
%show window
%plotWin(win,t);
 
%plotChirpFFT(u, win, w0);

%plotNyquist(d, type, ind45);

plotBode(M, ph, Mt, pht, w, type, 0, 10);

subplot(2,1,1);
plot(w, Mf, "b-", "LineWidth", 1.5);

subplot(2,1,2);
plot(w, phasef, "b-", "LineWidth", 1.5);

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


    %saveas(23, "plots/nyquist/" + type + '.png');
end

function plotBode(M, ph, Mt, pht, w, type, ind45, id)

    figure(id);
    subplot(2,1,1);
    semilogx(w, M-Mt, 'k-');
    hold on;
    %semilogx(w, Mt, 'b-');
    grid;
    title("Magnitude plot - " + type);
    xlabel("Frequency [Hz]");
    ylabel("Magnitude [dB]");
    legend("magnitude - dif", "model");
    xticks([0.1 0.2 0.5 1 2 5 10]);

    subplot(2,1,2);
    semilogx(w, ph-pht,'k-');
    hold on;
    %semilogx(w, pht, 'b-');
    grid;
    legend("phase-dif", "model");
    title("Phase plot - " + type);
    xlabel("Frequency [Hz]");
    ylabel("Phase shift [deg]");
    yticks([-180 -135 -90 -45 0 45 90]);
    xticks([0.1 0.2 0.5 1 2 5 10]);

    %saveas(4, "plots/bode2/" + type + '.png');
end

function sys = getTF()
        %% calc your D's
    si = [253.74 254.89 212.46 251.93 253.74]
    R = 3.964
    L = 0.5e-3
    U = 24
    ke = 2.7e-3;
    
    Di = (1./si - ke/U)*U/R
    
    %% and then your J's
    
    f45s = [0.6568 0.6270 0.5747 0.1065 0.5044];
    w45s = 2*pi*f45s;
    
    Ji = 1./w45s .* (ke./(R+L*w45s) + (R-L*w45s)./(R+L*w45s).*Di);
    
    %% calc other params
    
    J = sum(Ji) - 4*Ji(2);
    D = sum(Di) - 4*Di(2);
    
    L = U;
    M = [L*J L*D+R*J R*D+ke];
    
    G = tf2ss(L,M)
end
