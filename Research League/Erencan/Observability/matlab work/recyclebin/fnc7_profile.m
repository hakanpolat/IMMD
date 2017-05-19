tic
% Profile
n = numel(G(:,1));
profile_G = n;
flag = 0;
for i = 1:n
    ctr = 0;
    mtrx = G(:,i)~=0;
    while(1)
        ctr = ctr+1;
        if sum(mtrx) == 0
            flag = flag + 1;
            fi = 0;
            break;
        end
        if mtrx(ctr) == 1 || ctr == n
            fi = ctr;
            break;
        end
    end
    %G(:,1)~=0
    %fi = min(G(:,i))
    profile_G = profile_G + i - fi;
end
profile_G = profile_G - flag;
toc
