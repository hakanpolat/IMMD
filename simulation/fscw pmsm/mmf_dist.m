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

kp = 1 % bu simdilik dursun, integral falan almak lazim
kd = 1; % concentrated coil



%%
% h) Distribution factor: $k_d = 0.9567$
kd = sin(q*slot_angle/2)/(q*sin(slot_angle/2));

%%
% i) Pitch factor: $k_c = 0.9511$
kc = sin(coil_span/2);

%%
% j) Winding factor: $k_w = 0.91$
kw = kd*kc;

%%
% k) Mechanical speed of the air gap MMF: Nr = 3000 rpm
frequency = 50;
Nr = 120*frequency/pole;


%%
% PART B

%%
% Parts a, b, c, d)

peak_current = 2; % Amps

parts = 4;

% Define MMF components
mmfa = zeros(parts,slot_number);
mmfb = zeros(parts,slot_number);
mmfc = zeros(parts,slot_number);
mmftotal = zeros(parts,slot_number);

% Time array is the time instants at which MMF will be calculated
time_array = [0,6.67e-3,10e-3,13.33e-3];

for l = 1:parts
    
    % Define the time according the index l
    time = time_array(l);
    
    % Calculate the phase currents at that time instant
    Ia = peak_current*cos(2*pi*frequency*time);
    Ib = peak_current*cos(2*pi*50*time-2*pi/3);
    Ic = peak_current*cos(2*pi*50*time-4*pi/3);
    
    MMFa_layer1 = conductor*[Ia,Ia,Ia,Ia,Ia,0,0,0,0,0,0,0,0,0,0,-Ia,-Ia,...
        -Ia,-Ia,-Ia,0,0,0,0,0,0,0,0,0,0];
    MMFa_layer2 = conductor*[Ia,Ia,0,0,0,0,0,0,0,0,0,0,-Ia,-Ia,-Ia,-Ia,...
        -Ia,0,0,0,0,0,0,0,0,0,0,Ia,Ia,Ia];
    
    MMFb_layer1 = conductor*[0,0,0,0,0,0,0,0,0,0,Ib,Ib,Ib,Ib,Ib,0,0,0,0,0,...
        0,0,0,0,0,-Ib,-Ib,-Ib,-Ib,-Ib];
    MMFb_layer2 = conductor*[0,0,0,0,0,0,0,Ib,Ib,Ib,Ib,Ib,0,0,0,0,0,0,0,0,...
        0,0,-Ib,-Ib,-Ib,-Ib,-Ib,0,0,0];
    
    MMFc_layer1 = conductor*[0,0,0,0,0,-Ic,-Ic,-Ic,-Ic,-Ic,0,0,0,0,0,0,0,...
        0,0,0,Ic,Ic,Ic,Ic,Ic,0,0,0,0,0];
    MMFc_layer2 = conductor*[0,0,-Ic,-Ic,-Ic,-Ic,-Ic,0,0,0,0,0,0,0,0,0,0,...
        Ic,Ic,Ic,Ic,Ic,0,0,0,0,0,0,0,0];
    
    for k = 1:slot_number
        mmfa(l,k) = sum(MMFa_layer1(1:k))+sum(MMFa_layer2(1:k));
        mmfb(l,k) = sum(MMFb_layer1(1:k))+sum(MMFb_layer2(1:k));
        mmfc(l,k) = sum(MMFc_layer1(1:k))+sum(MMFc_layer2(1:k));
    end
    
    % To get rid of the offset on the MMF waveforms, use the following
    % routine for each phase MMF
    average = sum(mmfa(l,:))/slot_number;
    mmfa(l,:) = mmfa(l,:)-average;
    average = sum(mmfb(l,:))/slot_number;
    mmfb(l,:) = mmfb(l,:)-average;
    average = sum(mmfc(l,:))/slot_number;
    mmfc(l,:) = mmfc(l,:)-average;
    
    mmftotal(l,:) = mmfa(l,:)+mmfb(l,:)+mmfc(l,:);
    
end


%%
% Part e)

subplot(4,1,1)
stairs(mmfa(1,:),'b- ','Linewidth',1.5)
grid on;
set(gca,'FontSize',12);
ylabel('Phase A MMF','FontSize',8,'FontWeight','Bold');
set(gca,'xtick',[0:2:30]);
title('t = 0','FontSize',10,'FontWeight','Bold')

subplot(4,1,2)
stairs(mmfa(2,:),'b- ','Linewidth',1.5)
grid on;
set(gca,'FontSize',12);
ylabel('Phase A MMF','FontSize',8,'FontWeight','Bold');
set(gca,'xtick',[0:2:30]);
title('t = 6.67 msec','FontSize',10,'FontWeight','Bold')

subplot(4,1,3)
stairs(mmfa(3,:),'b- ','Linewidth',1.5)
grid on;
set(gca,'FontSize',12);
ylabel('Phase A MMF','FontSize',8,'FontWeight','Bold');
set(gca,'xtick',[0:2:30]);
title('t = 10 msec','FontSize',10,'FontWeight','Bold')

subplot(4,1,4)
stairs(mmfa(4,:),'b- ','Linewidth',1.5)
grid on;
set(gca,'FontSize',12);
xlabel('Slot Number','FontSize',8,'FontWeight','Bold');
ylabel('Phase A MMF','FontSize',8,'FontWeight','Bold');
set(gca,'xtick',[0:2:30]);
title('t = 13.33 msec','FontSize',10,'FontWeight','Bold')

