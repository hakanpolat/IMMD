% Below is an example

% Lnew = [1,0,0,0,0,0;
%     0,1,0,0,0,0;
%     1,1,1,0,0,0;
%     0,0,0,1,0,0;
%     0,0,1,0,1,0;
%     0,0,0,0,1,1];
% [ColumnL,ValueL,TotalL] = apply_gustavson(Lnew);
% b = [0,1,2,0,3,0];


[ColumnL,ValueL,TotalL] = apply_gustavson(myyL);
n = numel(TotalL)-1;
b = zeros(1,30);
for k = 1:n
    if k == 18 || k == 19 || k == 20 || k == 22 || k == 24
        b(k) = 1;
    end
end

% find the fpg array
myarray = [];
for k = 1:n
    if numel(find(ColumnL==k))==1
        myarray(k) = -1;
    else
        index = find(ColumnL==k);
        indexr = index(2);
        ctr = 0;
        while(1)
            ctr = ctr+1;
            if indexr >= TotalL(ctr) && indexr < TotalL(ctr+1)
                myarray(k) = ctr;
                break;
            end
        end
    end
end
% find the fpg tree
tree_connections = [];
ctr = 0;
inctr = 0;
while(1)
    ctr = ctr+1;
    if myarray(ctr) ~= -1
        inctr = inctr+1;
        tree_connections(inctr,1)=ctr;
        tree_connections(inctr,2)=myarray(ctr);
    end
    if ctr == numel(myarray)
        break;
    end
end
pathreq = find(b~=0);


% Below is an example

% n = 10;
% tree_connections = [1,2;2,4;2,3;3,6;6,7;3,5;5,8;5,9;9,10];
% pathreq = [1,2,3,5];
% 

tic
single_con = [];
for k = 1:n
    if numel(find(tree_connections(:,:)==k)) == 1
        single_con = [single_con k];
    end
end
combin = combnk(pathreq,2);
el_say = unique(tree_connections);
eklenebilir = setdiff(el_say,pathreq);
el_req = numel(pathreq);
ekle_comb = numel(el_say)-el_req;
index = 0;
con_var = [];
my_break = 0;
while(1)
    index = index + 1
    ekle_num = factorial(ekle_comb)/...
        (factorial(index-1)*factorial(ekle_comb-index+1));
    eklenecekler = combntns(eklenebilir,index-1);
    for m = 1:ekle_num
        if index == 1
            pathreq_temp = [pathreq];
        else
            pathreq_temp = [pathreq eklenecekler(m,:)];
        end
        combin = combnk(pathreq_temp,2);
        ctr = 0;
        con_var = [];
        for k = 1:numel(tree_connections(:,1))
            for l = 1:numel(combin(:,1))
                if tree_connections(k,1)==combin(l,1) && ...
                        tree_connections(k,2)==combin(l,2) || ...
                        tree_connections(k,1)==combin(l,2) && ...
                        tree_connections(k,2)==combin(l,1)
                    con_var = [con_var;combin(l,:)];
                    ctr = ctr+1;
                end
            end
        end
        %if ctr == numel(combin(:,1))+index-1
        isrepeated = 0;
        pathreq_temp;
        for g = 1:numel(pathreq_temp)
            isrepeated(g) = sum(sum(con_var==pathreq_temp(g)));
        end
        uc_var = 0;
        for h = 1:numel(single_con)
            uc_var = uc_var + sum(pathreq_temp(:)==single_con(h));
        end
        cond1 = ctr == numel(pathreq_temp)-1;
        cond2 = sum(isrepeated>2)==0;
        cond3 = uc_var == 2;
        if ctr == numel(pathreq_temp)-1 && sum(isrepeated>2)==0 && uc_var == 2
            % Burada uç olup olmadýðýna bakýlacak
            fprintf('\nPath found!\n');
            my_break = 1;
            pathreq_temp
            break;
        end 
    end
    if index == numel(unique(tree_connections))-numel(pathreq)+1 || my_break == 1
        break;
    end
end

toc


