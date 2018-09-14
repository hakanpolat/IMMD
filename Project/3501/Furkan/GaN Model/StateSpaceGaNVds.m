% State Variables
% Id, Ig, Vgsin, Vdsin
%% State Space Model of GaN
clear all;
tic
close all;
%% GaN Parameters
Rgin = 1.5;
Lgin = 0.65e-9;
Rss = 1e-3;
Lss = 0.43e-9;
Ls = 42e-12;
Rs = 3.6 * 0.238 * 0.82 * (1 - (-0.0135*(25 - 25))) / 295;
Ld = 450e-12;
Rd = (3.6/8) * (0.95*0.82*(1 - (-0.0135*(25 - 25))) * 18.2 / 295);

%% Simulation Parameters
SampleTime = 1e-12; %Time Steps
StopTime = 400e-9; %Stop Time
% Allocation
t = (0 : SampleTime : StopTime);
x1 = zeros(size(t)); %Ids
x3 = zeros(size(t)); %Vdsin
x4 = zeros(size(t)); %Vgsin
x5 = zeros(size(t)); %Vgdin
x7 = zeros(size(t)); %Ig
x8 = zeros(size(t)); %Ich
x9 = zeros(size(t)); %Cgd
x10 = zeros(size(t));%Cgs
x11 = zeros(size(t));%Cds
u1 = zeros(size(t)); %Vgss
u2 = zeros(size(t)); %Vdc

%% Input Definition
u1(t>=50e-9) = 6;
u2(t>=0e-9) = 2;
u1(t>=200e-9) = -3;
% u1(t>=400e-9) = 6;
u2(t>=200e-9) = 0;
x3 = u2;
x4 = u1;
[x8(1),x9(1),x10(1),x11(1)] = NumericCalc(x4(1),x3(1));
[m,n] = size(t);
for k = 2:n-1
    [x8(k), x9(k), x10(k), x11(k)] = NumericCalc(x4(k-1),x3(k-1));
%     x9(k) = 2e-12;
%     x10(k) = 258e-12;
%     x11(k) = 63e-12;
    CC = x9(k)*x10(k) + x9(k)*x11(k) + x10(k)*x11(k); %
    a11 = -(Rs+Rd)/(Ls+Ld);
    a13 = 0;
    a14 = -1/(Ls+Ld);
    a22 = -(Rgin+Rss)/(Lss+Lgin);
    a23 = -1/(Lgin + Lss);
    a31 = x9(k)/CC;
    a32 = (x11(k)+x9(k))/CC;
    a41 = (x9(k) + x10(k))/CC;
    a42 = -1/x9(k) + (x11(k)+x9(k))*(x10(k)+x9(k))/(x9(k)*CC);
    
    A = [a11 0 a13 a14;0 a22 a23 0;a31 a32 0 0;a41 a42 0 0];
    
    b12 = 1/(Ls+Ld);
    b21 = 1/(Lgin+Lss);
    b33 = -x9(k)/CC;
    b43 = -(x9(k) + x10(k))/CC;
    
    B = [0 b12 0;b21 0 0;0 0 b33;0 0 b43];
 
    CurrVect = [x1(k-1);x7(k-1);x4(k-1);x3(k-1)];
    InpVect = [u1(k); u2(k); x8(k)];

    % Backward Euler Solution
%     NextVect = inv(eye(4) - A*SampleTime)*(CurrVect + B*InpVect*SampleTime);
    
    % Forward Euler Solution
    NextVect = (eye(4) + A*SampleTime)*CurrVect + SampleTime*B*InpVect;
    
%     % Trapezoidal Integration Solution
%     Aprime = A*SampleTime/2;
%     NextVect = inv(eye(4) - Aprime)*((eye(4) + Aprime)*CurrVect + B*SampleTime*InpVect);
    
    x1(k) = NextVect(1,1); 
    x7(k) = NextVect(2,1);
    x4(k) = NextVect(3,1);
    x3(k) = NextVect(4,1);
    
    x5(k) = x4(k) - x3(k);
    
end
toc



figure;
hold all
grid on
plot(t,x1,t,u2,t,u1,'Linewidth',2.0);
%xlim([0]);
ylim([-110 450]);
xlabel('Time');
ylabel('Voltage,Ampere');
title({'Ids, Vds, Vgs OUT'})
legend ('Ids','Vds','Vgs','Location','best');
hold off

figure;
hold all
grid on
plot(t,x8,t,x3,t,x4,t,x5,'Linewidth',2.0);
%xlim([0]);
ylim([-110 450]);
xlabel('Time');
ylabel('Voltage,Ampere');
title({'Ich, Vds, Vgs IN'})
legend ('Ich','Vds','Vgs','Vgd','Location','best');
hold off


figure;
hold all
grid on
plot(t,x9,t,x10,t,x11,'Linewidth',2.0);
%xlim([0]);
ylim([-2e-9 2e-9]);
xlabel('Time');
ylabel('Capacitance');
title({'Cgd, Cgs, Cds IN'})
legend ('Cgd','Cgs','Cds','Location','best');
hold off


figure;
hold all
grid on
plot(t,x5,t,x4,t,x3,t,x7,'Linewidth',2.0);
%xlim([0]);
ylim([-20 20]);
xlabel('Time');
ylabel('Voltages');
title({'Vgd, Vgs, Vds IN'})
legend ('Vgd','Vgs','Vds','Ig','Location','best');
hold off

%%
% 
% figure;
% subplot(4,1,1)
% hold all
% grid on
% plot(t,x1,t,DrainCurr','Linewidth',2.0);
% xlim([1.5e-7 2.5e-7]);
% %ylim([-20 20]);
% xlabel('Time');
% ylabel('Currents');
% title({'Drain Current'})
% legend ('State Space','Simulink','Location','best');
% hold off
% 
% subplot(4,1,2)
% hold all
% grid on
% plot(t,x7,t,GateCurr','Linewidth',2.0);
% xlim([1.5e-7 2.5e-7]);
% %ylim([-20 20]);
% xlabel('Time');
% ylabel('Currents');
% title({'Gate Current'})
% legend ('State Space','Simulink','Location','best');
% hold off
% 
% subplot(4,1,3)
% hold all
% grid on
% plot(t,x4,t,GateVolt','Linewidth',2.0);
% xlim([1.5e-7 2.5e-7]);
% %ylim([-20 20]);
% xlabel('Time');
% ylabel('Voltages');
% title({'Gate Source Voltage'})
% legend ('State Space','Simulink','Location','best');
% hold off
% 
% subplot(4,1,4)
% hold all
% grid on
% plot(t,x3,t,DSVolt','Linewidth',2.0);
% xlim([1.5e-7 2.5e-7]);
% %ylim([-20 20]);
% xlabel('Time');
% ylabel('Voltages');
% title({'Drain Source Voltage'})
% legend ('State Space','Simulink','Location','best');
% hold off
% 
% %%
% tic 
% sim('Single1.slx')
% toc
