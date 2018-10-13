% Calculation of short circuit current and/or required inductance

Ephm = 81; % Vrms (phase voltage)
Nr = 600; % rpm
p = 20;
fs = Nr*p/120; % Hz
Rs = 0.277; % Ohms
La = 0.78e-3; % H (IMMD)
Llk = 2.87e-3; % H (IMMD)
Ls = La + Llk; % H (IMMD)
Xs = 2*pi*fs*Ls; % Ohms
Zsc = sqrt(Rs^2+Xs^2); % Ohms
Isc = Ephm/Zsc;

Iphm = 8.5; % Arms
Iscreq = Iphm; % Arms
Zscreq = Ephm/Iscreq; % Ohms
Xscreq = sqrt(Zscreq^2-Rs^2); % Ohms
Lscreq = Xscreq/(2*pi*fs); % H

Vtm = sqrt(Ephm^2+(Xs*Iphm)^2)
pf = Ephm/Vtm;
delta = 180/pi*acos(pf);
Vtm2 = sqrt(Ephm^2+(Xscreq*Iphm)^2)
pf2 = Ephm/Vtm2;
delta2 = 180/pi*acos(pf2);

