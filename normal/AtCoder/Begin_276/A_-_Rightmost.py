s = input()[::-1]
i = s.find('a')
if i == -1:
    print(-1)
else:
    print(len(s) - i)