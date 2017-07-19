%% In this file, MMF distribution of a given stator winding configuration
% are analyzed, harmonic components are investigated, flux linkage and
% induced emf waveforms are obtained. the results will be input for Maxwell
% simulation.

% The machi is fractional slot concentrated winding permanent magnet
% synchronous machine.
pole = 10;
slot = 12;
layer = 1; % all teeth
phase = 3;

slot_angle = 2*pi/slot; % mechanical
slot_angle_d = slot_angle*180/pi; % degrees
pole_angle = 2*pi/pole; % mechanical
pole_angle_d = pole_angle*180/pi;  % degrees

q = slot/(phase*pole);

conductor = 10; % per coil side
Nph = 0.5*conductor*layer*slot/phase;

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
    
    MMFa_layer1 = conductor*[Ia,-Ia,0,0,0,0,-Ia,Ia,0,0,0,0];
    MMFa_layer2 = conductor*[0,-Ia,Ia,0,0,0,0,Ia,-Ia,0,0,0];
    
    MMFb_layer1 = conductor*[0,0,0,0,Ib,-Ib,0,0,0,0,-Ib,Ib];
    MMFb_layer2 = conductor*[-Ib,0,0,0,0,-Ib,Ib,0,0,0,0,Ib];
    
    MMFc_layer1 = conductor*[0,0,-Ic,Ic,0,0,0,0,Ic,-Ic,0,0];
    MMFc_layer2 = conductor*[0,0,0,Ic,-Ic,0,0,0,0,-Ic,Ic,0];
    
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
xlabel('Slot Number','FontSize',8,'FontWeight','Bold');
ylabel('Phase A MMF','FontSize',8,'FontWeight','Bold');
%set(gca,'xtick',[0:2:100]);
ylim([-conductor*2 conductor*2]);
%xlim([1 slot]);

%%
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

%%
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
plot(f1/res,spect_mmf(1:349)*sqrt(2)/conductor,'b-o ','Linewidth',1.5)
grid on;
set(gca,'FontSize',12);
xlabel('Frequency','FontSize',8,'FontWeight','Bold');
ylabel('MMF Spectrum','FontSize',8,'FontWeight','Bold');
%set(gca,'xtick',[0:2:100]);
%ylim([-conductor*2 conductor*2]);
xlim([0 25]);

%%
% correction of phase
for k = 1:num/n
    spect_va2(k,:) = unwrap(spect_va2(k,:));
    spect_va2(k,:) = rem(spect_va2(k,:),2*pi);
    spect_ia2(k,:) = unwrap(spect_ia2(k,:));
    spect_ia2(k,:) = rem(spect_ia2(k,:),2*pi);
    spect_vb2(k,:) = unwrap(spect_vb2(k,:));
    spect_vb2(k,:) = rem(spect_vb2(k,:),2*pi);
    spect_ib2(k,:) = unwrap(spect_ib2(k,:));
    spect_ib2(k,:) = rem(spect_ib2(k,:),2*pi);
    spect_vc2(k,:) = unwrap(spect_vc2(k,:));
    spect_vc2(k,:) = rem(spect_vc2(k,:),2*pi);
    spect_ic2(k,:) = unwrap(spect_ic2(k,:));
    spect_ic2(k,:) = rem(spect_ic2(k,:),2*pi);
end
spect_va2 = (180/pi)*spect_va2;
spect_ia2 = (180/pi)*spect_ia2;
spect_vb2 = (180/pi)*spect_vb2;
spect_ib2 = (180/pi)*spect_ib2;
spect_vc2 = (180/pi)*spect_vc2;
spect_ic2 = (180/pi)*spect_ic2;
for l = 1:num/n
    for k = 1:numel(f1)
        if spect_va2(l,k) > 180
            spect_va2(l,k) = spect_va2(l,k)-360;
        end
        if spect_ia2(l,k) > 180
            spect_ia2(l,k) = spect_ia2(l,k)-360;
        end
        if spect_vb2(l,k) > 180
            spect_vb2(l,k) = spect_vb2(l,k)-360;
        end
        if spect_ib2(l,k) > 180
            spect_ib2(l,k) = spect_ib2(l,k)-360;
        end
        if spect_vc2(l,k) > 180
            spect_vc2(l,k) = spect_vc2(l,k)-360;
        end
        if spect_ic2(l,k) > 180
            spect_ic2(l,k) = spect_ic2(l,k)-360;
        end
    end
end
% in order to find the real amplitude spectrum;
% the fft result must be divided by: fft sample/2
window = 1:num/n;
window_count = numel(window);
max_order = 50;
Va_harmonics_magn = zeros(window_count,max_order);
Va_harmonics_phase = zeros(window_count,max_order);
Ia_harmonics_magn = zeros(window_count,max_order);
Ia_harmonics_phase = zeros(window_count,max_order);
Vb_harmonics_magn = zeros(window_count,max_order);
Vb_harmonics_phase = zeros(window_count,max_order);
Ib_harmonics_magn = zeros(window_count,max_order);
Ib_harmonics_phase = zeros(window_count,max_order);
Vc_harmonics_magn = zeros(window_count,max_order);
Vc_harmonics_phase = zeros(window_count,max_order);
Ic_harmonics_magn = zeros(window_count,max_order);
Ic_harmonics_phase = zeros(window_count,max_order);
for l = 1:window_count
    for k = 1:max_order
        Va_harmonics_magn(l,k) = spect_va(l,find(f1==50*k));
        Va_harmonics_phase(l,k) = spect_va2(l,find(f1==50*k));
        Ia_harmonics_magn(l,k) = spect_ia(l,find(f1==50*k));
        Ia_harmonics_phase(l,k) = spect_ia2(l,find(f1==50*k));
        Vb_harmonics_magn(l,k) = spect_vb(l,find(f1==50*k));
        Vb_harmonics_phase(l,k) = spect_vb2(l,find(f1==50*k));
        Ib_harmonics_magn(l,k) = spect_ib(l,find(f1==50*k));
        Ib_harmonics_phase(l,k) = spect_ib2(l,find(f1==50*k));
        Vc_harmonics_magn(l,k) = spect_vc(l,find(f1==50*k));
        Vc_harmonics_phase(l,k) = spect_vc2(l,find(f1==50*k));
        Ic_harmonics_magn(l,k) = spect_ic(l,find(f1==50*k));
        Ic_harmonics_phase(l,k) = spect_ic2(l,find(f1==50*k));
    end
end