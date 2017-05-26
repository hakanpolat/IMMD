function [ColumnB,ValueB,TotalB] = finding_B(n,ColumnG,ValueG,TotalG)

TotalB = TotalG((n+1):end);
TotalB = TotalB - (TotalB(1)-1);    % Take after (N+1)st element of
                                    %TotalG and decrease its all
                                    %elements till the first element
                                    %becomes '1'.
last_clmns = TotalB(end) - TotalB(1) - 1;   % This will be used for
                                            %ColumnB and ValueB
Columnss = ColumnG(TotalG(n):(TotalG(n+1)-1));
for a=1:numel(Columnss)     % If there is a non-zero column in Nth row
                            %then it means the corresponding row has a
                            %non-zero entry at Nth column. So it should
                            %be decreased for Sparse-B
    if Columnss(a) > n
        TotalB((Columnss(a)-n+1):end)=TotalB((Columnss(a)-n+1):end)-1;
    end
end
ColumnBtemp = ColumnG((numel(ColumnG)-last_clmns):end);
ValueBtemp = ValueG((numel(ColumnG)-last_clmns):end);
ColumnB = zeros(1,(TotalB(end)-1));
ValueB = zeros(1,(TotalB(end)-1));
minus_cntr = 0;
for a=1:numel(ColumnBtemp)  % Again we are  checking the non-zero
                            %entities at Nth column and excluding them.
    if ColumnBtemp(a) <= n
        minus_cntr = minus_cntr + 1;
    else
        ColumnB(a-minus_cntr) = ColumnBtemp(a)-n;
        ValueB(a-minus_cntr) = ValueBtemp(a);
    end
end

end