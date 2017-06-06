% Design file for the conference EL-EN
% This file is associated with the simulation file:
% immd_design_elen_sim.slx

%%
% Design with motor
m = 3;
Q = 48;
layer = 2;
n = 4;
p = 40;
Pout = 8e3;
Poutm = Pout/n;
Nrated = 540;
length = 0.15;
Din = 0.15;
Dout = 0.23;
effmotor = 0.9;

w = Q/(n*m);
ffund = Nrated*p/120;
kw = 0.933;

Bgapa = 0.6;
Bgap = Bgapa*pi/2;
fluxpp = 2*Din*length*Bgap/p;

zQ = 24;
Nph = zQ*w*layer/2;
E = 4.44*Nph*ffund*fluxpp*kw;

Vdc = 540;
Vdcm = Vdc/2;

Vllrms = E*sqrt(3);
scale = sqrt(3)/(2*sqrt(2));
ma = Vllrms/(scale*Vdcm);

Pdrout = Poutm/effmotor;
pf = 0.9;
Sdrout = Pdrout/pf;
Iphase = Sdrout/(sqrt(3)*Vllrms);


%%
% Simulation parameters

% Number of modules
n = 4;
% Step time
Ts = 1e-6; % sec
% Modulation index
ma = 1;
% Switching frequency
fsw = 10e3; % Hz
% DC link voltage
Vdc = 540; % Volts
% Load
Ptotal = 8e3; % W
Pout = Ptotal/n; % W
pf = 0.9;
Sout = Pout/pf; % VA
fout = 50; % Hz
wout = 2*pi*fout; % rad/sec
Vll_rms = ma*Vdc*0.612; % Volts
Iline = Sout/(Vll_rms*sqrt(3)); % Amps
Zload = Vll_rms/(Iline*sqrt(3)); % Ohms
Rload = Zload*pf; % Ohms
Xload = sqrt(Zload^2-Rload^2); % Ohms
Lload = Xload/wout; % Henries
phase = 0:90:270;

%%
% Run the simulation
sim('immd_design_elen_sim.slx');


%%
% Design and simulation with series connected modules

% Number of modules
n = 2;
ns = 2;
np = n/ns;
% Step time
Ts = 1e-6; % sec
% Modulation index
ma = 0.9;
% Switching frequency
fsw = 1e3; % Hz
% DC link voltage
Vdc = 540; % Volts
Vdcm = Vdc/ns;
% Load
Ptotal = 8e3; % W
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
phase = [0 0 0 0];


%%
% Run the simulation
sim('immd_design_elen_sim2.slx');

%%
Irmss = Iline*sqrt(2*ma*(sqrt(3)/(4*pi) + pf^2*(sqrt(3)/pi-9*ma/16)))
Idcc = (3/(2*sqrt(2))).*ma.*Iline*pf/0.999
Irmss/Idcc


%%
% Get parameters
Irms = Icrms(numel(Icrms));
Idc = Icdc(numel(Icdc));

% Calculation
Irms_perc = 100*Irms./Idc;


%%
% module phase shift effect on RMS current
Icrms = n*Iline*sqrt(2*ma*(sqrt(3)/(4*pi) + pf^2*(sqrt(3)/pi-9*ma/16)));
perc_an = 100*Icrms/Idc;

rmscp = [53.12 34.97 20.95 18.21 11.12 12.92 8.6 8.9]
module = 1:8
rmsc = rmscp*Idc/100

figure;
plot(module,rmsc,'bo-','Linewidth',1.5);
grid on;
set(gca,'FontSize',12);
xlabel('Number of modules','FontSize',12,'FontWeight','Bold')
ylabel('DC Link RMS Current (%)','FontSize',12,'FontWeight','Bold')

katsayi = rmsc/rmsc(1)
%katsayi2 = katsayi.*n.^(3/2)
k1 = 0.83;
k2 = 0.1;
myfunc = k1.^(module/0.6)+k2

figure;
plot(module,katsayi,'bo-','Linewidth',1.5);
hold on;
plot(module,myfunc,'ro-','Linewidth',1.5);
hold off;
grid on;
set(gca,'FontSize',12);
xlabel('Number of modules','FontSize',12,'FontWeight','Bold')
ylabel('DC Link RMS Current (%)','FontSize',12,'FontWeight','Bold')

%%
X = module';
Y = katsayi';
FO = fit(X, Y, 'poly2');
y = feval(FO,X)
figure;
plot(module,katsayi,'bo-','Linewidth',1.5);
hold on;
plot(module,y,'ro-','Linewidth',1.5);
hold off;
grid on;
set(gca,'FontSize',12);
xlabel('Number of modules','FontSize',12,'FontWeight','Bold')
ylabel('DC Link RMS Current (%)','FontSize',12,'FontWeight','Bold')

