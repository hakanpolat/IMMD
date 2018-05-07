%% MATLAB model for code-based IMMD inverter simulations
% Simulation parameters
Ts = 1e-6; % sec
Tfinal = 0.1; %sec
Ripth = 0.08; % sec
StepN = uint32(Tfinal/Ts);
StepN2 = Tfinal/Ts;

% Drive parameters
fsw = 10e3; % Hz
Vdc = 540; % Volts
Cdc = 100e-6; % Per series module group
Pout = 8e3/0.94; % W % Total output power
np = 2;
ns = 1;
n = ns*np;

% For simulations only
%phase = [0 90 0 90];
Rin = 10;
Vin = Vdc + Rin*(Pout/Vdc);

% Motor parameters
Ef = 155; % Volts
Efm = Ef/ns;
Ls = 13.8e-3; % Henries
%Ls = 50e-3; % Henries
Lsm = Ls/n;
Rs = 1e-9; % Ohms
Rsm = 1e-9/n; % Ohms
fout = 50; % Hz
wout = 2*pi*fout; % rad/sec
m = 3;

% Control parameter calculation
Poutm = Pout/n; % Watts
Is = Poutm/(Efm*m); % amps
Xsm = wout*Lsm; % Ohms
Vdrop = Is*Xsm; % Volts
Vt = sqrt(Efm^2+Vdrop^2); % Volts
Vdcm = Vdc/ns; % volts
ma = Vt*sqrt(3)/(Vdcm*0.612);
delta = acos(Efm/Vt); % radians
deltad = delta*180/pi; % degrees
pf = cos(delta);
phase = [0 0];

currentime = 0;
count = 0;
InducedVoltagePhaseA = zeros(1,StepN);
InducedVoltagePhaseB = zeros(1,StepN);
InducedVoltagePhaseC = zeros(1,StepN);
ModSignalPhaseA = zeros(1,StepN);
ModSignalPhaseB = zeros(1,StepN);
ModSignalPhaseC = zeros(1,StepN);
CarrierSignal = zeros(n,StepN);
InverterVoltagePhaseA = zeros(n,StepN);
InverterVoltagePhaseB = zeros(n,StepN+1);
InverterVoltagePhaseC = zeros(n,StepN);
InverterVoltageVAB = zeros(n,StepN);
InverterVoltageVBC = zeros(n,StepN);
InverterVoltageVCA = zeros(n,StepN);
LineCurrentA = zeros(n,StepN);
LineCurrentB = zeros(n,StepN);
LineCurrentC = zeros(n,StepN);
DCLinkCurrent = zeros(n,StepN+1);
DCLinkVoltage = zeros(ns,StepN);
DCLinkCapacitorCurrent = zeros(ns,StepN+1);
DCLinkAverageCurrent = zeros(1,n);
DCLinkRMSCurrent = zeros(1,ns);
PhaseARMSCurrent = zeros(1,n);
PhaseBRMSCurrent = zeros(1,n);
PhaseCRMSCurrent = zeros(1,n);
InverterVoltagePhaseARMS = zeros(1,n);
InverterVoltagePhaseBRMS = zeros(1,n);
InverterVoltagePhaseCRMS = zeros(1,n);
InverterVoltageVABRMS = zeros(1,n);
InverterVoltageVBCRMS = zeros(1,n);
InverterVoltageVCARMS = zeros(1,n);
DCLinkVoltagePeaktoPeak = zeros(1,ns);
DCLinkVoltagePercentRipple = zeros(1,ns);
InverterVoltageAFundRMS = zeros(1,n);
InverterVoltageVABFundRMS = zeros(1,n);
LineCurrentAFundRMS = zeros(1,n);
InducedVoltageAFundRMS = 0;
InverterVoltageAFundPhase = zeros(1,n);
InverterVoltageVABFundPhase = zeros(1,n);
LineCurrentAFundPhase = zeros(1,n);
InducedVoltageAFundPhase = 0;
THDInverterVoltagePhaseA = zeros(1,n);
THDInverterVoltageVAB = zeros(1,n);
THDLineCurrentA = zeros(1,n);
THDInducedVoltagePhaseA = 0;
AvgPowerMotorPhaseA = zeros(1,n);
AvgPowerMotorPhaseB = zeros(1,n);
AvgPowerMotorPhaseC = zeros(1,n);
AvgPowerMotor = zeros(1,n);
AvgPowerInverterPhaseA = zeros(1,n);
ApperantPowerInverterPhaseA = zeros(1,n);
PowerFactorInverter = zeros(1,n);
ReactivePowerInverter = zeros(1,n);
ActivePowerInverter = zeros(1,n);
ActivePowerInverterPhaseA = zeros(1,n);

timeaxis = 0:Ts:Tfinal;

% Main loop
tic
while (1)
    count = count+1;
    currenttime = count*Ts;
    
    InducedVoltagePhaseA(count) = Efm*sqrt(2)*sin(wout*currenttime);
    InducedVoltagePhaseB(count) = Efm*sqrt(2)*sin(wout*currenttime-2*pi/3);
    InducedVoltagePhaseC(count) = Efm*sqrt(2)*sin(wout*currenttime-4*pi/3);
    
    ModSignalPhaseA(count) = ma*sin(wout*currenttime+delta);
    ModSignalPhaseB(count) = ma*sin(wout*currenttime+delta-2*pi/3);
    ModSignalPhaseC(count) = ma*sin(wout*currenttime+delta-4*pi/3);
    
    %phase = [0 0 0 0];
    %phase = 0;
    
    CarrierSignal(:,count) = carriergen(currenttime,1,-1,fsw,phase)';
    
    for index = 1:n
        
        if ModSignalPhaseA(count) >= CarrierSignal(index,count)
            InverterVoltagePhaseA(index,count) = Vdcm;
        end
        if ModSignalPhaseB(count) >= CarrierSignal(index,count)
            InverterVoltagePhaseB(index,count) = Vdcm;
        end
        if ModSignalPhaseC(count) >= CarrierSignal(index,count)
            InverterVoltagePhaseC(index,count) = Vdcm;
        end
        
        InverterVoltageVAB(index,count) = InverterVoltagePhaseA(index,count)...
            - InverterVoltagePhaseB(index,count);
        InverterVoltageVBC(index,count) = InverterVoltagePhaseB(index,count)...
            - InverterVoltagePhaseC(index,count);
        InverterVoltageVCA(index,count) = InverterVoltagePhaseC(index,count)...
            - InverterVoltagePhaseA(index,count);
        
        LineCurrentA(index,count+1) = LineCurrentA(index,count) + ...
            Ts*(InverterVoltageVAB(index,count)-InverterVoltageVCA(index,count)...
            -2*InducedVoltagePhaseA(count)+InducedVoltagePhaseB(count)...
            +InducedVoltagePhaseC(count))/(3*Lsm);
        
        LineCurrentB(index,count+1) = LineCurrentB(index,count) + ...
            Ts*(InverterVoltageVBC(index,count)-InverterVoltageVAB(index,count)...
            -2*InducedVoltagePhaseB(count)+InducedVoltagePhaseA(count)...
            +InducedVoltagePhaseC(count))/(3*Lsm);
        
        LineCurrentC(index,count+1) = LineCurrentC(index,count) + ...
            Ts*(InverterVoltageVCA(index,count)-InverterVoltageVBC(index,count)...
            -2*InducedVoltagePhaseC(count)+InducedVoltagePhaseB(count)...
            +InducedVoltagePhaseA(count))/(3*Lsm);
        
    end
    if currenttime > Tfinal
        break;
        % end of the simulation
    end
end

LineCurrentA(:,end) = [];
LineCurrentB(:,end) = [];
LineCurrentC(:,end) = [];

for index = 1:n
    LineCurrentA(index,:) = LineCurrentA(index,:) - mean(LineCurrentA(index,:));
    LineCurrentB(index,:) = LineCurrentB(index,:) - mean(LineCurrentB(index,:));
    LineCurrentC(index,:) = LineCurrentC(index,:) - mean(LineCurrentC(index,:));
    InverterVoltagePhaseA(index,:) = InverterVoltagePhaseA(index,:)...
        - mean(InverterVoltagePhaseA(index,:));
    InverterVoltagePhaseB(index,:) = InverterVoltagePhaseB(index,:)...
        - mean(InverterVoltagePhaseB(index,:));
    InverterVoltagePhaseC(index,:) = InverterVoltagePhaseC(index,:)...
        - mean(InverterVoltagePhaseC(index,:));
    
    InverterVoltageVAB(index,:) = InverterVoltageVAB(index,:)...
        - mean(InverterVoltageVAB(index,:));
    InverterVoltageVBC(index,:) = InverterVoltageVBC(index,:)...
        - mean(InverterVoltageVBC(index,:));
    InverterVoltageVCA(index,:) = InverterVoltageVCA(index,:)...
        - mean(InverterVoltageVCA(index,:));
    DCLinkCurrent(index,:) = LineCurrentA(index,:).*InverterVoltagePhaseA(index,:)/Vdcm + ...
        LineCurrentB(index,:).*InverterVoltagePhaseB(index,:)/Vdcm + ...
        LineCurrentC(index,:).*InverterVoltagePhaseC(index,:)/Vdcm;
    DCLinkAverageCurrent(index) = mean(DCLinkCurrent(index,:));
    
    
end

for index2 = 1:ns
    for index3 = 1:np
        DCLinkCapacitorCurrent(index2,:) = DCLinkCapacitorCurrent(index2,:)...
            -DCLinkCurrent(index3,:)...
            + DCLinkAverageCurrent(index3);
    end
end
for index2 = 1:ns
    DCLinkRMSCurrent(index2) = sqrt(sum(DCLinkCapacitorCurrent(index2,:).^2)...
        /(StepN2+1));
end
for index = 1:n
    PhaseARMSCurrent(index) = sqrt(sum(LineCurrentA(index,:).^2)...
        /(StepN2+1));
    PhaseBRMSCurrent(index) = sqrt(sum(LineCurrentB(index,:).^2)...
        /(StepN2+1));
    PhaseCRMSCurrent(index) = sqrt(sum(LineCurrentC(index,:).^2)...
        /(StepN2+1));
    InverterVoltagePhaseARMS(index) = sqrt(sum(InverterVoltagePhaseA(index,:).^2)...
        /(StepN2+1));
    InverterVoltagePhaseBRMS(index) = sqrt(sum(InverterVoltagePhaseB(index,:).^2)...
        /(StepN2+1));
    InverterVoltagePhaseCRMS(index) = sqrt(sum(InverterVoltagePhaseC(index,:).^2)...
        /(StepN2+1));
    InverterVoltageVABRMS(index) = sqrt(sum(InverterVoltageVAB(index,:).^2)...
        /(StepN2+1));
    InverterVoltageVBCRMS(index) = sqrt(sum(InverterVoltageVBC(index,:).^2)...
        /(StepN2+1));
    InverterVoltageVCARMS(index) = sqrt(sum(InverterVoltageVCA(index,:).^2)...
        /(StepN2+1));
end

InducedVoltageARMS = sqrt(sum(InducedVoltagePhaseA.^2)...
        /(StepN2));
InducedVoltageBRMS = sqrt(sum(InducedVoltagePhaseB.^2)...
        /(StepN2));
InducedVoltageCRMS = sqrt(sum(InducedVoltagePhaseC.^2)...
        /(StepN2));
    
for index2 = 1:ns
    for k = 1:StepN
        DCLinkVoltage(index2,k+1) = DCLinkVoltage(index2,k) +...
            Ts*DCLinkCapacitorCurrent(index2,k)/Cdc;
    end
    DCRippleWindowLength = 0.005;
    DCLinkVoltagePeaktoPeak(index2) = max(DCLinkVoltage(find(timeaxis == Tfinal-DCRippleWindowLength):find(timeaxis == Tfinal)))...
        - min(DCLinkVoltage(find(timeaxis == Tfinal-DCRippleWindowLength):find(timeaxis == Tfinal)));
    DCLinkVoltagePercentRipple(index2) = DCLinkVoltagePeaktoPeak(index2)/Vdcm*100;
end


for index = 1:n
    [InverterVoltageAFundRMS(index),InverterVoltageAFundPhase(index)] = ...
        fundamentalcomp(InverterVoltagePhaseA(index,:),Ts,fout);
    [InverterVoltageVABFundRMS(index),InverterVoltageVABFundPhase(index)] = ...
        fundamentalcomp(InverterVoltageVAB(index,:),Ts,fout);
    [LineCurrentAFundRMS(index),LineCurrentAFundPhase(index)] = ...
        fundamentalcomp(LineCurrentA(index,:),Ts,fout);
    [InducedVoltageAFundRMS,InducedVoltageAFundPhase] = ...
        fundamentalcomp(InducedVoltagePhaseA,Ts,fout);
    
    THDInverterVoltagePhaseA(index) = 100*sqrt(InverterVoltagePhaseARMS(index)^2-...
        InverterVoltageAFundRMS(index)^2)/InverterVoltageAFundRMS(index);
    THDInverterVoltageVAB(index) = 100*sqrt(InverterVoltageVABRMS(index)^2-...
        InverterVoltageVABFundRMS(index)^2)/InverterVoltageVABFundRMS(index);
    THDLineCurrentA(index) = 100*sqrt(PhaseARMSCurrent(index)^2-...
        LineCurrentAFundRMS(index)^2)/LineCurrentAFundRMS(index); % PROBLEML? (RMS düzgün de?il)
    THDInducedVoltagePhaseA = 100*sqrt(InducedVoltageARMS^2-...
        InducedVoltageAFundRMS^2)/InducedVoltageAFundRMS;
    
    InstPowerMotorPhaseA = InducedVoltagePhaseA.*LineCurrentA(index,:);
    AvgPowerMotorPhaseA(index) = mean( InstPowerMotorPhaseA((StepN-(1/Ts)/fout):StepN) );
    InstPowerMotorPhaseB = InducedVoltagePhaseB.*LineCurrentB(index,:);
    AvgPowerMotorPhaseB(index) = mean( InstPowerMotorPhaseB((StepN-(1/Ts)/fout):StepN) );
    InstPowerMotorPhaseC = InducedVoltagePhaseC.*LineCurrentC(index,:);
    AvgPowerMotorPhaseC(index) = mean( InstPowerMotorPhaseC((StepN-(1/Ts)/fout):StepN) );
    AvgPowerMotor(index) = AvgPowerMotorPhaseA(index) +...
        AvgPowerMotorPhaseB(index) + AvgPowerMotorPhaseC(index);
    
    InstPowerInverterPhaseA = InverterVoltagePhaseA(index,:).*LineCurrentA(index,:);
    AvgPowerInverterPhaseA(index) = mean( InstPowerInverterPhaseA((StepN-(1/Ts)/fout):StepN) );
    
    ApperantPowerInverterPhaseA(index) = InverterVoltageAFundRMS(index)...
        *LineCurrentAFundRMS(index);
    ActivePowerInverterPhaseA(index) = ApperantPowerInverterPhaseA(index)*...
        cos(pi/180*(InverterVoltageAFundPhase(index)-LineCurrentAFundPhase(index)));
    PowerFactorInverter(index) = ActivePowerInverterPhaseA(index)...
        /ApperantPowerInverterPhaseA(index);
    ReactivePowerInverter(index) = 3*ApperantPowerInverterPhaseA(index)*...
        sin(pi/180*(InverterVoltageAFundPhase(index)-LineCurrentAFundPhase(index)));
    ActivePowerInverter(index) = 3*ApperantPowerInverterPhaseA(index)*...
        cos(pi/180*(InverterVoltageAFundPhase(index)-LineCurrentAFundPhase(index)));
    
end

toc
fprintf('Simulation finished.\n');

%%
tic
sim('modelsim_2p');
% LinecurrentsimA
% VABsim
% VAOsim
% DCcapcursim
% DCLinkRipplesim
toc
fprintf('Simulation finished.\n');

%%
% Plots
figure;
plot(timeaxis,LineCurrentA(1,1:StepN+1)*1,'k-','Linewidth',1);
hold all;
%plot(timeaxis,LineCurrentB(1,1:StepN+1),'r-','Linewidth',1);
%plot(timeaxis,LineCurrentC(1,1:StepN+1),'b-','Linewidth',1);
plot(timeaxis,InverterVoltagePhaseA(1,1:StepN+1),'b-','Linewidth',1);
%plot(timeaxis,LinecurrentsimA(:,1),'r-','Linewidth',1);
%plot(timeaxis,DCLinkCurrent(1:StepN+1),'r-','Linewidth',1);
%plot(timeaxis,DCLinkCapacitorCurrent(1:StepN+1),'k-','Linewidth',1);
%plot(timeaxis,VABsim(1:StepN+1),'b-','Linewidth',1);
%plot(timeaxis,InverterVoltageVAB(1:StepN+1),'r-','Linewidth',1);
plot(timeaxis,InducedVoltagePhaseA(1,:),'m-','Linewidth',2);
plot(timeaxis,ModSignalPhaseA(1,:)*Vdcm*0.612*sqrt(2)/sqrt(3),'g-','Linewidth',2);
grid on;
set(gca,'FontSize',12);
xlabel('Time (s)','FontSize',12,'FontWeight','Bold')
%ylabel('Motor Phase Induced Voltages (Volts)','FontSize',12,'FontWeight','Bold')
%legend('Phase-A','Phase-B','Phase-C');
%legend('Carrier Signal','Modulating Signal','PWM Output');
%ylim([-2 2]);
%xlim([0.08 0.1])


%%
tic
sim('immd_design_icem2');
% LinecurrentsimA
% VABsim
% VAOsim
% DCcapcursim
% DCLinkRipplesim
toc
fprintf('Simulation finished.\n');


%%
%
figure;
plot(timeaxis(1:StepN),ModSignalPhaseA(1:StepN),'b-','Linewidth',1);
hold on;
%plot(timeaxis(1:StepN),InducedVoltagePhaseA(1:StepN),'r-','Linewidth',1);
%hold on;
%plot(timeaxis(1:StepN),InverterVoltagePhaseA(1:StepN),'k-','Linewidth',1);
%hold on;
plot(timeaxis(1:StepN),CarrierSignal(1,1:StepN),'k-','Linewidth',1);
hold on;
plot(timeaxis(1:StepN),CarrierSignal(2,1:StepN),'r-','Linewidth',1);
hold on;
%plot(timeaxis(1:StepN),CarrierSignal(3,1:StepN),'m-','Linewidth',1);
%hold on;
%plot(timeaxis(1:StepN),CarrierSignal(4,1:StepN),'g-','Linewidth',1);
hold off;
grid on;
set(gca,'FontSize',12);
xlabel('Time (s)','FontSize',12,'FontWeight','Bold')
%ylabel('Motor Phase Induced Voltages (Volts)','FontSize',12,'FontWeight','Bold')
%legend('Phase-A','Phase-B','Phase-C');
%legend('Carrier Signal','Modulating Signal','PWM Output');
ylim([-2 2]);
%xlim([0 0.002])

    
    
%% PLAN:

% From transistor currents, calculate losses

% Find AC and DC spsctrums

% Extend the topology to Series, Parallel, Series/Parallel
% Try different PWM techniques on this model (2-Level)

% Convertert the model to 3-Level inverter topology
% Try different PWM techniques on this model (3-Level)



%%
% figure;
% %plot(timeaxis(1:StepN),DCLinkCurrent(1:StepN),'b-','Linewidth',1);
% plot(timeaxis(1:StepN),DCLinkRipplesim(1:StepN),'b-','Linewidth',1);
% hold on;
% %plot(timeaxis(1:StepN),DCLinkCurrentsim(1:StepN)','r-','Linewidth',1);
% %plot(timeaxis(1:StepN),DCLinkCapacitorCurrent(1:StepN),'k-','Linewidth',1);
% %hold on;
% plot(timeaxis(1:StepN),DCLinkVoltage(1:StepN),'r-','Linewidth',1);
% hold on;
% %plot(timeaxis,InducedVoltagePhaseA,'m-','Linewidth',2);
% %hold on;
% %plot(timeaxis,ModSignalPhaseA*Vdcm*0.612*sqrt(2)/sqrt(3),'g-','Linewidth',2);
% hold off;
% grid on;
% set(gca,'FontSize',12);
% xlabel('Time (s)','FontSize',12,'FontWeight','Bold')
% %ylabel('Motor Phase Induced Voltages (Volts)','FontSize',12,'FontWeight','Bold')
% %legend('Phase-A','Phase-B','Phase-C');
% %legend('Carrier Signal','Modulating Signal','PWM Output');
% %ylim([-2 2]);
% %xlim([0 0.02])
%
%
% %DCLinkCurrentsim
% %DCLinkRipplesim
%
% %%
%
% % Plots
% figure;
% plot(timeaxis,LineCurrentA(1:StepN+1),'k-','Linewidth',1);
% hold on;
% plot(timeaxis,LineCurrentB(1:StepN+1),'r-','Linewidth',1);
% hold on;
% plot(timeaxis,LineCurrentC(1:StepN+1),'b-','Linewidth',1);
% hold on;
% %plot(timeaxis,DCLinkCurrent(1:StepN+1),'b-','Linewidth',1);
% %hold on;
% %plot(timeaxis,DCLinkCapacitorCurrent(1:StepN+1),'k-','Linewidth',1);
% %hold on;
% %plot(timeaxis,DCLinkVoltage(1:StepN+1),'r-','Linewidth',1);
% %hold on;
% %plot(timeaxis,InducedVoltagePhaseA,'m-','Linewidth',2);
% %hold on;
% %plot(timeaxis,ModSignalPhaseA*Vdcm*0.612*sqrt(2)/sqrt(3),'g-','Linewidth',2);
% hold off;
% grid on;
% set(gca,'FontSize',12);
% xlabel('Time (s)','FontSize',12,'FontWeight','Bold')
% %ylabel('Motor Phase Induced Voltages (Volts)','FontSize',12,'FontWeight','Bold')
% %legend('Phase-A','Phase-B','Phase-C');
% %legend('Carrier Signal','Modulating Signal','PWM Output');
% %ylim([-2 2]);
% %xlim([0 0.02])
%
% %%
% figure;
% %plot(timeaxis(1:StepN),DCLinkCurrent(1:StepN),'b-','Linewidth',1);
% hold on;
% %plot(timeaxis(1:StepN),DCLinkCapacitorCurrent(1:StepN),'k-','Linewidth',1);
% hold on;
% plot(timeaxis(1:StepN),DCLinkVoltage(1:StepN),'r-','Linewidth',1);
% hold on;
% %plot(timeaxis,InducedVoltagePhaseA,'m-','Linewidth',2);
% %hold on;
% %plot(timeaxis,ModSignalPhaseA*Vdcm*0.612*sqrt(2)/sqrt(3),'g-','Linewidth',2);
% hold off;
% grid on;
% set(gca,'FontSize',12);
% xlabel('Time (s)','FontSize',12,'FontWeight','Bold')
% %ylabel('Motor Phase Induced Voltages (Volts)','FontSize',12,'FontWeight','Bold')
% %legend('Phase-A','Phase-B','Phase-C');
% %legend('Carrier Signal','Modulating Signal','PWM Output');
% %ylim([-2 2]);
% %xlim([0 0.02])
%
%
% %% BELOW ARE NOT USED
% %Rin = 10;
% %Lin = 1e-3;
% %Vin = Vdc + Rin*(Pout/Vdc);



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

%     LineCurrentA(count+1) = LineCurrentA(count) + ...
%         Ts*((InverterVoltagePhaseA(count)-Vdcm/2-InducedVoltagePhaseA(count))/Ls);
%     LineCurrentB(count+1) = LineCurrentB(count) + ...
%         Ts*((InverterVoltagePhaseB(count)-Vdcm/2-InducedVoltagePhaseB(count))/Ls);
%     LineCurrentC(count+1) = LineCurrentC(count) + ...
%         Ts*((InverterVoltagePhaseC(count)-Vdcm/2-InducedVoltagePhaseC(count))/Ls);
%