close all

T = 200;
sample_size = 200;
t = linspace(0,T,T*sample_size);
fmin = 0.1;
fmax = 10;

tau = t/T;

%Tukey window
%win = tukeywin(T*sample_size, 0.20);
win = 1;

%linear
f = 2*pi*((fmax-fmin).* t/T*0.5 + fmin).*t;

%exponential
%k = (fmax/fmin).^(1/T);
%f = 2*pi*fmin*((k.^t-1)./log(k));

u = sin(f);


figure(1);
plot(u.*win');
hold on;

v = fft(u'.*win);

w = linspace(0,sample_size, T*sample_size);

w = w(1:end/2);
v = v(1:end/2);

figure(2);
semilogx(w, abs(v), 'k-');
hold on;

%% test on a generic model

L = [1];
M = [0.005 0.15 1];

G = tf(L,M)

sfreq = sample_size;

src = lsim(G, u.*win', t);

figure(1);
plot(src);

vsrc = fft(src);
vsrc = vsrc(1:fmax*T);
w2 = w(1:fmax*T);
v2 = v(1:fmax*T);

figure(3)
plot(d,'b-')

figure(2);
semilogx(w2, abs(vsrc), 'b-');


d = vsrc./v2;
M = 20*log10(abs(d));
ph = 180/pi*angle(d);

figure(4);
subplot(2,1,1);
semilogx(w2, M, 'k-');
grid;

subplot(2,1,2);
semilogx(w2, ph,'k-');
grid;