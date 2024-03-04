T = int(input())
for _ in range(T):
    n, k = map(int, input().split(' '))
    if k <= 4 * n - 4:
        print(k // 2 + k % 2)
    else:
        k -= 4 * n - 4
        print(2 * n - 2 + k)