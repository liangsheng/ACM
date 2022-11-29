import sys

int1 = lambda x: int(x) - 1

# input = lambda: sys.stdin.buffer.readline()
input = lambda: sys.stdin.readline().rstrip()
ii = lambda: int(input())
i1 = lambda: int1(input())
mi = lambda: map(int, input().split())
mi1 = lambda: map(int1, input().split())
li = lambda: list(mi())
li1 = lambda: list(mi1())
lli = lambda n: [li() for _ in range(n)]

INF = float("inf")
# mod = int(1e9 + 7)
mod = 998244353

h, w = mi()
s = [input() for i in range(h)]
t = [input() for i in range(h)]
ans = "Yes"
for i in range(h):
    if s[i].count("#") != t[i].count("#"):
        ans = "No"
print(ans)
