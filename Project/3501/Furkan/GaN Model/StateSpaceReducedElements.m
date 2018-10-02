% State Variables
% Id, Ig, Vgsin, Vdsin
%% State Space Model of GaN
% clear all;
% close all;

profile on
tic
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
SampleTime = 1e-11; %Time Steps
StopTime = 400e-6; %Stop Time
% Allocation
t = (0 : SampleTime : StopTime);
x1 = zeros(size(t)); %Ids
x3 = zeros(size(t)); %Vdsin
x4 = zeros(size(t)); %Vgsin
% x5 = zeros(size(t)); %Vgdin
x7 = zeros(size(t)); %Ig
% x8 = zeros(size(t)); %Ich
% x9 = zeros(size(t)); %Cgd
% x10 = zeros(size(t));%Cgs
% x11 = zeros(size(t));%Cds
u1 = zeros(size(t)); %Vgss
u2 = zeros(size(t)); %Vdc

%% Creating Matrices
A = zeros(size(4));
    A(1,1) = -(Rs+Rd)/(Ls+Ld);
    A(1,4) = -1/(Ls+Ld);
    A(2,2) = -(Rgin+Rss)/(Lss+Lgin);
    A(2,3) = -1/(Lgin + Lss);
B = zeros(size(4,3));
    B(1,2) = 1/(Ls+Ld);
    B(2,1) = 1/(Lgin+Lss);
CurrVect = zeros(size(4,1));
NextVect = zeros(size(3,1));
%% Input Definition
u1(t>=50e-9) = 6;
u2(t>=0e-9) = 2;
u1(t>=200e-9) = -3;
% u1(t>=400e-9) = 6;
% u2(t>=200e-9) = 0;
x3 = u2(1);
x4 = u1(1);
[m,n] = size(t);
for k = 2:n-1
    [x8, x9, x10, x11] = NumericCalc(x4,x3);
%    A(1:4) = NumericCalc(x4,x3);
%    x8 = A(1);
%    x9 = A(2);
%    x10 = A(3);
%    x11 = A(4);
%    x9(k) = 2e-12;
%    x10(k) = 258e-12;
%    x11(k) = 63e-12;

    CC = x9*x10 + x9*x11 + x10*x11; 

    A(3,1) = x9/CC;
    A(3,2) = (x11+x9)/CC;
    A(4,1) = (x9 + x10)/CC;
    A(4,2) = -1/x9 + (x11 + x9)*(x10+x9)/(x9*CC);
    
%     A = [a11 0 a13 a14;0 a22 a23 0;a31 a32 0 0;a41 a42 0 0];
    

    B(3,3) = -x9/CC;
    B(4,3) = -(x9 + x10)/CC;
    
%     B = [0 b12 0;b21 0 0;0 0 b33;0 0 b43];
 
    CurrVect(1,1) = x1(k-1);
    CurrVect(2,1) = x7(k-1);
    CurrVect(3,1) = x4;
    CurrVect(4,1) = x3;
    
    InpVect(1,1) = u1(k);
    InpVect(2,1) = u2(k);
    InpVect(3,1) = x8;


    % Backward Euler Solution
%     NextVect = inv(eye(4) - A*SampleTime)*(CurrVect + B*InpVect*SampleTime);
    
    % Forward Euler Solution
    NextVect = (eye(4) + A*SampleTime)*CurrVect + SampleTime*B*InpVect;
    
%     % Trapezoidal Integration Solution
%     Aprime = A*SampleTime/2;
%     NextVect = inv(eye(4) - Aprime)*((eye(4) + Aprime)*CurrVect + B*SampleTime*InpVect);
    
    x1(k) = NextVect(1,1); 
    x7(k) = NextVect(2,1);
    x4 = NextVect(3,1);
    x3 = NextVect(4,1);

end
toc
profile off
profile viewer


figure;
hold all
grid on
plot(t,x1,t,u2,t,x7,t,u1,'Linewidth',2.0);
%xlim([0]);
ylim([-80 200]);
xlabel('Time');
ylabel('Voltage,Ampere');
title({'Ids, Vds, Ig, Vgs OUT'})
legend ('Ids','Vds','Ig','Vgs','Location','best');
hold off
