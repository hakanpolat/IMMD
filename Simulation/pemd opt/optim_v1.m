%% Multi-physics Optimization of IMMD
%%
% In this file, the system model is developed for the purpose of
% multi-physics optimization of the IMMD system for PEMD paper.
%%
% M. Uður
%
% 12.12.2017
%
% All rights reserved
%% Definitions
% The system is composed of the following parts:
%
% * Electrical (DC link + inverter)
% * Electromagnetic (windings + PM)
% * Geometry (motor + heatsink)
% * Thermal (drive + motor)
%% Parameters
% The following categories are proposed:
%
% * Constant parameters
% * Optimization parameters
% * Dependent parameters
% * Constraint parameters
% * Objective parameters
%

%% Global definitiona
global mu0
global roc
global muc
global dencu
global denm
global denc
global Tccu
global m
global Vdc
global Pout
global Armst
global Bavgt
global Jrmst
global Br
global mur
global Nr
global Tamb
global kst
global layer
global fsw
global ma
global lm
global em
global ar
global w
global kcumax
global Btsmax
global Bysmax
global Byrmax
global THDmax
global effdrmin
global effmmin
global pfmin
global Tcogmax
global Tripmax
global Tjmax
global Twmax
global Tmmax
global Tcamax
global vtipmax

%% Universal constants

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
% Temperature coefficient of copper
Tccu = 4.041e-3; % C-1

%% Constant parameters with definitions

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
Br = 1.2; % T
% Magnet relative permeability
mur = 1.1;
% Motor rated speed
Nr = 600; % rpm
% Ambient temperature
Tamb = 40; % C
% Stator stacking factor
kst = 0.96;
% Number of stator slot layers
layer = 2;

%% Optimization parameters with definitions

% Switching frequency ([10e3,200e3] Hz)
fsw = 40e3; % Hz
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
w = 2;
% Magnet thickness ([1,10] mm)
lm = 4; % mm

%% Constraint parameters

% Maximum fill factor
kcumax = 0.6;
% Maximum stator tooth flux density
Btsmax = 1.8; % T
% Maximum stator yoke flux density
Bysmax = 2.0; % T
% Maximum rotor yoke flux density
Byrmax = 1.4; % T
% Maximum total harmonic distortion (THD)
THDmax = 5; % percent
% Minimum motor drive efficiency
effdrmin = 98;% percent
% Minimum motor efficiency
effmmin = 94;% percent
% Minimum power factor
pfmin = 0.9;
% Maximum cogging torque
Tcogmax = 1; % percent
% Maximum torque ripple
Tripmax = 1; % percent
% Maximum device junction temperature
Tjmax = 140; % C
% Maximum winding temperature
Twmax = 200; % C
% Maximum magnet temperature
Tmmax = 120; % C
% Maximum capacitor temperature
Tcamax = 70; % C
% Maximum tip speed
vtipmax = 10; % m/s

%% Objective parameters

% System power density
PDmin = 1; % W/cm^3
% Magnet cost
Cmmax = 1; %
% Device cost
Cdmax = 1; %
% Capacitor cost
Ccmax = 1; %
% Copper cost
Ccumax = 1; %
% Iron cost
Cimax = 1; %

%% Electrical model-1: Device selection
device_parem = device_selection(n,ns);

%% Everything below is subject to change
% %%
% Q = 48;
% layer = 2;
% n = 4;
% p = 40;
% Pout = 8e3;
% Poutm = Pout/n;
% Nrated = 540;
% length = 0.15;
% Din = 0.15;
% Dout = 0.23;
% effmotor = 0.9;
% 
% w = Q/(n*m);
% ffund = Nrated*p/120;
% kw = 0.933;
% 
% Bgapa = 0.6;
% Bgap = Bgapa*pi/2;
% fluxpp = 2*Din*length*Bgap/p;
% 
% zQ = 22;
% Nph = zQ*w*layer/2;
% E = 4.44*Nph*ffund*fluxpp*kw;
% Vln = E*1.1;
% 
% Vdc = 540;
% Vdcm = Vdc/2;
% 
% Vllrms = Vln*sqrt(3);
% scale = sqrt(3)/(2*sqrt(2));
% ma = Vllrms/(scale*Vdcm);
% 
% Pdrout = Poutm/effmotor;
% pf = 0.9;
% Sdrout = Pdrout/pf;
% Iphase = Sdrout/(sqrt(3)*Vllrms);
% 
% 
% %%
% % Design ans Simulation with IGBT
% 
% Ts = 1e-6; % sec
% % Modulation index
% ma = 0.8;
% % Switching frequency
% fsw = 10e3; % Hz
% % DC link voltage
% Vdc = 400; % Volts
% % Load
% Ptotal = 8e3/0.9; % W
% Pout = Ptotal; % W
% pf = 0.9;
% Sout = Pout/pf; % VA
% fout = 50; % Hz
% wout = 2*pi*fout; % rad/sec
% Vll_rms = ma*Vdc*0.612; % Volts
% Iline = Sout/(Vll_rms*sqrt(3)); % Amps
% Zload = Vll_rms/(Iline*sqrt(3)); % Ohms
% Rload = Zload*pf; % Ohms
% Xload = sqrt(Zload^2-Rload^2); % Ohms
% Lload = Xload/wout; % Henries
% 
% Rin = 10;
% %Lin = 1e-3;
% Vin = Vdc + Rin*(Ptotal/Vdc);
% Cdc = 200e-6;
% 
% Iphase = Iline;
% Idct = Ptotal/Vdc;
% Idcc = (3/(2*sqrt(2)))*ma*Iphase*pf;
% Irmss = Iphase*sqrt(2*ma*(sqrt(3)/(4*pi) + pf^2*(sqrt(3)/pi-9*ma/16)));
% Irms_perc = 100*Irmss/Idcc;
% 
% fsw = 10e3; % Hz
% volt_ripple_perc = 1;
% volt_ripple = volt_ripple_perc*Vdc/100;
% Iapeak = Iphase*sqrt(2);
% Cdc = ma*(Iapeak - Idcc)/(volt_ripple*fsw*2);
% Cdcm = Cdc*1e6;
% 
% 
% %%
% % Capacitor selection
% M = 0.8;
% Iline = Iphase;
% cosphi = 0.9;
% module = 4;
% efficiency = 0.98;
% 
% Icrms = module/2*Iphase*sqrt(2*M*(sqrt(3)/(4*pi) +...
%     cosphi^2*(sqrt(3)/pi-9*M/16)));
% Idc = module/2*(3/(2*sqrt(2)))*M*Iline*cosphi/efficiency;
% Icrms_perc = 100*Icrms/Idc;
% 
% fsw = 40e3; % Hz
% Cdc = 40e-6; % F
% Iapeak = Iline*sqrt(2);
% volt_ripple = M*(Iapeak - Idc/2)/(Cdc*fsw*sqrt(2))
% volt_ripple_perc = volt_ripple/Vdc*100


