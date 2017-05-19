tic
Bus_number = Bus_Data(:,1);
Branch_number_from = Branch_Data(:,2);
Branch_number_to = Branch_Data(:,3);

A = zeros(No_of_Branches,No_of_Buses);

for k = 1:No_of_Branches
    A(k,Branch_number_from(k)) = 1;
    %(-1)^((Branch_number_from(k)>Branch_number_to(k)));
    A(k,Branch_number_to(k)) = -1;
    %(-1)^((Branch_number_to(k)>Branch_number_from(k)));
end
toc
