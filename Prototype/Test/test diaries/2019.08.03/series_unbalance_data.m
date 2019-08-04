% Voltage unbalance
Voltages = [
    5.5	10
11.3	20
17	30
23	40
29.3	50
35	60
41.2	70
47.7	80
53.8	90
59.8	100
66.1	110
72.2	120
78.5	130
84.8	140
91	150
97.2	160
103	170
109.4	180
115.1	190
121.5	200
127.5	210
133.7	220
139.4	230
145.4	240
151.3	250
157.6	260
163.4	270
169.2	280
175.3	290
180.8	300
186.5	310
192.4	320
198.6	330
204.2	340
210.4	350
215.8	360
221.5	370
227.6	380
233.5	390
239.4	400
];
VoltageBottomModule= Voltages(:,1);
VoltageTotal= Voltages(:,2);
VoltageTopModule = Voltages(:,2) - Voltages(:,1);
VoltageBottomToTotalRatio = VoltageBottomModule./VoltageTotal*100;

%%
figure;
hold all;
plot(VoltageTotal,VoltageBottomModule,'ko-','Linewidth',2);
plot(VoltageTotal,VoltageTopModule,'bx-','Linewidth',2);
set(gca,'FontSize',14);
xlabel('Total DC Link Voltage (Volts)','FontSize',14,'FontWeight','Bold')
ylabel('Module DC Link Voltage (Volts)','FontSize',14,'FontWeight','Bold')
xlim([10 400]);
%ylim([0.5 1.1]);
legend({'Bottom module','Top module'},'Location','best');
%title('Series - 100V - No int');

%%
figure;
hold all;
plot(VoltageTotal,VoltageBottomToTotalRatio,'b--','Linewidth',2);
set(gca,'FontSize',14);
xlabel('Total DC Link Voltage (Volts)','FontSize',14,'FontWeight','Bold')
ylabel('Voltage Ratio (Percent)','FontSize',14,'FontWeight','Bold')
xlim([10 400]);
ylim([50 65]);

%%
%save('series_unbalance_data.mat');

%%
%load('series_unbalance_data.mat');

%%
figure;
hold all;
plot(time_Vdcm1_100v_60v*1e3,Vdcm1_100v_60v,'k-','Linewidth',1);
plot(time_Vdcm2_100v_60v*1e3,Vdcm2_100v_60v,'b-','Linewidth',1);
plot(time_Vdctot_100v_60v*1e3,Vdctot_100v_60v,'r-','Linewidth',1);
set(gca,'FontSize',14);
xlabel('Time (ms)','FontSize',14,'FontWeight','Bold')
ylabel('DC Link voltage ripple (V)','FontSize',14,'FontWeight','Bold')
xlim([-10 10]);
%ylim([0.5 1.1]);
legend({'Top module','Bottom module','Total',},'Location','best');
title('Series - 100V - No int');

%%
figure;
hold all;
plot(time_Vdcm1_150v_91v*1e3,Vdcm1_150v_91v,'k-','Linewidth',1);
plot(time_Vdcm2_150v_91v*1e3,Vdcm2_150v_91v,'b-','Linewidth',1);
plot(time_Vdctot_150v_91v*1e3,Vdctot_150v_91v,'r-','Linewidth',1);
set(gca,'FontSize',14);
xlabel('Time (ms)','FontSize',14,'FontWeight','Bold')
ylabel('DC Link voltage ripple (V)','FontSize',14,'FontWeight','Bold')
xlim([-10 10]);
%ylim([0.5 1.1]);
legend({'Top module','Bottom module','Total',},'Location','best');
title('Series - 150v - No int');

%%
figure;
hold all;
plot(time_Vdcm1_200v_122v*1e3,Vdcm1_200v_122v,'k-','Linewidth',1);
plot(time_Vdcm2_200v_122v*1e3,Vdcm2_200v_122v,'b-','Linewidth',1);
plot(time_Vdctot_200v_122v*1e3,Vdctot_200v_122v,'r-','Linewidth',1);
set(gca,'FontSize',14);
xlabel('Time (ms)','FontSize',14,'FontWeight','Bold')
ylabel('DC Link voltage ripple (V)','FontSize',14,'FontWeight','Bold')
xlim([-10 10]);
%ylim([0.5 1.1]);
legend({'Top module','Bottom module','Total',},'Location','best');
title('Series - 200V - No int');

%%
figure;
hold all;
plot(time_Vdcm1_250v_151v*1e3,Vdcm1_250v_151v,'k-','Linewidth',1);
plot(time_Vdcm2_250v_151v*1e3,Vdcm2_250v_151v,'b-','Linewidth',1);
plot(time_Vdctot_250v_151v*1e3,Vdctot_250v_151v,'r-','Linewidth',1);
set(gca,'FontSize',14);
xlabel('Time (ms)','FontSize',14,'FontWeight','Bold')
ylabel('DC Link voltage ripple (V)','FontSize',14,'FontWeight','Bold')
xlim([-10 10]);
%ylim([0.5 1.1]);
legend({'Top module','Bottom module','Total',},'Location','best');
title('Series - 250V - No int');

%%
figure;
hold all;
plot(time_Vdcm1_300v_181v*1e3,Vdcm1_300v_181v,'k-','Linewidth',1);
plot(time_Vdcm2_300v_181v*1e3,Vdcm2_300v_181v,'b-','Linewidth',1);
plot(time_Vdctot_300v_181v*1e3,Vdctot_300v_181v,'r-','Linewidth',1);
set(gca,'FontSize',14);
xlabel('Time (ms)','FontSize',14,'FontWeight','Bold')
ylabel('DC Link voltage ripple (V)','FontSize',14,'FontWeight','Bold')
xlim([-10 10]);
%ylim([0.5 1.1]);
legend({'Top module','Bottom module','Total',},'Location','best');
title('Series - 300V - No int');

%%
figure;
hold all;
plot(time_Vdcm1_350v_211v*1e3,Vdcm1_350v_211v,'k-','Linewidth',1);
plot(time_Vdcm2_350v_211v*1e3,Vdcm2_350v_211v,'b-','Linewidth',1);
plot(time_Vdctot_350v_211v*1e3,Vdctot_350v_211v,'r-','Linewidth',1);
set(gca,'FontSize',14);
xlabel('Time (ms)','FontSize',14,'FontWeight','Bold')
ylabel('DC Link voltage ripple (V)','FontSize',14,'FontWeight','Bold')
xlim([-10 10]);
%ylim([0.5 1.1]);
legend({'Top module','Bottom module','Total',},'Location','best');
title('Series - 350V - No int');

%%
figure;
hold all;
plot(time_Vdcm1_400v_240v*1e3,Vdcm1_400v_240v,'k-','Linewidth',1);
plot(time_Vdcm2_400v_240v*1e3,Vdcm2_400v_240v,'b-','Linewidth',1);
plot(time_Vdctot_400v_240v*1e3,Vdctot_400v_240v,'r-','Linewidth',1);
set(gca,'FontSize',14);
xlabel('Time (ms)','FontSize',14,'FontWeight','Bold')
ylabel('DC Link voltage ripple (V)','FontSize',14,'FontWeight','Bold')
xlim([-10 10]);
%ylim([0.5 1.1]);
legend({'Top module','Bottom module','Total',},'Location','best');
title('Series - 400V - No int');

%%
figure;
hold all;
plot(time_IphAm1_100v_60v*1e3,IphAm1_100v_60v,'b-','Linewidth',1);
plot(time_IphAm2_100v_60v*1e3,IphAm2_100v_60v,'r-','Linewidth',1);
set(gca,'FontSize',14);
xlabel('Time (ms)','FontSize',14,'FontWeight','Bold')
ylabel('Phase-A Current (A)','FontSize',14,'FontWeight','Bold')
%xlim([-10 10]);
%ylim([0.5 1.1]);
legend({'Bottom module','Top module'},'Location','best');
title('Series - 100V - No int');

%%
figure;
hold all;
plot(time_IphAm1_250v_151v*1e3,IphAm1_250v_151v,'b-','Linewidth',1);
plot(time_IphAm2_250v_151v*1e3,IphAm2_250v_151v,'r-','Linewidth',1);
set(gca,'FontSize',14);
xlabel('Time (ms)','FontSize',14,'FontWeight','Bold')
ylabel('Phase-A Current (A)','FontSize',14,'FontWeight','Bold')
legend({'Bottom module','Top module'},'Location','best');
title('Series - 250V - No int');

%%
figure;
hold all;
plot(time_IphAm1_300v_181v*1e3,IphAm1_300v_181v,'b-','Linewidth',1);
plot(time_IphAm2_300v_181v*1e3,IphAm2_300v_181v,'r-','Linewidth',1);
set(gca,'FontSize',14);
xlabel('Time (ms)','FontSize',14,'FontWeight','Bold')
ylabel('Phase-A Current (A)','FontSize',14,'FontWeight','Bold')
legend({'Bottom module','Top module'},'Location','best');
title('Series - 300V - No int');

%%
figure;
hold all;
plot(time_IphAm1_350v_211v*1e3,IphAm1_350v_211v,'b-','Linewidth',1);
plot(time_IphAm2_350v_211v*1e3,IphAm2_350v_211v,'r-','Linewidth',1);
set(gca,'FontSize',14);
xlabel('Time (ms)','FontSize',14,'FontWeight','Bold')
ylabel('Phase-A Current (A)','FontSize',14,'FontWeight','Bold')
legend({'Bottom module','Top module'},'Location','best');
title('Series - 350V - No int');

%%
figure;
hold all;
plot(time_IphAm1_400v_240v*1e3,IphAm1_400v_240v,'b-','Linewidth',1);
plot(time_IphAm2_400v_240v*1e3,IphAm2_400v_240v,'r-','Linewidth',1);
set(gca,'FontSize',14);
xlabel('Time (ms)','FontSize',14,'FontWeight','Bold')
ylabel('Phase-A Current (A)','FontSize',14,'FontWeight','Bold')
legend({'Bottom module','Top module'},'Location','best');
title('Series - 400V - No int');

%%
figure;
hold all;
plot(time_genis_Vdcm1_100v_60v,genis_Vdcm1_100v_60v,'k-','Linewidth',1);
plot(time_genis_Vdcm2_100v_60v,genis_Vdcm2_100v_60v,'b-','Linewidth',1);
plot(time_genis_Vdctot_100v_60v,genis_Vdctot_100v_60v,'r-','Linewidth',1);
set(gca,'FontSize',14);
xlabel('Time (s)','FontSize',14,'FontWeight','Bold')
ylabel('DC Link voltage ripple (V)','FontSize',14,'FontWeight','Bold')
%xlim([-10 10]);
%ylim([0.5 1.1]);
legend({'Top module','Bottom module','Total',},'Location','best');
title('Series - 100V - No int');

%%
figure;
hold all;
plot(time_genis_Vdcm1_150v_91v,genis_Vdcm1_150v_91v,'k-','Linewidth',1);
plot(time_genis_Vdcm2_150v_91v,genis_Vdcm2_150v_91v,'b-','Linewidth',1);
plot(time_genis_Vdctot_150v_91v,genis_Vdctot_150v_91v,'r-','Linewidth',1);
set(gca,'FontSize',14);
xlabel('Time (s)','FontSize',14,'FontWeight','Bold')
ylabel('DC Link voltage ripple (V)','FontSize',14,'FontWeight','Bold')
%xlim([-10 10]);
%ylim([0.5 1.1]);
legend({'Top module','Bottom module','Total',},'Location','best');
title('Series - 150V - No int');

%%
figure;
hold all;
plot(time_genis_Vdcm1_200v_122v,genis_Vdcm1_200v_122v,'k-','Linewidth',1);
plot(time_genis_Vdcm2_200v_122v,genis_Vdcm2_200v_122v,'b-','Linewidth',1);
plot(time_genis_Vdctot_200v_122v,genis_Vdctot_200v_122v,'r-','Linewidth',1);
set(gca,'FontSize',14);
xlabel('Time (s)','FontSize',14,'FontWeight','Bold')
ylabel('DC Link voltage ripple (V)','FontSize',14,'FontWeight','Bold')
%xlim([-10 10]);
%ylim([0.5 1.1]);
legend({'Top module','Bottom module','Total',},'Location','best');
title('Series - 200V - No int');

%%
figure;
hold all;
plot(time_genis_Vdcm1_250v_151v,genis_Vdcm1_250v_151v,'k-','Linewidth',1);
plot(time_genis_Vdcm2_250v_151v,genis_Vdcm2_250v_151v,'b-','Linewidth',1);
plot(time_genis_Vdctot_250v_151v,genis_Vdctot_250v_151v,'r-','Linewidth',1);
set(gca,'FontSize',14);
xlabel('Time (s)','FontSize',14,'FontWeight','Bold')
ylabel('DC Link voltage ripple (V)','FontSize',14,'FontWeight','Bold')
%xlim([-10 10]);
%ylim([0.5 1.1]);
legend({'Top module','Bottom module','Total',},'Location','best');
title('Series - 250V - No int');

%%
figure;
hold all;
plot(time_genis_Vdcm1_300v_181v,genis_Vdcm1_300v_181v,'k-','Linewidth',1);
plot(time_genis_Vdcm2_300v_181v,genis_Vdcm2_300v_181v,'b-','Linewidth',1);
plot(time_genis_Vdctot_300v_181v,genis_Vdctot_300v_181v,'r-','Linewidth',1);
set(gca,'FontSize',14);
xlabel('Time (s)','FontSize',14,'FontWeight','Bold')
ylabel('DC Link voltage ripple (V)','FontSize',14,'FontWeight','Bold')
%xlim([-10 10]);
%ylim([0.5 1.1]);
legend({'Top module','Bottom module','Total',},'Location','best');
title('Series - 300V - No int');

%%
figure;
hold all;
plot(time_genis_Vdcm1_350v_211v,genis_Vdcm1_350v_211v,'k-','Linewidth',1);
plot(time_genis_Vdcm2_350v_211v,genis_Vdcm2_350v_211v,'b-','Linewidth',1);
plot(time_genis_Vdctot_350v_211v,genis_Vdctot_350v_211v,'r-','Linewidth',1);
set(gca,'FontSize',14);
xlabel('Time (s)','FontSize',14,'FontWeight','Bold')
ylabel('DC Link voltage ripple (V)','FontSize',14,'FontWeight','Bold')
xlim([-5 -4.95]);
%ylim([0.5 1.1]);
legend({'Top module','Bottom module','Total',},'Location','best');
title('Series - 350V - No int');

%%
figure;
hold all;
plot(time_genis_Vdcm1_400v_240v,genis_Vdcm1_400v_240v,'k-','Linewidth',1);
plot(time_genis_Vdcm2_400v_240v,genis_Vdcm2_400v_240v,'b-','Linewidth',1);
plot(time_genis_Vdctot_400v_240v,genis_Vdctot_400v_240v,'r-','Linewidth',1);
set(gca,'FontSize',14);
xlabel('Time (s)','FontSize',14,'FontWeight','Bold')
ylabel('DC Link voltage ripple (V)','FontSize',14,'FontWeight','Bold')
%xlim([-5 -4.95]);
%xlim([2.45 2.5]);
%ylim([0.5 1.1]);
legend({'Top module','Bottom module','Total',},'Location','best');
title('Series - 400V - No int');
