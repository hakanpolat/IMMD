%%
% DC Link Capacitor simulation

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

