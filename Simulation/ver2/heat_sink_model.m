%% Heat sink model (thermal)

% Thermal grease: http://tr.farnell.com/c/cooling-thermal-management/thermal-interface-materials/thermal-grease
% All GaNs are assumed as bottom cooled

% Inputs
Plosst = 7; % Loss of each GaN
Rthjc = 0.5; % Thermal resistance (junction-case) of each transistor
Tamb = 50; % Ambient temperature
Tjmax = 150; % Maximum junction temperature
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

% Rthtot = (Rthjc + Rthpcb + Rthtim)/(2*m); % C/W
Rth1 = Rthjc + Rthpcb + Rthtim; % C/W

Rthreq = (Tjmax-Tmargin-Tamb)/(Plosst*n*2*m) - Rth1/(n*2*m);


%% Thermal modeling of heatsink

% https://www.electronics-cooling.com/2003/02/estimating-parallel-plate-fin-heat-sink-thermal-resistance/#
% https://www.engineeringtoolbox.com/dry-air-properties-d_973.html
% https://www.myheatsinks.com/calculate/thermal-resistance-plate-fin/
% https://www.electronics-cooling.com/2002/02/estimating-natural-convection-heat-transfer-for-arrays-of-vertical-parallel-flat-plates/
  
% Main dimensions (square heat sink is assumed)
Whs = 200e-3; % m, width
Lhs = 200e-3; % m, length
Hfin = 50e-3; % m, height
Hbase = 10e-3; % m, base plate height
Nfin = 35; % number of fins
%tfin = Lhs/(2*Nfin); % m, fin width
tfin = 3e-3; % m, fin width
% Heat sink height
Hhs = Hfin+Hbase; % m
% The space width between fins
bfin = (Whs-Nfin*tfin)/(Nfin-1); % m
% Base surface area
Abase = (Nfin-1)*bfin*Lhs; % m^2
% Fin surface area
Afin = 2*Hfin*Lhs; % m^2
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
% Thermal resistance of heat sink base (conduction)
kbase = 205; % W/Km, thermal conductivity of base (aluminum)
Rthbase = Hbase/(kbase*Whs*Lhs); % C/W
% Thermal resistance of heat sink (convection)
Rthhsc = (htcoef*(Abase+Nfin*fineff*Afin))^(-1); % C/W
% Total thermal resistance of heat sink
Rthhs = Rthbase+Rthhsc; % C/W



%%
%vel = 2.5; % m/s, velocity of air flow

% Pr = 0.708; % @70 C
% https://www.engineeringtoolbox.com/dry-air-properties-d_973.html
% Reynolds number
%Re = roair*vel*bfins^2/(muair*Lhs);
% Nusselt number
%Nub = ( ( (Re*Pr/2)^(-3) ) +...
%    (0.664*sqrt(Re)*Pr^0.33*sqrt(1+3.65/sqrt(Re)))^(-3) )...
%    ^(-0.33);
% Heat transfer coefficient with convection
% kfluid = 0.0290; % W/Km, thermal conductivity of fluid (air)
% htcoef = Nub*kfluid/bfins;
% % Fin efficiency
% kfin = 205; % W/Km, thermal conductivity of fins (aluminum)
% mhs = sqrt(2*htcoef/(kfin*tfin)); % ???
% fineff = tanh(mhs*Hfin)/(mhs*Hfin);

%%
%Ra2 = (roair^2*grc*kair*bfin^4*deltaT)/(muair*kair*Lhs)
%htcoef = (Ra*kair)/(24*bfin)*(1-2.718281^(-35/Ra))^0.75
