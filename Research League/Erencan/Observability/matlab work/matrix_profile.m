%function profile = matrix_profile(given_matrix)

num_of_rows = numel(flagT)-1;
profile = num_of_rows;
flag = 0;
for i = 1:num_of_rows
    if sum(flagC==i) == 0
        flag = flag + 1;
        fi = 0;
    end
    ctr = 0;
    mtrx = flag_matrix(:,i)~=0;
    while(1)
        ctr = ctr+1;
        
        if mtrx(ctr) == 1 || ctr == n
            fi = ctr;
            break;
        end
    end
    profile = profile + i - fi;
end
profile = profile - flag;






%end
%
% n = numel(flag_matrix(:,1));
% profile = n;
% flag = 0;
% for i = 1:n
%     ctr = 0;
%     mtrx = flag_matrix(:,i)~=0;
%     while(1)
%         ctr = ctr+1;
%         if sum(mtrx) == 0
%             flag = flag + 1;
%             fi = 0;
%             break;
%         end
%         if mtrx(ctr) == 1 || ctr == n
%             fi = ctr;
%             break;
%         end
%     end
%     profile = profile + i - fi;
% end
% profile = profile - flag;
