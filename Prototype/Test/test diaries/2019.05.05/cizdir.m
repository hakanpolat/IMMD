% steady state maximum temperature against load

loading = [5,4,3,2,1,0];
load_power = loading*400;
max_temp = [81.7,67.5,57.3,50.2,40.1,25];

figure;
hold all;
plot(load_power,max_temp,'r-o','Linewidth',2);
grid on;
set(gca,'FontSize',12);
xlabel('Load Power (W)','FontSize',12,'FontWeight','Bold')
ylabel('Maximum Temperature (C)','FontSize',12,'FontWeight','Bold')
ylim([0 100]);
xlim([-100 2100])

%%
% Heating curve at full load
mydata = [
0	25
5	50.2
10	58.4
15	62.4
20	67.8
25	70.5
30	73.3
35	75.2
40	78.1
45	80
50	81
55	81.5
60	81.7
];
time = mydata(:,1);
mytemp = mydata(:,2);

figure;
hold all;
plot(time,mytemp,'r-o','Linewidth',2);
grid on;
set(gca,'FontSize',12);
xlabel('Time (min)','FontSize',12,'FontWeight','Bold')
ylabel('Maximum Temperature (C)','FontSize',12,'FontWeight','Bold')
ylim([0 100]);
xlim([-5 65])


%% Load stage-1 -- CH1
Ts = 0.1e-6;
time_DCload1 = (VarName1-VarName1(1))*1e3;
Tfinal = VarName1(end)-VarName1(1);
Vdc_load1 = VarName2;
Va_load1 = VarName3;
Vb_load1 = VarName4;
Vc_load1 = VarName5;

%% Load stage-2 -- CH1
Ts = 0.1e-6;
time_DCload2 = (VarName1-VarName1(1))*1e3;
Tfinal = VarName1(end)-VarName1(1);
Vdc_load2 = VarName2;
Va_load2 = VarName3;
Vb_load2 = VarName4;
Vc_load2 = VarName5;

%% Load stage-3 -- CH1
Ts = 0.1e-6;
time_DCload3 = (VarName1-VarName1(1))*1e3;
Tfinal = VarName1(end)-VarName1(1);
Vdc_load3 = VarName2;
Va_load3 = VarName3;
Vb_load3 = VarName4;
Vc_load3 = VarName5;

%% Load stage-4 -- CH1
Ts = 0.1e-6;
time_DCload4 = (VarName1-VarName1(1))*1e3;
Tfinal = VarName1(end)-VarName1(1);
Vdc_load4 = VarName2;
Va_load4 = VarName3;
Vb_load4 = VarName4;
Vc_load4 = VarName5;

%% Load stage-5 -- CH1
Ts = 0.1e-6;
time_DCload5 = (VarName1-VarName1(1))*1e3;
Tfinal = VarName1(end)-VarName1(1);
Vdc_load5 = VarName2;
Va_load5 = VarName3;
Vb_load5 = VarName4;
Vc_load5 = VarName5;

%%
figure;
hold all;
plot(time_DCload5,Va_load5,'r-','Linewidth',1);
grid on;
set(gca,'FontSize',12);
xlabel('Time (ms)','FontSize',12,'FontWeight','Bold')
ylabel('Voltage (Volts)','FontSize',12,'FontWeight','Bold')
%xlim([-10 20]);

%% -- CH1
save('voltage_data_for_efficiency.mat');

%% -- CH1
load('voltage_data_for_efficiency.mat');

%%
R1 = 101.878e-3;
R2 = 100.055e-3;
R3 = 101.934e-3;
R4 = 101.735e-3;

%% Load stage-1 -- CH2
Ts = 0.1e-6;
time_DC_a1_load1 = (VarName1-VarName1(1))*1e3;
Tfinal = VarName1(end)-VarName1(1);
Idc_a1_load1 = VarName2/R1;
Ia_a1_load1 = VarName3/R1;
Ib_a1_load1 = VarName4/R1;
Ic_a1_load1 = VarName5/R1;

%% Load stage-2 -- CH2
Ts = 0.1e-6;
time_DC_a1_load2 = (VarName1-VarName1(1))*1e3;
Tfinal = VarName1(end)-VarName1(1);
Idc_a1_load2 = VarName2/R1;
Ia_a1_load2 = VarName3/R1;
Ib_a1_load2 = VarName4/R1;
Ic_a1_load2 = VarName5/R1;

%% Load stage-3 -- CH2
Ts = 0.1e-6;
time_DC_a1_load3 = (VarName1-VarName1(1))*1e3;
Tfinal = VarName1(end)-VarName1(1);
Idc_a1_load3 = VarName2/R1;
Ia_a1_load3 = VarName3/R1;
Ib_a1_load3 = VarName4/R1;
Ic_a1_load3 = VarName5/R1;

%% Load stage-4 -- CH2
Ts = 0.1e-6;
time_DC_a1_load4 = (VarName1-VarName1(1))*1e3;
Tfinal = VarName1(end)-VarName1(1);
Idc_a1_load4 = VarName2/R1;
Ia_a1_load4 = VarName3/R1;
Ib_a1_load4 = VarName4/R1;
Ic_a1_load4 = VarName5/R1;

%% Load stage-5 -- CH2
Ts = 0.1e-6;
time_DC_a1_load5 = (VarName1-VarName1(1))*1e3;
Tfinal = VarName1(end)-VarName1(1);
Idc_a1_load5 = VarName2/R1;
Ia_a1_load5 = VarName3/R1;
Ib_a1_load5 = VarName4/R1;
Ic_a1_load5 = VarName5/R1;

%%
figure;
hold all;
plot(time_DC_a1_load5,Idc_a1_load5,'r-','Linewidth',1);
grid on;
set(gca,'FontSize',12);
xlabel('Time (ms)','FontSize',12,'FontWeight','Bold')
ylabel('Voltage (Volts)','FontSize',12,'FontWeight','Bold')
%xlim([-10 20]);

%% -- CH2
save('current_a1_data_for_efficiency.mat');

%% Load stage-1 -- CH3
Ts = 0.1e-6;
time_DC_a2_load1 = (VarName1-VarName1(1))*1e3;
Tfinal = VarName1(end)-VarName1(1);
Idc_a2_load1 = VarName2/R2;
Ia_a2_load1 = VarName3/R2;
Ib_a2_load1 = VarName4/R2;
Ic_a2_load1 = VarName5/R2;

%% Load stage-2 -- CH3
Ts = 0.1e-6;
time_DC_a2_load2 = (VarName1-VarName1(1))*1e3;
Tfinal = VarName1(end)-VarName1(1);
Idc_a2_load2 = VarName2/R2;
Ia_a2_load2 = VarName3/R2;
Ib_a2_load2 = VarName4/R2;
Ic_a2_load2 = VarName5/R2;

%% Load stage-3 -- CH3
Ts = 0.1e-6;
time_DC_a2_load3 = (VarName1-VarName1(1))*1e3;
Tfinal = VarName1(end)-VarName1(1);
Idc_a2_load3 = VarName2/R2;
Ia_a2_load3 = VarName3/R2;
Ib_a2_load3 = VarName4/R2;
Ic_a2_load3 = VarName5/R2;

%% Load stage-4 -- CH3
Ts = 0.1e-6;
time_DC_a2_load4 = (VarName1-VarName1(1))*1e3;
Tfinal = VarName1(end)-VarName1(1);
Idc_a2_load4 = VarName2/R2;
Ia_a2_load4 = VarName3/R2;
Ib_a2_load4 = VarName4/R2;
Ic_a2_load4 = VarName5/R2;

%% Load stage-5 -- CH3
Ts = 0.1e-6;
time_DC_a2_load5 = (VarName1-VarName1(1))*1e3;
Tfinal = VarName1(end)-VarName1(1);
Idc_a2_load5 = VarName2/R2;
Ia_a2_load5 = VarName3/R2;
Ib_a2_load5 = VarName4/R2;
Ic_a2_load5 = VarName5/R2;

%%
figure;
hold all;
plot(time_DC_a2_load5,Idc_a2_load5,'r-','Linewidth',1);
grid on;
set(gca,'FontSize',12);
xlabel('Time (ms)','FontSize',12,'FontWeight','Bold')
ylabel('Voltage (Volts)','FontSize',12,'FontWeight','Bold')
%xlim([-10 20]);

%% -- CH3
save('current_a2_data_for_efficiency.mat');


%%
% -- CH1
load('voltage_data_for_efficiency.mat');

% -- CH2
load('current_a1_data_for_efficiency.mat');

% -- CH3
load('current_a2_data_for_efficiency.mat');


