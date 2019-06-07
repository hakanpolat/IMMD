Ts = 1e-6; % sec
Tfinal = 0.5; % sec
Ripth = 0.3; % sec
minlim = 200; % V
maxlim = 340; % V
fsw = 10e3; % Hz
Vdc = 540; % Volts
Pout = 8e3; % W
Ef = 80; % Volts
Ls = 3.5e-3; % Henries
Rs = 1e-3; % Ohms
fout = 50; % Hz
wout = 2*pi*fout; % rad/sec
m = 3;
np = 2;
ns = 2;
n = ns*np;
Poutm = Pout/n; % Watts
Is = Poutm/(Ef*m); % amps
Xs = wout*Ls; % Ohms
Vdrop = Is*Xs; % Volts
Vt = sqrt(Ef^2+Vdrop^2); % Volts
Vdcm = Vdc/ns; % volts
ma = Vt*sqrt(3)/(Vdcm*0.612);
delta = acos(Ef/Vt); % radians
deltad = delta*180/pi; % degrees
pf = cos(delta);
phase = [0 90 0 90];
Rin = 70;
Lin = 1e-15;
Vinm = Vdcm + Rin*(Poutm/Vdcm);
Cdc1 = 5e-6; % F
Cdc = 3*Cdc1; % F
%ESL = 19e-9; % H
%ESR = 21.1e-3; % Ohm
ESL = 19e-15; % H
ESR = 21.1e-15; % Ohm
Lpar = 5e-15; % H
Rpar = 1e-15;

%%
%sim('sim_model_simpledclink');

%%
% FFT parameters
fft_cycle = 10;
fft_start = 0.3;
fft_fund = 50;
fft_maxfreq = 100000;
fft_THDmaxfreq = 100000;

%% DC link current
idc_FFTDATA = power_fftscope(idc);
idc_FFTDATA.startTime = fft_start;
idc_FFTDATA.cycles = fft_cycle; 
idc_FFTDATA.fundamental = fft_fund; 
idc_FFTDATA.maxFrequency = fft_maxfreq;
idc_FFTDATA.THDmaxFrequency = fft_THDmaxfreq;
idc_FFTDATA = power_fftscope(idc_FFTDATA);
num = numel(idc_FFTDATA.mag);
idc_DCcomp = idc_FFTDATA.mag(1);
%clc;
fprintf('\nDC component: %g\n',idc_DCcomp);
idc_rms_comp = idc_DCcomp;
for k = 2:num
    if (idc_FFTDATA.mag(k) >= idc_DCcomp*0.05)
       fprintf('\nFreq: %g, Mag: %g, Phase: %g\n',idc_FFTDATA.freq(k),idc_FFTDATA.mag(k),idc_FFTDATA.phase(k));
       idc_rms_comp = sqrt(idc_rms_comp^2 + (idc_FFTDATA.mag(k)/sqrt(2))^2);
    end    
end

%% PWM Signals - A
SA_FFTDATA = power_fftscope(SA);
SA_FFTDATA.startTime = fft_start;
SA_FFTDATA.cycles = fft_cycle; 
SA_FFTDATA.fundamental = fft_fund; 
SA_FFTDATA.maxFrequency = fft_maxfreq;
SA_FFTDATA.THDmaxFrequency = fft_THDmaxfreq;
SA_FFTDATA = power_fftscope(SA_FFTDATA);
num = numel(SA_FFTDATA.mag);
SA_DCcomp = SA_FFTDATA.mag(1);
SA_Fundcomp = SA_FFTDATA.mag(SA_FFTDATA.freq == 50);
clc;
fprintf('\nDC component: %g\n',SA_DCcomp);
fprintf('\nFundamental component: %g\n',SA_Fundcomp);
for k = 1:num
    if (SA_FFTDATA.mag(k) >= SA_DCcomp*0.1 || SA_FFTDATA.mag(k) >= SA_Fundcomp*0.1)
        fprintf('\nFreq: %g, Mag: %g, Phase: %g\n',SA_FFTDATA.freq(k),SA_FFTDATA.mag(k),SA_FFTDATA.phase(k));
    end    
end

%% PWM Signals - B
SB_FFTDATA = power_fftscope(SB);
SB_FFTDATA.startTime = fft_start;
SB_FFTDATA.cycles = fft_cycle; 
SB_FFTDATA.fundamental = fft_fund; 
SB_FFTDATA.maxFrequency = fft_maxfreq;
SB_FFTDATA.THDmaxFrequency = fft_THDmaxfreq;
SB_FFTDATA = power_fftscope(SB_FFTDATA);
num = numel(SB_FFTDATA.mag);
SB_DCcomp = SB_FFTDATA.mag(1);
SB_Fundcomp = SB_FFTDATA.mag(SB_FFTDATA.freq == 50);
clc;
fprintf('\nDC component: %g\n',SB_DCcomp);
fprintf('\nFundamental component: %g\n',SB_Fundcomp);
for k = 1:num
    if (SB_FFTDATA.mag(k) >= SB_DCcomp*0.1 || SB_FFTDATA.mag(k) >= SB_Fundcomp*0.1)
        fprintf('\nFreq: %g, Mag: %g, Phase: %g\n',SB_FFTDATA.freq(k),SB_FFTDATA.mag(k),SB_FFTDATA.phase(k));
    end    
end

%% PWM Signals - C
SC_FFTDATA = power_fftscope(SC);
SC_FFTDATA.startTime = fft_start;
SC_FFTDATA.cycles = fft_cycle; 
SC_FFTDATA.fundamental = fft_fund; 
SC_FFTDATA.maxFrequency = fft_maxfreq;
SC_FFTDATA.THDmaxFrequency = fft_THDmaxfreq;
SC_FFTDATA = power_fftscope(SC_FFTDATA);
num = numel(SC_FFTDATA.mag);
SC_DCcomp = SC_FFTDATA.mag(1);
SC_Fundcomp = SC_FFTDATA.mag(SC_FFTDATA.freq == 50);
clc;
fprintf('\nDC component: %g\n',SC_DCcomp);
fprintf('\nFundamental component: %g\n',SC_Fundcomp);
for k = 1:num
    if (SC_FFTDATA.mag(k) >= SC_DCcomp*0.1 || SC_FFTDATA.mag(k) >= SC_Fundcomp*0.1)
        fprintf('\nFreq: %g, Mag: %g, Phase: %g\n',SC_FFTDATA.freq(k),SC_FFTDATA.mag(k),SC_FFTDATA.phase(k));
    end    
end
 
%% Vll - AB
% Vll_FFTDATA = power_fftscope(vll);
% Vll_FFTDATA.startTime = fft_start;
% Vll_FFTDATA.cycles = fft_cycle; 
% Vll_FFTDATA.fundamental = fft_fund; 
% Vll_FFTDATA.maxFrequency = fft_maxfreq;
% Vll_FFTDATA.THDmaxFrequency = fft_THDmaxfreq;
% Vll_FFTDATA = power_fftscope(Vll_FFTDATA);
% num = numel(Vll_FFTDATA.mag);
% DCcomp = Vll_FFTDATA.mag(1);
% Fundcomp = Vll_FFTDATA.mag(Vll_FFTDATA.freq == 50);
% clc;
% fprintf('\nDC component: %g\n',DCcomp);
% fprintf('\nFundamental component: %g\n',Fundcomp);
% for k = 2:num
%     if (Vll_FFTDATA.mag(k) >= Fundcomp*0.05)
%         fprintf('\nFreq: %g, Mag: %g, Phase: %g\n',Vll_FFTDATA.freq(k),Vll_FFTDATA.mag(k),Vll_FFTDATA.phase(k));
%     end    
% end

%% is - A
isa_FFTDATA = power_fftscope(isa);
isa_FFTDATA.startTime = fft_start;
isa_FFTDATA.cycles = fft_cycle; 
isa_FFTDATA.fundamental = fft_fund; 
isa_FFTDATA.maxFrequency = fft_maxfreq;
isa_FFTDATA.THDmaxFrequency = fft_THDmaxfreq;
isa_FFTDATA = power_fftscope(isa_FFTDATA);
num = numel(isa_FFTDATA.mag);
isa_DCcomp = isa_FFTDATA.mag(1);
isa_Fundcomp = isa_FFTDATA.mag(isa_FFTDATA.freq == 50);
clc;
fprintf('\nDC component: %g\n',isa_DCcomp);
fprintf('\nFundamental component: %g\n',isa_Fundcomp);
for k = 2:num
    if (isa_FFTDATA.mag(k) >= isa_Fundcomp*0.002)
        fprintf('\nFreq: %g, Mag: %g, Phase: %g\n',isa_FFTDATA.freq(k),isa_FFTDATA.mag(k),isa_FFTDATA.phase(k));
    end    
end

%% is - B
isb_FFTDATA = power_fftscope(isb);
isb_FFTDATA.startTime = fft_start;
isb_FFTDATA.cycles = fft_cycle; 
isb_FFTDATA.fundamental = fft_fund; 
isb_FFTDATA.maxFrequency = fft_maxfreq;
isb_FFTDATA.THDmaxFrequency = fft_THDmaxfreq;
isb_FFTDATA = power_fftscope(isb_FFTDATA);
num = numel(isb_FFTDATA.mag);
isb_DCcomp = isb_FFTDATA.mag(1);
isb_Fundcomp = isb_FFTDATA.mag(isb_FFTDATA.freq == 50);
clc;
fprintf('\nDC component: %g\n',isb_DCcomp);
fprintf('\nFundamental component: %g\n',isb_Fundcomp);
for k = 2:num
    if (isb_FFTDATA.mag(k) >= isb_Fundcomp*0.002)
        fprintf('\nFreq: %g, Mag: %g, Phase: %g\n',isb_FFTDATA.freq(k),isb_FFTDATA.mag(k),isb_FFTDATA.phase(k));
    end    
end

%% is - C
isc_FFTDATA = power_fftscope(isc);
isc_FFTDATA.startTime = fft_start;
isc_FFTDATA.cycles = fft_cycle; 
isc_FFTDATA.fundamental = fft_fund; 
isc_FFTDATA.maxFrequency = fft_maxfreq;
isc_FFTDATA.THDmaxFrequency = fft_THDmaxfreq;
isc_FFTDATA = power_fftscope(isc_FFTDATA);
num = numel(isc_FFTDATA.mag);
isc_DCcomp = isc_FFTDATA.mag(1);
isc_Fundcomp = isc_FFTDATA.mag(isc_FFTDATA.freq == 50);
clc;
fprintf('\nDC component: %g\n',isc_DCcomp);
fprintf('\nFundamental component: %g\n',isc_Fundcomp);
for k = 2:num
    if (isc_FFTDATA.mag(k) >= isc_Fundcomp*0.002)
        fprintf('\nFreq: %g, Mag: %g, Phase: %g\n',isc_FFTDATA.freq(k),isc_FFTDATA.mag(k),isc_FFTDATA.phase(k));
    end    
end

%%
clc
captured_components_a_mag = 0;
captured_components_a_freq1 = 0;
captured_components_a_freq2 = 0;
captured_components_a_phase1 = 0;
captured_components_a_phase2 = 0;

captured_components_b_mag = 0;
captured_components_b_freq1 = 0;
captured_components_b_freq2 = 0;
captured_components_b_phase1 = 0;
captured_components_b_phase2 = 0;

captured_components_c_mag = 0;
captured_components_c_freq1 = 0;
captured_components_c_freq2 = 0;
captured_components_c_phase1 = 0;
captured_components_c_phase2 = 0;

for k = 1:num
   if (SA_FFTDATA.mag(k) >= SA_DCcomp*0.1 || SA_FFTDATA.mag(k) >= SA_Fundcomp*0.1)
       for l = 1:2000
           if (isa_FFTDATA.mag(l) >= isa_Fundcomp*0.002)
               new_comp_a_mag = SA_FFTDATA.mag(k) * isa_FFTDATA.mag(l) / 2;
               if (new_comp_a_mag > 0.1)
                   if (k == 1)
                       new_comp_a_freq1 = isa_FFTDATA.freq(l);
                       new_comp_a_freq2 = isa_FFTDATA.freq(l);
                       new_comp_a_phase1 = isa_FFTDATA.phase(l);
                       new_comp_a_phase2 = isa_FFTDATA.phase(l);
                   else
                       new_comp_a_freq1 = abs(SA_FFTDATA.freq(k) + isa_FFTDATA.freq(l));
                       new_comp_a_freq2 = abs(SA_FFTDATA.freq(k) - isa_FFTDATA.freq(l));
                       new_comp_a_phase1 = SA_FFTDATA.phase(k) + isa_FFTDATA.phase(l);
                       new_comp_a_phase2 = SA_FFTDATA.phase(k) - isa_FFTDATA.phase(l);
                   end
                   captured_components_a_mag = [captured_components_a_mag new_comp_a_mag];
                   captured_components_a_freq1 = [captured_components_a_freq1 new_comp_a_freq1];
                   captured_components_a_freq2 = [captured_components_a_freq2 new_comp_a_freq2];
                   captured_components_a_phase1 = [captured_components_a_phase1 new_comp_a_phase1];
                   captured_components_a_phase2 = [captured_components_a_phase2 new_comp_a_phase2];
               end
           end
       end
   end
end

for k = 1:num
   if (SB_FFTDATA.mag(k) >= SB_DCcomp*0.1 || SB_FFTDATA.mag(k) >= SB_Fundcomp*0.1)
       for l = 1:2000
           if (isb_FFTDATA.mag(l) >= isb_Fundcomp*0.002)
               new_comp_b_mag = SB_FFTDATA.mag(k) * isb_FFTDATA.mag(l) / 2;
               if (new_comp_b_mag > 0.1)
                   if (k == 1)
                       new_comp_b_freq1 = isb_FFTDATA.freq(l);
                       new_comp_b_freq2 = isb_FFTDATA.freq(l);
                       new_comp_b_phase1 = isb_FFTDATA.phase(l);
                       new_comp_b_phase2 = isb_FFTDATA.phase(l);
                   else
                       new_comp_b_freq1 = abs(SB_FFTDATA.freq(k) + isb_FFTDATA.freq(l));
                       new_comp_b_freq2 = abs(SB_FFTDATA.freq(k) - isb_FFTDATA.freq(l));
                       new_comp_b_phase1 = SB_FFTDATA.phase(k) + isb_FFTDATA.phase(l);
                       new_comp_b_phase2 = SB_FFTDATA.phase(k) - isb_FFTDATA.phase(l);
                   end
                   captured_components_b_mag = [captured_components_b_mag new_comp_b_mag];
                   captured_components_b_freq1 = [captured_components_b_freq1 new_comp_b_freq1];
                   captured_components_b_freq2 = [captured_components_b_freq2 new_comp_b_freq2];
                   captured_components_b_phase1 = [captured_components_b_phase1 new_comp_b_phase1];
                   captured_components_b_phase2 = [captured_components_b_phase2 new_comp_b_phase2];
               end
           end
       end
   end
end

for k = 1:num
   if (SC_FFTDATA.mag(k) >= SC_DCcomp*0.1 || SC_FFTDATA.mag(k) >= SC_Fundcomp*0.1)
       for l = 1:2000
           if (isc_FFTDATA.mag(l) >= isc_Fundcomp*0.002)
               new_comp_c_mag = SC_FFTDATA.mag(k) * isc_FFTDATA.mag(l) / 2;
               if (new_comp_c_mag > 0.1)
                   if (k == 1)
                       new_comp_c_freq1 = isc_FFTDATA.freq(l);
                       new_comp_c_freq2 = isc_FFTDATA.freq(l);
                       new_comp_c_phase1 = isc_FFTDATA.phase(l);
                       new_comp_c_phase2 = isc_FFTDATA.phase(l);
                   else
                       new_comp_c_freq1 = abs(SC_FFTDATA.freq(k) + isc_FFTDATA.freq(l));
                       new_comp_c_freq2 = abs(SC_FFTDATA.freq(k) - isc_FFTDATA.freq(l));
                       new_comp_c_phase1 = SC_FFTDATA.phase(k) + isc_FFTDATA.phase(l);
                       new_comp_c_phase2 = SC_FFTDATA.phase(k) - isc_FFTDATA.phase(l);
                   end
                   captured_components_c_mag = [captured_components_c_mag new_comp_c_mag];
                   captured_components_c_freq1 = [captured_components_c_freq1 new_comp_c_freq1];
                   captured_components_c_freq2 = [captured_components_c_freq2 new_comp_c_freq2];
                   captured_components_c_phase1 = [captured_components_c_phase1 new_comp_c_phase1];
                   captured_components_c_phase2 = [captured_components_c_phase2 new_comp_c_phase2];
               end
           end
       end
   end
end

idca_harm1 = [captured_components_a_freq1',captured_components_a_mag',captured_components_a_phase1'];
idca_harm2 = [captured_components_a_freq2',captured_components_a_mag',captured_components_a_phase2'];

idcb_harm1 = [captured_components_b_freq1',captured_components_b_mag',captured_components_b_phase1'];
idcb_harm2 = [captured_components_b_freq2',captured_components_b_mag',captured_components_b_phase2'];

idcc_harm1 = [captured_components_c_freq1',captured_components_c_mag',captured_components_c_phase1'];
idcc_harm2 = [captured_components_c_freq2',captured_components_c_mag',captured_components_c_phase2'];

idc_harm = [idca_harm1;idca_harm2;idcb_harm1;idcb_harm2;idcc_harm1;idcc_harm2];


%%
clc;

different_freq = -1;
for k = 1:numel(idc_harm(:,1))
    trial_freq = idc_harm(k,1);
    %for l = 1:numel(different_freq)
        if (trial_freq ~= different_freq(:))
            different_freq = [different_freq; idc_harm(k,1)];
        end
    %end
end

idc_harm_comp = zeros(numel(different_freq)-1,5);
idc_harm_comp(:,1) = different_freq(2:end);

for l = 2:numel(idc_harm_comp(:,1))
    for k = 1:numel(idc_harm(:,1))
        if (idc_harm(k,1) == idc_harm_comp(l))
            idc_harm_comp(l,4) = idc_harm_comp(l,4) + idc_harm(k,2)*cos(idc_harm(k,3)*pi/180);
            idc_harm_comp(l,5) = idc_harm_comp(l,5) + idc_harm(k,2)*sin(idc_harm(k,3)*pi/180);            
        end
    end
    idc_harm_comp(l,2) = sqrt(idc_harm_comp(l,4)^2 + idc_harm_comp(l,5)^2);
    idc_harm_comp(l,3) = atan(idc_harm_comp(l,5) / idc_harm_comp(l,4))*180/pi;
end
for k = 1:numel(idc_harm(:,1))
    if (idc_harm(k,1) == 0)
        idc_harm_comp(1,2) = idc_harm_comp(1,2) + idc_harm(k,2);
    end
end
idc_harm_comp;

idc_harm_comp_filtered = zeros(1,5);
idc_harm_comp_filtered(1,:) = idc_harm_comp(1,:);
for k = 2:numel(idc_harm_comp(:,1))
    if (idc_harm_comp(k,2) > 0.1)
       idc_harm_comp_filtered = [idc_harm_comp_filtered;idc_harm_comp(k,:)];
    end
end
idc_harm_comp_filtered;

idc_harm_comp_filtered_sorted = sortrows(idc_harm_comp_filtered(:,1:3),1)


%%
idc_calc_harm = zeros(1,num);
for k = 1:num
    cond = any(idc_FFTDATA.freq(k) == idc_harm_comp_filtered_sorted(:,1),1);
    if (cond == 1)
        my_index = find(idc_harm_comp_filtered_sorted(:,1) == idc_FFTDATA.freq(k));
        idc_calc_harm(k) = idc_harm_comp_filtered_sorted(my_index,2);
    end
end
figure;
hold all;
plot(idc_FFTDATA.freq*1e-3,idc_FFTDATA.mag,'r-','Linewidth',1);
plot(idc_FFTDATA.freq*1e-3,idc_calc_harm,'b-','Linewidth',1);
set(gca,'FontSize',14);
xlabel('Frequency (kHz)','FontSize',14,'FontWeight','Bold')
ylabel('Magnitude (Amps)','FontSize',14,'FontWeight','Bold')
xlim([-1 51]);
ylim([0 10]);
legend({'Simulated','Calculated'},'Location','best');


%% DC link input current
IinFFTDATA = power_fftscope(Iin);
IinFFTDATA.startTime = fft_start;
IinFFTDATA.cycles = fft_cycle; 
IinFFTDATA.fundamental = fft_fund; 
IinFFTDATA.maxFrequency = fft_maxfreq;
IinFFTDATA.THDmaxFrequency = fft_THDmaxfreq;
IinFFTDATA = power_fftscope(IinFFTDATA);
num = numel(IinFFTDATA.mag);
IinDCcomp = IinFFTDATA.mag(1);
%clc;
fprintf('\nDC component: %g\n',IinDCcomp);
Iinrms_comp = IinDCcomp;
for k = 2:num
    if (IinFFTDATA.mag(k) >= IinDCcomp*0.01)
       fprintf('\nFreq: %g, Mag: %g, Phase: %g\n',IinFFTDATA.freq(k),IinFFTDATA.mag(k),IinFFTDATA.phase(k));
       Iinrms_comp = sqrt(Iinrms_comp^2 + (IinFFTDATA.mag(k)/sqrt(2))^2);
    end    
end


%%
% figure;
% hold all;
% plot(idc_FFTDATA.freq*1e-3,idc_FFTDATA.mag,'r-','Linewidth',1);
% plot(isa_FFTDATA.freq*1e-3,isa_FFTDATA.mag*10,'b-','Linewidth',1);
% set(gca,'FontSize',14);
% xlabel('Frequency (kHz)','FontSize',14,'FontWeight','Bold')
% ylabel('Magnitude (Amps)','FontSize',14,'FontWeight','Bold')
% xlim([-1 51]);
% ylim([0 10]);
% legend({'Idc','Isa'},'Location','best');

