%%
% Control simulation Parameters
% V_by_f control trial

% Machine parameters
pole_pair = 10;
inertia = 0.0027; % kg.m^2
viscous_damping = 0.0005; % N.m.s
static_friction = 0; % N.m
rated_speed = 600e-3; % krpm
rated_Ef = 80; % Vph-rms
V_peak_L_L = rated_Ef*sqrt(2)*sqrt(3); % Vll-peak
voltage_constant = V_peak_L_L/rated_speed;
La = 3.5e-3; % H
Ra = 0.3; % Ohms
Tload = 30; % Nm
rotor_speed = rated_speed*2*pi/60*1e3;
Pmotor = Tload*rotor_speed;

% Simulation parameters
Ts = 1e-6; % sec
Tfinal = 1; % sec
Ripth = 0.08; % sec

% Converter parameters
Vdcm = 270;
fsw = 10e3; % Hz
fout = 100; % Hz
wout = 2*pi*fout; % rad/sec
m = 3;
np = 1;
ns = 1;
n = ns*np;
Cdc = 15e-6;
phase = [0];
Poutm = Pmotor/n; % Watts
Ef = rated_Ef;
Is = Poutm/(Ef*m); % amps
Xs = wout*La; % Ohms
Vdrop = Is*Xs; % Volts
Vt = sqrt(Ef^2+Vdrop^2); % Volts
ma = Vt*sqrt(3)/(Vdcm*0.612);
delta = acos(Ef/Vt); % radians
deltad = delta*180/pi; % degrees
pf = cos(delta);
Rin = 1;
Vdc = Vdcm*ns;
Pout = Poutm*n;
Vin = Vdc + Rin*(Pout/Vdc);

%%
% The following must be set



