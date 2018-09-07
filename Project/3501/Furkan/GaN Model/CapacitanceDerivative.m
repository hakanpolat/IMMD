%% Functions
function [Dx9,Dx10,Dx11] = CapacitanceDerivative(x10,Dx10,x11,Dx11,x13,Dx13,x14,Dx14) %Vgin,Vdin,Vsin

Vds = x14/x11;
Vdsdot = (Dx14*x11 - Dx11*x14)/x11^2;
Vgs = x13/x10;
Vgsdot = (Dx13*x10 - Dx10*x13)/x10^2;

%% DCrss calculation
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
Dx9 = a1*(-2*(Vds - b1)/c1^2)*exp(-1*(Vds - b1)^2/c1^2)*Vdsdot + ...
      a2*(-2*(Vds - b2)/c2^2)*exp(-1*(Vds - b2)^2/c2^2)*Vdsdot + ...
      a3*(-2*(Vds - b3)/c3^2)*exp(-1*(Vds - b3)^2/c3^2)*Vdsdot + ...
      a4*(-2*(Vds - b4)/c4^2)*exp(-1*(Vds - b4)^2/c4^2)*Vdsdot + ...
      a5*(-2*(Vds - b5)/c5^2)*exp(-1*(Vds - b5)^2/c5^2)*Vdsdot + ...
      a6*(-2*(Vds - b6)/c6^2)*exp(-1*(Vds - b6)^2/c6^2)*Vdsdot;
Dx9 = Dx9*1e-12;
%% Ciss Calculation
       a1 =        267.6;
       b1 =      2.007;
       c1 =       0.4734;
       a2 =       240.1;
       b2 =       3.049;
       c2 =      1.104;
       a3 =        -1336;
       b3 =       7.803;
       c3 =       9.331;
       a4 =       -250.6;
       b4 =       7.082;
       c4 =       1.715;
       a5 =       -2352;
       b5 =         11.25;
       c5 =       3.184;
       a6 =      8.572e13;
       b6 =       340.6;
       c6 =       67.72;
Dx10 = a1*(-2*(Vgs - b1)/c1^2)*exp(-1*(Vgs - b1)^2/c1^2)*Vgsdot + ...
       a2*(-2*(Vgs - b2)/c2^2)*exp(-1*(Vgs - b2)^2/c2^2)*Vgsdot + ...
       a3*(-2*(Vgs - b3)/c3^2)*exp(-1*(Vgs - b3)^2/c3^2)*Vgsdot + ...
       a4*(-2*(Vgs - b4)/c4^2)*exp(-1*(Vgs - b4)^2/c4^2)*Vgsdot + ...
       a5*(-2*(Vgs - b5)/c5^2)*exp(-1*(Vgs - b5)^2/c5^2)*Vgsdot + ...
       a6*(-2*(Vgs - b6)/c6^2)*exp(-1*(Vgs - b6)^2/c6^2)*Vgsdot;
Dx10 = Dx10*1e-12;
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
Dx11 = a1*(-2*(Vds - b1)/c1^2)*exp(-1*(Vds - b1)^2/c1^2)*Vdsdot + ...
       a2*(-2*(Vds - b2)/c2^2)*exp(-1*(Vds - b2)^2/c2^2)*Vdsdot + ...
       a3*(-2*(Vds - b3)/c3^2)*exp(-1*(Vds - b3)^2/c3^2)*Vdsdot + ...
       a4*(-2*(Vds - b4)/c4^2)*exp(-1*(Vds - b4)^2/c4^2)*Vdsdot + ...
       a5*(-2*(Vds - b5)/c5^2)*exp(-1*(Vds - b5)^2/c5^2)*Vdsdot + ...
       a6*(-2*(Vds - b6)/c6^2)*exp(-1*(Vds - b6)^2/c6^2)*Vdsdot;
Dx11 = Dx11*1e-12;

end