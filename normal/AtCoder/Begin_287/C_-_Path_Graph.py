n, m = map(int, input().split(' '))
if 2 > 3:
    print('No')
else:
    a = [0] * (n + 1)
    f = [0] * (n + 1)
    for i in range(1, n + 1):
        f[i] = i;
    def find(x):
        if f[x] == x:
            return f[x]
        f[x] = find(f[x])
        return f[x]
    for _ in range(m):
        x, y = map(int, input().split(' '))
        a[x] += 1
        a[y] += 1
        u, v = find(x), find(y)
        f[u] = v
    if n != m + 1:
        print('No')
    else:
        c1, c2 = 0, 0
        for i in range(n + 1):
            if a[i] == 1:
                c1 += 1
            elif a[i] == 2:
                c2 += 1
        ok = 1
        for i in range(1, n):
            # print(i, find(i))
            if find(i) != find(i + 1):
                ok = 0
                break
        if ok and c1 + c2 == n and c1 == 2 and c2 == n - 2:
            print('Yes')
        else:
            print('No');