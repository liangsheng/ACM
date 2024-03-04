T = int(input())
for _ in range(T):
    k, x, a = map(int, input().split(' '))
    if a <= x:
        print('NO')
        continue
    if x == 1:
        if k == 2 and a == 2:
            print('NO')
        else:
            print('YES')
        continue
    d, ok = 1, True
    for i in range(2, x + 2):
        c = (d + 1) // (k - 1) + (1 if (d + 1) % (k - 1) > 0 else 0)
        d += c
        if d > a:
            ok = False
            break
    print('YES' if ok else 'NO')

