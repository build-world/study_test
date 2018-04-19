#MyMathLib for studying math

#precision means (error < precision) = TRUE

#Foundation Function
def abs(num):
    if num >= 0:
        return num
    else:
        return -num

def fact(num):
    mul = 1
    while num > 0:
        mul *= num
        num -= 1
    return mul

def myfact(num):
    mul = 1
    for ctr in range(1,num+1):
        mul *= ctr
    return mul


#Approximate Function
def sqrt(x, precision):
    y = 0.0
    dy = 1.0
    #presearch
    while y * y < x:
        y += dy
    if y * y == x:
        return y
    else:
        high = y
        y -= dy
        low = y
    #binary search
    dy *= 0.5
    while high - low >= precision:
        y = low + dy
        temp = y * y
        if temp == x:
            return y
        elif temp < x:
            low = y
        else:
            high = y
        dy *= 0.5
    return low + dy


#Taylor formula expansion Function
#Thanks to Taylor, I know the significance of constant e.
def exp_te(x, precision):
    ctr = 0
    fact = 1.0
    sum = 0.0
    prev = 1.0
    while abs(sum - prev) >= precision:
        prev = sum
        sum += 1.0 / fact * (x ** ctr)
        ctr += 1
        fact *= ctr
    return sum

def log_ln(x, precision=0.1):
    """ 0<x y=(x-1)/(x+1)"""
    y = (x-1.0)/(x+1.0)
    summ = 0.0
    if x < 0:
        return False
    else:
        for i in range(10000):
            summ += (y**(i*2))/(2*i+1)
        summ = 2*y*summ
        return summ

def ln_te(x, precision):
    x -= 1
    ctr = 0
    sum = 0.0
    prev = 1.0
    sign = 1.0
    while abs(sum - prev) >= precision:
        prev = sum
        temp = ctr + 1
        sum += sign * (x ** temp) / temp
        sign = -sign
        ctr += 1
    return sum

def sin(rad, precision):
    ctr = 0
    fact = 1.0
    sum = 0.0
    prev = 1.0
    while abs(sum - prev) >= precision:
        if ctr % 4 != 0 and ctr % 4 != 2:
            if ctr % 4 == 1:
                sign = 1.0
            else:
                sign = -1.0
            prev = sum
            sum += sign / fact * (rad ** ctr)
        ctr += 1
        fact *= ctr
    return sum

def cos(rad, precision):
    ctr = 0
    fact = 1.0
    sum = 0.0
    prev = 1.0
    while abs(sum - prev) >= precision:
        if ctr % 4 != 1 and ctr % 4 != 3:
            if ctr % 4 == 0:
                sign = 1.0
            else:
                sign = -1.0
            prev = sum
            sum += sign / fact * (rad ** ctr)
        ctr += 1
        fact *= ctr
    return sum

# expression of  active function
def sigmoid(x):
    s = 1/(1+exp_te(-x, 0.000001))
    return s

def relu(x, a=0.25):
    if a < 0:
        x *= a
    return x

def tanh(x):
    tmp = exp_te(-2*x, 0.000001)
    y = (1-tmp)/(1+tmp)
    return y

def elu(x, a=0.25):
    if x < 0:
        x = a*(exp_te(x, 0.000001)-1)
    return x
