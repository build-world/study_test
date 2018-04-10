def myabs(num):
    if num >= 0:
        return num
    else:
        return -num

def myfact(num):
    mul = 1
    ctr = num
    while ctr > 0:
        mul *= ctr
        ctr -= 1
    return mul

def mysin(rad):
    ctr = 0
    sum = 0.0
    prev = 1.0
    while myabs(sum - prev) >= 0.0000001:
        if ctr % 4 != 0 and ctr % 4 != 2:
            if ctr % 4 == 1:
                sign = 1
            else:
                sign = -1
            prev = sum
            sum += sign / myfact(ctr) * (rad ** ctr)
        ctr += 1
    return sum

