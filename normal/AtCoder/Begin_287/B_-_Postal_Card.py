n, m = map(int, input().split(' '))
a = []
for i in range(n):
    s = input()
    a.append(s[3: ])
b = set()
for i in range(m):
    s = input()
    b.add(s)
cnt = 0
for x in a:
    if x in b:
        cnt += 1
print(cnt)