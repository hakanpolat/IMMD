function [ColumnLnew,ValueLnew,TotalLnew] = finding_Lnew(n,Dn,ColumnG,ValueG,TotalG)

TotalLnew = ones(1,numel(TotalG));
if Dn == 0
    ColumnLnew = zeros(1,numel(TotalG)-1+TotalG(n+1)-TotalG(n));
    Dn = 1;
else
    ColumnLnew = zeros(1,numel(TotalG)-1+TotalG(n+1)-TotalG(n)-1);
end
ValueLnew = ones(numel(ColumnLnew));


for a=1:numel(TotalLnew)
    TotalLnew(a) = a;
end
Req_Colmn = ColumnG(TotalG(n):(TotalG(n+1)-1));
Req_Val = ValueG(TotalG(n):(TotalG(n+1)-1));
for a=1:numel(Req_Colmn)
    if Req_Colmn(a) == n
        ValueLnew(n) = sqrt(abs(Dn));
    elseif Req_Colmn(a) ~= n
        TotalLnew((Req_Colmn(a)+1):end) = TotalLnew((Req_Colmn(a)+1):end)+1;
        ColumnLnew(Req_Colmn(a)+a-2) = n;
        ValueLnew(Req_Colmn(a)+a-2) = Req_Val(a)/sqrt(abs(Dn));
    end
end
linear_counter = 1;
for a=1:numel(ColumnLnew)
    if ColumnLnew(a)==0
        ColumnLnew(a) = linear_counter;
        linear_counter = linear_counter + 1;
    end
end

end