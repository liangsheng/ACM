t = int(input())
for _ in range(t):
    n = int(input())
    a = [i for i in range(1, n + 1)]
    for i in range(1, n - 1):
        a[i] = i + 2
    a[n - 1] = 2
    print(' '.join(list(map(str, a))))