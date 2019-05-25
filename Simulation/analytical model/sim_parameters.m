Ts = 1e-6; % sec
Tfinal = 0.5; % sec
Ripth = 0.25; % sec
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
Rin = 1;
%Lin = 1e-3;
Vinm = Vdcm + Rin*(Poutm/Vdcm);
Cdc1 = 5e-6; % F
Cdc = 3*Cdc1; % F
ESL = 19e-9; % H
Lpar = 5e-9; % H
Rpar = 1e-6;


%%
Vs1p = 0.42;
Vsphi = 6*pi/180;
Vshp = 0.37;
Vshphi = pi/2;
Voffset = 1.18*Vs1p;

%%
magnitude = 2.1;
ph1 = 161*pi/180;
ph2 = 6*pi/180;
v1 = magnitude*(cos(ph1)+1i*sin(ph1));
v2 = magnitude*(cos(ph2)+1i*sin(ph2));
v = v1+v2;
abs(v)
angle(v)*180/pi

%%
Isp = 11.83;
Vs1p = 0.42;
cosphi = 0.994;
Ishp = 0.3;
Vshp = 0.39;
Voff = 0.5;
phih = -3*pi/180;

idc1 = 3/2 * Isp * Vs1p * cosphi;
idc2 = 3 * Ishp * Voff;
idc3 = 3/2 * Ishp * Vshp;

%% DC link current
idc_FFTDATA = power_fftscope(idc);
idc_FFTDATA.startTime = 0.3;
idc_FFTDATA.cycles = 4; 
idc_FFTDATA.fundamental = 50; 
idc_FFTDATA.maxFrequency = 50000;
idc_FFTDATA.THDmaxFrequency = 50000;
idc_FFTDATA = power_fftscope(idc_FFTDATA);
num = numel(idc_FFTDATA.mag);
DCcomp = idc_FFTDATA.mag(1);
clc;
fprintf('\nDC component: %g\n',DCcomp);
for k = 2:num
    if (idc_FFTDATA.mag(k) >= DCcomp*0.01)
        fprintf('\nFreq: %g, Mag: %g, Phase: %g\n',idc_FFTDATA.freq(k),idc_FFTDATA.mag(k),idc_FFTDATA.phase(k));
    end    
end

%% PWM Signals - A
SA_FFTDATA = power_fftscope(SA);
SA_FFTDATA.startTime = 0.3;
SA_FFTDATA.cycles = 4; 
SA_FFTDATA.fundamental = 50; 
SA_FFTDATA.maxFrequency = 50000;
SA_FFTDATA.THDmaxFrequency = 50000;
SA_FFTDATA = power_fftscope(SA_FFTDATA);
num = numel(SA_FFTDATA.mag);
DCcomp = SA_FFTDATA.mag(1);
Fundcomp = SA_FFTDATA.mag(SA_FFTDATA.freq == 50);
clc;
fprintf('\nDC component: %g\n',DCcomp);
fprintf('\nFundamental component: %g\n',Fundcomp);
for k = 2:num
    if (SA_FFTDATA.mag(k) >= DCcomp*0.1 || SA_FFTDATA.mag(k) >= Fundcomp*0.1)
        fprintf('\nFreq: %g, Mag: %g, Phase: %g\n',SA_FFTDATA.freq(k),SA_FFTDATA.mag(k),SA_FFTDATA.phase(k));
    end    
end

%% PWM Signals - B
SB_FFTDATA = power_fftscope(SB);
SB_FFTDATA.startTime = 0.3;
SB_FFTDATA.cycles = 4; 
SB_FFTDATA.fundamental = 50; 
SB_FFTDATA.maxFrequency = 50000;
SB_FFTDATA.THDmaxFrequency = 50000;
SB_FFTDATA = power_fftscope(SB_FFTDATA);
num = numel(SB_FFTDATA.mag);
DCcomp = SB_FFTDATA.mag(1);
Fundcomp = SB_FFTDATA.mag(SB_FFTDATA.freq == 50);
clc;
fprintf('\nDC component: %g\n',DCcomp);
fprintf('\nFundamental component: %g\n',Fundcomp);
for k = 2:num
    if (SB_FFTDATA.mag(k) >= DCcomp*0.1 || SB_FFTDATA.mag(k) >= Fundcomp*0.1)
        fprintf('\nFreq: %g, Mag: %g, Phase: %g\n',SB_FFTDATA.freq(k),SB_FFTDATA.mag(k),SB_FFTDATA.phase(k));
    end    
end

%% PWM Signals - C
SC_FFTDATA = power_fftscope(SC);
SC_FFTDATA.startTime = 0.3;
SC_FFTDATA.cycles = 4; 
SC_FFTDATA.fundamental = 50; 
SC_FFTDATA.maxFrequency = 50000;
SC_FFTDATA.THDmaxFrequency = 50000;
SC_FFTDATA = power_fftscope(SC_FFTDATA);
num = numel(SC_FFTDATA.mag);
DCcomp = SC_FFTDATA.mag(1);
Fundcomp = SC_FFTDATA.mag(SC_FFTDATA.freq == 50);
clc;
fprintf('\nDC component: %g\n',DCcomp);
fprintf('\nFundamental component: %g\n',Fundcomp);
for k = 2:num
    if (SC_FFTDATA.mag(k) >= DCcomp*0.1 || SC_FFTDATA.mag(k) >= Fundcomp*0.1)
        fprintf('\nFreq: %g, Mag: %g, Phase: %g\n',SC_FFTDATA.freq(k),SC_FFTDATA.mag(k),SC_FFTDATA.phase(k));
    end    
end

%% Vll - AB
Vll_FFTDATA = power_fftscope(vll);
Vll_FFTDATA.startTime = 0.3;
Vll_FFTDATA.cycles = 4; 
Vll_FFTDATA.fundamental = 50; 
Vll_FFTDATA.maxFrequency = 50000;
Vll_FFTDATA.THDmaxFrequency = 50000;
Vll_FFTDATA = power_fftscope(Vll_FFTDATA);
num = numel(Vll_FFTDATA.mag);
DCcomp = Vll_FFTDATA.mag(1);
Fundcomp = Vll_FFTDATA.mag(Vll_FFTDATA.freq == 50);
clc;
fprintf('\nDC component: %g\n',DCcomp);
fprintf('\nFundamental component: %g\n',Fundcomp);
for k = 2:num
    if (Vll_FFTDATA.mag(k) >= Fundcomp*0.05)
        fprintf('\nFreq: %g, Mag: %g, Phase: %g\n',Vll_FFTDATA.freq(k),Vll_FFTDATA.mag(k),Vll_FFTDATA.phase(k));
    end    
end

%% is - A
isa_FFTDATA = power_fftscope(isa);
isa_FFTDATA.startTime = 0.3;
isa_FFTDATA.cycles = 4; 
isa_FFTDATA.fundamental = 50; 
isa_FFTDATA.maxFrequency = 50000;
isa_FFTDATA.THDmaxFrequency = 50000;
isa_FFTDATA = power_fftscope(isa_FFTDATA);
num = numel(isa_FFTDATA.mag);
DCcomp = isa_FFTDATA.mag(1);
Fundcomp = isa_FFTDATA.mag(isa_FFTDATA.freq == 50);
clc;
fprintf('\nDC component: %g\n',DCcomp);
fprintf('\nFundamental component: %g\n',Fundcomp);
for k = 2:num
    if (isa_FFTDATA.mag(k) >= Fundcomp*0.002)
        fprintf('\nFreq: %g, Mag: %g, Phase: %g\n',isa_FFTDATA.freq(k),isa_FFTDATA.mag(k),isa_FFTDATA.phase(k));
    end    
end

%% is - B
isb_FFTDATA = power_fftscope(isb);
isb_FFTDATA.startTime = 0.3;
isb_FFTDATA.cycles = 4; 
isb_FFTDATA.fundamental = 50; 
isb_FFTDATA.maxFrequency = 50000;
isb_FFTDATA.THDmaxFrequency = 50000;
isb_FFTDATA = power_fftscope(isb_FFTDATA);
num = numel(isb_FFTDATA.mag);
DCcomp = isb_FFTDATA.mag(1);
Fundcomp = isb_FFTDATA.mag(isb_FFTDATA.freq == 50);
clc;
fprintf('\nDC component: %g\n',DCcomp);
fprintf('\nFundamental component: %g\n',Fundcomp);
for k = 2:num
    if (isb_FFTDATA.mag(k) >= Fundcomp*0.002)
        fprintf('\nFreq: %g, Mag: %g, Phase: %g\n',isb_FFTDATA.freq(k),isb_FFTDATA.mag(k),isb_FFTDATA.phase(k));
    end    
end

%% is - C
isc_FFTDATA = power_fftscope(isc);
isc_FFTDATA.startTime = 0.3;
isc_FFTDATA.cycles = 4; 
isc_FFTDATA.fundamental = 50; 
isc_FFTDATA.maxFrequency = 50000;
isc_FFTDATA.THDmaxFrequency = 50000;
isc_FFTDATA = power_fftscope(isc_FFTDATA);
num = numel(isc_FFTDATA.mag);
DCcomp = isc_FFTDATA.mag(1);
Fundcomp = isc_FFTDATA.mag(isc_FFTDATA.freq == 50);
clc;
fprintf('\nDC component: %g\n',DCcomp);
fprintf('\nFundamental component: %g\n',Fundcomp);
for k = 2:num
    if (isc_FFTDATA.mag(k) >= Fundcomp*0.002)
        fprintf('\nFreq: %g, Mag: %g, Phase: %g\n',isc_FFTDATA.freq(k),isc_FFTDATA.mag(k),isc_FFTDATA.phase(k));
    end    
end

%%
figure;
hold all;
plot(FFTDATA.freq*1e-3,FFTDATA.mag,'r-','Linewidth',1);
plot(FFTDATA1.freq*1e-3,FFTDATA1.mag*10,'b-','Linewidth',1);
set(gca,'FontSize',14);
xlabel('Frequency (kHz)','FontSize',14,'FontWeight','Bold')
ylabel('Magnitude (Amps)','FontSize',14,'FontWeight','Bold')
xlim([-1 51]);
ylim([0 10]);
legend({'Idc','Isa'},'Location','best');

%FFTDATA1 = struct2cell(FFTDATA);
%FFTDATA2 = cell2dataset(FFTDATA1);
%FFTDATA3 = struct2dataset(FFTDATA);
