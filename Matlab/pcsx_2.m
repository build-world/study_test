%Copyright 2017 Fan Yifeng. All rights reserved.

%rho def
rho = 206265;
%original data
x_B = 20.384;
x_C = 59.503;
y_B = -49.801;
y_C = -796.549;
alpha_AB = dms2degrees([226 44 59]);
alpha_CD = dms2degrees([324 46 03]);
L = [204.952;200.130;345.153;dms2degrees([230 32 37]);dms2degrees([180 00 42]);dms2degrees([170 39 22]);dms2degrees([236 48 37])];
%????
Alpha = [alpha_AB - 180 + L(4);alpha_AB - 360 + L(4) + L(5);alpha_AB - 540 + L(4) + L(5) + L(6);alpha_AB - 720 + L(4) + L(5) + L(6) + L(7)];
COS = zeros(3,1);
SIN = zeros(3,1);
for i = 1:3
    COS(i,1) = cosd(Alpha(i,1));
    SIN(i,1) = sind(Alpha(i,1));
end
X = zeros(4,1);
X(1,1) = x_B;
Y = zeros(4,1);
Y(1,1) = y_B;
for i = 1:3
    X(i + 1,1) = X(i,1) + L(i,1)*COS(i,1);
    Y(i + 1,1) = Y(i,1) + L(i,1)*SIN(i,1);
end
%create A Matrix
A = [0 0 0 1 1 1 1;0 0 0 0 0 0 0;0 0 0 0 0 0 0];
for i = 1:3
    A(2,i) = COS(i,1);
    A(3,i) = SIN(i,1);
end
for i = 1:4
    A(2,i + 3) = -1000/rho*(y_C - Y(i,1));
    A(3,i + 3) = 1000/rho*(x_C - X(i,1));
end
%debug
A(2,7) = 0;
A(3,7) = 0;

%power matrix def
P = zeros(7);
for i = 1:3
    P(i,i) = (10/sqrt(L(i)))^2;
end
for i = 4:7
    P(i,i) = 1;
end
%W
W = [Alpha(4,1) - alpha_CD;X(4,1) - x_C;Y(4,1) - y_C];
%adjust
Q = inv(P);
NAA = A*Q*A';
K = -inv(NAA)*W;
V = Q*A'*K;
Lad = L + V;
%
Alphaad = [alpha_AB - 180 + Lad(4);alpha_AB - 360 + Lad(4) + Lad(5);alpha_AB - 540 + Lad(4) + Lad(5) + Lad(6);alpha_AB - 720 + Lad(4) + Lad(5) + Lad(6) + Lad(7)];
COSad = zeros(3,1);
SINad = zeros(3,1);
for i = 1:3
    COSad(i,1) = cosd(Alphaad(i,1));
    SINad(i,1) = sind(Alphaad(i,1));
end
Xad = zeros(4,1);
Xad(1,1) = x_B;
Yad = zeros(4,1);
Yad(1,1) = y_B;
for i = 1:3
    Xad(i + 1,1) = Xad(i,1) + Lad(i,1)*COSad(i,1);
    Yad(i + 1,1) = Yad(i,1) + Lad(i,1)*SINad(i,1);
end