%% Vds overshoots
Vdc1 = 25:25:200;
Vdc2 = 25:25:300;
PhA_Vds = [27.4,55.5,90.1,120.9,143.0,160.6,180.9,207.4];
PhB_Vds = [28.1,56.1,91.2,127.9,153.5,171.1,188.1,210.1];
PhC_Vds = [28.1,57.3,92.9,127.3,154.2,173.6,194.0,212.5];

figure;
hold all;
plot(Vdc1,PhA_Vds,'ro-','Linewidth',2);
plot(Vdc1,PhB_Vds,'b*-','Linewidth',2);
plot(Vdc1,PhC_Vds,'k--','Linewidth',2);
grid on;
set(gca,'FontSize',12);
xlabel('DC Link Voltage (Volts)','FontSize',12,'FontWeight','Bold')
ylabel('Vds (Volts)','FontSize',12,'FontWeight','Bold')
xlim([0 225]);
legend('Phase-A','Phase-B','Phase-C');

figure;
hold all;
plot(Vdc1,PhA_Vds-Vdc1,'ro-','Linewidth',2);
plot(Vdc1,PhB_Vds-Vdc1,'b*-','Linewidth',2);
plot(Vdc1,PhC_Vds-Vdc1,'k--','Linewidth',2);
grid on;
set(gca,'FontSize',12);
xlabel('DC Link Voltage (Volts)','FontSize',12,'FontWeight','Bold')
ylabel('Overshoot (Volts)','FontSize',12,'FontWeight','Bold')
xlim([0 225]);
ylim([0 50]);
legend('Phase-A','Phase-B','Phase-C');


%% Vgs false-turn-ons
Vdc1 = 25:25:200;
Vdc2 = 25:25:300;
PhA_Vgs = [-1.09,0.124,0.759,0.853,0.931,1.06,1.08,1.09,1.21,1.19,1.23,1.24];
PhB_Vgs = [-0.979,0.354,0.748,0.908,1.05,1.1,1.2,1.3];
PhC_Vgs = [-0.99,0.113,0.527,0.549,0.666,0.755,0.858,0.919,0.949,0.993,1.13,1.12];

figure;
hold all;
plot(Vdc2,PhA_Vgs,'ro-','Linewidth',2);
plot(Vdc1,PhB_Vgs,'b*-','Linewidth',2);
plot(Vdc2,PhC_Vgs,'k--','Linewidth',2);
plot(Vdc2,1.7*ones(1,numel(Vdc2)),'m-','Linewidth',1);
grid on;
set(gca,'FontSize',12);
xlabel('DC Link Voltage (Volts)','FontSize',12,'FontWeight','Bold')
ylabel('Vgs (Volts)','FontSize',12,'FontWeight','Bold')
xlim([0 325]);
legend('Phase-A','Phase-B','Phase-C','Threshold');


%%
% Vds at 200Vdc

figure;
hold all;
plot(e008*1e9,VarName2,'b-','Linewidth',2);
plot(e1*1e9,VarName1,'r-','Linewidth',2);
plot(e2*1e9,VarName3,'g-','Linewidth',1);
grid on;
set(gca,'FontSize',12);
xlabel('Time (ns)','FontSize',12,'FontWeight','Bold')
ylabel('Vds (Volts)','FontSize',12,'FontWeight','Bold')
xlim([-5 60]);
legend('Phase-A','Phase-B','Phase-C');

%%
% Vgs at 200Vdc

figure;
hold all;
plot(e6*1e9,VarName8,'b-','Linewidth',2);
plot(e5*1e9-2,VarName7,'r-','Linewidth',2);
plot(e4*1e9,VarName6,'g-','Linewidth',1);
plot(e6*1e9,1.7*ones(1,numel(e6)),'m-','Linewidth',1);
grid on;
set(gca,'FontSize',12);
xlabel('Time (ns)','FontSize',12,'FontWeight','Bold')
ylabel('Vgs (Volts)','FontSize',12,'FontWeight','Bold')
xlim([2160 2240]);
ylim([-8 3]);
legend('Phase-A','Phase-B','Phase-C','threshold');

%%
% Vgs at 300Vdc

figure;
hold all;
plot(e7*1e9-1,VarName9,'b-','Linewidth',2);
%plot(e5*1e9-2,VarName7,'r-','Linewidth',2);
plot(e8*1e9,VarName10,'g-','Linewidth',1);
plot(e8*1e9,1.7*ones(1,numel(e8)),'m-','Linewidth',1);
grid on;
set(gca,'FontSize',12);
xlabel('Time (ns)','FontSize',12,'FontWeight','Bold')
ylabel('Vgs (Volts)','FontSize',12,'FontWeight','Bold')
xlim([2160 2260]);
ylim([-8 3]);
legend('Phase-A','Phase-C','threshold');

%%
% Vgs garip-peak

figure;
hold all;
plot(e3*1e9,VarName5,'r-','Linewidth',1.5);
grid on;
set(gca,'FontSize',12);
xlabel('Time (ns)','FontSize',12,'FontWeight','Bold')
ylabel('Vgs (Volts)','FontSize',12,'FontWeight','Bold')
%xlim([-1200 -900]);
%xlim([2100 2400]);
%xlim([2900 3200]);
ylim([-9 3]);
%legend('Phase-A','Phase-B','Phase-C');

