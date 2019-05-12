% https://www.digikey.com/product-detail/en/epcos-tdk/B32774D4505K000/495-4828-ND/3492301

Is = 8.8; % A
pf = 0.97;
ma = 0.9;
fsw = 40e3; % Hz
Vdcrip = 1; % percent
ns = 2;
np = 2;
m = 3;

Idcrms = Is*sqrt( 2*ma*(sqrt(3)/(4*pi) +...
    pf^2*(sqrt(3)/pi-9*ma/16)) ) % Amps

Cdcreq = (ma*Is/(16*fsw*Vdcrip))*...
    sqrt( (6 - (96*sqrt(3)*ma)/(5*pi) +...
    (9*ma^2/2) )*pf^2 + (8*sqrt(3)*ma)/(5*pi) ) % Farads

Cdcreq_total = Cdcreq*ns
Cdcreq_int = Cdcreq_total/np
Cdcreq_phase = Cdcreq_int/m

Idcpercap = Idcrms/2;
ESR = 21.1e-3; % Ohms
Ta = 35;
Rthcap = 35.72; % C/W
Pcap = Idcpercap^2*ESR % W
Pcap_tot = Pcap*3 % W
Tcap = Ta + Pcap*Rthcap

% Caprating: 5A,5uF

