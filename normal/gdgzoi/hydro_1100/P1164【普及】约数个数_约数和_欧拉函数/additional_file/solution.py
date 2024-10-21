def gcd(x, y):
    if y == 0:
        return x
    return gcd(y, x % y)

T = int(input())
for _ in range(T):
    n = int(input())
    num = 2
    for i in range(2, n):
        if n % i == 0:
            num += 1
    sum = 1 + n
    for i in range(2, n):
        if n % i == 0:
            sum += i
    phi = 1
    for i in range(2, n):
        if n % i != 0 and gcd(n, i) == 1:
            phi += 1
    print(num, sum, phi)   