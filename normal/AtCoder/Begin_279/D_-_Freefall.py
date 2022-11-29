import math

a, b = map(float, input().split(' '))
x = (a / (2 * b)) ** (2.0 / 3) - 1
if x < 0:
    print(a)
else:
    c = math.floor(x)
    d = c + 1
    ans = b * c + a / ((1 + c) ** 0.5)
    res = b * d + a / ((1 + d) ** 0.5)
    print("%.6f" % min(ans, res))