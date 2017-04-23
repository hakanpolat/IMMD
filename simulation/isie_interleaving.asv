max_number_module = 8;
enable = zeros(1,max_number_module);
phase = zeros(1,max_number_module);
n = 4;
% step time
Ts = 1e-6; % sec
% modulation index
ma = 1;
% switching frequency
fsw = 1e3; % Hz
% DC link voltage
Vdc = 400; % Volts
% Load
Pout = 2e3; % W
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
%phase(1:4) = 0:90:270; % degrees
enable(1:4) = 1;
% Run the simulation
sim('topology2_module.slx');
% Get parameters
Irms = Icrms(numel(Icrms));
Icap = icdata;

%%
Icapflag1 = icdata(:,2);
Irms1 = Irms*ones(1,numel(Icrms));
%%
Icapflag2 = icdata(:,2);
Irms2 = Irms*ones(1,numel(Icrms));
%%
time = icdata(:,1);
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
ylabel('Capacitor Ripple Current (A)','FontSize',12,'FontWeight','Bold')
xlim([0.014 0.02]);
ylim([-22 15]);
legend('with interleaving','without interleaving','with interleaving','without interleaving');
