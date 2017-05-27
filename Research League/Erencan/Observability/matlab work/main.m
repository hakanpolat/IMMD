% This is the main code for EE674 project: Observability Analysis
clear all;
clc;
tic
%tic

% IEEE CDF data
% Data import
fid = fopen('ieee_cdf.dat');

% Bus Data
% Skip the first line
Skip_line = fgetl(fid);
% Read the number of buses
Read_line = fgetl(fid);
No_of_Buses = str2double(Read_line(41:46));
% Search for -999 to reach the branch data
while strcmp(Skip_line(1:4),'-999')==0
    Skip_line = fgetl(fid);
end

% Line Data
% Read the number of branches
Read_data = fgetl(fid);
No_of_Branches = str2double(Read_data(41:46));
% A matrix is stored using gustavson's method from the branch data
% Create V, C and T vectors for A matrix storage
ValueA = ones(1,2*No_of_Branches);
ColumnA = zeros(1,2*No_of_Branches);
TotalA = ones(1,No_of_Branches+1);
counter = 0;
Read_data = fgetl(fid);
while strcmp(Read_data(1:4),'-999') == 0
    From_bus = Read_data(1:4);
    To_bus = Read_data(6:9);
    if strcmp(Read_data(1:4),'-999') == 0
        counter = counter+1;
    end
    ValueA(2*counter) = -1;
    ColumnA(2*counter-1) = str2double(From_bus);
    ColumnA(2*counter )= str2double(To_bus);
    TotalA(counter+1) = TotalA(counter) + 2;
    Read_data = fgetl(fid);
end
fclose(fid);

% Measurement data
% Data import
fid = fopen('measure.dat');

% Skip the first reading
Read_line = fgetl(fid);
No_of_skips = str2double(Read_line);
for i = 1:No_of_skips
    Skip_data = fgetl(fid);
end

% Read the number of power injections
Read_line = fgetl(fid);
No_of_power_injections = str2double(Read_line);

% Read and store the first part of H matrix using Gustavson's method
% Power injection part will be stored first
% Create V, C and T vectors for H matrix storage
ColumnH = [];
ValueH = [];
TotalH = 1;
for i = 1:No_of_power_injections
    Read_data = fgetl(fid);
    Injected_bus = str2double(Read_data(1,1:4));
    temp = find(ColumnA == Injected_bus);
    j = length(temp);
    Totaltemp = j+1;
    Valuetemp = ones(1,j+1)*-1;
    ColumnHtemp = zeros(1,j+1);
    ColumnHtemp(1,j+1)= Injected_bus;
    for counter = 1:j
        if mod(temp(counter),2) == 0
            ColumnHtemp(counter) = ColumnA(temp(counter)-1);
        else
            ColumnHtemp(counter) = ColumnA(temp(counter)+1);
        end
    end
    ColumnHtemp = sort(ColumnHtemp);
    Valuetemp((ColumnHtemp == Injected_bus)) = j;
    ColumnH = [ColumnH ColumnHtemp];
    ValueH = [ValueH Valuetemp];
    TotalH = [TotalH,Totaltemp];
end
% Correcting TotalH
for counter = 2:length(TotalH)
    TotalH(counter)= TotalH(counter)+TotalH(counter-1);
end

% Skip the reactive power injections
Read_data = fgetl(fid);
No_of_skip = str2double(Read_data(1,1:4));
for i = 1:No_of_skip
    Skip_line = fgetl(fid);
end

% Read the number of power flows
Read_line = fgetl(fid);
No_of_power_flows = str2double(Read_line(1,1:4));
% Read and store the second part of H matrix using Gustavson's method
% Power flow part will be stored
Valuetemp = ones(1,2);
Columntemp = zeros(1,2);
Totaltemp = 2;
for i = 1:No_of_power_flows
    Read_line = fgetl(fid);
    From_bus = str2double(Read_line(1,1:5));
    To_bus = str2double(Read_line(1,6:10));
    Valuetemp(1,2)= -1;
    ValueH = [ValueH Valuetemp];
    Columntemp(1,1) = From_bus;
    Columntemp(1,2) = To_bus;
    ColumnH = [ColumnH Columntemp];
    Totaltemp = TotalH(end)+2;
    TotalH = [TotalH Totaltemp];
end

% Take the transpose of Jacobian (H) matrix
% The following function takes the transpose of a given matrix stored with
% with Gustavson using sparse techniques. The output is also retured in
% Gustavson form
%tic
[ColumnHT,ValueHT,TotalHT] = matrix_transpose(ColumnH,ValueH,TotalH);
%toc

% Apply sparse multiplication to the Jacobian matrix and its transpose to
% obtain the gain matrix, G.
% The following function multiplies two matrices both stored with Gustavson
% using sparse techniques. The output is also retured in Gustavson form
%tic
[ColumnG,ValueG,TotalG] = matrix_multiplication...
    (ColumnHT,ValueHT,TotalHT,ColumnH,ValueH,TotalH,No_of_Buses);
%toc

% Correct the number of rows if the last column is full zero and therefore
% not srored, using the information of number of buses

% if numel(TotalG)-1 < No_of_Buses
%     add_zero_row = -No_of_Buses + numel(TotalG)+1;
%     for k = 1:add_zero_row
%         TotalG = [TotalG TotalG(end)];
%     end
% end



%reconstruct_gustavson(ColumnG,ValueG,TotalG)

%tic
% Check the profile of a matrix stored with Gustavson
profile_G = matrix_profile(ColumnG,TotalG);
%toc

%tic
% Ordering is applied
[edges,new_order] = ordering(ColumnG,TotalG);
%toc

%tic
% New matrix G stored with gustavson is obtained using the new order
[ColumnGnew,ValueGnew,TotalGnew] = ordering_new_matrix(edges,new_order,...
    ColumnG,ValueG,TotalG);
%toc








%reconstruct_gustavson(ColumnGnew,ValueGnew,TotalGnew)

%tic
% New profile is checked and verified
profile_Gnew = matrix_profile(ColumnGnew,TotalGnew);
%toc

toc

tic

% Cholesky factorisation
[ColumnL,ValueL,TotalL,zero_locations] = sparsechol(ColumnGnew,ValueGnew,TotalGnew);
%reconstruct_gustavson(ColumnL,ValueL,TotalL);
zero_locations;

% Find upper triangular matrix (LT)
[ColumnLT,ValueLT,TotalLT] = matrix_transpose(ColumnL,ValueL,TotalL);
%reconstruct_gustavson(ColumnLT,ValueLT,TotalLT);

% Find the b vector from the zero locations found in Cholesky Factorisation
ctr = 0;
temp = 0;
b = zeros(1,numel(zero_locations));
while(1)
    ctr = ctr+1;
    if zero_locations(ctr) == 1
        b(ctr) = temp;
        temp = temp+1;
    end
    if ctr == numel(b)
        break;
    end
end

toc

tic

% Apply fast forward backward substitution to obtain theta
theta = fwd_bwd_subs(ColumnL,ValueL,TotalL,ColumnLT,ValueLT,TotalLT,b)';

% Original order of the theta vector. This is applied since we re-ordered G
% matrix.

toc

tic

ctr = 0;
theta_or = zeros(1,numel(theta));
while(1)
    ctr = ctr+1;
    index = new_order(ctr);
    theta_or(index) = theta(ctr);
    if ctr == numel(theta)
        break;
    end
end
theta_or = theta_or';

toc

tic

ctr = 0;
n = numel(TotalA)-1;
while(1)
    ctr = ctr+1;
    index = TotalA(ctr):TotalA(ctr+1)-1;
    columns = ColumnA(index);
    if theta_or(columns(1)) ~= 0 || theta_or(columns(2)) ~= 0
        unobs_branchv(ctr) = theta_or(columns(1))*ValueA(index(1))...
            +theta_or(columns(2))*ValueA(index(2));
    else
        unobs_branchv(ctr) = 0;
    end
    if ctr == n
        break;
    end
    
end

%actA = reconstruct_gustavson(ColumnA,ValueA,TotalA);
%unobs_branchv = actA*theta_or;

n = numel(TotalA)-1;
unobs_branch = [];
ctr = 0;
for k = 1:n
    if abs(unobs_branchv(k)) > 1e-5
        ctr = ctr+1;
        unobs_branch(ctr) = k;
    end
end

ctr = 0;
unobs_bus = [];
while(1)
    ctr = ctr+1;
    mybranch = unobs_branch(ctr);
    Aindex = TotalA(mybranch):TotalA(mybranch+1)-1;
    unobs_bus = [unobs_bus;ColumnA(Aindex)];
    if ctr == numel(unobs_branch)
        break;
    end
end

toc


%%
% IEEE CDF data
% Data import

fid = fopen('ieee_cdf.dat');

% Restriction list for injection measurements due to unobservable branches

restr1 = reshape(unobs_bus,[1,numel(unobs_bus)]);
restr = unique(restr1);  

% Bus Data
% Skip the first line
Skip_line = fgetl(fid);
% Read the number of buses
Read_line = fgetl(fid);
No_of_Buses = str2double(Read_line(41:46));
% Search for -999 to reach the branch data
while strcmp(Skip_line(1:4),'-999')==0
    Skip_line = fgetl(fid);
end

% Line Data
% Read the number of branches
Read_data = fgetl(fid);
No_of_Branches = str2double(Read_data(41:46));
% A matrix is stored using gustavson's method from the branch data
% Create V, C and T vectors for A matrix storage
ValueAnew = ones(1,2*No_of_Branches-2*numel(unobs_branch));
ColumnAnew = zeros(1,2*No_of_Branches-2*numel(unobs_branch));
TotalAnew = ones(1,No_of_Branches+1-numel(unobs_branch));
counter = 1;
counter2 = 0;
Read_data = fgetl(fid);
while strcmp(Read_data(1:4),'-999') == 0
    From_bus = Read_data(1:4);
    To_bus = Read_data(6:9);
    if strcmp(Read_data(1:4),'-999') == 0
        
        counter2 = counter2+1;
    end
    if  ismember(unobs_branch,counter2) ==0
       
    ValueAnew(2*counter) = -1;
    ColumnAnew(2*counter-1) = str2double(From_bus);
    ColumnAnew(2*counter )= str2double(To_bus)
    TotalAnew(counter+1) = TotalAnew(counter) + 2;
    
    counter = counter+1;
    end
    Read_data = fgetl(fid);
end
fclose(fid);


%%
% Measurement data
% Data import
fid = fopen('measure.dat');

% Skip the first reading
Read_line = fgetl(fid);
No_of_skips = str2double(Read_line);
for i = 1:No_of_skips
    Skip_data = fgetl(fid);
end

% Read the number of power injections
Read_line = fgetl(fid);
No_of_power_injections = str2double(Read_line);

% Read and store the first part of H matrix using Gustavson's method
% Power injection part will be stored first
% Create V, C and T vectors for H matrix storage
ColumnHnew = [];
ValueHnew = [];
TotalHnew = 1;
for i = 1:No_of_power_injections
    Read_data = fgetl(fid);
    Injected_bus = str2double(Read_data(1,1:4));
    if ismember(restr,Injected_bus) == 0
    temp = find(ColumnAnew == Injected_bus);
    j = length(temp);
    Totaltemp = j+1;
    Valuetemp = ones(1,j+1)*-1;
    ColumnHtemp = zeros(1,j+1);
    ColumnHtemp(1,j+1)= Injected_bus;
    for counter = 1:j
        if mod(temp(counter),2) == 0
            ColumnHtemp(counter) = ColumnAnew(temp(counter)-1);
        else
            ColumnHtemp(counter) = ColumnAnew(temp(counter)+1);
        end
    end
    ColumnHtemp = sort(ColumnHtemp);
    Valuetemp((ColumnHtemp == Injected_bus)) = j;
    ColumnHnew = [ColumnHnew ColumnHtemp];
    ValueHnew = [ValueHnew Valuetemp];
    TotalHnew = [TotalHnew,Totaltemp];
    end
end
% Correcting TotalH
for counter = 2:length(TotalHnew)
    TotalHnew(counter)= TotalHnew(counter)+TotalHnew(counter-1);
end

% Skip the reactive power injections
Read_data = fgetl(fid);
No_of_skip = str2double(Read_data(1,1:4));
for i = 1:No_of_skip
    Skip_line = fgetl(fid);
end

% Read the number of power flows
Read_line = fgetl(fid);
No_of_power_flows = str2double(Read_line(1,1:4));
% Read and store the second part of H matrix using Gustavson's method
% Power flow part will be stored
Valuetemp = ones(1,2);
Columntemp = zeros(1,2);
Totaltemp = 2;
for i = 1:No_of_power_flows
    Read_line = fgetl(fid);
    From_bus = str2double(Read_line(1,1:5));
    To_bus = str2double(Read_line(1,6:10));
    Valuetemp(1,2)= -1;
    ValueHnew = [ValueHnew Valuetemp];
    Columntemp(1,1) = From_bus;
    Columntemp(1,2) = To_bus;
    ColumnHnew = [ColumnHnew Columntemp];
    Totaltemp = TotalHnew(end)+2;
    TotalHnew = [TotalHnew Totaltemp];
end


%% 
clear ColumnHT
clear ValueHT
clear TotalHT
clear TotalG
clear ColumnG
clear ValueG
clear edges
clear new_order
clear TotalGnew
clear ColumnGnew
clear ValueGnew
clear TotalL
clear ColumnL
clear ValueL
clear TotalLT
clear ColumnLT
clear ValueLT
clear theta


[ColumnHT,ValueHT,TotalHT] = matrix_transpose(ColumnHnew,ValueHnew,TotalHnew);
%toc

% Apply sparse multiplication to the Jacobian matrix and its transpose to
% obtain the gain matrix, G.
% The following function multiplies two matrices both stored with Gustavson
% using sparse techniques. The output is also retured in Gustavson form
%tic
[ColumnG,ValueG,TotalG] = matrix_multiplication...
    (ColumnHT,ValueHT,TotalHT,ColumnHnew,ValueHnew,TotalHnew,No_of_Buses);
%toc

% Correct the number of rows if the last column is full zero and therefore
% not srored, using the information of number of buses

% if numel(TotalG)-1 < No_of_Buses
%     add_zero_row = -No_of_Buses + numel(TotalG)+1;
%     for k = 1:add_zero_row
%         TotalG = [TotalG TotalG(end)];
%     end
% end



%reconstruct_gustavson(ColumnG,ValueG,TotalG)

%tic
% Check the profile of a matrix stored with Gustavson
profile_G = matrix_profile(ColumnG,TotalG);
%toc

%tic
% Ordering is applied
[edges,new_order] = ordering(ColumnG,TotalG);
%toc

%tic
% New matrix G stored with gustavson is obtained using the new order
[ColumnGnew,ValueGnew,TotalGnew] = ordering_new_matrix(edges,new_order,...
    ColumnG,ValueG,TotalG);
%toc

%reconstruct_gustavson(ColumnGnew,ValueGnew,TotalGnew)

%tic
% New profile is checked and verified
profile_Gnew = matrix_profile(ColumnGnew,TotalGnew);
%toc

toc

tic

% Cholesky factorisation
[ColumnL,ValueL,TotalL,zero_locations] = sparsechol(ColumnGnew,ValueGnew,TotalGnew);
%reconstruct_gustavson(ColumnL,ValueL,TotalL);
zero_locations;

% Find upper triangular matrix (LT)
[ColumnLT,ValueLT,TotalLT] = matrix_transpose(ColumnL,ValueL,TotalL);
%reconstruct_gustavson(ColumnLT,ValueLT,TotalLT);

% Find the b vector from the zero locations found in Cholesky Factorisation
ctr = 0;
temp = 0;
b = zeros(1,numel(zero_locations));
while(1)
    ctr = ctr+1;
    if zero_locations(ctr) == 1
        b(ctr) = temp;
        temp = temp+1;
    end
    if ctr == numel(b)
        break;
    end
end

toc

tic
% Apply fast forward backward substitution to obtain theta
theta = fwd_bwd_subs(ColumnL,ValueL,TotalL,ColumnLT,ValueLT,TotalLT,b)';

% Original order of the theta vector. This is applied since we re-ordered G
% matrix.

toc

tic

ctr = 0;
theta_or = zeros(1,numel(theta));
while(1)
    ctr = ctr+1;
    index = new_order(ctr);
    theta_or(index) = theta(ctr);
    if ctr == numel(theta)
        break;
    end
end
theta_or = theta_or';

toc

tic

ctr = 0;
n = numel(TotalAnew)-1;
unobs_branchv = [];
while(1)
    ctr = ctr+1;
    index = TotalAnew(ctr):TotalAnew(ctr+1)-1;
    columns = ColumnAnew(index);
    if theta_or(columns(1)) ~= 0 || theta_or(columns(2)) ~= 0
        unobs_branchv(ctr) = theta_or(columns(1))*ValueAnew(index(1))...
            +theta_or(columns(2))*ValueAnew(index(2));
    else
        unobs_branchv(ctr) = 0;
    end
    if ctr == n
        break;
    end
    
end

actAnew = reconstruct_gustavson(ColumnAnew,ValueAnew,TotalAnew)
unobs_branchv = actAnew*theta_or

n = numel(TotalAnew)-1;
unobs_branch = [];
ctr = 0;
for k = 1:n
    if abs(unobs_branchv(k)) > 1e-5
        ctr = ctr+1;
        unobs_branch(ctr) = k;
    end
end

%%
ctr = 0;
unobs_bus = [];
while(1)
    ctr = ctr+1;
    mybranch = unobs_branch(ctr);
    Aindex = TotalAnew(mybranch):TotalAnew(mybranch+1)-1;
    unobs_bus = [unobs_bus;ColumnAnew(Aindex)];
    if ctr == numel(unobs_branch)
        break;
    end
end

