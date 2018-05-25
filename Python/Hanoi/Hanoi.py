def Hanoi_recursion(level, src, dest):
    buffer = 1
    while buffer == src or buffer == dest:
        buffer += 1
    if level > 1:
        Hanoi_recursion(level - 1, src, buffer)
        print("(", level, ") ", src, " -> ", dest)
        Hanoi_recursion(level - 1, buffer, dest)
    else:
        print("(", level, ") ", src, " -> ", dest)

level = int(input("input level"))
Hanoi_recursion(level, 1, 3)
