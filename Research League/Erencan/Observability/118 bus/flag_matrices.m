% This file is used for the verification of profile and ordering functions

flag_matrix = [1,0,0,1,0,1,1,0,0;0,1,0,0,1,0,0,1,0;...
    0,0,1,1,1,0,0,0,0;1,0,1,1,0,1,1,0,1;0,1,1,0,1,0,0,1,0;...
    1,0,0,1,0,1,0,0,0;1,0,0,1,0,0,1,1,0;0,1,0,0,1,0,1,1,0;...
    0,0,0,1,0,0,0,0,1];
[flagC,flagV,flagT] = apply_gustavson(flag_matrix);

%%
% symmetric matrix
n = 5;
G = rand(n,n);
G = 0.5*(G+G');
G = G + n*eye(n);
rank(G);
flag_matrix = G;
[flagC,flagV,flagT] = apply_gustavson(flag_matrix);

%%
G = [1,0,0,0,4;2,0,3,0,0;7,0,0,3,0;3,3,0,0,0;0,0,8,0,1];
G = G'*G;
flag_matrix = G;
[flagC,flagV,flagT] = apply_gustavson(flag_matrix);

