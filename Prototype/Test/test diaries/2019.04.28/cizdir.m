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
currenta1 = VarName2;
currenta3 = VarName3;
Ts1 = 0.1e-6;
Tfinal1 = VarName1(end)-VarName1(1);

figure;
hold all;
plot(time1,currenta3,'b-','Linewidth',1);
plot(time1,currenta4,'k-','Linewidth',1);
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
Ts1 = 0.1e-6;
Tfinal1 = VarName3(end)-VarName3(1);

   %%
time1 = VarName5-VarName5(1);
voltage1 = VarName6;
Ts1 = 0.1e-6;
Tfinal1 = VarName5(end)-VarName5(1);


%% harmonic content
time1 = VarName1-VarName1(1);
scale1 = 2.001838;
scale3 = 2.011222;
currenta1 = VarName2;
currenta3 = VarName3;
currentc = currenta1*scale1;
currenta = currenta3*scale3;
currentb = -(currenta+currentc);
Ts1 = 0.1e-6;
Tfinal1 = VarName1(end)-VarName1(1);
voltab = VarName4;
voltcb = VarName5;

% figure;
% hold all;
% 
% %plot(time1,currentc,'r-','Linewidth',1);
% plot(time1,voltcb,'m-','Linewidth',1);
% %plot(time1,currentc*10,'b-','Linewidth',1);
% %plot(time1,currentb*10,'k-','Linewidth',1);
% plot(time1,voltab,'g-','Linewidth',1);
% grid on;
% set(gca,'FontSize',12);
% xlabel('Time (s)','FontSize',12,'FontWeight','Bold')
% ylabel('Current (Amps)','FontSize',12,'FontWeight','Bold')
% %xlim([-10 20]);
% legend('Phase-A','Phase-B','Phase-C');

%%
Pac_inst = voltab.*currenta + voltcb.*currentc;

%%
time1 = VarName1-VarName1(1);
scale = 2.011222;
R3 = 101.934e-3;
R4 = 101.735e-3;
dcv1 = VarName2; % mavi
dcv2 = VarName3;
dca3 = VarName4/10/R3;
dca4 = VarName5/10/R4;
dcaa = dca3 + dca4;
Ts1 = 0.1e-6;
Tfinal1 = VarName1(end)-VarName1(1);

figure;
hold all;
plot(time1,dcv2,'r-','Linewidth',1);
plot(time1,dcv1,'b-','Linewidth',1);
%plot(time1,currentc*10,'b-','Linewidth',1);
%plot(time1,currentb*10,'k-','Linewidth',1);
%plot(time1,voltab,'g-','Linewidth',1);
grid on;
set(gca,'FontSize',12);
xlabel('Time (s)','FontSize',12,'FontWeight','Bold')
ylabel('Voltage (Volts)','FontSize',12,'FontWeight','Bold')
%xlim([-10 20]);
%legend('Phase-A','Phase-B','Phase-C');

figure;
hold all;
plot(time1,dca3,'r-','Linewidth',1);
plot(time1,dca4,'b-','Linewidth',1);
%plot(time1,currentb*10,'k-','Linewidth',1);
%plot(time1,voltab,'g-','Linewidth',1);
grid on;
set(gca,'FontSize',12);
xlabel('Time (s)','FontSize',12,'FontWeight','Bold')
ylabel('Voltage (Volts)','FontSize',12,'FontWeight','Bold')
%xlim([-10 20]);
%legend('Phase-A','Phase-B','Phase-C');

%%
scale31 = mean(dcaa)/mean(dca3)
scale32 = mean(dcaa./dca3)
scale41 = mean(dcaa)/mean(dca4)
scale42 = mean(dcaa./dca4)

%%
time1 = VarName1-VarName1(1);
R1 = 101.878e-3;
R2 = 100.055e-3;
R3 = 101.934e-3;
R4 = 101.735e-3;
a1 = VarName2/10/R1;
a2 = VarName3/10/R2;
a3 = VarName4/10/R3;
a4 = VarName5/10/R4;
a12 = a1+a2;
a34 = a3+a4;
Ts1 = 0.1e-6;
Tfinal1 = VarName1(end)-VarName1(1);

scale12g = a12 ./ a1;
scale12 = mean( scale12g( find(time1==0.006002) : find(time1==0.01403) ) )
scale22g = a12 ./ a2;
scale22 = mean( scale22g( find(time1==0.006002) : find(time1==0.01403) ) )
scale32g = a34 ./ a3;
scale32 = mean( scale32g( find(time1==0.006002) : find(time1==0.01403) ) )
scale42g = a34 ./ a4;
scale42 = mean( scale42g( find(time1==0.006002) : find(time1==0.01403) ) )

%%
time1 = VarName1-VarName1(1);
scale12 = 2.01731540901416;
scale22 = 1.98345121201965;
scale32 = 2.01131024311374;
scale42 = 1.98933046964858;
R1 = 101.878e-3;
R2 = 100.055e-3;
R3 = 101.934e-3;
R4 = 101.735e-3;
currenta1 = VarName2/10/R1;
currenta3 = VarName3/10/R3;
currentc = currenta1*scale12;
currenta = currenta3*scale32;
currentb = -(currenta+currentc);
Ts1 = 0.1e-6;
Tfinal1 = VarName1(end)-VarName1(1);
voltab = VarName4;
voltcb = VarName5;


%%
figure;
hold all;
plot(time1,scale12,'r-','Linewidth',1);
%plot(time1,a2,'b-','Linewidth',1);
%plot(time1,currentb*10,'k-','Linewidth',1);
%plot(time1,voltab,'g-','Linewidth',1);
grid on;
set(gca,'FontSize',12);
xlabel('Time (s)','FontSize',12,'FontWeight','Bold')
ylabel('Voltage (Volts)','FontSize',12,'FontWeight','Bold')
%xlim([-10 20]);
%legend('Phase-A','Phase-B','Phase-C');

%%
Pdc1_inst = dcv1.*dcaa;
Pdc2_inst = dcv2.*dcaa;

%%
s1 = VarName5*5.436; % a4
s2 = VarName4*5.497;
s1-s2;
%%
figure;
hold all;
plot(time1,dca-dcaa,'r-','Linewidth',1);
