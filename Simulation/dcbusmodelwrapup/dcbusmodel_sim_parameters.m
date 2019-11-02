%%
% Single module
% No parasitics
% Balanced load
% Infinite bus

Ts = 1e-6; % sec
Tfinal = 0.2; % sec
Ripth = 0.18; % sec
fsw = 10e3; % Hz
Vdc = 270; % Volts
fout = 50; % Hz
wout = 2*pi*fout; % rad/sec
m = 3;
np = 1;
ns = 1;
n = ns*np;
phase = [0 0 0 0];
Cdc = 15e-6;
delta = 0; % rad

% Calculate nominal values
Pmodt = 2e3;
pft = 0.9;
manom = 0.9;
Vdcnom = Vdc/ns;
Vllrmsnom = 0.612*manom*Vdcnom;
Vlnrms = Vllrmsnom/sqrt(3);
Smodt = Pmodt/pft;
Ilinemod = Smodt/(3*Vlnrms);
Znom = Vlnrms/Ilinemod;
Rnom = Znom*pft;
Xnom = sqrt(Znom^2-Rnom^2);
Lnom = Xnom/(2*pi*fout);

Lload_1A = Lnom*1.00; % Henries
Lload_1B = Lnom*1.00; % Henries
Lload_1C = Lnom*1.00; % Henries
Rload_1A = Rnom*1.00; % Ohms
Rload_1B = Rnom*1.00; % Ohms
Rload_1C = Rnom*1.00; % Ohms

Lload_2A = Lnom*1.00; % Henries
Lload_2B = Lnom*1.00; % Henries
Lload_2C = Lnom*1.00; % Henries
Rload_2A = Rnom*1.00; % Ohms
Rload_2B = Rnom*1.00; % Ohms
Rload_2C = Rnom*1.00; % Ohms

X1A = 2*pi*fout*Lload_1A; % Ohm
X1B = 2*pi*fout*Lload_1B; % Ohm
X1C = 2*pi*fout*Lload_1C; % Ohm
X2A = 2*pi*fout*Lload_2A; % Ohm
X2B = 2*pi*fout*Lload_2B; % Ohm
X2C = 2*pi*fout*Lload_2C; % Ohm

Z1A = sqrt(Rload_1A^2+X1A^2); % Ohm
Z1B = sqrt(Rload_1B^2+X1B^2); % Ohm
Z1C = sqrt(Rload_1C^2+X1C^2); % Ohm
Z2A = sqrt(Rload_2A^2+X2A^2); % Ohm
Z2B = sqrt(Rload_2B^2+X2B^2); % Ohm
Z2C = sqrt(Rload_2C^2+X2C^2); % Ohm

pf1A = Rload_1A/Z1A;
pf1B = Rload_1B/Z1B;
pf1C = Rload_1C/Z1C;
pf2A = Rload_2A/Z2A;
pf2B = Rload_2B/Z2B;
pf2C = Rload_2C/Z2C;

ma1 = manom;

Pout = Pmodt*ns*np;
Rin = 5;
Rmid = 1e-3;
Cdcrec = 1.1e-3;
Vin = Vdc + (Rin+Rmid)*(Pout/Vdc);


%%
% Single module
% No parasitics
% Unbalance on load
% Infinite bus

Ts = 1e-6; % sec
Tfinal = 0.2; % sec
Ripth = 0.18; % sec
fsw = 10e3; % Hz
Vdc = 270; % Volts
fout = 50; % Hz
wout = 2*pi*fout; % rad/sec
m = 3;
np = 1;
ns = 1;
n = ns*np;
phase = [0 0 0 0];
Cdc = 15e-6;
delta = 0; % rad

% Calculate nominal values
Pmodt = 2e3;
pft = 0.9;
manom = 0.9;
Vdcnom = Vdc/ns;
Vllrmsnom = 0.612*manom*Vdcnom;
Vlnrms = Vllrmsnom/sqrt(3);
Smodt = Pmodt/pft;
Ilinemod = Smodt/(3*Vlnrms);
Znom = Vlnrms/Ilinemod;
Rnom = Znom*pft;
Xnom = sqrt(Znom^2-Rnom^2);
Lnom = Xnom/(2*pi*fout);

Lload_1A = Lnom*1.00; % Henries
Lload_1B = Lnom*1.50; % Henries
Lload_1C = Lnom*1.00; % Henries
Rload_1A = Rnom*1.00; % Ohms
Rload_1B = Rnom*1.00; % Ohms
Rload_1C = Rnom*1.50; % Ohms

Lload_2A = Lnom*1.00; % Henries
Lload_2B = Lnom*1.00; % Henries
Lload_2C = Lnom*1.00; % Henries
Rload_2A = Rnom*1.00; % Ohms
Rload_2B = Rnom*1.00; % Ohms
Rload_2C = Rnom*1.00; % Ohms

X1A = 2*pi*fout*Lload_1A; % Ohm
X1B = 2*pi*fout*Lload_1B; % Ohm
X1C = 2*pi*fout*Lload_1C; % Ohm
X2A = 2*pi*fout*Lload_2A; % Ohm
X2B = 2*pi*fout*Lload_2B; % Ohm
X2C = 2*pi*fout*Lload_2C; % Ohm

Z1A = sqrt(Rload_1A^2+X1A^2); % Ohm
Z1B = sqrt(Rload_1B^2+X1B^2); % Ohm
Z1C = sqrt(Rload_1C^2+X1C^2); % Ohm
Z2A = sqrt(Rload_2A^2+X2A^2); % Ohm
Z2B = sqrt(Rload_2B^2+X2B^2); % Ohm
Z2C = sqrt(Rload_2C^2+X2C^2); % Ohm

pf1A = Rload_1A/Z1A;
pf1B = Rload_1B/Z1B;
pf1C = Rload_1C/Z1C;
pf2A = Rload_2A/Z2A;
pf2B = Rload_2B/Z2B;
pf2C = Rload_2C/Z2C;

ma1 = manom;

Pout = Pmodt*ns*np;
Rin = 5;
Rmid = 1e-3;
Cdcrec = 1.1e-3;
Vin = Vdc + (Rin+Rmid)*(Pout/Vdc);


%%
% Single module
% No parasitics
% Balanced load
% Rectifier added

Ts = 1e-6; % sec
Tfinal = 0.2; % sec
Ripth = 0.18; % sec
fsw = 10e3; % Hz
Vdc = 270; % Volts
fout = 50; % Hz
wout = 2*pi*fout; % rad/sec
m = 3;
np = 1;
ns = 1;
n = ns*np;
phase = [0 0 0 0];
Cdc = 15e-6;
delta = 0; % rad

% Calculate nominal values
Pmodt = 2e3;
pft = 0.9;
manom = 0.9;
Vdcnom = Vdc/ns;
Vllrmsnom = 0.612*manom*Vdcnom;
Vlnrms = Vllrmsnom/sqrt(3);
Smodt = Pmodt/pft;
Ilinemod = Smodt/(3*Vlnrms);
Znom = Vlnrms/Ilinemod;
Rnom = Znom*pft;
Xnom = sqrt(Znom^2-Rnom^2);
Lnom = Xnom/(2*pi*fout);

Lload_1A = Lnom*1.00; % Henries
Lload_1B = Lnom*1.00; % Henries
Lload_1C = Lnom*1.00; % Henries
Rload_1A = Rnom*1.00; % Ohms
Rload_1B = Rnom*1.00; % Ohms
Rload_1C = Rnom*1.50; % Ohms

Lload_2A = Lnom*1.00; % Henries
Lload_2B = Lnom*1.00; % Henries
Lload_2C = Lnom*1.00; % Henries
Rload_2A = Rnom*1.00; % Ohms
Rload_2B = Rnom*1.00; % Ohms
Rload_2C = Rnom*1.00; % Ohms

X1A = 2*pi*fout*Lload_1A; % Ohm
X1B = 2*pi*fout*Lload_1B; % Ohm
X1C = 2*pi*fout*Lload_1C; % Ohm
X2A = 2*pi*fout*Lload_2A; % Ohm
X2B = 2*pi*fout*Lload_2B; % Ohm
X2C = 2*pi*fout*Lload_2C; % Ohm

Z1A = sqrt(Rload_1A^2+X1A^2); % Ohm
Z1B = sqrt(Rload_1B^2+X1B^2); % Ohm
Z1C = sqrt(Rload_1C^2+X1C^2); % Ohm
Z2A = sqrt(Rload_2A^2+X2A^2); % Ohm
Z2B = sqrt(Rload_2B^2+X2B^2); % Ohm
Z2C = sqrt(Rload_2C^2+X2C^2); % Ohm

pf1A = Rload_1A/Z1A;
pf1B = Rload_1B/Z1B;
pf1C = Rload_1C/Z1C;
pf2A = Rload_2A/Z2A;
pf2B = Rload_2B/Z2B;
pf2C = Rload_2C/Z2C;

ma1 = manom;

Pout = Pmodt*ns*np;
Rin = 1;
Rmid = 4;
Vin = Vdc + (Rin+Rmid)*(Pout/Vdc);

% Rectifier parameters
Vacrms = 113 + 12; % Volts
GridPhase = 0; % deg
GridFreq = 50; % Hz
Cdcrec = 1.1e-3; % Farads
Rloadrec = Vdc^2/Pout; % Ohms

%%
%%
% 2-parallel modules
% No parasitics
% Balanced load
% Infinite bus

Ts = 1e-6; % sec
Tfinal = 0.2; % sec
Ripth = 0.18; % sec
fsw = 10e3; % Hz
Vdc = 270; % Volts
fout = 50; % Hz
wout = 2*pi*fout; % rad/sec
m = 3;
np = 2;
ns = 1;
n = ns*np;
phase = [0 180 0 0]; % for interleaving
Cdc = 15e-6;

% Calculate nominal values
Pmodt = 2e3;
pft = 0.9;
manom = 0.9;
Vdcnom = Vdc/ns;
Vllrmsnom = 0.612*manom*Vdcnom;
Vlnrms = Vllrmsnom/sqrt(3);
Smodt = Pmodt/pft;
Ilinemod = Smodt/(3*Vlnrms);
Znom = Vlnrms/Ilinemod;
Rnom = Znom*pft;
Xnom = sqrt(Znom^2-Rnom^2);
Lnom = Xnom/(2*pi*fout);

Lload_1A = Lnom*1.00; % Henries
Lload_1B = Lnom*1.00; % Henries
Lload_1C = Lnom*1.00; % Henries
Rload_1A = Rnom*1.00; % Ohms
Rload_1B = Rnom*1.00; % Ohms
Rload_1C = Rnom*1.00; % Ohms

Lload_2A = Lnom*1.00; % Henries
Lload_2B = Lnom*1.00; % Henries
Lload_2C = Lnom*1.00; % Henries
Rload_2A = Rnom*1.00; % Ohms
Rload_2B = Rnom*1.00; % Ohms
Rload_2C = Rnom*1.00; % Ohms

X1A = 2*pi*fout*Lload_1A; % Ohm
X1B = 2*pi*fout*Lload_1B; % Ohm
X1C = 2*pi*fout*Lload_1C; % Ohm
X2A = 2*pi*fout*Lload_2A; % Ohm
X2B = 2*pi*fout*Lload_2B; % Ohm
X2C = 2*pi*fout*Lload_2C; % Ohm

Z1A = sqrt(Rload_1A^2+X1A^2); % Ohm
Z1B = sqrt(Rload_1B^2+X1B^2); % Ohm
Z1C = sqrt(Rload_1C^2+X1C^2); % Ohm
Z2A = sqrt(Rload_2A^2+X2A^2); % Ohm
Z2B = sqrt(Rload_2B^2+X2B^2); % Ohm
Z2C = sqrt(Rload_2C^2+X2C^2); % Ohm

pf1A = Rload_1A/Z1A;
pf1B = Rload_1B/Z1B;
pf1C = Rload_1C/Z1C;
pf2A = Rload_2A/Z2A;
pf2B = Rload_2B/Z2B;
pf2C = Rload_2C/Z2C;

ma1 = manom;
ma2 = manom;
delta1 = 0; % rad
delta2 = 0; % rad

Pout = Pmodt*ns*np;
Rin = 50;
Rmid = 1e-3;
Vin = Vdc + (Rin+Rmid)*(Pout/Vdc);

