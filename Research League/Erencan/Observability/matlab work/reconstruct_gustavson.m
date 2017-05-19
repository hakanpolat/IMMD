% Reconstruction from Gustavson's method
function cons_matrix = reconstruct_gustavson(vect_column,vect_value,vect_total)
% vect_column
% vect_value
% vect_total

cons_matrix = 0;
ctr = 0;
row_num = numel(vect_total)-1;
index = 1;

while(1)
    ctr = ctr + 1;
    current_row = ctr;
    row_elnum = vect_total(ctr+1)-vect_total(ctr);
    for k = 1:row_elnum
        col_index = vect_column(index);
        cons_matrix(current_row,col_index) = vect_value(index);
        index = index+1;
    end
    if ctr == row_num
        break;
    end
end

end