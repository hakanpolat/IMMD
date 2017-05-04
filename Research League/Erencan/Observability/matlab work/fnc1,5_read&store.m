
% IEEE CDF data
% Data import
fid = fopen('ieee_cdf.dat');
% Bus Data
Line_String_Complete=fgetl(fid);
Line_String_Complete=fgetl(fid);
Bus_Data = [];
No_of_Buses = 0;
while ischar(Line_String_Complete)
    Line_String_Complete = fgetl(fid);
    if(strcmp(Line_String_Complete(1:4),'-999') == 1);
        break;
    end
    index = 15;
    Line_String_Numeric = Line_String_Complete(index:end);
    Line_Numeric = str2num(Line_String_Numeric);
    No_of_Buses = No_of_Buses+1;
    Bus_Data = [Bus_Data;
        [No_of_Buses Line_Numeric] ];
end
% Line Data
Line_String_Complete = fgetl(fid);
Branch_Data = [];
No_of_Branches = 0;
while ischar(Line_String_Complete)
    Line_String_Complete = fgetl(fid);
    if(strcmp(Line_String_Complete(1:4),'-999') == 1);
        break;
    end
    index = 1;
    Line_String_Numeric = Line_String_Complete(index:end);
    Line_Numeric = str2num(Line_String_Numeric);
    No_of_Branches = No_of_Branches+1;
    Branch_Data = [Branch_Data;
        [No_of_Branches Line_Numeric]];
end
fclose(fid);

% Measurement data
fid = fopen('measure.dat');
no_of_volt = str2double(fgetl(fid));
counter = 0;
while(1)
    fgetl(fid);
    counter = counter+1;
    if counter == no_of_volt
        break;
    end
end
no_of_pi = str2double(fgetl(fid));
pi_vect = zeros(no_of_pi,1);
counter = 0;
while(1)
    line_value = fgetl(fid);
    counter = counter+1;
    pi_vect(counter,1) = str2double(line_value(1:4));
    if counter == no_of_pi
        break;
    end
end
no_of_react = str2double(fgetl(fid));
counter = 0;
while(1)
    fgetl(fid);
    counter = counter+1;
    if counter == no_of_react
        break;
    end
end
no_of_pf = str2double(fgetl(fid));
pf_vect = zeros(no_of_pf,2);
counter = 0;
while(1)
    line_value = fgetl(fid);
    counter = counter+1;
    pf_vect(counter,1) = str2double(line_value(1:4));
    pf_vect(counter,2) = str2double(line_value(5:8));
    if counter == no_of_pf
        break;
    end
end
fclose(fid);

%%
% create A
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

%%
% create H
no_of_pi = numel(pi_vect);
no_of_pf = numel(pf_vect(:,1));
branch_data = [Branch_number_from Branch_number_to];
H = zeros(no_of_pi+no_of_pf,No_of_Buses);
for k = 1:no_of_pi
    H(k,pi_vect(k)) = sum(sum((branch_data(:,1) == pi_vect(k))));
    H(k,branch_data(find(branch_data(:,1) == pi_vect(k)),2)) = -1;
    H(k,pi_vect(k)) = H(k,pi_vect(k))+sum(sum((branch_data(:,2) == pi_vect(k))));
    H(k,branch_data(find(branch_data(:,2) == pi_vect(k)),1)) = -1;
end
for k = no_of_pi+1:no_of_pi+no_of_pf
    H(k,pf_vect(k-no_of_pi,1)) = 1;
    H(k,pf_vect(k-no_of_pi,2)) = -1;
end

%%
% storage of A with Gustavson's method

vect_total(1) = 1;
vect_column = 0;
vect_value = 0;
row_ctr = 0;
ctr = 0;

while(1)
    row_ctr = row_ctr+1;
    ctr = ctr+1;
    vect_value(ctr) = 1;
    vect_column(ctr) = first(row_ctr);
    ctr = ctr+1;
    vect_value(ctr) = -1;
    vect_column(ctr) = second(row_ctr);
    if row_ctr == length(first)
        break;
    end
    
end


%%
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

