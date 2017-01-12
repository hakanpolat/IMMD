%%
% Three phase modules connected parallel on the DC link
% Interleaving is applied
% DC link voltage  is 400V
% Number of modules is variable. Total power is constant.
% Total power is 12 kW

max_number_module = 8;
Irms = zeros(max_number_module,36);
Idc = zeros(max_number_module,36);
enable = zeros(1,max_number_module);
phase = zeros(1,max_number_module);
for n = 1:max_number_module
    tic
    % step time
    Ts = 1e-5; % sec
    % modulation index
    ma = 1;
    % switching frequency
    fsw = 1e3; % Hz
    % DC link voltage
    Vdc = 400; % Volts
    % Load
    Ptotal = 12e3; % W
    Pout = Ptotal/n; % W
    pf = 0.9;
    Sout = Pout/pf; % VA
    fout = 50; % Hz
    wout = 2*pi*fout; % rad/sec
    Vll_rms = ma*Vdc*0.612; % Volts
    Iline = Sout/(Vll_rms*sqrt(3)); % Amps
    Zload = Vll_rms/(Iline*sqrt(3)); % Ohms
    Rload = Zload*pf; % Ohms
    Xload = sqrt(Zload^2-Rload^2); % Ohms
    Lload = Xload/wout; % Henries
    step = 5; % degrees
    for l = 1:370/step+1
        %phase = zeros(1,n);
        for k = 1:n
            phase(k) = (k-1)*((l-1)*step);
            %if k == n
                %disp(phase);
            %end
        end
        enable(1:n) = 1;
        % Run the simulation
        sim('topology2_module.slx');
        % Get parameters
        Irms(n,l) = Icrms(numel(Icrms));
        Idc(n,l) = Icdc(numel(Icdc));
        %disp(Irms(l));
    end
    toc
end

Irms_perc = 100*Irms./Idc;
%phase_shift = 0:(45/n):19*(45/n);
phase_shift = 0:step:74*step;


%%
figure;
for n = 1:max_number_module
    plot(phase_shift,Irms_perc(n,:),'ko-','Linewidth',1.5);
    hold on;
end
hold off;
grid on;
set(gca,'FontSize',12);
xlabel('Phase shift angle','FontSize',12,'FontWeight','Bold')
ylabel('DC Link Capacitor RMS Current (%)','FontSize',12,'FontWeight','Bold')

%%
figure;
plot(phase_shift,Irms_perc(n,:),'k -','Linewidth',1.5);
hold on;
hold off;
grid on;
set(gca,'FontSize',12);
xlabel('Phase shift angle','FontSize',12,'FontWeight','Bold')
ylabel('DC Link Capacitor RMS Current (%)','FontSize',12,'FontWeight','Bold')
