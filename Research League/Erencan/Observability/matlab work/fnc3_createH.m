no_of_pi = numel(pi_vect);
no_of_pf = numel(pf_vect(:,1));
branch_data = [Branch_number_from Branch_number_to];
H = zeros(no_of_pi+no_of_pf,No_of_Buses);
for k = 1:no_of_pi
    H(k,pi_vect(k)) = sum(sum((branch_data(:,1) == pi_vect(k))));
    H(k,branch_data(find(branch_data(:,1)) == pi_vect(k))) = -1
end
for k = no_of_pi+1:no_of_pi+no_of_pf
    H(k,pf_vect(k-no_of_pi,1)) = 1;
    H(k,pf_vect(k-no_of_pi,2)) = -1;
end

