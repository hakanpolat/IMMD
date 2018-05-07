%%
% Plots
figure;
%plot(timeaxis,LineCurrentA(1,1:StepN+1)*1,'k-','Linewidth',1);
hold all;
%plot(timeaxis,LineCurrentB(1,1:StepN+1),'r-','Linewidth',1);
%plot(timeaxis,LineCurrentC(1,1:StepN+1),'b-','Linewidth',1);
plot(timeaxis,DCLinkVoltage(1,1:StepN+1),'b-','Linewidth',1);
%plot(timeaxis,DCLinkVoltage(2,1:StepN+1),'r-','Linewidth',1);
%plot(timeaxis,InverterVoltagePhaseA(1,1:StepN+1),'b-','Linewidth',1);
%plot(timeaxis,LinecurrentsimA(:,1),'r-','Linewidth',1);
plot(timeaxis,DCLinkCurrent(1:StepN+1),'r-','Linewidth',1);
%plot(timeaxis,DCLinkCapacitorCurrent(1:StepN+1),'k-','Linewidth',1);
%plot(timeaxis,VABsim(1:StepN+1),'b-','Linewidth',1);
%plot(timeaxis,InverterVoltageVAB(1:StepN+1),'r-','Linewidth',1);
%plot(timeaxis,InducedVoltagePhaseA(1,:),'m-','Linewidth',2);
%plot(timeaxis,ModSignalPhaseA(1,:)*Vdcm*0.612*sqrt(2)/sqrt(3),'g-','Linewidth',2);
grid on;
set(gca,'FontSize',12);
xlabel('Time (s)','FontSize',12,'FontWeight','Bold')
%ylabel('Motor Phase Induced Voltages (Volts)','FontSize',12,'FontWeight','Bold')
%legend('Phase-A','Phase-B','Phase-C');
%legend('Carrier Signal','Modulating Signal','PWM Output');
%ylim([-2 2]);
%xlim([0.08 0.1])
