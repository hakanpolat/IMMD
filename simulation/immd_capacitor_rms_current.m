%% Capacitor Analytical RMS
M = 0.5;
cosphi = 0.9;

Vdc = 400; % Volts
Pout = M*2e3; % W
Sout = Pout/(cosphi); % VA
Vll_rms = Vdc*0.612*M; % Volts
Iline = Sout/(Vll_rms*sqrt(3)); % Amps

Icrms = Iline*sqrt(2*M*(sqrt(3)/(4*pi) + cosphi^2*(sqrt(3)/pi-9*M/16)))


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
M = 0.9;
cosphi = 0.8;
Vdc = 400; % V
Pout = 2e3; % W
Sout = Pout/(cosphi); % VA
Vll_rms = Vdc*0.612*M; % V
Iarms = Sout/(Vll_rms*sqrt(3)); % A
Iapeak = Iarms*sqrt(2); % A
efficiency = 0.99;
Tambient = 30; % C

% Constraints
perc_ripple_c = 3; % percent
volt_ripple_c = perc_ripple_c*0.01*Vdc; % V
temp_max = 80; % C

% Select switching frequency
fsw = 1e3; % Hz

% Block 1 - RMS current
Icrms = Iline*sqrt(2*M*(sqrt(3)/(4*pi) + cosphi^2*(sqrt(3)/pi-9*M/16)));

% Block 2 - Charging current
Idc = (3/(2*sqrt(2)))*M*Iarms*cosphi/efficiency;
Icharge = Iapeak - Idc;
%volt_ripple = Icharge*0.5*M/(fsw*C);
C = Icharge*0.5*M/(volt_ripple_c*fsw); % F
Cap = ceil(C*1e4)*1e-4; % F

% Datasheet parameters
Capacitance = 220e-6; % F
Diameter = 25; % mm
Length = 45; % mm
ESR_100_20 = 400; % mOhm
Iacmax_100_60 = 3.02; % A
Iacmax_100_85 = 2.32; % A
Rth = 20.19; % C/W

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

