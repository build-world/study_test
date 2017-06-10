%Start Data
L = [2.359;-0.363;3.009;-1.012;8.23;-6.23;5.878;-5.211];
S = [2 2 1 1 2 2 1 1];

%power def
C = 2;
%C = 4;
%create power matrix
szS = size(S);
P = zeros(szS(2));
for i = 1:szS(2)
    P(i,i) = C/S(i);
end
Q = inv(P);

%Adjustment with Conditions
A = [1 0 0 0 -1 0 1 0;0 -1 0 0 0 1 1 0;0 0 -1 0 1 0 0 1;0 0 0 1 0 -1 0 1;0 0 0 0 1 1 0 0];
A0 = [0;0;0;0;-2];
W = A*L+A0;
NAA = A*Q*A';
K = -inv(NAA)*W;
V = Q*A'*K;
Lad = L + V;

%Adjustment with Indirect Observations
