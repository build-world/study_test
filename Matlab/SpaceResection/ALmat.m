function [A, L] = ALmat(R, f, x, x0, y, y0, X, Xs, Y, Ys, Z, Zs, omega, kappa)
X_ = R(1,1)*(X - Xs) + R(2,1)*(Y - Ys) +R(3,1)*(Z - Zs);
Y_ = R(1,2)*(X - Xs) + R(2,2)*(Y - Ys) +R(3,2)*(Z - Zs);
Z_ = R(1,3)*(X - Xs) + R(2,3)*(Y - Ys) +R(3,3)*(Z - Zs);
temp1 = (x - x0)*cos(kappa) - (y - y0)*sin(kappa);
temp2 = (x - x0)*sin(kappa) + (y - y0)*cos(kappa);
%
A(1,1) = (R(1,1)*f + R(1,3)*(x - x0))/Z_;
A(1,2) = (R(2,1)*f + R(2,3)*(x - x0))/Z_;
A(1,3) = (R(3,1)*f + R(3,3)*(x - x0))/Z_;
A(1,4) = (y - y0)*sin(omega) - ((x - x0)/f*temp1 + f*cos(kappa))*cos(omega);
A(1,5) = -f*sin(kappa) - (x - x0)/f*temp2;
A(1,6) = y - y0;
A(2,1) = (R(1,2)*f + R(1,3)*(y - y0))/Z_;
A(2,2) = (R(2,2)*f + R(2,3)*(y - y0))/Z_;
A(2,3) = (R(3,2)*f + R(3,3)*(y - y0))/Z_;
A(2,4) = (x - x0)*sin(omega) - ((y - y0)/f*temp1 - f*sin(kappa))*cos(omega);
A(2,5) = -f*cos(kappa) - (y - y0)/f*temp2;
A(2,6) = x0 - x;
%
L(1,1) = x + f*X_/Z_ - x0;
L(2,1) = y + f*Y_/Z_ - y0;
end