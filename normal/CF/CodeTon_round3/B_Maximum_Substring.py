T = int(input())
res = list()
for _ in range(T):
    n = int(input())
    s = input()
    x, y = s.count('0'), s.count('1')
    ans = x * y
    i = 0
    while i < len(s):
        j = i
        while i + 1 < len(s) and s[i + 1] == s[j]:
            i += 1
        ans = max(ans, (i - j + 1) * (i - j + 1))
        i += 1
    res.append(ans)
print('\n'.join(list(map(str, res))))