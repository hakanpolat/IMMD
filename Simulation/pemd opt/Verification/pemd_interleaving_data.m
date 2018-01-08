% Interleaving effect with parallel connected modules

%for k = 1:8
k = 4

    % Number of modules
    ns = 3;
    np = k;
    n = ns*np;
    
    Vdc = 540;
    Pout = 8000;
    effmmin = 0.94;
    pfmin = 0.9;
    
    % Modulation index
    ma = 0.9;
    % Switching frequency
    fsw = 10e3; % Hz
    % DC link
    Vdcm = Vdc/ns;
    % Load
    Ptotal = Pout/effmmin; % W
    Poutm = Ptotal/n; % W
    Sout = Poutm/pfmin; % VA
    fout = 50; % Hz
    wout = 2*pi*fout; % rad/sec
    Vll_rms = ma*Vdcm*0.612; % Volts
    Iline = Sout/(Vll_rms*sqrt(3)); % Amps
    Zload = Vll_rms/(Iline*sqrt(3)); % Ohms
    Rload = Zload*pfmin; % Ohms
    Xload = sqrt(Zload^2-Rload^2); % Ohms
    Lload = Xload/wout; % Henries
    % Interleaving angle
    phase = zeros(1,8);
    for l = 1:np
        phase(l) = 360/np*(l-1);
    end
    % Input for DC bus
    Rin = 10;
    Vin = Vdcm + Rin*((Ptotal/ns)/Vdcm);
    Cdc = 150e-6;
    % Simulation parameters
    Ts = 1e-6; % s
    Tmax = 0.05; % s
    Tth = 0.04; % s
    enable = zeros(1,8);
    enable(1:np) = 1;
    
    % Simulation call
    sim('pemd_interleaving_data_sim.slx');
    
    % Simulation outputs
    Irmsm = Irmssima(end)
    Irip = Icrmssim(end)
    Vrip = Vripsimp(end)
    rmsdata = Irmssima(end)/Icrmssim(end)
%     Poutsima1 = Poutsima(end)
%     pfsima1 = pfsima(end)
%     Poutsimb1 = Poutsimb(end)
%     pfsimb1 = pfsimb(end)
%     Poutsimc1 = Poutsimc(end)
%     pfsimc1 = pfsimc(end)
%     Poutsimd1 = Poutsimd(end)
%     pfsimd1 = pfsimd(end)
%     Vdcsim1 = Vdcsim(end)
    %intc = 1
    
%end

