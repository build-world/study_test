%Copyright 2017 Fan Yifeng. All rights reserved.

%global adjust measurement use degree and meter
%rho def 1rad = 180/pi degree
rho = 180/pi;
%original data
r = 3;
x_B = 20.348;
x_C = 59.503;
y_B = -49.801;
y_C = -796.549;
alpha_AB = dms2degrees([226 44 59]);
alpha_CD = dms2degrees([324 46 03]);
L = [204.952;200.130;345.153;dms2degrees([230 32 37]);dms2degrees([180 00 42]);dms2degrees([170 39 22]);dms2degrees([236 48 37])];
%approximate values calc
Alpha = [alpha_AB - 180 + L(4,1);alpha_AB - 360 + L(4,1) + L(5,1);alpha_AB - 540 + L(4,1) + L(5,1) + L(6,1);alpha_AB - 720 + L(4,1) + L(5,1) + L(6,1) + L(7,1)];
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
    A(2,i + 3) = -1/rho*(Y(4,1) - Y(i,1));
    A(3,i + 3) = 1/rho*(X(4,1) - X(i,1));
end
%W calc
W = [Alpha(4,1) - alpha_CD;X(4,1) - x_C;Y(4,1) - y_C];
%power matrix def
P = zeros(7);
for i = 1:3
    P(i,i) = (10/sqrt(L(i,1)))^2;
end
for i = 4:7
    P(i,i) = 1;
end
%adjust
Q = inv(P);
NAA = A*Q*A';
K = -inv(NAA)*W;
V = Q*A'*K;
msV = V;
for i = 1:7
    if(i < 4)
        msV(i,1) = 1000*msV(i,1);
    else
        msV(i,1) = 3600*msV(i,1);
    end
end
Lad = L + V;
%adjusted values calc
Alphaad = [alpha_AB - 180 + Lad(4,1);alpha_AB - 360 + Lad(4,1) + Lad(5,1);alpha_AB - 540 + Lad(4,1) + Lad(5,1) + Lad(6,1);alpha_AB - 720 + Lad(4,1) + Lad(5,1) + Lad(6,1) + Lad(7,1)];
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
%Error
StdErr0 = sqrt(V'*P*V/r);
QLL = Q - Q*A'*inv(NAA)*A*Q;
StdErri = zeros(7,1);
for i = 1:7
    StdErri(i,1) = StdErr0*sqrt(QLL(i,i));
end
%for question
StdErrS2 = StdErri(2,1);
StdErrB2 = StdErri(5,1);
fx = [COSad(1,1) 0 0 -1/rho*SINad(1,1)*Lad(1,1) 0 0 0];
fy = [SINad(1,1) 0 0 1/rho*COSad(1,1)*Lad(1,1) 0 0 0];
Qxx = fx*QLL*fx';
Qyy = fy*QLL*fy';
StdErrP2 = StdErr0*sqrt(Qxx + Qyy);
