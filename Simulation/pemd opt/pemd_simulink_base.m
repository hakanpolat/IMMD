%%
% This file is the base .m file for the verification simulations carried
% out on Simulink
% This verification is used for optimization (PEMD) purposes

%%
% Design and simulation with single module
% Number of modules
n = 1;
ns = 1;
np = n/ns;
% Step time
Ts = 1e-6; % sec
% Modulation index
ma = 0.8;
% Switching frequency
fsw = 10e3; % Hz
% DC link voltage
Vdc = 540; % Volts
Vdcm = Vdc/ns;
% Load
effmotor = 0.94;
Ptotal = 8e3/effmotor; % W
Pout = Ptotal/n; % W
pf = 0.9;
Sout = Pout/pf; % VA
fout = 50; % Hz
wout = 2*pi*fout; % rad/sec
Vll_rms = ma*Vdcm*0.612; % Volts
Iline = Sout/(Vll_rms*sqrt(3)); % Amps
Zload = Vll_rms/(Iline*sqrt(3)); % Ohms
Rload = Zload*pf; % Ohms
Xload = sqrt(Zload^2-Rload^2); % Ohms
Lload = Xload/wout; % Henries
%phase = [0 80 0 80];

Rin = 10;
Vin = Vdc + Rin*(Ptotal/Vdc);
Cdc = 100e-6;




%%
% Design and simulation with series connected modules

% Number of modules
n = 4;
ns = 2;
np = n/ns;
% Step time
Ts = 1e-6; % sec
% Modulation index
ma = 0.8;
% Switching frequency
fsw = 10e3; % Hz
% DC link voltage
Vdc = 540; % Volts
Vdcm = Vdc/ns;
% Load
Ptotal = 8e3/0.9; % W
Pout = Ptotal/n; % W
pf = 0.9;
Sout = Pout/pf; % VA
fout = 50; % Hz
wout = 2*pi*fout; % rad/sec
Vll_rms = ma*Vdcm*0.612; % Volts
Iline = Sout/(Vll_rms*sqrt(3)); % Amps
Zload = Vll_rms/(Iline*sqrt(3)); % Ohms
Rload = Zload*pf; % Ohms
Xload = sqrt(Zload^2-Rload^2); % Ohms
Lload = Xload/wout; % Henries
phase = [0 80 0 80];

Rin = 10;
%Lin = 1e-3;
Vin = Vdc + Rin*(Ptotal/Vdc);
Cdc = 100e-6;
