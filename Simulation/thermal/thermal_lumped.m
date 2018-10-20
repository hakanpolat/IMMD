% Thermal lumped parameter model
Ts = 1e-3;
Tfinal = 1e-1;
% Loss
PGaN = 8; % Watts

% GaN thermal resistance
% This is taken from:
% https://gansystems.com/wp-content/uploads/2018/07/GS66508B-DS-Rev-180709.pdf
Rth_jc = 0.5; % K/W

% PCB thermal resistance
% This is taken from:
% https://gansystems.com/wp-content/uploads/2018/01/GN005_PCB-Thermal-Design-Guide-Enhancement-Mode-031815.pdf
Rth_pcb = 3.39; % K/W

% Pad thermal resistance
% TGF50-07870787-079
conP = 5; % W/mK
lenP = 2e-3; % m
areaP1 = 18e-3*12e-3; % m^2
areaP2 = 15e-3*15e-3; % m^2
Rth_pa = lenP/(conP*areaP1); % K/W
Rth_tim = 0.5; % K/W
Rth_pad = Rth_pa + 2*Rth_tim; % K/W

% Heat Sink thermal resistance
Rth_hs = 1; % K/W

% Junction Temperature
Tjreq = 140; % C
num = 30;
Tj = zeros(1,num); % C

% Ambient Temperature
Ta = 40; % C

sim('thermal_model_lumped.slx');


%%
for k = 1:num
    Rth_hs = 0.05*(k);
    sim('thermal_model_lumped.slx');
    Tj(k) = Tjunction(end);
end

%%
Rthhs = 0.05*(1:num);
Tjre = Tjreq*ones(1,num);
Tamb = Ta*ones(1,num);

figure;
hold all;
plot(Rthhs,Tj,'b- ','Linewidth',2);
plot(Rthhs,Tjre,'r- ','Linewidth',2);
plot(Rthhs,Tamb,'k- ','Linewidth',2);
grid on;
set(gca,'FontSize',13);
xlabel('Heat sink thermal resistance (K/W)','FontSize',12,'FontWeight','Bold');
ylabel('Temperature (C)','FontSize',12,'FontWeight','Bold');
legend('Junction temp','Maximum junction temp','Ambient temp')

ylim([0 200]);
%xlim([1 slot]);


