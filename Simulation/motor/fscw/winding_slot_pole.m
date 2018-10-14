% Number of stator slots
Qs = 24;
% Number of pole pairs
pp = 10;
% Number of poles
p = 2*pp;
% Number of phases
m = 3;
% Number of modules
n = 4;
% Electrical periodicity of the machine
t = gcd(pp,Qs);
% Must be an integer
sp = Qs/(m*t*n);
% Coil span
yq = round(Qs/(p));
% When the coil throw equals one slot, yq = 1,
% the coil windings do not overlap and 
% the end-winding length is kept at its minimum.

% Layer number
nl = 2;
% Group
Ngrp = abs(Qs-p);
% number of coils per group
Ncpg = (nl*Qs)/(2*m*Ngrp);

p/Qs; % for kw

per = gcd(p,Qs);
% At no load, in order for the radial forces to be regularly distributed,
% it suffices that the greatest common divisor of the number of poles 
% and slots is greater than 1, gcd(2p,Q) > 1.

% Cogging torque
% The number of cogging torque periods per slot-pitch
Np = p/(per)
