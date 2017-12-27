function Plossdr = electrical_loss(device_parameters,fsw,ma,pf,Irms)
% device parameters:
% 1. Igan, 2. Vgan, 3. Rdson, 4. Eon, 5. Eoff, 6. Eoss, 7. Rthjc, 8. Cgan
%[Igan,Vgan,Rdson,Eon,Eoff,Eoss,Rthjc,Cgan]
Rdson = device_parameters(3);
Eon = device_parameters(4);
Eoff = device_parameters(5);
Eoss = device_parameters(6);

% Transistor forward conduction
Pcf = Rdson*(Irms*sqrt(2))^2/4;
% Transistor reverse conduction
Pcr = ;
% Transistor switching
Pst = 1;
% Transistor Coss
Pso = 1;
% Total loss (transistor)
Plosst = Pcf+Pcr+Pst+Pso;
% Total loss (module)
Plossm = Plosst*2*m;
% Total loss (drive)
Plossdr = Plossm*n;

end