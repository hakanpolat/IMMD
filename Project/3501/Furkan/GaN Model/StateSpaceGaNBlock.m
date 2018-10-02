% State Variables
% Id, Ig, Vgsin, Vdsin
function [x1,x7,x4,x3] = StateSpaceGaNBlock(u1,u2,x1e,x7e,x4e,x3e,SampleTime) %Vgsso & Vdso & Idsold & Igold & Vgsold & Vdsold
%% State Space Model of GaN
if u1 > 0
    Rgin = 11.5;
else
    Rgin = 3.5;
end
Lgin = 0.65e-9;
Rss = 1e-3;
Lss = 0.43e-9;
Ls = 42e-12;
Rs = 3.6 * 0.238 * 0.82 * (1 - (-0.0135*(125 - 25))) / 295;
Ld = 450e-12;
Rd = (3.6/8) * (0.95*0.82*(1 - (-0.0135*(125 - 25))) * 18.2 / 295);

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

%% Input Definition
    [x8, x9, x10, x11] = NumericCalc(x4e,x3e);
    CC = x9*x10 + x9*x11 + x10*x11; 
    A(3,1) = x9/CC;
    A(3,2) = (x11+x9)/CC;
    A(4,1) = (x9 + x10)/CC;
    A(4,2) = -1/x9 + (x11 + x9)*(x10+x9)/(x9*CC);

    B(3,3) = -x9/CC;
    B(4,3) = -(x9 + x10)/CC;

    CurrVect(1,1) = x1e;
    CurrVect(2,1) = x7e;
    CurrVect(3,1) = x4e;
    CurrVect(4,1) = x3e;
    
    InpVect(1,1) = u1;
    InpVect(2,1) = u2;
    InpVect(3,1) = x8;
   
    % Forward Euler Solution
    NextVect = (eye(4) + A*SampleTime)*CurrVect + SampleTime*B*InpVect;
  
 
    x1 = NextVect(1,1); 
    x7 = NextVect(2,1);
    x4 = NextVect(3,1);
    x3 = NextVect(4,1);
