%%
%data input
%elements of interior orientation 
x0 = 0;
y0 = 0;
f = 153.24/1000;
%control point data
data = [
%     Image Space | Object Space
%      x      y        X         Y         Z
    -86.15, -68.99, 36589.41, 25273.32, 2195.17;
    -53.4 , 82.21 , 37631.08, 31324.51, 728.69;
    -14.78, -76.63, 39100.97, 24934.98, 2386.5;
    10.46 , 64.43 , 40426.54, 30319.81, 757.31
];

%%
%preprocess
%get number of control point
szdata = size(data);
%(mm)->(m)
for i = 1:szdata(1)
    data(i,1) = data(i,1)/1000;
    data(i,2) = data(i,2)/1000;
end
%calc scale(var "m") of Image amd Object
sum = 0;
SUM = 0;
for i = 1:szdata - 1
    sum = sum + sqrt((data(i,1) - data(i+1,1))^2 + (data(i,2) - data(i+1,2))^2);
    SUM = SUM + sqrt((data(i,3) - data(i+1,3))^2 + (data(i,4) - data(i+1,4))^2);
end
m = SUM/sum;
%defination iteration initial value of exterior orient elements
Zs_0 = m*f;
H = Zs_0;
Xs_0 = 0;
Ys_0 = 0;
for i = 1:szdata(1)
    Xs_0 = Xs_0 + data(i,3);
    Ys_0 = Ys_0 + data(i,4);
end
Xs_0 = Xs_0/szdata(1);
Ys_0 = Ys_0/szdata(1);
phi_0 = 0;
omega_0 = 0;
kappa_0 = 0;
R_0 = pok2Rmat(phi_0, omega_0, kappa_0);

%%
% iteratively calc
Xs = Xs_0;
Ys = Ys_0;
Zs = Zs_0;
phi = phi_0;
omega = omega_0;
kappa = kappa_0;
R = R_0;
ctr = 0; %iteration counter
adj = zeros(6,1);
%iteration starting point
while (ctr == 0 || adj(4,1) > deg2rad(0.1/60) || adj(5,1) > deg2rad(0.1/60) || adj(6,1) > deg2rad(0.1/60))
    ctr = ctr + 1;
    for i = 1:szdata(1)
        %A mat and %L mat
        [A{i}, L{i}]= ALmat(R, f, data(i,1), x0, data(i,2), y0, data(i,3), Xs, data(i,4), Ys, data(i,5), Zs, omega, kappa);
    end
    %%
    %reconstruct error equations matrix(A mat and L mat) 
    %construct AA matrix by A{} matrix
    for i = 1:szdata(1)
        r = 1;c = 1;
        while r <= 2
            AA(r + (i-1)*2, c) = A{i}(r,c);
            c = c + 1;
            if (c>6)
                c = 1;
                r = r + 1;
            end
        end
    end
    %construct LL matrix by L{} matrix
    for i = 1:szdata(1)
        for r = 1:2
            LL(r + (i-1)*2, 1) = L{i}(r,1);
        end
    end
    %calc new values of iteration
    %adj means adjust values
    adj = LeastSquareAdjust(AA, LL);
    %ExtElem means elements of exterior orientation
    ExtElem = adj + [Xs; Ys; Zs; phi; omega; kappa];
    Xs = ExtElem(1,1);
    Ys = ExtElem(2,1);
    Zs = ExtElem(3,1);
    phi = ExtElem(4,1);
    omega = ExtElem(5,1);
    kappa = ExtElem(6,1);
    R = pok2Rmat(phi, omega, kappa);
end
