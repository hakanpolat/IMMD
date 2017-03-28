%% Simulation base for RPG
Ts = 1e-6;
% RPCU
% switching frequency

% Solar panel side
Vdc = 700; % V
Rseries = 5; % Ohm
Pout = 50e3; % W
Rrefl = Vdc^2/Pout;
V1 = Vdc*(Rseries+Rrefl)/Rrefl; % V

% Inverter
fsw = 5e3; % Hz
Ls = 1e-3; % H
RLs = 1e-6; % Ohms

% Grid
Vphase = 230; % V
Vline = Vphase*sqrt(3); % V
fs = 50; % Hz

% Load
Pload = 200e3; % W
Qload = 100e3; % VAr
Sload = sqrt(Pload^2+Qload^2); % VA
pfload = Pload/Sload;
Zload = Vphase^2/(Sload/3); % Ohm
Rload = Zload*pfload; % Ohm
Xload = sqrt(Zload^2-Rload^2); % Ohm
Lload = Xload/(2*pi*fs); % H

% RPCU
rpcu_capacity = 50e3; % VAr
Qrpcu_each = rpcu_capacity/(3*4)
Zrpcu_each = Vphase^2/(Qrpcu_each);
Crpcu_each = 1/(2*pi*fs*Zrpcu_each);
% USER SELECTED
rpc_demand = 23e3; % VAr
% USER SELECTED
if rpc_demand > 0 && rpc_demand <= rpcu_capacity/4
    rpcu_s1 = 1;
    rpcu_s2 = 0;
    rpcu_s3 = 0;
    rpcu_s4 = 0;
elseif rpc_demand > rpcu_capacity/4 && rpc_demand <= rpcu_capacity/2
    rpcu_s1 = 1;
    rpcu_s2 = 1;
    rpcu_s3 = 0;
    rpcu_s4 = 0;
elseif rpc_demand > rpcu_capacity/2 && rpc_demand <= 3*rpcu_capacity/4
    rpcu_s1 = 1;
    rpcu_s2 = 1;
    rpcu_s3 = 1;
    rpcu_s4 = 0;
elseif rpc_demand > 3*rpcu_capacity/4 && rpc_demand <= rpcu_capacity
    rpcu_s1 = 1;
    rpcu_s2 = 1;
    rpcu_s3 = 1;
    rpcu_s4 = 1;
else
       rpcu_s1 = 0;
    rpcu_s2 = 0;
    rpcu_s3 = 0;
    rpcu_s4 = 0; 
end    
    

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

