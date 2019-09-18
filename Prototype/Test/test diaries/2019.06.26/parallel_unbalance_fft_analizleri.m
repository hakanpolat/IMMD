%% First, load the data into workspace
%load('ecce_parallel.mat');
%% A time-series object is created with time and data arrays to be imported in simulink model
% Then, a structure is obtained by a scope in Simulink to be able to apply FFT using power_fftscope
time_array = time_noint_200v_200khz - time_noint_200v_200khz(1);
Tstep = time_array(2) - time_array(1);
time_array3 = transpose(linspace(0.01,0.3,(0.3-0.01)/Tstep));
time_array=[ time_array; time_array3];
time_array2 = time_array(1:0.3/Tstep); % 5 seconds of data is taken

Vdc_noint_200v_200khzn= [Vdc_noint_200v_200khz; Vdc_noint_200v_200khz; Vdc_noint_200v_200khz; Vdc_noint_200v_200khz; Vdc_noint_200v_200khz; Vdc_noint_200v_200khz; Vdc_noint_200v_200khz; Vdc_noint_200v_200khz; Vdc_noint_200v_200khz; Vdc_noint_200v_200khz; Vdc_noint_200v_200khz; Vdc_noint_200v_200khz; Vdc_noint_200v_200khz; Vdc_noint_200v_200khz; Vdc_noint_200v_200khz; Vdc_noint_200v_200khz; Vdc_noint_200v_200khz; Vdc_noint_200v_200khz; Vdc_noint_200v_200khz; Vdc_noint_200v_200khz; Vdc_noint_200v_200khz];
Vdctot_noint_200v_data = Vdc_noint_200v_200khzn(1:0.3/Tstep); % 5 seconds of data is taken
ts_Vdctot_noint_200v = timeseries(Vdctot_noint_200v_data,time_array2);

Vdc_yesint_200v_200khzn= [Vdc_yesint_200v_200khz; Vdc_yesint_200v_200khz; Vdc_yesint_200v_200khz; Vdc_yesint_200v_200khz; Vdc_yesint_200v_200khz; Vdc_yesint_200v_200khz; Vdc_yesint_200v_200khz; Vdc_yesint_200v_200khz; Vdc_yesint_200v_200khz; Vdc_yesint_200v_200khz; Vdc_yesint_200v_200khz; Vdc_yesint_200v_200khz; Vdc_yesint_200v_200khz; Vdc_yesint_200v_200khz; Vdc_yesint_200v_200khz; Vdc_yesint_200v_200khz; Vdc_yesint_200v_200khz; Vdc_yesint_200v_200khz; Vdc_yesint_200v_200khz; Vdc_yesint_200v_200khz; Vdc_yesint_200v_200khz];
Vdctot_yesint_200v_data = Vdc_yesint_200v_200khzn(1:0.3/Tstep); % 5 seconds of data is taken
ts_Vdctot_yesint_200v = timeseries(Vdctot_yesint_200v_data,time_array2);
%% Run the simulation to obtain the structure for FFT analysis
sim('for_fft_p.slx');
%% Adjust FFT parameters
fft_cycle = 10;
fft_start = 0;
fft_fund = 50;
fft_maxfreq = 200000;
fft_THDmaxfreq = 200000;
%% Vdctotal no interleaving
Vtot400V_FFTDATA = power_fftscope(Vdctot_400v_forfft);
Vtot400V_FFTDATA.startTime = fft_start;
Vtot400V_FFTDATA.cycles = fft_cycle; 
Vtot400V_FFTDATA.fundamental = fft_fund; 
Vtot400V_FFTDATA.maxFrequency = fft_maxfreq;
Vtot400V_FFTDATA.THDmaxFrequency = fft_THDmaxfreq;
Vtot400V_FFTDATA = power_fftscope(Vtot400V_FFTDATA);
%% Vdctotal yes interleaving
Vm1400V_FFTDATA = power_fftscope(Vdcm1_400v_forfft);
Vm1400V_FFTDATA.startTime = fft_start;
Vm1400V_FFTDATA.cycles = fft_cycle; 
Vm1400V_FFTDATA.fundamental = fft_fund; 
Vm1400V_FFTDATA.maxFrequency = fft_maxfreq;
Vm1400V_FFTDATA.THDmaxFrequency = fft_THDmaxfreq;
Vm1400V_FFTDATA = power_fftscope(Vm1400V_FFTDATA);
%% This part is result analysis
num = numel(Vtot400V_FFTDATA.mag);
Vtot400V_DCcomp = Vtot400V_FFTDATA.mag(1);
Vm1400V_DCcomp = Vm1400V_FFTDATA.mag(1);
fprintf('Resolution: %g Hertz\n',Vtot400V_FFTDATA.freq(2));
fprintf('Starting point: %g seconds\n',fft_start);
fprintf('Length of Data: %g seconds\n',1/fft_fund*fft_cycle);
%% Vdctot without Interleaving
fprintf('\nHarmonics without Interleaving:\n');
for k = 1:num
    if (Vtot400V_FFTDATA.mag(k) >= Vtot400V_DCcomp*0.002)
        fprintf('Freq: %g, Mag: %g, Phase: %g\n',...
            Vtot400V_FFTDATA.freq(k),...
            Vtot400V_FFTDATA.mag(k),...
            Vtot400V_FFTDATA.phase(k));
    end    
end
%% Vdctot with Interleaving
fprintf('\nHarmonics with Interleaving:\n');
for k = 1:num
    if (Vm1400V_FFTDATA.mag(k) >= Vm1400V_DCcomp*0.002)
        fprintf('Freq: %g, Mag: %g, Phase: %g\n',...
            Vm1400V_FFTDATA.freq(k),...
            Vm1400V_FFTDATA.mag(k),...
            Vm1400V_FFTDATA.phase(k));
    end    
end
%% Plot the FFT result (magnitude) for Vdctot without Interleaving
figure;
hold all;
plot(Vtot400V_FFTDATA.freq,Vtot400V_FFTDATA.mag,'bo-','Linewidth',1);
set(gca,'FontSize',14);
xlabel('Frequency (Hertz)','FontSize',14,'FontWeight','Bold')
ylabel('FFT of Total DC Link Voltage without Interleaving (Volts)','FontSize',14,'FontWeight','Bold')
xlim([-1 1000]);
ylim([0 10]);
title('Parallel - 200V - Yes int');

%% Plot the FFT result (magnitude) for Vdctot with Interleaving
figure;
hold all;
plot(Vm1400V_FFTDATA.freq,Vm1400V_FFTDATA.mag,'bo-','Linewidth',1);
set(gca,'FontSize',14);
xlabel('Frequency (Hertz)','FontSize',14,'FontWeight','Bold')
ylabel('FFT of Total DC Link Voltage with Interleaving (Volts)','FontSize',14,'FontWeight','Bold')
xlim([-1 1000]);
%ylim([0 2]);
title('Parallel - 200V - No int');
%% Plot the FFT result (magnitude) all together
figure;
hold all;
plot(Vtot400V_FFTDATA.freq,Vtot400V_FFTDATA.mag,'bo-','Linewidth',1);
plot(Vm1400V_FFTDATA.freq,Vm1400V_FFTDATA.mag,'ro-','Linewidth',1);
set(gca,'FontSize',14);
xlabel('Frequency (Hertz)','FontSize',14,'FontWeight','Bold')
ylabel('FFT of Total DC Link Voltage (Volts)','FontSize',14,'FontWeight','Bold')
 xlim([39000 41000]);
 ylim([0 1]);
 grid on
legend('No Interleaving','Yes Interleaving');
title('Parallel - 200V');