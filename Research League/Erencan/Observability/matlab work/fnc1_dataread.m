% Data import
fid = fopen('ieee_cdf.dat');
% Bus Data
Line_String_Complete = fgetl(fid);
Line_String_Complete = fgetl(fid);
Bus_Data = [];
No_of_Buses = 0;
while ischar(Line_String_Complete)
    Line_String_Complete = fgetl(fid);
    %disp(['#' Line_String_Complete '#'] );
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
    %     disp(['#' Line_String_Complete '#'] );
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

