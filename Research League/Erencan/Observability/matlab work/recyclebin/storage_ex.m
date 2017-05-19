% Reconstruction from Gustavson's method

% vect_column
% vect_value
% vect_total

cons_matrix = 0;
ctr = 0;
row_num = numel(TotalH)-1;
index = 1;

while(1)
    ctr = ctr + 1;
    current_row = ctr;
    row_elnum = TotalH(ctr+1)-TotalH(ctr);
    for k = 1:row_elnum
        col_index = ColumnH(index);
        cons_matrix(current_row,col_index) = ValueH(index);
        index = index+1;
    end
    if ctr == row_num
        break;
    end
end

%%

% Reconstruction from Knutt's method

cons_matrix = 0;
current_row = 0;
row_num = numel(vect_BeginR);
index = 1;

while(1)
    current_row = current_row + 1;
    current_el = vect_BeginR(current_row);
    cons_matrix(current_row,vect_C(current_el)) = vect_V(current_el);
    while(1)
        current_el = vect_NextR(current_el);
        if current_el == -1
            break;
        end
        cons_matrix(current_row,vect_C(current_el)) = vect_V(current_el);
    end
    if current_row == row_num
        break;
    end
end



