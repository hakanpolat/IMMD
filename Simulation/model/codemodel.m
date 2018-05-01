%% MATLAB model for code-based IMMD inverter simulations
% Simulation parameters
Ts = 1e-6; % sec
StepN = 100000; % number of steps
Tfinal = StepN*Ts; % sec

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
    InducedVoltagePhaseB(count) = Ef*sqrt(2)*sin(wout*currenttime+2*pi/3);
    InducedVoltagePhaseC(count) = Ef*sqrt(2)*sin(wout*currenttime+4*pi/3);
    
    ModSignalPhaseA(count) = ma*sin(wout*currenttime+delta);
    ModSignalPhaseB(count) = ma*sin(wout*currenttime+delta+2*pi/3);
    ModSignalPhaseC(count) = ma*sin(wout*currenttime+delta+4*pi/3);
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

for k = 1:StepN+1
    DCLinkCurrent(k) = LineCurrentA(k)*InverterVoltagePhaseA(k)/Vdcm + ...
        LineCurrentB(k)*InverterVoltagePhaseB(k)/Vdcm + ...
        LineCurrentC(k)*InverterVoltagePhaseC(k)/Vdcm;
end
DCLinkAverageCurrent = mean(DCLinkCurrent);
DCLinkCapacitorCurrent = DCLinkCurrent - DCLinkAverageCurrent;

rmsflagIcap = 0;
rmsflagIsa = 0;
rmsflagIsb = 0;
rmsflagIsc = 0;
for k = 1:StepN+1
    rmsflagIcap = rmsflagIcap + DCLinkCapacitorCurrent(k)^2;
    rmsflagIsa = rmsflagIsa + LineCurrentA(k)^2;
    rmsflagIsb = rmsflagIsb + LineCurrentB(k)^2;
    rmsflagIsc = rmsflagIsc + LineCurrentC(k)^2;
end
DCLinkRMSCurrent = sqrt(rmsflagIcap/StepN+1);
PhaseARMSCurrent = sqrt(rmsflagIsa/StepN+1);
PhaseBRMSCurrent = sqrt(rmsflagIsb/StepN+1);
PhaseCRMSCurrent = sqrt(rmsflagIsc/StepN+1);

for k = 1:StepN+1
    DCLinkVoltage(k+1) = DCLinkVoltage(k) + Ts*DCLinkCapacitorCurrent(k)/Cdc;
end

WindowLength = 0.005;

DCLinkVoltagePeaktoPeak = max(DCLinkVoltage(find(timeaxis == Tfinal-WindowLength):find(timeaxis == Tfinal)))...
    - min(DCLinkVoltage(find(timeaxis == Tfinal-WindowLength):find(timeaxis == Tfinal)));
DCLinkVoltagePercentRipple = DCLinkVoltagePeaktoPeak/Vdcm*100;



%% PLAN:
% 1. Calculate RMS values of all AC quantities
% 2. Calculate Fundamental values of all AC quantities with Fourier Series
% 3. Find THD of all AC quantities
% 4. Find instantaneous power, average power, Active, Reactive, apparent
% power
% 5. Find power factor
% 6. From transistor currents, calculate losses
% 7. Find AC and DC spsctrums
% 8. Extend the topology to Series, Parallel, Series/Parallel
% 9. Try different PWM techniques on this model (2-Level)
% 10. Convertert the model to 3-Level inverter topology
% 11. Try different PWM techniques on this model (3-Level)



%%

% Plots
figure;
% plot(timeaxis,LineCurrentA(1:StepN+1),'k-','Linewidth',1);
% hold on;
% plot(timeaxis,LineCurrentB(1:StepN+1),'r-','Linewidth',1);
% hold on;
% plot(timeaxis,LineCurrentC(1:StepN+1),'b-','Linewidth',1);
% hold on;
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
