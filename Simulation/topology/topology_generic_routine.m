np = 2;
ns = 2;
Load_Nominal_Freq = 50;
ref_frequency = 2*pi*Load_Nominal_Freq; %radians per sec
sw_frequency = 50050; %Hz
Sampling_time = 1/(10*sw_frequency); %sampling frequency of the model
%Fs = 0.5/Sampling_time;  %Sampling Frequency for the spectrum analysis  %5e-6 goes up to 50kHz band
stop_time = 1; %duration of the model
% Load&Source settings
Pout = 8000; %W
Poutm = Pout/(ns*np);
Ef = 155; % Vln
Efm = Ef/2;
Ls = 13.8e-3; % H
Lsm = Ls;
Vdc = 540; % Vdc
Vdcm = Vdc/ns; % V
Is = Poutm/(3*np*Efm); % Aline
Xs = ref_frequency*Lsm; % Ohm
Vtln = sqrt(Efm^2+(Xs*Is)^2); % Vln
Vtll = Vtln*sqrt(3); % Vll
ma = (Vtll)/(Vdcm*0.612);
delta = 180*atan(Xs*Is/Efm)/pi;
Load_Angle = delta*pi/180;
pf = cos(Load_Angle);

interleaving_angle = 360/np;
intangle1 = 0;
intangle2 = intangle1 + interleaving_angle;
intangle3 =intangle1;
intangle4 = intangle2;

Idcrms1 = Is*sqrt( 2*ma*(sqrt(3)/(4*pi) +...
    pf^2*(sqrt(3)/pi-9*ma/16)) ); % Amps

Vdcrip = 1;
Cdcreq1 = ns*(ma*Is/(16*sw_frequency*Vdcrip))*...
    sqrt( (6 - (96*sqrt(3)*ma)/(5*pi) +...
    (9*ma^2/2) )*pf^2 + (8*sqrt(3)*ma)/(5*pi) ); % Farads

% When no interleaving is used, the ripple voltage (or capacitance)
% can be directly multiplied by the number of parallel connected modules
%[intc,intv] = interleaving_effect(n,ns);
intc = 1;
intv = 1;
Idcrms = Idcrms1*np*intc; % Amps
Cdcreq = Cdcreq1*np*intv; % Amps
DCLINK_Cap = Cdcreq;

%capacitorsabiti = 200e-6*14000;
%DCLINK_Cap = capacitorsabiti/sw_frequency;
Rin = 1; %ohm
Vin = Vdc + Rin*(Pout/Vdc);

Ls = Lsm;
Ef = Efm;

%%
% Capacitor requirement vs topology (for all fsw)
Load_Nominal_Freq = 50;
ref_frequency = 2*pi*Load_Nominal_Freq; %radians per sec

% 2L-VSI
np = 1;
ns = 1;
fsw = 1000:1000:25000; %Hz
Pout = 8000; %W
Poutm = Pout/(ns*np);
Ef = 155; % Vln
Efm = Ef/2;
Ls = 13.8e-3; % H
Lsm = Ls/2;
Vdc = 540; % Vdc
Vdcm = Vdc/ns; % V
Is = Poutm/(3*np*Efm); % Aline
Xs = ref_frequency*Lsm; % Ohm
Vtln = sqrt(Efm^2+(Xs*Is)^2); % Vln
Vtll = Vtln*sqrt(3); % Vll
ma = (Vtll)/(Vdcm*0.612);
delta = 180*atan(Xs*Is/Efm)/pi;
Load_Angle = delta*pi/180;
pf = cos(Load_Angle);

Cdcreq1 = ns*(ma*Is./(16*fsw*Vdcrip))*...
    sqrt( (6 - (96*sqrt(3)*ma)/(5*pi) +...
    (9*ma^2/2) )*pf^2 + (8*sqrt(3)*ma)/(5*pi) ); % Farads
intv = 1;
Cdcreq_2LVSI = Cdcreq1*np*intv;


