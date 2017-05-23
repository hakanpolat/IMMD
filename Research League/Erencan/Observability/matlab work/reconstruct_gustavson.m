% Reconstruction from Gustavson's method
function cons_matrix = reconstruct_gustavson(vect_column,vect_value,vect_total)
% vect_column
% vect_value
% vect_total

ctr = 0;
cons_matrix = 0;
row_num = numel(vect_total)-1;
%cons_matrix = zeros(row_num,row_num);
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
    if ctr == row_num && row_elnum == 0
        cons_matrix(current_row,:) = 0;
        cons_matrix(:,current_row) = 0;
    end
    if ctr == row_num
        break;
    end
end

end