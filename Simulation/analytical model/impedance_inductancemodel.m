%% w axis
w = 2*pi*logspace(0,7,1000)';
%% Parameter values
LATop  = 03.40e-9;
LABot  = 20.25e-9;
LAMid  = 01.30e-9;
LBTop  = 03.38e-9;
LBBot  = 20.38e-9;
LBMid  = 01.30e-9;
LCTop  = 03.41e-9;
LCBot  = 20.94e-9;
LCMid  = 01.30e-9;
LABTop = 18.30e-9;
LABBot = 10.20e-9;
LBCTop = 21.84e-9;
LBCBot = 11.14e-9;

ESLA = 19e-15;
ESLB = 19e-15;
ESLC = 19e-15;

C1A = 5e-6;
C1B = 5e-6;
C1C = 5e-6;

%% New merged inducances
L1 = LATop + LABot + ESLA;
L2 = LABTop;
L3 = LABBot;
L4 = ESLB;
L5 = LBTop + LBBot + LBCTop + LBCBot + ESLC;

%% Calculated impedances
Z1 = 1i*w*L5 + 1./(1i*w*C1C);
Z2 = 1i*w*L4 + 1./(1i*w*C1B);
Z3 = Z1.*Z2./(Z1+Z2);
Z4 = Z3 + 1i*w*(L2+L3);
Z5 = 1i*w*L1 + 1./(1i*w*C1A);
Zeqv = Z4.*Z5./(Z4+Z5);

figure;
%hold all;
loglog(w/(2*pi*1000),abs(Zeqv),'-s')
grid on;
set(gca,'FontSize',14);
xlabel('Frequency (kHz)','FontSize',14,'FontWeight','Bold')
ylabel('Magnitude of equivalent impedance','FontSize',14,'FontWeight','Bold')
%xlim([0 40e-3]);
%ylim([-1.2 1.2]);


% plot(time_array,DCBusVoltage,'b-','Linewidth',2);
% plot(time_array,InputVoltage,'r-','Linewidth',2);
