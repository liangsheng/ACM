import functools

T = int(input())
for _ in range(T):
    n = int(input())
    a = list(map(int, input().strip().split(' ')))
    print(functools.reduce(lambda x, y: x | y, a))
