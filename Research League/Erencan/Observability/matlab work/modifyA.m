% This function modifies the A matrix by deleting its rows corresponding to
% nonzero indices in the theta vector
% Theta vector is obtained from the fast forward backward substitution
% algorithm

% ColumnA
% ValueA
% TotalA
actualA = reconstruct_gustavson(ColumnA,ValueA,TotalA)
[ColA,ValA,TotA] = apply_gustavson(actualA(1:10,1:10))
artA = reconstruct_gustavson(ColA,ValA,TotA)

n = numel(TotA)-1;
theta = zeros(n,1);
for k = 1:n
    if k == 1 || k == 3 || k == 5 || k == 9 
    theta(k) = 1;
    end
end
ColAmod = [];
ValAmod = [];
TotAmod = [];
ctr = 0;
while(1)
    ctr = ctr+1;
    if theta(ctr) ~= 0
        num_el = TotA(ctr+1)-TotA(ctr)
        
    end
    if ctr == n
        break;
    end
end


