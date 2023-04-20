n = int(input())
a, b = 0, 0
for _ in range(n):
    s = input()
    if s == "For":
        a += 1
    else:
        b += 1
print("Yes" if a > b else "No")