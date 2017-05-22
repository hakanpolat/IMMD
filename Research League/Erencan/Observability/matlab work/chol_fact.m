%function L = chol_fact(matrix)

%tic
B = matrix;
n = length(matrix);
L = eye(n,n);
L_temp = eye(n,n);
zerovec = zeros(n,1);
zerocounter = 0;
for i = 1:length(matrix(:,1))
    d = B(1,1)
    if (d == 0)   % Then it means there is either rank efficiency or slack bus
        zerovec(i,1) = zerocounter   %Flag the number of dependent rows
        zerocounter=zerocounter+1
        d = 1;
    end
    a = B(2:(n+1-i),1)
    B = B(2:(n+1-i),2:(n+1-i)) %Taking submatrix
    B = B-(a*a')./d       % New submatrix
    L_temp(i,i) = sqrt(d)
    L_temp(i+1:n,i) =  a./sqrt(d)
    L = L*L_temp
    L_temp = eye(n,n)
end

%toc

%end


%
% B = matrix;
% n = length(matrix);
% L = eye(n,n);
% L_temp = eye(n,n);
% zerovec = zeros(n,1);
% zerocounter = 0;
% for i = 1:length(matrix(:,1))
%     d = B(1,1);
%     if (d == 0)   % Then it means there is either rank efficiency or slack bus
%         zerovec(i,1) = zerocounter;   %Flag the number of dependent rows
%         zerocounter=zerocounter+1;
%         d = 1;
%     end
%     a = B(2:(n+1-i),1);
%     B = B(2:(n+1-i),2:(n+1-i)); %Taking submatrix
%     B = B-(a*a')./d;       % New submatrix
%     L_temp(i,i) = sqrt(d);
%     L_temp(i+1:n,i) =  a./sqrt(d);
%     L = L*L_temp;
%     L_temp = eye(n,n);
% end

