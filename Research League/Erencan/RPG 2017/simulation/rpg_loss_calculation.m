%% DEVICES
% There are two cases considered: 50kVA output power and 70 kVA output
% power. The required phase currents (rms) are calculated as follows:
Power1 = 50e3; % VA
Power2 = 70e3; % VA
Vline = 400; % V
Iphase1 = Power1/(Vline*sqrt(3)); % A
Iphase2 = Power2/(Vline*sqrt(3)); % A
% The DC bus voltage is selected as 750V
% The IGBT parameter selection is as follows:
% Case 1: 1200V, 150A
% Case 2: 1200V, 200A
% Two alternative devices are selected for each case:
% Case-1, device-1: Powerex CM150DY-24A
% Case-1, device-2: Infineon FF150R12RT4
% Case-2, device-1: Powerex CM200DY-24A
% Case-2, device-2: Infineon FF200R12KT4

%% DATASHEET PARAMETERS



