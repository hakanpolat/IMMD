% ind_vdata = importdata('ind_v.xlsx');
% data2 = ind_vdata(2:7,1);
% data3 = str2num(cell2mat(data2));

%%
dataa = [
    0,-0.174429192,0.243728789
    1,-0.166771196,0.253214362
    2,-0.161058837,0.260503546
    3,-0.156608306,0.266349309
    4,-0.152991625,0.27123618
    5,-0.149931712,0.275490173
    6,-0.14723722,0.279347722
    7,-0.144764386,0.282997163
    8,-0.1423941,0.286605165
    9,-0.140016381,0.290336717
    10,-0.137517096,0.294374977
    11,-0.134762728,0.298947315
    12,-0.131578332,0.304366034
    13,-0.127712186,0.31109607
    14,-0.122780214,0.319862879
    15,-0.116192973,0.331794205
    16,-0.10711196,0.348501018
    17,-0.094589905,0.37178626
    18,-0.078133373,0.402501005
    19,-0.058550591,0.438816539
    20,-0.03798587,0.476103218
    21,-0.018386311,0.50992832
    22,0,0.539022402
    23,0.018386311,0.564954459
    24,0.03798587,0.589791662
    25,0.058550591,0.614055501
    26,0.078133373,0.636333428
    27,0.094589905,0.654817781
    28,0.10711196,0.668907643
    29,0.116192973,0.679226483
    30,0.122780214,0.68680637
    31,0.127712186,0.692543632
    32,0.131578332,0.697068824
    33,0.134762728,0.700796273
    34,0.137517096,0.704000556
    35,0.140016381,0.706874237
    36,0.1423941,0.709564623
    37,0.144764386,0.712196767
    38,0.14723722,0.71488938
    39,0.149931712,0.717768603
    40,0.152991625,0.720983899
    41,0.156608306,0.724731261
    42,0.161058837,0.729291564
    43,0.166771196,0.735095901
    44,0.174429192,0.742830631
    45,0.185110159,0.753575178
    46,0.200359603,0.768876753
    47,0.221889346,0.790448558
    48,0.250415155,0.81900746
    49,0.283896579,0.852513866
    50,0.317363572,0.885998371
    51,0.345845643,0.914490937
    52,0.367300994,0.93595003
    53,0.382443076,0.95108837
    54,0.392980312,0.961615112
    55,0.400453559,0.969070845
    56,0.405934006,0.974526311
    57,0.410097485,0.978656697
    58,0.413361691,0.981878842
    59,0.41599046,0.984455479
    60,0.418157982,0.986559421
    61,0.419985558,0.988310263
    62,0.421562383,0.989795111
    63,0.422957615,0.99108057
    64,0.424227805,0.99222008
    65,0.425421885,0.993258775
    66,0.426584943,0.994237102
    67,0.427761549,0.99519393
    68,0.428999265,0.996169789
    69,0.430353097,0.997210954
    70,0.431892073,0.998375533
    71,0.433710043,0.999743588
    72,0.435944366,1.001434858
    73,0.438808256,1.003639701
    74,0.442643094,1.006669249
    75,0.447987178,1.011020688
    76,0.455612979,1.017408661
    77,0.466376165,1.026604041
    78,0.480634379,1.038834433
    79,0.497367131,1.05287204
    80,0.514089088,1.06589488
    81,0.528314632,1.074882779
    82,0.539022402,1.078044805
    83,0.546568148,1.074882779
    84,0.551805792,1.06589488
    85,0.555504909,1.05287204
    86,0.558200054,1.038834433
    87,0.560227876,1.026604041
    88,0.561795682,1.017408661
    89,0.56303351,1.011020688
    90,0.564026155,1.006669249
    91,0.564831445,1.003639701
    92,0.565490492,1.001434858
    93,0.566033545,0.999743588
    94,0.56648346,0.998375533
    95,0.566857857,0.997210954
    96,0.567170523,0.996169789
    97,0.567432381,0.99519393
    98,0.567652159,0.994237102
    99,0.56783689,0.993258775
    100,0.567992274,0.99222008
    101,0.568122955,0.99108057
    102,0.568232728,0.989795111
    103,0.568324705,0.988310263
    104,0.568401439,0.986559421
    105,0.568465019,0.984455479
    106,0.56851715,0.981878842
    107,0.568559212,0.978656697
    108,0.568592305,0.974526311
    109,0.568617286,0.969070845
    110,0.5686348,0.961615112
    111,0.568645294,0.95108837
    112,0.568649036,0.93595003
    113,0.568645294,0.914490937
    114,0.5686348,0.885998371
    115,0.568617286,0.852513866
    116,0.568592305,0.81900746
    117,0.568559212,0.790448558
    118,0.56851715,0.768876753
    119,0.568465019,0.753575178
    120,0.568401439,0.742830631
    121,0.568324705,0.735095901
    122,0.568232728,0.729291564
    123,0.568122955,0.724731261
    124,0.567992274,0.720983899
    125,0.56783689,0.717768603
    126,0.567652159,0.71488938
    127,0.567432381,0.712196767
    128,0.567170523,0.709564623
    129,0.566857857,0.706874237
    130,0.56648346,0.704000556
    131,0.566033545,0.700796273
    132,0.565490492,0.697068824
    133,0.564831445,0.692543632
    134,0.564026155,0.68680637
    135,0.56303351,0.679226483
    136,0.561795682,0.668907643
    137,0.560227876,0.654817781
    138,0.558200054,0.636333428
    139,0.555504909,0.614055501
    140,0.551805792,0.589791662
    141,0.546568148,0.564954459
    142,0.539022402,0.539022402
    143,0.528314632,0.50992832
    144,0.514089088,0.476103218
    145,0.497367131,0.438816539
    146,0.480634379,0.402501005
    147,0.466376165,0.37178626
    148,0.455612979,0.348501018
    149,0.447987178,0.331794205
    150,0.442643094,0.319862879
    151,0.438808256,0.31109607
    152,0.435944366,0.304366034
    153,0.433710043,0.298947315
    154,0.431892073,0.294374977
    155,0.430353097,0.290336717
    156,0.428999265,0.286605165
    157,0.427761549,0.282997163
    158,0.426584943,0.279347722
    159,0.425421885,0.275490173
    160,0.424227805,0.27123618
    161,0.422957615,0.266349309
    162,0.421562383,0.260503546
    163,0.419985558,0.253214362
    164,0.418157982,0.243728789
    165,0.41599046,0.230880301
    166,0.413361691,0.213002088
    167,0.410097485,0.188208139
    168,0.405934006,0.155518851
    169,0.400453559,0.116556979
    170,0.392980312,0.07561674
    171,0.382443076,0.036597433
    172,0.367300994,0
    173,0.345845643,-0.036597433
    174,0.317363572,-0.07561674
    175,0.283896579,-0.116556979
    176,0.250415155,-0.155518851
    177,0.221889346,-0.188208139
    178,0.200359603,-0.213002088
    179,0.185110159,-0.230880301
    180,0.174429192,-0.243728789
    181,0.166771196,-0.253214362
    182,0.161058837,-0.260503546
    183,0.156608306,-0.266349309
    184,0.152991625,-0.27123618
    185,0.149931712,-0.275490173
    186,0.14723722,-0.279347722
    187,0.144764386,-0.282997163
    188,0.1423941,-0.286605165
    189,0.140016381,-0.290336717
    190,0.137517096,-0.294374977
    191,0.134762728,-0.298947315
    192,0.131578332,-0.304366034
    193,0.127712186,-0.31109607
    194,0.122780214,-0.319862879
    195,0.116192973,-0.331794205
    196,0.10711196,-0.348501018
    197,0.094589905,-0.37178626
    198,0.078133373,-0.402501005
    199,0.058550591,-0.438816539
    200,0.03798587,-0.476103218
    201,0.018386311,-0.50992832
    202,0,-0.539022402
    203,-0.018386311,-0.564954459
    204,-0.03798587,-0.589791662
    205,-0.058550591,-0.614055501
    206,-0.078133373,-0.636333428
    207,-0.094589905,-0.654817781
    208,-0.10711196,-0.668907643
    209,-0.116192973,-0.679226483
    210,-0.122780214,-0.68680637
    211,-0.127712186,-0.692543632
    212,-0.131578332,-0.697068824
    213,-0.134762728,-0.700796273
    214,-0.137517096,-0.704000556
    215,-0.140016381,-0.706874237
    216,-0.1423941,-0.709564623
    217,-0.144764386,-0.712196767
    218,-0.14723722,-0.71488938
    219,-0.149931712,-0.717768603
    220,-0.152991625,-0.720983899
    221,-0.156608306,-0.724731261
    222,-0.161058837,-0.729291564
    223,-0.166771196,-0.735095901
    224,-0.174429192,-0.742830631
    225,-0.185110159,-0.753575178
    226,-0.200359603,-0.768876753
    227,-0.221889346,-0.790448558
    228,-0.250415155,-0.81900746
    229,-0.283896579,-0.852513866
    230,-0.317363572,-0.885998371
    231,-0.345845643,-0.914490937
    232,-0.367300994,-0.93595003
    233,-0.382443076,-0.95108837
    234,-0.392980312,-0.961615112
    235,-0.400453559,-0.969070845
    236,-0.405934006,-0.974526311
    237,-0.410097485,-0.978656697
    238,-0.413361691,-0.981878842
    239,-0.41599046,-0.984455479
    240,-0.418157982,-0.986559421
    241,-0.419985558,-0.988310263
    242,-0.421562383,-0.989795111
    243,-0.422957615,-0.99108057
    244,-0.424227805,-0.99222008
    245,-0.425421885,-0.993258775
    246,-0.426584943,-0.994237102
    247,-0.427761549,-0.99519393
    248,-0.428999265,-0.996169789
    249,-0.430353097,-0.997210954
    250,-0.431892073,-0.998375533
    251,-0.433710043,-0.999743588
    252,-0.435944366,-1.001434858
    253,-0.438808256,-1.003639701
    254,-0.442643094,-1.006669249
    255,-0.447987178,-1.011020688
    256,-0.455612979,-1.017408661
    257,-0.466376165,-1.026604041
    258,-0.480634379,-1.038834433
    259,-0.497367131,-1.05287204
    260,-0.514089088,-1.06589488
    261,-0.528314632,-1.074882779
    262,-0.539022402,-1.078044805
    263,-0.546568148,-1.074882779
    264,-0.551805792,-1.06589488
    265,-0.555504909,-1.05287204
    266,-0.558200054,-1.038834433
    267,-0.560227876,-1.026604041
    268,-0.561795682,-1.017408661
    269,-0.56303351,-1.011020688
    270,-0.564026155,-1.006669249
    271,-0.564831445,-1.003639701
    272,-0.565490492,-1.001434858
    273,-0.566033545,-0.999743588
    274,-0.56648346,-0.998375533
    275,-0.566857857,-0.997210954
    276,-0.567170523,-0.996169789
    277,-0.567432381,-0.99519393
    278,-0.567652159,-0.994237102
    279,-0.56783689,-0.993258775
    280,-0.567992274,-0.99222008
    281,-0.568122955,-0.99108057
    282,-0.568232728,-0.989795111
    283,-0.568324705,-0.988310263
    284,-0.568401439,-0.986559421
    285,-0.568465019,-0.984455479
    286,-0.56851715,-0.981878842
    287,-0.568559212,-0.978656697
    288,-0.568592305,-0.974526311
    289,-0.568617286,-0.969070845
    290,-0.5686348,-0.961615112
    291,-0.568645294,-0.95108837
    292,-0.568649036,-0.93595003
    293,-0.568645294,-0.914490937
    294,-0.5686348,-0.885998371
    295,-0.568617286,-0.852513866
    296,-0.568592305,-0.81900746
    297,-0.568559212,-0.790448558
    298,-0.56851715,-0.768876753
    299,-0.568465019,-0.753575178
    300,-0.568401439,-0.742830631
    301,-0.568324705,-0.735095901
    302,-0.568232728,-0.729291564
    303,-0.568122955,-0.724731261
    304,-0.567992274,-0.720983899
    305,-0.56783689,-0.717768603
    306,-0.567652159,-0.71488938
    307,-0.567432381,-0.712196767
    308,-0.567170523,-0.709564623
    309,-0.566857857,-0.706874237
    310,-0.56648346,-0.704000556
    311,-0.566033545,-0.700796273
    312,-0.565490492,-0.697068824
    313,-0.564831445,-0.692543632
    314,-0.564026155,-0.68680637
    315,-0.56303351,-0.679226483
    316,-0.561795682,-0.668907643
    317,-0.560227876,-0.654817781
    318,-0.558200054,-0.636333428
    319,-0.555504909,-0.614055501
    320,-0.551805792,-0.589791662
    321,-0.546568148,-0.564954459
    322,-0.539022402,-0.539022402
    323,-0.528314632,-0.50992832
    324,-0.514089088,-0.476103218
    325,-0.497367131,-0.438816539
    326,-0.480634379,-0.402501005
    327,-0.466376165,-0.37178626
    328,-0.455612979,-0.348501018
    329,-0.447987178,-0.331794205
    330,-0.442643094,-0.319862879
    331,-0.438808256,-0.31109607
    332,-0.435944366,-0.304366034
    333,-0.433710043,-0.298947315
    334,-0.431892073,-0.294374977
    335,-0.430353097,-0.290336717
    336,-0.428999265,-0.286605165
    337,-0.427761549,-0.282997163
    338,-0.426584943,-0.279347722
    339,-0.425421885,-0.275490173
    340,-0.424227805,-0.27123618
    341,-0.422957615,-0.266349309
    342,-0.421562383,-0.260503546
    343,-0.419985558,-0.253214362
    344,-0.418157982,-0.243728789
    345,-0.41599046,-0.230880301
    346,-0.413361691,-0.213002088
    347,-0.410097485,-0.188208139
    348,-0.405934006,-0.155518851
    349,-0.400453559,-0.116556979
    350,-0.392980312,-0.07561674
    351,-0.382443076,-0.036597433
    352,-0.367300994,0
    353,-0.345845643,0.036597433
    354,-0.317363572,0.07561674
    355,-0.283896579,0.116556979
    356,-0.250415155,0.155518851
    357,-0.221889346,0.188208139
    358,-0.200359603,0.213002088
    359,-0.185110159,0.230880301
    360,-0.174429192,0.243728789
    ];

elect_angle = dataa(:,1);
indvphase = dataa(:,2)*1000;
indvline = dataa(:,3)*1000;

%%
Num = numel(elect_angle)-1;
% % some functions
% for k = 1:Num+1
%     if k <= Num/2
%         fun1(k) = 10;
%         fun2(k) = -20;
%         fun3(k) = sin((k-1)*pi/180);
%         fun4(k) = 0;
%         fun5(k) = sin((k-1)*pi/180);
%         fun6(k) = cos((k-1)*pi/180);
%     else
%         fun1(k) = -10;
%         fun2(k) = 5;
%         fun3(k) = sin((k-1)*pi/180);
%         fun4(k) = 3;
%         fun5(k) = 0;
%         fun6(k) = cos((k-1)*pi/180);
%     end
% end
% mean value
a0_int = 0;
% fundamental & harmonics
a_int = zeros(1,20);
b_int = zeros(1,20);
% function
func = indvphase;
for k = 1:Num
    radang = (k-1)*pi/(Num/2);
    a0_int = a0_int+func(k);
    for l = 1:numel(a_int)
        a_int(1,l) = a_int(1,l)+func(k)*cos(l*radang);
        b_int(1,l) = b_int(1,l)+func(k)*sin(l*radang);
    end
end

fprintf('\nList of harmonis:\n');
dcval = a0_int/(Num);
fprintf('DC:%g\n',dcval);
for l = 1:numel(a_int)
    a = 2*a_int(l)/(Num);
    b = 2*b_int(l)/(Num);
    peak_magn(l) = sqrt(a.^2+b.^2);
    fprintf('%gth:%g\n',l,peak_magn(l));
end

% a0 = a0_int/(Num);
% a = 2*a_int/(Num);
% b = 2*b_int/(Num);
%
% peak_magn = sqrt(a1^2+b1^2);
% rms_magn = peak_magn/sqrt(2);
% one_module = rms_magn/4;

figure;
subplot(2,1,1)
plot(elect_angle,func,'b- ','Linewidth',1.5)
grid on;
set(gca,'FontSize',12);
xlabel('Electrical degrees','FontSize',8,'FontWeight','Bold');
ylabel('Phase induced voltage','FontSize',8,'FontWeight','Bold');
harm = 0:20;
harmvals(1) = dcval;
harmvals(2:length(harm)) = peak_magn(:);
subplot(2,1,2)
plot(harm,harmvals,'b o','Linewidth',1.5)
grid on;
set(gca,'FontSize',12);
xlabel('Harmonic order','FontSize',8,'FontWeight','Bold');
ylabel('Value (peak)','FontSize',8,'FontWeight','Bold');
