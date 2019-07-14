% FFT parameters
fft_cycle = 10;
fft_start = 0.3;
fft_fund = 50;
fft_maxfreq = 50000;
fft_THDmaxfreq = 50000;

%% PWM Signals - A - M1
SA1_FFTDATA = power_fftscope(SA1);
SA1_FFTDATA.startTime = fft_start;
SA1_FFTDATA.cycles = fft_cycle; 
SA1_FFTDATA.fundamental = fft_fund; 
SA1_FFTDATA.maxFrequency = fft_maxfreq;
SA1_FFTDATA.THDmaxFrequency = fft_THDmaxfreq;
SA1_FFTDATA = power_fftscope(SA1_FFTDATA);
num = numel(SA1_FFTDATA.mag);
SA1_DCcomp = SA1_FFTDATA.mag(1);
SA1_Fundcomp = SA1_FFTDATA.mag(SA1_FFTDATA.freq == 50);
%clc;
fprintf('\n----- PWM - M1 - Ph A -----\n');
%fprintf('\nDC component: %g\n',SA1_DCcomp);
%fprintf('\nFundamental component: %g\n',SA1_Fundcomp);
for k = 1:num
    if (SA1_FFTDATA.mag(k) >= SA_DCcomp*0.1 || SA1_FFTDATA.mag(k) >= SA1_Fundcomp*0.1)
        fprintf('Freq: %g, Mag: %g, Phase: %g\n',SA1_FFTDATA.freq(k),SA1_FFTDATA.mag(k),SA1_FFTDATA.phase(k));
    end    
end

%% PWM Signals - B - M1
SB1_FFTDATA = power_fftscope(SB1);
SB1_FFTDATA.startTime = fft_start;
SB1_FFTDATA.cycles = fft_cycle; 
SB1_FFTDATA.fundamental = fft_fund; 
SB1_FFTDATA.maxFrequency = fft_maxfreq;
SB1_FFTDATA.THDmaxFrequency = fft_THDmaxfreq;
SB1_FFTDATA = power_fftscope(SB1_FFTDATA);
num = numel(SB1_FFTDATA.mag);
SB1_DCcomp = SB1_FFTDATA.mag(1);
SB1_Fundcomp = SB1_FFTDATA.mag(SB1_FFTDATA.freq == 50);
%clc;
fprintf('\n----- PWM - M1 - Ph B -----\n');
%fprintf('\nDC component: %g\n',SB1_DCcomp);
%fprintf('\nFundamental component: %g\n',SB1_Fundcomp);
for k = 1:num
    if (SB1_FFTDATA.mag(k) >= SB1_DCcomp*0.1 || SB1_FFTDATA.mag(k) >= SB1_Fundcomp*0.1)
        fprintf('Freq: %g, Mag: %g, Phase: %g\n',SB1_FFTDATA.freq(k),SB1_FFTDATA.mag(k),SB1_FFTDATA.phase(k));
    end    
end

%% PWM Signals - C - M1
SC1_FFTDATA = power_fftscope(SC1);
SC1_FFTDATA.startTime = fft_start;
SC1_FFTDATA.cycles = fft_cycle; 
SC1_FFTDATA.fundamental = fft_fund; 
SC1_FFTDATA.maxFrequency = fft_maxfreq;
SC1_FFTDATA.THDmaxFrequency = fft_THDmaxfreq;
SC1_FFTDATA = power_fftscope(SC1_FFTDATA);
num = numel(SC1_FFTDATA.mag);
SC1_DCcomp = SC1_FFTDATA.mag(1);
SC1_Fundcomp = SC1_FFTDATA.mag(SC1_FFTDATA.freq == 50);
%clc;
fprintf('\n----- PWM - M1 - Ph C -----\n');
%fprintf('\nDC component: %g\n',SC1_DCcomp);
%fprintf('\nFundamental component: %g\n',SC1_Fundcomp);
for k = 1:num
    if (SC1_FFTDATA.mag(k) >= SC1_DCcomp*0.1 || SC1_FFTDATA.mag(k) >= SC1_Fundcomp*0.1)
        fprintf('Freq: %g, Mag: %g, Phase: %g\n',SC1_FFTDATA.freq(k),SC1_FFTDATA.mag(k),SC1_FFTDATA.phase(k));
    end    
end

%% is - A - M1
isa1_FFTDATA = power_fftscope(isa1);
isa1_FFTDATA.startTime = fft_start;
isa1_FFTDATA.cycles = fft_cycle; 
isa1_FFTDATA.fundamental = fft_fund; 
isa1_FFTDATA.maxFrequency = fft_maxfreq;
isa1_FFTDATA.THDmaxFrequency = fft_THDmaxfreq;
isa1_FFTDATA = power_fftscope(isa1_FFTDATA);
num = numel(isa1_FFTDATA.mag);
isa1_DCcomp = isa1_FFTDATA.mag(1);
isa1_Fundcomp = isa1_FFTDATA.mag(isa1_FFTDATA.freq == 50);
%clc;
fprintf('\n----- Current - M1 - Ph A -----\n');
%fprintf('\nDC component: %g\n',isa1_DCcomp);
%fprintf('\nFundamental component: %g\n',isa1_Fundcomp);
for k = 2:num
    if (isa1_FFTDATA.mag(k) >= isa1_Fundcomp*0.001)
        fprintf('Freq: %g, Mag: %g, Phase: %g\n',isa1_FFTDATA.freq(k),isa1_FFTDATA.mag(k),isa1_FFTDATA.phase(k));
    end    
end

%% is - B - M1
isb1_FFTDATA = power_fftscope(isb1);
isb1_FFTDATA.startTime = fft_start;
isb1_FFTDATA.cycles = fft_cycle; 
isb1_FFTDATA.fundamental = fft_fund; 
isb1_FFTDATA.maxFrequency = fft_maxfreq;
isb1_FFTDATA.THDmaxFrequency = fft_THDmaxfreq;
isb1_FFTDATA = power_fftscope(isb1_FFTDATA);
num = numel(isb1_FFTDATA.mag);
isb1_DCcomp = isb1_FFTDATA.mag(1);
isb1_Fundcomp = isb1_FFTDATA.mag(isb1_FFTDATA.freq == 50);
%clc;
fprintf('\n----- Current - M1 - Ph B -----\n');
%fprintf('\nDC component: %g\n',isb1_DCcomp);
%fprintf('\nFundamental component: %g\n',isb1_Fundcomp);
for k = 2:num
    if (isb1_FFTDATA.mag(k) >= isb1_Fundcomp*0.001)
        fprintf('Freq: %g, Mag: %g, Phase: %g\n',isb1_FFTDATA.freq(k),isb1_FFTDATA.mag(k),isb1_FFTDATA.phase(k));
    end    
end

%% is - C - M1
isc1_FFTDATA = power_fftscope(isc1);
isc1_FFTDATA.startTime = fft_start;
isc1_FFTDATA.cycles = fft_cycle; 
isc1_FFTDATA.fundamental = fft_fund; 
isc1_FFTDATA.maxFrequency = fft_maxfreq;
isc1_FFTDATA.THDmaxFrequency = fft_THDmaxfreq;
isc1_FFTDATA = power_fftscope(isc1_FFTDATA);
num = numel(isc1_FFTDATA.mag);
isc1_DCcomp = isc1_FFTDATA.mag(1);
isc1_Fundcomp = isc1_FFTDATA.mag(isc1_FFTDATA.freq == 50);
%clc;
fprintf('\n----- Current - M1 - Ph C -----\n');
%fprintf('\nDC component: %g\n',isc1_DCcomp);
%fprintf('\nFundamental component: %g\n',isc1_Fundcomp);
for k = 2:num
    if (isc1_FFTDATA.mag(k) >= isc1_Fundcomp*0.001)
        fprintf('Freq: %g, Mag: %g, Phase: %g\n',isc1_FFTDATA.freq(k),isc1_FFTDATA.mag(k),isc1_FFTDATA.phase(k));
    end    
end

%% PWM Signals - A - M2
SA2_FFTDATA = power_fftscope(SA2);
SA2_FFTDATA.startTime = fft_start;
SA2_FFTDATA.cycles = fft_cycle; 
SA2_FFTDATA.fundamental = fft_fund; 
SA2_FFTDATA.maxFrequency = fft_maxfreq;
SA2_FFTDATA.THDmaxFrequency = fft_THDmaxfreq;
SA2_FFTDATA = power_fftscope(SA2_FFTDATA);
num = numel(SA2_FFTDATA.mag);
SA2_DCcomp = SA2_FFTDATA.mag(1);
SA2_Fundcomp = SA2_FFTDATA.mag(SA2_FFTDATA.freq == 50);
%clc;
fprintf('\n----- PWM - M2 - Ph A -----\n');
%fprintf('\nDC component: %g\n',SA2_DCcomp);
%fprintf('\nFundamental component: %g\n',SA2_Fundcomp);
for k = 1:num
    if (SA2_FFTDATA.mag(k) >= SA_DCcomp*0.1 || SA2_FFTDATA.mag(k) >= SA2_Fundcomp*0.1)
        fprintf('Freq: %g, Mag: %g, Phase: %g\n',SA2_FFTDATA.freq(k),SA2_FFTDATA.mag(k),SA2_FFTDATA.phase(k));
    end    
end

%% PWM Signals - B - M2
SB2_FFTDATA = power_fftscope(SB2);
SB2_FFTDATA.startTime = fft_start;
SB2_FFTDATA.cycles = fft_cycle; 
SB2_FFTDATA.fundamental = fft_fund; 
SB2_FFTDATA.maxFrequency = fft_maxfreq;
SB2_FFTDATA.THDmaxFrequency = fft_THDmaxfreq;
SB2_FFTDATA = power_fftscope(SB2_FFTDATA);
num = numel(SB2_FFTDATA.mag);
SB2_DCcomp = SB2_FFTDATA.mag(1);
SB2_Fundcomp = SB2_FFTDATA.mag(SB2_FFTDATA.freq == 50);
%clc;
fprintf('\n----- PWM - M2 - Ph B -----\n');
%fprintf('\nDC component: %g\n',SB2_DCcomp);
%fprintf('\nFundamental component: %g\n',SB2_Fundcomp);
for k = 1:num
    if (SB2_FFTDATA.mag(k) >= SB2_DCcomp*0.1 || SB2_FFTDATA.mag(k) >= SB2_Fundcomp*0.1)
        fprintf('Freq: %g, Mag: %g, Phase: %g\n',SB2_FFTDATA.freq(k),SB2_FFTDATA.mag(k),SB2_FFTDATA.phase(k));
    end    
end

%% PWM Signals - C - M2
SC2_FFTDATA = power_fftscope(SC2);
SC2_FFTDATA.startTime = fft_start;
SC2_FFTDATA.cycles = fft_cycle; 
SC2_FFTDATA.fundamental = fft_fund; 
SC2_FFTDATA.maxFrequency = fft_maxfreq;
SC2_FFTDATA.THDmaxFrequency = fft_THDmaxfreq;
SC2_FFTDATA = power_fftscope(SC2_FFTDATA);
num = numel(SC2_FFTDATA.mag);
SC2_DCcomp = SC2_FFTDATA.mag(1);
SC2_Fundcomp = SC2_FFTDATA.mag(SC2_FFTDATA.freq == 50);
%clc;
fprintf('\n----- PWM - M2 - Ph C -----\n');
%fprintf('\nDC component: %g\n',SC2_DCcomp);
%fprintf('\nFundamental component: %g\n',SC2_Fundcomp);
for k = 1:num
    if (SC2_FFTDATA.mag(k) >= SC2_DCcomp*0.1 || SC2_FFTDATA.mag(k) >= SC2_Fundcomp*0.1)
        fprintf('Freq: %g, Mag: %g, Phase: %g\n',SC2_FFTDATA.freq(k),SC2_FFTDATA.mag(k),SC2_FFTDATA.phase(k));
    end    
end

%% is - A - M2
isa2_FFTDATA = power_fftscope(isa2);
isa2_FFTDATA.startTime = fft_start;
isa2_FFTDATA.cycles = fft_cycle; 
isa2_FFTDATA.fundamental = fft_fund; 
isa2_FFTDATA.maxFrequency = fft_maxfreq;
isa2_FFTDATA.THDmaxFrequency = fft_THDmaxfreq;
isa2_FFTDATA = power_fftscope(isa2_FFTDATA);
num = numel(isa2_FFTDATA.mag);
isa2_DCcomp = isa2_FFTDATA.mag(1);
isa2_Fundcomp = isa2_FFTDATA.mag(isa2_FFTDATA.freq == 50);
%clc;
fprintf('\n----- Current - M2 - Ph A -----\n');
%fprintf('\nDC component: %g\n',isa2_DCcomp);
%fprintf('\nFundamental component: %g\n',isa2_Fundcomp);
for k = 2:num
    if (isa2_FFTDATA.mag(k) >= isa2_Fundcomp*0.001)
        fprintf('Freq: %g, Mag: %g, Phase: %g\n',isa2_FFTDATA.freq(k),isa2_FFTDATA.mag(k),isa2_FFTDATA.phase(k));
    end    
end

%% is - B - M2
isb2_FFTDATA = power_fftscope(isb2);
isb2_FFTDATA.startTime = fft_start;
isb2_FFTDATA.cycles = fft_cycle; 
isb2_FFTDATA.fundamental = fft_fund; 
isb2_FFTDATA.maxFrequency = fft_maxfreq;
isb2_FFTDATA.THDmaxFrequency = fft_THDmaxfreq;
isb2_FFTDATA = power_fftscope(isb2_FFTDATA);
num = numel(isb2_FFTDATA.mag);
isb2_DCcomp = isb2_FFTDATA.mag(1);
isb2_Fundcomp = isb2_FFTDATA.mag(isb2_FFTDATA.freq == 50);
%clc;
fprintf('\n----- Current - M2 - Ph B -----\n');
%fprintf('\nDC component: %g\n',isb2_DCcomp);
%fprintf('\nFundamental component: %g\n',isb2_Fundcomp);
for k = 2:num
    if (isb2_FFTDATA.mag(k) >= isb2_Fundcomp*0.001)
        fprintf('Freq: %g, Mag: %g, Phase: %g\n',isb2_FFTDATA.freq(k),isb2_FFTDATA.mag(k),isb2_FFTDATA.phase(k));
    end    
end

%% is - C - M2
isc2_FFTDATA = power_fftscope(isc2);
isc2_FFTDATA.startTime = fft_start;
isc2_FFTDATA.cycles = fft_cycle; 
isc2_FFTDATA.fundamental = fft_fund; 
isc2_FFTDATA.maxFrequency = fft_maxfreq;
isc2_FFTDATA.THDmaxFrequency = fft_THDmaxfreq;
isc2_FFTDATA = power_fftscope(isc2_FFTDATA);
num = numel(isc2_FFTDATA.mag);
isc2_DCcomp = isc2_FFTDATA.mag(1);
isc2_Fundcomp = isc2_FFTDATA.mag(isc2_FFTDATA.freq == 50);
%clc;
fprintf('\n----- Current - M2 - Ph C -----\n');
%fprintf('\nDC component: %g\n',isc2_DCcomp);
%fprintf('\nFundamental component: %g\n',isc2_Fundcomp);
for k = 2:num
    if (isc2_FFTDATA.mag(k) >= isc2_Fundcomp*0.001)
        fprintf('Freq: %g, Mag: %g, Phase: %g\n',isc2_FFTDATA.freq(k),isc2_FFTDATA.mag(k),isc2_FFTDATA.phase(k));
    end    
end

%% DC link current - M1
idc1_FFTDATA = power_fftscope(idc1);
idc1_FFTDATA.startTime = fft_start;
idc1_FFTDATA.cycles = fft_cycle; 
idc1_FFTDATA.fundamental = fft_fund; 
idc1_FFTDATA.maxFrequency = fft_maxfreq;
idc1_FFTDATA.THDmaxFrequency = fft_THDmaxfreq;
idc1_FFTDATA = power_fftscope(idc1_FFTDATA);
num = numel(idc1_FFTDATA.mag);
idc1_DCcomp = idc1_FFTDATA.mag(1);
%clc;
fprintf('\n----- DC Link Current - M1 -----\n');
%fprintf('\nDC component: %g\n',idc1_DCcomp);
idc1_rms_comp = idc1_DCcomp;
for k = 1:num
    if (idc1_FFTDATA.mag(k) >= idc1_DCcomp*0.05)
       fprintf('Freq: %g, Mag: %g, Phase: %g\n',idc1_FFTDATA.freq(k),idc1_FFTDATA.mag(k),idc1_FFTDATA.phase(k));
    end    
end

%% DC link current - M2
idc2_FFTDATA = power_fftscope(idc2);
idc2_FFTDATA.startTime = fft_start;
idc2_FFTDATA.cycles = fft_cycle; 
idc2_FFTDATA.fundamental = fft_fund; 
idc2_FFTDATA.maxFrequency = fft_maxfreq;
idc2_FFTDATA.THDmaxFrequency = fft_THDmaxfreq;
idc2_FFTDATA = power_fftscope(idc2_FFTDATA);
num = numel(idc2_FFTDATA.mag);
idc2_DCcomp = idc2_FFTDATA.mag(1);
%clc;
fprintf('\n----- DC Link Current - M2 -----\n');
%fprintf('\nDC component: %g\n',idc2_DCcomp);
idc2_rms_comp = idc2_DCcomp;
for k = 1:num
    if (idc2_FFTDATA.mag(k) >= idc2_DCcomp*0.05)
       fprintf('Freq: %g, Mag: %g, Phase: %g\n',idc2_FFTDATA.freq(k),idc2_FFTDATA.mag(k),idc2_FFTDATA.phase(k));
    end    
end

%% Capacitor current - M1
icap1_FFTDATA = power_fftscope(icap1);
icap1_FFTDATA.startTime = fft_start;
icap1_FFTDATA.cycles = fft_cycle; 
icap1_FFTDATA.fundamental = fft_fund; 
icap1_FFTDATA.maxFrequency = fft_maxfreq;
icap1_FFTDATA.THDmaxFrequency = fft_THDmaxfreq;
icap1_FFTDATA = power_fftscope(icap1_FFTDATA);
num = numel(icap1_FFTDATA.mag);
icap1_DCcomp = icap1_FFTDATA.mag(1);
%clc;
fprintf('\n----- Capacitor Current - M1 -----\n');
%fprintf('\nDC component: %g\n',icap1_DCcomp);
icap1_rms_comp = icap1_DCcomp;
for k = 1:num
    if (icap1_FFTDATA.mag(k) >= idc_DCcomp*0.05)
       fprintf('Freq: %g, Mag: %g, Phase: %g\n',icap1_FFTDATA.freq(k),icap1_FFTDATA.mag(k),icap1_FFTDATA.phase(k));
       icap1_rms_comp = sqrt(icap1_rms_comp^2 + (icap1_FFTDATA.mag(k)/sqrt(2))^2);
    end    
end

%% Capacitor current - M2
icap2_FFTDATA = power_fftscope(icap2);
icap2_FFTDATA.startTime = fft_start;
icap2_FFTDATA.cycles = fft_cycle; 
icap2_FFTDATA.fundamental = fft_fund; 
icap2_FFTDATA.maxFrequency = fft_maxfreq;
icap2_FFTDATA.THDmaxFrequency = fft_THDmaxfreq;
icap2_FFTDATA = power_fftscope(icap2_FFTDATA);
num = numel(icap2_FFTDATA.mag);
icap2_DCcomp = icap2_FFTDATA.mag(1);
%clc;
fprintf('\n----- Capacitor Current - M2 -----\n');
%fprintf('\nDC component: %g\n',icap2_DCcomp);
icap2_rms_comp = icap2_DCcomp;
for k = 1:num
    if (icap2_FFTDATA.mag(k) >= idc_DCcomp*0.05)
       fprintf('Freq: %g, Mag: %g, Phase: %g\n',icap2_FFTDATA.freq(k),icap2_FFTDATA.mag(k),icap2_FFTDATA.phase(k));
       icap2_rms_comp = sqrt(icap2_rms_comp^2 + (icap2_FFTDATA.mag(k)/sqrt(2))^2);
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
num = numel(vdc_FFTDATA.mag);
vdc_DCcomp = vdc_FFTDATA.mag(1);
%clc;
fprintf('\n----- DC Link Voltage -----\n');
%fprintf('\nDC component: %g\n',vdc_DCcomp);
for k = 1:num
    if (vdc_FFTDATA.mag(k) >= vdc_DCcomp*5e-4)
       fprintf('Freq: %g, Mag: %g, Phase: %g\n',vdc_FFTDATA.freq(k),vdc_FFTDATA.mag(k),vdc_FFTDATA.phase(k));
    end    
end

%% Input current - M1
iin1_FFTDATA = power_fftscope(iin1);
iin1_FFTDATA.startTime = fft_start;
iin1_FFTDATA.cycles = fft_cycle; 
iin1_FFTDATA.fundamental = fft_fund; 
iin1_FFTDATA.maxFrequency = fft_maxfreq;
iin1_FFTDATA.THDmaxFrequency = fft_THDmaxfreq;
iin1_FFTDATA = power_fftscope(iin1_FFTDATA);
num = numel(iin1_FFTDATA.mag);
iin1_DCcomp = iin1_FFTDATA.mag(1);
%clc;
fprintf('\n----- Input Current - M1 -----\n');
%fprintf('\nDC component: %g\n',iin1_DCcomp);
iin1_rms_comp = iin1_DCcomp;
for k = 1:num
    if (iin1_FFTDATA.mag(k) >= idc_DCcomp*0.01)
       fprintf('Freq: %g, Mag: %g, Phase: %g\n',iin1_FFTDATA.freq(k),iin1_FFTDATA.mag(k),iin1_FFTDATA.phase(k));
       iin1_rms_comp = sqrt(iin1_rms_comp^2 + (iin1_FFTDATA.mag(k)/sqrt(2))^2);
    end    
end

%% Input current - M2
iin2_FFTDATA = power_fftscope(iin2);
iin2_FFTDATA.startTime = fft_start;
iin2_FFTDATA.cycles = fft_cycle; 
iin2_FFTDATA.fundamental = fft_fund; 
iin2_FFTDATA.maxFrequency = fft_maxfreq;
iin2_FFTDATA.THDmaxFrequency = fft_THDmaxfreq;
iin2_FFTDATA = power_fftscope(iin2_FFTDATA);
num = numel(iin2_FFTDATA.mag);
iin2_DCcomp = iin2_FFTDATA.mag(1);
%clc;
fprintf('\n----- Input Current - M2 -----\n');
%fprintf('\nDC component: %g\n',iin2_DCcomp);
iin2_rms_comp = iin2_DCcomp;
for k = 1:num
    if (iin2_FFTDATA.mag(k) >= idc_DCcomp*0.01)
       fprintf('Freq: %g, Mag: %g, Phase: %g\n',iin2_FFTDATA.freq(k),iin2_FFTDATA.mag(k),iin2_FFTDATA.phase(k));
       iin2_rms_comp = sqrt(iin2_rms_comp^2 + (iin2_FFTDATA.mag(k)/sqrt(2))^2);
    end    
end

%%

