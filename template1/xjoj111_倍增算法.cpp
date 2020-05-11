#include <iostream>
#include <cstdio>
#include <cstring>
#define N 1000005
using namespace std;

int n, m;
int a[N], b[N];

int main()
{
    int k, p, m1;
    int i, j, t1, t2;
    scanf("%d%d", &n, &m);
    if (n == 0) return 0;
    for (i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        b[i] = a[i];
    }
    if (n == 1)
    {
        if (m == 0)
            printf("%d\n", a[1]);
        else
            printf("0\n");
        //system("pause");
        return 0;  
    }
    while (m != 0)
    {
        k = 0, p = m;
        while (p != 1)
            p /= 2, k++;
        m1 = 1 << k;
        m = m - m1;
        m1 = (m1 + 1) % n  ? (m1 + 1) % n : n;
        for (i = 1; i <= n; i++)
        {
            a[i] = a[i] ^ b[m1];
            m1++;
            if (m1 > n)
            m1 = 1;
        }
        for (i = 1; i <= n; i++)
            b[i] = a[i];
    }
    for (i = 1; i<= n; i++)
        printf("%d\n", a[i]);      
    system("pause");
    return 0;
}
