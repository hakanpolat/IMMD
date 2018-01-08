function [intc,intv] = interleaving_effect(n,ns)
% Interleaving effect with parallel connected modules
np = n/ns
if np == 1
    intc = 1;
    intv = 1;
elseif np == 2
    intc = 0.76;
    intv = 0.48;
elseif np == 3
    intc = 0.36;
    intv = 0.19;
elseif np == 4
    intc = 0.30;
    intv = 0.19;
elseif np == 5
    intc = 0.26;
    intv = 0.17;
elseif np == 6
    intc = 0.23;
    intv = 0.09;
elseif np == 7
    intc = 0.2;
    intv = 0.07;
elseif np == 8
    intc = 0.15;
    intv = 0.05;
end

end