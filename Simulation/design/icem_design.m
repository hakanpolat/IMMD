%% IMMD Design (2s-2p)

% Permeability of air
mu0 = 4*pi*1e-7; % H/m
% Copper resistivity (20 C)
roc = 1.7e-8; % Ohm*m
% Copper permeability
muc = 1.2e-6; % H/m
% Density of copper
dencu = 8.96; % g/cm^3
% Density of magnet (NeFeB)
denm = 7.4; % g/cm^3
% Density of iron
denc = 7.65; % g/cm^3
% Density of aluminum
dena = 2.70; % g/cm^3
% Temperature coefficient of copper
Tccu = 4.041e-3; % C-1

% Number of phases in each module
m = 3;
% Average DC link voltage
Vdc = 540; % V
% Total mechanical output power
Pout = 8e3; % W
% Electrical loading target
Armst = 35e3; % A/m
% Magnetic loading target
Bavgt = 0.6; % T
% Electric current density target
Jrmst = 4; % A/mm^2
% Magnet remamnent flux density
Br = 1.25; % T !!!! Select this
% Magnet relative permeability
mur = 1.1; % !!!! Select this
% Motor rated speed
Nr = 600; % rpm
% Ambient temperature
Tamb = 40; % C
% Stator stacking factor
kst = 0.96;
% Number of stator slot layers
layer = 2;

% DC link maximum voltage ripple
Vdcrip = 1; % percent, peak-to-peak
% Maximum fill factor
kcumax = 0.6;
% Maximum stator tooth flux density
Btsmax = 1.8; % T
% Maximum stator yoke flux density
Bysmax = 1.4; % T
% Maximum rotor yoke flux density
Byrmax = 1.4; % T
% Maximum total harmonic distortion (THD)
THDmax = 1; % percent
% Minimum motor drive efficiency
effdrmin = 0.98;
% Minimum motor efficiency
effmmin = 0.96;
% Minimum power factor
pfmin = 0.96;
% Maximum cogging torque
Tcogmax = 1; % percent
% Maximum torque ripple
Tripmax = 1; % percent
% Maximum device junction temperature
Tjmax = 150; % C
% Maximum winding temperature
Twmax = 200; % C
% Maximum magnet temperature
Tmmax = 120; % C
% Maximum capacitor temperature
Tcamax = 70; % C
% Maximum tip speed
vtipmax = 10; % m/s

fsw = 50e3; % Hz
% Total number of modules ([2,10])
n = 4;
% Number of series connected modules ([2,5])
ns = 2;
% Modulation index ([0.55,0.95])
ma = 0.9;
% Aspect ratio ([0.2-2])
ar = 0.5;
% Magnet embrace ([0.45-0.95])
em = 0.7;
% Number of slots per module per phase ([2,10])
ws = 2;
% Magnet thickness ([1,10] mm)
lm = 4; % mm

%%
% Drive parameters
Vdcm = Vdc/ns; % Volts dc
Poutm = Pout/n; % Watts
np = n/ns;
Vline = 0.612*ma*Vdcm; % Volts line to line
Iline = Poutm/((effmmin*pfmin)*(Vline*sqrt(3))); % Arms
Vphm = Vline/sqrt(3); % Volts
Ephm = pfmin*Vphm; % Volts
Ip = Iline*sqrt(2);

%%
% E-mode GaN
Igan = 30; % A
Eon = 47.5e-6; % J, 400 V, 15A
Eoff = 7.5e-6; % J, 400 V, 15A
Eoss = 7e-6; % J, 400 V
Rdson = 0.1255 + Ip*6.67e-4;
Eond = Eon*(Vdcm*Ip)/(400*(Igan/2));
Eoffd = Eoff*(Vdcm*Ip)/(400*(Igan/2));
Eossd = Eoss*Vdcm/400;
% Transistor forward conduction
Pcf = Rdson*Ip^2*(1/8+ma*pfmin/(3*pi));
% Transistor reverse conduction
Pcr = Rdson*Ip^2*(1/8-ma*pfmin/(3*pi));
% Transistor switching
Pst = (Eond+Eoffd)*fsw/pi;
% Transistor Coss
Pso = Eossd*fsw/pi;
% Total loss (transistor)
Plosst = Pcf+Pcr+Pst+Pso;
% Total loss (module)
Plossm = Plosst*2*m;
% Total loss (drive)
Plossdr = Plossm*n;
Poutdr = Pout/effmmin;
effdr = Poutdr/(Poutdr+Plossdr);

%%
% Cascode GaN
Icp = Ip; % A
Iep = Ip; % A
Vceo = 0; % V
Ro = 105*1e-3; % Ohms
Vdo = 0.6; % V
Rd = (8-6)/(80-60); % Ohms
Vnom = 400; % V
Inom = 22; % A
Eon = 1/6*(Inom*Vnom*(36+7.6)*1e-9); % J
Eoff = 1/6*(Inom*Vnom*(40+8.6)*1e-9); % J
Err = 1/6*(Inom*Vnom*(40)*1e-9); % J
Eoss = 9e-6; % J

% Loss calculation
Psc = Vceo*Icp/(2*pi) + Ro*Icp^2/8 + ma*pf*Vceo*Icp/8 + ma*pf*Ro*Icp^2/(3*pi); % W
Pdc = Vdo*Iep/(2*pi) + Rd*Iep^2/8 - ma*pf*Vdo*Iep/8 - ma*pf*Rd*Iep^2/(3*pi); % W
Pss = (Eon+Eoff)*fsw*Vdcm*Icp/(pi*Vnom*Inom); % W
Pds = Err*fsw*Vdcm*Icp/(pi*Vnom*Inom) % W

Ploss1 = Psc+Pdc+Pss+Pds; % W
Ploss = Ploss1*6; % W
efficiency = 100*Pdrout/(Ploss+Pdrout); % percent
