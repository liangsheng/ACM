T = int(input())
for _ in range(T):
    n = int(input())
    q = {}
    for i in range(4):
        for j in range(4 - i):
            q[(i, j, 3 - i - j)] = set()
    a = list()
    for i in range(n):
        s = input()
        W, I, N = 0, 0, 0
        for j in range(3):
            if s[j] == 'w':
                W += 1
            elif s[j] == 'i':
                I += 1
            else:
                N += 1
        q[(W, I, N)].add(i)
        a.append((W, I, N))
    ans, p = list(), 0
    while p < n:
        if a[p] == (1, 1, 1):
            p += 1
        else:
            x, y, z = a[p]
            print("ggg", p, a[p], q[a[p]])
            q[a[p]].remove(p)
            for i in range(4):
                for j in range(4 - i):
                    k = 3 - i - j
                    if x == 0 and i > 1 and y > 1 and j == 0:
                        id = q[(i, j, k)].pop
                        q[(x + 1, y - 1, z)].add(p)
                        q[(i - 1, j + 1, k)].add(id)
                        ans.append((p, 'w', id, 'i'))
                    elif x == 0 and i > 1 and z > 1 and k == 0:
                        id = q[(i, j, k)].pop
                        q[(x + 1, y, z - 1)].add(p)
                        q[(i - 1, j, k + 1)].add(id)
                        ans.append((p, 'w', id, 'n'))
                    elif y == 0 and j > 1 and x > 1 and i == 0:
                        id = q[(i, j, k)].pop
                        q[(x - 1, y + 1, z)].add(p)
                        q[(i + 1, j - 1, k)].add(id)
                        ans.append((p, 'i', id, 'w'))
                    elif y == 0 and j > 1 and z > 1 and k == 0:
                        id = q[(i, j, k)].pop
                        q[(x, y + 1, z - 1)].add(p)
                        q[(i, j - 1, k + 1)].add(id)
                        ans.append((p, 'i', id, 'n'))
                    elif z == 0 and k > 1 and x > 1 and i == 0:
                        id = q[(i, j, k)].pop
                        q[(x - 1, y, z + 1)].add(p)
                        q[(i + 1, j, k - 1)].add(id)
                        ans.append((p, 'n', id, 'w'))
                    elif z == 0 and k > 1 and y > 1 and j == 0:
                        id = q[(i, j, k)].pop
                        q[(x, y - 1, z + 1)].add(p)
                        q[(i, j + 1, k - 1)].add(id)
                        ans.append((p, 'n', id, 'i'))
    print(len(ans))
    for i in ans:
        print(i[0], i[1], i[2], i[3])
