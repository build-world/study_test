phi = -2;
omega = 3;
kappa = 88;
R_phi = [cosd(phi) 0 -sind(phi);0 1 0;sind(phi) 0 cosd(phi)];
R_omega = [1 0 0;0 cosd(omega) -sind(omega);0 sind(omega) cosd(omega)];
R_kappa = [cosd(kappa) -sind(kappa) 0;sind(kappa) cosd(kappa) 0;0 0 1];
R = R_phi * R_omega * R_kappa;
%
X = -150;
Y = -300;
Z = -2800;
f = 0.153;
x_0 = -0.012 / 1000;
y_0 = 0.006 / 1000;
x = (R(1,1)*X + R(2,1)*Y + R(3,1)*Z)/(R(1,3)*X + R(2,3)*Y + R(3,3)*Z)*(-f) + x_0;
y = (R(1,2)*X + R(2,2)*Y + R(3,2)*Z)/(R(1,3)*X + R(2,3)*Y + R(3,3)*Z)*(-f) + y_0;
