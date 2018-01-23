%% ECCE Loss Model
%% Initialization
% Device Parameters
Cgd = 1.748e-12;
Cgs = 160e-12;
Cds = 65.7e-12;

Ls = 62e-12;
Ld = 450e-12;
Lg = 0.65e-9;
Lss = 0.43e-9;

Rg = 1.5;
Rd = 0.0024 + 1e-4;
Rs = 0.0433 + 1e-4;
Rss = 1e-3;

Rt = (0.9*0.95*0.82*18.2/295 + 3.6*0.238*0.82/295);

% Circuit Parasitics
Ldc = 1.5e-9;
Lground = 5e-9;
Lp = 10e-12;
% Gate Driver
Lgex = 3e-9;
Ron = 10;
Roff = 2;
% Source parameters
PulseAmplitude = 9;
fsw = 2000e3;
Vdc = 400;
VpulseMax = 6;
VpulseMin = -3;
% Quantities in below are in percent
Dtop = 48; % duty cycle of top
Dbot = 48; % duty cycle of bot
DelayTop = 0;
DelayBot = 50;


% Load parameters
LoadCurrent = 30;
Lload = 480e-6;

CurrRipple = Vdc*(Dbot/100)/(fsw*Lload);
InitialCurrent = LoadCurrent + CurrRipple/2;

Req = Rg + Rs + Ron;
Leq = Lgex + Lg + Ls + Lp;
Ceq = Cgs + Cgd;
%% Time & I-V Calculator

tdelayon = Req*220e-12*log((VpulseMax - VpulseMin)/(VpulseMax)) + Req*360e-12*log((VpulseMax)/(VpulseMax-1.7))...
    + 5e-10*(1.7/(1.7 - VpulseMin)); %1e-10 placed to compensate gate voltage source rise time
Vgs_tcrl = 2 + (LoadCurrent - 5)/40; %Vgs value when current reaches to load ampere
time_cur_RiseToLoad = Req*(600e-12)*log((VpulseMax - 1.7)/(VpulseMax - Vgs_tcrl));
time_cur_RiseToPeak = Req*(600e-12)*log((VpulseMax - Vgs_tcrl)/(VpulseMax - Vgs_tcrl - 0.65));

%% Loss Calculator

Eon = Vdc * LoadCurrent/2 * time_cur_RiseToLoad + ...
    (Vdc + Vi_peak)/2 * (LoadCurrent + Ipeak)/2 * time_cur_RiseToPeak + ...
    Vi_peak/2 * (Ipeak + LoadCurrent)/2 * time_cur_FallToLoad;

