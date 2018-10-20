% Number of stator slots
Qs = 24;
% Number of pole pairs
pp = 10;
% Number of poles
p = 2*pp;
% Number of phases
m = 4;
% Number of modules
n = 4;
% Electrical periodicity of the machine
t = gcd(pp,Qs)
% Must be an integer
sp = Qs/(m*t*n);
% Coil span
yq = round(Qs/(p))
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

per = gcd(p,Qs)
% At no load, in order for the radial forces to be regularly distributed,
% it suffices that the greatest common divisor of the number of poles 
% and slots is greater than 1, gcd(2p,Q) > 1.

% Cogging torque
% The number of cogging torque periods per slot-pitch
Np = p/(per)

Qs/t;
Qs/(2*t);

num = (1:10);
% 1-layer harmonics
v1 = (2*num-1)*t;

% 2-layer harmonics
v2 = (2*num-1)*t;

% 1-layer
Qs/(2*m*t);
% 2-layer
Qs/(m*t);


%%
% Magnet embrace
%em = 0.78;
em = 0.5:0.01:1;

Y = sqrt(em); % rms
Y1 = 2*sqrt(2)./pi*sin(em*pi/2); % rms
THDy = sqrt(Y.^2-Y1.^2)./Y1;

figure;
plot(em,THDy,'b-','Linewidth',2.5);
grid on;
set(gca,'FontSize',12);
xlabel('Magnet embrace','FontSize',12,'FontWeight','Bold');
ylabel('THD of Flux Density','FontSize',12,'FontWeight','Bold');
ylim([0 0.7]);



