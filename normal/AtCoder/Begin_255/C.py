x, a, d, n = map(int, input().split(' '))
l, r = a, a + (n - 1) * d
if d < 0:
    l, r, d = r, l, -d

def gao():
    if x <= l: return l - x
    if x >= r: return x - r
    t = (x - l) % d
    if t == 0: return 0
    ans = min(t, d - t)
    return ans
print(gao())
