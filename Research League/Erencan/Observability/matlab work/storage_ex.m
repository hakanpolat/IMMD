% Reconstruction from Gustavson's method

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

%%

% Reconstruction from Knutt's method

% vect_C
% vect_V
% vect_BeginR
% vect_NextR

cons_matrix = 0;
current_row = 0;
row_num = numel(vect_BeginR);
index = 1;

while(1)
    current_row = current_row + 1;
    first_el = vect_BeginR(current_row)
%     
%     for k = 1:row_elnum
%         col_index = vect_column(index);
%         cons_matrix(current_row,col_index) = vect_value(index);
%         index = index+1;
%     end
    if current_row == row_num
        break;
    end
end



