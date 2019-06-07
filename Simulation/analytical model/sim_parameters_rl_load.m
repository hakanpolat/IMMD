% Simulation parameters
% Analytical model
% RL load

% Series or parallel
np = 1;
ns = 1;

% Selections
ESL_ESR = 1;
Par_module = 1;

Ts = 1e-8; % sec
Tfinal = 0.05; % sec
Ripth = 0.03; % sec
minlim = 200; % V
maxlim = 340; % V
fsw = 10e3; % Hz
fout = 50; % Hz
wout = 2*pi*fout; % rad/sec
Poutm = 2e3; % W
Vdcm = 270; % V
m = 3;
n = ns*np;
Pout = Poutm*n; % W
Vdc = Vdcm*ns; % V
ma = 0.9;
delta = 0;
deltad = delta*180/pi; % degrees
phase = [0 0];
Rin = 200;
Lin = 1e-6;
Vin = Vdc + Rin*(Pout/Vdc);
Cdc1 = 5e-6; % F
Cdc = 3*Cdc1; % F
Vt = 0.612*ma*Vdcm/sqrt(3);
pf = 0.9;
Soutm = Poutm/pf;
Is = Soutm/(m*Vt);
Zload = Vt/Is;
Rload = Zload*pf;
Xload = sqrt(Zload^2-Rload^2);
Lload = Xload/(2*pi*fout);

switch ESL_ESR
    case 1
        ESL = 19e-9/3; % H
        ESR = 21.1e-3/3; % Ohm
    case 0
        ESL = 1e-15; % H
        ESR = 1e-15; % Ohm
    otherwise
        ESL = 1e-15; % H
        ESR = 1e-15; % Ohm
end

switch Par_module
    case 1
        Lpar = 50e-9; % H
        Rpar = 10e-3; % Ohm
    case 0
        Lpar = 1e-9; % H
        Rpar = 1e-9; % Ohm
    otherwise
        Lpar = 1e-9; % H
        Rpar = 1e-9; % Ohm
end

