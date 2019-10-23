%% First, load the data into workspace

load('ecce_parallel.mat');

%% A time-series object is created with time and data arrays to be imported in simulink model
% Then, a structure is obtained by a scope in Simulink to be able to apply FFT using power_fftscope

time_array = time_noint_200v_200khz - time_noint_200v_200khz(1);
Tstep = time_array(2) - time_array(1);
time_array2 = transpose(4e-08:Tstep:0.3); % 0.3 seconds of data is taken

% Idc - Module 1 - No int

Idc1_noint_200v_200khz= Idcm1sh1_noint_200v_200khz;
Idc1_noint_200v_200khzn= [Idc1_noint_200v_200khz; Idc1_noint_200v_200khz; Idc1_noint_200v_200khz; Idc1_noint_200v_200khz; Idc1_noint_200v_200khz; Idc1_noint_200v_200khz; Idc1_noint_200v_200khz; Idc1_noint_200v_200khz; Idc1_noint_200v_200khz; Idc1_noint_200v_200khz; Idc1_noint_200v_200khz; Idc1_noint_200v_200khz; Idc1_noint_200v_200khz; Idc1_noint_200v_200khz; Idc1_noint_200v_200khz; Idc1_noint_200v_200khz];
Idc1_noint_200v_data = Idc1_noint_200v_200khzn(1:7500000); % 0.3 seconds of data is taken
ts_Idc1_noint_200v = timeseries(Idc1_noint_200v_data,time_array2);

%Idc - Module2 - No int

Idc2_noint_200v_200khz= Idcm2sh3_noint_200v_200khz;
Idc2_noint_200v_200khzn= [Idc2_noint_200v_200khz; Idc2_noint_200v_200khz; Idc2_noint_200v_200khz; Idc2_noint_200v_200khz; Idc2_noint_200v_200khz; Idc2_noint_200v_200khz; Idc2_noint_200v_200khz; Idc2_noint_200v_200khz; Idc2_noint_200v_200khz; Idc2_noint_200v_200khz; Idc2_noint_200v_200khz; Idc2_noint_200v_200khz; Idc2_noint_200v_200khz; Idc2_noint_200v_200khz; Idc2_noint_200v_200khz; Idc2_noint_200v_200khz];
Idc2_noint_200v_data = Idc2_noint_200v_200khzn(1:7500000); % 0.3 seconds of data is taken
ts_Idc2_noint_200v = timeseries(Idc2_noint_200v_data,time_array2);

%Idc - Module 1 - Yes int

Idc1_yesint_200v_200khz= Idcm1sh1_yesint_200v_200khz;
Idc1_yesint_200v_200khzn= [Idc1_yesint_200v_200khz; Idc1_yesint_200v_200khz; Idc1_yesint_200v_200khz; Idc1_yesint_200v_200khz; Idc1_yesint_200v_200khz; Idc1_yesint_200v_200khz; Idc1_yesint_200v_200khz; Idc1_yesint_200v_200khz; Idc1_yesint_200v_200khz; Idc1_yesint_200v_200khz; Idc1_yesint_200v_200khz; Idc1_yesint_200v_200khz; Idc1_yesint_200v_200khz; Idc1_yesint_200v_200khz; Idc1_yesint_200v_200khz; Idc1_yesint_200v_200khz];
Idc1_yesint_200v_data = Idc1_yesint_200v_200khzn(1:7500000); % 5 seconds of data is taken
ts_Idc1_yesint_200v = timeseries(Idc1_yesint_200v_data,time_array2);

%Idc - Module 2 - Yes int

Idc2_yesint_200v_200khz= Idcm2sh3_yesint_200v_200khz;
Idc2_yesint_200v_200khzn= [Idc2_yesint_200v_200khz; Idc2_yesint_200v_200khz; Idc2_yesint_200v_200khz; Idc2_yesint_200v_200khz; Idc2_yesint_200v_200khz; Idc2_yesint_200v_200khz; Idc2_yesint_200v_200khz; Idc2_yesint_200v_200khz; Idc2_yesint_200v_200khz; Idc2_yesint_200v_200khz; Idc2_yesint_200v_200khz; Idc2_yesint_200v_200khz; Idc2_yesint_200v_200khz; Idc2_yesint_200v_200khz; Idc2_yesint_200v_200khz; Idc2_yesint_200v_200khz];
Idc2_yesint_200v_data = Idc2_yesint_200v_200khzn(1:7500000); % 5 seconds of data is taken
ts_Idc2_yesint_200v = timeseries(Idc2_yesint_200v_data,time_array2);

% Vdc - Total - No int

Vdc_noint_200v_200khz= Vdc_noint_200v_200khz;
Vdc_noint_200v_200khzn= [Vdc_noint_200v_200khz; Vdc_noint_200v_200khz; Vdc_noint_200v_200khz; Vdc_noint_200v_200khz; Vdc_noint_200v_200khz; Vdc_noint_200v_200khz; Vdc_noint_200v_200khz; Vdc_noint_200v_200khz; Vdc_noint_200v_200khz; Vdc_noint_200v_200khz; Vdc_noint_200v_200khz; Vdc_noint_200v_200khz; Vdc_noint_200v_200khz; Vdc_noint_200v_200khz; Vdc_noint_200v_200khz; Vdc_noint_200v_200khz];
Vdc_noint_200v_data = Vdc_noint_200v_200khzn(1:7500000); % 5 seconds of data is taken
ts_Vdc_noint_200v = timeseries(Vdc_noint_200v_data,time_array2);

%Vdc - Total - Yes int

Vdc_yesint_200v_200khz= Vdc_yesint_200v_200khz;
Vdc_yesint_200v_200khzn= [Vdc_yesint_200v_200khz; Vdc_yesint_200v_200khz; Vdc_yesint_200v_200khz; Vdc_yesint_200v_200khz; Vdc_yesint_200v_200khz; Vdc_yesint_200v_200khz; Vdc_yesint_200v_200khz; Vdc_yesint_200v_200khz; Vdc_yesint_200v_200khz; Vdc_yesint_200v_200khz; Vdc_yesint_200v_200khz; Vdc_yesint_200v_200khz; Vdc_yesint_200v_200khz; Vdc_yesint_200v_200khz; Vdc_yesint_200v_200khz; Vdc_yesint_200v_200khz];
Vdc_yesint_200v_data = Vdc_yesint_200v_200khzn(1:7500000); % 5 seconds of data is taken
ts_Vdc_yesint_200v = timeseries(Vdc_yesint_200v_data,time_array2);

% Isum - No int

Isum_noint_200v_200khz= Idcm1sh1_noint_200v_200khz + Idcm2sh3_noint_200v_200khz;
Isum_noint_200v_200khzn= [Isum_noint_200v_200khz; Isum_noint_200v_200khz; Isum_noint_200v_200khz; Isum_noint_200v_200khz; Isum_noint_200v_200khz; Isum_noint_200v_200khz; Isum_noint_200v_200khz; Isum_noint_200v_200khz; Isum_noint_200v_200khz; Isum_noint_200v_200khz; Isum_noint_200v_200khz; Isum_noint_200v_200khz; Isum_noint_200v_200khz; Isum_noint_200v_200khz; Isum_noint_200v_200khz; Isum_noint_200v_200khz];
Isum_noint_200v_data = Isum_noint_200v_200khzn(1:7500000); % 5 seconds of data is taken
ts_Isum_noint_200v = timeseries(Isum_noint_200v_data,time_array2);

% Isum - Yes int

Isum_yesint_200v_200khz= Idcm1sh1_yesint_200v_200khz + Idcm2sh3_yesint_200v_200khz;
Isum_yesint_200v_200khzn= [Isum_yesint_200v_200khz; Isum_yesint_200v_200khz; Isum_yesint_200v_200khz; Isum_yesint_200v_200khz; Isum_yesint_200v_200khz; Isum_yesint_200v_200khz; Isum_yesint_200v_200khz; Isum_yesint_200v_200khz; Isum_yesint_200v_200khz; Isum_yesint_200v_200khz; Isum_yesint_200v_200khz; Isum_yesint_200v_200khz; Isum_yesint_200v_200khz; Isum_yesint_200v_200khz; Isum_yesint_200v_200khz; Isum_yesint_200v_200khz];
Isum_yesint_200v_data = Isum_yesint_200v_200khzn(1:7500000); % 5 seconds of data is taken
ts_Isum_yesint_200v = timeseries(Isum_yesint_200v_data,time_array2);

% Idif - No int

Idif_noint_200v_200khz= Idcm1sh1_noint_200v_200khz - Idcm2sh3_noint_200v_200khz;
Idif_noint_200v_200khzn= [Idif_noint_200v_200khz; Idif_noint_200v_200khz; Idif_noint_200v_200khz; Idif_noint_200v_200khz; Idif_noint_200v_200khz; Idif_noint_200v_200khz; Idif_noint_200v_200khz; Idif_noint_200v_200khz; Idif_noint_200v_200khz; Idif_noint_200v_200khz; Idif_noint_200v_200khz; Idif_noint_200v_200khz; Idif_noint_200v_200khz; Idif_noint_200v_200khz; Idif_noint_200v_200khz; Idif_noint_200v_200khz];
Idif_noint_200v_data = Idif_noint_200v_200khzn(1:7500000); % 5 seconds of data is taken
ts_Idif_noint_200v = timeseries(Idif_noint_200v_data,time_array2);

% Idif - Yes int

Idif_yesint_200v_200khz= Idcm1sh1_yesint_200v_200khz - Idcm2sh3_yesint_200v_200khz;
Idif_yesint_200v_200khzn= [Idif_yesint_200v_200khz; Idif_yesint_200v_200khz; Idif_yesint_200v_200khz; Idif_yesint_200v_200khz; Idif_yesint_200v_200khz; Idif_yesint_200v_200khz; Idif_yesint_200v_200khz; Idif_yesint_200v_200khz; Idif_yesint_200v_200khz; Idif_yesint_200v_200khz; Idif_yesint_200v_200khz; Idif_yesint_200v_200khz; Idif_yesint_200v_200khz; Idif_yesint_200v_200khz; Idif_yesint_200v_200khz; Idif_yesint_200v_200khz];
Idif_yesint_200v_data = Idif_yesint_200v_200khzn(1:7500000); % 5 seconds of data is taken
ts_Idif_yesint_200v = timeseries(Idif_yesint_200v_data,time_array2);

%% Run the simulation to obtain the structure for FFT analysis

sim('for_fft_parallel.slx');

%% Adjust FFT parameters

fft_cycle = 2;
fft_start = 0;
fft_fund = 50;
fft_maxfreq = 200000;
fft_THDmaxfreq = 200000;
h_level=0.02;
% n_harmonic=20;

%% Idc - Module 1 - No int

Idc1_noint_200v_forfft_FFTDATA = power_fftscope(Idc1_noint_200v_forfft);
Idc1_noint_200v_forfft_FFTDATA.startTime = fft_start;
Idc1_noint_200v_forfft_FFTDATA.cycles = fft_cycle; 
Idc1_noint_200v_forfft_FFTDATA.fundamental = fft_fund; 
Idc1_noint_200v_forfft_FFTDATA.maxFrequency = fft_maxfreq;
Idc1_noint_200v_forfft_FFTDATA.THDmaxFrequency = fft_THDmaxfreq;
Idc1_noint_200v_forfft_FFTDATA = power_fftscope(Idc1_noint_200v_forfft_FFTDATA);

%% Idc - Module 2 - No int

Idc2_noint_200v_forfft_FFTDATA = power_fftscope(Idc2_noint_200v_forfft);
Idc2_noint_200v_forfft_FFTDATA.startTime = fft_start;
Idc2_noint_200v_forfft_FFTDATA.cycles = fft_cycle; 
Idc2_noint_200v_forfft_FFTDATA.fundamental = fft_fund; 
Idc2_noint_200v_forfft_FFTDATA.maxFrequency = fft_maxfreq;
Idc2_noint_200v_forfft_FFTDATA.THDmaxFrequency = fft_THDmaxfreq;
Idc2_noint_200v_forfft_FFTDATA = power_fftscope(Idc2_noint_200v_forfft_FFTDATA);

%% Idc - Module 1 - Yes int

Idc1_yesint_200v_forfft_FFTDATA = power_fftscope(Idc1_yesint_200v_forfft);
Idc1_yesint_200v_forfft_FFTDATA.startTime = fft_start;
Idc1_yesint_200v_forfft_FFTDATA.cycles = fft_cycle; 
Idc1_yesint_200v_forfft_FFTDATA.fundamental = fft_fund; 
Idc1_yesint_200v_forfft_FFTDATA.maxFrequency = fft_maxfreq;
Idc1_yesint_200v_forfft_FFTDATA.THDmaxFrequency = fft_THDmaxfreq;
Idc1_yesint_200v_forfft_FFTDATA = power_fftscope(Idc1_yesint_200v_forfft_FFTDATA);

%% Idc - Module 2 - Yes int

Idc2_yesint_200v_forfft_FFTDATA = power_fftscope(Idc2_yesint_200v_forfft);
Idc2_yesint_200v_forfft_FFTDATA.startTime = fft_start;
Idc2_yesint_200v_forfft_FFTDATA.cycles = fft_cycle; 
Idc2_yesint_200v_forfft_FFTDATA.fundamental = fft_fund; 
Idc2_yesint_200v_forfft_FFTDATA.maxFrequency = fft_maxfreq;
Idc2_yesint_200v_forfft_FFTDATA.THDmaxFrequency = fft_THDmaxfreq;
Idc2_yesint_200v_forfft_FFTDATA = power_fftscope(Idc2_yesint_200v_forfft_FFTDATA);

%% Vdc - Total - No int

Vdc_noint_200v_forfft_FFTDATA = power_fftscope(Vdc_noint_200v_forfft);
Vdc_noint_200v_forfft_FFTDATA.startTime = fft_start;
Vdc_noint_200v_forfft_FFTDATA.cycles = fft_cycle; 
Vdc_noint_200v_forfft_FFTDATA.fundamental = fft_fund; 
Vdc_noint_200v_forfft_FFTDATA.maxFrequency = fft_maxfreq;
Vdc_noint_200v_forfft_FFTDATA.THDmaxFrequency = fft_THDmaxfreq;
Vdc_noint_200v_forfft_FFTDATA = power_fftscope(Vdc_noint_200v_forfft_FFTDATA);

%% Vdc - Total - Yes int

Vdc_yesint_200v_forfft_FFTDATA = power_fftscope(Vdc_yesint_200v_forfft);
Vdc_yesint_200v_forfft_FFTDATA.startTime = fft_start;
Vdc_yesint_200v_forfft_FFTDATA.cycles = fft_cycle; 
Vdc_yesint_200v_forfft_FFTDATA.fundamental = fft_fund; 
Vdc_yesint_200v_forfft_FFTDATA.maxFrequency = fft_maxfreq;
Vdc_yesint_200v_forfft_FFTDATA.THDmaxFrequency = fft_THDmaxfreq;
Vdc_yesint_200v_forfft_FFTDATA = power_fftscope(Vdc_yesint_200v_forfft_FFTDATA);

%% Isum - No int

Isum_noint_200v_forfft_FFTDATA = power_fftscope(Isum_noint_200v_forfft);
Isum_noint_200v_forfft_FFTDATA.startTime = fft_start;
Isum_noint_200v_forfft_FFTDATA.cycles = fft_cycle; 
Isum_noint_200v_forfft_FFTDATA.fundamental = fft_fund; 
Isum_noint_200v_forfft_FFTDATA.maxFrequency = fft_maxfreq;
Isum_noint_200v_forfft_FFTDATA.THDmaxFrequency = fft_THDmaxfreq;
Isum_noint_200v_forfft_FFTDATA = power_fftscope(Isum_noint_200v_forfft_FFTDATA);

%% Isum - Yes int

Isum_yesint_200v_forfft_FFTDATA = power_fftscope(Isum_yesint_200v_forfft);
Isum_yesint_200v_forfft_FFTDATA.startTime = fft_start;
Isum_yesint_200v_forfft_FFTDATA.cycles = fft_cycle; 
Isum_yesint_200v_forfft_FFTDATA.fundamental = fft_fund; 
Isum_yesint_200v_forfft_FFTDATA.maxFrequency = fft_maxfreq;
Isum_yesint_200v_forfft_FFTDATA.THDmaxFrequency = fft_THDmaxfreq;
Isum_yesint_200v_forfft_FFTDATA = power_fftscope(Isum_yesint_200v_forfft_FFTDATA);

%% Idif - No int

Idif_noint_200v_forfft_FFTDATA = power_fftscope(Idif_noint_200v_forfft);
Idif_noint_200v_forfft_FFTDATA.startTime = fft_start;
Idif_noint_200v_forfft_FFTDATA.cycles = fft_cycle; 
Idif_noint_200v_forfft_FFTDATA.fundamental = fft_fund; 
Idif_noint_200v_forfft_FFTDATA.maxFrequency = fft_maxfreq;
Idif_noint_200v_forfft_FFTDATA.THDmaxFrequency = fft_THDmaxfreq;
Idif_noint_200v_forfft_FFTDATA = power_fftscope(Idif_noint_200v_forfft_FFTDATA);

%% Idif - Yes int

Idif_yesint_200v_forfft_FFTDATA = power_fftscope(Idif_yesint_200v_forfft);
Idif_yesint_200v_forfft_FFTDATA.startTime = fft_start;
Idif_yesint_200v_forfft_FFTDATA.cycles = fft_cycle; 
Idif_yesint_200v_forfft_FFTDATA.fundamental = fft_fund; 
Idif_yesint_200v_forfft_FFTDATA.maxFrequency = fft_maxfreq;
Idif_yesint_200v_forfft_FFTDATA.THDmaxFrequency = fft_THDmaxfreq;
Idif_yesint_200v_forfft_FFTDATA = power_fftscope(Idif_yesint_200v_forfft_FFTDATA);

%% Plot the FFT result (magnitude) of module's DC currents

figure;
hold all;
plot(Idc1_noint_200v_forfft_FFTDATA.freq,Idc1_noint_200v_forfft_FFTDATA.mag,'bo-','Linewidth',1);
plot(Idc1_yesint_200v_forfft_FFTDATA.freq,Idc1_yesint_200v_forfft_FFTDATA.mag,'go-','Linewidth',1);
plot(Idc2_noint_200v_forfft_FFTDATA.freq,Idc2_noint_200v_forfft_FFTDATA.mag,'r*-','Linewidth',1);
plot(Idc2_yesint_200v_forfft_FFTDATA.freq,Idc2_yesint_200v_forfft_FFTDATA.mag,'y*-','Linewidth',1);
set(gca,'FontSize',14);
xlabel('Frequency (Hertz)','FontSize',14,'FontWeight','Bold')
ylabel('FFT of Module Currents (Amper)','FontSize',14,'FontWeight','Bold')
% xlim([0 1000]);
% ylim([0 0.6]);
grid on
L1=sprintf('Mod 1 - No Interleaving - Idc = %.3f A ',max(Idc1_noint_200v_forfft_FFTDATA.mag));
L2=sprintf('Mod 1 - Yes Interleaving - Idc = %.3f A ',max(Idc1_yesint_200v_forfft_FFTDATA.mag));
L3=sprintf('Mod 2 - No Interleaving - Idc = %.3f A ',max(Idc2_noint_200v_forfft_FFTDATA.mag));
L4=sprintf('Mod 2 - Yes Interleaving - Idc = %.3f A ',max(Idc2_yesint_200v_forfft_FFTDATA.mag));
legend(L1,L2,L3,L4);
title('DC Currents of the Modules- Parallel - 200V - 200 kHz ');

%% Plot the FFT result (magnitude) of total DC link voltage

figure;
hold all;
plot(Vdc_noint_200v_forfft_FFTDATA.freq,Vdc_noint_200v_forfft_FFTDATA.mag,'bo-','Linewidth',1);
plot(Vdc_yesint_200v_forfft_FFTDATA.freq,Vdc_yesint_200v_forfft_FFTDATA.mag,'r*-','Linewidth',1);
set(gca,'FontSize',14);
xlabel('Frequency (Hertz)','FontSize',14,'FontWeight','Bold')
ylabel('FFT of Total DC Voltage (Volt)','FontSize',14,'FontWeight','Bold')
%  xlim([39000 41000]);
%   ylim([0 0.5]);
grid on
L5=sprintf('Vdc - No Interleaving - Vdc = %.3f V ',max(Vdc_noint_200v_forfft_FFTDATA.mag));
L6=sprintf('Vdc - Yes Interleaving - Vdc = %.3f V ',max(Vdc_yesint_200v_forfft_FFTDATA.mag));
legend(L5,L6);
title('Total DC Voltage of the Modules- Parallel - 200V - 200 kHz ');

%% Plot the FFT result (magnitude) of sum and difference of currents

figure;
hold all;
plot(Isum_noint_200v_forfft_FFTDATA.freq,Isum_noint_200v_forfft_FFTDATA.mag,'bo-','Linewidth',1);
plot(Isum_yesint_200v_forfft_FFTDATA.freq,Isum_yesint_200v_forfft_FFTDATA.mag,'go-','Linewidth',1);
plot(Idif_noint_200v_forfft_FFTDATA.freq,Idif_noint_200v_forfft_FFTDATA.mag,'r*-','Linewidth',1);
plot(Idif_yesint_200v_forfft_FFTDATA.freq,Idif_yesint_200v_forfft_FFTDATA.mag,'y*-','Linewidth',1);
set(gca,'FontSize',14);
xlabel('Frequency (Hertz)','FontSize',14,'FontWeight','Bold')
ylabel('FFT of Sum and Difference of Currents (Amper)','FontSize',14,'FontWeight','Bold')
% xlim([0 1000]);
 ylim([0 1.5]);
grid on
L7=sprintf('Isum - No Interleaving - Idc = %.3f A ',max(Isum_noint_200v_forfft_FFTDATA.mag));
L8=sprintf('Isum - Yes Interleaving - Idc = %.3f A ',max(Isum_yesint_200v_forfft_FFTDATA.mag));
L9=sprintf('Idif - No Interleaving - Idc = %.3f A ',max(Idif_noint_200v_forfft_FFTDATA.mag));
L10=sprintf('Idif - Yes Interleaving - Idc = %.3f A ',max(Idif_yesint_200v_forfft_FFTDATA.mag));
legend(L7,L8,L9,L10);
title('Sum and Difference of the Module Currents- Parallel - 200V - 200 kHz ');


%% Harmonic Analysis

mp_Idc1_noint_200v=[Idc1_noint_200v_forfft_FFTDATA.freq Idc1_noint_200v_forfft_FFTDATA.mag Idc1_noint_200v_forfft_FFTDATA.phase ];
mp_Idc1_yesint_200v=[Idc1_yesint_200v_forfft_FFTDATA.freq Idc1_yesint_200v_forfft_FFTDATA.mag Idc1_yesint_200v_forfft_FFTDATA.phase ];
mp_Idc2_noint_200v=[Idc2_noint_200v_forfft_FFTDATA.freq Idc2_noint_200v_forfft_FFTDATA.mag Idc2_noint_200v_forfft_FFTDATA.phase ];
mp_Idc2_yesint_200v=[Idc2_yesint_200v_forfft_FFTDATA.freq Idc2_yesint_200v_forfft_FFTDATA.mag Idc2_yesint_200v_forfft_FFTDATA.phase ];
mp_Isum_noint_200v=[Isum_noint_200v_forfft_FFTDATA.freq Isum_noint_200v_forfft_FFTDATA.mag Isum_noint_200v_forfft_FFTDATA.phase ];
mp_Isum_yesint_200v=[Isum_yesint_200v_forfft_FFTDATA.freq Isum_yesint_200v_forfft_FFTDATA.mag Isum_yesint_200v_forfft_FFTDATA.phase ];
mp_Idif_noint_200v=[Idif_noint_200v_forfft_FFTDATA.freq Idif_noint_200v_forfft_FFTDATA.mag Idif_noint_200v_forfft_FFTDATA.phase ];
mp_Idif_yesint_200v=[Idif_yesint_200v_forfft_FFTDATA.freq Idif_yesint_200v_forfft_FFTDATA.mag Idif_yesint_200v_forfft_FFTDATA.phase ];
mp_Vdc_noint_200v=[Vdc_noint_200v_forfft_FFTDATA.freq Vdc_noint_200v_forfft_FFTDATA.mag Vdc_noint_200v_forfft_FFTDATA.phase ];
mp_Vdc_yesint_200v=[Vdc_yesint_200v_forfft_FFTDATA.freq Vdc_yesint_200v_forfft_FFTDATA.mag Vdc_yesint_200v_forfft_FFTDATA.phase ];

num = size(mp_Idc1_noint_200v);
i=1;

for k = 1:num(1)
    if (mp_Idc1_noint_200v(k,2) >= h_level*max(mp_Idc1_noint_200v(:,2)))
        a(i,:)=[mp_Idc1_noint_200v(k,:) mp_Idc1_yesint_200v(k,:) mp_Idc2_noint_200v(k,:) mp_Idc2_yesint_200v(k,:) mp_Isum_noint_200v(k,:) mp_Isum_yesint_200v(k,:) mp_Idif_noint_200v(k,:) mp_Idif_yesint_200v(k,:) mp_Vdc_noint_200v(k,:) mp_Vdc_yesint_200v(k,:)];
        i=i+1;
    elseif  (mp_Idc1_yesint_200v(k,2) >= h_level*max(mp_Idc1_yesint_200v(:,2)))
        a(i,:)=[mp_Idc1_noint_200v(k,:) mp_Idc1_yesint_200v(k,:) mp_Idc2_noint_200v(k,:) mp_Idc2_yesint_200v(k,:) mp_Isum_noint_200v(k,:) mp_Isum_yesint_200v(k,:) mp_Idif_noint_200v(k,:) mp_Idif_yesint_200v(k,:) mp_Vdc_noint_200v(k,:) mp_Vdc_yesint_200v(k,:)];
        i=i+1;
    elseif  (mp_Idc2_noint_200v(k,2) >= h_level*max(mp_Idc2_noint_200v(:,2)))
        a(i,:)=[mp_Idc1_noint_200v(k,:) mp_Idc1_yesint_200v(k,:) mp_Idc2_noint_200v(k,:) mp_Idc2_yesint_200v(k,:) mp_Isum_noint_200v(k,:) mp_Isum_yesint_200v(k,:) mp_Idif_noint_200v(k,:) mp_Idif_yesint_200v(k,:) mp_Vdc_noint_200v(k,:) mp_Vdc_yesint_200v(k,:)];
        i=i+1;
    elseif  (mp_Idc2_yesint_200v(k,2) >= h_level*max(mp_Idc2_yesint_200v(:,2)))
        a(i,:)=[mp_Idc1_noint_200v(k,:) mp_Idc1_yesint_200v(k,:) mp_Idc2_noint_200v(k,:) mp_Idc2_yesint_200v(k,:) mp_Isum_noint_200v(k,:) mp_Isum_yesint_200v(k,:) mp_Idif_noint_200v(k,:) mp_Idif_yesint_200v(k,:) mp_Vdc_noint_200v(k,:) mp_Vdc_yesint_200v(k,:)];
        i=i+1;
    elseif  (mp_Isum_noint_200v(k,2) >= h_level*max(mp_Isum_noint_200v(:,2)))
        a(i,:)=[mp_Idc1_noint_200v(k,:) mp_Idc1_yesint_200v(k,:) mp_Idc2_noint_200v(k,:) mp_Idc2_yesint_200v(k,:) mp_Isum_noint_200v(k,:) mp_Isum_yesint_200v(k,:) mp_Idif_noint_200v(k,:) mp_Idif_yesint_200v(k,:) mp_Vdc_noint_200v(k,:) mp_Vdc_yesint_200v(k,:)];
        i=i+1;
    elseif  (mp_Isum_yesint_200v(k,2) >= h_level*max(mp_Isum_yesint_200v(:,2)))
        a(i,:)=[mp_Idc1_noint_200v(k,:) mp_Idc1_yesint_200v(k,:) mp_Idc2_noint_200v(k,:) mp_Idc2_yesint_200v(k,:) mp_Isum_noint_200v(k,:) mp_Isum_yesint_200v(k,:) mp_Idif_noint_200v(k,:) mp_Idif_yesint_200v(k,:) mp_Vdc_noint_200v(k,:) mp_Vdc_yesint_200v(k,:)];
        i=i+1;
    elseif  (mp_Idif_noint_200v(k,2) >= h_level*max(mp_Idif_noint_200v(:,2)))
        a(i,:)=[mp_Idc1_noint_200v(k,:) mp_Idc1_yesint_200v(k,:) mp_Idc2_noint_200v(k,:) mp_Idc2_yesint_200v(k,:) mp_Isum_noint_200v(k,:) mp_Isum_yesint_200v(k,:) mp_Idif_noint_200v(k,:) mp_Idif_yesint_200v(k,:) mp_Vdc_noint_200v(k,:) mp_Vdc_yesint_200v(k,:)];
        i=i+1;
    elseif  (mp_Idif_yesint_200v(k,2) >= h_level*max(mp_Idif_yesint_200v(:,2)))
        a(i,:)=[mp_Idc1_noint_200v(k,:) mp_Idc1_yesint_200v(k,:) mp_Idc2_noint_200v(k,:) mp_Idc2_yesint_200v(k,:) mp_Isum_noint_200v(k,:) mp_Isum_yesint_200v(k,:) mp_Idif_noint_200v(k,:) mp_Idif_yesint_200v(k,:) mp_Vdc_noint_200v(k,:) mp_Vdc_yesint_200v(k,:)];
        i=i+1;
    elseif  (mp_Vdc_noint_200v(k,2) >= h_level*max(mp_Vdc_noint_200v(:,2)))
        a(i,:)=[mp_Idc1_noint_200v(k,:) mp_Idc1_yesint_200v(k,:) mp_Idc2_noint_200v(k,:) mp_Idc2_yesint_200v(k,:) mp_Isum_noint_200v(k,:) mp_Isum_yesint_200v(k,:) mp_Idif_noint_200v(k,:) mp_Idif_yesint_200v(k,:) mp_Vdc_noint_200v(k,:) mp_Vdc_yesint_200v(k,:)];
        i=i+1;
    elseif  (mp_Vdc_yesint_200v(k,2) >= h_level*max(mp_Vdc_yesint_200v(:,2)))
        a(i,:)=[mp_Idc1_noint_200v(k,:) mp_Idc1_yesint_200v(k,:) mp_Idc2_noint_200v(k,:) mp_Idc2_yesint_200v(k,:) mp_Isum_noint_200v(k,:) mp_Isum_yesint_200v(k,:) mp_Idif_noint_200v(k,:) mp_Idif_yesint_200v(k,:) mp_Vdc_noint_200v(k,:) mp_Vdc_yesint_200v(k,:)];
        i=i+1;
    end
end

%% Exporting as .xlsx file

C=[{{},'Idc1_noint_200v',{},{},'Idc1_yesint_200v',{},{},'Idc2_noint_200v',{},{},'Idc2_yesint_200v',{},{},'Isum_noint_200v',{},{},'Isum_yesint_200v',{},{},'Idif_noint_200v',{},{},'Idif_yesint_200v',{},{},'Vdc_noint_200v',{},{},'Vdc_yesint_200v',{};'Frequency','Magnitude','Phase','Frequency','Magnitude','Phase','Frequency','Magnitude','Phase','Frequency','Magnitude','Phase','Frequency','Magnitude','Phase','Frequency','Magnitude','Phase','Frequency','Magnitude','Phase','Frequency','Magnitude','Phase','Frequency','Magnitude','Phase','Frequency','Magnitude','Phase',};num2cell(a)];
T=cell2table(C);
filename = 'harmonicse.xlsx';
writetable(T,filename);

%%
% %Idc - Module 1 - No int
% 
% mp_Idc1_noint_200v=[Idc1_noint_200v_forfft_FFTDATA.freq Idc1_noint_200v_forfft_FFTDATA.mag Idc1_noint_200v_forfft_FFTDATA.phase ];
% [B_Idc1_noint_200v,I_Idc1_noint_200v]=sort(Idc1_noint_200v_forfft_FFTDATA.mag,'descend');
% H_Idc1_noint_200v=Idc1_noint_200v_forfft_FFTDATA.phase(I_Idc1_noint_200v);
% I_Idc1_noint_200v=(I_Idc1_noint_200v-1)*Idc1_noint_200v_forfft_FFTDATA.freq(2);
% harmonics_Idc1_noint_200v=[I_Idc1_noint_200v(1:n_harmonic) B_Idc1_noint_200v(1:n_harmonic) H_Idc1_noint_200v(1:n_harmonic)];
% 
% %% Idc - Module 2 - No int
% 
% mp_Idc2_noint_200v=[Idc2_noint_200v_forfft_FFTDATA.freq Idc2_noint_200v_forfft_FFTDATA.mag Idc2_noint_200v_forfft_FFTDATA.phase ];
% [B_Idc2_noint_200v,I_Idc2_noint_200v]=sort(Idc2_noint_200v_forfft_FFTDATA.mag,'descend');
% H_Idc2_noint_200v=Idc2_noint_200v_forfft_FFTDATA.phase(I_Idc2_noint_200v);
% I_Idc2_noint_200v=(I_Idc2_noint_200v-1)*Idc2_noint_200v_forfft_FFTDATA.freq(2);
% harmonics_Idc2_noint_200v=[I_Idc2_noint_200v(1:n_harmonic) B_Idc2_noint_200v(1:n_harmonic) H_Idc2_noint_200v(1:n_harmonic)];
% 
% %% Idc - Module 1 - Yes int
% 
% mp_Idc1_yesint_200v=[Idc1_yesint_200v_forfft_FFTDATA.freq Idc1_yesint_200v_forfft_FFTDATA.mag Idc1_yesint_200v_forfft_FFTDATA.phase ];
% [B_Idc1_yesint_200v,I_Idc1_yesint_200v]=sort(Idc1_yesint_200v_forfft_FFTDATA.mag,'descend');
% H_Idc1_yesint_200v=Idc1_yesint_200v_forfft_FFTDATA.phase(I_Idc1_yesint_200v);
% I_Idc1_yesint_200v=(I_Idc1_yesint_200v-1)*Idc1_yesint_200v_forfft_FFTDATA.freq(2);
% harmonics_Idc1_yesint_200v=[I_Idc1_yesint_200v(1:n_harmonic) B_Idc1_yesint_200v(1:n_harmonic) H_Idc1_yesint_200v(1:n_harmonic)];
% 
% %% Idc - Module 2 - Yes int
% 
% mp_Idc2_yesint_200v=[Idc2_yesint_200v_forfft_FFTDATA.freq Idc2_yesint_200v_forfft_FFTDATA.mag Idc2_yesint_200v_forfft_FFTDATA.phase ];
% [B_Idc2_yesint_200v,I_Idc2_yesint_200v]=sort(Idc2_yesint_200v_forfft_FFTDATA.mag,'descend');
% H_Idc2_yesint_200v=Idc2_yesint_200v_forfft_FFTDATA.phase(I_Idc2_yesint_200v);
% I_Idc2_yesint_200v=(I_Idc2_yesint_200v-1)*Idc2_yesint_200v_forfft_FFTDATA.freq(2);
% harmonics_Idc2_yesint_200v=[I_Idc2_yesint_200v(1:n_harmonic) B_Idc2_yesint_200v(1:n_harmonic) H_Idc2_yesint_200v(1:n_harmonic)];
% 
% %% Vdc - Total - No int
% 
% mp_Vdc_noint_200v=[Vdc_noint_200v_forfft_FFTDATA.freq Vdc_noint_200v_forfft_FFTDATA.mag Vdc_noint_200v_forfft_FFTDATA.phase ];
% [B_Vdc_noint_200v,I_Vdc_noint_200v]=sort(Vdc_noint_200v_forfft_FFTDATA.mag,'descend');
% H_Vdc_noint_200v=Vdc_noint_200v_forfft_FFTDATA.phase(I_Vdc_noint_200v);
% I_Vdc_noint_200v=(I_Vdc_noint_200v-1)*Vdc_noint_200v_forfft_FFTDATA.freq(2);
% harmonics_Vdc_noint_200v=[I_Vdc_noint_200v(1:n_harmonic) B_Vdc_noint_200v(1:n_harmonic) H_Vdc_noint_200v(1:n_harmonic)];
% 
% %% Vdc - Total - Yes int
% 
% mp_Vdc_yesint_200v=[Vdc_yesint_200v_forfft_FFTDATA.freq Vdc_yesint_200v_forfft_FFTDATA.mag Vdc_yesint_200v_forfft_FFTDATA.phase ];
% [B_Vdc_yesint_200v,I_Vdc_yesint_200v]=sort(Vdc_yesint_200v_forfft_FFTDATA.mag,'descend');
% H_Vdc_yesint_200v=Vdc_yesint_200v_forfft_FFTDATA.phase(I_Vdc_yesint_200v);
% I_Vdc_yesint_200v=(I_Vdc_yesint_200v-1)*Vdc_yesint_200v_forfft_FFTDATA.freq(2);
% harmonics_Vdc_yesint_200v=[I_Vdc_yesint_200v(1:n_harmonic) B_Vdc_yesint_200v(1:n_harmonic) H_Vdc_yesint_200v(1:n_harmonic)];
% 
% %% Isum - No int
% 
% mp_Isum_noint_200v=[Isum_noint_200v_forfft_FFTDATA.freq Isum_noint_200v_forfft_FFTDATA.mag Isum_noint_200v_forfft_FFTDATA.phase ];
% [B_Isum_noint_200v,I_Isum_noint_200v]=sort(Isum_noint_200v_forfft_FFTDATA.mag,'descend');
% H_Isum_noint_200v=Isum_noint_200v_forfft_FFTDATA.phase(I_Isum_noint_200v);
% I_Isum_noint_200v=(I_Isum_noint_200v-1)*Isum_noint_200v_forfft_FFTDATA.freq(2);
% harmonics_Isum_noint_200v=[I_Isum_noint_200v(1:n_harmonic) B_Isum_noint_200v(1:n_harmonic) H_Isum_noint_200v(1:n_harmonic)];
% 
% %% Isum - Yes int
% 
% mp_Isum_yesint_200v=[Isum_yesint_200v_forfft_FFTDATA.freq Isum_yesint_200v_forfft_FFTDATA.mag Isum_yesint_200v_forfft_FFTDATA.phase ];
% [B_Isum_yesint_200v,I_Isum_yesint_200v]=sort(Isum_yesint_200v_forfft_FFTDATA.mag,'descend');
% H_Isum_yesint_200v=Isum_yesint_200v_forfft_FFTDATA.phase(I_Isum_yesint_200v);
% I_Isum_yesint_200v=(I_Isum_yesint_200v-1)*Isum_yesint_200v_forfft_FFTDATA.freq(2);
% harmonics_Isum_yesint_200v=[I_Isum_yesint_200v(1:n_harmonic) B_Isum_yesint_200v(1:n_harmonic) H_Isum_yesint_200v(1:n_harmonic)];
% 
% %% Idif - No int
% 
% mp_Idif_noint_200v=[Idif_noint_200v_forfft_FFTDATA.freq Idif_noint_200v_forfft_FFTDATA.mag Idif_noint_200v_forfft_FFTDATA.phase ];
% [B_Idif_noint_200v,I_Idif_noint_200v]=sort(Idif_noint_200v_forfft_FFTDATA.mag,'descend');
% H_Idif_noint_200v=Idif_noint_200v_forfft_FFTDATA.phase(I_Idif_noint_200v);
% I_Idif_noint_200v=(I_Idif_noint_200v-1)*Idif_noint_200v_forfft_FFTDATA.freq(2);
% harmonics_Idif_noint_200v=[I_Idif_noint_200v(1:n_harmonic) B_Idif_noint_200v(1:n_harmonic) H_Idif_noint_200v(1:n_harmonic)];
% 
% %% Idif - Yes int
% 
% mp_Idif_yesint_200v=[Idif_yesint_200v_forfft_FFTDATA.freq Idif_yesint_200v_forfft_FFTDATA.mag Idif_yesint_200v_forfft_FFTDATA.phase ];
% [B_Idif_yesint_200v,I_Idif_yesint_200v]=sort(Idif_yesint_200v_forfft_FFTDATA.mag,'descend');
% H_Idif_yesint_200v=Idif_yesint_200v_forfft_FFTDATA.phase(I_Idif_yesint_200v);
% I_Idif_yesint_200v=(I_Idif_yesint_200v-1)*Idif_yesint_200v_forfft_FFTDATA.freq(2);
% harmonics_Idif_yesint_200v=[I_Idif_yesint_200v(1:n_harmonic) B_Idif_yesint_200v(1:n_harmonic) H_Idif_yesint_200v(1:n_harmonic)];
% 
% harm=[harmonics_Idc1_noint_200v, harmonics_Idc1_yesint_200v, harmonics_Idc2_noint_200v, harmonics_Idc2_yesint_200v, harmonics_Isum_noint_200v, harmonics_Isum_yesint_200v, harmonics_Idif_noint_200v, harmonics_Idif_yesint_200v, harmonics_Vdc_noint_200v, harmonics_Vdc_yesint_200v];
% C=[{{},'Idc1_noint_200v',{},{},'Idc1_yesint_200v',{},{},'Idc2_noint_200v',{},{},'Idc2_yesint_200v',{},{},'Isum_noint_200v',{},{},'Isum_yesint_200v',{},{},'Idif_noint_200v',{},{},'Idif_yesint_200v',{},{},'Vdc_noint_200v',{},{},'Vdc_yesint_200v',{};'Frequency','Magnitude','Phase','Frequency','Magnitude','Phase','Frequency','Magnitude','Phase','Frequency','Magnitude','Phase','Frequency','Magnitude','Phase','Frequency','Magnitude','Phase','Frequency','Magnitude','Phase','Frequency','Magnitude','Phase','Frequency','Magnitude','Phase','Frequency','Magnitude','Phase',};num2cell(harm)];
% T=cell2table(C);
% filename = 'harmonicse.xlsx';
% writetable(T,filename);

%% This part is result analysis

% Vtot400V_DCcomp = Isum_yesint_200v_forfft_FFTDATA.mag(1);
% Vm1400V_DCcomp = Idif_yesint_200v_forfft_FFTDATA.mag(1);
% fprintf('Resolution: %g Hertz\n',Idc_sum_yesint_200v_forfft_FFTDATA.freq(2));
% fprintf('Starting point: %g seconds\n',fft_start);
% fprintf('Length of Data: %g seconds\n',1/fft_fund*fft_cycle);


%%
% num = numel(Isum_yesint_200v_forfft_FFTDATA.mag);
% for k = 1:num
%     if (Isum_yesint_200v_forfft_FFTDATA.mag(k) >= Vtot400V_DCcomp*0.002)
%         fprintf('Freq: %g, Mag: %g, Phase: %g\n',...
%             Idc_sum_yesint_200v_forfft_FFTDATA.freq(k),...
%             Idc_sum_yesint_200v_forfft_FFTDATA.mag(k),...
%             Idc_sum_yesint_200v_forfft_FFTDATA.phase(k));
%     end    
% end
%% Vdctot with Interleaving
% fprintf('\nHarmonics with Interleaving:\n');
% for k = 1:num
%     if (Idc_dif_yesint_200v_forfft_FFTDATA.mag(k) >= Vm1400V_DCcomp*0.002)
%         fprintf('Freq: %g, Mag: %g, Phase: %g\n',...
%             Idc_dif_yesint_200v_forfft_FFTDATA.freq(k),...
%             Idc_dif_yesint_200v_forfft_FFTDATA.mag(k),...
%             Idc_dif_yesint_200v_forfft_FFTDATA.phase(k));
%     end    
% end
