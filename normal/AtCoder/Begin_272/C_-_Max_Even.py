n = int(input())
a = list(map(int, input().split(' ')))
x, y = list(), list()
for i in a:
    if i % 2 == 0:
        x.append(i)
    else:
        y.append(i)
x.sort()
y.sort()
ans = -1
if len(x) >= 2:
    ans = max(ans, x[-1] + x[-2])
if len(y) >= 2:
    ans = max(ans, y[-1] + y[-2])
print(ans)