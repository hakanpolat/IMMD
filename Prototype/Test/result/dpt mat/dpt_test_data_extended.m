%% Phase-A, Load bottom
%% Variables
% Vds1: Phase-A, 200V, Loadbot, Top, 6.6 A
% Vds2: Phase-A, 225V, Loadbot, Top, 7.5 A
% Vds3: Phase-A, 250V, Loadtop, Top, 8.4 A
% Vds4: Phase-A, 275V, Loadtop, Top, 9.4 A
% Vds5: Phase-A, 275V, Loadtop, Bottom, 11.5 A
% Vds6: Phase-A, 300V, Loadtop, Bottom, 12.6 A
%%
% Save the data
filename = 'test.mat';
save(filename);
%%
% Load the data
load('test.mat');
%% Plot
figure;
hold all;
plot(time4*1e9,Vds4,'b-','Linewidth',2);
plot(time5*1e9,Vds5,'r-','Linewidth',2);
grid on;
set(gca,'FontSize',12);
xlabel('Time (ns)','FontSize',12,'FontWeight','Bold')
ylabel('Vds (Volts)','FontSize',12,'FontWeight','Bold')
xlim([-20 100]);
ylim([-50 500]);
title('Phase-A DPT Results (Load is on Bottom)')
legend('275V, 9.4A, Top','275V, 11.5A, Bottom');

%% Phase-A, Load top
%% Variables

% datalar kayboldu

%% Phase-B, Load bottom
%% Variables
% Vds7: Phase-B, 275V, Loadbot, Top, 11.5 A
% Vds8: Phase-B, 300V, Loadbot, Top, 12.6 A

%% Plot
figure;
hold all;
plot(time7*1e9,Vds7,'b-','Linewidth',2);
plot(time8*1e9,Vds8,'r-','Linewidth',2);
grid on;
set(gca,'FontSize',12);
xlabel('Time (ns)','FontSize',12,'FontWeight','Bold')
ylabel('Vds (Volts)','FontSize',12,'FontWeight','Bold')
xlim([-20 100]);
ylim([-50 500]);
title('Phase-B DPT Results (Load is on Bottom)')
legend('275V, 11.5A, Top','300V, 12.6A, Top');

%% Phase-B, Load top
% Vds9: Phase-B, 150V, Loadtop, Top, 5.6 A
% Vds10: Phase-B, 150V, Loadtop, Bottom, 6.2 A

% yanlýþlýk var muhtemelen

%% Plot
figure;
hold all;
plot(time9*1e9,Vds9,'b-','Linewidth',2);
plot(time10*1e9,Vds10,'r-','Linewidth',2);
grid on;
set(gca,'FontSize',12);
xlabel('Time (ns)','FontSize',12,'FontWeight','Bold')
ylabel('Vds (Volts)','FontSize',12,'FontWeight','Bold')
xlim([-20 100]);
ylim([-50 400]);
title('Phase-B DPT Results (Load is on Top)')
legend('150V, 5.6A, Top','150V, 6.2A, Bottom');

%% 
% Vds9: Phase-B, 150V, Loadtop, Top, 5.6 A
% Vds11: Phase-C, 150V, Loadtop, Top, 5.5 A
% Vds12: Phase-A, 150V, Loadtop, Top, 6 A

figure;
hold all;
plot(time12*1e9+5,Vds12,'k-','Linewidth',2);
plot(time9*1e9,Vds9,'b-','Linewidth',2);
plot(time11*1e9,Vds11,'r-','Linewidth',2);
grid on;
set(gca,'FontSize',12);
xlabel('Time (ns)','FontSize',12,'FontWeight','Bold')
ylabel('Vds (Volts)','FontSize',12,'FontWeight','Bold')
xlim([-20 100]);
ylim([-50 400]);
title('DPT Results (Load is on Top)')
legend('150V, 6A, Top, Phase A','150V, 5.6A, Top, Phase B','150V, 6.2A, Top, Phase C');

