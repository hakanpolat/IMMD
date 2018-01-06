function [Igan,Vgan,Rdson,Eon,Eoff,Eoss,Rthjc,Cgan] = device_selection(Ireq)
% GS66502B 	650 V 	7.5 A 	200 m? 	5.0 x 6.6 x 0.51 	Bottom-side
% GS66504B 	650 V 	15 A 	100 m? 	5.0 x 6.6 x 0.51 	Bottom-side
% GS66506T 	650 V 	22.5 A 	67 m? 	5.6 x 4.5 x 0.54 	Top-side
% GS66508B 	650 V 	30 A 	50 m? 	7.0 x 8.4 x 0.51 	Bottom-side
% GS66508P 	650 V 	30 A 	50 m? 	10.0 x 8.7 x 0.51 	Bottom-side
% GS66508T 	650 V 	30 A 	50 m? 	6.9 x 4.5 x 0.54 	Top-side
% GS66516T 	650 V 	60 A 	25 m? 	9.0 x 7.6 x 0.54 	Top-side
% GS66516B 	650 V 	60 A 	25 m? 	11.0 x 9.0 x 0.51 	Bottom-side

if Ireq < 7
    Vgan = 650;
    Igan = 7.5; % A
    Rdson = 516e-3; % Ohms, 150 C, 2.25 A
    Eon = 6.9e-6; %NOT FOUND % J, 400 V
    Eoff = 1.9e-6; %NOT FOUND % J, 400 V
    Eoss = 1.9e-6; % J, 400 V
    Rthjc = 2; % C/W
    Cgan = 0.075;
elseif Ireq>=7 && Ireq < 14
    Vgan = 650;
    Igan = 15; % A
    Rdson = 258e-3; % Ohms, 150 C, 4.5 A
    Eon = 18.5e-6; %NOT FOUND % J, 400 V
    Eoff = 3.7e-6; %NOT FOUND % J, 400 V
    Eoss = 3.3e-6; % J, 400 V
    Rthjc = 1; % C/W
    Cgan = 0.15;
elseif Ireq>=14 && Ireq < 21
    Vgan = 650;
    Igan = 22.5; % A
    Rdson = 175e-3; % Ohms, 150 C, 6.7 A
    Eon = 20.7e-6; %NOT FOUND % J, 400 V
    Eoff = 5.4e-6; %NOT FOUND % J, 400 V
    Eoss = 5.3e-6; % J, 400 V
    Rthjc = 0.7; % C/W
    Cgan = 0.225;
elseif Ireq>=21 && Ireq < 28
    Vgan = 650;
    Igan = 30; % A
    Rdson = 129e-3; % Ohms, 150 C, 2.25 A
    Eon = 47.5e-6; % J, 400 V, 15A
    Eoff = 7.5e-6; % J, 400 V, 15A
    Eoss = 7e-6; % J, 400 V
    Rthjc = 0.5; % C/W
    Cgan = 0.30;
elseif Ireq>=28 && Ireq < 56
    Vgan = 650;
    Igan = 60; % A
    Rdson = 65e-3; % Ohms, 150 C, 2.25 A
    Eon = 134.1e-6; % J, 400 V, 20A
    Eoff = 14.7e-6; % J, 400 V, 20A
    Eoss = 14.1e-6; % J, 400 V
    Rthjc = 0.3; % C/W
    Cgan = 0.60;
end
Vgan = 650;

end