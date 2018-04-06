function R = pok2Rmat(phi, omega, kappa)
%paramete: 3 axis rotate angle
%return Rotate Matrix
R = [cos(phi), 0, -sin(phi);0, 1, 0;sin(phi), 0, cos(phi)]*[1, 0. 0;0, cos(omega), -sin(omega);0, sin(omega), cos(omega)]*[cos(kappa), -sin(kappa), 0;sin(kappa), cos(kappa), 0;0, 0, 1];
end