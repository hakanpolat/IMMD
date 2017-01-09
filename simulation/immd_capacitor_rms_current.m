%% Capacitor Analytical RMS
M = 0.5;
cosphi = 0.9;
module = 4;
phase_dif = 90; % degrees

Vdc = 400; % Volts
Pout1 = 2e3; % W
Sout1 = Pout/(cosphi); % VA
Vll_rms = Vdc*0.612*M; % Volts
Iline = Sout1/(Vll_rms*sqrt(3)); % Amps
efficiency = 0.99;

Icrms = (0.275)*module*Iline*sqrt(2*M*(sqrt(3)/(4*pi) + cosphi^2*(sqrt(3)/pi-9*M/16)));
Idc = module*(3/(2*sqrt(2)))*M*Iline*cosphi/efficiency;
Icrms_perc = 100*Icrms/Idc;



%%
% 0.612 = sqrt(3/2)/2


%% Capacitor Selection
% Aluminium Electolytic

% Capacitance
% Rated voltage
% Iac_r (T,f)
% ESR (T,f)
% ESL
% Lifetime (T,Iac_r)
% Volume = D*L
% Rth_ca
% Weight


%%

% Inputs
M = 0.5;
cosphi = 0.9;
Vdc = 400; % V
module = 4;
phase_dif = 90; % degrees
Pout1 = 2e3; % W
Sout1 = Pout1/(cosphi); % VA
Vll_rms = Vdc*0.612*M; % V
Iarms = Sout1/(Vll_rms*sqrt(3)); % A
Iapeak = Iarms*sqrt(2); % A
efficiency = 0.99;
Tambient = 30; % C

% Constraints
perc_ripple_c = 3; % percent
volt_ripple_c = perc_ripple_c*0.01*Vdc; % V
temp_max = 80; % C
power_density_min = 100; % W/cm^3
height_max = 50; % mm
weight_max = 30; % g

% Select switching frequency
fsw = 100e3; % Hz

% Block 1 - RMS current
Icrms = (0.275)*module*Iarms*sqrt(2*M*(sqrt(3)/(4*pi) + cosphi^2*(sqrt(3)/pi-9*M/16)));
Idc = module*(3/(2*sqrt(2)))*M*Iarms*cosphi/efficiency;
Icrms_perc = 100*Icrms/Idc;

% Block 2 - Charging current
Icharge = module*Iapeak - Idc;
%volt_ripple = Icharge*0.5*M/(fsw*C);
Cap = Icharge*0.5*M/(volt_ripple_c*fsw); % F
%Cap = ceil(C*1e4)*1e-4; % F

% Datasheet parameters (electrolytic)
% http://www.farnell.com/datasheets/1792285.pdf
Capacitance = 220e-6; % F
Diameter = 25; % mm
Length = 45; % mm
ESR_100_20 = 0.4; % Ohm
Iacmax_100_60 = 3.02; % A
Iacmax_100_85 = 2.32; % A
Rth = 20.19; % C/W
ESR_20 = ESR_100_20*0.7; % Ohm
ESR_80 = ESR_100_20*0.4; % Ohm
Iacmax_60 = Iacmax_100_60*1.37; % A
Iacmax_85 = Iacmax_100_85*1.37; % A
weight = 25; % g

Okey = zeros(1,5);

if Capacitance > Cap
    Okey(1) = 1;
end

Tcore = (Tambient+Icrms^2*Rth*0.32)/(1+Icrms^2*Rth*0.002); % C
ESR = 0.32-0.002*Tcore; % Ohm
Ploss = Icrms^2*ESR; % W
Iac_max = 4.7 - 0.028*Tcore; % A

if Iac_max > Icrms
    Okey(2) = 1;
end

if temp_max > Tcore
    Okey(3) = 1;
end

if height_max > Length
    Okey(4) = 1;
end

volume = pi*(Diameter/2)^2*Length*1e-3; % cm^3
power_density = Pout/volume; % W/cm^3

if power_density > power_density_min
    Okey(5) = 1;
end


%%
% Datasheet parameters (film)
% http://www.farnell.com/datasheets/1794158.pdf
series = 2;
parallel = 6;
Capacitance1 = 60e-6; % F
Capacitance = Capacitance1*(parallel/series); % F

%%
Width = 35; % mm
Length = 45; % mm
ESR_100_20 = 0.4; % Ohm
Iacmax_100_60 = 3.02; % A
Iacmax_100_85 = 2.32; % A
Rth = 20.19; % C/W
ESR_20 = ESR_100_20*0.7; % Ohm
ESR_80 = ESR_100_20*0.4; % Ohm
Iacmax_60 = Iacmax_100_60*1.37; % A
Iacmax_85 = Iacmax_100_85*1.37; % A
weight = 25; % g

Okey = zeros(1,5);

if Capacitance > Cap
    Okey(1) = 1;
end

Tcore = (Tambient+Icrms^2*Rth*0.32)/(1+Icrms^2*Rth*0.002); % C
ESR = 0.32-0.002*Tcore; % Ohm
Ploss = Icrms^2*ESR; % W
Iac_max = 4.7 - 0.028*Tcore; % A

if Iac_max > Icrms
    Okey(2) = 1;
end

if temp_max > Tcore
    Okey(3) = 1;
end

if height_max > Length
    Okey(4) = 1;
end

volume = pi*(Diameter/2)^2*Length*1e-3; % cm^3
power_density = Pout/volume; % W/cm^3

if power_density > power_density_min
    Okey(5) = 1;
end


%%
% Frequency factor of permissible ripple current Iac
freq1 = [50,60,70,80,90,100,200,300,400,500,600,700,800,900,1000,2000];
Iac_factor = [0.88,0.91,0.94,0.96,0.98,1,1.12,1.19,1.24,1.27,1.3,1.315,1.325,1.34,1.35,1.37];

num = numel(freq1);
N = 4;
P = polyfit(freq1,Iac_factor,N);
Iac_factor2 = zeros(1,num);

for k = 1:N+1
    Iac_factor2 = Iac_factor2+P(k)*freq1.^(N-k+1);
end

figure;
plot(freq1,Iac_factor,'ro-','Linewidth',1.5);
hold on;
plot(freq1,Iac_factor2,'bo-','Linewidth',1.5);
hold off;
grid on;
set(gca,'FontSize',12);
xlabel('Frequency','FontSize',12,'FontWeight','Bold')
ylabel('Iac factor','FontSize',12,'FontWeight','Bold')

%%
Iacc = 0;
frequency = 10:10:2000;
for k = 1:N+1
    Iacc = Iacc+P(k)*frequency.^(N-k+1);
end
figure;
plot(frequency,Iacc,'r -','Linewidth',1.5);
grid on;
set(gca,'FontSize',12);
xlabel('Frequency','FontSize',12,'FontWeight','Bold')
ylabel('Iac factor','FontSize',12,'FontWeight','Bold')

%%
% Frequency characteristics of ESR
freq11 = linspace(10,100,10);
freq22 = linspace(200,1000,9);
freq2 = zeros(1,19);
freq2(1:10) = freq11;
freq2(11:19) = freq22;
RMS_factor_20 = [1.7,1.6,1.5,1.46,1.3,1.23,1.17,1.08,1.03,1,0.85,0.78,0.76,0.75,0.74,0.73,0.72,0.71,0.7];

num = numel(freq2);
N = 7;
P = polyfit(freq2,RMS_factor_20,N);
RMS_factor2_20 = zeros(1,num);

for k = 1:N+1
    RMS_factor2_20 = RMS_factor2_20+P(k)*freq2.^(N-k+1);
end

figure;
plot(freq2,RMS_factor_20,'ro-','Linewidth',1.5);
hold on;
plot(freq2,RMS_factor2_20,'bo-','Linewidth',1.5);
hold off;
grid on;
set(gca,'FontSize',12);
xlabel('Frequency','FontSize',12,'FontWeight','Bold')
ylabel('RMS factor','FontSize',12,'FontWeight','Bold')

