%% Plot for time plots
%Indicate Top or Bot then set xlim and ylim
%Indicate Xtick Ytick and check legend and labels
fplot = figure;
figure(fplot)
plot((1:6000001)*SampleTime, -10*BotChCons, (1:6000001)*SampleTime, 10*TopChCons,'Linewidth',2.0);
ylim([-60 560]);
xlim([0.249E-5 0.25E-5]);
ax = gca;
ax.XTick = [0.248E-5 0.249E-5 0.25E-5 0.251E-5 0.252E-5 0.253E-5];
ax.YTick = [0 100 200 300 400 500];
legend('IBotCh (-x10))','ITopCh (x10)');
xlabel('Time(s)','FontSize',12);
ylabel('Current(A)');
grid on
%For Top Turn OFF - Bottom Turn ON
%[0.248E-5 0.249E-5 0.25E-5 0.251E-5 0.252E-5 0.253E-5]
%For Top Turn ON - Bottom Turn OFF
%[0.199E-5 0.2E-5 0.201E-5 0.202E-5 0.203E-5 0.204E-5]