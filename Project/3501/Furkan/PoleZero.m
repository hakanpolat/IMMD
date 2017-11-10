%% Reverse Conduction Oscillations
s = tf('s');
% z1 = Rg + s*Lg;
% z2 = s*Ls;
% z3 = s*(Ls+2*Ld) + 1/(s*(Cgd + Cds)) + 2*Rd+2*Rs;
% z4 = (z1*z2+z2*z3+z1*z3)/z2;
% z5 = (z1*z2+z2*z3+z1*z3)/z3;
% z6 = (z1*z2+z2*z3+z1*z3)/z1;
% z7 = z4/(1+s*z4*Cgd);
% z8 = z5/(1+s*z5*Cgs);
% z9 = z6/(1+s*z6*Cds);
% F = -(z7*z9)/(z7+z8+z9);
% A = 15.2733333;
% G = F*A;
% T = A/(1-G);

% Cgd1 = 2e-12;
% Cgs1 = 258e-12;
% Cds1 = 63e-12;
% Coss = Cgd1+Cds1;
hold on
for Vds = 0:25:500
%% Crss calculation
       a1 =   2.519e+14;
       b1 =      -345.7;
       c1 =       63.76;
       a2 =       27.99;
       b2 =       12.86;
       c2 =       18.29;
       a3 =       8.666;
       b3 =       33.93;
       c3 =       9.161;
       a4 =       1.502;
       b4 =       125.5;
       c4 =       121.9;
       a5 =      0.6563;
       b5 =         500;
       c5 =       34.57;
       a6 =        1.98;
       b6 =       408.2;
       c6 =       134.7;
Crss1 = a1.*exp(-((Vds-b1)./c1).^2) + a2.*exp(-((Vds-b2)./c2).^2) + a3*exp(-((Vds-b3)./c3).^2)...
   + a4.*exp(-((Vds-b4)./c4).^2) +a5.*exp(-((Vds-b5)./c5).^2) +a6.*exp(-((Vds-b6)./c6).^2);
%% Ciss Calculation
       a1 =        1167;
       b1 =      -115.8;
       c1 =       60.96;
       a2 =       269.7;
       b2 =       -5402;
       c2 =   4.243e+04;
       a3 =        3.61;
       b3 =       238.5;
       c3 =       2.507;
       a4 =       1.036;
       b4 =       175.8;
       c4 =       16.81;
       a5 =       1.571;
       b5 =         263;
       c5 =       3.586;
       a6 =      -1.174;
       b6 =       238.2;
       c6 =       25.85;
Ciss1 = a1.*exp(-((Vds-b1)./c1).^2) + a2.*exp(-((Vds-b2)./c2).^2) + a3*exp(-((Vds-b3)./c3).^2)...
   + a4.*exp(-((Vds-b4)./c4).^2) +a5.*exp(-((Vds-b5)./c5).^2) +a6.*exp(-((Vds-b6)./c6).^2);


%% Coss Calculation
       a1 =         328;
       b1 =       -8.43;
       c1 =       30.26;
       a2 =       115.8;
       b2 =        42.2;
       c2 =       7.341;
       a3 =       45.83;
       b3 =       59.01;
       c3 =       6.099;
       a4 =       183.1;
       b4 =        28.6;
       c4 =       16.39;
       a5 =       69.29;
       b5 =       154.4;
       c5 =        1511;
       a6 =       125.6;
       b6 =       22.68;
       c6 =       119.6;
Coss1 = a1.*exp(-((Vds-b1)./c1).^2) + a2.*exp(-((Vds-b2)./c2).^2) + a3*exp(-((Vds-b3)./c3).^2)...
   + a4.*exp(-((Vds-b4)./c4).^2) +a5.*exp(-((Vds-b5)./c5).^2) +a6.*exp(-((Vds-b6)./c6).^2);
%% Outputs
Coss1 = Coss1 * 1e-12;
Crss1 = Crss1 * 1e-12;
Ciss1 = Ciss1 * 1e-12;

Cgs1 = Ciss1 - Crss1;
Cds1 = Coss1 - Crss1;
Cgd1 = Crss1;

Ls1 = 2e-10;
Ld1 = 7e-10;
Lg1 = 7e-10;
Lk =2*Ld1+Ls1;

Ron1 = 12;
Rg1 = 1.5;
Rloop = 0;

a0 = 1;
a1 = Cgs1*(Rg1+Ron1)+Coss1*Rloop;
a2 = Cgs1*Lg1 + Coss1*Lk + Cgs1*Ls1 + Cgs1*Coss1*(Rg1+Ron1)*Rloop;
a3 = Cgs1*Coss1*(Lk*(Rg1+Ron1) + Ls1*(Rg1+Ron1) + Lg1*Rloop + Ls1*Rloop);
a4 = Cgs1*Coss1*(Lk*Lg1+ Lk*Ls1 + Lg1*Ls1);
b0 = Cds1 + Cgd1 + Coss1;
b1 = (Cds1*Cgd1+Cds1*Cgs1+Cgd1*Cgs1)*(Rg1+Ron1) + (Cgd1+Cgs1)*Coss1*(Rg1+Ron1) + (Cds1 + Cgd1)*Coss1*(Rloop);
b2 = (Cds1*Cgd1+Cds1*Cgs1+Cgd1*Cgs1)*(Lg1+Ls1+Coss1*(Rg1+Ron1)*Rloop) + Coss1*(Cds1*(Lk+Ls1)+Cgd1*(Lk+Lg1)+Cgs1*(Ls1+Lg1));
b3 = Coss1*(Cds1*Cgd1+Cds1*Cgs1+Cgd1*Cgs1)*(Lk*(Rg1+Ron1)+Ls1*(Rg1+Ron1)+Lg1*Rloop+Ls1*Rloop);
b4 = Coss1*(Cds1*Cgd1+Cds1*Cgs1+Cgd1*Cgs1)*(Lk*Lg1 + Lk*Ls1 + Lg1*Ls1);
gm= 15.2733333;
c0 = gm*a0;
c1 = gm*a1+b0;
c2 = gm*a2+b1;
c3 = gm*a3+b2;
c4 = gm*a4+b3;
c5 = b4;
T = gm*s*(b4*s^4+b3*s^3+b2*s^2+b1*s+b0)/(c5*s^5+c4*s^4+c3*s^3+c2*s^2+c1*s+c0);
pzmap(T);
p = pole(T);
z = zero(T);
end
% sizez = size(z);
% sizez = sizez(1);
% k = 1;
% for j = 1:sizez
%     if p(j) ~= 0 && z(j) ~= 0
%        for i=1:sizez
%            if p(j) == z(i)
%                polenew = p;
%                zeronew = z;
%                polenew(j) = [];
%                zeronew(i) = [];
%                
%                
%        
% end