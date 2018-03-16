function X = LeastSquareAdjust(A, L)
X = (A'*A)\A'*L;
end
