%% AC waveforms
time = VarName1*1e3; % ms
Ia = VarName2*2;
Ib = VarName3*2;
Ic = -Ia-Ib;
Vllab = VarName4;
Vllcb = VarName5;

%%
figure;
hold all;
plot(time,Ia,'r-','Linewidth',1);
plot(time,Ib,'b-','Linewidth',1);
plot(time,Ic,'k-','Linewidth',1);
set(gca,'FontSize',14);
xlabel('Time (ms)','FontSize',14,'FontWeight','Bold')
ylabel('Phase Currents (Amps)','FontSize',14,'FontWeight','Bold')
xlim([-10 20]);
legend({'Phase-A','Phase-B','Phase-C'},'Location','northeast');

%%
figure;
hold all;
yyaxis left
ylabel('Phase-A to Phase-B Voltage (Volts)','FontSize',14,'FontWeight','Bold')
plot(time,Vllab,'b-','Linewidth',0.2);
yyaxis right
ylabel('Phase-A Current (Smps)','FontSize',14,'FontWeight','Bold')
plot(time,Ia,'r-','Linewidth',1);
set(gca,'FontSize',14);
xlabel('Time (ms)','FontSize',14,'FontWeight','Bold')
xlim([-10 20]);

%%
figure;
hold all;
plot(time,Vllab,'b-','Linewidth',0.2);
set(gca,'FontSize',14);
ylabel('Phase-A to Phase-B Voltage (Volts)','FontSize',14,'FontWeight','Bold')
xlabel('Time (ms)','FontSize',14,'FontWeight','Bold')
xlim([-10 20]);

%%
Ts = 100e-9;
timeaxis = (time-time(1))*1e-3;
Tfinal = (time(end)-time(1))*1e-3;

%% DC waveforms
time = VarName1*1e3; % ms
Idc = VarName2+VarName3;
Vdc1 = VarName4;
Vdc2 = VarName5;

%%
figure;
hold all;
plot(time,Vdc1,'r-','Linewidth',1);
set(gca,'FontSize',14);
xlabel('Time (ms)','FontSize',14,'FontWeight','Bold')
ylabel('DC Link Voltage (Volts)','FontSize',14,'FontWeight','Bold')
xlim([0 20]);
ylim([250 320]);

%%
figure;
hold all;
plot(time,Idc,'b-','Linewidth',1);
set(gca,'FontSize',14);
xlabel('Time (ms)','FontSize',14,'FontWeight','Bold')
ylabel('DC Link Current (Amps)','FontSize',14,'FontWeight','Bold')
xlim([0 20]);
%ylim([0 10])
