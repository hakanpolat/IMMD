function device_param = device_selection(n,ns)
% GS66502B 	650 V 	7.5 A 	200 m? 	5.0 x 6.6 x 0.51 	Bottom-side
% GS66504B 	650 V 	15 A 	100 m? 	5.0 x 6.6 x 0.51 	Bottom-side
% GS66506T 	650 V 	22.5 A 	67 m? 	5.6 x 4.5 x 0.54 	Top-side
% GS66508B 	650 V 	30 A 	50 m? 	7.0 x 8.4 x 0.51 	Bottom-side
% GS66508P 	GS66508P 	650 V 	30 A 	50 m? 	10.0 x 8.7 x 0.51 	Bottom-side
% GS66508T 	GS66508T 	650 V 	30 A 	50 m? 	6.9 x 4.5 x 0.54 	Top-side
% GS66516T 	650 V 	60 A 	25 m? 	9.0 x 7.6 x 0.54 	Top-side
% GS66516B 	650 V 	60 A 	25 m? 	11.0 x 9.0 x 0.51 	Bottom-side

global Vdc
global Pout
global ma
global effmmin
global pfmin

Sreq = 100*Pout/(effmmin*pfmin*n);
Vmll = 0.612*Vdc*ma/(ns);
Ireq = sqrt(2)*1.5*Sreq/(Vmll*sqrt(3));

if Ireq < 7
    Igan = 7.5; % A
    Rdson = 516e-3; % Ohms, 150 C, 2.25 A
    Eon = 1; %NOT FOUND % J, 400 V
    Eoff = 1; %NOT FOUND % J, 400 V
    Eoss = 1.9e-6; % J, 400 V
    Rthjc = 2; % C/W
elseif Ireq>=7 && Ireq < 14
    Igan = 15; % A
    Rdson = 258e-3; % Ohms, 150 C, 4.5 A
    Eon = 1; %NOT FOUND % J, 400 V
    Eoff = 1; %NOT FOUND % J, 400 V
    Eoss = 3.3e-6; % J, 400 V
    Rthjc = 1; % C/W
elseif Ireq>=14 && Ireq < 21
    Igan = 22.5; % A
    Rdson = 175e-3; % Ohms, 150 C, 6.7 A
    Eon = 1; %NOT FOUND % J, 400 V
    Eoff = 1; %NOT FOUND % J, 400 V
    Eoss = 5.3e-6; % J, 400 V
    Rthjc = 0.7; % C/W
elseif Ireq>=21 && Ireq < 28
    Igan = 30; % A
    Rdson = 516e-3; % Ohms, 150 C, 2.25 A
    Eon = 1; %NOT FOUND % J, 400 V
    Eoff = 1; %NOT FOUND % J, 400 V
    Eoss = 1.9e-6; % J, 400 V
    Rthjc = 2; % C/W
elseif Ireq>=28 && Ireq < 56
    Igan = 60; % A
    Rdson = 516e-3; % Ohms, 150 C, 2.25 A
    Eon = 1; %NOT FOUND % J, 400 V
    Eoff = 1; %NOT FOUND % J, 400 V
    Eoss = 1.9e-6; % J, 400 V
    Rthjc = 2; % C/W
end
Vgan = 650;
device_param = [Igan,Vgan];

end