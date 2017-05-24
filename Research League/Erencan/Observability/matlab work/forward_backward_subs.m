[ColumnL,ValueL,TotalL] = apply_gustavson(myyL);
n = numel(TotalL)-1;
b = zeros(1,30);
fpg_eqn = zeros(1,30);
for k = 1:n
    if k == 1 || k == 3 || k == 4 || k == 10 || k == 15
        b(k) = 1;
        fpg_eqn(k) = 1;
    end
    if k == 2 || k == 5 || k == 6 || k == 9 || k == 14
        fpg_eqn(k) = 1;
    end
end
y = zeros(1,n);
ctr = 0;
while(1)
    ctr = ctr+1
    Ly_mult = 0;
    if fpg_eqn(ctr) == 1
        ctr;
        indexrange = TotalL(ctr):TotalL(ctr+1)-1
        for k = 1:ctr-1
            if sum(ColumnL(indexrange)==k)>0
                index = TotalL(ctr)+find(ColumnL(indexrange)==k)-1
                Ly_mult = Ly_mult + ValueL(index)*y(k)
            end
            %Ly_mult = Ly_mult + myL(ctr,k)*y(k)
        end
        index = TotalL(ctr)+find(ColumnL(indexrange)==ctr)-1
        y(ctr) = (b(ctr) - Ly_mult)/ValueL(index)
    end
    if ctr == n
        break;
    end
end



%TotalG(old_order_index):TotalG(old_order_index+1)-1