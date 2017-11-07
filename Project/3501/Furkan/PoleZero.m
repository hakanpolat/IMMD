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

Cgd1 = 2e-12;
Cgs1 = 258e-12;
Cds1 = 63e-12;
Coss = Cgd1+Cds1;

Ls1 = 2e-10;
Ld1 = 7e-10;
Lg1 = 7e-10;
Lk =2*Ld1+Ls1;

Ron1 = 12;
Rg1 = 1.5;
Rloop = 0;

a0 = 1;
a1 = Cgs1*(Rg1+Ron1)+Coss*Rloop;
a2 = Cgs1*Lg1 + Coss*Lk + Cgs1*Ls1 + Cgs1*Coss*(Rg1+Ron1)*Rloop;
a3 = Cgs1*Coss*(Lk*(Rg1+Ron1) + Ls1*(Rg1+Ron1) + Lg1*Rloop + Ls1*Rloop);
a4 = Cgs1*Coss*(Lk*Lg1+ Lk*Ls1 + Lg1*Ls1);
b0 = Cds1 + Cgd1 + Coss;
b1 = (Cds1*Cgd1+Cds1*Cgs1+Cgd1*Cgs1)*(Rg1+Ron1) + (Cgd1+Cgs1)*Coss*(Rg1+Ron1) + (Cds1 + Cgd1)*Coss*(Rloop);
b2 = (Cds1*Cgd1+Cds1*Cgs1+Cgd1*Cgs1)*(Lg1+Ls1+Coss*(Rg1+Ron1)*Rloop) + Coss*(Cds1*(Lk+Ls1)+Cgd1*(Lk+Lg1)+Cgs1*(Ls1+Lg1));
b3 = Coss*(Cds1*Cgd1+Cds1*Cgs1+Cgd1*Cgs1)*(Lk*(Rg1+Ron1)+Ls1*(Rg1+Ron1)+Lg1*Rloop+Ls1*Rloop);
b4 = Coss*(Cds1*Cgd1+Cds1*Cgs1+Cgd1*Cgs1)*(Lk*Lg1 + Lk*Ls1 + Lg1*Ls1);
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