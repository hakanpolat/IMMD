% This function implements sparse storage of any given matrix with
% Gustavson's method

function [vect_column,vect_value,vect_total] = apply_gustavson(given_matrix)
size_row = numel(given_matrix(:,1));
size_column = numel(given_matrix(1,:));
ctr1 = 0;
ctr2 = 0;
vect_total = zeros(1,size_row);
vect_total(1) = 1;
vect_column = 0;
vect_value = 0;
for i = 1:size_row
    for j = 1:size_column
        value = given_matrix(i,j);
        if value ~= 0
            ctr2 = ctr2 + 1;
            ctr1 = ctr1 + 1;
            vect_column(ctr1) = j;
            vect_value(ctr1) = value;
        end
    end
    vect_total(i+1) = vect_total(i) + ctr2;
    ctr2 = 0;
end

end
