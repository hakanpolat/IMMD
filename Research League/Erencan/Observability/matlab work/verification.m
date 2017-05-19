
%% VERIFICATION
recons_H = reconstruct_gustavson(ColumnH,ValueH,TotalH);
recons_HT = reconstruct_gustavson(ColumnHT,ValueHT,TotalHT);
actual_HT = recons_H';
must_be_zero = sum(sum(abs(recons_HT - actual_HT)));

recons_G = reconstruct_gustavson(ColumnG,ValueG,TotalG);
actual_G = recons_G';
must_be_zero = sum(sum(abs(recons_G - actual_G)));
