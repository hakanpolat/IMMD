%% ECCE Loss Model
%% Initialization
% Device Parameters
Cgd = 2e-12;
Cgs = 258e-12;
Cds = 63e-12;

Ls = 62e-12;
Ld = 450e-12;
Lg = 0.65e-9;
Lss = 0.43e-9;

Rg = 1.5;
Rd = 0.0024 + 1e-4;
Rs = 0.0433 + 1e-4;
Rss = 1e-3;

Rt = (0.9*0.95*0.82*18.2/295 + 3.6*0.238*0.82/295);

% Circuit Parasitics
Ldc = 1.5e-9;
Lground = 5e-9;
Lp = 10e-12;
% Gate Driver
Lgex = 3e-9;
Ron = 10;
Roff = 2;
% Source parameters
PulseAmplitude = 9;
fsw = 2000e3;
Vdc = 400;
VpulseMax = 6;
VpulseMin = -3;
% Quantities in below are in percent
Dtop = 48; % duty cycle of top
Dbot = 48; % duty cycle of bot
DelayTop = 0;
DelayBot = 50;
SampleTime =  5e-13;

% Load parameters
LoadCurrent = 30;
Lload = 480e-6;

CurrRipple = Vdc*(Dbot/100)/(fsw*Lload);
InitialCurrent = LoadCurrent + CurrRipple/2;

Req = Rg + Rs + Ron;
Leq = Lgex + Lg + Ls + Lp;
Ceq = Cgs + Cgd;
%% Time & I-V Calculator

% tdelayon = Req*220e-12*log((VpulseMax - VpulseMin)/(VpulseMax)) + Req*360e-12*log((VpulseMax)/(VpulseMax-1.7))...
%     + 5e-10*(1.7/(1.7 - VpulseMin)); %1e-10 placed to compensate gate voltage source rise time
% VgsFit(j)_tcrl = 2 + (LoadCurrent - 5)/40; %VgsFit(j) value when current reaches to load ampere
% time_cur_RiseToLoad = Req*(600e-12)*log((VpulseMax - 1.7)/(VpulseMax - VgsFit(j)_tcrl));
% time_cur_RiseToPeak = Req*(600e-12)*log((VpulseMax - VgsFit(j)_tcrl)/(VpulseMax - VgsFit(j)_tcrl - 0.65));

%% Loss Calculator
% 
% Eon = Vdc * LoadCurrent/2 * time_cur_RiseToLoad + ...
%     (Vdc + Vi_peak)/2 * (LoadCurrent + Ipeak)/2 * time_cur_RiseToPeak + ...
%     Vi_peak/2 * (Ipeak + LoadCurrent)/2 * time_cur_FallToLoad;

%% Turn ON - Turn OFF Waveform MODEL 3
t1 = 2.4e-7;
t2 = 2.8e-7;
n1 = t1/SampleTime;
n2 = t2/SampleTime;
% Turn ON Waveforms
figure 
hold all
grid on
ax = gca;
title('I_{ds}, V_{ds} and V_{gs} waveforms for Turn-on Period (Model 3)','FontSize',12,'FontWeight','bold','Color','k');
xlabel('Time(sec)','FontSize',12,'FontWeight','bold','Color','k');
ylabel('Current (A), Voltage(V)','FontSize',12,'FontWeight','bold','Color','k');
ax.FontSize = 12;
ax.XTick = [t1:0.1e-7:t2];
plot(t1:SampleTime:t2, BotVoltDSM3(n1:n2)/50,'LineWidth',3.0,'Color','r');
plot(t1:SampleTime:t2, BotDSCurrM3(n1:n2)/5,'LineWidth',3.0,'Color','b');
plot(t1:SampleTime:t2, BotVoltGSM3(n1:n2),'LineWidth',3.0,'Color','g');
xlim([t1 t2])
legend('V_{ds} (x1/50)','I_{ds} (x1/5)','V_{gs}','Location','SouthEast');
hold off
% Turn ON Loss Graph
figure 
hold all
grid on
ax = gca;
title('Instantaneous Turn-On Loss Graph (Model 3)','FontSize',12,'FontWeight','bold','Color','k');
xlabel('Time(sec)','FontSize',12,'FontWeight','bold','Color','k');
ylabel('Loss(kW)','FontSize',12,'FontWeight','bold','Color','k');
ax.FontSize = 12;
ax.XTick = [t1:0.1e-7:t2];
plot(t1:SampleTime:t2, BotDSCurrM3(n1:n2).*BotVoltDSM3(n1:n2)/1000,'LineWidth',3.0,'Color','k');
xlim([t1 t2])
hold off
% Turn OFF Waveforms
t1 = 4.8e-7;
t2 = 5.1e-7;
n1 = t1/SampleTime;
n2 = t2/SampleTime;
figure
hold all
grid on
ax = gca;
title('I_{ds}, V_{ds} and V_{gs} waveforms for Turn-off Period (Model 3)','FontSize',12,'FontWeight','bold','Color','k');
xlabel('Time(sec)','FontSize',12,'FontWeight','bold','Color','k');
ylabel('Current (A), Voltage(V)','FontSize',12,'FontWeight','bold','Color','k');
ax.FontSize = 12;
ax.XTick = [t1:0.1e-7:t2];
plot(t1:SampleTime:t2, BotVoltDSM3(n1:n2)/50,'LineWidth',3.0,'Color','r');
plot(t1:SampleTime:t2, BotDSCurrM3(n1:n2)/5,'LineWidth',3.0,'Color','b');
plot(t1:SampleTime:t2, BotVoltGSM3(n1:n2),'LineWidth',3.0,'Color','g');
xlim([t1 t2])
legend('V_{ds} (x1/50)','I_{ds} (x1/5)','V_{gs}','Location','SouthWest');
hold off
%Turn OFF Loss Graph
figure 
hold all
grid on
ax = gca;
title('Instantaneous Turn-Off Loss Graph (Model 3)','FontSize',12,'FontWeight','bold','Color','k');
xlabel('Time(sec)','FontSize',12,'FontWeight','bold','Color','k');
ylabel('Loss(kW)','FontSize',12,'FontWeight','bold','Color','k');
ax.FontSize = 12;
ax.XTick = [t1:0.1e-7:t2];
plot(t1:SampleTime:t2, BotDSCurrM3(n1:n2).*BotVoltDSM3(n1:n2)/1000,'LineWidth',3.0,'Color','k');
xlim([t1 t2])
hold off
%% Turn ON - Turn OFF Waveform MODEL 2
t1 = 2.4e-7;
t2 = 2.8e-7;
n1 = t1/SampleTime;
n2 = t2/SampleTime;
figure 
hold all
grid on
ax = gca;
title('I_{ds}, V_{ds} and V_{gs} waveforms for Turn-on Period (Model 2)','FontSize',12,'FontWeight','bold','Color','k');
xlabel('Time(sec)','FontSize',12,'FontWeight','bold','Color','k');
ylabel('Current (A), Voltage(V)','FontSize',12,'FontWeight','bold','Color','k');
ax.FontSize = 12;
ax.XTick = [t1:0.1e-7:t2];
plot(t1:SampleTime:t2, BotVoltDSM2(n1:n2)/50,'LineWidth',3.0,'Color','r');
plot(t1:SampleTime:t2, BotDSCurrM2(n1:n2)/5,'LineWidth',3.0,'Color','b');
plot(t1:SampleTime:t2, BotVoltGSM2(n1:n2),'LineWidth',3.0,'Color','g');
xlim([t1 t2])
legend('V_{ds} (x1/50)','I_{ds} (x1/5)','V_{gs}','Location','SouthEast');
hold off

t1 = 4.8e-7;
t2 = 5.1e-7;
n1 = t1/SampleTime;
n2 = t2/SampleTime;
figure 
hold all
grid on
ax = gca;
title('I_{ds}, V_{ds} and V_{gs} waveforms for Turn-off Period (Model 2)','FontSize',12,'FontWeight','bold','Color','k');
xlabel('Time(sec)','FontSize',12,'FontWeight','bold','Color','k');
ylabel('Current (A), Voltage(V)','FontSize',12,'FontWeight','bold','Color','k');
ax.FontSize = 12;
ax.XTick = [t1:0.1e-7:t2];
plot(t1:SampleTime:t2, BotVoltDSM2(n1:n2)/50,'LineWidth',3.0,'Color','r');
plot(t1:SampleTime:t2, BotDSCurrM2(n1:n2)/5,'LineWidth',3.0,'Color','b');
plot(t1:SampleTime:t2, BotVoltGSM2(n1:n2),'LineWidth',3.0,'Color','g');
xlim([t1 t2])
legend('V_{ds} (x1/50)','I_{ds} (x1/5)','V_{gs}','Location','SouthWest');
hold off
%% Turn ON - Turn OFF Waveform MODEL 1
t1 = 2.4e-7;
t2 = 2.8e-7;
n1 = t1/SampleTime;
n2 = t2/SampleTime;
figure 
hold all
grid on
ax = gca;
title('I_{ds}, V_{ds} and V_{gs} waveforms for Turn-on Period (Model 1)','FontSize',12,'FontWeight','bold','Color','k');
xlabel('Time(sec)','FontSize',12,'FontWeight','bold','Color','k');
ylabel('Current (A), Voltage(V)','FontSize',12,'FontWeight','bold','Color','k');
ax.FontSize = 12;
ax.XTick = [t1:0.1e-7:t2];
plot(t1:SampleTime:t2, BotVoltDSM1(n1:n2)/50,'LineWidth',3.0,'Color','r');
plot(t1:SampleTime:t2, BotDSCurrM1(n1:n2)/5,'LineWidth',3.0,'Color','b');
plot(t1:SampleTime:t2, BotVoltGSM1(n1:n2),'LineWidth',3.0,'Color','g');
xlim([t1 t2])
legend('V_{ds} (x1/50)','I_{ds} (x1/5)','V_{gs}','Location','SouthEast');
hold off

t1 = 4.8e-7;
t2 = 5.1e-7;
n1 = t1/SampleTime;
n2 = t2/SampleTime;
figure 
hold all
grid on
ax = gca;
title('I_{ds}, V_{ds} and V_{gs} waveforms for Turn-off Period (Model 1)','FontSize',12,'FontWeight','bold','Color','k');
xlabel('Time(sec)','FontSize',12,'FontWeight','bold','Color','k');
ylabel('Current (A), Voltage(V)','FontSize',12,'FontWeight','bold','Color','k');
ax.FontSize = 12;
ax.XTick = [t1:0.1e-7:t2];
plot(t1:SampleTime:t2, BotVoltDSM1(n1:n2)/50,'LineWidth',3.0,'Color','r');
plot(t1:SampleTime:t2, BotDSCurrM1(n1:n2)/5,'LineWidth',3.0,'Color','b');
plot(t1:SampleTime:t2, BotVoltGSM1(n1:n2),'LineWidth',3.0,'Color','g');
xlim([t1 t2])
legend('V_{ds} (x1/50)','I_{ds} (x1/5)','V_{gs}','Location','SouthWest');
hold off

%% VgsFit(j) - CissCalc(j) Calc and Plot
%Load Fitted Vgs and Ciss curves from MatFileStore Folder
%Calc
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
TemporaryMatrix = size(VgsFit);
SizeMatrix = TemporaryMatrix(1);
clear TemporaryMatrix;
for j=1:SizeMatrix
CissCalc(j) = a1.*exp(-((VgsFit(j)-b1)./c1).^2) + a2.*exp(-((VgsFit(j)-b2)./c2).^2) + a3*exp(-((VgsFit(j)-b3)./c3).^2)...
   + a4.*exp(-((VgsFit(j)-b4)./c4).^2) +a5.*exp(-((VgsFit(j)-b5)./c5).^2) +a6.*exp(-((VgsFit(j)-b6)./c6).^2);
%CissCalc(j) = CissCalc(j)*1e-12;
end
% Plot
figure 
hold all
grid on
ax = gca;
title('C_{ISS} vs V_{GS} Graph','FontSize',12,'FontWeight','bold','Color','k');
xlabel('V_{GS} (Volts)','FontSize',12,'FontWeight','bold','Color','k');
ylabel('C_{ISS} (pF)','FontSize',12,'FontWeight','bold','Color','k');
ax.FontSize = 12;
ax.XTick = [-10:5:10];
plot(VgsFit, CissCalc,'LineWidth',3.0,'Color','r');
plot(VgsFit, CissFit,'LineWidth',3.0,'Color','b');
line([1.7 1.7],[0 700],'LineWidth',3,'LineStyle',':','Color','k');
set(gca, 'XTick', sort([1.7, get(gca, 'XTick')]));
xlim([-10 10])
ylim([0 700])
legend('Modeled C_{ISS}','Reference C_{ISS}','Threshold Voltage','Location','NorthWest');
hold off

%% Turn ON Plots
figure 
hold all
grid on
ax = gca
title('Turn-on Loss of the Models','FontSize',12,'FontWeight','bold','Color','k');
xlabel('Load Current (A)','FontSize',12,'FontWeight','bold','Color','k');
ylabel('E_{on} (\muJ)','FontSize',12,'FontWeight','bold','Color','k');
ax.FontSize = 12;
plot(Load, Model1_Eon,'LineWidth',3.0,'Color','r');
plot(Load, Model2_Eon,'LineWidth',3.0,'Color','b');
plot(Load, Model3_Eon,'LineWidth',3.0,'Color','m');
legend('Model 1','Model 2','Model 3','Location','NorthWest');
hold off
%% Turn OFF Plots
figure 
hold all
grid on
ax = gca
title('Turn-off Loss of the Models','FontSize',12,'FontWeight','bold','Color','k');
xlabel('Load Current (A)','FontSize',12,'FontWeight','bold','Color','k');
ylabel('E_{off} (\muJ)','FontSize',12,'FontWeight','bold','Color','k');
ax.FontSize = 12;
plot(Load, Model1_Eoff,'LineWidth',3.0,'Color','r');
plot(Load, Model2_Eoff,'LineWidth',3.0,'Color','b');
plot(Load, Model3_Eoff,'LineWidth',3.0,'Color','m');
legend('Model 1','Model 2','Model 3','Location','NorthWest');
hold off
%% Eon + Eoff Plots
figure 
hold all
grid on
ax = gca
title('E_{ON} + E_{OFF} Graph','FontSize',12,'FontWeight','bold','Color','k');
xlabel('Load Current (A)','FontSize',12,'FontWeight','bold','Color','k');
ylabel('E_{ON}+E_{OFF} (\muJ)','FontSize',12,'FontWeight','bold','Color','k');
ax.FontSize = 12;
plot(Load, Model1_Eoff + Model1_Eon,'LineWidth',3.0,'Color','r');
plot(Load, Model2_Eoff + Model2_Eon,'LineWidth',3.0,'Color','b');
plot(Load, Model3_Eoff + Model3_Eon,'LineWidth',3.0,'Color','m');
plot(Load, ModelP,'LineWidth',3.0,'Color','k','LineStyle','--');
legend('Model 1','Model 2','Model 3','Experiment','Location','NorthWest');
hold off
%% Current Rise Time Plots
figure 
hold all
grid on
ax = gca;
title('Current Rise Time of the Models','FontSize',12,'FontWeight','bold','Color','k');
xlabel('Load Current (A)','FontSize',12,'FontWeight','bold','Color','k');
ylabel('t_{cr} (ns)','FontSize',12,'FontWeight','bold','Color','k');
ax.FontSize = 12;
plot(Load, Model1_tcr,'LineWidth',3.0,'Color','r');
plot(Load, Model2_tcr,'LineWidth',3.0,'Color','b');
plot(Load, Model3_tcr,'LineWidth',3.0,'Color','g');
legend('Model 1','Model 2','Model 3','Location','NorthWest');
hold off
%% Voltage Fall Time Plots
figure 
hold all
grid on
ax = gca;
title('Voltage Fall Time of the Models','FontSize',12,'FontWeight','bold','Color','k');
xlabel('Load Current (A)','FontSize',12,'FontWeight','bold','Color','k');
ylabel('t_{vf} (ns)','FontSize',12,'FontWeight','bold','Color','k');
ax.FontSize = 12;
plot(Load, Model1_tvf,'LineWidth',3.0,'Color','r');
plot(Load, Model2_tvf,'LineWidth',3.0,'Color','b');
plot(Load, Model3_tvf,'LineWidth',3.0,'Color','g');
legend('Model 1','Model 2','Model 3','Location','NorthWest');
hold off
%% Current Fall Time - Voltage Rise Time Plots
figure 
hold all
grid on
ax = gca;
title('Current Fall Time - Voltage Rise Time of the Models','FontSize',12,'FontWeight','bold','Color','k');
xlabel('Load Current (A)','FontSize',12,'FontWeight','bold','Color','k');
ylabel('t_{cf} - t_{vr} (ns)','FontSize',12,'FontWeight','bold','Color','k');
ax.FontSize = 12;
plot(Load, Model1_tcf,'LineWidth',3.0,'Color','r');
plot(Load, Model2_tcf,'LineWidth',3.0,'Color','b');
plot(Load, Model3_tcf,'LineWidth',3.0,'Color','g');
legend('Model 1','Model 2','Model 3','Location','NorthEast');
hold off