n, m, s, t = map(int, input().split(' '))
a = list()
for i in range(m):
    u, v, w = map(int, input().split(' '))
    w = -10000
    a.append([u, v, w])

print(n, m, s, t)
for i in range(m):
    print(a[i][0], a[i][1], a[i][2])

