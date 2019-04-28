% Vllab
time_Vllab_300V_Load5_10kHz = VarName1;
voltage_Vllab_300V_Load5_10kHz = VarName2;
time_Vllab_300V_Load5_40kHz = VarName3;
voltage_Vllab_300V_Load5_40kHz = VarName4;

% Ia
time_Ia_300V_Load5_10kHz = VarName5;
current_Ia_300V_Load5_10kHz = VarName6;
time_Ia_300V_Load5_40kHz = VarName7;
current_Ia_300V_Load5_40kHz = VarName8;

% Ib
time_Ib_300V_Load5_10kHz = VarName9;
current_Ib_300V_Load5_10kHz = VarName10;
time_Ib_300V_Load5_40kHz = VarName11;
current_Ib_300V_Load5_40kHz = VarName12;

% Ic
time_Ic_300V_Load5_10kHz = VarName13;
current_Ic_300V_Load5_10kHz = VarName14;
time_Ic_300V_Load5_40kHz = VarName15;
current_Ic_300V_Load5_40kHz = VarName16;

%% Save workspace
save('inverterdata.mat');

%% Load workspace
load('inverterdata.mat');

%% Plots
figure;
hold all;
plot(time_Vllab_300V_Load5_10kHz*1e3,voltage_Vllab_300V_Load5_10kHz,'r-','Linewidth',1);
%plot(time_Vllab_300V_Load5_40kHz,voltage_Vllab_300V_Load5_40kHz,'b-','Linewidth',1);
grid on;
set(gca,'FontSize',12);
xlabel('Time (ms)','FontSize',12,'FontWeight','Bold')
ylabel('Voltage (Volts)','FontSize',12,'FontWeight','Bold')
xlim([-10 20]);

%%
figure;
hold all;
plot(time_Ia_300V_Load5_10kHz*1e3,current_Ia_300V_Load5_10kHz*10,'b-','Linewidth',1);
plot(time_Ib_300V_Load5_10kHz*1e3,current_Ib_300V_Load5_10kHz*10,'k-','Linewidth',1);
plot(time_Ic_300V_Load5_10kHz*1e3,current_Ic_300V_Load5_10kHz*10,'r-','Linewidth',1);
grid on;
set(gca,'FontSize',12);
xlabel('Time (ms)','FontSize',12,'FontWeight','Bold')
ylabel('Current (Amps)','FontSize',12,'FontWeight','Bold')
xlim([-10 20]);
legend('Phase-A','Phase-B','Phase-C');

