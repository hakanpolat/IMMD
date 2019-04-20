%% Load stage-1

Vab = VarName2(1:187638);
Ia = VarName3(1:187638)*10;
Ib = VarName4(1:187638)*10;
Ic = VarName5(1:187638)*10;
time = VarName1(1:187638)*1e3; % ms

%%
figure;
hold all;
plot(time,Vab,'r-','Linewidth',1);
%plot(time,Ia,'b-','Linewidth',1);
%plot(time,Ib,'k-','Linewidth',1);
%plot(time,Ic,'g-','Linewidth',1);
grid on;
set(gca,'FontSize',12);
xlabel('Time (ms)','FontSize',12,'FontWeight','Bold')
ylabel('Voltage (Volts)','FontSize',12,'FontWeight','Bold')
%xlim([-10 20]);

%%
figure;
hold all;
plot(time,Ia,'b-','Linewidth',1);
plot(time,Ib,'k-','Linewidth',1);
plot(time,Ic,'r-','Linewidth',1);
grid on;
set(gca,'FontSize',12);
xlabel('Time (ms)','FontSize',12,'FontWeight','Bold')
ylabel('Current (Amps)','FontSize',12,'FontWeight','Bold')
%xlim([-10 20]);
legend('Phase-A','Phase-B','Phase-C');

%% 10kHz vs 40kHz

Ic = VarName2*10;
time = VarName1*1e3; % ms
Ic2 = VarName3*10;
time2 = VarName3*1e3; % ms

%%
figure;
hold all;
%plot(time,Ia,'b-','Linewidth',1);
plot(time,Ic,'k-','Linewidth',1);
plot(time,Ic2,'r-','Linewidth',1);
grid on;
set(gca,'FontSize',12);
xlabel('Time (ms)','FontSize',12,'FontWeight','Bold')
ylabel('Current (Amps)','FontSize',12,'FontWeight','Bold')
%xlim([-10 20]);
%legend('Phase-A','Phase-B','Phase-C');

