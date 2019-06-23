time_data_200kfilt = VarName1;
Vcap_phA_200kfilt = VarName2;
Vcap_phB_200kfilt = VarName3;
Vcap_phC_200kfilt = VarName4;
Vcap_phA_725kfilt = VarName5;
Vcap_phB_725kfilt = VarName6;
Vcap_phC_725kfilt = VarName7;
time_data_725kfilt = VarName8;

%%
figure;
hold all;
plot(time_data_200kfilt*1e3,Vcap_phA_200kfilt,'r-','Linewidth',1);
plot(time_data_200kfilt*1e3,Vcap_phB_200kfilt,'b-','Linewidth',1);
plot(time_data_200kfilt*1e3,Vcap_phC_200kfilt,'k-','Linewidth',1);
set(gca,'FontSize',14);
xlabel('Time (ms)','FontSize',14,'FontWeight','Bold')
ylabel('Voltage (V)','FontSize',14,'FontWeight','Bold')
%xlim([0 100e-6]);
%ylim([0.5 1.1]);
legend({'phA','phB','phC'},'Location','best');

%%
figure;
hold all;
plot(time_data_725kfilt,Vcap_phA_725kfilt,'b-','Linewidth',1);
plot(time_data_200kfilt,Vcap_phA_200kfilt,'r-','Linewidth',1);
set(gca,'FontSize',14);
xlabel('Time (ms)','FontSize',14,'FontWeight','Bold')
ylabel('Voltage (V)','FontSize',14,'FontWeight','Bold')
%xlim([0 100e-6]);
%ylim([0.5 1.1]);
%legend({'ma2','ma1','Limit'},'Location','best');

%%
Cdc_single = 5e-6; % F
Icap_phA_200kfilt = Cdc_single * (diff(Vcap_phA_200kfilt)./diff(time_data_200kfilt));
Icap_phB_200kfilt = Cdc_single * (diff(Vcap_phB_200kfilt)./diff(time_data_200kfilt));
Icap_phC_200kfilt = Cdc_single * (diff(Vcap_phC_200kfilt)./diff(time_data_200kfilt));
Icap_phA_725kfilt = Cdc_single * (diff(Vcap_phA_725kfilt)./diff(time_data_725kfilt));
Icap_phB_725kfilt = Cdc_single * (diff(Vcap_phB_725kfilt)./diff(time_data_725kfilt));
Icap_phC_725kfilt = Cdc_single * (diff(Vcap_phC_725kfilt)./diff(time_data_725kfilt));

num_200kfilt = numel(Icap_phA_200kfilt);
num_725kfilt = numel(Icap_phA_725kfilt);

%%
figure;
hold all;
plot(time_data_200kfilt(1:num_200kfilt),Icap_phA_200kfilt,'b-','Linewidth',1);
plot(time_data_725kfilt(1:num_725kfilt),Icap_phA_725kfilt,'r-','Linewidth',1);
set(gca,'FontSize',14);
xlabel('Time (ms)','FontSize',14,'FontWeight','Bold')
ylabel('Current (A)','FontSize',14,'FontWeight','Bold')
xlim([0 100e-6]);
ylim([-2 2]);
%legend({'ma2','ma1','Limit'},'Location','best');


%%
figure;
hold all;
plot(time_data_200kfilt(1:num_200kfilt),Icap_phA_200kfilt,'b-','Linewidth',1);
plot(time_data_200kfilt(1:num_200kfilt),Icap_phB_200kfilt,'r-','Linewidth',1);
plot(time_data_200kfilt(1:num_200kfilt),Icap_phC_200kfilt,'k-','Linewidth',1);
set(gca,'FontSize',14);
xlabel('Time (ms)','FontSize',14,'FontWeight','Bold')
ylabel('Current (A)','FontSize',14,'FontWeight','Bold')
xlim([0 100e-6]);
%ylim([0.5 1.1]);
%legend({'ma2','ma1','Limit'},'Location','best');

%%
figure;
hold all;
plot(time_data_725kfilt(1:num_725kfilt),Icap_phA_725kfilt,'b-','Linewidth',1);
plot(time_data_725kfilt(1:num_725kfilt),Icap_phB_725kfilt,'r-','Linewidth',1);
plot(time_data_725kfilt(1:num_725kfilt),Icap_phC_725kfilt,'k-','Linewidth',1);
set(gca,'FontSize',14);
xlabel('Time (ms)','FontSize',14,'FontWeight','Bold')
ylabel('Current (A)','FontSize',14,'FontWeight','Bold')
xlim([0 100e-6]);
%ylim([0.5 1.1]);
%legend({'ma2','ma1','Limit'},'Location','best');

%% RMS
total_sample_200kfilt = num_200kfilt;
total_sample_725kfilt = num_725kfilt;
sampling_time = 40e-9;
cycle_time = 1/40e3*10;
cycle_sample = cycle_time/sampling_time;
total_cycle_200kfilt = floor(total_sample_200kfilt/cycle_sample);
total_cycle_725kfilt = floor(total_sample_725kfilt/cycle_sample);

Icap_rms_phA_200kfilt = zeros(1,total_cycle_200kfilt-cycle_sample);
Icap_rms_phB_200kfilt = zeros(1,total_cycle_200kfilt-cycle_sample);
Icap_rms_phC_200kfilt = zeros(1,total_cycle_200kfilt-cycle_sample);
Icap_rms_phA_725kfilt = zeros(1,total_cycle_725kfilt-cycle_sample);
Icap_rms_phB_725kfilt = zeros(1,total_cycle_725kfilt-cycle_sample);
Icap_rms_phC_725kfilt = zeros(1,total_cycle_725kfilt-cycle_sample);


%%
for k = cycle_sample+1:total_sample_200kfilt
    rms_pha = 0;
    rms_phb = 0;
    rms_phc = 0;
    for l = 1:cycle_sample
        rms_pha = rms_pha + Icap_phA_200kfilt(k-cycle_sample+l)^2;
        rms_phb = rms_phb + Icap_phB_200kfilt(k-cycle_sample+l)^2;
        rms_phc = rms_phc + Icap_phC_200kfilt(k-cycle_sample+l)^2;
    end
    Icap_rms_phA_200kfilt(k) = sqrt(rms_pha/cycle_sample);
    Icap_rms_phB_200kfilt(k) = sqrt(rms_phb/cycle_sample);
    Icap_rms_phC_200kfilt(k) = sqrt(rms_phc/cycle_sample);
end
num2_rms_200kfilt = numel(Icap_rms_phA_200kfilt);

for k = cycle_sample+1:total_sample_725kfilt
    rms_pha = 0;
    rms_phb = 0;
    rms_phc = 0;
    for l = 1:cycle_sample
        rms_pha = rms_pha + Icap_phA_725kfilt(k-cycle_sample+l)^2;
        rms_phb = rms_phb + Icap_phB_725kfilt(k-cycle_sample+l)^2;
        rms_phc = rms_phc + Icap_phC_725kfilt(k-cycle_sample+l)^2;
    end
    Icap_rms_phA_725kfilt(k) = sqrt(rms_pha/cycle_sample);
    Icap_rms_phB_725kfilt(k) = sqrt(rms_phb/cycle_sample);
    Icap_rms_phC_725kfilt(k) = sqrt(rms_phc/cycle_sample);
end
num2_rms_725kfilt = numel(Icap_rms_phA_725kfilt);

%%
figure;
hold all;
plot(time_data_200kfilt(1:num2_rms_200kfilt),Icap_rms_phA_200kfilt,'b-','Linewidth',1);
plot(time_data_200kfilt(1:num2_rms_200kfilt),Icap_rms_phB_200kfilt,'r-','Linewidth',1);
plot(time_data_200kfilt(1:num2_rms_200kfilt),Icap_rms_phC_200kfilt,'k-','Linewidth',1);
set(gca,'FontSize',14);
xlabel('Time (ms)','FontSize',14,'FontWeight','Bold')
ylabel('Current (A)','FontSize',14,'FontWeight','Bold')
%xlim([0 100e-6]);
%ylim([0.5 1.1]);
legend({'phA','phB','phC'},'Location','best');

%%
figure;
hold all;
plot(time_data_725kfilt(1:num2_rms_725kfilt),Icap_rms_phA_725kfilt,'b-','Linewidth',1);
plot(time_data_725kfilt(1:num2_rms_725kfilt),Icap_rms_phB_725kfilt,'r-','Linewidth',1);
plot(time_data_725kfilt(1:num2_rms_725kfilt),Icap_rms_phC_725kfilt,'k-','Linewidth',1);
set(gca,'FontSize',14);
xlabel('Time (ms)','FontSize',14,'FontWeight','Bold')
ylabel('Current (A)','FontSize',14,'FontWeight','Bold')
%xlim([0 100e-6]);
%ylim([0.5 1.1]);
legend({'phA','phB','phC'},'Location','best');
