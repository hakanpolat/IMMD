function [Columna_n,Valuea_n,Totala_n] = finding_a_n(n,ColumnG,ValueG,TotalG)

Totala_n = ones(1,numel(TotalG)-n);
Colmn = ColumnG(TotalG(n):(TotalG(n+1)-1));
for a=1:numel(Colmn)
    if Colmn(a) > n
        Colmn(a) = Colmn(a) - n;
        Totala_n((Colmn(a)+1):end) = Totala_n((Colmn(a)+1):end) + 1;
    end
end
Valuea_n = ValueG(TotalG(n)+1:(TotalG(n+1)-1));
Columna_n = ones(1,numel(Valuea_n));

end