function [Columna_nT,Valuea_nT,Totala_nT] = finding_a_nT(n,ColumnG,ValueG,TotalG)

Columna_nT = ColumnG(TotalG(n)+1:(TotalG(n+1)-1));
for a=1:numel(Columna_nT)
    if Columna_nT(a) > n
        Columna_nT(a) = Columna_nT(a) - n;
    end
end
Totala_nT = [1 1+numel(Columna_nT)];
Valuea_nT = ValueG(TotalG(n)+1:(TotalG(n+1)-1));

end