%% DC Link Capacitor simulation

% modulation index
ma = 0.66;
% switching frequency
fsw = 1e3; % Hz
% DC link voltage
Vdc = 700; % Volts
% DC Link capacitor
Cdc = 1e-3; % Farads
ESR = 1e-3; % Ohms
% Load
Sout = 20e3; % VA
fout = 50; % Hz
wout = 2*pi*fout; % rad/sec
Vll_rms = 400; % Volts
Iline = Sout/(Vll_rms*sqrt(3)); % Amps
pf = 0.8;
Zload = Vll_rms/(Iline*sqrt(3)); % Ohms
Rload = Zload*pf; % Ohms
Xload = sqrt(Zload^2-Rload^2); % Ohms
Lload = Xload/wout; % Henries
% Run the simulation
sim('capacitor1.slx');
% Get parameters
Vrms = Vrms_sim(numel(Vrms_sim));
Irms = Irms_sim(numel(Irms_sim));
Sout = sqrt(3)*Vrms*Irms;


%%
num = 20;
Vcrms = zeros(1,num);
for k = 1:num
    Sout = k*1e3; % VA
    fout = 50; % Hz
    wout = 2*pi*fout; % rad/sec
    Vll_rms = 400; % Volts
    Iline = Sout/(Vll_rms*sqrt(3)); % Amps
    pf = 0.8;
    Zload = Vll_rms/(Iline*sqrt(3)); % Ohms
    Rload = Zload*pf; % Ohms
    Xload = sqrt(Zload^2-Rload^2); % Ohms
    Lload = Xload/wout; % Henries
    sim('capacitor1.slx');
    Vcrms(k) = Vcrms_sim(numel(Vcrms_sim));
end

power_out = 1e3*(1:num);
figure;
plot(power_out,Vcrms,'bo-','Linewidth',1.5);
grid on;
set(gca,'FontSize',12);
xlabel('Power Output (VA)','FontSize',12,'FontWeight','Bold')
ylabel('DC Link RMS Current (A)','FontSize',12,'FontWeight','Bold')

%%
num = 20;
Vcrms = zeros(1,num);
for k = 1:num
    fsw = k*1e3; % Hz
    sim('capacitor1.slx');
    Vcrms(k) = Vcrms_sim(numel(Vcrms_sim));
end

sw_freq = 1e3*(1:num);
figure;
plot(sw_freq,Vcrms,'bo-','Linewidth',1.5);
grid on;
set(gca,'FontSize',12);
xlabel('Switching Freqency (Hz)','FontSize',12,'FontWeight','Bold')
ylabel('DC Link RMS Current (A)','FontSize',12,'FontWeight','Bold')

%%
% Topology simulation
% Three phase modules connected parallel on the DC link
% Interleaving is applied
% DC link is 400V - 650V devices are used
% modules
n = 4;
%phase = zeros(1,4);
phase = 0:90:270;
%phase = 0:75:225;
% step time
Ts = 1e-7; % sec
% modulation index
ma = 1;
% switching frequency
fsw = 100e3; % Hz
% DC link voltage
Vdc = 400; % Volts
% Load
Sout = 2e3/0.9; % VA
fout = 50; % Hz
wout = 2*pi*fout; % rad/sec
%Vll_rms = Vdc/sqrt(2); % Volts
Vll_rms = ma*Vdc*0.612; % Volts
Iline = Sout/(Vll_rms*sqrt(3)); % Amps
pf = 0.9;
Zload = Vll_rms/(Iline*sqrt(3)); % Ohms
Rload = Zload*pf; % Ohms
Xload = sqrt(Zload^2-Rload^2); % Ohms
Lload = Xload/wout; % Henries

%%
step = 5; % degrees

tic
for l = 1:75
    phase = zeros(1,n);
    for k = 1:n
        phase(k) = (k-1)*((l-1)*step);
        if k == n
            disp(phase);
        end
    end
    % Run the simulation
    sim('topology1.slx');
    % Get parameters
    Irms(l) = Icrms(numel(Icrms));
    disp(Irms(l));
end
toc

%%
Idc = 18;
Irms_perc = 100*Irms/Idc;
phase_shift = 0:(45/n):19*(45/n);
%phase_shift = 0:step:74*step;

figure;
plot(phase_shift,Irms_perc,'ro-','Linewidth',1.5);
grid on;
set(gca,'FontSize',12);
xlabel('Phase shift angle','FontSize',12,'FontWeight','Bold')
ylabel('DC Link Capacitor RMS Current (%)','FontSize',12,'FontWeight','Bold')


%%
time = 0:1e-5:0.5;

figure;
plot(time,Idcin,'b -','Linewidth',1.5);
hold on;
plot(time,Idc1,'r -','Linewidth',1.5);
hold on;
plot(time,Idc2,'k -','Linewidth',1.5);
hold on;
plot(time,Idc3,'m -','Linewidth',1.5);
hold on;
plot(time,Idc4,'g -','Linewidth',1.5);
hold off;
grid on;
set(gca,'FontSize',12);
xlabel('Time (sec)','FontSize',12,'FontWeight','Bold')
ylabel('DC Link Ripple Current (A)','FontSize',12,'FontWeight','Bold')

%%
figure;
subplot(5,1,1);
plot(time,Idcin,'b -','Linewidth',1.5);
grid on;
set(gca,'FontSize',12);
xlim([0.096 0.1]);
subplot(5,1,2);
plot(time,Idc1,'r -','Linewidth',1.5);
grid on;
set(gca,'FontSize',12);
xlim([0.096 0.1]);
subplot(5,1,3);
plot(time,Idc2,'k -','Linewidth',1.5);
grid on;
set(gca,'FontSize',12);
xlim([0.096 0.1]);
subplot(5,1,4);
plot(time,Idc3,'m -','Linewidth',1.5);
grid on;
set(gca,'FontSize',12);
xlim([0.096 0.1]);
subplot(5,1,5);
plot(time,Idc4,'g -','Linewidth',1.5);
grid on;
set(gca,'FontSize',12);
xlim([0.096 0.1]);

%%
Icapflag1 = Idcin;
Irms1 = 1.17*ones(1,numel(time));
%%
Icapflag2 = Idcin;
Irms2 = Irms*ones(1,numel(time));
%%
figure;
plot(time,Icapflag1,'b -','Linewidth',1.5);
hold on;
plot(time,Icapflag2,'r -','Linewidth',1.5);
hold on;
plot(time,Irms1,'m -','Linewidth',1.5);
hold on;
plot(time,Irms2,'k -','Linewidth',1.5);
hold off;
grid on;
set(gca,'FontSize',12);
xlabel('Time (sec)','FontSize',12,'FontWeight','Bold')
ylabel('DC Link Ripple Current (A)','FontSize',12,'FontWeight','Bold')
xlim([0.096 0.1]);
legend('w interleaving','w/o interleaving','w interleaving rms','w/o interleaving rms');


%%
% NEW TRIAL for capacitor ripple voltage
% step time
Ts = 1e-6; % sec
% modulation index
ma = 1;
% DC link voltage
Vdc = 400; % Volts
% Load
pf = 0.9;
Pout = 2e3; % VA
Sout = Pout/pf; % VA
efficiency = 0.99;
fout = 50; % Hz
wout = 2*pi*fout; % rad/sec
%Vll_rms = Vdc/sqrt(2); % Volts
Vll_rms = ma*Vdc*0.612; % Volts
Iline = Sout/(Vll_rms*sqrt(3)); % Amps
Zload = Vll_rms/(Iline*sqrt(3)); % Ohms
Rload = Zload*pf; % Ohms
Xload = sqrt(Zload^2-Rload^2); % Ohms
Lload = Xload/wout; % Henries
R1 = 5; % Ohm
Rrefl = Vdc^2/(Pout/efficiency);
V1 = Vdc*(R1+Rrefl)/Rrefl; % V
Cdc = 50e-6; % F
num = 10;
percent_ripple = zeros(1,num);
for k = 1:num
    fsw = k*1e3; % Hz
    sim('capacitor_voltripple.slx');
    percent_ripple(k) = perc_rip(numel(perc_rip));
end

%%
M = ma;
cosphi = pf;
module = 1;
phase_dif = 0; % degrees

switching_freq = 1e3:1e3:num*1e3;
% Capacitor Analytical voltage Ripple
Cdc = 50e-6; % F
Iapeak = Iline*sqrt(2);
Icharge_pos = Idc;
Icharge_neg = Iapeak - Idc;
volt_ripple1 = M*Icharge_neg./(Cdc*switching_freq);
volt_ripple2 = 0.3*Icharge_pos*M./(Cdc*switching_freq);
volt_ripple = max(volt_ripple1,volt_ripple2);
volt_ripple_perc = volt_ripple/Vdc*100;


%%
figure;
plot(switching_freq/1e3,percent_ripple,'ro-','Linewidth',1.5);
hold on;
plot(switching_freq/1e3,volt_ripple_perc,'bo-','Linewidth',1.5);
hold off;
grid on;
set(gca,'FontSize',12);
xlabel('Switching frequency (kHz)','FontSize',12,'FontWeight','Bold')
ylabel('DC Link Voltage Ripple (%)','FontSize',12,'FontWeight','Bold')
legend('Simulation','Analytical');
