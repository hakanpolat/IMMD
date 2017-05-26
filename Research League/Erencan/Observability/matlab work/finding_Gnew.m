function [ColumnGnew,ValueGnew,TotalGnew] = finding_Gnew(n,BnewC,BnewV,BnewT,TotalG)

ValueGnew = zeros(1,(n+numel(BnewV)));
ColumnGnew = ValueGnew;
TotalGnew = ones(1,numel(TotalG));
for a=1:n
    ValueGnew(a) = 1;
    ColumnGnew(a) = a;
    TotalGnew(a) = a;
end
for a=(n+1):numel(ValueGnew)
    ValueGnew(a) = BnewV(a-n);
    ColumnGnew(a) = BnewC(a-n)+n;
end
for a=(n+1):numel(TotalGnew)
    TotalGnew(a) = BnewT(a-n)+n;
end

end