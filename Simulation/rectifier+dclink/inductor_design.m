f=40;                                   %kHz
L=0.1;                                  %mH
I=7;                                    %A
LI=L*I^2;                               
    %55928 core 
Al(1)=0.92*201;                         %Inductance factor
N(1)=sqrt(L*1e06/Al(1));                %Number of turns
for i=1:10
    H(i)=N(i)*I/6.35;
    Bi(i)=1/(0.01+1.667e-06*H(i)^2.477);
    Al(i+1)=201*Bi(i)/100;
    N(i+1)=sqrt(L*1e06/Al(i+1));
end
%AWG 15 cable
A_copper=N(11)*1.65;                    %copper area
k=A_copper/156;                         %fill factor
L_copper=N(11)*43.8/1000;               %length of the cable
R_copper=L_copper*10.45/1000;           %DC resistance 
P_copper=R_copper*I^2;                  %Copper loss
Hmax=N(11)*(I+0.2)/6.35;                %Max B
Hmin=N(11)*(I-0.2)/6.35;                %Min B
Bmax=((1.458e-02+2.14e-02*Hmax+1.436e-03*Hmax^2)/(1+4.367e-02*Hmax+1.389e-03*Hmax^2))^1.124;
Bmin=((1.458e-02+2.14e-02*Hmin+1.436e-03*Hmin^2)/(1+4.367e-02*Hmin+1.389e-03*Hmin^2))^1.124;
P_core=0.001*6.35*0.654*254.26*(((Bmax-Bmin)/2)^2.222)*f^1.56;