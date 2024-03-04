T = int(input())
for _ in range(T):
    a, b = map(int, input().split(' '))
    if a % 2 == 1 and b % 2 == 1:
        print('No')
    else:
        if a % 2 == 1 or b % 2 == 1:
            if a % 2 == 1:
                a, b = b, a
            if b * 2 == a:
                print('No')
            else:
                print('Yes')
        else:
            print('Yes')