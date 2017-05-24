% This function modifies the A matrix by deleting its rows corresponding to
% nonzero indices in the theta vector
% Theta vector is obtained from the fast forward backward substitution
% algorithm

% ColumnA
% ValueA
% TotalA
% actualA = reconstruct_gustavson(ColumnA,ValueA,TotalA)
n = numel(TotalA)-1;
theta = zeros(n,1);
for k = 1:n
    if k == 1 || k == 3 || k == 8 || k == 14 || k == 21 ||...
        k == 24 || k == 25 || k == 28
    theta(k) = 1;
    end
end
ctr = 0;
while(1)
    ctr = ctr+1;
    if theta(ctr) ~= 0
        
    end
    if ctr == n
        break;
    end
end


