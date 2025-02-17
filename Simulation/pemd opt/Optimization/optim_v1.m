%% Multi-physics Optimization of IMMD
%%
% In this file, the system model is developed for the purpose of
% multi-physics optimization of the IMMD system for PEMD paper.
%%
% M. U�ur
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
global dena
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
% Density of aluminum
dena = 2.70; % g/cm^3
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
Tjmax = 150; % C
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
%device_parameters = device_selection(Ireq)
[Igan,Vgan,Rdson,Eon,Eoff,Eoss,Rthjc,Cgan]...
    = device_selection(Ireq);

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
intc = 1;
Idcrms = Idcrms1*np*intc; % Amps
Idcavg = Pout/(effmmin*effdrmin*Vdc); % Amps

% It has been observed that, series connection interleaving has no effect
% on the current ripple RMS of the capacitors.

% When no interleaving is used, the rms current requirement can be directly
% multiplied by the number of parallel connected modules

Cdcreq1 = ns^2*(ma*Iline/(16*fsw*Vdcrip))*...
    sqrt( (6 - (96*sqrt(3)*ma)/(5*pi) +...
    (9*ma^2/2) )*pfmin^2 + (8*sqrt(3)*ma)/(5*pi) ); % Farads
Cdcreq = Cdcreq1*intc; % Amps

% In order to get the same voltage ripple (percent) on the DC bus of each
% module, Creq*ns capacitance should be connected on each module DC bus.
% It has been observed that, although interleaving has positive effect on
% the ripple of overall DC bus, it has no effect on the percent voltage
% ripple of each module separately. Therefore, the capacitance requirement
% depends on the square of number of series modules (for the total 
% capacitance requirement)

% When no interleaving is used, the ripple voltage (or capacitance)
% can be directly multiplied by the number of parallel connected modules


%% Electrical model-4: DC link capacitor selection

% Capacitor data:
% 1. Cseri, 2. Capacitance, 3. Wcap, 4. Hcap, 5. Lcap,
% 6. Current, 7. ESR, 8. Gcap, 9. Cost
[Cseri,Cap,Wcap,Hcap,Lcap,Icap,ESR,Gcap,Ccap] = ...
    capacitor_selection(Cdcreq*1e6,Idcrms,Vdcm);

TotalCcap = Cseri*ns*Ccap; % dollars
hcap = Hcap; % mm
Volcap = Hcap*Wcap*Lcap*Cseri*ns*1e-3; % cm^3
EqvESR = ESR*Cseri*ns*1e-3; % Ohms
Plosscap = Idcrms^2*EqvESR; % W

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

%% Electromagnetic model-1: slot-pole
Qs = w*n*m;
%p = Qs-2; % This can be different.
% Use tables for winding factor
if rem(Qs,12) == 0
    p = Qs/1.2;
    kwf = 0.933;
end

if Qs == 6
    p = 4;
    kwf = 0.866;
elseif Qs == 18
    p = 16;
    kwf = 0.945;
elseif Qs == 30
    p = 26;
    kwf = 0.936;
elseif Qs == 42
    p = 38;
    kwf = 0.945;
elseif Qs == 54
    p = 46;
    kwf = 0.930;
elseif Qs == 90
    p = 76;
    kwf = 0.933;
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
% em????
Fluxpph = zeros(1,hnum);
for k = 1:hnum
    Fluxpph = (2/pi)*(Bgph/k)*Apole; % Weber
    Ecoilh = 4.44*k*fs*Fluxpph*kwf; % Volts
end
% !!!! In this model, kwh for each harmonic is needed
Ecoil = Ecoilh(1);

%% Electromagnetic model-5: Winding
Nphmrev = Ephm/Ecoil;
turnc = ceil(2*Nphmrev/(layer*w));
Nphm = turnc*layer*w/2;
Ephm = Ecoil*Nphm; % Volts
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
hs2 = -bs1*Qs/(2*pi) + sqrt((bs1*Qs/pi)^2 + 4*Qs*Aslotmin/pi)/2; % mm
hs2 = ceil(hs2); % mm
bs2 = bs1+2*pi*hs2/Qs; % mm
Aslot = (bs1+bs2)*hs2/2; % mm
kcu = Acu/Aslot;
hs0 = 1.5; % mm
hs1 = 1.5; % mm
hs = hs0+hs1+hs2;
Dss = Dis*1e3+2*hs; % mm
Taoss = pi*Dss/Qs; % mm
Dos = Dss+2*hbc; % mm

%% Electromagnetic model-7: Inductances
% Armature reaction
%Lgap1 = 16*mu0*Nphm^2*Dis*La/(pi*lg*1e-3*p^3) % Henries
Agap = em*pi*Dis*La/p; % m^2
Lgap = w*turnc^2*mu0*mur*Agap/((mur*lg+lm)*1e-3); % Henries

% Slot leakage
bs0 = bs1/2; % mm
bsavg = (bs1+bs2)/2; % mm
Lslk1 = Qs*(2*turnc)^2*[mu0*hs2*La/(3*bsavg)]; % Henries
Lslk2 = Qs*(2*turnc)^2*[mu0*La*hs1/((bs0+bsavg)/2)]; % Henries
Lslk3 = Qs*(2*turnc)^2*[mu0*hs0*La/bs0]; % Henries
Lslk = Lslk1+Lslk2+Lslk3; % Henries

% End turn leakage
Lendt = w*mu0*Taos*turnc^2/4*log(Taos*sqrt(pi)/sqrt(2*Aslot*1e-6)); % Henries

% Phase inductance
Lph = Lgap + Lslk + Lendt; % Henries


%% From maxwell
Xa = 0.98;
Xlk = 1.93;
multip = 2*pi*fs;
Lamx = Xa/multip*1000; % mH

Agap = em*pi*Dis*La/p;
Lgap = 1e3*w*turnc^2*mu0*mur*Agap/((mur*lg+lm)*1e-3); % mH
Lslk1 = 1e3*w*(2*turnc)^2*[mu0*hs2*La/(3*bsavg)]; % mH
Lslk2 = 1e3*w*(2*turnc)^2*[mu0*La*hs1/((bs0+bsavg)/2)]; % mH
Lslk3 = 1e3*w*(2*turnc)^2*[mu0*hs0*La/bs0]; % mH
%Lslk = Lslk1+Lslk2+Lslk3 % mH

%Llkmx = Xlk/multip*1000 % mH

%Lgap/Lamx;
%Lslk/Llkmx

%%
%Lgap = 1e3*turnc^2*pi*La*Dis*mu0*mur/(p*(mur*lg+lm)*1e-3) % mH


%% Electromagnetic model-8: Resistances
% Mean length turn
MLT = 2*(La+pi*Taos/4+hs*1e-3/2); % m
Lengthph = MLT*Nphm; % m

% Phase resistance
Rphm20 = roc*Lengthph/(Awdg*1e-6); % 20 0C
Rphm = Rphm20*(1+Tccu*(75-20)); % 75 0C

% Effect of skin depth
% !!! add later


%% Winding model (copper loss)
Pcuphm = Iphm^2*Rphm;
Pcum = Pcuphm*m;
Pcu = Pcum*n;

%% Electromagnetic model (core loss)
% material should be selected???
% material datasheet
% B values at yoke etc.
% Harmonics?? (use EM harmonic model)
% Output is Pc, Rc

%% Harmonic equivalent circuit
Xsh = 2*pi*fs*Lph;
Vdrop = Xsh*Iphm;
phi = 180/pi*atan(Vdrop/Ephm);
pf = cos(phi*pi/180);

Iphmh = zeros(1,31);
Ephmh = Nphm*Ecoilh';
Iharm = 0;
for k = 3:31
    Xphmh = 2*pi*fs*k*Lph;
    Iphmh(k) = Ephmh(k)/Xphmh;
    Iharm = Iharm+Iphmh(k)^2;
end
Iharm = sqrt(Iharm);
Iphm;
THD = 100*Iharm/Iphm;


%% Cogging torque model
% Inputs: Qs, p, em, lm, lg
% Tcog


%% Heat sink model (thermal)

% Thermal grease: http://tr.farnell.com/c/cooling-thermal-management/thermal-interface-materials/thermal-grease
% All GaNs are assumed as bottom cooled

% Inputs
Plosst; % Loss of each GaN
Rthjc; % Thermal resistance (junction-case) of each transistor
Tamb; % Ambient temperature
Tjmax; % Maximum junction temperature
Tmargin = 10; % Junction temperature margin
RthjT = 8.5; % C/W, Junction-to-top thermal resistance

% PCB dimensions
Nvia = 120; % Number of thermal vias
Tpcb = 1.6; % mm, PCB thickness (FR4)
Tcop = 70; % micron, Copper layer thickness
Dvia = 0.3; % mm, Diameter of thermal via
Pvia = 0.64; % mm, Pitch of thermal vias
Layerp = 4; % PCB number of layers
PadW = 10; % mm
PadL = 25; % mm

% PCB thermal resistance
Rthpcb = 4.8; % C/W, Thermal resistance of PCB

% Thermal interface material (TIM)
Ctim = 3; % W/Km, Thermal conductivity
Ltim = 0.254; % mm, Thickness
Atim = 56; % mm^2, Surface area

% TIM thermal resistance
Rthtim = Ltim*1e-3/(Ctim*Atim*1e-6); % Thermal resistance

Rthtot = (Rthjc + Rthpcb + Rthtim)/(2*m); % C/W
Rthreq = (Tjmax-Tmargin-Tamb)/Plossm - Rthtot;


%% Thermal modeling of heatsink

% https://www.electronics-cooling.com/2003/02/estimating-parallel-plate-fin-heat-sink-thermal-resistance/#
% https://www.engineeringtoolbox.com/dry-air-properties-d_973.html
% https://www.myheatsinks.com/calculate/thermal-resistance-plate-fin/

% Main dimensions (square heat sink is assumed)
Whs = 50e-3; % m, width
Lhs = 50e-3; % m, length
Hfin = 37.5e-3; % m, height
Hbase = 10e-3; % m, base plate height
Nfin = 25; % number of fins
%tfin = Lhs/(2*Nfin); % m, fin width
tfin = 0.4e-3; % m, fin width
vel = 2.5; % m/s, velocity of air flow

% Heat sink height
Hhs = Hfin+Hbase; % m
% The space width between fins
bfins = (Whs-Nfin*tfin)/(Nfin-1); % m
% Base surface area
Abase = (Nfin-1)*bfins*Lhs; % m^2
% Fin surface area
Afin = 2*Hfin*Lhs; % m^2

% The Prandtl number:
kair = 0.0290; % W/Km, thermal conductivity of air
muair = 2e-5; % kg/(ms), dynamic viscosity of air
cpair = 1008; % J/(kgK), specific heat of air
Pr = muair*cpair/kair;
% Pr = 0.708; % @70 C
% https://www.engineeringtoolbox.com/dry-air-properties-d_973.html

% Reynolds number
roair = 1.009; % kg/m^3, density of air
Re = roair*vel*bfins^2/(muair*Lhs);

% Nusselt number
Nub = ( ( (Re*Pr/2)^(-3) ) +...
    (0.664*sqrt(Re)*Pr^0.33*sqrt(1+3.65/sqrt(Re)))^(-3) )...
    ^(-0.33);

% Heat transfer coefficient with convection
kfluid = 0.0290; % W/Km, thermal conductivity of fluid (air)
htcoef = Nub*kfluid/bfins;

% Fin efficiency
kfin = 205; % W/Km, thermal conductivity of fins (aluminum)
mhs = sqrt(2*htcoef/(kfin*tfin)); % ???
fineff = tanh(mhs*Hfin)/(mhs*Hfin);

% Thermal resistance of heat sink base (conduction)
kbase = 205; % W/Km, thermal conductivity of base (aluminum)
Rthbase = Hbase/(kbase*Whs*Lhs); % C/W

% Thermal resistance of heat sink (convection)
Rthhsc = (htcoef*(Abase+Nfin*fineff*Afin))^(-1); % C/W

% Total thermal resistance of heat sink
Rthhs = Rthbase+Rthhsc; % C/W

%% Geometric model: power density
% Volm = pi*(Dos/2)^2*La; % m^3
% Voldr = pi*(Dos/2)^2*(0.01+hcap); % m^3
% Volhs = pi*(Dos/2)^2*Hhs; % m^3
% Volsys = Voldr+Volhs+Volm; % m^3
% PD = (Pout*1e-3)/(Volsys*1e3); % kW/lt

%% Geometric model: material volume and mass
% Core material: M250-50A
% https://perso.uclouvain.be/ernest.matagne/ELEC2311/T2006/NOFP.pdf
tlam = 0.5; % mm
sploss15 = 2.5; % W/kg, @50Hz
sploss10 = 1.05; % W/kg, @50Hz
% Magnet: NdFeB40H, H grade (120 C)

% Rotor volume
% !!!! Rotor inner diameter (what will we do abut this???)
Dor = Dis*1e3-2*(lg+lm); % mm
Dir = Dor/2;
Vrotor = pi/4*(Dor^2-Dir^2)*La; % cm^3
mrotor = 1e-3*Vrotor*denc; % kg

% Stator volume
Vstator = pi/4*(Dos^2-Dss^2)*La + hs*bt*La*Qs; % cm^3
mstator = 1e-3*Vstator*denc; % kg

% Iron volume
Viron = Vrotor + Vstator; % cm^3
miron = mrotor + mstator; % kg

% Magnet volume
Vmagnet = pi*Dor*em*La*lm; % cm^3
mmagnet = 1e-3*Vmagnet*denm; % kg

% Copper volume
Vcopper = Lengthph*Awdg*n*m; % cm^3
mcopper = 1e-3*Vcopper*dencu; % kg

% Heat sink volume
Vhsink = pi/4*Dos^2*Hbase + Nfin*tfin*Dos*Hfin*1e3; % cm^3
mhsink = 1e-3*Vhsink*dena; % kg

