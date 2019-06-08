% Simulation parameters
% Analytical model
% RL load

% Series or parallel
np = 1;
ns = 1;

% Selections
ESL_ESR = 1;
Par_module = 0;

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
        ESL = 19e-9; % H
        ESR = 21.1e-3; % Ohm
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
        
        LATop  = 03.40e-9;
        LABot  = 20.25e-9;
        LAMid  = 01.30e-9;
        LBTop  = 03.38e-9;
        LBBot  = 20.38e-9;
        LBMid  = 01.30e-9;
        LCTop  = 03.41e-9;
        LCBot  = 20.94e-9;
        LCMid  = 01.30e-9;
        LABTop = 18.30e-9;
        LABBot = 10.20e-9;
        LBCTop = 21.84e-9;
        LBCBot = 11.14e-9;

        RATop  = 9.70e-3;
        RABot  = 52.8e-3;
        RAMid  = 1.30e-3;
        RBTop  = 9.87e-3;
        RBBot  = 43.9e-3;
        RBMid  = 1.30e-3;
        RCTop  = 49.4e-3;
        RCBot  = 46.6e-3;
        RCMid  = 1.30e-3;
        RABTop = 42.6e-3;
        RABBot = 20.4e-3;
        RBCTop = 49.4e-3;
        RBCBot = 16.6e-3;

    case 0
        LATop  = 03.40e-15;
        LABot  = 20.25e-15;
        LAMid  = 01.30e-15;
        LBTop  = 03.38e-15;
        LBBot  = 20.38e-15;
        LBMid  = 01.30e-15;
        LCTop  = 03.41e-15;
        LCBot  = 20.94e-15;
        LCMid  = 01.30e-15;
        LABTop = 18.30e-15;
        LABBot = 10.20e-15;
        LBCTop = 21.84e-15;
        LBCBot = 11.14e-15;

        RATop  = 03.40e-15;
        RABot  = 20.25e-15;
        RAMid  = 01.30e-15;
        RBTop  = 03.38e-15;
        RBBot  = 20.38e-15;
        RBMid  = 01.30e-15;
        RCTop  = 03.41e-15;
        RCBot  = 20.94e-15;
        RCMid  = 01.30e-15;
        RABTop = 18.30e-15;
        RABBot = 10.20e-15;
        RBCTop = 21.84e-15;
        RBCBot = 11.14e-15;

    otherwise
        LATop  = 03.40e-15;
        LABot  = 20.25e-15;
        LAMid  = 01.30e-15;
        LBTop  = 03.38e-15;
        LBBot  = 20.38e-15;
        LBMid  = 01.30e-15;
        LCTop  = 03.41e-15;
        LCBot  = 20.94e-15;
        LCMid  = 01.30e-15;
        LABTop = 18.30e-15;
        LABBot = 10.20e-15;
        LBCTop = 21.84e-15;
        LBCBot = 11.14e-15;

        RATop  = 03.40e-15;
        RABot  = 20.25e-15;
        RAMid  = 01.30e-15;
        RBTop  = 03.38e-15;
        RBBot  = 20.38e-15;
        RBMid  = 01.30e-15;
        RCTop  = 03.41e-15;
        RCBot  = 20.94e-15;
        RCMid  = 01.30e-15;
        RABTop = 18.30e-15;
        RABBot = 10.20e-15;
        RBCTop = 21.84e-15;
        RBCBot = 11.14e-15;

end





