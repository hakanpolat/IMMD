%% First, load the data into workspace
load('series_data.mat');
%% A time-series object is created with time and data arrays to be imported in simulink model
% Then, a structure is obtained by a scope in Simulink to be able to apply FFT using power_fftscope
% V1_yesint_100v_200khz=Vdc_yesint_100v_200khz-V2_yesint_100v_200khz;
% V1_noint_100v_200khz=Vdc_noint_100v_200khz-V2_noint_100v_200khz;

time_array = time_noint_100v_200khz - time_noint_100v_200khz(1);
Tstep = time_array(2) - time_array(1);
time_array2 = transpose(4e-08:Tstep:0.3); % 0.3 seconds of data is taken

% Vdc - Total - No int

Vdc_noint_100v_200khzn= [Vdc_noint_100v_200khz;Vdc_noint_100v_200khz;Vdc_noint_100v_200khz;Vdc_noint_100v_200khz;Vdc_noint_100v_200khz;Vdc_noint_100v_200khz;Vdc_noint_100v_200khz;Vdc_noint_100v_200khz;Vdc_noint_100v_200khz;Vdc_noint_100v_200khz;Vdc_noint_100v_200khz;Vdc_noint_100v_200khz;Vdc_noint_100v_200khz;Vdc_noint_100v_200khz;Vdc_noint_100v_200khz;Vdc_noint_100v_200khz;Vdc_noint_100v_200khz;Vdc_noint_100v_200khz;Vdc_noint_100v_200khz;Vdc_noint_100v_200khz;Vdc_noint_100v_200khz];
Vdctot_noint_100v_data = Vdc_noint_100v_200khzn(1:7500000); % 5 seconds of data is taken
ts_Vdctot_noint_100v = timeseries(Vdctot_noint_100v_data,time_array2);

% Vdc - Total - Yes int

Vdc_yesint_100v_200khzn= [Vdc_yesint_100v_200khz;Vdc_yesint_100v_200khz;Vdc_yesint_100v_200khz;Vdc_yesint_100v_200khz;Vdc_yesint_100v_200khz;Vdc_yesint_100v_200khz;Vdc_yesint_100v_200khz;Vdc_yesint_100v_200khz;Vdc_yesint_100v_200khz;Vdc_yesint_100v_200khz;Vdc_yesint_100v_200khz;Vdc_yesint_100v_200khz;Vdc_yesint_100v_200khz;Vdc_yesint_100v_200khz;Vdc_yesint_100v_200khz;Vdc_yesint_100v_200khz;Vdc_yesint_100v_200khz;Vdc_yesint_100v_200khz;Vdc_yesint_100v_200khz;Vdc_yesint_100v_200khz;Vdc_yesint_100v_200khz];
Vdctot_yesint_100v_data = Vdc_yesint_100v_200khzn(1:7500000); % 5 seconds of data is taken
ts_Vdctot_yesint_100v = timeseries(Vdctot_yesint_100v_data,time_array2);

% Vdc - Module 1 - No int

V1_noint_100v_200khzn= [V1_noint_100v_200khz; V1_noint_100v_200khz; V1_noint_100v_200khz; V1_noint_100v_200khz; V1_noint_100v_200khz; V1_noint_100v_200khz; V1_noint_100v_200khz; V1_noint_100v_200khz; V1_noint_100v_200khz; V1_noint_100v_200khz; V1_noint_100v_200khz; V1_noint_100v_200khz; V1_noint_100v_200khz; V1_noint_100v_200khz; V1_noint_100v_200khz; V1_noint_100v_200khz];
V1_noint_100v_data = V1_noint_100v_200khzn(1:7500000); % 5 seconds of data is taken
ts_V1_noint_100v = timeseries(V1_noint_100v_data,time_array2);

% Vdc - Module 1 - Yes int

V1_yesint_100v_200khzn= [V1_yesint_100v_200khz; V1_yesint_100v_200khz; V1_yesint_100v_200khz; V1_yesint_100v_200khz; V1_yesint_100v_200khz; V1_yesint_100v_200khz; V1_yesint_100v_200khz; V1_yesint_100v_200khz; V1_yesint_100v_200khz; V1_yesint_100v_200khz; V1_yesint_100v_200khz; V1_yesint_100v_200khz; V1_yesint_100v_200khz; V1_yesint_100v_200khz; V1_yesint_100v_200khz; V1_yesint_100v_200khz];
V1_yesint_100v_data = V1_yesint_100v_200khzn(1:7500000); % 5 seconds of data is taken
ts_V1_yesint_100v = timeseries(V1_yesint_100v_data,time_array2);

% Vdc - Module 2 - No int

V2_noint_100v_200khzn= [V2_noint_100v_200khz; V2_noint_100v_200khz; V2_noint_100v_200khz; V2_noint_100v_200khz; V2_noint_100v_200khz; V2_noint_100v_200khz; V2_noint_100v_200khz; V2_noint_100v_200khz; V2_noint_100v_200khz; V2_noint_100v_200khz; V2_noint_100v_200khz; V2_noint_100v_200khz; V2_noint_100v_200khz; V2_noint_100v_200khz; V2_noint_100v_200khz; V2_noint_100v_200khz];
V2_noint_100v_data = V2_noint_100v_200khzn(1:7500000); % 5 seconds of data is taken
ts_V2_noint_100v = timeseries(V2_noint_100v_data,time_array2);

% Vdc - Module 2 - Yes int

V2_yesint_100v_200khzn= [V2_yesint_100v_200khz; V2_yesint_100v_200khz; V2_yesint_100v_200khz; V2_yesint_100v_200khz; V2_yesint_100v_200khz; V2_yesint_100v_200khz; V2_yesint_100v_200khz; V2_yesint_100v_200khz; V2_yesint_100v_200khz; V2_yesint_100v_200khz; V2_yesint_100v_200khz; V2_yesint_100v_200khz; V2_yesint_100v_200khz; V2_yesint_100v_200khz; V2_yesint_100v_200khz; V2_yesint_100v_200khz];
V2_yesint_100v_data = V2_yesint_100v_200khzn(1:7500000); % 5 seconds of data is taken
ts_V2_yesint_100v = timeseries(V2_yesint_100v_data,time_array2);

%% Run the simulation to obtain the structure for FFT analysis

sim('for_fft_series.slx');

%% Adjust FFT parameters

fft_cycle = 2;
fft_start = 0;
fft_fund = 50;
fft_maxfreq = 200000;
fft_THDmaxfreq = 200000;
h_level=0.2;
% n_harmonic=20;

%% Vdc -Total - No interleaving

Vdc_noint_100v_FFTDATA = power_fftscope(Vdc_noint_100v_forfft);
Vdc_noint_100v_FFTDATA.startTime = fft_start;
Vdc_noint_100v_FFTDATA.cycles = fft_cycle; 
Vdc_noint_100v_FFTDATA.fundamental = fft_fund; 
Vdc_noint_100v_FFTDATA.maxFrequency = fft_maxfreq;
Vdc_noint_100v_FFTDATA.THDmaxFrequency = fft_THDmaxfreq;
Vdc_noint_100v_FFTDATA = power_fftscope(Vdc_noint_100v_FFTDATA);

%% Vdc -Total - Yes interleaving

Vdc_yesint_100v_FFTDATA = power_fftscope(Vdc_yesint_100v_forfft);
Vdc_yesint_100v_FFTDATA.startTime = fft_start;
Vdc_yesint_100v_FFTDATA.cycles = fft_cycle; 
Vdc_yesint_100v_FFTDATA.fundamental = fft_fund; 
Vdc_yesint_100v_FFTDATA.maxFrequency = fft_maxfreq;
Vdc_yesint_100v_FFTDATA.THDmaxFrequency = fft_THDmaxfreq;
Vdc_yesint_100v_FFTDATA = power_fftscope(Vdc_yesint_100v_FFTDATA);

%% Vdc -Module 1 - No interleaving

V1_noint_100v_FFTDATA = power_fftscope(V1_noint_100v_forfft);
V1_noint_100v_FFTDATA.startTime = fft_start;
V1_noint_100v_FFTDATA.cycles = fft_cycle; 
V1_noint_100v_FFTDATA.fundamental = fft_fund; 
V1_noint_100v_FFTDATA.maxFrequency = fft_maxfreq;
V1_noint_100v_FFTDATA.THDmaxFrequency = fft_THDmaxfreq;
V1_noint_100v_FFTDATA = power_fftscope(V1_noint_100v_FFTDATA);

%% Vdc -Total - Yes interleaving

V1_yesint_100v_FFTDATA = power_fftscope(V1_yesint_100v_forfft);
V1_yesint_100v_FFTDATA.startTime = fft_start;
V1_yesint_100v_FFTDATA.cycles = fft_cycle; 
V1_yesint_100v_FFTDATA.fundamental = fft_fund; 
V1_yesint_100v_FFTDATA.maxFrequency = fft_maxfreq;
V1_yesint_100v_FFTDATA.THDmaxFrequency = fft_THDmaxfreq;
V1_yesint_100v_FFTDATA = power_fftscope(V1_yesint_100v_FFTDATA);

%% V2 -Total - No interleaving

V2_noint_100v_FFTDATA = power_fftscope(V2_noint_100v_forfft);
V2_noint_100v_FFTDATA.startTime = fft_start;
V2_noint_100v_FFTDATA.cycles = fft_cycle; 
V2_noint_100v_FFTDATA.fundamental = fft_fund; 
V2_noint_100v_FFTDATA.maxFrequency = fft_maxfreq;
V2_noint_100v_FFTDATA.THDmaxFrequency = fft_THDmaxfreq;
V2_noint_100v_FFTDATA = power_fftscope(V2_noint_100v_FFTDATA);

%% V2 -Total - Yes interleaving

V2_yesint_100v_FFTDATA = power_fftscope(V2_yesint_100v_forfft);
V2_yesint_100v_FFTDATA.startTime = fft_start;
V2_yesint_100v_FFTDATA.cycles = fft_cycle; 
V2_yesint_100v_FFTDATA.fundamental = fft_fund; 
V2_yesint_100v_FFTDATA.maxFrequency = fft_maxfreq;
V2_yesint_100v_FFTDATA.THDmaxFrequency = fft_THDmaxfreq;
V2_yesint_100v_FFTDATA = power_fftscope(V2_yesint_100v_FFTDATA);

%% Plot the FFT result (magnitude) of module's DC currents

figure;
hold all;
plot(Vdc_noint_100v_FFTDATA.freq,Vdc_noint_100v_FFTDATA.mag,'m+-','Linewidth',1);
plot(Vdc_yesint_100v_FFTDATA.freq,Vdc_yesint_100v_FFTDATA.mag,'k+-','Linewidth',1);
plot(V1_noint_100v_FFTDATA.freq,V1_noint_100v_FFTDATA.mag,'bo-','Linewidth',1);
plot(V1_yesint_100v_FFTDATA.freq,V1_yesint_100v_FFTDATA.mag,'go-','Linewidth',1);
plot(V2_noint_100v_FFTDATA.freq,V2_noint_100v_FFTDATA.mag,'r*-','Linewidth',1);
plot(V2_yesint_100v_FFTDATA.freq,V2_yesint_100v_FFTDATA.mag,'y*-','Linewidth',1);
set(gca,'FontSize',14);
xlabel('Frequency (Hertz)','FontSize',14,'FontWeight','Bold')
ylabel('FFT of Voltage (V)','FontSize',14,'FontWeight','Bold')
% xlim([0 1000]);
% ylim([0 0.4]);
grid on
L1=sprintf('Total - No Interleaving');
L2=sprintf('Total - Yes Interleaving ');
L3=sprintf('Mod 1 - No Interleaving ');
L4=sprintf('Mod 1 - Yes Interleaving ');
L5=sprintf('Mod 2 - No Interleaving ');
L6=sprintf('Mod 2 - Yes Interleaving ');
legend(L1,L2,L3,L4,L5,L6);
title('FFT Results of Modules Voltage Ripples - Series - 100V - 200 kHz ');

%% Harmonic Analysis

mp_Vdc_noint_100v=[Vdc_noint_100v_FFTDATA.freq Vdc_noint_100v_FFTDATA.mag Vdc_noint_100v_FFTDATA.phase ];
mp_Vdc_yesint_100v=[Vdc_yesint_100v_FFTDATA.freq Vdc_yesint_100v_FFTDATA.mag Vdc_yesint_100v_FFTDATA.phase ];
mp_V1_noint_100v=[V1_noint_100v_FFTDATA.freq V1_noint_100v_FFTDATA.mag V1_noint_100v_FFTDATA.phase ];
mp_V1_yesint_100v=[V1_yesint_100v_FFTDATA.freq V1_yesint_100v_FFTDATA.mag V1_yesint_100v_FFTDATA.phase ];
mp_V2_noint_100v=[V2_noint_100v_FFTDATA.freq V2_noint_100v_FFTDATA.mag V2_noint_100v_FFTDATA.phase ];
mp_V2_yesint_100v=[V2_yesint_100v_FFTDATA.freq V2_yesint_100v_FFTDATA.mag V2_yesint_100v_FFTDATA.phase ];

num = size(mp_Vdc_noint_100v);
i=1;

for k = 1:num(1)
    if (mp_Vdc_noint_100v(k,2) >= h_level*max(mp_Vdc_noint_100v(:,2)))
        a(i,:)=[mp_Vdc_noint_100v(k,:) mp_Vdc_yesint_100v(k,:) mp_V1_noint_100v(k,:) mp_V1_yesint_100v(k,:) mp_V2_noint_100v(k,:) mp_V2_yesint_100v(k,:)];
        i=i+1;
    elseif  (mp_Vdc_yesint_100v(k,2) >= h_level*max(mp_Vdc_yesint_100v(:,2)))
        a(i,:)=[mp_Vdc_noint_100v(k,:) mp_Vdc_yesint_100v(k,:) mp_V1_noint_100v(k,:) mp_V1_yesint_100v(k,:) mp_V2_noint_100v(k,:) mp_V2_yesint_100v(k,:)];
        i=i+1;
    elseif  (mp_V1_noint_100v(k,2) >= h_level*max(mp_V1_noint_100v(:,2)))
        a(i,:)=[mp_Vdc_noint_100v(k,:) mp_Vdc_yesint_100v(k,:) mp_V1_noint_100v(k,:) mp_V1_yesint_100v(k,:) mp_V2_noint_100v(k,:) mp_V2_yesint_100v(k,:)];
        i=i+1;
    elseif  (mp_V1_yesint_100v(k,2) >= h_level*max(mp_V1_yesint_100v(:,2)))
        a(i,:)=[mp_Vdc_noint_100v(k,:) mp_Vdc_yesint_100v(k,:) mp_V1_noint_100v(k,:) mp_V1_yesint_100v(k,:) mp_V2_noint_100v(k,:) mp_V2_yesint_100v(k,:)];
        i=i+1;
    elseif  (mp_V2_noint_100v(k,2) >= h_level*max(mp_V2_noint_100v(:,2)))
        a(i,:)=[mp_Vdc_noint_100v(k,:) mp_Vdc_yesint_100v(k,:) mp_V1_noint_100v(k,:) mp_V1_yesint_100v(k,:) mp_V2_noint_100v(k,:) mp_V2_yesint_100v(k,:)];
        i=i+1;
    elseif  (mp_V2_yesint_100v(k,2) >= h_level*max(mp_V2_yesint_100v(:,2)))
        a(i,:)=[mp_Vdc_noint_100v(k,:) mp_Vdc_yesint_100v(k,:) mp_V1_noint_100v(k,:) mp_V1_yesint_100v(k,:) mp_V2_noint_100v(k,:) mp_V2_yesint_100v(k,:)];
        i=i+1;
    end
end
%% Exporting as .xlsx file

C=[{{},'Vdc_noint_100v',{},{},'Vdc_yesint_100v',{},{},'V1_noint_100v',{},{},'V1_yesint_100v',{},{},'V2_noint_100v',{},{},'V2_yesint_100v',{};'Frequency','Magnitude','Phase','Frequency','Magnitude','Phase','Frequency','Magnitude','Phase','Frequency','Magnitude','Phase','Frequency','Magnitude','Phase','Frequency','Magnitude','Phase'};num2cell(a)];
T=cell2table(C);
filename = 'series_harmonics1.xlsx';
writetable(T,filename);


%%

% %% Harmonic Analysis
% % Vdc - Total - No int
% 
% mp_Vdc_noint_100v=[Vdc_noint_100v_FFTDATA.freq Vdc_noint_100v_FFTDATA.mag Vdc_noint_100v_FFTDATA.phase ];
% [B_Vdc_noint_100v,I_Vdc_noint_100v]=sort(Vdc_noint_100v_FFTDATA.mag,'descend');
% H_Vdc_noint_100v=Vdc_noint_100v_FFTDATA.phase(I_Vdc_noint_100v);
% I_Vdc_noint_100v=(I_Vdc_noint_100v-1)*Vdc_noint_100v_FFTDATA.freq(2);
% harmonics_Vdc_noint_100v=[I_Vdc_noint_100v(1:n_harmonic) B_Vdc_noint_100v(1:n_harmonic) H_Vdc_noint_100v(1:n_harmonic)];
% 
% %% Vdc - Total - Yes int
% 
% mp_Vdc_yesint_100v=[Vdc_yesint_100v_FFTDATA.freq Vdc_yesint_100v_FFTDATA.mag Vdc_yesint_100v_FFTDATA.phase ];
% [B_Vdc_yesint_100v,I_Vdc_yesint_100v]=sort(Vdc_yesint_100v_FFTDATA.mag,'descend');
% H_Vdc_yesint_100v=Vdc_yesint_100v_FFTDATA.phase(I_Vdc_yesint_100v);
% I_Vdc_yesint_100v=(I_Vdc_yesint_100v-1)*Vdc_yesint_100v_FFTDATA.freq(2);
% harmonics_Vdc_yesint_100v=[I_Vdc_yesint_100v(1:n_harmonic) B_Vdc_yesint_100v(1:n_harmonic) H_Vdc_yesint_100v(1:n_harmonic)];
% 
% %% Vdc - Module 1 - No int
% 
% mp_V1_noint_100v=[V1_noint_100v_FFTDATA.freq V1_noint_100v_FFTDATA.mag V1_noint_100v_FFTDATA.phase ];
% [B_V1_noint_100v,I_V1_noint_100v]=sort(V1_noint_100v_FFTDATA.mag,'descend');
% H_Idc1_yesint_200v=V1_noint_100v_FFTDATA.phase(I_V1_noint_100v);
% I_V1_noint_100v=(I_V1_noint_100v-1)*V1_noint_100v_FFTDATA.freq(2);
% harmonics_V1_noint_100v=[I_V1_noint_100v(1:n_harmonic) B_V1_noint_100v(1:n_harmonic) H_Idc1_yesint_200v(1:n_harmonic)];
% 
% % Vdc - Module 1 - Yes int
% 
% mp_V1_yesint_100v=[V1_yesint_100v_FFTDATA.freq V1_yesint_100v_FFTDATA.mag V1_yesint_100v_FFTDATA.phase ];
% [B_V1_yesint_100v,I_V1_yesint_100v]=sort(V1_yesint_100v_FFTDATA.mag,'descend');
% H_V1_yesint_100v=V1_yesint_100v_FFTDATA.phase(I_V1_yesint_100v);
% I_V1_yesint_100v=(I_V1_yesint_100v-1)*V1_yesint_100v_FFTDATA.freq(2);
% harmonics_V1_yesint_100v=[I_V1_yesint_100v(1:n_harmonic) B_V1_yesint_100v(1:n_harmonic) H_V1_yesint_100v(1:n_harmonic)];
% 
% % Vdc - Module 2 - No int
% 
% mp_V2_noint_100v=[V2_noint_100v_FFTDATA.freq V2_noint_100v_FFTDATA.mag V2_noint_100v_FFTDATA.phase ];
% [B_V2_noint_100v,I_V2_noint_100v]=sort(V2_noint_100v_FFTDATA.mag,'descend');
% H_V2_noint_100v=V2_noint_100v_FFTDATA.phase(I_V2_noint_100v);
% I_V2_noint_100v=(I_V2_noint_100v-1)*V2_noint_100v_FFTDATA.freq(2);
% harmonics_V2_noint_100v=[I_V2_noint_100v(1:n_harmonic) B_V2_noint_100v(1:n_harmonic) H_V2_noint_100v(1:n_harmonic)];
% 
% %% Vdc - Module 2 - Yes int
% 
% mp_V2_yesint_100v=[V2_yesint_100v_FFTDATA.freq V2_yesint_100v_FFTDATA.mag V2_yesint_100v_FFTDATA.phase ];
% [B_V2_yesint_100v,I_V2_yesint_100v]=sort(V2_yesint_100v_FFTDATA.mag,'descend');
% H_V2_yesint_100v=V2_yesint_100v_FFTDATA.phase(I_V2_yesint_100v);
% I_V2_yesint_100v=(I_V2_yesint_100v-1)*V2_yesint_100v_FFTDATA.freq(2);
% harmonics_V2_yesint_100v=[I_V2_yesint_100v(1:n_harmonic) B_V2_yesint_100v(1:n_harmonic) H_V2_yesint_100v(1:n_harmonic)];
% 
% %% Exporting as .xlsx file
% 
% harm=[ harmonics_Vdc_noint_100v, harmonics_Vdc_yesint_100v, harmonics_V1_noint_100v, harmonics_V1_yesint_100v, harmonics_V2_noint_100v, harmonics_V2_yesint_100v];
% C=[{{},'Vdc_noint_100v',{},{},'Vdc_yesint_100v',{},{},'V1_noint_100v',{},{},'V1_yesint_100v',{},{},'V2_noint_100v',{},{},'V2_yesint_100v',{};'Frequency','Magnitude','Phase','Frequency','Magnitude','Phase','Frequency','Magnitude','Phase','Frequency','Magnitude','Phase','Frequency','Magnitude','Phase','Frequency','Magnitude','Phase'};num2cell(harm)];
% T=cell2table(C);
% filename = 'series_harmonics1.xlsx';
% writetable(T,filename);
