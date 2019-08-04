%% For this analysis, the following structures are needed:
%Vdctot_400v_forfft, Vdcm1_400v_forfft, Vdcm2_400v_forfft
%% Adjust FFT parameters
fft_cycle = 10;
fft_fund = 50;
fft_maxfreq = 200000;
fft_THDmaxfreq = 200000;
%% Prepare for Moving FFT
LengthOfFFTWindow = 1/fft_fund*fft_cycle;
NumberofFFTWindows = time_array2(end)/LengthOfFFTWindow;
% The content of the harmonics matrix is as follows:
% |    1    |     2     |    3    |     4     |    5    |     6     |    7    |     8     |
% |100Hz-mag|100Hz-phase|200Hz-mag|200Hz-phase|300Hz-mag|300Hz-phase|600Hz-mag|600Hz-phase|
% The matrix construction
Vdctot_harmonic = zeros(8,uint8(NumberofFFTWindows)-1);
Vdcm1_harmonic = zeros(8,uint8(NumberofFFTWindows)-1);
Vdcm2_harmonic = zeros(8,uint8(NumberofFFTWindows)-1);
%% Moving FFT
for k = 1:NumberofFFTWindows
    fft_start = (k-1)*LengthOfFFTWindow;
    % Apply FFT to the obtained strcuture
    % Vdctotal
    Vtot400V_FFTDATA = power_fftscope(Vdctot_400v_forfft);
    Vtot400V_FFTDATA.startTime = fft_start;
    Vtot400V_FFTDATA.cycles = fft_cycle;
    Vtot400V_FFTDATA.fundamental = fft_fund;
    Vtot400V_FFTDATA.maxFrequency = fft_maxfreq;
    Vtot400V_FFTDATA.THDmaxFrequency = fft_THDmaxfreq;
    Vtot400V_FFTDATA = power_fftscope(Vtot400V_FFTDATA);
    Vm1400V_FFTDATA = power_fftscope(Vdcm1_400v_forfft);
    Vm1400V_FFTDATA.startTime = fft_start;
    Vm1400V_FFTDATA.cycles = fft_cycle;
    Vm1400V_FFTDATA.fundamental = fft_fund;
    Vm1400V_FFTDATA.maxFrequency = fft_maxfreq;
    Vm1400V_FFTDATA.THDmaxFrequency = fft_THDmaxfreq;
    Vm1400V_FFTDATA = power_fftscope(Vm1400V_FFTDATA);
    Vm2400V_FFTDATA = power_fftscope(Vdcm2_400v_forfft);
    Vm2400V_FFTDATA.startTime = fft_start;
    Vm2400V_FFTDATA.cycles = fft_cycle;
    Vm2400V_FFTDATA.fundamental = fft_fund;
    Vm2400V_FFTDATA.maxFrequency = fft_maxfreq;
    Vm2400V_FFTDATA.THDmaxFrequency = fft_THDmaxfreq;
    Vm2400V_FFTDATA = power_fftscope(Vm2400V_FFTDATA);
    for l = 2:numel(Vtot400V_FFTDATA.freq)
        if (Vtot400V_FFTDATA.phase(l)<0)
            Vtot400V_FFTDATA.phase(l) = Vtot400V_FFTDATA.phase(l)+360;
        end
        if (Vm1400V_FFTDATA.phase(l)<0)
            Vm1400V_FFTDATA.phase(l) = Vm1400V_FFTDATA.phase(l)+360;
        end
        if (Vm2400V_FFTDATA.phase(l)<0)
            Vm2400V_FFTDATA.phase(l) = Vm2400V_FFTDATA.phase(l)+360;
        end
    end
    Vdctot_harmonic(1,k) = Vtot400V_FFTDATA.mag(Vtot400V_FFTDATA.freq == 100);
    Vdctot_harmonic(2,k) = Vtot400V_FFTDATA.phase(Vtot400V_FFTDATA.freq == 100);
    Vdctot_harmonic(3,k) = Vtot400V_FFTDATA.mag(Vtot400V_FFTDATA.freq == 200);
    Vdctot_harmonic(4,k) = Vtot400V_FFTDATA.phase(Vtot400V_FFTDATA.freq == 200);
    Vdctot_harmonic(5,k) = Vtot400V_FFTDATA.mag(Vtot400V_FFTDATA.freq == 300);
    Vdctot_harmonic(6,k) = Vtot400V_FFTDATA.phase(Vtot400V_FFTDATA.freq == 300);
    Vdctot_harmonic(7,k) = Vtot400V_FFTDATA.mag(Vtot400V_FFTDATA.freq == 600);
    Vdctot_harmonic(8,k) = Vtot400V_FFTDATA.phase(Vtot400V_FFTDATA.freq == 600);
    Vdcm1_harmonic(1,k) = Vm1400V_FFTDATA.mag(Vm1400V_FFTDATA.freq == 100);
    Vdcm1_harmonic(2,k) = Vm1400V_FFTDATA.phase(Vm1400V_FFTDATA.freq == 100);
    Vdcm1_harmonic(3,k) = Vm1400V_FFTDATA.mag(Vm1400V_FFTDATA.freq == 200);
    Vdcm1_harmonic(4,k) = Vm1400V_FFTDATA.phase(Vm1400V_FFTDATA.freq == 200);
    Vdcm1_harmonic(5,k) = Vm1400V_FFTDATA.mag(Vm1400V_FFTDATA.freq == 300);
    Vdcm1_harmonic(6,k) = Vm1400V_FFTDATA.phase(Vm1400V_FFTDATA.freq == 300);
    Vdcm1_harmonic(7,k) = Vm1400V_FFTDATA.mag(Vm1400V_FFTDATA.freq == 600);
    Vdcm1_harmonic(8,k) = Vm1400V_FFTDATA.phase(Vm1400V_FFTDATA.freq == 600);
    Vdcm2_harmonic(1,k) = Vm2400V_FFTDATA.mag(Vm2400V_FFTDATA.freq == 100);
    Vdcm2_harmonic(2,k) = Vm2400V_FFTDATA.phase(Vm2400V_FFTDATA.freq == 100);
    Vdcm2_harmonic(3,k) = Vm2400V_FFTDATA.mag(Vm2400V_FFTDATA.freq == 200);
    Vdcm2_harmonic(4,k) = Vm2400V_FFTDATA.phase(Vm2400V_FFTDATA.freq == 200);
    Vdcm2_harmonic(5,k) = Vm2400V_FFTDATA.mag(Vm2400V_FFTDATA.freq == 300);
    Vdcm2_harmonic(6,k) = Vm2400V_FFTDATA.phase(Vm2400V_FFTDATA.freq == 300);
    Vdcm2_harmonic(7,k) = Vm2400V_FFTDATA.mag(Vm2400V_FFTDATA.freq == 600);
    Vdcm2_harmonic(8,k) = Vm2400V_FFTDATA.phase(Vm2400V_FFTDATA.freq == 600);
end
%% Plot the result (Vdctotal-mag)
figure;
hold all;
plot(1:uint8(NumberofFFTWindows)-1,Vdctot_harmonic(1,:),'b--','Linewidth',2);
plot(1:uint8(NumberofFFTWindows)-1,Vdctot_harmonic(3,:),'rx-','Linewidth',2);
plot(1:uint8(NumberofFFTWindows)-1,Vdctot_harmonic(5,:),'ko-','Linewidth',2);
plot(1:uint8(NumberofFFTWindows)-1,Vdctot_harmonic(7,:),'g+-','Linewidth',2);
set(gca,'FontSize',14);
xlabel('Window','FontSize',14,'FontWeight','Bold')
ylabel('Mags of Total DC Link Voltage (Volts)','FontSize',14,'FontWeight','Bold')
%xlim([-1 1000]);
ylim([0 2]);
title('Series - 400V - No int');
legend({'100 Hz','200 Hz','300 Hz','600 Hz'},'Location','best');
%% Plot the result (Vdctotal-phase)
figure;
hold all;
plot(1:uint8(NumberofFFTWindows)-1,Vdctot_harmonic(2,:),'b--','Linewidth',2);
plot(1:uint8(NumberofFFTWindows)-1,Vdctot_harmonic(4,:),'rx-','Linewidth',2);
plot(1:uint8(NumberofFFTWindows)-1,Vdctot_harmonic(6,:),'ko-','Linewidth',2);
plot(1:uint8(NumberofFFTWindows)-1,Vdctot_harmonic(8,:),'g+-','Linewidth',2);
set(gca,'FontSize',14);
xlabel('Window','FontSize',14,'FontWeight','Bold')
ylabel('Phases of Total DC Link Voltage (Degrees)','FontSize',14,'FontWeight','Bold')
%xlim([-1 1000]);
ylim([0 360]);
title('Series - 400V - No int');
legend({'100 Hz','200 Hz','300 Hz','600 Hz'},'Location','best');
%% Plot the result (Vdcm1-mag)
figure;
hold all;
plot(1:uint8(NumberofFFTWindows)-1,Vdcm1_harmonic(1,:),'b--','Linewidth',2);
plot(1:uint8(NumberofFFTWindows)-1,Vdcm1_harmonic(3,:),'rx-','Linewidth',2);
plot(1:uint8(NumberofFFTWindows)-1,Vdcm1_harmonic(5,:),'ko-','Linewidth',2);
plot(1:uint8(NumberofFFTWindows)-1,Vdcm1_harmonic(7,:),'g+-','Linewidth',2);
set(gca,'FontSize',14);
xlabel('Window','FontSize',14,'FontWeight','Bold')
ylabel('Mags of Total DC Link Voltage (Volts)','FontSize',14,'FontWeight','Bold')
%xlim([-1 1000]);
%ylim([0 2]);
title('Series - 400V - No int');
legend({'100 Hz','200 Hz','300 Hz','600 Hz'},'Location','best');
%% Plot the result (Vdcm1-phase)
figure;
hold all;
plot(1:uint8(NumberofFFTWindows)-1,Vdcm1_harmonic(2,:),'b--','Linewidth',2);
plot(1:uint8(NumberofFFTWindows)-1,Vdcm1_harmonic(4,:),'rx-','Linewidth',2);
plot(1:uint8(NumberofFFTWindows)-1,Vdcm1_harmonic(6,:),'ko-','Linewidth',2);
plot(1:uint8(NumberofFFTWindows)-1,Vdcm1_harmonic(8,:),'g+-','Linewidth',2);
set(gca,'FontSize',14);
xlabel('Window','FontSize',14,'FontWeight','Bold')
ylabel('Phases of Total DC Link Voltage (Degrees)','FontSize',14,'FontWeight','Bold')
%xlim([-1 1000]);
ylim([0 360]);
title('Series - 400V - No int');
legend({'100 Hz','200 Hz','300 Hz','600 Hz'},'Location','best');
%% Plot the result (Vdcm2-mag)
figure;
hold all;
plot(1:uint8(NumberofFFTWindows)-1,Vdcm2_harmonic(1,:),'b--','Linewidth',2);
plot(1:uint8(NumberofFFTWindows)-1,Vdcm2_harmonic(3,:),'rx-','Linewidth',2);
plot(1:uint8(NumberofFFTWindows)-1,Vdcm2_harmonic(5,:),'ko-','Linewidth',2);
plot(1:uint8(NumberofFFTWindows)-1,Vdcm2_harmonic(7,:),'g+-','Linewidth',2);
set(gca,'FontSize',14);
xlabel('Window','FontSize',14,'FontWeight','Bold')
ylabel('Mags of Total DC Link Voltage (Volts)','FontSize',14,'FontWeight','Bold')
%xlim([-1 1000]);
%ylim([0 2]);
title('Series - 400V - No int');
legend({'100 Hz','200 Hz','300 Hz','600 Hz'},'Location','best');
%% Plot the result (Vdcm2-phase)
figure;
hold all;
plot(1:uint8(NumberofFFTWindows)-1,Vdcm2_harmonic(2,:),'b--','Linewidth',2);
plot(1:uint8(NumberofFFTWindows)-1,Vdcm2_harmonic(4,:),'rx-','Linewidth',2);
plot(1:uint8(NumberofFFTWindows)-1,Vdcm2_harmonic(6,:),'ko-','Linewidth',2);
plot(1:uint8(NumberofFFTWindows)-1,Vdcm2_harmonic(8,:),'g+-','Linewidth',2);
set(gca,'FontSize',14);
xlabel('Window','FontSize',14,'FontWeight','Bold')
ylabel('Phases of Total DC Link Voltage (Degrees)','FontSize',14,'FontWeight','Bold')
%xlim([-1 1000]);
ylim([0 360]);
title('Series - 400V - No int');
legend({'100 Hz','200 Hz','300 Hz','600 Hz'},'Location','best');

%% Plot of 300 Hz - MAgs
figure;
hold all;
plot(1:uint8(NumberofFFTWindows)-1,Vdctot_harmonic(5,:),'b--','Linewidth',2);
plot(1:uint8(NumberofFFTWindows)-1,Vdcm1_harmonic(5,:),'rx-','Linewidth',2);
plot(1:uint8(NumberofFFTWindows)-1,Vdcm2_harmonic(5,:),'ko-','Linewidth',2);
set(gca,'FontSize',14);
xlabel('Window','FontSize',14,'FontWeight','Bold')
ylabel('Mags of 300 Hz (Volts)','FontSize',14,'FontWeight','Bold')
%xlim([-1 1000]);
ylim([0 2]);
title('Series - 400V - No int');
legend({'Total','Top module','Bottom module'},'Location','best');
%% Plot of 300 Hz - Phases
figure;
hold all;
plot(1:uint8(NumberofFFTWindows)-1,Vdctot_harmonic(6,:),'b--','Linewidth',2);
plot(1:uint8(NumberofFFTWindows)-1,Vdcm1_harmonic(6,:),'rx-','Linewidth',2);
plot(1:uint8(NumberofFFTWindows)-1,Vdcm2_harmonic(6,:),'ko-','Linewidth',2);
set(gca,'FontSize',14);
xlabel('Window','FontSize',14,'FontWeight','Bold')
ylabel('Phases of 300 Hz (Degrees)','FontSize',14,'FontWeight','Bold')
%xlim([-1 1000]);
ylim([0 360]);
title('Series - 400V - No int');
legend({'Total','Top module','Bottom module'},'Location','best');
