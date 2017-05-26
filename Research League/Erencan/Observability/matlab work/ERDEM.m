%% Clearing Workspace
clearvars;
clc;

%% Input Matrix
ColumnG = [ 3 , 2 , 3 , 4 , 3 , 5 , 4] ;
ValueG= [3, 3, 1, 2 , 2, 3, 3] ;
TotalG= [1, 1 , 2 , 5 , 7 ,8 ] ;

ValueB = ValueG;
ColumnB = ColumnG;
TotalB = TotalG;

%% Initiate L-Vector
ValueL = ones(1,numel(TotalG)-1);
ColumnL = ones(1,numel(TotalG)-1);
TotalL = ones(1,numel(TotalG));
for a=1:numel(TotalG)-1
    ColumnL(a) = a;
    TotalL(a)= a;
end
TotalL(numel(TotalG)) = numel(TotalG);
%reconstruct_gustavson(ColumnL,ValueL,TotalL)

%% Cholesky Factorization
% If Nth row is empty (also first column)
if TotalG(n+1)==TotalG(n)
    % zero counter say?lacak!
    % L=L*Ltemp oldu?u için L ayn? kalacak

    continue;
% If Nth dioganal is zero
elseif sum(ismember(ColumnG(TotalG(n):(TotalG(n+1)-1)),n))==0
    % zero counter say?lacak!
    TotalB = TotalG((n+1):numel(TotalG));
    TotalB = TotalB - (TotalB(1)-1);
    Columnss = ColumnG(TotalG(n):(TotalG(n+1)-1));
    for a=1:numel(Columnss)
        if Columnss(a) > n
            TotalB((Columnss(a)-n+1):numel(TotalB)) = TotalB((Columnss(a)-n+1):numel(TotalB)) - 1;
        end
    end

    
    
    
end













