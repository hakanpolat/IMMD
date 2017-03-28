%% Simulation base for RPG
Ts = 1e-6;
% RPCU
Crpcu_each = 250e-6; % Farads
% switching frequency
fsw = 5e3; % Hz

% Solar panel side
Vdc = 700; % V
Rseries = 5; % Ohm
Pout = 50e3; % W
Rrefl = Vdc^2/Pout;
V1 = Vdc*(Rseries+Rrefl)/Rrefl; % V


%%
% modulation index
ma = 0.66;
% switching frequency
fsw = 1e3; % Hz
% DC link voltage
Vdc = 700; % Volts
% DC Link capacitor
Cdc = 1e-3; % Farads
ESR = 1e-3; % Ohms
% Load
Sout = 20e3; % VA
fout = 50; % Hz
wout = 2*pi*fout; % rad/sec
Vll_rms = 400; % Volts
Iline = Sout/(Vll_rms*sqrt(3)); % Amps
pf = 0.8;
Zload = Vll_rms/(Iline*sqrt(3)); % Ohms
Rload = Zload*pf; % Ohms
Xload = sqrt(Zload^2-Rload^2); % Ohms
Lload = Xload/wout; % Henries

