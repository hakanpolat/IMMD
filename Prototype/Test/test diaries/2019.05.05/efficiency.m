%%
% -- CH1
load('voltage_data_for_efficiency.mat');

% -- CH2
load('current_a1_data_for_efficiency.mat');

% -- CH3
load('current_a2_data_for_efficiency.mat');

%% Averaging window
window_period = 20e-3;
time_offset = 0e-3;
index_offset = time_offset/Ts;
start_index = index_offset+1;
stop_index = start_index+window_period/Ts;

freq_fourier = 50; % Hz

%% Efficiency Load-1
Inst_Power_PhaseA_Load1 = Va_load1.*(Ia_a1_load1+Ia_a2_load1);
Inst_Power_PhaseB_Load1 = Vb_load1.*(Ib_a1_load1+Ib_a2_load1);
Inst_Power_PhaseC_Load1 = Vc_load1.*(Ic_a1_load1+Ic_a2_load1);
Inst_Power_DC_Load1 = Vdc_load1.*(Idc_a1_load1+Idc_a2_load1);
Inst_Power_AC_Load1 = Inst_Power_PhaseA_Load1(start_index:stop_index)+...
                      Inst_Power_PhaseB_Load1(start_index:stop_index)+...
                      Inst_Power_PhaseB_Load1(start_index:stop_index);

Avrg_Power_PhaseA_Load1 = mean(Inst_Power_PhaseA_Load1(start_index:stop_index));
Avrg_Power_PhaseB_Load1 = mean(Inst_Power_PhaseB_Load1(start_index:stop_index));
Avrg_Power_PhaseC_Load1 = mean(Inst_Power_PhaseC_Load1(start_index:stop_index));
Avrg_Power_DC_Load1 = mean(Inst_Power_DC_Load1(start_index:stop_index));
Avrg_Power_AC1_Load1 = mean(Inst_Power_AC_Load1);
Avrg_Power_AC2_Load1 = Avrg_Power_PhaseA_Load1+Avrg_Power_PhaseB_Load1+Avrg_Power_PhaseC_Load1;

Efficiency1_Load1 = 100*Avrg_Power_AC1_Load1/Avrg_Power_DC_Load1;
Efficiency2_Load1 = 100*Avrg_Power_AC2_Load1/Avrg_Power_DC_Load1;
Wattmeter_Power_DC_Load1 = 398;
Efficiency3_Load1 = 100*Avrg_Power_AC2_Load1/Wattmeter_Power_DC_Load1;


%% Efficiency Load-2
Inst_Power_PhaseA_Load2 = Va_load2.*(Ia_a1_load2+Ia_a2_load2);
Inst_Power_PhaseB_Load2 = Vb_load2.*(Ib_a1_load2+Ib_a2_load2);
Inst_Power_PhaseC_Load2 = Vc_load2.*(Ic_a1_load2+Ic_a2_load2);
Inst_Power_DC_Load2 = Vdc_load2.*(Idc_a1_load2+Idc_a2_load2);
Inst_Power_AC_Load2 = Inst_Power_PhaseA_Load2(start_index:stop_index)+...
                      Inst_Power_PhaseB_Load2(start_index:stop_index)+...
                      Inst_Power_PhaseB_Load2(start_index:stop_index);

Avrg_Power_PhaseA_Load2 = mean(Inst_Power_PhaseA_Load2(start_index:stop_index));
Avrg_Power_PhaseB_Load2 = mean(Inst_Power_PhaseB_Load2(start_index:stop_index));
Avrg_Power_PhaseC_Load2 = mean(Inst_Power_PhaseC_Load2(start_index:stop_index));
Avrg_Power_DC_Load2 = mean(Inst_Power_DC_Load2(start_index:stop_index));
Avrg_Power_AC1_Load2 = mean(Inst_Power_AC_Load2);
Avrg_Power_AC2_Load2 = Avrg_Power_PhaseA_Load2+Avrg_Power_PhaseB_Load2+Avrg_Power_PhaseC_Load2;

Efficiency1_Load2 = 100*Avrg_Power_AC1_Load2/Avrg_Power_DC_Load2;
Efficiency2_Load2 = 100*Avrg_Power_AC2_Load2/Avrg_Power_DC_Load2;
Wattmeter_Power_DC_Load2 = 775;
Efficiency3_Load2 = 100*Avrg_Power_AC2_Load2/Wattmeter_Power_DC_Load2;


%% Efficiency Load-3
Inst_Power_PhaseA_Load3 = Va_load3.*(Ia_a1_load3+Ia_a2_load3);
Inst_Power_PhaseB_Load3 = Vb_load3.*(Ib_a1_load3+Ib_a2_load3);
Inst_Power_PhaseC_Load3 = Vc_load3.*(Ic_a1_load3+Ic_a2_load3);
Inst_Power_DC_Load3 = Vdc_load3.*(Idc_a1_load3+Idc_a2_load3);
Inst_Power_AC_Load3 = Inst_Power_PhaseA_Load3+Inst_Power_PhaseB_Load3+Inst_Power_PhaseB_Load3;

Avrg_Power_PhaseA_Load3 = mean(Inst_Power_PhaseA_Load3);
Avrg_Power_PhaseB_Load3 = mean(Inst_Power_PhaseB_Load3);
Avrg_Power_PhaseC_Load3 = mean(Inst_Power_PhaseC_Load3);
Avrg_Power_DC_Load3 = mean(Inst_Power_DC_Load3);
Avrg_Power_AC1_Load3 = mean(Inst_Power_AC_Load3);
Avrg_Power_AC2_Load3 = Avrg_Power_PhaseA_Load3+Avrg_Power_PhaseB_Load3+Avrg_Power_PhaseC_Load3;

Efficiency1_Load3 = 100*Avrg_Power_AC1_Load3/Avrg_Power_DC_Load3;
Efficiency2_Load3 = 100*Avrg_Power_AC2_Load3/Avrg_Power_DC_Load3;
Wattmeter_Power_DC_Load3 = 1150;
Efficiency3_Load3 = 100*Avrg_Power_AC2_Load3/Wattmeter_Power_DC_Load3;


%% Efficiency Load-4
Inst_Power_PhaseA_Load4 = Va_load4.*(Ia_a1_load4+Ia_a2_load4);
Inst_Power_PhaseB_Load4 = Vb_load4.*(Ib_a1_load4+Ib_a2_load4);
Inst_Power_PhaseC_Load4 = Vc_load4.*(Ic_a1_load4+Ic_a2_load4);
Inst_Power_DC_Load4 = Vdc_load4.*(Idc_a1_load4+Idc_a2_load4);
Inst_Power_AC_Load4 = Inst_Power_PhaseA_Load4+Inst_Power_PhaseB_Load4+Inst_Power_PhaseB_Load4;

Avrg_Power_PhaseA_Load4 = mean(Inst_Power_PhaseA_Load4);
Avrg_Power_PhaseB_Load4 = mean(Inst_Power_PhaseB_Load4);
Avrg_Power_PhaseC_Load4 = mean(Inst_Power_PhaseC_Load4);
Avrg_Power_DC_Load4 = mean(Inst_Power_DC_Load4);
Avrg_Power_AC1_Load4 = mean(Inst_Power_AC_Load4);
Avrg_Power_AC2_Load4 = Avrg_Power_PhaseA_Load4+Avrg_Power_PhaseB_Load4+Avrg_Power_PhaseC_Load4;

Efficiency1_Load4 = 100*Avrg_Power_AC1_Load4/Avrg_Power_DC_Load4;
Efficiency2_Load4 = 100*Avrg_Power_AC2_Load4/Avrg_Power_DC_Load4;
Wattmeter_Power_DC_Load4 = 1530;
Efficiency3_Load4 = 100*Avrg_Power_AC2_Load4/Wattmeter_Power_DC_Load4;


%% Efficiency Load-5
Inst_Power_PhaseA_Load5 = Va_load5.*(Ia_a1_load5+Ia_a2_load5);
Inst_Power_PhaseB_Load5 = Vb_load5.*(Ib_a1_load5+Ib_a2_load5);
Inst_Power_PhaseC_Load5 = Vc_load5.*(Ic_a1_load5+Ic_a2_load5);
Inst_Power_DC_Load5 = Vdc_load5.*(Idc_a1_load5+Idc_a2_load5);
Inst_Power_AC_Load5 = Inst_Power_PhaseA_Load5+Inst_Power_PhaseB_Load5+Inst_Power_PhaseB_Load5;

Avrg_Power_PhaseA_Load5 = mean(Inst_Power_PhaseA_Load5);
Avrg_Power_PhaseB_Load5 = mean(Inst_Power_PhaseB_Load5);
Avrg_Power_PhaseC_Load5 = mean(Inst_Power_PhaseC_Load5);
Avrg_Power_DC_Load5 = mean(Inst_Power_DC_Load5);
Avrg_Power_AC1_Load5 = mean(Inst_Power_AC_Load5);
Avrg_Power_AC2_Load5 = Avrg_Power_PhaseA_Load5+Avrg_Power_PhaseB_Load5+Avrg_Power_PhaseC_Load5;

Efficiency1_Load5 = 100*Avrg_Power_AC1_Load5/Avrg_Power_DC_Load5;
Efficiency2_Load5 = 100*Avrg_Power_AC2_Load5/Avrg_Power_DC_Load5;
Wattmeter_Power_DC_Load5 = 1910;
Efficiency3_Load5 = 100*Avrg_Power_AC2_Load5/Wattmeter_Power_DC_Load5;


%% Plots

Efficiency1 = [Efficiency1_Load1
               Efficiency1_Load2
               Efficiency1_Load3
               Efficiency1_Load4
               Efficiency1_Load5];

Efficiency2 = [Efficiency2_Load1
               Efficiency2_Load2
               Efficiency2_Load3
               Efficiency2_Load4
               Efficiency2_Load5];

Efficiency3 = [Efficiency3_Load1
               Efficiency3_Load2
               Efficiency3_Load3
               Efficiency3_Load4
               Efficiency3_Load5];

loading = 1:5;
load_power = loading*400;

figure;
hold all;
plot(load_power,Efficiency1,'b-o','Linewidth',2);
plot(load_power,Efficiency2,'r-o','Linewidth',2);
plot(load_power,Efficiency3,'k-o','Linewidth',2);
grid on;
set(gca,'FontSize',12);
xlabel('Load Power (W)','FontSize',12,'FontWeight','Bold')
ylabel('Efficiency (%)','FontSize',12,'FontWeight','Bold')
ylim([90 102]);
xlim([300 2100])

%%
%%akim_load1 = max(Idc_a1_load1)
Loss_data_Load1 = Wattmeter_Power_DC_Load1 - Avrg_Power_AC2_Load1;
Loss_data_Load2 = Wattmeter_Power_DC_Load2 - Avrg_Power_AC2_Load2;
Loss_data_Load3 = Wattmeter_Power_DC_Load3 - Avrg_Power_AC2_Load3;
Loss_data_Load4 = Wattmeter_Power_DC_Load4 - Avrg_Power_AC2_Load4;
Loss_data_Load5 = Wattmeter_Power_DC_Load5 - Avrg_Power_AC2_Load5;
Loss_data = [Loss_data_Load1
             Loss_data_Load2
             Loss_data_Load3
             Loss_data_Load4
             Loss_data_Load5];

%%
Wattmeter_Power_DC = [1910,1530,1150,775,398];
Simulasyon_Inst_Power_AC = [1893,1514,1140,767.7,390.6];
Simulasyon_Fund_Power_AC = [1890,1512,1138,766.2,389.8];

PCB_loss = 2.85;
Capacitor_loss = 0.3;
Loss_data_ACinst = Wattmeter_Power_DC' - Simulasyon_Inst_Power_AC';
Loss_data_ACfund = Wattmeter_Power_DC' - Simulasyon_Fund_Power_AC';
Loss_data_Furkan = [18.15776307,10.82091244,6.084196153,3.057558565,1.298884292];
Loss_data_Furkan = Capacitor_loss + Loss_data_Furkan;
Loss_data_Ozan   = [21,15.7,12.0,9.3,5.6]-PCB_loss;

Efficiency_ACinst = Simulasyon_Inst_Power_AC'./Wattmeter_Power_DC'*100;
Efficiency_ACfund = Simulasyon_Fund_Power_AC'./Wattmeter_Power_DC'*100;
Efficiency_Furkan = (Wattmeter_Power_DC' - Loss_data_Furkan')./Wattmeter_Power_DC'*100;
Efficiency_Ozan = (Wattmeter_Power_DC' - Loss_data_Ozan')./Wattmeter_Power_DC'*100;
Efficiency_exp_from_sim = [98.97,98.78,99.02,98.89,97.99];

load_power = 400*[5,4,3,2,1];


figure;
hold all;
plot(load_power,Efficiency_Furkan,'r-o','Linewidth',2);
%plot(load_power,smooth(Efficiency_Furkan),'r-o','Linewidth',2);
plot(load_power,Efficiency_ACfund,'k-x','Linewidth',2);
%plot(load_power,smooth(Efficiency_ACfund),'b-o','Linewidth',2);
plot(load_power,Efficiency_Ozan,'b-+','Linewidth',2);
%plot(load_power,smooth(Efficiency_Ozan),'g-o','Linewidth',2);
grid on;
set(gca,'FontSize',12);
xlabel('Load Power (W)','FontSize',12,'FontWeight','Bold')
ylabel('Efficiency (%)','FontSize',12,'FontWeight','Bold')
ylim([95 100]);
xlim([300 2100])
%legend('Instantaneous AC Power','Fundamental AC Power','Furkan','Ozan');
legend('Calculated','Experimental','Estimated from Thermal Data');
