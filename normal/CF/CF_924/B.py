T = int(input())
for _ in range(T):
    n = int(input())
    a = list(map(int, input().split(' ')))
    a.sort()
    b = [0] * n
    for i in range(1, n):
        b[i] = b[i - 1] + (1 if a[i] == a[i - 1] else 0)
    ans, j = 1, 0
    for i in range(n):
        while j + 1 < n and a[j + 1] - a[i] <= n - 1:
            j += 1
        # print('i= %d, j= %d, %d' % (i, j, b[j] - b[i]))
        ans = max(ans, j - i + 1 - (b[j] - b[i]))
    print(ans)