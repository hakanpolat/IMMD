function [vect_columnT,vect_valueT,vect_totalT] = matrix_transpose(vect_column,vect_value,vect_total)
% Row Number
row = numel(vect_total)-1;
column = max(vect_column); % If a column is zero at most right, this is wrong !
vect_totalT = 1;
vect_valueT = [];
vect_columnT =  [];
for i = 1:column
    temp = find(vect_column == i);
    Totaltemp = vect_totalT(end)+numel(temp);
    vect_totalT = [vect_totalT Totaltemp];
    for j = 1:numel(temp)
        Valuetemp(j) = vect_value(temp(j));
        Ctemp = zeros(1,numel(temp));
        for f = 1:row
            if (temp(j)>=vect_total(f) && temp(j)<vect_total(f+1))
                Ctemp = f;
                vect_columnT = [vect_columnT Ctemp];
            end
        end
    end
    vect_valueT = [vect_valueT Valuetemp];
    Valuetemp = [];
end
end