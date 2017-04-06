q=[2 0 10];
x=-10:0.1:10;
y=polyval(q,x);
plot(x,y);
title('y=x^2+10');
xlabel('x');
ylabel('y');