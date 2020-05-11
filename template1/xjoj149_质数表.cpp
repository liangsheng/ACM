#include <iostream>
#include <cstdio>
#define N 100000
using namespace std;

int test, n;
int iseve[N + 1], a[N + 1];

int main()
{
    int i, t, ans, temp, h, p, s;
    for (i = 2; i <= N; i++) iseve[i] = 1;
    for (i = 2; i <= N / 2; i++) iseve[i * 2] = 0;
    p = 2;
    while (p * p <= N)
    {
        p++;
        while (iseve[p] == 0)
            p++;
        t = p * p;
        s = 2 * p;
        while (t <= N)
        {
            iseve[t] = 0;
            t += s;  
        }  
    }
    t = 0;
    for (i = 2; i <= N; i++)
        if (iseve[i]) a[++t] = i;
    scanf("%d", &test);
    while (test--)
    {
        scanf("%d", &n);
        if (n == 1)
        {
            printf("1\n");
            continue;  
        } 
        temp = 0;
        h = 1;
        t = 1;
        ans = 1;
        while (n != 1)
        {
            if (n % a[t] == 0)
            {
                n /= a[t];
                h *= a[t];
                temp += h;                 
            }    
            else 
            {
                t++;
                ans *= temp + 1; 
                temp = 0;
                h = 1;
            }
        } 
        ans *= temp + 1;
        printf("%d\n", ans);
    }
    system("pause");
    return 0;
}
