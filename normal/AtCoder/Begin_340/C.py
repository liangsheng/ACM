def gao(n):
    if n < 2:
        return 0
    return n + gao(n // 2) + gao(n - n // 2)
# for i in range(1, 300):
    # print(i, gao(i))
# print(gao(100000000000000000))

n = int(input())
r, d = 1, 0
while r <= n:
    r *= 2
    d += 1
l = r // 2
ans = 0
x = 2
for i in range(d - 1):
    ans += x * (1 << i)
    x += 1
print(ans + (n - l) * x)