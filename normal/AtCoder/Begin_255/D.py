n, m = map(int, input().split(' '))
a = map(int, input().split(' '))
s = sum(a)
for _ in range(m):
    c = int(input())
    print(abs(n * c - s))