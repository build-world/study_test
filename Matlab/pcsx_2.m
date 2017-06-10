x_B = 20.384;
x_C = 59.503;
y_B = -49.801;
y_C = -796.549;
alpha_AB = dms2degrees([226 44 59]);
alpha_CD = dms2degrees([324 46 03]);
L = [204.952;200.130;345.153;dms2degrees([230 32 37]);dms2degrees([180 00 42]);dms2degrees([170 39 22]);dms2degrees([236 48 37])];

Alpha = [alpha_AB - 180 + L(4);alpha_AB - 360 + L(4) + L(5);alpha_AB - 540 + L(4) + L(5) + L(6)];
X = zeros(4,1);
X(1,1) = x_B;
Y = zeros(4,1);
Y(1,1) = y_B;
for i = 1:3
    X(i + 1,1) = X(i,1) + cosd(Alpha(i,1));
    Y(i + 1,1) = Y(i,1) + sind(Alpha(i,1));
end

A = [0 0 0 1 1 1 1;0 0 0 0 0 0 0;0 0 0 0 0 0 0];
for i = 1:3
    A(2,i) = cosd(Alpha(i,1));
    A(3,i) = sind(Alpha(i,1));
end
for i = 1:4
    A(2,i + 3) = y_C - Y(i,1);
    A(3,i + 3) = x_C - X(i,1);
end

