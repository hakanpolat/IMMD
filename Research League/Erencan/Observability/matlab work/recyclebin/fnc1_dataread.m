tic
% IEEE CDF data
% Data import
fid = fopen('ieee_cdf.dat');
% Bus Data
Line_String_Complete = fgetl(fid);
Line_String_Complete = fgetl(fid);
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

Bus_number = Bus_Data(:,1);
Branch_number_from = Branch_Data(:,1);
Branch_number_to = Branch_Data(:,2);

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

toc
