%Copyright 2017 Fan Yifeng. All rights reserved.

%Original Data
HA = 10;
HB = 12;
L = [2.359;-0.363;3.009;-1.012;8.23;-6.23;5.878;-5.211];
szL = size(L);
S = [2 2 1 1 2 2 1 1];
szS = size(S);
r = 5;

%power def
C = 2;
%C = 4;
%create power matrix
P = zeros(szS(2));
for i = 1:szS(2)
    P(i,i) = C/S(i);
end
Q = inv(P);

%Adjustment with Conditions
A = [1 0 0 0 -1 0 1 0;0 -1 0 0 0 1 1 0;0 0 -1 0 1 0 0 1;0 0 0 1 0 -1 0 1;0 0 0 0 1 1 0 0];
A0 = [0;0;0;0;-2];
W_1 = A*L+A0;
NAA = A*Q*A';
K = -inv(NAA)*W_1;
V_1 = Q*A'*K;
Lad_1 = L + V_1;
Had_1 = [HA + Lad_1(1);HA + Lad_1(5);HA + Lad_1(3)];

MidErr0_1 = sqrt(V_1'*P*V_1/r);
QLL_1 = Q - Q*A'*inv(NAA)*A*Q;
MidErri_1 = zeros(szL(2),1);
for i = 1:szL(1)
    MidErri_1(i,1) = MidErr0_1*sqrt(QLL_1(i,i));
end

%Adjustment with Indirect Observations
B = [1 0 0;-1 0 0;0 0 1;0 0 -1;0 1 0;0 -1 0;-1 1 0;0 -1 1];
l = [0;-0.004;0;-0.003;0;0;0.007;0.01];
X0 = [HA + L(1);HA + L(5);HA + L(3)];
NBB = B'*P*B;
W_2 = B'*P*l;
x = inv(NBB)*W_2;
Xad = X0 + x;
V_2 = B*x-l;
Lad_2 = L + V_2;
Had_2 = [HA + Lad_2(1);HA + Lad_2(5);HA + Lad_2(3)];

MidErr0_2 = sqrt(V_2'*P*V_2/r);
QXX = inv(NBB);
QLL_2 = B*QXX*B';
MidErri_2 = zeros(szL(2),1);
for i = 1:szL(1)
    MidErri_2(i,1) = MidErr0_2*sqrt(QLL_2(i,i));
end
