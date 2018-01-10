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
%vel = 2.5; % m/s, velocity of air flow

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



