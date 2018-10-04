%% Functions
function [Ich,Cgd,Cgs,Cds] = NumericCalc(Vgs,Vds) %Vgin,Vdin,Vsin
% Vgs = x5-x4;
% Vds = x4-x3;
% Vgd = x5-x4;
Vgd = Vgs - Vds;
cur = 4.5057; % To be updated
K = cur * 0.8 * (273/300)^(-2.7);
x0 = 0.31 ;
x1 = 0.255;
slp = 2;
if Vds>=0
            Ich = K*log(1+exp(26*(Vgs-1.7)/slp))*(Vds)/(1+max((x0+x1*(Vgs+4.1)),0.2)*Vds);
else
            Ich = -K*log(1+exp(26*(Vgd-1.7)/slp))*(-Vds)/(1+max((x0+x1*(Vgd+6.1)),0.2)*(-Vds));
end

Vds = abs(Vds);
%% Crss Calc
 if Vds<=51
     Crss = -1.0716*Vds + 56.3216;
 else
     Crss = 1.67;
 end
 Crss = Crss * 1e-12;
%% Coss Calc
if Vds <= 40
    Coss = -1.60513*Vds+500.11;
elseif Vds<=70
    Coss = -8.563*Vds+778.41; 
elseif Vds<=222
    Coss = -0.6711*Vds+226;
else
    Coss = -0.0534*Vds+88.86;
end
 Coss = Coss * 1e-12;
%% Ciss Calc

if Vgs <= 1
    Ciss = 9.245*Vds+231.35;
elseif Vgs<=2
    Ciss = 400.9*Vgs+641.5; 
elseif Vgs<=5
    Ciss = -37*Vgs+715.5;
else
    Ciss = -9.4*Vgs+577.5;
end
 Ciss = Ciss * 1e-12;

%% Outputs
Cgs = Ciss - Crss;
Cds = Coss - Crss;
Cgd = Crss;
% 
% end