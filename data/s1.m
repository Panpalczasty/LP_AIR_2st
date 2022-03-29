offset = 100;
w = PD_C.signals(2).values(offset:end,1);
u = PD_C.signals(4).values(offset:end);

figure(1);
plot(u,w,'k-');
grid on;
hold on;