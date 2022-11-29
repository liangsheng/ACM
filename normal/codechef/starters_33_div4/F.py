T = int(input())
for _ in range(T):
    n = int(input())
    a = map(lambda x: int(x) % 2, input().strip().split(' '))
    b = sum(a)
    if b == n:
        print(0)
    elif b % 2 == 0:
        print(b // 2)
    else:
        print(n - 1)