Lnew = [1,0,0,0,0,0;
    0,1,0,0,0,0;
    1,1,1,0,0,0;
    0,0,0,1,0,0;
    0,0,1,0,1,0;
    0,0,0,0,1,1];
[ColumnL,ValueL,TotalL] = apply_gustavson(Lnew);
b = [0,1,2,0,3,0];
%%
%tic
clc
% find the fpg array
n = numel(TotalL)-1;
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
el_say = unique(tree_connections);
eklenecek = 
index = 0;
con_var = [];
while(1)
    for m = 1:index
        combin = combnk(pathreq,2)
        ctr = 0;
        for k = 1:numel(tree_connections(:,1))
            for l = 1:numel(combin(:,1))
                if tree_connections(k,1)==combin(l,1) && ...
                        tree_connections(k,2)==combin(l,2) || ...
                        tree_connections(k,1)==combin(l,2) && ...
                        tree_connections(k,2)==combin(l,1)
                    con_var = [con_var;combin(l,:)]
                    ctr = ctr+1
                end
            end
        end
        if ctr == numel(combin(:,1))+index-1
            45
        end
    end
        index = index + 1
    
    if index == 3
        break;
    end
end




%%
% shortest path algorithm
% possible paths are determined
single_con = [];
for k = 1:n
    if numel(find(tree_connections(:,:)==k)) == 1
        single_con = [single_con k];
    end
end
num_sc = numel(single_con);
num_of_paths = num_sc*(num_sc-1)/2;




%%
stop = 0;
ctr = 0;
path = 0;
possible_path = [];
for k = 1:num_of_paths
    %k=1
    path(1) = single_con(k);
    pos_con = [tree_connections(find(tree_connections(:,2)==path(1)),1)
        tree_connections(find(tree_connections(:,1)==path(1)),2)];
    path(2) = pos_con;
    for l = k+1:numel(single_con)
        if path(2)==single_con(l)
            stop = 1;
        end
    end
    if stop~=1
        pos_con = [tree_connections(find(tree_connections(:,2)==path(2)),1)
            tree_connections(find(tree_connections(:,1)==path(2)),2)]
        for l = 1:numel(pos_con)
            if sum(pos_con(l) == path(:)) > 0
                pos_con(l) = []
                break;
            end
        end
        ctr = 1;
        for l = 1:numel(pos_con)
            path(ctr+2) = pos_con(l)
            for m = k+1:numel(single_con)
                if path(ctr+2)==single_con(m)
                    stop2 = 1
                    break;
                end
            end
            if stop2 == 1
                possible_path = [possible_path path]
                mysum = 0;
                for n = 1:numel(pathreq)
                    mysum = mysum + any(possible_path==pathreq(n))
                    
                end
                if mysum == numel(pathreq)
                    4
                end
                stop2 = 0
            else
                ctr = ctr+1
                pos_con2 = [tree_connections(find(tree_connections(:,2)==path(ctr+1)),1)
                    tree_connections(find(tree_connections(:,1)==path(ctr+1)),2)]
                for o = 1:numel(pos_con2)
                    if sum(pos_con2(o) == path(:)) > 0
                        pos_con2(o) = []
                        break;
                    end
                end
                path(ctr+2) = pos_con2
                for m = k+1:numel(single_con)
                    if path(ctr+2)==single_con(m)
                        stop2 = 1
                        break;
                    end
                end
                
                if stop2 == 1
                    
                    mysum = 0;
                    for n = 1:numel(pathreq)
                        mysum = mysum + any(path==pathreq(n))
                        
                    end
                    if mysum == numel(pathreq)
                        4
                    end
                    stop2 = 0
                end
                
            end
            %pos_con = [tree_connections(find(tree_connections(:,2)==path(ctr)),1)
            %    tree_connections(find(tree_connections(:,1)==path(ctr)),2)]
            
        end
    end
end



%toc

