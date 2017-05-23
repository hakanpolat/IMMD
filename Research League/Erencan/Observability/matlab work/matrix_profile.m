function profile = matrix_profile(vect_column,vect_total)
num_of_rows = numel(vect_total)-1;
profile = num_of_rows;
flag = 0;
hey = 0;
for i = 1:num_of_rows
    if sum(vect_column==i) == 0
        flag = flag + 1;
        hey = 1;
        fi = 0;
        add_index = 0;
    else
        add_index = i;
    
    end
    ctr = 0;
    while(hey==0)
        ctr = ctr+1;
        if sum(vect_column(vect_total(i):vect_total(i+1)-1)==ctr)
            fi = ctr;
            break;
        end
    end
    profile = profile + add_index - fi;
    hey = 0;
end
profile = profile;
%profile = profile - flag

end

