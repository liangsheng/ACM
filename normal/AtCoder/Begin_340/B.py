m = int(input())
a = list()
for _ in range(m):
    c, x = map(int, input().split(' '))
    if c == 1:
        a.append(x)
    else:
        print(a[len(a) - x])