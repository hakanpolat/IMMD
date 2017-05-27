%clc
%tic
% Forward substitution
% Ly = b
% Given L (Gustavson) and b (vector), find y

function x = fwd_bwd_subs(ColumnL,ValueL,TotalL,ColumnLT,ValueLT,TotalLT,b)

%[ColumnL,ValueL,TotalL] = apply_gustavson(myyL);
n = numel(TotalL)-1;
%b = zeros(1,n);
% fpg_eqn = zeros(1,n);
% for k = 1:n
%     if k == 1 || k == 3 || k == 4 || k == 8
%         b(k) = 1;
%         fpg_eqn(k) = 1;
%     end
%     if k == 2 || k == 5 || k == 6 || k == 7 || k == 9 || k == 10
%         fpg_eqn(k) = 1;
%     end
% end
y = zeros(1,n);
ctr = 0;
while(1)
    ctr = ctr+1;
    Ly_mult = 0;
    %if fpg_eqn(ctr) == 1
    ctr;
    indexrange = TotalL(ctr):TotalL(ctr+1)-1;
    for k = 1:ctr-1
        if sum(ColumnL(indexrange)==k)>0
            index = TotalL(ctr)+find(ColumnL(indexrange)==k)-1;
            Ly_mult = Ly_mult + ValueL(index)*y(k);
        end
    end
    index = TotalL(ctr)+find(ColumnL(indexrange)==ctr)-1;
    y(ctr) = (b(ctr) - Ly_mult)/ValueL(index);
    %end
    if ctr == n
        break;
    end
end

% check
% foundy = y';
% acty = inv(myyL)*b';
% diff = sum(abs(foundy-acty))

% Backward substitution
% L'x = y
% Given L' (Gustavson) and y (calculated), find x
% x is theta

%[ColumnL,ValueL,TotalL] = apply_gustavson(myyL);
%[ColumnLT,ValueLT,TotalLT] = matrix_transpose(ColumnL,ValueL,TotalL);
%myyLT = reconstruct_gustavson(ColumnLT,ValueLT,TotalLT)
%
% fpg_eqn2 = zeros(1,n);
% for k = 1:n
%     if k == 1 || k == 3 || k == 4 || k == 8
%         fpg_eqn2(k) = 1;
%     end
%     if k == 2 || k == 5 || k == 6 || k == 7 || k == 9 || k == 10
%         fpg_eqn2(k) = 1;
%     end
% end


x = zeros(1,n);
ctr = n+1;
while(1)
    ctr = ctr-1;
    LTx_mult = 0;
    %if fpg_eqn2(ctr) == 1
    ctr;
    indexrange = TotalLT(ctr):TotalLT(ctr+1)-1;
    for k = ctr+1:n
        k;
        if sum(ColumnLT(indexrange)==k)>0
            index = TotalLT(ctr)+find(ColumnLT(indexrange)==k)-1;
            ValueLT(index);
            LTx_mult = LTx_mult + ValueLT(index)*x(k);
        end
    end
    index = TotalLT(ctr)+find(ColumnLT(indexrange)==ctr)-1;
    ValueLT(index);
    x(ctr) = (y(ctr) - LTx_mult)/ValueLT(index);
    %end
    if ctr == 1
        break;
    end
end

% check
% foundx = x';
% actx = inv(myyLT)*y';
% diff = sum(abs(foundx-actx))

%toc

end

