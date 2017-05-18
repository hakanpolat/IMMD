ValueHT = [1 2 3 5 2 1 2 1 2];
CHT = [1 2 2 5 3 5 4 2 4 ];
TotalHT = [1 3 5 7 8 10];

ValueH = [3 2 1 3 5 2 1 3];
CH = [3 4 5 1 2 1 3 5];
TotalH = [1 2 4 5 6 9];


cons_matrix = 0;
ctr = 0;
row_num = numel(TotalH)-1;
index = 1;

while(1)
    ctr = ctr + 1;
    current_row = ctr;
    row_elnum = TotalH(ctr+1)-TotalH(ctr);
    for k = 1:row_elnum
        col_index = CH(index);
        cons_matrix(current_row,col_index) = ValueH(index);
        index = index+1;
    end
    if ctr == row_num
        break;
    end
end
