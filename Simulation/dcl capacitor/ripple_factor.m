function Iac_factor = ripple_factor(f)

P = [-6.3285e-13,2.5667e-09,-3.5415e-06,0.002163,0.8017];
Iac_factor = 0;
N = numel(P)-1;
for k = 1:N+1
    Iac_factor = Iac_factor+P(k)*f^(N-k+1);
end

end
