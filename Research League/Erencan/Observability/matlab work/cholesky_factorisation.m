function L = cholesky_factosation(matrix)

tic

n = 4;
% Generate a dense n x n symmetric, positive definite matrix
G = rand(n,n); % generate a random n x n matrix
% construct a symmetric matrix using either
G = 0.5*(G+G');
G = G*G';
% The first is significantly faster: O(n^2) compared to O(n^3)
% since A(i,j) < 1 by construction and a symmetric diagonally dominant matrix
%   is symmetric positive definite, which can be ensured by adding nI
G = G + n*eye(n);
% G = [ 1 , 2, 3, 1, 2, 3; 2, 4, 2, 1, 1, 0 ; 3 ,3 , 4, 3, 2, 1 ; 0, 0, 0, 0,0 ,0 ; 7,8,8,9,20,1; 4,4,5,7,8,9 ]
rank(G)
tic
B = G;
n = length(G);
L = eye(n,n);
L_temp = eye(n,n);
zerovec = zeros(n,1);
zerocounter = 0;
for i = 1:length(G(:,1))
    d = B(1,1);
    if (d == 0)   % Then it means there is either rank efficiency or slack bus
        zerovec(i,1) = zerocounter;   %Flag the number of dependent rows
        zerocounter=zerocounter+1;
        d = 1;
    end
    a = B(2:(n+1-i),1);
    B = B(2:(n+1-i),2:(n+1-i)); %Taking submatrix
    B = B-(a*a')./d;       % New submatrix
    L_temp(i,i) = sqrt(d);
    L_temp(i+1:n,i) =  a./sqrt(d);
    L = L*  L_temp;
    L_temp = eye(n,n);
end

toc

end
