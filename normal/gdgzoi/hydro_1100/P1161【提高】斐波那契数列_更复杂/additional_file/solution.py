P = 1000000007
n = int(input())
a, b, c = 1, 1, 17
for i in range(4, n + 1):
    a, b, c = [b, c, (2 * b + 3 * c + 4 * i) % P]
print(c)