N = 1001
a = [[0 for _ in range(N)] for _ in range(N)]
a[0][0] = 1
maxi = 1
for i in range(1, N):
    a[i][0], a[i][i] = 1, 1
    for j in range(i):
        a[i][j] = a[i - 1][j] + a[i - 1][j - 1]
        maxi = max(maxi, len(str(a[i][j])))

f = [1] * N
for i in range(2, N):
    f[i] = f[i - 1] * i

print('maxi:', maxi)
n, m = map(int, input().split())
print(a[n][m] == f[n] // f[m] // f[n - m], a[n][m], len(str(a[n][m])))