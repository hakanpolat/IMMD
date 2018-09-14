%% State Space Model of GaN
clear all;
close all;
%% GaN Parameters
% Rgin = 1.5;
Lgin = 0.65e-9;
Rss = 1e-3;
Lss = 0.43e-9;
Ls = 42e-12;
Rs = 3.6 * 0.238 * 0.82 * (1 - (-0.0135*(25 - 25))) / 295;
Ld = 450e-12;
Rd = (3.6/8) * (0.95*0.82*(1 - (-0.0135*(25 - 25))) * 18.2 / 295);

%% Simulation Parameters
SampleTime = 5e-13; %Time Steps
StopTime = 400e-9; %Stop Time
% Allocation
t = (0 : SampleTime : StopTime);
x1 = zeros(size(t)); %Ids
x2 = zeros(size(t)); %Vd
x3 = zeros(size(t)); %Vdsin
x4 = zeros(size(t)); %Vgsin
x5 = zeros(size(t)); %Vgdin
x7 = zeros(size(t)); %Ig
x8 = zeros(size(t)); %Ich
x9 = zeros(size(t)); %Cgd
x10 = zeros(size(t));%Cgs
x11 = zeros(size(t));%Cds
u1 = zeros(size(t)); %Vgss
Rgin = zeros(size(t));

%% Input Definition
u1(t>=50e-9) = 6;
Rgin(t>=0e-9) = 1.5;
x2(t>=0e-9) = 2;
u1(t>=200e-9) = -3;
% u1(t>=400e-9) = 6;
% Rgin(t>=200e-9) = 2 + 1.5;
% x2(t>=200e-9) = 0;
x3 = x2;
x4 = u1;
[x8(1),x9(1),x10(1),x11(1)] = NumericCalc(x4(1),x3(1));
[m,n] = size(t);
for k = 2:n-1
    [x8(k), x9(k), x10(k), x11(k)] = NumericCalc(x4(k-1),x3(k-1));
%     x9(k) = 2e-12;
%     x10(k) = 258e-12;
%     x11(k) = 63e-12;
    CC = x9(k)*x10(k) + x9(k)*x11(k) + x10(k)*x11(k);
    a11 = -(Rs+Rd)/(Ls+Ld);
    a13 = -1/(Ls+Ld);
    a14 = 1/(Ls+Ld);
    a22 = -(Rgin(k)+Rss)/(Lss+Lgin);
    a23 = -1/(Lgin + Lss);
    a31 = x9(k)/CC;
    a32 = x11(k)/CC;
    a41 = -x10(k)/CC;
    a42 = 1/x9(k) - x10(k)*x11(k)/(x9(k)*CC);
    
    A = [a11 0 a13 a14;0 a22 a23 0;a31 a32 0 0;a41 a42 0 0];
    
    b12 = 1/(Ls+Ld);
    b21 = 1/(Lgin+Lss);
    b33 = -x9(k)/CC;
    b43 = x10(k)/CC;
    
    B = [0 b12 0;b21 0 0;0 0 b33;0 0 b43];
 
    CurrVect = [x1(k-1);x7(k-1);x4(k-1);x5(k-1)];
    InpVect = [u1(k); x2(k); x8(k)];

    NextVect = inv(eye(4) - A*SampleTime)*(CurrVect + B*InpVect*SampleTime);
    
    x1(k) = NextVect(1,1); 
    x7(k) = NextVect(2,1);
    x4(k) = NextVect(3,1);
    x5(k) = NextVect(4,1);
    
    x3(k) = x4(k) - x5(k);
    
end




figure;
hold all
grid on
plot(t,x1,t,x2,t,u1,'Linewidth',2.0);
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
plot(t,x8,t,x3,t,x4,'Linewidth',2.0);
%xlim([0]);
ylim([-110 450]);
xlabel('Time');
ylabel('Voltage,Ampere');
title({'Ich, Vds, Vgs IN'})
legend ('Ich','Vds','Vgs','Location','best');
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

