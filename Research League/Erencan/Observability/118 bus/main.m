% This is the main code for EE674 project: Observability Analysis
clear all;
clc;
tic
%tic

% IEEE CDF data
% Data import
fid = fopen('IEEE118BusSystemCDF.txt');

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
fid = fopen('measure_118.dat');

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
toc
%
% Take the transpose of Jacobian (H) matrix
% The following function takes the transpose of a given matrix stored with 
% with Gustavson using sparse techniques. The output is also retured in
% Gustavson form
%

[ColumnHT,ValueHT,TotalHT] = matrix_transpose(ColumnH,ValueH,TotalH);


% Apply sparse multiplication to the Jacobian matrix and its transpose to
% obtain the gain matrix, G.
% The following function multiplies two matrices both stored with Gustavson
% using sparse techniques. The output is also retured in Gustavson form
%
%%
tic
[ColumnG,ValueG,TotalG] = matrix_multiplication...
    (ColumnHT,ValueHT,TotalHT,ColumnH,ValueH,TotalH,No_of_Buses);
 toc
%%
%
% Correct the number of rows if the last column is full zero and therefore
% not srored, using the information of number of buses

% if numel(TotalG)-1 < No_of_Buses
%     add_zero_row = -No_of_Buses + numel(TotalG)+1;
%     for k = 1:add_zero_row
%         TotalG = [TotalG TotalG(end)];
%     end
% end



%reconstruct_gustavson(ColumnG,ValueG,TotalG)

%
% tic
% Check the profile of a matrix stored with Gustavson
profile_G = matrix_profile(ColumnG,TotalG);
% toc
%%
tic
% Ordering is applied
[edges,new_order] = ordering(ColumnG,TotalG);

% New matrix G stored with gustavson is obtained using the new order
[ColumnGnew,ValueGnew,TotalGnew] = ordering_new_matrix(edges,new_order,...
    ColumnG,ValueG,TotalG);
toc
%
%reconstruct_gustavson(ColumnGnew,ValueGnew,TotalGnew)

%tic
% New profile is checked and verified
profile_Gnew = matrix_profile(ColumnGnew,TotalGnew)
%toc


% Cholesky factorisation
[ColumnL,ValueL,TotalL,zero_locations] = sparsechol(ColumnGnew,ValueGnew,TotalGnew);
%reconstruct_gustavson(ColumnL,ValueL,TotalL)
[ColumnLold,ValueLold,TotalLold,zero_locationsold] = sparsechol(ColumnG,ValueG,TotalG);
% zero_locations; 


%%
H = reconstruct_gustavson(ColumnH,ValueH,TotalH);
HT = reconstruct_gustavson(ColumnHT,ValueHT,TotalHT);

%%


G = HT*H ;

tic 

a = inv(G);

toc

%%

toc


