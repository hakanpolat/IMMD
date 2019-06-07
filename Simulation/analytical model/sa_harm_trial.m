%% PWM Signals - A
SA_FFTDATA = power_fftscope(SA);
SA_FFTDATA.startTime = fft_start;
SA_FFTDATA.cycles = fft_cycle; 
SA_FFTDATA.fundamental = fft_fund; 
SA_FFTDATA.maxFrequency = fft_maxfreq;
SA_FFTDATA.THDmaxFrequency = fft_THDmaxfreq;
SA_FFTDATA = power_fftscope(SA_FFTDATA);
num = numel(SA_FFTDATA.mag);
SA_DCcomp = SA_FFTDATA.mag(1);
SA_Fundcomp = SA_FFTDATA.mag(SA_FFTDATA.freq == 50);
fprintf('\nDC component: %g\n',SA_DCcomp);
fprintf('\nFundamental component: %g\n',SA_Fundcomp);
saharm_data = 0;
for k = 1:num
    if (SA_FFTDATA.mag(k) >= SA_DCcomp*0.05 || SA_FFTDATA.mag(k) >= SA_Fundcomp*0.1)
        fprintf('\nFreq: %g, Mag: %g, Phase: %g\n',SA_FFTDATA.freq(k),SA_FFTDATA.mag(k),SA_FFTDATA.phase(k));
%        saharm_data = [saharm_data;SA_FFTDATA.mag(k)];
    end    
end
% figure;
% hold all;
% plot(SA_FFTDATA.freq*1e-3,SA_FFTDATA.mag,'r-','Linewidth',1);
% %plot(idc_FFTDATA.freq*1e-3,idc_calc_harm,'b-','Linewidth',1);
% set(gca,'FontSize',14);
% xlabel('Frequency (kHz)','FontSize',14,'FontWeight','Bold')
% ylabel('Magnitude (Amps)','FontSize',14,'FontWeight','Bold')
% xlim([-1 51]);
% ylim([0 0.55]);
% %legend({'Simulated','Calculated'},'Location','best');

saharm_data = [0.49995,0.38566,0.145068,0.0845651,0.0548651,0.0350747]'
saharm_freq = 0:5;
figure;
plot(saharm_freq,saharm_data,'r-','Linewidth',1);
set(gca,'FontSize',14);
xlabel('Frequency (kHz)','FontSize',14,'FontWeight','Bold')
ylabel('Magnitude (Amps)','FontSize',14,'FontWeight','Bold')
xlim([-1 6]);
ylim([0 0.55]);
%legend({'Simulated','Calculated'},'Location','best');

