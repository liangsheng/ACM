h, w = map(int, input().split(' '))
a, b = [''] * w, [''] * w
for _ in range(h):
    s = input()
    for i in range(len(s)):
        a[i] += s[i]
for _ in range(h):
    s = input()
    for i in range(len(s)):
        b[i] += s[i]

a = set(a)
b = set(b)
if a == b:
    print('Yes');
else:
    print('No')