n, m = map(int, input().split(' '))
a = [(i, j) for i in range(1, n + 1) for j in range(i + 1, n + 1)]
h = set()
for _ in range(m):
    b = list(map(int, input().split(' ')))[1: ]
    t = set((i, j) for i in b for j in b)
    h = h | t
flag = 1
for it in a:
    if not (it in h):
        flag = 0
        break
if flag:
    print('Yes')
else:
    print('No')
