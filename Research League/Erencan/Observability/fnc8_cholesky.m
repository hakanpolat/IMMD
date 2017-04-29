clear all
clc

n = 3;
% Generate a dense n x n symmetric, positive definite matrix

A = rand(n,n); % generate a random n x n matrix

% construct a symmetric matrix using either
A = 0.5*(A+A'); 
A = A*A';
% The first is significantly faster: O(n^2) compared to O(n^3)

% since A(i,j) < 1 by construction and a symmetric diagonally dominant matrix
%   is symmetric positive definite, which can be ensured by adding nI
A = A + n*eye(n);


G = A;




rank(G)

B = G;

n = length(G);
L = eye(n,n);
L_temp = eye(n,n);
zerovec = zeros(n,1);
zerocounter = 0;



for i = 1:length(G)
   
    d = B(1,1);
    if (d ==0)   % Then it means there is either rank efficiency or slack bus
        
        zerovec(i,1) = zerocounter;   %Flag the number of dependent rows
        zerocounter=zerocounter+1;    
        B(1,1) = 1;
        d = 1;
        
    end
    
     
    a = B(2:(n+1-i),1);
    
    B_temp=B(2:(n+1-i),2:(n+1-i));
    
    B = (1/d).*(B_temp-a*a');
    

        L_temp(i,i) = sqrt(abs(d));
        L_temp(i+1:n,i) =  a./sqrt(abs(d));
        L = L_temp*L; 
    
end