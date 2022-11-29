def solve(a):
    s = sum(a)
    if s == 0: return 0
    if s <= 15: return 1
    a.sort()
    if a[0] + a[1] < a[2]:
        t = (a[2] - a[0] - a[1] + 14) / 15
        a[2] -= min(a[2], 15 * t)
        return t + solve(a)
    return (s + 19) / 20

print 6 * solve(map(int, raw_input().split()))
