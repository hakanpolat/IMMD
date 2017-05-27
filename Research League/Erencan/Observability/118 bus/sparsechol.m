function [ColumnL,ValueL,TotalL,zero_locations] = sparsechol(ColumnG,ValueG,TotalG)

ValueB = ValueG;
ColumnB = ColumnG;
TotalB = TotalG;

%% Initiate L-Matrix as Identity matrix
ValueL = ones(1,numel(TotalG)-1);
ColumnL = ones(1,numel(TotalG)-1);
TotalL = ones(1,numel(TotalG));
for a=1:numel(TotalG)-1
    ColumnL(a) = a;
    TotalL(a)= a;
end
TotalL(numel(TotalG)) = numel(TotalG);

%% Cholesky Factorization
zero_locations = zeros(1,numel(TotalG)-1);

for n=1:numel(TotalG)-1
    
    % If Nth row is empty (also first column)
    if TotalG(n+1)==TotalG(n)
        % zero counter sayýlacak!
        zero_locations(n) = 1;
        
        % Lnew will be Identity
        [ColumnLnew,ValueLnew,TotalLnew]=finding_Ident_Lnew(TotalG);
        
        % Finding new G matrix directly
        [ColumnGnew,ValueGnew,TotalGnew] = finding_newG_in_0row(n,ColumnG,ValueG,TotalG);
        
        % If Nth diagonal is zero
    elseif sum(ismember(ColumnG(TotalG(n):(TotalG(n+1)-1)),n))==0
        Dn = 0;
        % zero counter sayýlacak!
        zero_locations(n) = 1;
        
        % Finding a_n column vector
        [Columna_n,Valuea_n,Totala_n] = finding_a_n(n,ColumnG,ValueG,TotalG);
        
        % Finding (a_n)T row array
        [Columna_nT,Valuea_nT,Totala_nT]=finding_a_nT(n,ColumnG,ValueG,TotalG);
        
        % Finding Lnew
        [ColumnLnew,ValueLnew,TotalLnew]=finding_Lnew(n,Dn,ColumnG,ValueG,TotalG);
        
        % Finding smaller B matrix
        [ColumnB,ValueB,TotalB] = finding_B(n,ColumnG,ValueG,TotalG);
        
        % Finding new G matrix
        Dn = 1;
        [MultC,MultV,MultT] = matrix_multiplication(Columna_n,Valuea_n,Totala_n,Columna_nT,Valuea_nT,Totala_nT,(numel(TotalB)-1));
        MultV = MultV/abs(Dn);
        [BnewC,BnewV,BnewT] = matrix_sub(ColumnB,ValueB,TotalB,MultC,MultV,MultT);
        [ColumnGnew,ValueGnew,TotalGnew] = finding_Gnew(n,BnewC,BnewV,BnewT,TotalG);
        
        
        % If Nth diagonal is non-zero
    else
        % Finding Dn
        Column_for_Dn = ColumnG(TotalG(n):(TotalG(n+1)-1));
        for a=1:numel(Column_for_Dn)
            if Column_for_Dn(a)==n
                Dn = ValueG(TotalG(n)+a-1);
            end
        end
        
        % Finding a_n column vector
        [Columna_n,Valuea_n,Totala_n] = finding_a_n(n,ColumnG,ValueG,TotalG);
        
        % Finding (a_n)T row array
        [Columna_nT,Valuea_nT,Totala_nT]=finding_a_nT(n,ColumnG,ValueG,TotalG);
        
        % Finding Lnew
        [ColumnLnew,ValueLnew,TotalLnew]=finding_Lnew(n,Dn,ColumnG,ValueG,TotalG);
        
        % Finding smaller B matrix
        [ColumnB,ValueB,TotalB] = finding_B(n,ColumnG,ValueG,TotalG);
        
        % Finding new G matrix
        [MultC,MultV,MultT] = matrix_multiplication(Columna_n,Valuea_n,Totala_n,Columna_nT,Valuea_nT,Totala_nT,(numel(TotalB)-1));
        MultV = MultV/abs(Dn);
        [BnewC,BnewV,BnewT] = matrix_sub(ColumnB,ValueB,TotalB,MultC,MultV,MultT);
        %reconstruct_gustavson(BnewC,BnewV,BnewT)
        [ColumnGnew,ValueGnew,TotalGnew] = finding_Gnew(n,BnewC,BnewV,BnewT,TotalG);
        %reconstruct_gustavson(ColumnGnew,ValueGnew,TotalGnew)
    end
    
    %reconstruct_gustavson(ColumnLnew,ValueLnew,TotalLnew)
    [ColumnL,ValueL,TotalL] = matrix_multiplication(ColumnL,ValueL,TotalL,ColumnLnew,ValueLnew,TotalLnew,(numel(TotalL)-1));
    ColumnG = ColumnGnew;
    ValueG = ValueGnew;
    TotalG = TotalGnew;
    
    
end


end