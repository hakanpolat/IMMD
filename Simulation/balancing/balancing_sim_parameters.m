% Induced Voltage
Ts = 1e-7; % sec
Tfinal = 0.1; % sec
Ripth = 0.08; % sec
fsw = 40e3; % Hz
Vdc = 540; % Volts
fout = 50; % Hz
wout = 2*pi*fout; % rad/sec
m = 3;
np = 1;
ns = 2;
n = ns*np;
phase = [0 90 0 90];
Cdc = 15e-6;
Ls = 10e-3; % Henries
Rs = 1e-3; % Ohms
Xs = wout*Ls; % Ohms

Ef1A = 80;
Ef1B = Ef1A;
Ef1C = Ef1A;
Ef2A = 90;
Ef2B = Ef2A;
Ef2C = Ef2A;

Ef1A_ph = 0;
Ef1B_ph = Ef1A_ph - 120;
Ef1C_ph = Ef1A_ph + 120;
Ef2A_ph = 0;
Ef2B_ph = Ef2A_ph - 120;
Ef2C_ph = Ef2A_ph + 120;

Ef1_avg = mean([Ef1A,Ef1B,Ef1C]);
Ef2_avg = mean([Ef2A,Ef2B,Ef2C]);

Poutm1 = 2e3;
Is1 = Poutm1/(Ef1_avg*m);
Vdrop1 = Is1*Xs; % Volts
Vt1 = sqrt(Ef1_avg^2+Vdrop1^2); % Volts
Vdcm1 = Vdc/ns; % volts
ma1 = Vt1*sqrt(3)/(Vdcm1*0.612);
delta1 = acos(Ef1_avg/Vt1); % radians
deltad1 = delta1*180/pi; % degrees
pf1 = cos(delta1);
Soutm1 = Poutm1/pf1;
Qoutm1 = sqrt(Soutm1^2-Poutm1^2);

Poutm2 = 2e3;
Is2 = Poutm2/(Ef2_avg*m);
Vdrop2 = Is2*Xs; % Volts
Vt2 = sqrt(Ef2_avg^2+Vdrop2^2); % Volts
Vdcm2 = Vdc/ns; % volts
ma2 = Vt2*sqrt(3)/(Vdcm2*0.612);
delta2 = acos(Ef2_avg/Vt2); % radians
deltad2 = delta2*180/pi; % degrees
pf2 = cos(delta2);
Soutm2 = Poutm2/pf2;
Qoutm2 = sqrt(Soutm2^2-Poutm2^2);

Pout = Poutm1 + Poutm2;
Rin = 70;
Vin = Vdc + Rin*(Pout/Vdc);

% Pcalc1 = 3*Vt1*Ef1_avg*sin(delta1)/Xs
% Qcalc1 = 3*(Vt1^2-Vt1*Ef1_avg*cos(delta1))/Xs
% Pcalc2 = 3*Vt2*Ef2_avg*sin(delta2)/Xs
% Qcalc2 = 3*(Vt2^2-Vt2*Ef2_avg*cos(delta2))/Xs
% 
% calc_rat1 = ma1*sin(delta1) / (ma2*sin(delta2))
% calc_rat2 = Ef2_avg/Ef1_avg
% 
% ma1/ma2
% sin(delta1)/sin(delta2)



%% Series RL Load
Ts = 1e-7; % sec
Tfinal = 0.05; % sec
Ripth = 0.04; % sec
fsw = 40e3; % Hz
Vdc = 540; % Volts
fout = 50; % Hz
wout = 2*pi*fout; % rad/sec
m = 3;
np = 1;
ns = 2;
n = ns*np;
phase = [0 90 0 90];
Cdc = 15e-6;
delta = 0; % deg

% calculate nominal values
Pmodt = 2e3;
pft = 0.9;
manom = 0.9;
Vdcnom = Vdc/2;
Vllrmsnom = 0.612*manom*Vdcnom;
Vlnrms = Vllrmsnom/sqrt(3);
Smodt = Pmodt/pft;
Ilinemod = Smodt/(3*Vlnrms);
Znom = Vlnrms/Ilinemod;
Rnom = Znom*pft;
Xnom = sqrt(Znom^2-Rnom^2);
Lnom = Xnom/(2*pi*fout);

% balanced load
% Lload_1A = Lnom; % Henries
% Lload_1B = Lnom; % Henries
% Lload_1C = Lnom; % Henries
% Rload_1A = Rnom; % Ohms
% Rload_1B = Rnom; % Ohms
% Rload_1C = Rnom; % Ohms
% Lload_2A = Lnom; % Henries
% Lload_2B = Lnom; % Henries
% Lload_2C = Lnom; % Henries
% Rload_2A = Rnom; % Ohms
% Rload_2B = Rnom; % Ohms
% Rload_2C = Rnom; % Ohms

% unbalanced load
Lload_1A = Lnom*1.00; % Henries
Lload_1B = Lnom*1.00; % Henries
Lload_1C = Lnom*1.00; % Henries
Rload_1A = Rnom*1.20; % Ohms
Rload_1B = Rnom*1.20; % Ohms
Rload_1C = Rnom*1.20; % Ohms

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

% No balancing
ma1 = 0.9;
ma2 = 0.9;

% Balancing
Rload1 = Rload_1A;
Rload2 = Rload_2A;
pf1 = pf1A;
pf2 = pf2A;
ratioma = sqrt(Rload1/Rload2)*(pf2/pf1);
ma2 = 0.9;
ma1 = ma2*ratioma;

ratio_R = mean([Rload_2A,Rload_2B,Rload_2C])/mean([Rload_1A,Rload_1B,Rload_1C]);
ratio_pf = mean([pf1A,pf1B,pf1C])^2/mean([pf2A,pf2B,pf2C])^2;
ratio_ma = (ma1/ma2)^2;
ratio = ratio_ma*ratio_pf*ratio_R;
Vdc1 = Vdc/(ratio+1);
Vdc2 = Vdc-Vdc1;
V1 = 0.612*ma1*Vdc1/sqrt(3);
I1 = V1/mean([Z1A,Z1B,Z1C]);
S1 = 3*V1*I1;
P1 = S1*mean([pf1A,pf1B,pf1C]);
V2 = 0.612*ma2*Vdc2/sqrt(3);
I2 = V2/mean([Z2A,Z2B,Z2C]);
S2 = 3*V2*I2;
P2 = S2*mean([pf2A,pf2B,pf2C]);

Pout = P1 + P2;

Rin = 70;
Vin = Vdc + Rin*(Pout/Vdc)+3;

%% Parallel RL Load
Ts = 1e-7; % sec
Tfinal = 0.05; % sec
Ripth = 0.04; % sec
fsw = 40e3; % Hz
Vdc = 270; % Volts
fout = 50; % Hz
wout = 2*pi*fout; % rad/sec
m = 3;
np = 2;
ns = 1;
n = ns*np;
phase = [0 90 0 90];
Cdc = 15e-6;
delta = 0; % deg

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

% balanced load
% Lload_1A = Lnom; % Henries
% Lload_1B = Lnom; % Henries
% Lload_1C = Lnom; % Henries
% Rload_1A = Rnom; % Ohms
% Rload_1B = Rnom; % Ohms
% Rload_1C = Rnom; % Ohms
% Lload_2A = Lnom; % Henries
% Lload_2B = Lnom; % Henries
% Lload_2C = Lnom; % Henries
% Rload_2A = Rnom; % Ohms
% Rload_2B = Rnom; % Ohms
% Rload_2C = Rnom; % Ohms

% unbalanced load
Lload_1A = Lnom*1.20; % Henries
Lload_1B = Lnom*1.20; % Henries
Lload_1C = Lnom*1.20; % Henries
Rload_1A = Rnom*1.20; % Ohms
Rload_1B = Rnom*1.20; % Ohms
Rload_1C = Rnom*1.20; % Ohms

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

% No balancing
ma1 = 0.9;
ma2 = 0.9;

% Balancing
% Rload1 = Rload_1A;
% Rload2 = Rload_2A;
% pf1 = pf1A;
% pf2 = pf2A;
% ratioma = sqrt(Rload1/Rload2)*(pf2/pf1);
% ma2 = 0.9;
% ma1 = ma2*ratioma;

% ratio_R = mean([Rload_2A,Rload_2B,Rload_2C])/mean([Rload_1A,Rload_1B,Rload_1C]);
% ratio_pf = mean([pf1A,pf1B,pf1C])^2/mean([pf2A,pf2B,pf2C])^2;
% ratio_ma = (ma1/ma2)^2;
% ratio = ratio_ma*ratio_pf*ratio_R;
Vdc1 = Vdc;
Vdc2 = Vdc1;
V1 = 0.612*ma1*Vdc1/sqrt(3);
I1 = V1/mean([Z1A,Z1B,Z1C]);
S1 = 3*V1*I1;
P1 = S1*mean([pf1A,pf1B,pf1C]);
V2 = 0.612*ma2*Vdc2/sqrt(3);
I2 = V2/mean([Z2A,Z2B,Z2C]);
S2 = 3*V2*I2;
P2 = S2*mean([pf2A,pf2B,pf2C]);

Pout = P1 + P2;

Rin = 70;
Vin = Vdc + Rin*(Pout/Vdc)+3;

%% Series RL Load with rectifier
Ts = 1e-7; % sec
Tfinal = 0.1; % sec
Ripth = 0.18; % sec
fsw = 40e3; % Hz
Vdc = 540; % Volts
fout = 50; % Hz
wout = 2*pi*fout; % rad/sec
m = 3;
np = 1;
ns = 2;
n = ns*np;
phase = [0 90 0 90];
Cdc = 15e-6;
delta = 0; % deg

% calculate nominal values
Pmodt = 2e3;
pft = 0.9;
manom = 0.9;
Vdcnom = Vdc/2;
Vllrmsnom = 0.612*manom*Vdcnom;
Vlnrms = Vllrmsnom/sqrt(3);
Smodt = Pmodt/pft;
Ilinemod = Smodt/(3*Vlnrms);
Znom = Vlnrms/Ilinemod;
Rnom = Znom*pft;
Xnom = sqrt(Znom^2-Rnom^2);
Lnom = Xnom/(2*pi*fout);

% balanced load
% Lload_1A = Lnom; % Henries
% Lload_1B = Lnom; % Henries
% Lload_1C = Lnom; % Henries
% Rload_1A = Rnom; % Ohms
% Rload_1B = Rnom; % Ohms
% Rload_1C = Rnom; % Ohms
% Lload_2A = Lnom; % Henries
% Lload_2B = Lnom; % Henries
% Lload_2C = Lnom; % Henries
% Rload_2A = Rnom; % Ohms
% Rload_2B = Rnom; % Ohms
% Rload_2C = Rnom; % Ohms

% unbalanced load
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

% No balancing
ma1 = 0.9;
ma2 = 0.9;

% Balancing
% Rload1 = Rload_1A;
% Rload2 = Rload_2A;
% pf1 = pf1A;
% pf2 = pf2A;
% ratioma = sqrt(Rload1/Rload2)*(pf2/pf1);
% ma2 = 0.9;
% ma1 = ma2*ratioma;

ratio_R = mean([Rload_2A,Rload_2B,Rload_2C])/mean([Rload_1A,Rload_1B,Rload_1C]);
ratio_pf = mean([pf1A,pf1B,pf1C])^2/mean([pf2A,pf2B,pf2C])^2;
ratio_ma = (ma1/ma2)^2;
ratio = ratio_ma*ratio_pf*ratio_R;
Vdc1 = Vdc/(ratio+1);
Vdc2 = Vdc-Vdc1;
V1 = 0.612*ma1*Vdc1/sqrt(3);
I1 = V1/mean([Z1A,Z1B,Z1C]);
S1 = 3*V1*I1;
P1 = S1*mean([pf1A,pf1B,pf1C]);
V2 = 0.612*ma2*Vdc2/sqrt(3);
I2 = V2/mean([Z2A,Z2B,Z2C]);
S2 = 3*V2*I2;
P2 = S2*mean([pf2A,pf2B,pf2C]);

Pout = P1 + P2;



% Pout = Pmodt;
 Rin = 0;
 Rmid = 4;
 Cdcrec = 4e-3;
Voutdcrec = Vdc + Rmid*(Pout/Vdc);
Vacrms=230;
% 
 GridFreq = 50;
% Vacrms = Voutdcrec*2*pi/(3*sqrt(6));
 
% Voutdcrec = Vacrms*sqrt(2)*sqrt(3);
% Poutrec = Pmodt;
% Ioutrec = Poutrec/Voutdcrec;
% Rloadrec = Voutdcrec/Ioutrec;

%% Parallel RL Load with rectifier
Ts = 1e-7; % sec
Tfinal = 0.1; % sec
Ripth = 0.18; % sec
fsw = 40e3; % Hz
Vdc = 270; % Volts
fout = 50; % Hz
wout = 2*pi*fout; % rad/sec
m = 3;
np = 2;
ns = 1;
n = ns*np;
phase = [0 90 0 90];
Cdc = 15e-6;
delta = 0; % deg

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

% balanced load
% Lload_1A = Lnom; % Henries
% Lload_1B = Lnom; % Henries
% Lload_1C = Lnom; % Henries
% Rload_1A = Rnom; % Ohms
% Rload_1B = Rnom; % Ohms
% Rload_1C = Rnom; % Ohms
% Lload_2A = Lnom; % Henries
% Lload_2B = Lnom; % Henries
% Lload_2C = Lnom; % Henries
% Rload_2A = Rnom; % Ohms
% Rload_2B = Rnom; % Ohms
% Rload_2C = Rnom; % Ohms

% unbalanced load
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

% No balancing
ma1 = 0.9;
ma2 = 0.9;

% Balancing
% Rload1 = Rload_1A;
% Rload2 = Rload_2A;
% pf1 = pf1A;
% pf2 = pf2A;
% ratioma = sqrt(Rload1/Rload2)*(pf2/pf1);
% ma2 = 0.9;
% ma1 = ma2*ratioma;

% ratio_R = mean([Rload_2A,Rload_2B,Rload_2C])/mean([Rload_1A,Rload_1B,Rload_1C]);
% ratio_pf = mean([pf1A,pf1B,pf1C])^2/mean([pf2A,pf2B,pf2C])^2;
% ratio_ma = (ma1/ma2)^2;
% ratio = ratio_ma*ratio_pf*ratio_R;
Vdc1 = Vdc;
Vdc2 = Vdc1;
V1 = 0.612*ma1*Vdc1/sqrt(3);
I1 = V1/mean([Z1A,Z1B,Z1C]);
S1 = 3*V1*I1;
P1 = S1*mean([pf1A,pf1B,pf1C]);
V2 = 0.612*ma2*Vdc2/sqrt(3);
I2 = V2/mean([Z2A,Z2B,Z2C]);
S2 = 3*V2*I2;
P2 = S2*mean([pf2A,pf2B,pf2C]);

Pout = P1 + P2;



% Pout = Pmodt;
 Rin = 0;
 Rmid = 4;
 Cdcrec = 4e-3;
Voutdcrec = Vdc + Rmid*(Pout/Vdc);
Vacrms=140;
% 
 GridFreq = 50;
% Vacrms = Voutdcrec*2*pi/(3*sqrt(6));
 
% Voutdcrec = Vacrms*sqrt(2)*sqrt(3);
% Poutrec = Pmodt;
% Ioutrec = Poutrec/Voutdcrec;
% Rloadrec = Voutdcrec/Ioutrec;