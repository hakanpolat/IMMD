function [ColumnGnew,ValueGnew,TotalGnew] = finding_newG_in_0row(n,ColumnG,ValueG,TotalG)

TotalGnew = TotalG;
TotalGnew(n+1:end) = TotalGnew(n+1:end)+1;

ValueGnew = zeros(1, numel(ValueG)+1);
ValueGnew(1:TotalG(n)-1) = ValueG(1:TotalG(n)-1);
ValueGnew(TotalG(n)) = 1;
ValueGnew(TotalG(n)+1:end) = ValueG(TotalG(n):end);

ColumnGnew = zeros(1, numel(ColumnG)+1);
ColumnGnew(1:TotalG(n)-1) = ColumnG(1:TotalG(n)-1);
ColumnGnew(TotalG(n)) = n;
ColumnGnew(TotalG(n)+1:end) = ColumnG(TotalG(n):end);

end