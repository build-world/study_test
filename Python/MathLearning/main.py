#-*- coding: UTF-8 -*-
import MyMathLib as mml
x = float(input("x = "))
print("ln(x) = ", mml.ln_te(x, 1e-100), " / ", mml.log_ln(x, 1e-8))
#print("sqrt(x) = ", mml.sqrt(x, 1e-8))
#print("exp(x) = ", mml.exp_te(x, 1e-16), "\nsin x = ", mml.sin(x, 1e-16), "\ncos x = ", mml.cos(x, 1e-16), "\n sqrt(x) = ", mml.sqrt(x, 1e-16))
#print(mml.exp(100, 1.0))
