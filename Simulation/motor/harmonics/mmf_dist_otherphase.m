%% In this file, MMF distribution of a given stator winding configuration
% are analyzed, harmonic components are investigated, flux linkage and
% induced emf waveforms are obtained. the results will be input for Maxwell
% simulation.

% The machine is fractional slot concentrated winding permanent magnet
% synchronous machine.
pole = 4;
pp = pole/2; % pole pair
slotn = 6;
layer = 1; % alternate teeth
phase = 3;

slot_angle = 2*pi/slotn; % mechanical
slot_angle_d = slot_angle*180/pi; % degrees
pole_angle = 2*pi/pole; % mechanical
pole_angle_d = pole_angle*180/pi;  % degrees

q = slotn/(phase*pole);

conductor = 1; % per coil side
Nph = 0.5*conductor*layer*slotn/phase;

peak_current = 1; % Amps

moodo = 2;

% Define MMF components
mmfa = zeros(1,slotn);
mmfb = zeros(1,slotn);
mmfc = zeros(1,slotn);
mmftotal = zeros(1,slotn);

rotor_speed = 600; % rpm
freq = rotor_speed*pole/120; % Hz
period = 1/freq; % s
time_instant = period*(0:1/3:1)';

for l = 1:numel(time_instant)
    
    % Define the time according the index l
    time = time_instant(l);
    
    % Calculate the phase currents at that time instant
    
    if moodo == 0
    Ia1 = peak_current*cos(2*pi*freq*time);
    Ia2 = peak_current*cos(2*pi*freq*time);
 
    Ib1 = peak_current*cos(2*pi*freq*time-2*pi/3);
    Ib2 = peak_current*cos(2*pi*freq*time-2*pi/3);
    
    Ic1 = peak_current*cos(2*pi*freq*time-4*pi/3);
    Ic2 = peak_current*cos(2*pi*freq*time-4*pi/3);
    
    slot =                  [1  ,2  ,3  ,4  ,5  ,6  ];
    MMFa_layer1 = conductor*[+Ia1,-Ia1,0  ,0  ,0  ,0  ];
    MMFa_layer2 = conductor*[0  ,0  ,0  ,-Ia2,+Ia2,0  ];
    MMFb_layer1 = conductor*[0  ,0  ,0  ,0  ,+Ib1,-Ib1];
    MMFb_layer2 = conductor*[0  ,-Ib2,+Ib2,0  ,0  ,0  ];
    MMFc_layer1 = conductor*[0  ,0  ,+Ic1,-Ic1,0  ,0  ];
    MMFc_layer2 = conductor*[+Ic2,0  ,0  ,0  ,0  ,-Ic2];

    end
    
    if moodo == 1
    Ia1 = peak_current*cos(2*pi*freq*time);
    Ia2 = peak_current*cos(2*pi*freq*time-pi/3);
    Ib1 = peak_current*cos(2*pi*freq*time-2*pi/3);
    Ib2 = peak_current*cos(2*pi*freq*time-2*pi/3-pi/3);
    Ic1 = peak_current*cos(2*pi*freq*time-4*pi/3);
    Ic2 = peak_current*cos(2*pi*freq*time-4*pi/3-pi/3);
    
    slot =                  [1  ,2  ,3  ,4  ,5  ,6  ];
    MMFa_layer1 = conductor*[+Ia1,-Ia1,0  ,0  ,0  ,0  ];
    MMFa_layer2 = conductor*[0  ,-Ia2,+Ia2,0  ,0  ,0  ];
    MMFb_layer1 = conductor*[0  ,0  ,+Ib1,-Ib1,0  ,0  ];
    MMFb_layer2 = conductor*[0  ,0  ,0  ,-Ib2,+Ib2,0  ];
    MMFc_layer1 = conductor*[0  ,0  ,0  ,0  ,+Ic1,-Ic1];
    MMFc_layer2 = conductor*[+Ic2,0  ,0  ,0  ,0  ,-Ic2];

    end
    
    
    if moodo == 2
    Ia = peak_current*cos(2*pi*freq*time);
    Ib = peak_current*cos(2*pi*freq*time-pi/3);
    Ic = peak_current*cos(2*pi*freq*time-2*pi/3);
    Id = peak_current*cos(2*pi*freq*time-2*pi/3-pi/3);
    Ie = peak_current*cos(2*pi*freq*time-4*pi/3);
    If = peak_current*cos(2*pi*freq*time-4*pi/3-pi/3);
    
    slot =                  [1  ,2  ,3  ,4  ,5  ,6  ];
    MMFa_layer1 = conductor*[+Ia,-Ia,0  ,0  ,0  ,0  ];
    MMFa_layer2 = conductor*[0  ,-Ib,+Ib,0  ,0  ,0  ];
    MMFb_layer1 = conductor*[0  ,0  ,+Ic,-Ic,0  ,0  ];
    MMFb_layer2 = conductor*[0  ,0  ,0  ,-Id,+Id,0  ];
    MMFc_layer1 = conductor*[0  ,0  ,0  ,0  ,+Ie,-Ie];
    MMFc_layer2 = conductor*[+If,0  ,0  ,0  ,0  ,-If];

    end
    
    MMFa_total = MMFa_layer1 + MMFa_layer2;
    MMFb_total = MMFb_layer1 + MMFb_layer2;
    MMFc_total = MMFc_layer1 + MMFc_layer2;
%     
%     MMFa_total = MMFa_layer1;
%     MMFb_total = MMFb_layer1;
%     MMFc_total = MMFc_layer1;
    
    for k = 1:slotn
        mmfa(l,k) = sum(MMFa_total(1:k));
        mmfb(l,k) = sum(MMFb_total(1:k));
        mmfc(l,k) = sum(MMFc_total(1:k));
    end
    
    % To get rid of the offset on the MMF waveforms, use the following
    % routine for each phase MMF
    average = sum(mmfa(l,:))/slotn;
    mmfa(l,:) = mmfa(l,:)-average;
    average = sum(mmfb(l,:))/slotn;
    mmfb(l,:) = mmfb(l,:)-average;
    average = sum(mmfc(l,:))/slotn;
    mmfc(l,:) = mmfc(l,:)-average;
    
    mmftotal(l,:) = mmfa(l,:)+mmfb(l,:)+mmfc(l,:);
    
end

nully = mmftotal(1,:)';
multip = 10;
for k = 1:multip
    nully(k*slotn+1:(k+1)*slotn) = nully(1:slotn);
end

window_angle = numel(nully)*slot_angle_d;
angle_array = 1:window_angle;
%mmf_angle = zeros(1,window_angle);

for k = 1:window_angle
    mmf_angle(k) = nully(floor(k/slot_angle_d)+1);
end

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

fun_order = 1/res;

fun_val = spect_mmf(int8(fun_order))/sqrt(2);


figure;
%plot(f1/res,spect_mmf(1:349)*sqrt(2)/conductor,'b-o ','Linewidth',1.5)
bar(f1/res,spect_mmf(1:numel(f1))/sqrt(2));
grid on;
set(gca,'FontSize',14);
xlabel('Harmonic','FontSize',12,'FontWeight','Bold');
ylabel('MMF Spectrum','FontSize',12,'FontWeight','Bold');
%set(gca,'xtick',[0:2:100]);
%ylim([0 1.5]);
xlim([0 20]);



%%

figure;
subplot(4,1,1)
stairs(mmfa(2,:),'b- ','Linewidth',1.5)
grid on;
set(gca,'FontSize',12);
ylabel('Phase A MMF','FontSize',8,'FontWeight','Bold');
set(gca,'xtick',[0:2:30]);
title('t = 0','FontSize',10,'FontWeight','Bold')
%ylim([-conductor*2 conductor*2]);
xlim([1 slotn]);

subplot(4,1,2)
stairs(mmfb(2,:),'b- ','Linewidth',1.5)
grid on;
set(gca,'FontSize',12);
ylabel('Phase B MMF','FontSize',8,'FontWeight','Bold');
set(gca,'xtick',[0:2:30]);
%ylim([-conductor*2 conductor*2]);
xlim([1 slotn]);

subplot(4,1,3)
stairs(mmfc(2,:),'b- ','Linewidth',1.5)
grid on;
set(gca,'FontSize',12);
ylabel('Phase C MMF','FontSize',8,'FontWeight','Bold');
set(gca,'xtick',[0:2:30]);
%ylim([-conductor*2 conductor*2]);
xlim([1 slotn]);

subplot(4,1,4)
stairs(mmftotal(2,:),'b- ','Linewidth',1.5)
grid on;
set(gca,'FontSize',12);
xlabel('Slot Number','FontSize',8,'FontWeight','Bold');
ylabel('Total MMF','FontSize',8,'FontWeight','Bold');
set(gca,'xtick',[0:2:30]);
%ylim([-conductor*2 conductor*2]);
xlim([1 slotn]);

%%
subplot(4,1,1)
stairs(mmftotal(1,:),'b- ','Linewidth',1.5)
grid on;
set(gca,'FontSize',12);
xlabel('Slot Number','FontSize',8,'FontWeight','Bold');
ylabel('t = 0','FontSize',8,'FontWeight','Bold');
set(gca,'xtick',[0:2:30]);
%ylim([-700 700]);
xlim([1 slotn]);

subplot(4,1,2)
stairs(mmftotal(2,:),'r- ','Linewidth',1.5)
grid on;
set(gca,'FontSize',12);
xlabel('Slot Number','FontSize',8,'FontWeight','Bold');
ylabel('t = 0.0033','FontSize',8,'FontWeight','Bold');
set(gca,'xtick',[0:2:30]);
%ylim([-700 700]);
xlim([1 slotn]);

subplot(4,1,3)
stairs(mmftotal(3,:),'k- ','Linewidth',1.5)
grid on;
set(gca,'FontSize',12);
xlabel('Slot Number','FontSize',8,'FontWeight','Bold');
ylabel('t = 0.0066','FontSize',8,'FontWeight','Bold');
set(gca,'xtick',[0:2:30]);
%ylim([-700 700]);
xlim([1 slotn]);

subplot(4,1,4)
stairs(mmftotal(4,:),'g- ','Linewidth',1.5)
grid on;
set(gca,'FontSize',12);
xlabel('Slot Number','FontSize',8,'FontWeight','Bold');
ylabel('t = 0.01','FontSize',8,'FontWeight','Bold');
set(gca,'xtick',[0:2:30]);
%ylim([-700 700]);
xlim([1 slotn]);

%%
figure;
hold all;
stairs(mmftotal(1,:),'b- ','Linewidth',1.5)
stairs(mmftotal(2,:),'r- ','Linewidth',1.5)
stairs(mmftotal(3,:),'k- ','Linewidth',1.5)
%stairs(mmftotal(4,:),'g- ','Linewidth',1.5)
grid on;
set(gca,'FontSize',12);
xlabel('Slot Number','FontSize',8,'FontWeight','Bold');
%ylabel('t = 0','FontSize',8,'FontWeight','Bold');
set(gca,'xtick',[0:2:30]);
%ylim([-700 700]);
xlim([1 slotn]);

%%
figure;
stairs(nully,'b- ','Linewidth',1.5)
grid on;
set(gca,'FontSize',12);
xlabel('Slot Number','FontSize',12,'FontWeight','Bold');
ylabel('Total MMF','FontSize',12,'FontWeight','Bold');
%set(gca,'xtick',[0:2:100]);
%ylim([-conductor*2 conductor*2]);
%xlim([1 slotn]);

%%
figure;
plot(angle_array,mmf_angle,'b- ','Linewidth',1.5)
grid on;
set(gca,'FontSize',12);
xlabel('Slot Number','FontSize',8,'FontWeight','Bold');
ylabel('Phase A MMF','FontSize',8,'FontWeight','Bold');
%set(gca,'xtick',[0:2:100]);
%ylim([-conductor*2 conductor*2]);
%xlim([1 slot]);



