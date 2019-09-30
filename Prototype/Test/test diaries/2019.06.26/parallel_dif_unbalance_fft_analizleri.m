%% First, load the data into workspace
%load('ecce_parallel.mat');
%% A time-series object is created with time and data arrays to be imported in simulink model
% Then, a structure is obtained by a scope in Simulink to be able to apply FFT using power_fftscope
time_array = time_noint_200v_200khz - time_noint_200v_200khz(1);
Tstep = time_array(2) - time_array(1);
time_array3 = transpose(linspace(0.01,0.3,(0.3-0.01)/Tstep));
time_array=[ time_array; time_array3];
time_array2 = time_array(1:0.3/Tstep); % 5 seconds of data is taken

%No int - sum of currents
Idc_sum_noint_200v_200khz= Idcm1sh1_noint_200v_200khz + Idcm2sh3_noint_200v_200khz;
Idc_sum_noint_200v_200khzn= [Idc_sum_noint_200v_200khz; Idc_sum_noint_200v_200khz; Idc_sum_noint_200v_200khz; Idc_sum_noint_200v_200khz; Idc_sum_noint_200v_200khz; Idc_sum_noint_200v_200khz; Idc_sum_noint_200v_200khz; Idc_sum_noint_200v_200khz; Idc_sum_noint_200v_200khz; Idc_sum_noint_200v_200khz; Idc_sum_noint_200v_200khz; Idc_sum_noint_200v_200khz; Idc_sum_noint_200v_200khz; Idc_sum_noint_200v_200khz; Idc_sum_noint_200v_200khz; Idc_sum_noint_200v_200khz; Idc_sum_noint_200v_200khz; Idc_sum_noint_200v_200khz; Idc_sum_noint_200v_200khz; Idc_sum_noint_200v_200khz; Idc_sum_noint_200v_200khz];
Idc_sum_noint_200v_data = Idc_sum_noint_200v_200khzn(1:0.3/Tstep); % 5 seconds of data is taken
ts_Idc_sum_noint_200v = timeseries(Idc_sum_noint_200v_data,time_array2);

%No int - dif of currents
Idc_dif_noint_200v_200khz= Idcm1sh1_noint_200v_200khz - Idcm2sh3_noint_200v_200khz;
Idc_dif_noint_200v_200khzn= [Idc_dif_noint_200v_200khz; Idc_dif_noint_200v_200khz; Idc_dif_noint_200v_200khz; Idc_dif_noint_200v_200khz; Idc_dif_noint_200v_200khz; Idc_dif_noint_200v_200khz; Idc_dif_noint_200v_200khz; Idc_dif_noint_200v_200khz; Idc_dif_noint_200v_200khz; Idc_dif_noint_200v_200khz; Idc_dif_noint_200v_200khz; Idc_dif_noint_200v_200khz; Idc_dif_noint_200v_200khz; Idc_dif_noint_200v_200khz; Idc_dif_noint_200v_200khz; Idc_dif_noint_200v_200khz; Idc_dif_noint_200v_200khz; Idc_dif_noint_200v_200khz; Idc_dif_noint_200v_200khz; Idc_dif_noint_200v_200khz; Idc_dif_noint_200v_200khz];
Idc_dif_noint_200v_data = Idc_dif_noint_200v_200khzn(1:0.3/Tstep); % 5 seconds of data is taken
ts_Idc_dif_noint_200v = timeseries(Idc_dif_noint_200v_data,time_array2);

%Yes int - sum of currents
Idc_sum_yesint_200v_200khz= Idcm1sh1_yesint_200v_200khz + Idcm2sh3_yesint_200v_200khz;
Idc_sum_yesint_200v_200khzn= [Idc_sum_yesint_200v_200khz; Idc_sum_yesint_200v_200khz; Idc_sum_yesint_200v_200khz; Idc_sum_yesint_200v_200khz; Idc_sum_yesint_200v_200khz; Idc_sum_yesint_200v_200khz; Idc_sum_yesint_200v_200khz; Idc_sum_yesint_200v_200khz; Idc_sum_yesint_200v_200khz; Idc_sum_yesint_200v_200khz; Idc_sum_yesint_200v_200khz; Idc_sum_yesint_200v_200khz; Idc_sum_yesint_200v_200khz; Idc_sum_yesint_200v_200khz; Idc_sum_yesint_200v_200khz; Idc_sum_yesint_200v_200khz; Idc_sum_yesint_200v_200khz; Idc_sum_yesint_200v_200khz; Idc_sum_yesint_200v_200khz; Idc_sum_yesint_200v_200khz; Idc_sum_yesint_200v_200khz];
Idc_sum_yesint_200v_data = Idc_sum_yesint_200v_200khzn(1:0.3/Tstep); % 5 seconds of data is taken
ts_Idc_sum_yesint_200v = timeseries(Idc_sum_yesint_200v_data,time_array2);

%Yes int - dif of currents
Idc_dif_yesint_200v_200khz= Idcm1sh1_yesint_200v_200khz - Idcm2sh3_yesint_200v_200khz;
Idc_dif_yesint_200v_200khzn= [Idc_dif_yesint_200v_200khz; Idc_dif_yesint_200v_200khz; Idc_dif_yesint_200v_200khz; Idc_dif_yesint_200v_200khz; Idc_dif_yesint_200v_200khz; Idc_dif_yesint_200v_200khz; Idc_dif_yesint_200v_200khz; Idc_dif_yesint_200v_200khz; Idc_dif_yesint_200v_200khz; Idc_dif_yesint_200v_200khz; Idc_dif_yesint_200v_200khz; Idc_dif_yesint_200v_200khz; Idc_dif_yesint_200v_200khz; Idc_dif_yesint_200v_200khz; Idc_dif_yesint_200v_200khz; Idc_dif_yesint_200v_200khz; Idc_dif_yesint_200v_200khz; Idc_dif_yesint_200v_200khz; Idc_dif_yesint_200v_200khz; Idc_dif_yesint_200v_200khz; Idc_dif_yesint_200v_200khz];
Idc_dif_yesint_200v_data = Idc_dif_yesint_200v_200khzn(1:0.3/Tstep); % 5 seconds of data is taken
ts_Idc_dif_yesint_200v = timeseries(Idc_dif_yesint_200v_data,time_array2);

%% Run the simulation to obtain the structure for FFT analysis
sim('for_fft_dif.slx');
%% Adjust FFT parameters
fft_cycle = 10;
fft_start = 0;
fft_fund = 50;
fft_maxfreq = 200000;
fft_THDmaxfreq = 200000;
%% Idc no int  - sum of currents
Idc_sum_noint_200v_forfft_FFTDATA = power_fftscope(Idc_sum_noint_200v_forfft);
Idc_sum_noint_200v_forfft_FFTDATA.startTime = fft_start;
Idc_sum_noint_200v_forfft_FFTDATA.cycles = fft_cycle; 
Idc_sum_noint_200v_forfft_FFTDATA.fundamental = fft_fund; 
Idc_sum_noint_200v_forfft_FFTDATA.maxFrequency = fft_maxfreq;
Idc_sum_noint_200v_forfft_FFTDATA.THDmaxFrequency = fft_THDmaxfreq;
Idc_sum_noint_200v_forfft_FFTDATA = power_fftscope(Idc_sum_noint_200v_forfft_FFTDATA);
%% Idc no int  - dif of currents
Idc_dif_noint_200v_forfft_FFTDATA = power_fftscope(Idc_dif_noint_200v_forfft);
Idc_dif_noint_200v_forfft_FFTDATA.startTime = fft_start;
Idc_dif_noint_200v_forfft_FFTDATA.cycles = fft_cycle; 
Idc_dif_noint_200v_forfft_FFTDATA.fundamental = fft_fund; 
Idc_dif_noint_200v_forfft_FFTDATA.maxFrequency = fft_maxfreq;
Idc_dif_noint_200v_forfft_FFTDATA.THDmaxFrequency = fft_THDmaxfreq;
Idc_dif_noint_200v_forfft_FFTDATA = power_fftscope(Idc_dif_noint_200v_forfft_FFTDATA);
%% Idc yes int  - sum of currents
Idc_sum_yesint_200v_forfft_FFTDATA = power_fftscope(Idc_sum_yesint_200v_forfft);
Idc_sum_yesint_200v_forfft_FFTDATA.startTime = fft_start;
Idc_sum_yesint_200v_forfft_FFTDATA.cycles = fft_cycle; 
Idc_sum_yesint_200v_forfft_FFTDATA.fundamental = fft_fund; 
Idc_sum_yesint_200v_forfft_FFTDATA.maxFrequency = fft_maxfreq;
Idc_sum_yesint_200v_forfft_FFTDATA.THDmaxFrequency = fft_THDmaxfreq;
Idc_sum_yesint_200v_forfft_FFTDATA = power_fftscope(Idc_sum_yesint_200v_forfft_FFTDATA);
%% Idc yes int  - dif of currents
Idc_dif_yesint_200v_forfft_FFTDATA = power_fftscope(Idc_dif_yesint_200v_forfft);
Idc_dif_yesint_200v_forfft_FFTDATA.startTime = fft_start;
Idc_dif_yesint_200v_forfft_FFTDATA.cycles = fft_cycle; 
Idc_dif_yesint_200v_forfft_FFTDATA.fundamental = fft_fund; 
Idc_dif_yesint_200v_forfft_FFTDATA.maxFrequency = fft_maxfreq;
Idc_dif_yesint_200v_forfft_FFTDATA.THDmaxFrequency = fft_THDmaxfreq;
Idc_dif_yesint_200v_forfft_FFTDATA = power_fftscope(Idc_dif_yesint_200v_forfft_FFTDATA);
%% This part is result analysis
% num = numel(Idc_sum_yesint_200v_forfft_FFTDATA.mag);
% Vtot400V_DCcomp = Idc_sum_yesint_200v_forfft_FFTDATA.mag(1);
% Vm1400V_DCcomp = Idc_dif_yesint_200v_forfft_FFTDATA.mag(1);
% fprintf('Resolution: %g Hertz\n',Idc_sum_yesint_200v_forfft_FFTDATA.freq(2));
% fprintf('Starting point: %g seconds\n',fft_start);
% fprintf('Length of Data: %g seconds\n',1/fft_fund*fft_cycle);
% %% Vdctot without Interleaving
% fprintf('\nHarmonics without Interleaving:\n');
% for k = 1:num
%     if (Idc_sum_yesint_200v_forfft_FFTDATA.mag(k) >= Vtot400V_DCcomp*0.002)
%         fprintf('Freq: %g, Mag: %g, Phase: %g\n',...
%             Idc_sum_yesint_200v_forfft_FFTDATA.freq(k),...
%             Idc_sum_yesint_200v_forfft_FFTDATA.mag(k),...
%             Idc_sum_yesint_200v_forfft_FFTDATA.phase(k));
%     end    
% end
% %% Vdctot with Interleaving
% fprintf('\nHarmonics with Interleaving:\n');
% for k = 1:num
%     if (Idc_dif_yesint_200v_forfft_FFTDATA.mag(k) >= Vm1400V_DCcomp*0.002)
%         fprintf('Freq: %g, Mag: %g, Phase: %g\n',...
%             Idc_dif_yesint_200v_forfft_FFTDATA.freq(k),...
%             Idc_dif_yesint_200v_forfft_FFTDATA.mag(k),...
%             Idc_dif_yesint_200v_forfft_FFTDATA.phase(k));
%     end    
% end
%% Plot the FFT result (magnitude) for Idc - no int - sum of currents
% figure;
% hold all;
% plot(Idc_sum_noint_200v_forfft_FFTDATA.freq,Idc_sum_noint_200v_forfft_FFTDATA.mag,'bo-','Linewidth',1);
% set(gca,'FontSize',14);
% xlabel('Frequency (Hertz)','FontSize',14,'FontWeight','Bold')
% ylabel('FFT of Total DC Link Voltage without Interleaving (Volts)','FontSize',14,'FontWeight','Bold')
% xlim([-1 1000]);
% ylim([0 10]);
% title('Parallel - 200V - Yes int');
% 
% %% Plot the FFT result (magnitude) for Idc - no int - dif of currents
% figure;
% hold all;
% plot(Idc_dif_noint_200v_forfft_FFTDATA.freq,Idc_dif_noint_200v_forfft_FFTDATA.mag,'bo-','Linewidth',1);
% set(gca,'FontSize',14);
% xlabel('Frequency (Hertz)','FontSize',14,'FontWeight','Bold')
% ylabel('FFT of Total DC Link Voltage with Interleaving (Volts)','FontSize',14,'FontWeight','Bold')
% xlim([-1 1000]);
% %ylim([0 2]);
% title('Parallel - 200V - No int');
%% Plot the FFT result (magnitude) all together
figure;
hold all;
plot(Idc_sum_noint_200v_forfft_FFTDATA.freq,Idc_sum_noint_200v_forfft_FFTDATA.mag,'bo-','Linewidth',1);
plot(Idc_sum_yesint_200v_forfft_FFTDATA.freq,Idc_sum_yesint_200v_forfft_FFTDATA.mag,'ro-','Linewidth',1);
set(gca,'FontSize',14);
xlabel('Frequency (Hertz)','FontSize',14,'FontWeight','Bold')
ylabel('FFT of Total DC Link Voltage (Volts)','FontSize',14,'FontWeight','Bold')
%xlim([39000 41000]);
%ylim([0 0.1]);
 grid on
legend('No Interleaving','Yes Interleaving');
title('Sum of currents - Parallel - 200V - 200 kHz ');
%% Plot the FFT result (magnitude) all together
figure;
hold all;
plot(Idc_dif_noint_200v_forfft_FFTDATA.freq,Idc_dif_noint_200v_forfft_FFTDATA.mag,'bo-','Linewidth',1);
plot(Idc_dif_yesint_200v_forfft_FFTDATA.freq,Idc_dif_yesint_200v_forfft_FFTDATA.mag,'ro-','Linewidth',1);
set(gca,'FontSize',14);
xlabel('Frequency (Hertz)','FontSize',14,'FontWeight','Bold')
ylabel('FFT of Total DC Link Voltage (Volts)','FontSize',14,'FontWeight','Bold')
 xlim([0 1000]);
ylim([0 0.1]);
 grid on
legend('No Interleaving','Yes Interleaving');
title('Difference of currents - Parallel - 200V - 200 kHz');