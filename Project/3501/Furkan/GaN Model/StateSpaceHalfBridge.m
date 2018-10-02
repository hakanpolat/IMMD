% State Variables
% Id, Ig, Vgsin, Vdsin
%% State Space Model of GaN
% clear all;
% close all;

profile on
tic
%% Simulation Parameters
SampleTime = 1e-11; %Time Steps
StopTime = 1000e-9; %Stop Time

%% Load Parameters
Rload = 10;
Lload = 40e-6;
fsw = 3e6;
Lp = 1e-10;
LdcP = 5e-9;
LdcN = 5e-9;

%% Allocation
t = (0 : SampleTime : StopTime);

x1T = zeros(size(t)); %Ids
x3T = zeros(size(t)); %Vdsin
x4T = zeros(size(t)); %Vgsin
x7T = zeros(size(t)); %Ig
% u1T = zeros(size(t)); %Vgsso
u2T = zeros(size(t)); %Vdso

x1B = zeros(size(t)); %Ids
x3B = zeros(size(t)); %Vdsin
x4B = zeros(size(t)); %Vgsin
x7B = zeros(size(t)); %Ig
% u1B = zeros(size(t)); %Vgsso
u2B = zeros(size(t)); %Vdso

u = 100*ones(size(t)); %Vdc
Vload = zeros(size(t)); %Load Voltage

%% Input Definition
[u1T, u1B] = PulseTimer(t,fsw,SampleTime);
% plot(t,u1T,t,u1B);

%% Calculation
[~,n] = size(t);
for k=3:n
    u2B(k) = Vload(k-1); %- Lp*(x1B(k-1) - x1B(k-2))/SampleTime;
    u2T(k) = u(k) - Vload(k-1);% - (LdcP + LdcN + Lp)*(x1T(k-1) - x1T(k-2))/SampleTime;
    [x1B(k),x7B(k),x4B(k),x3B(k)] = StateSpaceGaNBlock(u1B(k),u2B(k),x1B(k-1),x7B(k-1),x4B(k-1),x3B(k-1),SampleTime);
    [x1T(k),x7T(k),x4T(k),x3T(k)] = StateSpaceGaNBlock(u1T(k),u2T(k),x1T(k-1),x7T(k-1),x4T(k-1),x3T(k-1),SampleTime);
    Vload(k) = Lload*(x1B(k-1) - x1B(k-2) - x1B(k-1) + x1B(k-2))/SampleTime + Rload*(x1T(k) - x1B(k));
end
profile off
profile viewer
%% Plot and See

figure;
hold all
grid on
plot(t,x1T,t,u2T,t,x7T,t,u1T,'Linewidth',2.0);
%xlim([0]);
ylim([-80 200]);
xlabel('Time');
ylabel('Voltage,Ampere');
title({'Top Switch Ids, Vds, Ig, Vgs'})
legend ('Ids','Vds','Ig','Vgs','Location','best');
hold off

figure;
hold all
grid on
plot(t,x1B,t,u2B,t,x7B,t,u1B,'Linewidth',2.0);
%xlim([0]);
ylim([-80 200]);
xlabel('Time');
ylabel('Voltage,Ampere');
title({'Bottom Switch Ids, Vds, Ig, Vgs'})
legend ('Ids','Vds','Ig','Vgs','Location','best');
hold off

