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

%clear all
clc

% Global definitiona
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

% Universal constants

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

% Constant parameters with definitions

% Number of phases in each module
m = 3;
% Average DC link voltage
Vdc = 270; % V
% Total mechanical output power
Pout = 10e3; % W
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
%Nr = 5000; % rpm
% Ambient temperature
Tamb = 40; % C
% Stator stacking factor
kst = 0.96;
% Number of stator slot layers
layer = 2;

% Constraint parameters

% DC link maximum voltage ripple
Vdcrip = 1; % percent, peak-to-peak
% Maximum fill factor
kcumax = 0.4;
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
effmmin = 0.96;
% Minimum power factor
pfmin = 0.95;
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

% Optimization parameters with definitions
% Switching frequency ([10e3,200e3] Hz)
fsw = 50e3; % Hz
% Total number of modules ([2,10])
n = 4;
% Number of series connected modules ([2,5])
ns = 1;
% Modulation index ([0.55,0.95])
ma = 0.9;
% Aspect ratio ([0.2-2])
ar = 0.5;
% Magnet embrace ([0.45-0.95])
em = 0.8;
% Number of slots per module per phase ([2,10])
w = 2;
% Magnet thickness ([1,10] mm)
lm = 5; % mm

% Objective parameters

% System power density
% Magnet cost
% Device cost
% Capacitor cost
% Copper cost
% Iron cost

%clear param;
%clear param1;
%clear param2;

%for indexa = 1:3
%indexa = 1;
%ns = 1+indexa;

%for indexa = 1:6
%ns = 2;
%n = ns*indexa;
%n = ns*indexa;

%for indexo = 1:3
%indexo = 2;
%n = ns*indexo;
%w = 2*indexa;

% The parameter interdependencies
for index = 1:50

%n = ns*index;
%fsw = index*10e3;
%ma = 0.4 + 0.012*(index) % for 50 index values
%ar = 0.2+(index-1)*0.045;
%w = 2*index;

%ar = 0.66; % change aspect ratio

Nr = index*100; % rpm

% ___________________________________________
% Electrical model-1: Device selection
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
[Igan,Vgan,Eon,Eoff,Eoss,Rthjc,Cgan]...
    = device_selection(Ireq);
TotalCgan = Cgan*6*n;
% ___________________________________________


% ___________________________________________
% Electrical model-2: Inverter model
Vdcm = Vdc/ns; % Volts dc
Poutm = Pout/n; % Watts
np = n/ns;
Vline = 0.612*ma*Vdcm; % Volts line to line
Iline = Poutm/((effmmin*pfmin)*(Vline*sqrt(3))); % Arms
Vphm = Vline/sqrt(3); % Volts
Ephm = pfmin*Vphm; % Volts
% ___________________________________________


% ___________________________________________
% Electrical model-3: Electrical loss model
Ip = Iline*sqrt(2);
% Rdson is % @150C and Ip
if Igan == 7.5
    if Ip < 4
        Rdson = 0.4933 + Ip*0.01;
    elseif Ip >= 4
        Rdson = 0.5352 + (Ip-4)*0.0419;
    end
elseif Igan == 15
    if Ip < 7.5
        Rdson = 0.2466 + Ip*2.5e-3;
    elseif Ip >= 7.5
        Rdson = 0.2654 + (Ip-7.5)*6.72e-3;
    end
elseif Igan == 30
    if Ip < 15
        Rdson = 0.1255 + Ip*6.67e-4;
    elseif Ip >= 15
        Rdson = 0.1355 + (Ip-15)*1.74e-3;
    end
elseif Igan == 60
    if Ip < 30
        Rdson = 60.676e-3 + Ip*0.15e-3;
    elseif Ip >= 30
        Rdson = 65.160e-3 + (Ip-30)*0.363e-3;
    end
end
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
% ___________________________________________


% ___________________________________________
% Electrical model-4: DC link model
Idcrms1 = Iline*sqrt( 2*ma*(sqrt(3)/(4*pi) +...
    pfmin^2*(sqrt(3)/pi-9*ma/16)) ); % Amps
%Idcavg = Pout/(effmmin*effdrmin*Vdc); % Amps
% It has been observed that, series connection interleaving has no effect
% on the current ripple RMS of the capacitors.
% When no interleaving is used, the rms current requirement can be directly
% multiplied by the number of parallel connected modules
Cdcreq1 = ns*(ma*Iline/(16*fsw*Vdcrip))*...
    sqrt( (6 - (96*sqrt(3)*ma)/(5*pi) +...
    (9*ma^2/2) )*pfmin^2 + (8*sqrt(3)*ma)/(5*pi) ); % Farads
% In order to get the same voltage ripple (percent) on the DC bus of each
% module, Creq*ns capacitance should be connected on each module DC bus.
% It has been observed that, although interleaving has positive effect on
% the ripple of overall DC bus, it has no effect on the percent voltage
% ripple of each module separately. Therefore, the capacitance requirement
% depends on the square of number of series modules (for the total
% capacitance requirement) ?????

% When no interleaving is used, the ripple voltage (or capacitance)
% can be directly multiplied by the number of parallel connected modules
[intc,intv] = interleaving_effect(n,ns);
Idcrms = Idcrms1*np*intc; % Amps
Cdcreq = Cdcreq1*np*intv; % Amps
% This result is the capacitance requirement of one series module.
% ___________________________________________


% ___________________________________________
% Electrical model-5: DC link capacitor selection

% Capacitor data:
% 1. Cseri, 2. Capacitance, 3. Wcap, 4. Hcap, 5. Lcap,
% 6. Current, 7. ESR, 8. Gcap, 9. Cost
[Cseri,Cpar,Cap,Wcap,Hcap,Lcap,Icap,ESR,Gcap,Ccap] = ...
    capacitor_selection(Cdcreq*1e6,Idcrms,Vdcm);

TotalCcap = Cpar*Cseri*ns*Ccap; % dollars
hcap = Hcap; % mm
Volcap = Hcap*Wcap*Lcap*Cseri*Cpar*ns*1e-3; % cm^3
EqvESR = ESR*Cseri*Cpar*ns*1e-3; % Ohms
Plosscap = Idcrms^2*EqvESR; % W
Capperseri = Cap*Cpar/Cseri;
% ___________________________________________


% ___________________________________________
% Spatial Model-1: Magnetic stress tensor and machine dimensions
% Rated torque
Tm = Pout/(Nr*2*pi/60); % Nm
% Sheer stress
mst = Armst*Bavgt; % Pa
% Air gap volume
Vr = Tm/(2*mst); % m^3
Dis2L = 4*Vr/pi; % m^3
% Stator inner diameter
Dis = (Dis2L/ar)^(1/3); % m
Dis = ceil(Dis*1000); % mm
% Axial length
La = ar*Dis; % mm
% ___________________________________________


% ___________________________________________
% Electromagnetic model-1: slot-pole
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
Taos = pi*Dis/Qs; % mm
Taop = pi*Dis/p; % mm
% ___________________________________________



% ___________________________________________
% Electromagnetic model-2: Magnetic equivalent circuit
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
% ___________________________________________



% ___________________________________________
% Electromagnetic model-3: Magnetic equivalent circuit
% For tooth and yoke (stator)
hbc = Bgp*Taop*1e-3*em/(2*Bysmax); % m
hbc = ceil(hbc*1e3*2)/2; % mm
alfat = Bgp/Btsmax;
bt = ceil(Taos*alfat); % mm
bs1 = Taos-bt; % mm
% ___________________________________________


% ___________________________________________
% Electromagnetic model-4: Flux per pole, Coil induced voltage
% In this model, all harmonics are considered
fs = Nr*p/120; % Hz
Apole = Taop*La; % mm^2
% em????
Fluxpph = zeros(1,hnum);
Ecoilh = zeros(1,hnum);
for k = 1:hnum
    Fluxpph(k) = (2/pi)*(Bgph(k)/k)*Apole*1e-6; % Weber
    Ecoilh(k) = 4.44*k*fs*Fluxpph(k)*kwf; % Volts
end
% !!!! In this model, kwh for each harmonic is needed
Ecoil = Ecoilh(1);
% ___________________________________________


% ___________________________________________
% Electromagnetic model-5: Winding
Nphmrev = Ephm/Ecoil;
turnc = ceil(2*Nphmrev/(layer*w));
Nphm = turnc*layer*w/2;
Ephm = Ecoil*Nphm; % Volts
Iphm = Pout/(m*n*Ephm); % Arms
Arms = 1e-3*layer*turnc*Qs*Iphm/(pi*Dis/1000); % kA/m
% ___________________________________________


% ___________________________________________
% Electromagnetic model-6: Winding selection
Awdgmin = Iphm/Jrmst; % mm^2
Dwdgmin = sqrt(4*Awdgmin/pi); % mm
[Dwdg,awgno] = awg_wire_table(Dwdgmin); % mm
Awdg = (Dwdg/2)^2*pi; % mm^2
Jrms = Iphm/Awdg; % A/mm^2
% ___________________________________________


% ___________________________________________
% Spatial model 2: Stator slot model
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
Dss = Dis+2*hs; % mm
Taoss = pi*Dss/Qs; % mm
Dos = Dss+2*hbc; % mm


% %% Electromagnetic model-7: Inductances
% % Armature reaction
% %Lgap1 = 16*mu0*Nphm^2*Dis*La/(pi*lg*1e-3*p^3) % Henries
% Agap = em*pi*Dis*La/p; % m^2
% Lgap = w*turnc^2*mu0*mur*Agap/((mur*lg+lm)*1e-3); % Henries
%
% % Slot leakage
% bs0 = bs1/2; % mm
% bsavg = (bs1+bs2)/2; % mm
% Lslk1 = Qs*(2*turnc)^2*[mu0*hs2*La/(3*bsavg)]; % Henries
% Lslk2 = Qs*(2*turnc)^2*[mu0*La*hs1/((bs0+bsavg)/2)]; % Henries
% Lslk3 = Qs*(2*turnc)^2*[mu0*hs0*La/bs0]; % Henries
% Lslk = Lslk1+Lslk2+Lslk3; % Henries
%
% % End turn leakage
% Lendt = w*mu0*Taos*turnc^2/4*log(Taos*sqrt(pi)/sqrt(2*Aslot*1e-6)); % Henries
%
% % Phase inductance
% Lph = Lgap + Lslk + Lendt; % Henries


% %% From maxwell
% Xa = 0.98;
% Xlk = 1.93;
% multip = 2*pi*fs;
% Lamx = Xa/multip*1000; % mH
%
% Agap = em*pi*Dis*La/p;
% Lgap = 1e3*w*turnc^2*mu0*mur*Agap/((mur*lg+lm)*1e-3); % mH
% Lslk1 = 1e3*w*(2*turnc)^2*[mu0*hs2*La/(3*bsavg)]; % mH
% Lslk2 = 1e3*w*(2*turnc)^2*[mu0*La*hs1/((bs0+bsavg)/2)]; % mH
% Lslk3 = 1e3*w*(2*turnc)^2*[mu0*hs0*La/bs0]; % mH
% %Lslk = Lslk1+Lslk2+Lslk3 % mH

% %Llkmx = Xlk/multip*1000 % mH
%
% %Lgap/Lamx;
% %Lslk/Llkmx

% %%
% %Lgap = 1e3*turnc^2*pi*La*Dis*mu0*mur/(p*(mur*lg+lm)*1e-3) % mH
%


% ___________________________________________
% Electromagnetic model-8: Resistances
% Mean length turn
MLT = 2*(La*1e-3+pi*Taos*1e-3/4+hs*1e-3/2); % m
Lengthph = MLT*Nphm; % m
% Phase resistance
Rphm20 = roc*Lengthph/(Awdg*1e-6); % 20 0C
Rphm = Rphm20*(1+Tccu*(75-20)); % 75 0C
% Effect of skin depth
% !!! add later
% ___________________________________________


% ___________________________________________
% Winding model (copper loss)
Pcuphm = Iphm^2*Rphm;
Pcum = Pcuphm*m;
Pcu = Pcum*n;
% ___________________________________________


% %% Harmonic equivalent circuit
% Xsh = 2*pi*fs*Lph;
% Vdrop = Xsh*Iphm;
% phi = 180/pi*atan(Vdrop/Ephm);
% pf = cos(phi*pi/180);
%
% Iphmh = zeros(1,31);
% Ephmh = Nphm*Ecoilh';
% Iharm = 0;
% for k = 3:31
%     Xphmh = 2*pi*fs*k*Lph;
%     Iphmh(k) = Ephmh(k)/Xphmh;
%     Iharm = Iharm+Iphmh(k)^2;
% end
% Iharm = sqrt(Iharm);
% Iphm;
% THD = 100*Iharm/Iphm;
%
%
% %% Cogging torque model
% % Inputs: Qs, p, em, lm, lg
% % Tcog



% ___________________________________________
% Thermal model-1: Lumped parameter model
% All GaNs are assumed as bottom cooled
Tmargin = 10; % Junction temperature margin
%RthjT = 8.5; % C/W, Junction-to-top thermal resistance
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
% Rthtot = (Rthjc + Rthpcb + Rthtim)/(2*m); % C/W
Rth1 = Rthjc + Rthpcb + Rthtim; % C/W
Rthsareq = (Tjmax-Tmargin-Tamb)/(Plosst*n*2*m) - Rth1/(n*2*m); % C/W
% ___________________________________________


% ___________________________________________
% Thermal model-2: Heat sink thermal model
% Natural convection is assumed
% Main dimensions (square heat sink is assumed)
%Whs = 200e-3; % m, width
Whs =  Dos; % mm
%Lhs = 200e-3; % m, length (also the lengrth of each fin)
Lhs = Dos; % mm
Hbase = 10e-3; % m, base plate height
% Some constants
cpair = 1000; % J/(kgK), specific heat of air
grc = 9.81; % m/s^2, gravitational acceleration
muair = 1.87e-5; % kg/(ms), dynamic viscosity of air
roair = 1.1; % kg/m^3, density of air
kair = 0.027; % W/Km, thermal conductivity of air
beta = 3.095e-3; % 1/K, coefficient of thermal expansion for air
deltaT = 40; % C, temperature difference from surface to air
% The Prandtl number:
Pr = muair*cpair/kair;
% Gr number ???
Gr = Lhs^3*roair^2*grc*deltaT*beta/muair^2;
% Rayleigh number
Ra = Pr*Gr;
if Ra > 1e9
    Nu = ( 0.825 + (0.387*Ra^(1/6))/(1+(0.492/Pr)^(9/16))^(8/27) )^2;
else
    Nu = 0.68 + (0.67*Ra^(1/4)) / (1+(0.492/Pr)^(9/16))^(4/9);
end
htcoef = Nu*kair/Lhs; % W/(Km^2), heat transfer coefficient
fineff = 1;
Nfin = 35; % number of fins
tfin = Lhs/(2*Nfin); % m, fin width
% The space width between fins
bfin = (Whs-Nfin*tfin)/(Nfin-1); % m
% Base surface area
Abase = (Nfin-1)*bfin*Lhs*1e-6; % m^2
% Thermal resistance of heat sink base (conduction)
kbase = 205; % W/Km, thermal conductivity of base (aluminum)
Rthbase = Hbase/(kbase*Whs*Lhs*1e-6); % C/W
Rthhscreq = Rthsareq - Rthbase; % C/W
% Required surface area
Areq = (htcoef*Rthsareq)^(-1); % m^2
Areqc = Areq - Abase; % m^2
Afinc = (Areq - Abase)/(fineff*Nfin); % m^2
Hfinc = Afinc/(2*Lhs*1e-3); % m
Hfinc = ceil(Hfinc*1000)/1000; % m
% Hotal heat sink height
Hhs = Hfinc+Hbase; % m
% ___________________________________________


% ___________________________________________
% Geometric model-3: power density
Volm = pi*(Dos*1e-3/2)^2*La*1e-3; % m^3
Voldr = pi*(Dos*1e-3/2)^2*(0.010+hcap*1e-3); % m^3
Volhs = pi*(Dos*1e-3/2)^2*Hhs; % m^3
Volsys = Voldr+Volhs+Volm; % m^3
PDv = (Pout*1e-3)/(Volsys*1e3); % kW/lt
% ___________________________________________


% ___________________________________________
% Geometric model-4: material volume and mass
% Core material: M250-50A
% https://perso.uclouvain.be/ernest.matagne/ELEC2311/T2006/NOFP.pdf
%tlam = 0.5; % mm
%sploss15 = 2.5; % W/kg, @50Hz
%sploss10 = 1.05; % W/kg, @50Hz
% Magnet: NdFeB40H, H grade (120 C)
% Rotor volume
% !!!! Rotor inner diameter (what will we do abut this???)
Dor = Dis-2*(lg+lm); % mm
Dir = Dor/2;
Vrotor = pi/4*(Dor^2-Dir^2)*La*1e-3; % cm^3
mrotor = 1e-3*Vrotor*denc; % kg
% Stator volume
Vstator = pi/4*(Dos^2-Dss^2)*La*1e-3 + hs*bt*La*1e-3*Qs; % cm^3
mstator = 1e-3*Vstator*denc; % kg
% Iron volume
Viron = Vrotor + Vstator; % cm^3
miron = mrotor + mstator; % kg
% Magnet volume
Vmagnet = pi*Dor*em*La*1e-3*lm; % cm^3
mmagnet = 1e-3*Vmagnet*denm; % kg
% Copper volume
Vcopper = Lengthph*Awdg*n*m; % cm^3
mcopper = 1e-3*Vcopper*dencu; % kg
% Heat sink volume
Vhsink = (pi/4*(Dos*1e-3)^2*Hbase + Nfin*(tfin*1e-3)*(Dos*1e-3)*Hfinc ) *1e6; % cm^3
mhsink = 1e-3*Vhsink*dena; % kg
% ___________________________________________


% ___________________________________________
% Electromagnetic model-9: Core loss
% Core material: M250-50A
% https://perso.uclouvain.be/ernest.matagne/ELEC2311/T2006/NOFP.pdf
Pcden = 4; % W/kg
Pc = Pcden*miron; % W
effm = Pout/(Pout+Pc+Pcu);
% ___________________________________________



problema = 0;
if Taos < 7 || Taos > 50
problema = 1
Nr
end


%param(indexa,index,indexo) = 1000*Taos;
%param(indexa,index,indexo) = 100*effm;
%param(indexa,index,indexo) = 100*effdr;
%param(indexa,index,indexo) = ns*Cdcreq*1e6;
%param(indexa,index,indexo) = Volcap;
%param1(indexa,index,indexo) = TotalCcap;
%param2(indexa,index,indexo) = TotalCgan;
%param1(indexa,index,indexo) = La*1e3;
%param2(indexa,index,indexo) = Dis*1e3;
%param(indexa,index,indexo) = Idcrms


% ma = 0.9, fsw = 40kHz, np = 1,2,3,4,5,6,7,8, ns = 2,3,4
% np_ns_Cdcreq(indexa,index) = ns*Cdcreq*1e6;
% np_ns_effdr(indexa,index) = 100*effdr;
% np_ns_PDv(indexa,index) = PDv;


% ns = 2, ma = 0.9, np = 1,2,3,4,5,6
% fsw_np_effdr(indexa,index) = 100*effdr;
% fsw_np_Cdcreq(indexa,index) = ns*Cdcreq*1e6;
% fsw_np_PDv(indexa,index) = PDv;
% fsw_np_Volcap(indexa,index) = Volcap*1e-3; % lt, actual
% fsw_np_Volhs(indexa,index) = Vhsink*1e-3; % lt, actual
% fsw_np_Voldr(indexa,index) = Voldr*1e3; % lt, drive
% fsw_np_Vhs(indexa,index) = Volhs*1e3; % lt, hetsink


% ns = 2, fsw = 40kHz, np = 1,2,3,4,5,6
% ma_np_effdr(indexa,index) = 100*effdr;
% ma_np_Cdcreq(indexa,index) = ns*Cdcreq*1e6;
% ma_np_Icrms(indexa,index) = Idcrms;
% ma_np_effm(indexa,index) = 100*effm;
% ma_np_PDv(indexa,index) = PDv;


% ns = 2, w = 2, np = 1,2,3,4
% ar_np_miron(indexa,index) = miron;
% ar_np_mmagnet(indexa,index) = mmagnet;
% ar_np_mcopper(indexa,index) = mcopper;
% ar_np_effm(indexa,index) = 100*effm;
% ar_np_PDv(indexa,index) = PDv;


%ar_np_cost(indexa,index) = miron*3 + mcopper*10 + mmagnet*80;

% ns = 2, np = 1, w = 2,4,6,8, Qs = 12,24,36,48
% ar_Qs_miron(indexa,index) = miron;
% ar_Qs_mmagnet(indexa,index) = mmagnet;
% ar_Qs_mcopper(indexa,index) = mcopper;
% ar_Qs_effm(indexa,index) = 100*effm;
% ar_Qs_PDv(indexa,index) = PDv;

%end
%end
%end

% fsw_xaxis = (1:21)'*10;
% ma_xaxis = 0.5 + (0:20)'*0.025;
% ar_xaxis = 0.2+(0:40)'*0.045;
% np_xaxis = 1:8;
% n_xaxis = (1:5)*2;
% 
% 
% save('pemd_data.mat');


outerdia(index) = Dos*1e-3; % m
innerdia(index) = Dis*1e-3; % m
axiallen(index) = La*1e-3; % m

%motoreff(index) = effm*100; % percent
%driveeff(index) = effdr*100; % percent

%copperloss(index) = Pcu; % W
%coreloss(index) = Pc; % W

%airgapB(index) = Bgp; % T
%currentdensity(index) = Jrms; % A/mm^2
%electricloading(index) = Arms; % kA/m
powden(index) = PDv; % kW/l

motorvolume(index) = Volm*1e3; % l
drivevolume(index) = Voldr*1e3; % l
heatsinkvolume(index) = Volhs*1e3; % l
totalvolume(index) = Volsys*1e3; % l

end

totalvol = pi*(outerdia/2).^2.*axiallen*1e3; % l
Powerdens = Pout*1e-3./totalvol; % kW/l
motor_speed = (1:50)*100; % rpm
%ma = 0.4 + (1:50)*0.012;


figure;
yyaxis left
plot(motor_speed,motorvolume,'b-','Linewidth',2.5);
hold on
plot(motor_speed,drivevolume,'r-','Linewidth',2.5);
hold on
plot(motor_speed,heatsinkvolume,'m-','Linewidth',2.5);
hold on
plot(motor_speed,totalvolume,'k-','Linewidth',2.5);
hold off;
ylim([0 20]);
yyaxis right 
plot(motor_speed,Powerdens,'g-','Linewidth',2.5);
hold on;
plot(motor_speed,powden,'c-','Linewidth',2.5);
hold off;
ylabel('Power Density (kW/lt)');
ylim([0 10])
grid on;
set(gca,'FontSize',12);
legend('Motor volume (l)','Drive volume (l)','Heat sink volume (l)',...
'Total Volume (l)','Power Density-1 (kW/l)','Power Density-2 (kW/l)');
xlabel('Motor speed (rpm)','FontSize',12,'FontWeight','Bold');


%%

figure;
plot(motor_speed,motorvolume./totalvolume,'b-','Linewidth',2.5);
grid on;
set(gca,'FontSize',12);
title('Ratio of motor volume to total volume','FontSize',12,'FontWeight','Bold')
xlabel('Motor speed (rpm)','FontSize',12,'FontWeight','Bold');


%%
figure;
yyaxis left
plot(ma,motoreff,'bo-','Linewidth',1.5);
hold on
plot(ma,driveeff,'ko-','Linewidth',1.5);
hold off;
ylim([95 100])
yyaxis right 
plot(ma,Powerdens,'go-','Linewidth',1.5);
hold off;
ylabel('Power Density (kW/lt)');
ylim([0 10])
grid on;
set(gca,'FontSize',12);
legend('Motor efficiency (%)','Drive efficiency (%)','Power Density (kW/l)');
xlabel('Modulation index','FontSize',12,'FontWeight','Bold')
title('5000 rpm design','FontSize',12,'FontWeight','Bold')

%%
figure;
yyaxis left
plot(motor_speed,outerdia*1e3,'bo-','Linewidth',1.5);
hold on
plot(motor_speed,innerdia*1e3,'ko-','Linewidth',1.5);
hold on;
plot(motor_speed,axiallen*1e3,'ro-','Linewidth',1.5);
hold off;
ylim([0 500])
yyaxis right 
plot(motor_speed,Powerdens,'go-','Linewidth',1.5);
hold off;
ylabel('Power Density (kW/lt)');
ylim([0 10])
grid on;
set(gca,'FontSize',12);
legend('Outer diameter (mm)','Bore diameter (mm)','Axial length (mm)','Power Density (kW/l)');
xlabel('Motor speed (rpm)','FontSize',12,'FontWeight','Bold')



%%
figure;
yyaxis left
plot(aspectratio,outerdia,'bo-','Linewidth',1.5);
hold on
plot(aspectratio,innerdia,'ko-','Linewidth',1.5);
hold on;
plot(aspectratio,axiallen,'ro-','Linewidth',1.5);
hold off;
yyaxis right 
plot(aspectratio,totalvol,'go-','Linewidth',1.5);
hold off;
ylabel('Total Volume (lt)');
ylim([0 10])
grid on;
set(gca,'FontSize',12);
legend('Outer diameter (mm)','Bore diameter (mm)','Axial length (mm)');
xlabel('Aspect ratio','FontSize',12,'FontWeight','Bold')



%%
Igan
Costm = miron*3 + mcopper*10 + mmagnet*80
Driveeff = 100*effdr
Motoreff = 100*effm
Powden = PDv
Cdcr = ns*Cdcreq*1e6
Icapr = Idcrms

%%
figure;
plot(xaxis,param1(4,:),'bo-','Linewidth',1.5);
hold on
plot(xaxis,param2(4,:),'ko-','Linewidth',1.5);
hold on;
plot(xaxis,param3(4,:),'ro-','Linewidth',1.5);
% hold on;
% plot(xaxis,param3(5,:),'go-','Linewidth',1.5);
% hold on;
% plot(xaxis,param3(6,:),'mo-','Linewidth',1.5);
% hold on;
% plot(xaxis,param3(7,:),'co-','Linewidth',1.5);
% hold on;
% plot(xaxis,param3(8,:),'kx','Linewidth',1.5);
hold off;
grid on;
set(gca,'FontSize',12);
%legend('Qs=12','Qs=18','Qs=24','Qs=30','Qs=36','Qs=42','Qs=48');
legend('Iron mass (1/10)','Magnet mass','Copper mass');
%'2parallel','3parallel','4parallel',...
%    '5parallel','6parallel','7parallel','8parallel');
title('Qs = 24');
xlabel('Aspect ratio','FontSize',12,'FontWeight','Bold')
ylabel('Active material mass (kg)','FontSize',12,'FontWeight','Bold')
%legend('Capacitor','Heat sink');
%ylim([5 10]);


%%
figure;
plot(xaxis,param3(2,:),'bo-','Linewidth',1.5);
hold on
plot(xaxis,param3(3,:),'ko-','Linewidth',1.5);
hold on;
plot(xaxis,param3(4,:),'ro-','Linewidth',1.5);
hold on;
plot(xaxis,param3(5,:),'go-','Linewidth',1.5);
hold on;
plot(xaxis,param3(6,:),'mo-','Linewidth',1.5);
hold on;
plot(xaxis,param3(7,:),'co-','Linewidth',1.5);
hold on;
plot(xaxis,param3(8,:),'kx','Linewidth',1.5);
hold off;
grid on;
set(gca,'FontSize',12);
legend('Qs=12','Qs=18','Qs=24','Qs=30','Qs=36','Qs=42','Qs=48');
%'2parallel','3parallel','4parallel',...
%    '5parallel','6parallel','7parallel','8parallel');
%title('w = 2');
xlabel('Aspect ratio','FontSize',12,'FontWeight','Bold')
ylabel('Active material mass (kg)','FontSize',12,'FontWeight','Bold')
%legend('Capacitor','Heat sink');
ylim([5 10]);


%%

clear yaxis
for uindex = 1:8
yaxis(uindex,:) = param(uindex,1,:);
end



%%
figure;
plot(xaxis,yaxis(1,:),'bo-','Linewidth',1.5);
hold on;
plot(xaxis,yaxis(2,:),'ko-','Linewidth',1.5);
hold on;
plot(xaxis,yaxis(3,:),'ro-','Linewidth',1.5);
hold on;
plot(xaxis,yaxis(4,:),'go-','Linewidth',1.5);
hold on;
plot(xaxis,yaxis(5,:),'co-','Linewidth',1.5);
hold on;
plot(xaxis,yaxis(6,:),'mo-','Linewidth',1.5);
hold on;
plot(xaxis,yaxis(7,:),'bo-','Linewidth',1.5);
hold on;
plot(xaxis,yaxis(8,:),'kx','Linewidth',1.5);
hold off;
grid on;
set(gca,'FontSize',12);
legend('1parallel','2parallel','3parallel','4parallel',...
    '5parallel','6parallel','7parallel','8parallel');
title('w = 2');
xlabel('Aspect ratio','FontSize',12,'FontWeight','Bold')
ylabel('Power density (kW/lt)','FontSize',12,'FontWeight','Bold')
%legend('Capacitor','Heat sink');
%ylim([94 98]);


%%
figure;
plot(xaxis,yaxis(1,:),'bo-','Linewidth',1.5);
hold on;
plot(xaxis,yaxis(2,:),'ko-','Linewidth',1.5);
hold on;
plot(xaxis,yaxis(3,:),'ro-','Linewidth',1.5);
hold on;
plot(xaxis,yaxis(4,:),'go-','Linewidth',1.5);
hold on;
plot(xaxis,yaxis(5,:),'co-','Linewidth',1.5);
hold on;
plot(xaxis,yaxis(6,:),'mo-','Linewidth',1.5);
hold on;
plot(xaxis,yaxis(7,:),'bo-','Linewidth',1.5);
hold on;
plot(xaxis,yaxis(8,:),'kx','Linewidth',1.5);
hold off;
grid on;
set(gca,'FontSize',12);
legend('1parallel','2parallel','3parallel','4parallel',...
    '5parallel','6parallel','7parallel','8parallel');
title('w = 2');
xlabel('Aspect ratio','FontSize',12,'FontWeight','Bold')
ylabel('Motor efficiency (%)','FontSize',12,'FontWeight','Bold')
%legend('Capacitor','Heat sink');
ylim([95 98])



%%
figure;
plot(xaxis,param1(1,:,1),'bo-','Linewidth',1.5);
hold on;
plot(xaxis,param(1,:,2),'ko-','Linewidth',1.5);
hold on;
plot(xaxis,param(1,:,3),'ro-','Linewidth',1.5);
hold on;
plot(xaxis,param(1,:,4),'go-','Linewidth',1.5);
hold on;
plot(xaxis,param(1,:,5),'co-','Linewidth',1.5);
hold on;
plot(xaxis,param(1,:,6),'mo-','Linewidth',1.5);
hold on;
plot(xaxis,param(1,:,7),'bo-','Linewidth',1.5);
hold on;
plot(xaxis,param1(1,:,8),'kx','Linewidth',1.5);
hold off;
grid on;
set(gca,'FontSize',12);
legend('2parallel','3parallel','4parallel',...
    '5parallel','6parallel','7parallel');
title('2 series modules, ma = 0.9');
xlabel('Switching frequency (kHz)','FontSize',12,'FontWeight','Bold')
ylabel('Power density (kW/lt)','FontSize',12,'FontWeight','Bold')
%legend('Capacitor','Heat sink');
ylim([0.5 1])



%%

%
%
figure;
%subplot(3,1,1)
%plot(xaxis,param(1,:,1),'bo-','Linewidth',1.5);
%hold on;
yyaxis left
ylabel('Capacitor bank volume (lt)','FontSize',12,'FontWeight','Bold')
plot(xaxis,param1(1,:,2),'ko-','Linewidth',1.5);
%hold on;
ylim([0 0.4])

yyaxis right
ylabel('Heat sink volume (lt)','FontSize',12,'FontWeight','Bold')
plot(xaxis,param2(1,:,2),'ro-','Linewidth',1.5);
%hold on;
%plot(xaxis,param(1,:,4),'go-','Linewidth',1.5);
%hold on;
%plot(xaxis,param(1,:,5),'co-','Linewidth',1.5);
%hold on;
%plot(xaxis,param(1,:,6),'mo-','Linewidth',1.5);
%hold on;
%plot(xaxis,param(1,:,7),'bx-','Linewidth',1.5);
%hold on;
%plot(xaxis,param(1,:,8),'kx','Linewidth',1.5);
%hold off;
grid on;
set(gca,'FontSize',12);
%legend('2parallel','3parallel','4parallel',...
%    '5parallel','6parallel');%,'7parallel','8parallel');
title('2 series modules, ma = 0.9');
xlabel('Switching frequency (kHz)','FontSize',12,'FontWeight','Bold')
ylabel('Volume (lt)','FontSize',12,'FontWeight','Bold')
%legend('Capacitor','Heat sink');

%%
figure;
subplot(3,1,1)
plot(xaxis,param(1,:,1),'bo-','Linewidth',1.5);
hold on;
plot(xaxis,param(1,:,2),'ko-','Linewidth',1.5);
hold on;
plot(xaxis,param(1,:,3),'ro-','Linewidth',1.5);
hold on;
plot(xaxis,param(1,:,4),'go-','Linewidth',1.5);
hold on;
plot(xaxis,param(1,:,5),'co-','Linewidth',1.5);
hold on;
plot(xaxis,param(1,:,6),'mo-','Linewidth',1.5);
hold off;
grid on;
set(gca,'FontSize',12);
legend('1parallel','2parallel','3parallel','4parallel','5parallel','6parallel');
title('2 series modules');
xlabel('Switching frequency (kHz)','FontSize',12,'FontWeight','Bold')
ylabel('Overall power density (kW/lt)','FontSize',12,'FontWeight','Bold')
ylim([0.5 1]);

%ylabel('Magnet mass (kg)','FontSize',12,'FontWeight','Bold')
%xlabel('Slot/module/phase','FontSize',12,'FontWeight','Bold')
%xlabel('Aspect ratio','FontSize',12,'FontWeight','Bold')
%ylabel('Motor efficiency (%)','FontSize',12,'FontWeight','Bold')
%xlabel('Switching frequency (kHz)','FontSize',12,'FontWeight','Bold')
%xlabel('Modulation index','FontSize',12,'FontWeight','Bold')
%ylabel('Drive efficiency (%)','FontSize',12,'FontWeight','Bold')
%ylabel('Capacitance requirement (uF)','FontSize',12,'FontWeight','Bold')
%ylabel('Total capacitor volume (cm^3)','FontSize',12,'FontWeight','Bold')
%ylabel('DC bus ripple current requirement (Arms)','FontSize',12,'FontWeight','Bold')
%xlim([0.0995 0.1]);
%ylim([0 400]);


subplot(3,1,2)
plot(xaxis,param(2,:,1),'bo-','Linewidth',1.5);
hold on;
plot(xaxis,param(2,:,2),'ko-','Linewidth',1.5);
hold on;
plot(xaxis,param(2,:,3),'ro-','Linewidth',1.5);
hold on;
plot(xaxis,param(2,:,4),'go-','Linewidth',1.5);
hold on;
plot(xaxis,param(2,:,5),'co-','Linewidth',1.5);
hold on;
plot(xaxis,param(2,:,6),'mo-','Linewidth',1.5);
hold off;
grid on;
set(gca,'FontSize',12);
legend('1parallel','2parallel','3parallel','4parallel','5parallel','6parallel');
title('3 series modules');
xlabel('Switching frequency (kHz)','FontSize',12,'FontWeight','Bold')
ylabel('Overall power density (kW/lt)','FontSize',12,'FontWeight','Bold')
ylim([0.5 1]);

subplot(3,1,3)
plot(xaxis,param(3,:,1),'bo-','Linewidth',1.5);
hold on;
plot(xaxis,param(3,:,2),'ko-','Linewidth',1.5);
hold on;
plot(xaxis,param(3,:,3),'ro-','Linewidth',1.5);
hold on;
plot(xaxis,param(3,:,4),'go-','Linewidth',1.5);
hold on;
plot(xaxis,param(3,:,5),'co-','Linewidth',1.5);
hold on;
plot(xaxis,param(3,:,6),'mo-','Linewidth',1.5);
hold off;
grid on;
set(gca,'FontSize',12);
legend('1parallel','2parallel','3parallel','4parallel','5parallel','6parallel');
title('4 series modules');
xlabel('Switching frequency (kHz)','FontSize',12,'FontWeight','Bold')
ylabel('Overall power density (kW/lt)','FontSize',12,'FontWeight','Bold')
ylim([0.5 1]);


%%

figure;
subplot(3,1,1)
plot(xaxis,param(1,:,1),'bo-','Linewidth',1.5);
hold on;
plot(xaxis,param(1,:,2),'ko-','Linewidth',1.5);
hold on;
plot(xaxis,param(1,:,3),'ro-','Linewidth',1.5);
hold on;
plot(xaxis,param(1,:,4),'go-','Linewidth',1.5);
hold on;
plot(xaxis,param(1,:,5),'co-','Linewidth',1.5);
hold on;
plot(xaxis,param(1,:,6),'mo-','Linewidth',1.5);
hold off;
grid on;
set(gca,'FontSize',12);
xlabel('Switching frequency (kHz)','FontSize',12,'FontWeight','Bold')
%ylabel('Drive efficiency (%)','FontSize',12,'FontWeight','Bold')
%ylabel('Capacitance requirement (uF)','FontSize',12,'FontWeight','Bold')
ylabel('DC bus ripple current requirement (Arms)','FontSize',12,'FontWeight','Bold')
%xlim([0.0995 0.1]);
ylim([0 20]);
legend('1parallel','2parallel','3parallel','4parallel','5parallel','6parallel');
title('2 series modules');

subplot(3,1,2)
plot(xaxis,param(2,:,1),'bo-','Linewidth',1.5);
hold on;
plot(xaxis,param(2,:,2),'ko-','Linewidth',1.5);
hold on;
plot(xaxis,param(2,:,3),'ro-','Linewidth',1.5);
hold on;
plot(xaxis,param(2,:,4),'go-','Linewidth',1.5);
hold on;
plot(xaxis,param(2,:,5),'co-','Linewidth',1.5);
hold on;
plot(xaxis,param(2,:,6),'mo-','Linewidth',1.5);
hold off;
grid on;
set(gca,'FontSize',12);
xlabel('Switching frequency (kHz)','FontSize',12,'FontWeight','Bold')
ylabel('DC bus ripple current requirement (Arms)','FontSize',12,'FontWeight','Bold')
%xlim([0.0995 0.1]);
ylim([0 20]);
legend('1parallel','2parallel','3parallel','4parallel','5parallel','6parallel');
title('3 series modules');

subplot(3,1,3)
plot(xaxis,param(3,:,1),'bo-','Linewidth',1.5);
hold on;
plot(xaxis,param(3,:,2),'ko-','Linewidth',1.5);
hold on;
plot(xaxis,param(3,:,3),'ro-','Linewidth',1.5);
hold on;
plot(xaxis,param(3,:,4),'go-','Linewidth',1.5);
hold on;
plot(xaxis,param(3,:,5),'co-','Linewidth',1.5);
hold on;
plot(xaxis,param(3,:,6),'mo-','Linewidth',1.5);
hold off;
grid on;
set(gca,'FontSize',12);
xlabel('Switching frequency (kHz)','FontSize',12,'FontWeight','Bold')
ylabel('DC bus ripple current requirement (Arms)','FontSize',12,'FontWeight','Bold')
%xlim([0.0995 0.1]);
ylim([0 20]);
legend('1parallel','2parallel','3parallel','4parallel','5parallel','6parallel');
title('4 series modules');


%%
figure;

%subplot(3,1,1)
plot(xaxis,param1(1,:,1),'bo-','Linewidth',1.5);
hold on;
plot(xaxis,param2(1,:,1),'ko-','Linewidth',1.5);
% hold on;
% plot(xaxis,param(1,:,3),'ro-','Linewidth',1.5);
% hold on;
% plot(xaxis,param(1,:,4),'go-','Linewidth',1.5);
% hold on;
% plot(xaxis,param(1,:,5),'co-','Linewidth',1.5);
% hold on;
% plot(xaxis,param(1,:,6),'mo-','Linewidth',1.5);
hold off;
grid on;
set(gca,'FontSize',12);
xlabel('Switching frequency (kHz)','FontSize',12,'FontWeight','Bold')
%xlabel('Modulation index','FontSize',12,'FontWeight','Bold')
%ylabel('Drive efficiency (%)','FontSize',12,'FontWeight','Bold')
%ylabel('Capacitance requirement (uF)','FontSize',12,'FontWeight','Bold')
ylabel('Cost','FontSize',12,'FontWeight','Bold')
%ylabel('DC bus ripple current requirement (Arms)','FontSize',12,'FontWeight','Bold')
%xlim([0.0995 0.1]);
%ylim([95 100]);
%ylim([0 400]);
legend('Cap cost','Gan cost');
title('2 series modules');
