function xdot = GaN( t,x ) % t-> Time span, x-> State Vector
% GaN state equations to be used in ode solvers.
% There are four state elements: Id, Ig, Vds, Vgs
Id = x(1);
Ig = x(2);
Vgs = x(3);
Vds = x(4);

Rgin = 1.5;
Lgin = 0.65e-9;
Rss = 1e-3;
Lss = 0.43e-9;
Ls = 42e-12;
Rs = 3.6 * 0.238 * 0.82 * (1 - (-0.0135*(125 - 25))) / 295;
Ld = 450e-12;
Rd = (3.6/8) * (0.95*0.82*(1 - (-0.0135*(125 - 25))) * 18.2 / 295);

Coss = calculateCoss(Vds);
Ciss = calculateCiss(Vgs);
Crss = calculateCrss(Vds);
Ich = calculateIch(Vds,Vgs);
U = calculateInp(t);
u1 = U(1);
u2 = U(2);

Cds = Coss - Crss;
Cgd = Crss;
Cgs = Ciss - Crss;
CC = Cgd*Cgs + Cgd*Cds + Cgs*Cds; 

a11 = -(Rs+Rd)/(Ls+Ld);
a14 = -1/(Ls+Ld);
a22 = -(Rgin+Rss)/(Lss+Lgin);
a23 = -1/(Lgin + Lss);
a31 = Cgd/CC;
a32 = Coss/CC;
a41 = Ciss/CC;
a42 = -1/Cgd + (Ciss)*(Coss)/(Cgd*CC);

b12 = 1/(Ls+Ld);
b21 = 1/(Lgin+Lss);
b33 = -a31;
b43 = -(Ciss)/CC;

Id_dot = a11*Id + a14*Vds + b12*u2;
Ig_dot = a22*Ig + a23*Vgs + b21*u1;
Vgs_dot = a31*Id + a32*Ig + b33*Ich;
Vds_dot = a41*Id + a42*Ig + b43*Ich;

xdot = [Id_dot; Ig_dot; Vgs_dot; Vds_dot];


end

function Ich = calculateIch(vds,vgs)
vgd = vgs - vds;
cur = 4.5057; % To be updated
K = cur * 0.8 * (273/300)^(-2.7);
x0 = 0.31 ;
x1 = 0.255;
slp = 2;
if vds>=0
            Ich = K*log(1+exp(26*(vgs-1.7)/slp))*(vds)/(1+max((x0+x1*(vgs+4.1)),0.2)*vds);
else
            Ich = -K*log(1+exp(26*(vgd-1.7)/slp))*(-vds)/(1+max((x0+x1*(vgd+6.1)),0.2)*(-vds));
end
end
function Coss = calculateCoss(vds)
vds = abs(vds);
if vds <= 40
    Coss = -1.60513*vds+500.11;
elseif vds<=70
    Coss = -8.563*vds+778.41; 
elseif vds<=222
    Coss = -0.6711*vds+226;
else
    Coss = -0.0534*vds+88.86;
end
 Coss = Coss * 1e-12;
end
function Ciss = calculateCiss(vgs)
if vgs <= 1
    Ciss = 9.245*vgs+231.35;
elseif vgs<=2
    Ciss = 400.9*vgs+641.5; 
elseif vgs<=5
    Ciss = -37*vgs+715.5;
else
    Ciss = -9.4*vgs+577.5;
end
 Ciss = Ciss * 1e-12;
end
function Crss = calculateCrss(vds)
vds = abs(vds);
 if vds<=51
     Crss = -1.0716*vds + 56.3216;
 else
     Crss = 1.67;
 end
 Crss = Crss * 1e-12;
end
function u=calculateInp(t)
u2 = 2;
tmod = mod(t,2e-5);
if (50e-9<tmod) && (tmod<10000e-9)
    u1 = 6;
else
    u1 = -3;
end
u = [u1; u2];
end



