% The analytical model for heat sink sizing

% Required heat sink thermal resistance
Rthsareq = 1; % K/W
Dos = 270; % mm

% Natural convection is assumed

% Main dimensions (square heat sink is assumed)
Atot = pi*(Dos*1e-3/2)^2/4; % m^2
Lhs = sqrt(Atot); % m
Whs = Lhs; % m
Hbase = 7e-3; % m, base plate height

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
Nfin = 12; % number of fins
%tfin = Lhs/(2*Nfin); % m, fin width
tfin = 3e-3; % m

% The space width between fins
bfin = (Dos*1e-3/2-Nfin*tfin)/(Nfin-1); % m

% Base surface area
Abase = (Nfin-1)*bfin*Lhs; % m^2
% Thermal resistance of heat sink base (conduction)
kbase = 205; % W/Km, thermal conductivity of base (aluminum)
Rthbase = Hbase/(kbase*Whs*Lhs); % C/W
Rthhscreq = Rthsareq - Rthbase; % C/W

% Required surface area
Areq = (htcoef*Rthsareq)^(-1); % m^2
Areqc = Areq - Abase; % m^2
Afinc = Areqc/(fineff*Nfin); % m^2
Hfinc = Afinc/(2*Lhs); % m
Hfinc = ceil(Hfinc*1000)/1000; % m
% Hotal heat sink height
Hhs = Hfinc+Hbase; % m
% ___________________________________________

