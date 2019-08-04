%% First, load the data into workspace
%load('series_unbalance_data.mat');
%% These are the original time and data arrays (to be modified)
time_genis_Vdctot_400v_240v;
genis_Vdctot_400v_240v;
time_genis_Vdcm1_400v_240v;
genis_Vdcm1_400v_240v;
time_genis_Vdcm2_400v_240v;
genis_Vdcm2_400v_240v;
%% A time-series object is created with time and data arrays to be imported in simulink model
% Then, a structure is obtained by a scope in Simulink to be able to apply FFT using power_fftscope
time_array = time_genis_Vdctot_400v_240v - time_genis_Vdctot_400v_240v(1);
Tstep = time_array(2) - time_array(1);
time_array2 = time_array(1:5/Tstep); % 5 seconds of data is taken
Vdctot_400v_data = genis_Vdctot_400v_240v(1:5/Tstep); % 5 seconds of data is taken
Vdcm1_400v_data = genis_Vdcm1_400v_240v(1:5/Tstep);
Vdcm2_400v_data = genis_Vdcm2_400v_240v(1:5/Tstep);
ts_Vdctot_400v = timeseries(Vdctot_400v_data,time_array2);
ts_Vdcm1_400v = timeseries(Vdcm1_400v_data,time_array2);
ts_Vdcm2_400v = timeseries(Vdcm2_400v_data,time_array2);
%% Run the simulation to obtain the structure for FFT analysis
sim('for_fft.slx');
%% Adjust FFT parameters
fft_cycle = 10;
fft_start = 0;
fft_fund = 50;
fft_maxfreq = 200000;
fft_THDmaxfreq = 200000;
%% Apply FFT to the obtained strcuture
%% Vdctotal
Vtot400V_FFTDATA = power_fftscope(Vdctot_400v_forfft);
Vtot400V_FFTDATA.startTime = fft_start;
Vtot400V_FFTDATA.cycles = fft_cycle; 
Vtot400V_FFTDATA.fundamental = fft_fund; 
Vtot400V_FFTDATA.maxFrequency = fft_maxfreq;
Vtot400V_FFTDATA.THDmaxFrequency = fft_THDmaxfreq;
Vtot400V_FFTDATA = power_fftscope(Vtot400V_FFTDATA);
%% Vdcm1
Vm1400V_FFTDATA = power_fftscope(Vdcm1_400v_forfft);
Vm1400V_FFTDATA.startTime = fft_start;
Vm1400V_FFTDATA.cycles = fft_cycle; 
Vm1400V_FFTDATA.fundamental = fft_fund; 
Vm1400V_FFTDATA.maxFrequency = fft_maxfreq;
Vm1400V_FFTDATA.THDmaxFrequency = fft_THDmaxfreq;
Vm1400V_FFTDATA = power_fftscope(Vm1400V_FFTDATA);
%% Vdcm2
Vm2400V_FFTDATA = power_fftscope(Vdcm2_400v_forfft);
Vm2400V_FFTDATA.startTime = fft_start;
Vm2400V_FFTDATA.cycles = fft_cycle; 
Vm2400V_FFTDATA.fundamental = fft_fund; 
Vm2400V_FFTDATA.maxFrequency = fft_maxfreq;
Vm2400V_FFTDATA.THDmaxFrequency = fft_THDmaxfreq;
Vm2400V_FFTDATA = power_fftscope(Vm2400V_FFTDATA);
%% This part is result analysis
num = numel(Vtot400V_FFTDATA.mag);
Vtot400V_DCcomp = Vtot400V_FFTDATA.mag(1);
Vm1400V_DCcomp = Vm1400V_FFTDATA.mag(1);
Vm2400V_DCcomp = Vm2400V_FFTDATA.mag(1);
%Vtot400V_Fundcomp = Vtot400V_FFTDATA.mag(Vtot400V_FFTDATA.freq == 50);
%clc;
%fprintf('DC component: %g\n',Vtot400V_DCcomp);
%fprintf('Fundamental component: %g\n',Vtot400V_Fundcomp);
fprintf('Resolution: %g Hertz\n',Vtot400V_FFTDATA.freq(2));
fprintf('Starting point: %g seconds\n',fft_start);
fprintf('Length of Data: %g seconds\n',1/fft_fund*fft_cycle);
%% Vdctot harmonics
fprintf('\nHarmonics of Vdctotal:\n');
for k = 1:num
    if (Vtot400V_FFTDATA.mag(k) >= Vtot400V_DCcomp*0.2)
        fprintf('Freq: %g, Mag: %g, Phase: %g\n',...
            Vtot400V_FFTDATA.freq(k),...
            Vtot400V_FFTDATA.mag(k),...
            Vtot400V_FFTDATA.phase(k));
    end    
end
%% Vdcm1 harmonics
fprintf('\nHarmonics of Vdcm1:\n');
for k = 1:num
    if (Vm1400V_FFTDATA.mag(k) >= Vm1400V_DCcomp*0.2)
        fprintf('Freq: %g, Mag: %g, Phase: %g\n',...
            Vm1400V_FFTDATA.freq(k),...
            Vm1400V_FFTDATA.mag(k),...
            Vm1400V_FFTDATA.phase(k));
    end    
end
%% Vdcm2 harmonics
fprintf('\nHarmonics of Vdcm2:\n');
for k = 1:num
    if (Vm2400V_FFTDATA.mag(k) >= Vm2400V_DCcomp*0.5)
        fprintf('Freq: %g, Mag: %g, Phase: %g\n',...
            Vm2400V_FFTDATA.freq(k),...
            Vm2400V_FFTDATA.mag(k),...
            Vm2400V_FFTDATA.phase(k));
    end    
end
%% Plot the FFT result (magnitude) for Vdctot
figure;
hold all;
plot(Vtot400V_FFTDATA.freq,Vtot400V_FFTDATA.mag,'bo-','Linewidth',1);
set(gca,'FontSize',14);
xlabel('Frequency (Hertz)','FontSize',14,'FontWeight','Bold')
ylabel('FFT of Total DC Link Voltage (Volts)','FontSize',14,'FontWeight','Bold')
xlim([-1 1000]);
ylim([0 2]);
title('Series - 400V - No int');

%% Plot the FFT result (magnitude) for Vdcm1
figure;
hold all;
plot(Vm1400V_FFTDATA.freq,Vm1400V_FFTDATA.mag,'bo-','Linewidth',1);
set(gca,'FontSize',14);
xlabel('Frequency (Hertz)','FontSize',14,'FontWeight','Bold')
ylabel('FFT of Module-1 DC Link Voltage (Volts)','FontSize',14,'FontWeight','Bold')
xlim([-1 1000]);
%ylim([0 2]);
title('Series - 400V - No int');

%% Plot the FFT result (magnitude) for Vdcm2
figure;
hold all;
plot(Vm2400V_FFTDATA.freq,Vm2400V_FFTDATA.mag,'bo-','Linewidth',1);
set(gca,'FontSize',14);
xlabel('Frequency (Hertz)','FontSize',14,'FontWeight','Bold')
ylabel('FFT of Module-2 DC Link Voltage (Volts)','FontSize',14,'FontWeight','Bold')
xlim([-1 1000]);
%ylim([0 2]);
title('Series - 400V - No int');

%% Plot the FFT results (magnitude) together
figure;
hold all;
plot(Vtot400V_FFTDATA.freq,Vtot400V_FFTDATA.mag,'bo-','Linewidth',1);
plot(Vm1400V_FFTDATA.freq,Vm1400V_FFTDATA.mag,'ko-','Linewidth',1);
plot(Vm2400V_FFTDATA.freq,Vm2400V_FFTDATA.mag,'ro-','Linewidth',1);
set(gca,'FontSize',14);
xlabel('Frequency (Hertz)','FontSize',14,'FontWeight','Bold')
ylabel('FFT of DC Link Voltage (Volts)','FontSize',14,'FontWeight','Bold')
xlim([-1 1000]);
%ylim([0 2]);
title('Series - 400V - No int');
legend({'Total','Top module','Bottom module'},'Location','best');

