%%
% This file is the base .m file for the verification simulations carried
% out on Simulink
% This verification is used for optimization (PEMD) purposes

%%
% Design and simulation with single module
%for k = 1:20

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
%pf = 0.7+k*0.02;
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
% Input for DC bus
Rin = 10;
Vin = Vdc + Rin*(Ptotal/Vdc);
Cdc = 100e-6;
% Simulation parameters
Tmax = 0.05; % s
Tth = 0.04; % s

% Simulation call
sim('verify_voltrip.slx')

% Simulation outputs
Poutsim1 = Poutsim(end);
pfsim1 = pfsim(end);
Vdcsim1 = Vdcsim(end);
Irmssim1 = Irmssim(end);
Vripsim1 = Vripsim(end)


% Analytical calculations
Irms1 = Iline*sqrt( 2*ma*(sqrt(3)/(4*pi) +...
    pf^2*(sqrt(3)/pi-9*ma/16)) );
multip = sqrt( (6 - (96*sqrt(3)*ma)/(5*pi) +...
    (9*ma^2/2) )*pf^2 + (8*sqrt(3)*ma)/(5*pi) );
Vrip1 = ma*Iline*multip/(16*fsw*Cdc)
Vrip1 = Vrip1*Vdc/100

% Verification
Poutsim1;
pfsim1;
Vdcsim1;
Irmssim1/Irms1;
Vripsim1/Vrip1;

%end

%%
% Design and simulation with series connected modules

%for k = 1:30

% Number of modules
n = 2;
ns = 2;
np = n/ns;
% Step time
Ts = 1e-6; % sec
% Modulation index
ma = 0.9;
% Switching frequency
fsw = 10e3; % Hz
% DC link voltage
Vdc = 540; % Volts
Vdcm = Vdc/ns;
% Load
effmotor = 0.94;
%pf = 0.7+k*0.02;
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
% Interleaving angle
phase = [0 0 0];
% Input for DC bus
Rin = 10;
Vin = Vdc + Rin*(Ptotal/Vdc);
Cdc = 200e-6;
% Simulation parameters
Tmax = 0.05; % s
Tth = 0.04; % s

% Simulation call
sim('verify_voltrip_series.slx')

% Simulation outputs
Poutsima1 = Poutsima(end)
pfsima1 = pfsima(end)
Poutsimb1 = Poutsimb(end)
pfsimb1 = pfsimb(end)
%Poutsimc1 = Poutsimc(end)
%pfsimc1 = pfsimc(end)
Vdcsim1 = Vdcsim(end)
Vdcsima1 = Vdcsima(end)
Vdcsimb1 = Vdcsimb(end)
%Vdcsimc1 = Vdcsimc(end)
fprintf('\n');

% Simulation rms currents
%Irmssima1 = Irmssima(end);
%Irmssimb1 = Irmssimb(end);

% simulation ripple voltages
Vripsim1 = Vripsim(end);
Vripsima1 = Vripsima(end);
Vripsimb1 = Vripsimb(end);
%Vripsimc1 = Vripsimc(end);
Vripap = Vripsima1/Vdcsima1*100
Vripbp = Vripsimb1/Vdcsimb1*100
%Vripcp = Vripsimc1/Vdcsimc1;

% Analytical calculations
Irms1 = Iline*sqrt( 2*ma*(sqrt(3)/(4*pi) +...
    pf^2*(sqrt(3)/pi-9*ma/16)) );
multip = sqrt( (6 - (96*sqrt(3)*ma)/(5*pi) +...
    (9*ma^2/2) )*pf^2 + (8*sqrt(3)*ma)/(5*pi) );
Vrip1 = ns*ma*Iline*multip/(16*fsw*Cdc)

% Verification
% Vripsim1
% Vripp = Vripsim1/Vdc*100
% Vripsima1
% Vripm = Vripsima1/Vdcm*100

%Vripp = Vripsim1/Vdc*100
%Vripm = Vripsima1/Vdcm*100

%Vrip2 = Vrip1*Vdc/100
%Vripcp = Vrip1

%Irmssima1/Irms1
%Vripsim1/Vrip2

%end



%%
% Design and simulation with parallel connected modules

for k = 1:37

% Number of modules
n = 4;
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
%pf = 0.7+k*0.02;
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
% Interleaving angle
phase = [0 (k-1)*10 (k-1)*20 (k-1)*30];
% Input for DC bus
Rin = 10;
Vin = Vdc + Rin*(Ptotal/Vdc);
Cdc = 50e-6;
% Simulation parameters
Tmax = 0.05; % s
Tth = 0.04; % s

% Simulation call
sim('verify_voltrip_parallel.slx')

% Simulation outputs
Poutsima1 = Poutsima(end)
pfsima1 = pfsima(end)
Poutsimb1 = Poutsimb(end)
pfsimb1 = pfsimb(end)
Poutsimc1 = Poutsimc(end)
pfsimc1 = pfsimc(end)
Poutsimd1 = Poutsimd(end)
pfsimd1 = pfsimd(end)
Vdcsim1 = Vdcsim(end)
fprintf('\n');

% Simulation rms currents
% Irmssima1 = Irmssima(end)
% Irmssimb1 = Irmssimb(end)
% Irmssimc1 = Irmssimc(end)
% Icrmssim1 = Icrmssim(end)
(k-1)*10
% simulation ripple voltages
Vripsim1(k) = Vripsim(end)
Vripp(k) = Vripsim1(k)/Vdcsim1*100;
multip = sqrt( (6 - (96*sqrt(3)*ma)/(5*pi) +...
     (9*ma^2/2) )*pf^2 + (8*sqrt(3)*ma)/(5*pi) );
Vrip1 = np*ma*Iline*multip/(16*fsw*Cdc);

Icrmssim1(k) = Icrmssim(end)
Irmssima1(k) = Irmssima(end);

% Analytical calculations
Irms1 = np*Iline*sqrt( 2*ma*(sqrt(3)/(4*pi) +...
    pf^2*(sqrt(3)/pi-9*ma/16)) );

Icrmssim1/Irms1;
Vripp/Vrip1;

end

%%
anglea = 0:10:360;
figure;
plot(anglea,Vripsim1,'bo-','Linewidth',2);
hold on;
%plot(anglea,Irmssima1,'ro-','Linewidth',2);
%hold on;
plot(anglea,Icrmssim1,'ko-','Linewidth',2);
hold off;
grid on;
set(gca,'FontSize',12);
xlabel('Interleaving angle','FontSize',12,'FontWeight','Bold')
ylabel('Ripple voltage (V), RMS current (A)','FontSize',12,'FontWeight','Bold')
ylim([0 15]);
legend('Ripple Voltage','Ripple Current');

%%
anglea = 0:10:500;
figure;
plot(anglea,datak1,'bo-','Linewidth',2);
hold on;
plot(anglea,datak2,'ro-','Linewidth',2);
hold off;
grid on;
set(gca,'FontSize',12);
% xlabel('Switching frequency (kHz)','FontSize',12,'FontWeight','Bold')
% ylabel('Capacitance requirement (uF)','FontSize',12,'FontWeight','Bold')
ylim([0 10])

