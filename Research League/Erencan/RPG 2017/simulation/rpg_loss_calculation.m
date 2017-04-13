%% DEVICES
% There are two cases considered: 50kVA output power and 70 kVA output
% power. The required phase currents (rms) are calculated as follows:
Power1 = 50e3; % VA
Power2 = 70e3; % VA
Vline = 400; % V
Iphase1 = Power1/(Vline*sqrt(3)); % A
Iphase2 = Power2/(Vline*sqrt(3)); % A
Vdc = 750; % V
% The DC bus voltage is selected as 750V
% The IGBT parameter selection is as follows:
% Case 1: 1200V, 150A
% Case 2: 1200V, 200A
% Two alternative devices are selected for each case:
% Case-1, device-1: Powerex CM150DY-24A
% Case-1, device-2: Infineon FF150R12RT4
% Case-2, device-1: Powerex CM200DY-24A
% Case-2, device-2: Infineon FF200R12KT4
%% SELECTION
ccase = 2;
device = 2;
%% DATASHEET PARAMETERS
if ccase == 1 && device == 1
    Vce_sat = 2.3; % V, @102 A peak
    Eon = 6e-3; % J, @600V
    Eon = Eon*Vdc/600; % J, @750V
    Eoff = 10.4e-3; % J, @600V
    Eoff = Eoff*Vdc/600; % J, @750V
    Err = 8e-3; % J, @600V
    Err = Err*Vdc/600; % J, @750V
    Vec = 2.05; % V
    trr = 150e-9; % s, @600V
    trr = trr*Vdc/600; % s, @750V
elseif ccase == 1 && device == 2
    Vce_sat = 1.7; % V, @102 A peak
    Eon = 9e-3; % J, @600V
    Eon = Eon*Vdc/600; % J, @750V
    Eoff = 9e-3; % J, @600V
    Eoff = Eoff*Vdc/600; % J, @750V
    Err = 8.5e-3; % J, @600V
    Err = Err*Vdc/600; % J, @750V
    Vec = 1.42; % V
elseif ccase == 2 && device == 1
    Vce_sat = 2.15; % V, @102 A peak
    Eon = 5e-3; % J, @600V
    Eon = Eon*Vdc/600; % J, @750V
    Eoff = 10.6e-3; % J, @600V
    Eoff = Eoff*Vdc/600; % J, @750V
    Err = 10.2e-3; % J, @600V
    Err = Err*Vdc/600; % J, @750V
    Vec = 2.2; % V
    trr = 150e-9; % s, @600V
    trr = trr*Vdc/600; % s, @750V
elseif ccase == 2 && device == 2
    Vce_sat = 1.73; % V, @102 A peak
    Eon = 11e-3; % J, @600V
    Eon = Eon*Vdc/600; % J, @750V
    Eoff = 15e-3; % J, @600V
    Eoff = Eoff*Vdc/600; % J, @750V
    Err = 14e-3; % J, @600V
    Err = Err*Vdc/600; % J, @750V
    Vec = 1.45; % V
end
%% OPERATIONAL PARAMETERS
D = Vline/(0.612*Vdc); % modulation depth
fsw = 5e3; % Hz, switching frequency
Vce_p = Vdc; % V, peak diode voltage
if ccase == 1
    cos_phi = 1; % power factor
    Icp = Iphase1*sqrt(2); % A, peak current
    Iep = Iphase1*sqrt(2); % A, peak current
    Sout = Power1; % VA
    Pout = Sout*cos_phi; % W
    Irr = Iep; % A, peak reverse recovery current
elseif ccase == 2
    cos_phi = 0.714; % power factor
    Icp = Iphase2*sqrt(2); % A, peak current
    Iep = Iphase2*sqrt(2); % A, peak current
    Sout = Power2; % VA
    Pout = Sout*cos_phi; % W
    Irr = Iep; % A, peak reverse recovery current
end
%% LOSS CALCULATION
Psc = Icp*Vce_sat*(1/8+D*cos_phi/(3*pi)) % W
Pdc = Iep*Vec*(1/8-D*cos_phi/(3*pi)) % W
Pss = (Eon+Eoff)*fsw*(1/pi) % W
%Pds = (1/8)*Irr*trr*Vce_p*fsw; % W
Pds = (Err)*fsw*(1/pi) % W
Ploss1 = Psc+Pdc+Pss+Pds; % W
Ploss = Ploss1*6 % W
efficiency = 100*Pout/(Ploss+Pout)% percent
% fprintf('Efficiency is %g %%\n',efficiency);
% fprintf('Power loss is %g W\n',Ploss);


