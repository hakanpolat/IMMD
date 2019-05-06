%% Vds overshoots
Vdc = 25:25:300;
PhA_Vds = [27.4,55.5,90.1,120.9,143.0,160.6,180.9,207.4,231.9,255.9,279.6,303.3];
PhB_Vds = [28.1,56.1,91.2,127.9,153.5,171.1,188.1,210.1,232.3,257.3,279.5,302.2];
PhC_Vds = [28.1,57.3,92.9,127.3,154.2,173.6,194.0,212.5,234.0,255.2,279.0,304.0];

figure;
hold all;
plot(Vdc,PhA_Vds,'ro-','Linewidth',2);
plot(Vdc,PhB_Vds,'bx-','Linewidth',2);
plot(Vdc,PhC_Vds,'k+-','Linewidth',2);
grid on;
set(gca,'FontSize',14);
xlabel('DC Link Voltage (Volts)','FontSize',14,'FontWeight','Bold')
ylabel('Maximum Drain-Source Voltage (Volts)','FontSize',14,'FontWeight','Bold')
xlim([0 310]);
legend({'Phase-A','Phase-B','Phase-C'},'Location','best');

%%
figure;
hold all;
plot(Vdc,PhA_Vds-Vdc,'ro-','Linewidth',2);
plot(Vdc,PhB_Vds-Vdc,'bx-','Linewidth',2);
plot(Vdc,PhC_Vds-Vdc,'k+-','Linewidth',2);
grid on;
set(gca,'FontSize',14);
xlabel('DC Link Voltage (Volts)','FontSize',14,'FontWeight','Bold')
ylabel('Peak Overshoot (Volts)','FontSize',14,'FontWeight','Bold')
xlim([0 310]);
ylim([0 50]);
legend({'Phase-A','Phase-B','Phase-C'},'Location','best');


%% Vgs false-turn-ons
Vdc = 25:25:300;
PhA_Vgs = [-1.09,0.124,0.759,0.853,0.931,1.06,1.08,1.09,1.21,1.19,1.23,1.24];
PhB_Vgs = [-0.979,0.354,0.748,0.908,1.05,1.1,1.2,1.3,1.37,1.48,1.52,1.56];
PhC_Vgs = [-0.99,0.113,0.527,0.549,0.666,0.755,0.858,0.919,0.949,0.993,1.13,1.12];

figure;
hold all;
plot(Vdc,PhA_Vgs,'ro-','Linewidth',2);
plot(Vdc,PhB_Vgs,'bx-','Linewidth',2);
plot(Vdc,PhC_Vgs,'k+-','Linewidth',2);
plot(Vdc,1.7*ones(1,numel(Vdc)),'g--','Linewidth',2);
%grid on;
set(gca,'FontSize',14);
xlabel('DC Link Voltage (Volts)','FontSize',14,'FontWeight','Bold')
ylabel('Peak Gate-Source Voltage (Volts)','FontSize',14,'FontWeight','Bold')
xlim([0 310]);
legend({'Phase-A','Phase-B','Phase-C','Threshold'},'Location','best');


%%
% Vds at 300Vdc

figure;
hold all;
plot(e008*1e9,VarName2,'r-','Linewidth',2);
plot(e1*1e9,VarName1,'b-','Linewidth',2);
plot(e2*1e9,VarName3,'k-','Linewidth',2);
plot(e2*1e9,300*ones(1,numel(e1)),'g--','Linewidth',2);
%grid on;
set(gca,'FontSize',14);
xlabel('Time (ns)','FontSize',14,'FontWeight','Bold')
ylabel('Drain-Source Voltage (Volts)','FontSize',14,'FontWeight','Bold')
xlim([-5 60]);
legend({'Phase-A','Phase-B','Phase-C','DC Link Voltage'},'Location','best');

%%
% Vgs at 300Vdc

figure;
hold all;
plot(e006*1e9,VarName2,'r-','Linewidth',2);
plot(e2*1e9-2,VarName3,'b-','Linewidth',2);
plot(e1*1e9+2,VarName1,'k-','Linewidth',2);
plot(e1*1e9,1.7*ones(1,numel(e1)),'g--','Linewidth',2);
%grid on;
set(gca,'FontSize',14);
xlabel('Time (ns)','FontSize',14,'FontWeight','Bold')
ylabel('Gate-Source Voltage (Volts)','FontSize',14,'FontWeight','Bold')
xlim([2160 2240]);
ylim([-8 3]);
legend({'Phase-A','Phase-B','Phase-C','Threshold'},'Location','best');

%% Top results Vds
figure;
hold all;
plot(e1*1e9,VarName1,'r-','Linewidth',2);
plot(e008*1e9,VarName2,'b-','Linewidth',2);
plot(e1*1e9,300*ones(1,numel(e1)),'g--','Linewidth',2);
%grid on;
set(gca,'FontSize',14);
xlabel('Time (ns)','FontSize',14,'FontWeight','Bold')
ylabel('Drain-Source Voltage (Volts)','FontSize',14,'FontWeight','Bold')
xlim([-5 60]);
legend({'Load Top','Load Bottom','DC Link Voltage'},'Location','best');

%% Top results Vgs

figure;
hold all;
%plot(e1*1e9-2175,VarName1,'r-','Linewidth',2);
plot(e006*1e9,VarName2,'b-','Linewidth',2);
grid on;
set(gca,'FontSize',12);
xlabel('Time (ns)','FontSize',12,'FontWeight','Bold')
ylabel('Phase-C Vgs (Volts)','FontSize',12,'FontWeight','Bold')
%xlim([-50 250]);
legend('Bottom','Top');

%% Vgs turn-on and turn-off
Vgs_turn_on = VarName2(14850:14850+1250);
Vgs_turn_off = VarName2(19100:19100+1250);
timeax = 0:0.2:250;

figure;
hold all;
plot(timeax,Vgs_turn_on,'b-','Linewidth',2);
plot(timeax,Vgs_turn_off,'r-','Linewidth',2);
plot(timeax,6*ones(1,numel(timeax)),'k--','Linewidth',2);
plot(timeax,-3.7*ones(1,numel(timeax)),'g--','Linewidth',2);
grid off;
set(gca,'FontSize',14);
xlabel('Time (ns)','FontSize',14,'FontWeight','Bold')
ylabel('Gate-Source Voltage (Volts)','FontSize',14,'FontWeight','Bold')
%xlim([-50 250]);
legend({'Turn-on','Turn-off','Positive drive voltage','Negative drive voltage'},'Location','best');

%% Top results Vgs-modify

figure;
hold all;
plot(e1*1e9-2175,VarName1*-1,'r-','Linewidth',2);
plot(e006*1e9,VarName2,'b-','Linewidth',2);
grid on;
set(gca,'FontSize',12);
xlabel('Time (ns)','FontSize',12,'FontWeight','Bold')
ylabel('Phase-C Vgs (Volts)','FontSize',12,'FontWeight','Bold')
xlim([-50 150]);
legend('Bottom*(-1)','Top');
