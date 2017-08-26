a = {'Module','m','n';1,2,3;4,5,6;7,8,9};
%a = {'Time','Temperature'; 12,98; 13,99; 14,97};
filename = 'testdata.xlsx';
xlswrite(filename,a);

%%
b = zeros(9,76);
b = {'Module',};
b(2:9,1) = 1:8
