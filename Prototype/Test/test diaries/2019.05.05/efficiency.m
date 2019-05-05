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

Efficiency1_Load1 = 100*Avrg_Power_AC1_Load1/Avrg_Power_DC_Load1
Efficiency2_Load1 = 100*Avrg_Power_AC2_Load1/Avrg_Power_DC_Load1


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

Efficiency1_Load2 = 100*Avrg_Power_AC1_Load2/Avrg_Power_DC_Load2
Efficiency2_Load2 = 100*Avrg_Power_AC2_Load2/Avrg_Power_DC_Load2


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

loading = 1:5;
load_power = loading*400;

figure;
hold all;
plot(load_power,Efficiency1,'b-o','Linewidth',2);
plot(load_power,Efficiency2,'r-o','Linewidth',2);
grid on;
set(gca,'FontSize',12);
xlabel('Load Power (W)','FontSize',12,'FontWeight','Bold')
ylabel('Efficiency (%)','FontSize',12,'FontWeight','Bold')
ylim([90 110]);
xlim([300 2100])
