%% MATLAB model for code-based IMMD inverter simulations
% Simulation parameters
Ts = 1e-6; % sec
Tfinal = 0.1; %sec
StepN = uint32(Tfinal/Ts);
StepN2 = Tfinal/Ts;

% Drive parameters
fsw = 1e3; % Hz
Vdc = 540; % Volts
Cdc = 100e-6;
Pout = 8e3/0.94; % W
np = 1;
ns = 1;
n = ns*np;

% Motor parameters
Ef = 155; % Volts
Ls = 13.8e-3; % Henries
Rs = 1e-3; % Ohms
fout = 50; % Hz
wout = 2*pi*fout; % rad/sec
m = 3;

% Control parameter calculation
Poutm = Pout/n; % Watts
Is = Poutm/(Ef*m); % amps
Xs = wout*Ls; % Ohms
Vdrop = Is*Xs; % Volts
Vt = sqrt(Ef^2+Vdrop^2); % Volts
Vdcm = Vdc/ns; % volts
ma = Vt*sqrt(3)/(Vdcm*0.612);
delta = acos(Ef/Vt); % radians
deltad = delta*180/pi; % degrees
pf = cos(delta);
phase = [0 0 0 0];

currentime = 0;
count = 0;
InducedVoltagePhaseA = zeros(1,StepN);
InducedVoltagePhaseB = zeros(1,StepN);
InducedVoltagePhaseC = zeros(1,StepN);
ModSignalPhaseA = zeros(1,StepN);
ModSignalPhaseB = zeros(1,StepN);
ModSignalPhaseC = zeros(1,StepN);
CarrierSignal = zeros(1,StepN);
InverterVoltagePhaseA = zeros(1,StepN);
InverterVoltagePhaseB = zeros(1,StepN);
InverterVoltagePhaseC = zeros(1,StepN);
InverterVoltageVAB = zeros(1,StepN);
InverterVoltageVBC = zeros(1,StepN);
InverterVoltageVCA = zeros(1,StepN);
LineCurrentA = zeros(1,StepN);
LineCurrentB = zeros(1,StepN);
LineCurrentC = zeros(1,StepN);
DCLinkCurrent = zeros(1,StepN);
DCLinkVoltage = zeros(1,StepN);
DCLinkCapacitorCurrent = zeros(1,StepN);

timeaxis = 0:Ts:Tfinal;

% Main loop
tic
while (1)
    count = count+1;
    currenttime = count*Ts;
    
    InducedVoltagePhaseA(count) = Ef*sqrt(2)*sin(wout*currenttime);
    InducedVoltagePhaseB(count) = Ef*sqrt(2)*sin(wout*currenttime-2*pi/3);
    InducedVoltagePhaseC(count) = Ef*sqrt(2)*sin(wout*currenttime-4*pi/3);
    
    ModSignalPhaseA(count) = ma*sin(wout*currenttime+delta);
    ModSignalPhaseB(count) = ma*sin(wout*currenttime+delta-2*pi/3);
    ModSignalPhaseC(count) = ma*sin(wout*currenttime+delta-4*pi/3);
    CarrierSignal(count) = carriergen(currenttime,1,-1,Ts,fsw);
    
    if ModSignalPhaseA(count) >= CarrierSignal(count)
        InverterVoltagePhaseA(count) = Vdcm;
    end
    if ModSignalPhaseB(count) >= CarrierSignal(count)
        InverterVoltagePhaseB(count) = Vdcm;
    end
    if ModSignalPhaseC(count) >= CarrierSignal(count)
        InverterVoltagePhaseC(count) = Vdcm;
    end
    
    InverterVoltageVAB(count) = InverterVoltagePhaseA(count) - InverterVoltagePhaseB(count);
    InverterVoltageVBC(count) = InverterVoltagePhaseB(count) - InverterVoltagePhaseC(count);
    InverterVoltageVCA(count) = InverterVoltagePhaseC(count) - InverterVoltagePhaseA(count);
    
    LineCurrentA(count+1) = LineCurrentA(count) + ...
        Ts*((InverterVoltagePhaseA(count)-Vdcm/2-InducedVoltagePhaseA(count))/Ls);
    LineCurrentB(count+1) = LineCurrentB(count) + ...
        Ts*((InverterVoltagePhaseB(count)-Vdcm/2-InducedVoltagePhaseB(count))/Ls);
    LineCurrentC(count+1) = LineCurrentC(count) + ...
        Ts*((InverterVoltagePhaseC(count)-Vdcm/2-InducedVoltagePhaseC(count))/Ls);
    
    if currenttime > Tfinal
        break;
        % end of the4 simulation
    end
end
toc
fprintf('Simulation finished.\n');

LineCurrentA = LineCurrentA - mean(LineCurrentA);
LineCurrentB = LineCurrentB - mean(LineCurrentB);
LineCurrentC = LineCurrentC - mean(LineCurrentC);
InverterVoltagePhaseA = InverterVoltagePhaseA - mean(InverterVoltagePhaseA);
InverterVoltagePhaseB = InverterVoltagePhaseB - mean(InverterVoltagePhaseB);
InverterVoltagePhaseC = InverterVoltagePhaseC - mean(InverterVoltagePhaseC);
LineCurrentA = LineCurrentA(1:end-1);
LineCurrentB = LineCurrentB(1:end-1);
LineCurrentC = LineCurrentC(1:end-1);
InverterVoltageVAB = InverterVoltageVAB - mean(InverterVoltageVAB);
InverterVoltageVBC = InverterVoltageVBC - mean(InverterVoltageVBC);
InverterVoltageVCA = InverterVoltageVCA - mean(InverterVoltageVCA);
DCLinkCurrent2 = LineCurrentA.*InverterVoltagePhaseA/Vdcm + ...
    LineCurrentB.*InverterVoltagePhaseB/Vdcm + ...
    LineCurrentC.*InverterVoltagePhaseC/Vdcm;
DCLinkAverageCurrent = mean(DCLinkCurrent);
DCLinkCapacitorCurrent = DCLinkCurrent - DCLinkAverageCurrent;
DCLinkRMSCurrent = sqrt(sum(DCLinkCapacitorCurrent.^2)/(StepN2+1));
PhaseARMSCurrent = sqrt(sum(LineCurrentA.^2)/(StepN2+1));
PhaseBRMSCurrent = sqrt(sum(LineCurrentB.^2)/(StepN2+1));
PhaseCRMSCurrent = sqrt(sum(LineCurrentC.^2)/(StepN2+1));
InverterVoltagePhaseARMS = sqrt(sum(InverterVoltagePhaseA.^2)/(StepN2+1));
InverterVoltagePhaseBRMS = sqrt(sum(InverterVoltagePhaseB.^2)/(StepN2+1));
InverterVoltagePhaseVRMS = sqrt(sum(InverterVoltagePhaseC.^2)/(StepN2+1));
InverterVoltageVABRMS = sqrt(sum(InverterVoltageVAB.^2)/(StepN2+1));
InverterVoltageVBCRMS = sqrt(sum(InverterVoltageVBC.^2)/(StepN2+1));
InverterVoltageVCARMS = sqrt(sum(InverterVoltageVCA.^2)/(StepN2+1));
InducedVoltageARMS = sqrt(sum(InducedVoltagePhaseA.^2)/(StepN2));
InducedVoltageBRMS = sqrt(sum(InducedVoltagePhaseB.^2)/(StepN2));
InducedVoltageCRMS = sqrt(sum(InducedVoltagePhaseC.^2)/(StepN2));


for k = 1:StepN
    DCLinkVoltage(k+1) = DCLinkVoltage(k) + Ts*DCLinkCapacitorCurrent(k)/Cdc;
end
WindowLength = 0.005;
DCLinkVoltagePeaktoPeak = max(DCLinkVoltage(find(timeaxis == Tfinal-WindowLength):find(timeaxis == Tfinal)))...
    - min(DCLinkVoltage(find(timeaxis == Tfinal-WindowLength):find(timeaxis == Tfinal)));
DCLinkVoltagePercentRipple = DCLinkVoltagePeaktoPeak/Vdcm*100;



[InverterVoltageAFundRMS,InverterVoltageAFundPhase] = ...
    fundamentalcomp(InverterVoltagePhaseA,Ts,fout);
[InverterVoltageVABFundRMS,InverterVoltageVABFundPhase] = ...
    fundamentalcomp(InverterVoltageVAB,Ts,fout);
[LineCurrentAFundRMS,LineCurrentAFundPhase] = ...
    fundamentalcomp(LineCurrentA,Ts,fout);
[InducedVoltageAFundRMS,InducedVoltageAFundPhase] = ...
    fundamentalcomp(InducedVoltagePhaseA,Ts,fout);

THDInverterVoltagePhaseA = 100*sqrt(InverterVoltagePhaseARMS^2-...
    InverterVoltageAFundRMS^2)/InverterVoltageAFundRMS;
THDInverterVoltageVAB = 100*sqrt(InverterVoltageVABRMS^2-...
    InverterVoltageVABFundRMS^2)/InverterVoltageVABFundRMS;
THDLineCurrentA = 100*sqrt(PhaseARMSCurrent^2-...
    LineCurrentAFundRMS^2)/LineCurrentAFundRMS; % PROBLEML? (RMS düzgün de?il)
THDInducedVoltagePhaseA = 100*sqrt(InducedVoltageARMS^2-...
    InducedVoltageAFundRMS^2)/InducedVoltageAFundRMS;




%% PLAN:
% Instantaneous power, average power, Active, Reactive, Apparent power
% Power factor

% From transistor currents, calculate losses
% Find AC and DC spsctrums

% Extend the topology to Series, Parallel, Series/Parallel
% Try different PWM techniques on this model (2-Level)

% Convertert the model to 3-Level inverter topology
% Try different PWM techniques on this model (3-Level)




%%

% Plots
figure;
plot(timeaxis,LineCurrentA(1:StepN+1),'k-','Linewidth',1);
hold on;
plot(timeaxis,LineCurrentB(1:StepN+1),'r-','Linewidth',1);
hold on;
plot(timeaxis,LineCurrentC(1:StepN+1),'b-','Linewidth',1);
hold on;
%plot(timeaxis,DCLinkCurrent(1:StepN+1),'b-','Linewidth',1);
%hold on;
%plot(timeaxis,DCLinkCapacitorCurrent(1:StepN+1),'k-','Linewidth',1);
%hold on;
%plot(timeaxis,DCLinkVoltage(1:StepN+1),'r-','Linewidth',1);
%hold on;
%plot(timeaxis,InducedVoltagePhaseA,'m-','Linewidth',2);
%hold on;
%plot(timeaxis,ModSignalPhaseA*Vdcm*0.612*sqrt(2)/sqrt(3),'g-','Linewidth',2);
hold off;
grid on;
set(gca,'FontSize',12);
xlabel('Time (s)','FontSize',12,'FontWeight','Bold')
%ylabel('Motor Phase Induced Voltages (Volts)','FontSize',12,'FontWeight','Bold')
%legend('Phase-A','Phase-B','Phase-C');
%legend('Carrier Signal','Modulating Signal','PWM Output');
%ylim([-2 2]);
%xlim([0 0.02])

%%
figure;
plot(timeaxis,DCLinkCurrent(1:StepN+1),'b-','Linewidth',1);
hold on;
plot(timeaxis,DCLinkCapacitorCurrent(1:StepN+1),'k-','Linewidth',1);
hold on;
plot(timeaxis,DCLinkVoltage(1:StepN+1),'r-','Linewidth',1);
hold on;
%plot(timeaxis,InducedVoltagePhaseA,'m-','Linewidth',2);
%hold on;
%plot(timeaxis,ModSignalPhaseA*Vdcm*0.612*sqrt(2)/sqrt(3),'g-','Linewidth',2);
hold off;
grid on;
set(gca,'FontSize',12);
xlabel('Time (s)','FontSize',12,'FontWeight','Bold')
%ylabel('Motor Phase Induced Voltages (Volts)','FontSize',12,'FontWeight','Bold')
%legend('Phase-A','Phase-B','Phase-C');
%legend('Carrier Signal','Modulating Signal','PWM Output');
%ylim([-2 2]);
%xlim([0 0.02])


%% BELOW ARE NOT USED
%Rin = 10;
%Lin = 1e-3;
%Vin = Vdc + Rin*(Pout/Vdc);



% WindowCycle = 1;
% SampleInWindow = WindowCycle/(Ts*fout);
% MaxHarmonic = 1;
% FourierSeriesAk = zeros(1,MaxHarmonic);
% FourierSeriesBk = zeros(1,MaxHarmonic);
% FourierSeriesAo = zeros(1,1);
% %FunctionHarmonic = InducedVoltagePhaseA;
% %FunctionHarmonic = LineCurrentA;
% FunctionHarmonic = InverterVoltageVAB;
% for k = 1:SampleInWindow
%     radang = (k-1)*pi/(SampleInWindow/2);
%     radang = double(radang);
%     FourierSeriesAo = FourierSeriesAo+FunctionHarmonic(1,k);
%     for l = 1:MaxHarmonic
%         FourierSeriesAk(l) = FourierSeriesAk(l)+FunctionHarmonic(1,k)*cos(l*radang);
%         FourierSeriesBk(l) = FourierSeriesBk(l)+FunctionHarmonic(1,k)*sin(l*radang);
%     end
% end
% DCValue = FourierSeriesAo/SampleInWindow;
%
%
% for l = 1:MaxHarmonic
%     a = 2*FourierSeriesAk(l)/SampleInWindow;
%     b = 2*FourierSeriesBk(l)/SampleInWindow;
%     peak_magn(l) = sqrt(a.^2+b.^2);
%     fprintf('\n%gth:%g\n',l,peak_magn(l)/sqrt(2));
% end


% 
% 
% FourierSeriesAk = 0;
% FourierSeriesBk = 0;
% FourierSeriesAo = 0;
% FunctionHarmonic = InverterVoltagePhaseA;
% %FunctionHarmonic = LineCurrentA;
% %FunctionHarmonic = InverterVoltageVAB;
% for k = 1:SampleInWindow
%     FourierSeriesAo = FourierSeriesAo+FunctionHarmonic(k);
%     FourierSeriesAk = FourierSeriesAk+FunctionHarmonic(k)*...
%         cos(double((k-1)*pi/(SampleInWindow/2)));
%     FourierSeriesBk = FourierSeriesBk+FunctionHarmonic(k)*...
%         sin(double((k-1)*pi/(SampleInWindow/2)));
% end
% DCValue = FourierSeriesAo/SampleInWindow
% CosValue = 2*FourierSeriesAk/SampleInWindow;
% SinValue = 2*FourierSeriesBk/SampleInWindow;
% FundamentalPeak = sqrt(CosValue.^2 + SinValue.^2);
% FudamentalRMS = FundamentalPeak/sqrt(2)
% 
% 
% 
