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

%%
figure;
hold all;
%plot(time,Ia,'b-','Linewidth',1);
plot(VarName1*1e3,VarName2*10,'k-','Linewidth',1);
plot(VarName3*1e3,VarName4*10,'r-','Linewidth',1);
grid on;
set(gca,'FontSize',12);
xlabel('Time (ms)','FontSize',12,'FontWeight','Bold')
ylabel('Current (Amps)','FontSize',12,'FontWeight','Bold')
%xlim([-10 20]);
%legend('Phase-A','Phase-B','Phase-C');

%%
figure;
hold all;
%plot(time,Ia,'b-','Linewidth',1);
plot(time1*1e3,Vllab*10,'k-','Linewidth',1);
grid on;
set(gca,'FontSize',12);
xlabel('Time (ms)','FontSize',12,'FontWeight','Bold')
ylabel('Current (Amps)','FontSize',12,'FontWeight','Bold')
%xlim([-10 20]);
%legend('Phase-A','Phase-B','Phase-C');

%%
time1 = VarName1-VarName1(1);
current1 = VarName2*10;
%current2 = VarName3*10;
Ts1 = 0.5e-6;
Tfinal1 = VarName1(end)-VarName1(1);

figure;
hold all;
plot(time1,current1,'b-','Linewidth',1);
%plot(time1,current2,'k-','Linewidth',1);
grid on;
set(gca,'FontSize',12);
xlabel('Time (s)','FontSize',12,'FontWeight','Bold')
ylabel('Current (Amps)','FontSize',12,'FontWeight','Bold')
%xlim([-10 20]);
%legend('Phase-A','Phase-B','Phase-C');

%%
time2 = VarName3-VarName3(1);
current2 = VarName4*10;
%current2 = VarName3*10;
Ts2 = 0.2e-6;
Tfinal2 = VarName3(end)-VarName3(1);

figure;
hold all;
plot(time2,current2,'b-','Linewidth',1);
%plot(time1,current2,'k-','Linewidth',1);
grid on;
set(gca,'FontSize',12);
xlabel('Time (s)','FontSize',12,'FontWeight','Bold')
ylabel('Current (Amps)','FontSize',12,'FontWeight','Bold')
%xlim([-10 20]);
%legend('Phase-A','Phase-B','Phase-C');

%%
current3 = zeros(1,numel(time1));
for k = 1:187638*2/5
    ktime2 = round(k*Ts1/Ts2);
    current3(k) = current2(ktime2);
end

figure;
hold all;
plot(time2,current2,'r-','Linewidth',1);
plot(time1,current3,'b-','Linewidth',1);
plot(time1,VarName5*10,'k-','Linewidth',1);
grid on;
set(gca,'FontSize',12);
xlabel('Time (s)','FontSize',12,'FontWeight','Bold')
ylabel('Current (Amps)','FontSize',12,'FontWeight','Bold')
%xlim([-10 20]);
legend('40 kHz Recorded','Undersampled to 10 kHz','10 kHz Recorded');
    

%%
time1 = VarName1-VarName1(1);
voltage1 = VarName2;
Ts1 = 0.1e-6;
Tfinal1 = VarName1(end)-VarName1(1);

%%
time1 = VarName3-VarName3(1);
voltage1 = VarName4;
Ts1 = 0.2e-6;
Tfinal1 = VarName3(end)-VarName3(1);

    