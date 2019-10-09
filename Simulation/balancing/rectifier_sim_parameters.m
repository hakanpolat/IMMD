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
phase = [0 90 0 90];
Cdc = 15e-6;
delta = 0; % rad

% calculate nominal values
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

ma1 = 0.9;

Pout = Pmodt;
Rin = 10;
Rmid = 0.1;
Lmid = 1e-3;
Cdcrec = 1.1e-3;
ESLrec = 100e-9;
ESRrec = 10e-3;
Vin = Vdc + (Rin+Rmid)*(Pout/Vdc);

GridFreq = 50;
GridPhase = 5.5;
Vacrms = 120;
Voutdcrec = Vacrms*sqrt(2)*sqrt(3);
Poutrec = Pmodt;
Ioutrec = Poutrec/Voutdcrec;
Rloadrec = Voutdcrec/Ioutrec;

% 3rd harmonic injection
ma_third = 0.5;
f_third = 150;
delta_third = 0*pi/180;


%% Some trials
SA_ma1 = 0.9;
SA_f1 = 150;
SA_delta1 = 0*pi/180;
SA_ma3 = 0.2;
SA_f3 = 150;
SA_delta3 = 0*pi/180;
SB_delta3 = 0*pi/180;
SC_delta3 = 0*pi/180;
Is1_f = 150;
Is3_f = 150;
third = 1;
Isa1 = 5;
Isa3 = third;
Isb1 = 5;
Isb3 = third;
Isc1 = 5;
Isc3 = third;
Isa1_delta = 0*pi/180;
Isb1_delta = -120*pi/180;
Isc1_delta = 120*pi/180;
Isa3_delta = 0*pi/180;
Isb3_delta = 0*pi/180;
Isc3_delta = 0*pi/180;

