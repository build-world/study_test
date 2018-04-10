#MyMathLib for studying math

#Foundation
def abs(num):
    if num >= 0:
        return num
    else:
        return -num

def fact(num):
    mul = 1
    ctr = num
    while ctr > 0:
        mul *= ctr
        ctr -= 1
    return mul

#By Taylor formula
#Thanks to Taylor, I know the significance of constant e.
def exp(x, precision):
    ctr = 0
    sum = 0.0
    prev = 1.0
    while abs(sum - prev) >= precision:
        prev = sum
        sum += 1.0 / fact(ctr) * (x ** ctr)
        ctr += 1
    return sum

def sin(rad, precision):
    ctr = 0
    sum = 0.0
    prev = 1.0
    while abs(sum - prev) >= precision:
        if ctr % 4 != 0 and ctr % 4 != 2:
            if ctr % 4 == 1:
                sign = 1
            else:
                sign = -1
            prev = sum
            sum += sign / fact(ctr) * (rad ** ctr)
        ctr += 1
    return sum

def cos(rad, precision):
    ctr = 0
    sum = 0.0
    prev = 1.0
    while abs(sum - prev) >= precision:
        if ctr % 4 != 1 and ctr % 4 != 3:
            if ctr % 4 == 0:
                sign = 1
            else:
                sign = -1
            prev = sum
            sum += sign / fact(ctr) * (rad ** ctr)
        ctr += 1
    return sum
