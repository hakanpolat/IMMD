Lnew = [1,0,0,0,0,0;
    1,1,0,0,0,0;
    1,1,1,0,0,0;
    1,0,0,1,0,0;
    1,0,1,0,1,0;
    0,0,0,0,1,1];

[ColumnL,ValueL,TotalL] = apply_gustavson(Lnew);

n = numel(TotalL)-1;
myarray = [];
for k = 1:n
    if numel(find(ColumnL==k))==1
        myarray(k) = -1;
    else
        index = find(ColumnL==k);
        indexr = index(2);
        ctr = 0;
        while(1)
            ctr = ctr+1;
            if indexr >= TotalL(ctr) && indexr < TotalL(ctr+1)
                myarray(k) = ctr;
                break;
            end
        end
    end
end
    
myarray