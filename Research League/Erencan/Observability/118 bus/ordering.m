function [edges,new_order] = ordering(col,tot)
n = numel(tot)-1;
nodes = 1:n;
edges = [];
for k = 1:n
    nonzero_places = 0;
    num_of_nonzero = tot(k+1)-tot(k);
    for l = 1:num_of_nonzero
        if col(tot(k)+l-1) > k
            edges = [edges;k,col(tot(k)+l-1)];
        end
    end
end

stored_zero = [];
for k = 1:n
    if any(col(:)==k)==0
        stored_zero = [stored_zero k];
    end
end

% discard the columns with full zero elements
new_order = stored_zero';

start = 1;
edges_mod = edges;
new_order = [new_order;start];
candidate = edges((edges(:,1)==start),2);
candidate = [candidate;edges((edges(:,2)==start),1)];
next = candidate;
new_order = [new_order;next];
edges_mod((edges(:,1)==start),:) = [];
temp = next;
next = [];
ctr = 0;
while(1)
    ctr = ctr+1;
    for k = 1:numel(temp)
        temp(k);
        candidate = edges_mod((edges_mod(:,2)==temp(k)),1);
        candidate = [candidate;edges_mod((edges_mod(:,1)==temp(k)),2)];
        for l = 1:numel(candidate)
            if any(candidate(l)==new_order)~=1
                next = [next;candidate(l)];
                new_order = [new_order;candidate(l)];
            end
        end
        edges_mod((edges_mod(:,2)==temp(k)),:) = [];
        edges_mod((edges_mod(:,1)==temp(k)),:) = [];
    end
    temp = next;
    next = [];
    if isempty(edges_mod) || numel(new_order) == n || ctr == 30 || isempty(temp)
        break;
    end
end
if isempty(edges_mod)==0
    new_order = [new_order;edges_mod(1,1)];
    continued = edges_mod(1,1);
end
ctr = 0;
next = continued;
temp = next;
next = [];
while(isempty(edges_mod)==0)
    ctr = ctr+1;
    for k = 1:numel(temp)
        temp(k);
        candidate = edges_mod((edges_mod(:,1)==temp(k)),2);
        candidate = [candidate;edges_mod((edges_mod(:,2)==temp(k)),1)];
        for l = 1:numel(candidate)
            if any(candidate(l)==new_order)~=1
                next = [next;candidate(l)];
                new_order = [new_order;candidate(l)];
            end
        end
        edges_mod((edges_mod(:,2)==temp(k)),:) = [];
        edges_mod((edges_mod(:,1)==temp(k)),:) = [];
    end
    temp = next;
    next = [];
    if isempty(edges_mod) || numel(new_order) == n || ctr == 30 || isempty(temp)
        break;
    end
end

end



