function [ColumnLnew,ValueLnew,TotalLnew]=finding_Ident_Lnew(TotalG)

ValueLnew = ones(1,numel(TotalG)-1);
ColumnLnew = ones(1,numel(TotalG)-1);
TotalLnew = ones(1,numel(TotalG));
for a=1:numel(TotalG)-1
    ColumnLnew(a) = a;
    TotalLnew(a)= a;
end
TotalLnew(numel(TotalG)) = numel(TotalG);

end