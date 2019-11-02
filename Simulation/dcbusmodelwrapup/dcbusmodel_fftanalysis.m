
%% FFT analysis
fft_cycle = 5;
fft_start = 0.04;
fft_fund = 50;
fft_maxfreq = 50000;
fft_THDmaxfreq = 50000;
%%
Iin_FFTDATA = power_fftscope(Iin);
Iin_FFTDATA.startTime = fft_start;
Iin_FFTDATA.cycles = fft_cycle; 
Iin_FFTDATA.fundamental = fft_fund; 
Iin_FFTDATA.maxFrequency = fft_maxfreq;
Iin_FFTDATA.THDmaxFrequency = fft_THDmaxfreq;
Iin_FFTDATA = power_fftscope(Iin_FFTDATA);

Idc_FFTDATA = power_fftscope(Idc);
Idc_FFTDATA.startTime = fft_start;
Idc_FFTDATA.cycles = fft_cycle; 
Idc_FFTDATA.fundamental = fft_fund; 
Idc_FFTDATA.maxFrequency = fft_maxfreq;
Idc_FFTDATA.THDmaxFrequency = fft_THDmaxfreq;
Idc_FFTDATA = power_fftscope(Idc_FFTDATA);

Icap_FFTDATA = power_fftscope(Icap);
Icap_FFTDATA.startTime = fft_start;
Icap_FFTDATA.cycles = fft_cycle; 
Icap_FFTDATA.fundamental = fft_fund; 
Icap_FFTDATA.maxFrequency = fft_maxfreq;
Icap_FFTDATA.THDmaxFrequency = fft_THDmaxfreq;
Icap_FFTDATA = power_fftscope(Icap_FFTDATA);

Vdc_FFTDATA = power_fftscope(Vdc1);
Vdc_FFTDATA.startTime = fft_start;
Vdc_FFTDATA.cycles = fft_cycle; 
Vdc_FFTDATA.fundamental = fft_fund; 
Vdc_FFTDATA.maxFrequency = fft_maxfreq;
Vdc_FFTDATA.THDmaxFrequency = fft_THDmaxfreq;
Vdc_FFTDATA = power_fftscope(Vdc_FFTDATA);

%%
Iin_FFTDATA_unbalanced = Iin_FFTDATA;
Idc_FFTDATA_unbalanced = Idc_FFTDATA;
Icap_FFTDATA_unbalanced = Icap_FFTDATA;
Vdc_FFTDATA_unbalanced = Vdc_FFTDATA;

%%
Iin_FFTDATA_balanced = Iin_FFTDATA;
Idc_FFTDATA_balanced = Idc_FFTDATA;
Icap_FFTDATA_balanced = Icap_FFTDATA;
Vdc_FFTDATA_balanced = Vdc_FFTDATA;

%%
figure;
hold all;
plot(Vdc_FFTDATA_unbalanced.freq,Vdc_FFTDATA_unbalanced.mag,'r-o','Linewidth',1);
plot(Vdc_FFTDATA_balanced.freq,Vdc_FFTDATA_balanced.mag,'b-o','Linewidth',1);
set(gca,'FontSize',14);
xlabel('Frequency (Hz)','FontSize',14,'FontWeight','Bold')
ylabel('Magnitude (Volts)','FontSize',14,'FontWeight','Bold')
xlim([-1 1000]);
ylim([0 10]);
legend({'Unbalanced','Balanced'},'Location','best');
title('Vdc');

%%
figure;
hold all;
plot(Idc_FFTDATA_unbalanced.freq,Idc_FFTDATA_unbalanced.mag,'r-o','Linewidth',1);
plot(Idc_FFTDATA_balanced.freq,Idc_FFTDATA_balanced.mag,'b-o','Linewidth',1);
set(gca,'FontSize',14);
xlabel('Frequency (Hz)','FontSize',14,'FontWeight','Bold')
ylabel('Magnitude (Amps)','FontSize',14,'FontWeight','Bold')
xlim([-1 1000]);
ylim([0 1]);
legend({'Unbalanced','Balanced'},'Location','best');
title('Idc');

%%
figure;
hold all;
plot(Iin_FFTDATA_unbalanced.freq,Iin_FFTDATA_unbalanced.mag,'r-o','Linewidth',1);
plot(Iin_FFTDATA_balanced.freq,Iin_FFTDATA_balanced.mag,'b-o','Linewidth',1);
set(gca,'FontSize',14);
xlabel('Frequency (Hz)','FontSize',14,'FontWeight','Bold')
ylabel('Magnitude (Volts)','FontSize',14,'FontWeight','Bold')
xlim([-1 1000]);
ylim([0 1]);
legend({'Unbalanced','Balanced'},'Location','best');
title('Iin');

%%
figure;
hold all;
plot(Icap_FFTDATA_unbalanced.freq,Icap_FFTDATA_unbalanced.mag,'r-o','Linewidth',1);
plot(Icap_FFTDATA_balanced.freq,Icap_FFTDATA_balanced.mag,'b-o','Linewidth',1);
set(gca,'FontSize',14);
xlabel('Frequency (Hz)','FontSize',14,'FontWeight','Bold')
ylabel('Magnitude (Volts)','FontSize',14,'FontWeight','Bold')
xlim([-1 1000]);
ylim([0 0.3]);
legend({'Unbalanced','Balanced'},'Location','best');
title('Icap');
