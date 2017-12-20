%% Plot for time plots
%Indicate Top or Bot then set xlim and ylim
%Indicate Xtick Ytick and check legend and labels
fplot = figure;
figure(fplot)
plot((1:6000001)*SampleTime, -10*BotDSCurrInd,(1:6000001)*SampleTime, BotVoltDSInd,'Linewidth',3.0);
ylim([-100 500]);
xlim([0.249E-5 0.251E-5]);
ax = gca;
ax.XTick = [0.248E-5 0.249E-5 0.25E-5 0.251E-5 0.252E-5 0.253E-5];
ax.YTick = [-100 0 100 200 300 400 500];
legend('I_d_s (x10)','V_d_s');
xlabel('Time(s)','FontSize',12);
ylabel('Current(A), Voltage(V)');
% grid on
%For Top Turn OFF - Bottom Turn ON
%[0.248E-5 0.249E-5 0.25E-5 0.251E-5 0.252E-5 0.253E-5]
%For Top Turn ON - Bottom Turn OFF
%[0.199E-5 0.2E-5 0.201E-5 0.202E-5 0.203E-5 0.204E-5]