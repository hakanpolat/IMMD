% FFT parameters
fft_cycle = 10;
fft_start = 0.3;
fft_fund = 50;
fft_maxfreq = 50000;
fft_THDmaxfreq = 50000;
num = 6400;

%% PWM Signals - A
SA_FFTDATA = power_fftscope(SA1);
SA_FFTDATA.startTime = fft_start;
SA_FFTDATA.cycles = fft_cycle; 
SA_FFTDATA.fundamental = fft_fund; 
SA_FFTDATA.maxFrequency = fft_maxfreq;
SA_FFTDATA.THDmaxFrequency = fft_THDmaxfreq;
SA_FFTDATA = power_fftscope(SA_FFTDATA);
%num = numel(SA_FFTDATA.mag);
SA_DCcomp = SA_FFTDATA.mag(1);
SA_Fundcomp = SA_FFTDATA.mag(SA_FFTDATA.freq == 50);
%clc;
fprintf('\n----- PWM - Phase A -----\n');
%fprintf('\nDC component: %g\n',SA_DCcomp);
%fprintf('\nFundamental component: %g\n',SA_Fundcomp);
for k = 1:num
    if (SA_FFTDATA.mag(k) >= SA_DCcomp*0.1 || SA_FFTDATA.mag(k) >= SA_Fundcomp*0.1)
        fprintf('Freq: %g, Mag: %g, Phase: %g\n',SA_FFTDATA.freq(k),SA_FFTDATA.mag(k),SA_FFTDATA.phase(k));
    end    
end

%% PWM Signals - B
SB_FFTDATA = power_fftscope(SB1);
SB_FFTDATA.startTime = fft_start;
SB_FFTDATA.cycles = fft_cycle; 
SB_FFTDATA.fundamental = fft_fund; 
SB_FFTDATA.maxFrequency = fft_maxfreq;
SB_FFTDATA.THDmaxFrequency = fft_THDmaxfreq;
SB_FFTDATA = power_fftscope(SB_FFTDATA);
%num = numel(SB_FFTDATA.mag);
SB_DCcomp = SB_FFTDATA.mag(1);
SB_Fundcomp = SB_FFTDATA.mag(SB_FFTDATA.freq == 50);
%clc;
fprintf('\n----- PWM - Phase B -----\n');
%fprintf('\nDC component: %g\n',SB_DCcomp);
%fprintf('\nFundamental component: %g\n',SB_Fundcomp);
for k = 1:num
    if (SB_FFTDATA.mag(k) >= SB_DCcomp*0.1 || SB_FFTDATA.mag(k) >= SB_Fundcomp*0.1)
        fprintf('Freq: %g, Mag: %g, Phase: %g\n',SB_FFTDATA.freq(k),SB_FFTDATA.mag(k),SB_FFTDATA.phase(k));
    end    
end

%% PWM Signals - C
SC_FFTDATA = power_fftscope(SC1);
SC_FFTDATA.startTime = fft_start;
SC_FFTDATA.cycles = fft_cycle; 
SC_FFTDATA.fundamental = fft_fund; 
SC_FFTDATA.maxFrequency = fft_maxfreq;
SC_FFTDATA.THDmaxFrequency = fft_THDmaxfreq;
SC_FFTDATA = power_fftscope(SC_FFTDATA);
%num = numel(SC_FFTDATA.mag);
SC_DCcomp = SC_FFTDATA.mag(1);
SC_Fundcomp = SC_FFTDATA.mag(SC_FFTDATA.freq == 50);
%clc;
fprintf('\n----- PWM - Phase C -----\n');
%fprintf('\nDC component: %g\n',SC_DCcomp);
%fprintf('\nFundamental component: %g\n',SC_Fundcomp);
for k = 1:num
    if (SC_FFTDATA.mag(k) >= SC_DCcomp*0.1 || SC_FFTDATA.mag(k) >= SC_Fundcomp*0.1)
        fprintf('Freq: %g, Mag: %g, Phase: %g\n',SC_FFTDATA.freq(k),SC_FFTDATA.mag(k),SC_FFTDATA.phase(k));
    end    
end

%% is - A
isa_FFTDATA = power_fftscope(isa1);
isa_FFTDATA.startTime = fft_start;
isa_FFTDATA.cycles = fft_cycle; 
isa_FFTDATA.fundamental = fft_fund; 
isa_FFTDATA.maxFrequency = fft_maxfreq;
isa_FFTDATA.THDmaxFrequency = fft_THDmaxfreq;
isa_FFTDATA = power_fftscope(isa_FFTDATA);
%num = numel(isa_FFTDATA.mag);
isa_DCcomp = isa_FFTDATA.mag(1);
isa_Fundcomp = isa_FFTDATA.mag(isa_FFTDATA.freq == 50);
%clc;
fprintf('\n----- Current - Phase A -----\n');
%fprintf('\nDC component: %g\n',isa_DCcomp);
%fprintf('\nFundamental component: %g\n',isa_Fundcomp);
for k = 2:num
    if (isa_FFTDATA.mag(k) >= isa_Fundcomp*0.001)
        fprintf('Freq: %g, Mag: %g, Phase: %g\n',isa_FFTDATA.freq(k),isa_FFTDATA.mag(k),isa_FFTDATA.phase(k));
    end    
end

%% is - B
isb_FFTDATA = power_fftscope(isb1);
isb_FFTDATA.startTime = fft_start;
isb_FFTDATA.cycles = fft_cycle; 
isb_FFTDATA.fundamental = fft_fund; 
isb_FFTDATA.maxFrequency = fft_maxfreq;
isb_FFTDATA.THDmaxFrequency = fft_THDmaxfreq;
isb_FFTDATA = power_fftscope(isb_FFTDATA);
%num = numel(isb_FFTDATA.mag);
isb_DCcomp = isb_FFTDATA.mag(1);
isb_Fundcomp = isb_FFTDATA.mag(isb_FFTDATA.freq == 50);
%clc;
fprintf('\n----- Current - Phase B -----\n');
%fprintf('\nDC component: %g\n',isb_DCcomp);
%fprintf('\nFundamental component: %g\n',isb_Fundcomp);
for k = 2:num
    if (isb_FFTDATA.mag(k) >= isb_Fundcomp*0.001)
        fprintf('Freq: %g, Mag: %g, Phase: %g\n',isb_FFTDATA.freq(k),isb_FFTDATA.mag(k),isb_FFTDATA.phase(k));
    end    
end

%% is - C
isc_FFTDATA = power_fftscope(isc1);
isc_FFTDATA.startTime = fft_start;
isc_FFTDATA.cycles = fft_cycle; 
isc_FFTDATA.fundamental = fft_fund; 
isc_FFTDATA.maxFrequency = fft_maxfreq;
isc_FFTDATA.THDmaxFrequency = fft_THDmaxfreq;
isc_FFTDATA = power_fftscope(isc_FFTDATA);
%num = numel(isc_FFTDATA.mag);
isc_DCcomp = isc_FFTDATA.mag(1);
isc_Fundcomp = isc_FFTDATA.mag(isc_FFTDATA.freq == 50);
%clc;
fprintf('\n----- Current - Phase C -----\n');
%fprintf('\nDC component: %g\n',isc_DCcomp);
%fprintf('\nFundamental component: %g\n',isc_Fundcomp);
for k = 2:num
    if (isc_FFTDATA.mag(k) >= isc_Fundcomp*0.001)
        fprintf('Freq: %g, Mag: %g, Phase: %g\n',isc_FFTDATA.freq(k),isc_FFTDATA.mag(k),isc_FFTDATA.phase(k));
    end    
end

%% DC link current
idc_FFTDATA = power_fftscope(idc);
idc_FFTDATA.startTime = fft_start;
idc_FFTDATA.cycles = fft_cycle; 
idc_FFTDATA.fundamental = fft_fund; 
idc_FFTDATA.maxFrequency = fft_maxfreq;
idc_FFTDATA.THDmaxFrequency = fft_THDmaxfreq;
idc_FFTDATA = power_fftscope(idc_FFTDATA);
%num = numel(idc_FFTDATA.mag);
idc_DCcomp = idc_FFTDATA.mag(1);
%clc;
fprintf('\n----- DC Link Current -----\n');
%fprintf('\nDC component: %g\n',idc_DCcomp);
for k = 1:num
    if (idc_FFTDATA.mag(k) >= idc_DCcomp*0.05)
       fprintf('Freq: %g, Mag: %g, Phase: %g\n',idc_FFTDATA.freq(k),idc_FFTDATA.mag(k),idc_FFTDATA.phase(k));
    end    
end

%% Capacitor current
icap_FFTDATA = power_fftscope(icap);
icap_FFTDATA.startTime = fft_start;
icap_FFTDATA.cycles = fft_cycle; 
icap_FFTDATA.fundamental = fft_fund; 
icap_FFTDATA.maxFrequency = fft_maxfreq;
icap_FFTDATA.THDmaxFrequency = fft_THDmaxfreq;
icap_FFTDATA = power_fftscope(icap_FFTDATA);
%num = numel(icap_FFTDATA.mag);
icap_DCcomp = icap_FFTDATA.mag(1);
%clc;
fprintf('\n----- Capacitor Current -----\n');
%fprintf('\nDC component: %g\n',icap_DCcomp);
icap_rms_comp = icap_DCcomp;
for k = 1:num
    if (icap_FFTDATA.mag(k) >= idc_DCcomp*0.05)
       fprintf('Freq: %g, Mag: %g, Phase: %g\n',icap_FFTDATA.freq(k),icap_FFTDATA.mag(k),icap_FFTDATA.phase(k));
       icap_rms_comp = sqrt(icap_rms_comp^2 + (icap_FFTDATA.mag(k)/sqrt(2))^2);
    end    
end

%% DC link voltage
vdc_FFTDATA = power_fftscope(vdc);
vdc_FFTDATA.startTime = fft_start;
vdc_FFTDATA.cycles = fft_cycle; 
vdc_FFTDATA.fundamental = fft_fund; 
vdc_FFTDATA.maxFrequency = fft_maxfreq;
vdc_FFTDATA.THDmaxFrequency = fft_THDmaxfreq;
vdc_FFTDATA = power_fftscope(vdc_FFTDATA);
%num = numel(vdc_FFTDATA.mag);
vdc_DCcomp = vdc_FFTDATA.mag(1);
%clc;
fprintf('\n----- DC Link Voltage -----\n');
%fprintf('\nDC component: %g\n',vdc_DCcomp);
temp_sum = 0;
for k = 1:num
    if (vdc_FFTDATA.mag(k) >= vdc_DCcomp*5e-4)
       fprintf('Freq: %g, Mag: %g, Phase: %g\n',vdc_FFTDATA.freq(k),vdc_FFTDATA.mag(k),vdc_FFTDATA.phase(k));
       %vc_calc = icap_FFTDATA.mag(k)/(2*pi*vdc_FFTDATA.freq(k)*Cdc)
       if k>1
           temp_sum = temp_sum + vdc_FFTDATA.mag(k);
       end
   end    
end

%fprintf('\nEstimated Voltage Ripple: %g Volts, %g %%\n',temp_sum,temp_sum/Vdcm*100);


%%

