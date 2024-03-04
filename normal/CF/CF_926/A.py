T = int(input())
for _ in range(T):
    n = int(input())
    a = list(map(int, input().split(' ')))
    a.sort()
    ans = 0
    for i in range(1, n):
        ans += a[i] - a[i - 1]
    print(ans)