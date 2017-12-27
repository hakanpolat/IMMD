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
% global n
% global ns
% global fsw
% global ma
% global lm
% global em
% global ar
% global w
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
global Vdcrip

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
THDmax = 5; % percent
% Minimum motor drive efficiency
effdrmin = 0.98;
% Minimum motor efficiency
effmmin = 0.94;
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

% GS66502B 	650 V 	7.5 A 	200 m? 	5.0 x 6.6 x 0.51 	Bottom-side
% GS66504B 	650 V 	15 A 	100 m? 	5.0 x 6.6 x 0.51 	Bottom-side
% GS66506T 	650 V 	22.5 A 	67 m? 	5.6 x 4.5 x 0.54 	Top-side
% GS66508B 	650 V 	30 A 	50 m? 	7.0 x 8.4 x 0.51 	Bottom-side
% GS66508P 	650 V 	30 A 	50 m? 	10.0 x 8.7 x 0.51 	Bottom-side
% GS66508T 	650 V 	30 A 	50 m? 	6.9 x 4.5 x 0.54 	Top-side
% GS66516T 	650 V 	60 A 	25 m? 	9.0 x 7.6 x 0.54 	Top-side
% GS66516B 	650 V 	60 A 	25 m? 	11.0 x 9.0 x 0.51 	Bottom-side

Sreq = Pout/(effmmin*pfmin*n);
Vmll = 0.612*Vdc*ma/(ns);
Ireq = sqrt(2)*1.5*Sreq/(Vmll*sqrt(3));
if Ireq < 7
    Vgan = 650;
    Igan = 7.5; % A
    Rdson = 516e-3; % Ohms, 150 C, 2.25 A
    Eon = 6.9e-6; %NOT FOUND % J, 400 V
    Eoff = 1.9e-6; %NOT FOUND % J, 400 V
    Eoss = 1.9e-6; % J, 400 V
    Rthjc = 2; % C/W
    Cgan = 0.075;
elseif Ireq>=7 && Ireq < 14
    Vgan = 650;
    Igan = 15; % A
    Rdson = 258e-3; % Ohms, 150 C, 4.5 A
    Eon = 18.5e-6; %NOT FOUND % J, 400 V
    Eoff = 3.7e-6; %NOT FOUND % J, 400 V
    Eoss = 3.3e-6; % J, 400 V
    Rthjc = 1; % C/W
    Cgan = 0.15;
elseif Ireq>=14 && Ireq < 21
    Vgan = 650;
    Igan = 22.5; % A
    Rdson = 175e-3; % Ohms, 150 C, 6.7 A
    Eon = 20.7e-6; %NOT FOUND % J, 400 V
    Eoff = 5.4e-6; %NOT FOUND % J, 400 V
    Eoss = 5.3e-6; % J, 400 V
    Rthjc = 0.7; % C/W
    Cgan = 0.225;
elseif Ireq>=21 && Ireq < 28
    Vgan = 650;
    Igan = 30; % A
    Rdson = 129e-3; % Ohms, 150 C, 2.25 A
    Eon = 47.5e-6; % J, 400 V, 15A
    Eoff = 7.5e-6; % J, 400 V, 15A
    Eoss = 7e-6; % J, 400 V
    Rthjc = 0.5; % C/W
    Cgan = 0.30;
elseif Ireq>=28 && Ireq < 56
    Vgan = 650;
    Igan = 60; % A
    Rdson = 65e-3; % Ohms, 150 C, 2.25 A
    Eon = 134.1e-6; % J, 400 V, 20A
    Eoff = 14.7e-6; % J, 400 V, 20A
    Eoss = 14.1e-6; % J, 400 V
    Rthjc = 0.3; % C/W
    Cgan = 0.60;
end

%% Electrical model-2: Inverter model
Vdcm = Vdc/ns; % Volts dc
Poutm = Pout/n; % Watts
np = n/ns;
Vline = 0.612*ma*Vdcm; % Volts line to line
Iline = Poutm/((effmmin*pfmin)*(Vline*sqrt(3))); % Arms
Vphm = Vline/sqrt(3); % Volts
Ephm = pfmin*Vphm; % Volts

%% Electrical model-2: Electrical loss model
Ip = Iline*sqrt(2);
Rdson = Rdson*1.05; % Add temperature and current dependence !!!
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

%% Electrical model-3: DC link model
Idcrms1 = Iline*sqrt( 2*ma*(sqrt(3)/(4*pi) +...
    pfmin^2*(sqrt(3)/pi-9*ma/16)) ); % Amps
% Use the interleaving effect using number of parallel modules
intc = 1;
Idcrms = Idcrms1*np*intc; % Amps
Idcavg = Pout/(effmmin*effdrmin*Vdc); % Amps

Cdcreq1 = (ma*Iline/(16*fsw*(Vdcrip*Vdc/100)))*...
    sqrt( (6 - (96*sqrt(3)*ma)/(5*pi) +...
    (9*ma^2/2) )*pf^2 + (8*sqrt(3)*ma)/(5*pi) ); % Farads
Cdcreq = Cdcreq1*intc; % Amps
% Cdcreq2 = 0.7*(Iline*sqrt(2)-Idcavg/2)*ma/(fsw*Vdcrip*Vdc/100)

% !!! review the capacitance requirement and its relationship with interleaving

%% Electrical model-4: DC link capacitor selection
% Inputs are Cdc, Icrms, Vdcm
% Use Ta, n and ns
% Tcapmax is constraint
% Outputs are hcap, Ccap
% !!!! There should be a database
% Internal parameters are ESR and Rthcap


%% Geometrical Model-1: Magnetic stress tensor and machine dimensions
% Rated torque
Tm = Pout/(Nr*2*pi/60); % Nm
% Sheer stress
mst = Armst*Bavgt; % Pa
% Air gap volume
Vr = Tm/(2*mst); % m^3
Dis2L = 4*Vr/pi; % m^3
% Stator inner diameter
Dis = (Dis2L/ar)^(1/3); % m
Dis = ceil(Dis*100)/100; % m
% Axial length
La = ar*Dis; % m
% !!!! Rotor inner diameter (what will we do abut this???) 
Dir = Dis/2;

%% Electromagnetic model-1: slot-pole
Qs = w*n*m;
p = Qs-2; % This can be different. Check this out. p can be an 
% optimization parameter
% Use tables for winding factor
if Qs == 6
    kwf = 0.866;
elseif Qs == 12
    kwf = 0.933;
elseif Qs == 18
    kwf = 0.945;
elseif Qs == 24
    kwf = 0.949;
elseif Qs == 30
    kwf = 0.951;
elseif Qs == 36
    kwf = 0.953;
elseif Qs == 42
    kwf = 0.953;
elseif Qs == 48
    kwf = 0.954;
elseif Qs == 54
    kwf = 0.954;
elseif Qs == 60
    kwf = 0.954;
elseif Qs == 66
    kwf = 0.954;
end

% !!! What can we do about harmonic winding factors???

Taos = pi*Dis/Qs;
Taop = pi*Dis/p;

%% Electromagnetic model-2: Magnetic equivalent circuit
% For air gap flux density
cphi = 1; % flux concentration factor
Kl = 1; % leakage factor
Kr = 1; % reluctance factor
PC = (cphi*Kl*Br-Bavgt*pi/2)/(Kr*mur*Bavgt*pi/2);
%(Kr*mur)/(cphi*Kl*Br/(Bavgt*pi/2)-1); % permeance coefficient
lgmin = lm*PC; % mm
lg = ceil(lgmin*2)/2; % mm
PC = lg/lm;
Bgp = cphi*Kl*Br/(1+Kr*mur*PC);

hnum = 31;
Bgph = zeros(1,hnum);
for k = 1:hnum
    if rem(k,2)~=0
    Bgph(k) = (4*Bgp)/(k*pi)*cos(k*(pi/2)*(1-em));
    end
end

%% Electromagnetic model-3: Magnetic equivalent circuit
% For tooth and yoke (stator)
hbc = Bgp*Taop*em/(2*Bysmax); % m
hbc = ceil(hbc*1e3*2)/2; % mm
alfat = Bgp/Btsmax;
bt = ceil(1e3*Taos*alfat); % mm
bs1 = Taos*1e3-bt; % mm

%% Electromagnetic model-4: Flux per pole, Coil induced voltage
% In this model, all harmonics are considered
fs = Nr*p/120; % Hz
Apole = Taop*La; % m^2
Fluxpph = zeros(1,hnum);
for k = 1:hnum
    Fluxpph = (2/pi)*(Bgph/k)*Apole; % Weber
    Ecoilh = 4.44*k*fs*Fluxpph*kwf; % Volts
end
% !!!! In this model, kwh for each harmonic is needed
Ecoil = Ecoilh(1);

%% Electromagnetic model-5: Winding
Nphm = Ephm/Ecoil;
turnc = ceil(2*Nphm/(layer*w));
Iphm = Pout/(m*n*Ephm); % Arms
Arms = 1e-3*layer*turnc*Qs*Iphm/(pi*Dis); % kA/m


%% Electromagnetic model-6: Winding selection
Awdgmin = Iphm/Jrmst; % mm^2
Dwdgmin = sqrt(4*Awdgmin/pi); % mm
[Dwdg,awgno] = awg_wire_table(Dwdgmin); % mm
Awdg = (Dwdg/2)^2*pi; % mm^2
Jrms = Iphm/Awdg; % A/mm^2

%% Geometric model 1: Stator slot model
Acu = layer*turnc*Awdg; % mm^2
Aslotmin = Acu/kcumax; % mm^2
hs = -bs1*Qs/(2*pi) + sqrt((bs1*Qs/pi)^2 + 4*Qs*Aslotmin/pi)/2; % mm
hs = ceil(hs2); % mm
bs2 = bs1+2*pi*hs/Qs; % mm
Aslot = (bs1+bs2)*hs/2; % mm
kcu = Acu/Aslot;

Dss = Dis*1e3+2*hs; % mm
Taoss = pi*Dss/Qs; % mm
Dos = Dss+2*hbc; % mm


%% Winding model (copper loss)
% input is dimensions
% cable should be selected
% Nphm, w etc.
% Output is Rcu, Pcu


%% Winding model (inductances)
% Both leakage and armature reaction will be obtained
% Slot dimensions....
% pf will be obtained


%% Electromagnetic model (core loss)
% material should be selected???
% material datasheet
% B values at yoke etc.
% Harmonics?? (use EM harmonic model)
% Output is Pc, Rc

%% Harmonic equivalent circuit
% Use electrical model, Llk, La etc
% Obtain THD

%% Cogging torque model
% Inputs: Qs, p, em, lm, lg
% Tcog


%% Heat sink model (thermal)
% Plossdr is input
% PCB dimensions are input
% Use Ta, Tjmax, Rthdevice
% Dind Rthpcb
% Find Rthsa
% Then, heat sink dimensions will be found

%% Geometric model
% Volm = pi*(Dos/2)^2*La; % m^3
% Voldr = pi*(Dos/2)^2*(0.01+hcap); % m^3
% Volhs = pi*(Dos/2)^2*Lhs; % m^3
% Volsys = Voldr+Volhs+Volm; % m^3
% PD = (Pout*1e-3)/(Volsys*1e3); % kW/lt


%%
% Select the winding diameter somewhere


