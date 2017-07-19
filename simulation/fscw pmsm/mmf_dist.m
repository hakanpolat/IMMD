%% In this file, MMF distribution of a given stator winding configuration
% are analyzed, harmonic components are investigated, flux linkage and
% induced emf waveforms are obtained. the results will be input for Maxwell
% simulation.

% The machi is fractional slot concentrated winding permanent magnet
% synchronous machine.
pole = 10;
pp = pole/2; % pole pair
slot = 24;
layer = 2; % all teeth
phase = 3;

slot_angle = 2*pi/slot; % mechanical
slot_angle_d = slot_angle*180/pi; % degrees
pole_angle = 2*pi/pole; % mechanical
pole_angle_d = pole_angle*180/pi;  % degrees

q = slot/(phase*pole);

conductor = 10; % per coil side
Nph = 0.5*conductor*layer*slot/phase;

% Winding factor (OBSOLETE)
% kp = sin(pi*pp/slot);
% t = gcd(slot,pp);
% checkvar = slot/(t*phase);
% alfa = 30*pi/180;
% if mod(checkvar,2) == 0
%     kd = sin(q*alfa/4)/((q/2)*sin(alfa/2));
% else
%     kd = sin(q*alfa/4)/((q)*sin(alfa/4));    
% end

kp = 0.933; % bu simdilik dursun, integral falan almak lazim
kd = 1; % concentrated coil
kw = kp*kd; % winding factor

peak_current = 1; % Amps

% Define MMF components
mmfa = zeros(1,slot);
mmfb = zeros(1,slot);
mmfc = zeros(1,slot);
mmftotal = zeros(1,slot);

rotor_speed = 600; % rpm
freq = rotor_speed*pole/120; % Hz
period = 1/freq;
time_instant = period*[0:1/3:1];

for l = 1:numel(time_instant)
    
    % Define the time according the index l
    time = time_instant(l);
    
    % Calculate the phase currents at that time instant
    Ia = peak_current*cos(2*pi*freq*time);
    Ib = peak_current*cos(2*pi*freq*time-2*pi/3);
    Ic = peak_current*cos(2*pi*freq*time-4*pi/3);
    
    %%%%%% Original 12-10 double layer winding 
%     MMFa_layer1 = conductor*[Ia,-Ia,0,0,0,0,-Ia,Ia,0,0,0,0];
%     MMFa_layer2 = conductor*[0,-Ia,Ia,0,0,0,0,Ia,-Ia,0,0,0];
%     
%     MMFb_layer1 = conductor*[0,0,0,0,Ib,-Ib,0,0,0,0,-Ib,Ib];
%     MMFb_layer2 = conductor*[-Ib,0,0,0,0,-Ib,Ib,0,0,0,0,Ib];
%     
%     MMFc_layer1 = conductor*[0,0,-Ic,Ic,0,0,0,0,Ic,-Ic,0,0];
%     MMFc_layer2 = conductor*[0,0,0,Ic,-Ic,0,0,0,0,-Ic,Ic,0];
%     %%%%%%
    
    %%%%%% 
    MMFa_layer1 = conductor*[Ia,0,0,-Ia,0,Ia,0,0,0,0,Ia,0,...
        -Ia,0,0,Ia,0,-Ia,0,0,0,0,-Ia,0];
    MMFa_layer2 = conductor*[Ia,0,-Ia,0,0,Ia,0,-Ia,0,0,0,0,...
        -Ia,0,Ia,0,0,-Ia,0,Ia,0,0,0,0];
    
    MMFb_layer1 = conductor*[0,0,Ib,0,-Ib,0,0,Ib,0,-Ib,0,0,...
        0,0,-Ib,0,Ib,0,0,-Ib,0,Ib,0,0];
    MMFb_layer2 = conductor*[0,0,0,0,-Ib,0,Ib,0,0,-Ib,0,Ib,...
        0,0,0,0,Ib,0,-Ib,0,0,Ib,0,-Ib];
    
    MMFc_layer1 = conductor*[0,-Ic,0,0,0,0,-Ic,0,Ic,0,0,-Ic,...
        0,Ic,0,0,0,0,Ic,0,-Ic,0,0,Ic];
    MMFc_layer2 = conductor*[0,-Ic,0,Ic,0,0,0,0,Ic,0,-Ic,0,...
        0,Ic,0,-Ic,0,0,0,0,-Ic,0,Ic,0];
    %%%%%%
    
    %%%%%% Distributed winding trial, FAIL
%     MMFa_layer1 = conductor*[Ia,Ia,-Ia,-Ia,0,0,0,0,0,0,0,0];
%     MMFa_layer2 = conductor*[0,0,-Ia,-Ia,Ia,Ia,0,0,0,0,0,0,];
%     
%     MMFb_layer1 = conductor*[0,0,0,0,0,0,0,0,Ib,Ib,-Ib,-Ib];
%     MMFb_layer2 = conductor*[Ib,Ib,0,0,0,0,0,0,0,0,-Ib,-Ib];
%     
%     MMFc_layer1 = conductor*[0,0,0,0,-Ic,-Ic,Ic,Ic,0,0,0,0];
%     MMFc_layer2 = conductor*[0,0,0,0,0,0,Ic,Ic,-Ic,-Ic,0,0];
    %%%%%%
    
    for k = 1:slot
        mmfa(l,k) = sum(MMFa_layer1(1:k))+sum(MMFa_layer2(1:k));
        mmfb(l,k) = sum(MMFb_layer1(1:k))+sum(MMFb_layer2(1:k));
        mmfc(l,k) = sum(MMFc_layer1(1:k))+sum(MMFc_layer2(1:k));
    end
    
    % To get rid of the offset on the MMF waveforms, use the following
    % routine for each phase MMF
    average = sum(mmfa(l,:))/slot;
    mmfa(l,:) = mmfa(l,:)-average;
    average = sum(mmfb(l,:))/slot;
    mmfb(l,:) = mmfb(l,:)-average;
    average = sum(mmfc(l,:))/slot;
    mmfc(l,:) = mmfc(l,:)-average;
    
    mmftotal(l,:) = mmfa(l,:)+mmfb(l,:)+mmfc(l,:);
    
end


%%
% Part e)

subplot(4,1,1)
stairs(mmfa(2,:),'b- ','Linewidth',1.5)
grid on;
set(gca,'FontSize',12);
ylabel('Phase A MMF','FontSize',8,'FontWeight','Bold');
set(gca,'xtick',[0:2:30]);
title('t = 0','FontSize',10,'FontWeight','Bold')
ylim([-conductor*2 conductor*2]);
xlim([1 slot]);

subplot(4,1,2)
stairs(mmfb(2,:),'b- ','Linewidth',1.5)
grid on;
set(gca,'FontSize',12);
ylabel('Phase A MMF','FontSize',8,'FontWeight','Bold');
set(gca,'xtick',[0:2:30]);
ylim([-conductor*2 conductor*2]);
xlim([1 slot]);

subplot(4,1,3)
stairs(mmfc(2,:),'b- ','Linewidth',1.5)
grid on;
set(gca,'FontSize',12);
ylabel('Phase A MMF','FontSize',8,'FontWeight','Bold');
set(gca,'xtick',[0:2:30]);
ylim([-conductor*2 conductor*2]);
xlim([1 slot]);

subplot(4,1,4)
stairs(mmftotal(2,:),'b- ','Linewidth',1.5)
grid on;
set(gca,'FontSize',12);
xlabel('Slot Number','FontSize',8,'FontWeight','Bold');
ylabel('Phase A MMF','FontSize',8,'FontWeight','Bold');
set(gca,'xtick',[0:2:30]);
ylim([-conductor*2 conductor*2]);
xlim([1 slot]);

%%
subplot(4,1,1)
stairs(mmftotal(1,:),'b- ','Linewidth',1.5)
grid on;
set(gca,'FontSize',12);
xlabel('Slot Number','FontSize',8,'FontWeight','Bold');
ylabel('Phase A MMF','FontSize',8,'FontWeight','Bold');
set(gca,'xtick',[0:2:30]);
ylim([-conductor*2 conductor*2]);
xlim([1 slot]);

subplot(4,1,2)
stairs(mmftotal(2,:),'b- ','Linewidth',1.5)
grid on;
set(gca,'FontSize',12);
xlabel('Slot Number','FontSize',8,'FontWeight','Bold');
ylabel('Phase A MMF','FontSize',8,'FontWeight','Bold');
set(gca,'xtick',[0:2:30]);
ylim([-conductor*2 conductor*2]);
xlim([1 slot]);

subplot(4,1,3)
stairs(mmftotal(3,:),'b- ','Linewidth',1.5)
grid on;
set(gca,'FontSize',12);
xlabel('Slot Number','FontSize',8,'FontWeight','Bold');
ylabel('Phase A MMF','FontSize',8,'FontWeight','Bold');
set(gca,'xtick',[0:2:30]);
ylim([-conductor*2 conductor*2]);
xlim([1 slot]);

subplot(4,1,4)
stairs(mmftotal(4,:),'b- ','Linewidth',1.5)
grid on;
set(gca,'FontSize',12);
xlabel('Slot Number','FontSize',8,'FontWeight','Bold');
ylabel('Phase A MMF','FontSize',8,'FontWeight','Bold');
set(gca,'xtick',[0:2:30]);
ylim([-conductor*2 conductor*2]);
xlim([1 slot]);

%%
nully = mmftotal(1,:)';
multip = 10;
for k = 1:multip
    nully(k*slot+1:(k+1)*slot) = nully(1:slot);
end

figure;
stairs(nully,'b- ','Linewidth',1.5)
grid on;
set(gca,'FontSize',12);
xlabel('Slot Number','FontSize',12,'FontWeight','Bold');
ylabel('Total MMF','FontSize',12,'FontWeight','Bold');
%set(gca,'xtick',[0:2:100]);
ylim([-conductor*2 conductor*2]);
xlim([1 slot]);

window_angle = numel(nully)*slot_angle_d;
angle_array = 1:window_angle;
mmf_angle = zeros(1,window_angle);
for k = 1:window_angle
    mmf_angle(k) = nully(floor(k/slot_angle_d)+1);
end

figure;
plot(angle_array,mmf_angle,'b- ','Linewidth',1.5)
grid on;
set(gca,'FontSize',12);
xlabel('Slot Number','FontSize',8,'FontWeight','Bold');
ylabel('Phase A MMF','FontSize',8,'FontWeight','Bold');
%set(gca,'xtick',[0:2:100]);
ylim([-conductor*2 conductor*2]);
%xlim([1 slot]);

% FFT of MMF waveform
fo = 1; % fundemental frequency
L = 360; % cycle length
N = window_angle; % window length
n = 360; % number of samples in a window
% spectral estimation by DFT
% resolution: system frequency/# of cycles in the window
res = fo/(N/L);
% frequency axis
f1 = 0:res:(n-1)*res-1;
% signal spectrum
spect_mmf = abs(fft(mmf_angle(1:((n-1)))))/((n-1)/2);

figure;
%plot(f1/res,spect_mmf(1:349)*sqrt(2)/conductor,'b-o ','Linewidth',1.5)
bar(f1/res,spect_mmf(1:349)*sqrt(2)/(2*conductor))
grid on;
set(gca,'FontSize',12);
xlabel('Harmonic','FontSize',8,'FontWeight','Bold');
ylabel('MMF Spectrum','FontSize',8,'FontWeight','Bold');
%set(gca,'xtick',[0:2:100]);
%ylim([-conductor*2 conductor*2]);
xlim([0 25]);

