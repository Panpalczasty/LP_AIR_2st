clc
clear all
close all

%% get object data 

%get measurement data
type = "walec";
path = "../data/data/lab4/chirp_silnik_" + type + "_0-01_1_10minut";
src = open (path + '.mat');

u = src.PD_C.signals(4).values;
v = src.PD_C.signals(2).values(:,1);
t = src.PD_C.time;

T = t(end);

%% get linmodel data

%propagate output signal thru simulation 
usim = [t u];
vsim = [t v];

%simulate 
open ../models/model_QA.slx
sim ../models/model_QA.slx

t = ans.time;
u = ans.input;
vmod = ans.output;
vref = ans.vref;

%% calc bode

%calculate measurement params
             %time
sfreq = 1/(t(2)-t(1));  %sampling frequency

%frequency of chirp at the beginning and end of test
[upeaks, i]  = findpeaks(u);
di = diff(i);
fmax = 1/(t(end) - t(end - di(end)))-0.15;
fmin = 0.01;            %manual 

%time window - Tukey, crop ends of chirp
win = tukeywin(T*sfreq+1,0.15);

%Perform FFT
uf = fft(u.*win);
vfref = fft(vref.*win);
vfmod = fft(vmod.*win);

%get frequency vector
w0 = linspace(0,sfreq, T*sfreq+1);

%drop values at frequencies outside chirp
uf = uf(fmin*T:fmax*T);
vfref = vfref(fmin*T:fmax*T);
vfmod = vfmod(fmin*T:fmax*T);
w = w0(fmin*T:fmax*T);

%response over input
Gmod = vfmod./uf;
Gref = vfref./uf;

plotBode(w, Gmod, Gref, 1);
plotMetrics(w, Gmod, Gref, 2);

%% plots 

function plotMetrics(w ,Gmod, Gref, id)
    
    %get phase
    pmod = 180/pi*angle(Gmod);
    pref = 180/pi*angle(Gref);
    %lil correction for angle
    pmod(pmod > 90) = pmod(pmod > 90) - 360;
    pref(pref > 90) = pref(pref > 90) - 360;

    % nyqiust accuracy 
    nacc = abs(Gmod-Gref)./abs(Gref);
    % magnitude accuracy
    macc = 20*log10(abs(Gmod)./abs(Gref));
    % Phase model shift
    phs = pmod - pref;
    
    modl = "\hat{G}(i\omega)";
    refl = "G(i\omega)";

    figure(id)
    subplot(3,1,1)
    semilogx(w, 20*log10(nacc), 'k-', "LineWidth", 1.5);
    grid;
    xlabel("Frequency [Hz]");
    ylabel("Error magnitude [dB]");
    title("Nyquist error $$\frac{\|"+modl+"-"+refl+"\|}{\|"+refl+"\|}$$", ...
          "Interpreter", ...
          "latex");
    xticks([0.01 0.02 0.05 0.1 0.2 0.5 1 2]);
    
    subplot(3,1,2)
    semilogx(w, macc, 'k-', "LineWidth", 1.5);
    grid;
    xlabel("Frequency [Hz]");
    ylabel("Magnitude [dB]");
    title("Magnitude deviation $$20*\log_{10}\frac{\|"+modl+"\|}{\|"+refl+"\|}$$", ...
          "Interpreter", ...
          "latex");
    xticks([0.01 0.02 0.05 0.1 0.2 0.5 1 2]);
    
    subplot(3,1,3)
    semilogx(w, phs, 'k-', "LineWidth", 1.5);
    grid;
    xlabel("Frequency [Hz]");
    ylabel("Phase [deg]");
    title("Phase shift $$arg("+modl+") - arg("+refl+")$$", ...
          "Interpreter", ...
          "latex");
    xticks([0.01 0.02 0.05 0.1 0.2 0.5 1 2]);
    

end

function plotBode(w, Gmod, Gref, id)
    
    %get magnitude
    Mmod = 20*log10(abs(Gmod));
    Mref = 20*log10(abs(Gref));
    
    %get phase
    pmod = 180/pi*angle(Gmod);
    pref = 180/pi*angle(Gref);
    
    %lil correction for angle
    pmod(pmod > 90) = pmod(pmod > 90) - 360;
    pref(pref > 90) = pref(pref > 90) - 360;

    figure(id);
    
    subplot(2,1,1);
    semilogx(w, Mref, 'k-', "LineWidth", 1.5);
    hold on;
    semilogx(w, Mmod, 'b--');
    grid;
    xlabel("Frequency [Hz]");
    ylabel("Magnitude [dB]");
    legend("object", "linear model")
    title("Model - object comparison");
    xticks([0.01 0.02 0.05 0.1 0.2 0.5 1 2]);
    
    subplot(2,1,2);
    semilogx(w, pref, 'k-', "LineWidth", 1.5);
    hold on;
    semilogx(w, pmod, 'b-');
    grid;
    xlabel("Frequency [Hz]");
    ylabel("Phase [deg]");
    legend("object", "linear model");    
    xticks([0.01 0.02 0.05 0.1 0.2 0.5 1 2]);
    
end