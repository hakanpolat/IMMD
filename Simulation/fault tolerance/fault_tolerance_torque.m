% 3-phase drive (PMSM)
Ep = 100; % V
Ip = 10; % A
fo = 50; % Hz
p = 10; % pole number
Nm = 120*fo/p; % rpm
wm = Nm*2*pi/60; % rad/sec
phase = 0*pi/180; % rad
shift = 30*(pi/180); % rad
scale = sqrt(3);
%scale = 1;

% time-axis
t = 0:1e-6:0.1; % s

% induced voltages
Ea = Ep*sin(2*pi*fo*t); % V
Eb = Ep*sin(2*pi*fo*t-2*pi/3); % V
Ec = Ep*sin(2*pi*fo*t+2*pi/3); % V

% phase currents
Ia = scale*Ip*sin(2*pi*fo*t-phase-shift); % V
Ib = scale*Ip*sin(2*pi*fo*t-2*pi/3-phase+shift); % V
%Ic = Ip*sin(2*pi*fo*t+2*pi/3-phase); % V
Ic = zeros(1,numel(Ia));

Tma = Ea.*Ia/wm;
Tmb = Eb.*Ib/wm;
Tmc = Ec.*Ic/wm;
Tm = Tma + Tmb + Tmc;

theta = 2*pi*fo*t;
Torque = (Ip*Ep/wm)*( 1 - cos(2*theta)/4 + sqrt(3)/4*sin(2*theta));

figure;
hold all;
%plot(t,Ia*0.5,'b--','Linewidth',2)
plot(t,Tma,'b-','Linewidth',2);
plot(t,Tmb,'r-','Linewidth',2);
plot(t,Tmc,'g-','Linewidth',2);
plot(t,Tm,'k-','Linewidth',3);
%plot(t,Torque,'r-','Linewidth',3);
grid on;
set(gca,'FontSize',12);
xlabel('Time (s)','FontSize',12,'FontWeight','Bold')
ylabel('Torque (Nm)','FontSize',12,'FontWeight','Bold')
legend('Phase-A','Phase-B','Phase-C','Total');
xlim([0.06 0.1])
ylim([-5 30])

%Torque = 3/2*Ip*Ep/wm*cos(phase)


figure;
hold all;
%plot(t,Ia*0.5,'b--','Linewidth',2)
plot(t,Ia,'b-','Linewidth',2);
plot(t,Ib,'r-','Linewidth',2);
plot(t,Ic,'g-','Linewidth',2);
grid on;
set(gca,'FontSize',12);
xlabel('Time (s)','FontSize',12,'FontWeight','Bold')
ylabel('Current (A)','FontSize',12,'FontWeight','Bold')
legend('Phase-A','Phase-B','Phase-C');
xlim([0.06 0.1])
ylim([-20 20])


%%
% 3-phase drive (PMSM)
Ep = 100; % V
Ip = 10; % A
fo = 50; % Hz
p = 10; % pole number
Nm = 120*fo/p; % rpm
wm = Nm*2*pi/60; % rad/sec
phase = 0*pi/180; % rad
%shift = 30*(pi/180); % rad
shift = 0*(pi/180); % rad
%scale = sqrt(3);
scale = 1;

% time-axis
t = 0:1e-6:0.1; % s

% induced voltages
Ea = Ep*sin(2*pi*fo*t); % V
Eb = Ep*sin(2*pi*fo*t-2*pi/3); % V
Ec = Ep*sin(2*pi*fo*t+2*pi/3); % V

% phase currents
Ia = scale*Ip*sin(2*pi*fo*t-phase-shift); % V
Ib = scale*Ip*sin(2*pi*fo*t-2*pi/3-phase+shift); % V
%Ic = Ip*sin(2*pi*fo*t+2*pi/3-phase); % V
Ic = zeros(1,numel(Ia));

Tma = Ea.*Ia/wm;
Tmb = Eb.*Ib/wm;
Tmc = Ec.*Ic/wm;
Tm = Tma + Tmb + Tmc;

theta = 2*pi*fo*t;
Torque = (Ip*Ep/wm)*( 1 - cos(2*theta)/4 + sqrt(3)/4*sin(2*theta));

figure;
hold all;
%plot(t,Ia*0.5,'b--','Linewidth',2)
plot(t,Tma,'b-','Linewidth',2);
plot(t,Tmb,'r-','Linewidth',2);
plot(t,Tmc,'g-','Linewidth',2);
plot(t,Tm,'k-','Linewidth',3);
%plot(t,Torque,'r-','Linewidth',3);
grid on;
set(gca,'FontSize',12);
xlabel('Time (s)','FontSize',12,'FontWeight','Bold')
ylabel('Torque (Nm)','FontSize',12,'FontWeight','Bold')
legend('Phase-A','Phase-B','Phase-C','Total');
xlim([0.06 0.1])
ylim([-5 30])

%Torque = 3/2*Ip*Ep/wm*cos(phase)

figure;
hold all;
%plot(t,Ia*0.5,'b--','Linewidth',2)
plot(t,Ia,'b-','Linewidth',2);
plot(t,Ib,'r-','Linewidth',2);
plot(t,Ic,'g-','Linewidth',2);
grid on;
set(gca,'FontSize',12);
xlabel('Time (s)','FontSize',12,'FontWeight','Bold')
ylabel('Current (A)','FontSize',12,'FontWeight','Bold')
legend('Phase-A','Phase-B','Phase-C');
xlim([0.06 0.1])
ylim([-15 15])
