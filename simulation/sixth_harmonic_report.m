timeaxis = iload(:,1);
figure;
subplot(3,2,1)
plot(timeaxis,vabc(:,2),'b -','Linewidth',1.5);
hold on;
plot(timeaxis,vabc(:,3),'r -','Linewidth',1.5);
hold on;
plot(timeaxis,vabc(:,4),'k -','Linewidth',1.5);
hold off;
grid on;
set(gca,'FontSize',12);
xlim([0.46 0.5]);
ylabel('Grid voltages, va, vb, vc (V)','FontSize',12,'FontWeight','Bold')

subplot(3,2,2)
plot(timeaxis,iabc(:,2),'b -','Linewidth',1.5);
hold on;
plot(timeaxis,iabc(:,3),'r -','Linewidth',1.5);
hold on;
plot(timeaxis,iabc(:,4),'k -','Linewidth',1.5);
hold off;
grid on;
set(gca,'FontSize',12);
xlim([0.46 0.5]);
ylabel('Grid currents, ia, ib, ic (A)','FontSize',12,'FontWeight','Bold')
    
vflag = Vllrms*sqrt(2)*sin(2*pi*50*timeaxis-pi/6);
subplot(3,2,3)
plot(timeaxis,vdc(:,2),'b -','Linewidth',1.5);
hold on;
plot(timeaxis,vflag,'r -','Linewidth',1.5);
hold off;
grid on;
set(gca,'FontSize',12);
xlim([0.46 0.5]);
ylim([0 580]);
ylabel('Rectifier output voltage, Vdc (V)','FontSize',12,'FontWeight','Bold')

subplot(3,2,4)
plot(timeaxis,idc(:,2),'b -','Linewidth',1.5);
grid on;
set(gca,'FontSize',12);
xlim([0.46 0.5]);
ylim([0 80]);
ylabel('Rectifier output current, idc (V)','FontSize',12,'FontWeight','Bold')
xlabel('Time (sec)','FontSize',12,'FontWeight','Bold')

subplot(3,2,5)
plot(timeaxis,vload(:,2),'b -','Linewidth',1.5);
grid on;
set(gca,'FontSize',12);
xlim([0.46 0.5]);
ylim([0 580]);
ylabel('Load voltage, vload (V)','FontSize',12,'FontWeight','Bold')

subplot(3,2,6)
plot(timeaxis,iload(:,2),'b -','Linewidth',1.5);
grid on;
set(gca,'FontSize',12);
xlim([0.46 0.5]);
ylim([0 56]);
ylabel('Load current, iload (A)','FontSize',12,'FontWeight','Bold')


%%
% Rectifier output voltage
Ts = 1e-5;
Vsrms = 230;
Vspeak = Vsrms*sqrt(2);
Vllrms = Vsrms*sqrt(3);
Vdc = (3/pi)*Vllrms*sqrt(2);
Vdc_6m = Vllrms*sqrt(2)*(3/5-3/7)/(pi);
Vdc_12m = Vllrms*sqrt(2)*(3/11-3/13)/(pi);
Vdc_18m = Vllrms*sqrt(2)*(3/17-3/19)/(pi);
Vdc_24m = Vllrms*sqrt(2)*(3/23-3/25)/(pi);
Vdc_30m = Vllrms*sqrt(2)*(3/29-3/31)/(pi);
Vdc_36m = Vllrms*sqrt(2)*(3/35-3/37)/(pi);
for k = 1:10
    Vdc_6hm(k) = Vspeak*3*sqrt(3)/pi*(2/(36*k^2-1));
    Vdc_6hp(k) = (-1)^(k+1)*pi/2;
    Vdc(k) = Vdc_6hm(k)*cos(Vdc_6hp(k))+1j*Vdc_6hm(k)*sin(Vdc_6hp(k));
end

%%
% DC link current
Rload = 10; % Ohms
Ldc = 1e-3; % H
Cdc = 1e-3; % F
fs = 50; % Hz
ws = 2*pi*fs; % rad/sec
for k = 1:10
    wdc = (k*6)*ws;
    Zc = 1/(1j*wdc*Cdc);
    Zr = Rload;
    Zout = (Zc*Zr)/(Zc+Zr);
    Zf = 1j*wdc*Ldc;
    Vload(k) = Vdc(k)*Zout/(Zout+Zf);
    Idc(k) = Vdc(k)/(Zout+Zf);
end

Vload_6hm = abs(Vload);
Vload_6hp = phase(Vload)*180/pi;
Idc_6hm = abs(Idc);
Idc_6hp = phase(Idc)*180/pi;

Idc_6hm(1)
Vload_6hm(1)


%%
% Filter characteristics
L = 3e-3; % Henries
C = 1e-3; % Farads
R = 24.3; % Ohms (load resistance)
fres = 1/(2*pi*sqrt(L*C)); % Hz
SYS1 =  tf(1,[L*C 0 0]);
SYS2 =  tf(R,[L*C*R L R]);
z = zero(SYS2);
p = pole(SYS2);
WMIN = 2*pi*10;
WMAX = 100e3*2*pi;
bodeoptions('cstprefs');
opts = bodeoptions;
opts.FreqUnits = 'Hz';
bode(SYS2,{WMIN,WMAX},opts);
grid on;



