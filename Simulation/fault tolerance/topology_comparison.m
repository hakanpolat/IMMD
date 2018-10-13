% Design and Simulation with IGBT

% 3-phase half-bridge
Vdc = 270; % Volts
Pout = 10e3; % W
m = 3;
n = 4;
Ephm = 80; % Volts
Poutm = Pout/n; % Watts
Iphm = Poutm/(Ephm*m); % amps
pf = 0.95;
Vphm = Ephm/pf; % Volts
NoT = 2*n*m;
Vt = Vphm;
It = Iphm;
kVAs = Vt*It;
kVAt = kVAs*n*m*2;
kVAn = kVAt/Pout;
STF = (n-1)/n*100
DTF = (n-2)/n*100


% 3-phase full-bridge
Vdc = 270; % Volts
Pout = 10e3; % W
m = 3;
n = 4;
Ephm = 80; % Volts
Poutm = Pout/n; % Watts
Iphm = Poutm/(Ephm*m); % amps
pf = 0.95;
Vphm = Ephm/pf; % Volts
NoT = 4*n*m;
Vt = Vphm;
It = Iphm;
kVAs = Vt*It;
kVAt = kVAs*n*m*2;
kVAn = kVAt/Pout;
STF = (n*m-1)/(n*m)*100
DTF = (n*m-2)/(n*m)*100



% 4-phase half-bridge
Vdc = 270; % Volts
Pout = 10e3; % W
m = 4;
n = 3;
Ephm = 80; % Volts
Poutm = Pout/n; % Watts
Iphm = Poutm/(Ephm*m); % amps
pf = 0.95;
Vphm = Ephm/pf; % Volts
NoT = 2*n*m;
Vt = Vphm;
It = Iphm;
kVAs = Vt*It;
kVAt = kVAs*n*m*2;
kVAn = kVAt/Pout;
STF = (n*m-1)/(n*m)*100
DTF = (n*m-2)/(n*m)*100


