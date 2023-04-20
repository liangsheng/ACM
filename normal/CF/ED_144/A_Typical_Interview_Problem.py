t = int(input())
a = 'FBFFBFFBFBFFBFFB'
for _ in range(t):
    n = int(input())
    s = input()
    if a.find(s) != -1:
        print('YES')
    else:
        print('NO')
