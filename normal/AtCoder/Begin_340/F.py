import math

def gao(x1, y1, x2, y2):
    return 0.5 * abs(x1* y2 - x2* y1)

def ext_gcd(x, y):
    if y == 0:
        return [x, 1, 0]
    d, a, b = ext_gcd(y, x % y)
    return d, b, a - x // y * b

x1, y1 = map(int, input().split(' '))
if x1 == 0:
    if abs(y1) == 1 or abs(y1) == 2:
        print(2 // y1, 0)
    else:
        print(-1)
elif y1 == 0:
    if abs(x1) == 1 or abs(x1) == 2:
        print(0, 2 // x1)
    else:
        print(-1)
else:
    d, x, y = ext_gcd(x1, y1)
    if abs(d) > 2:
        print(-1)
    else:
        x, y = 2 // d * x, 2 // d * y
        print(y, -x)
