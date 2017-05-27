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

