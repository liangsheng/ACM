#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
#define eps 1e-8
#define PI 3.14159265358979
#define inf 0x3fffffff
#define L 100005

int able[20];
__int64 n, m, ans, e;
__int64 a[25], b[25];

__int64 gcd(__int64 x, __int64 y)
{
    return x % y ? gcd(y, x % y) : y;
}

__int64 lcm(__int64 x, __int64 y)
{
    return x * y / gcd(x, y);
}

__int64 DFS(__int64 pre, __int64 now, __int64 sum)
{
    __int64 i, j, temp;
    for (i = now; i < e; i++)
    {
        temp = lcm(pre, b[i]);
        if ((sum + 1) % 2 == 1) ans += n / temp;
        else ans -= n / temp;
        DFS(temp, i + 1, sum + 1);
    }
    return 1;
}

int main()
{
    __int64 i, j, f, temp;
    while (scanf("%I64d%I64d", &n, &f) != EOF)
    {
        m = 0;
        for (i = 0; i < f; i++)
        {
            scanf("%I64d", &j);
            if (j) a[m++] = j;
        }
        if (m == 0)
        {
            printf("0\n");
            continue;
        }
        sort(a, a + m);
        memset(able, 0, sizeof(able));
        for (i = 0; i < m; i++)
            for (j = i + 1; j < m; j++)
                if (a[j] % a[i] == 0)
                {
                    able[j] = 1;
                    break;
                }
        e = 0;
        for (i = 0; i < m; i++)
            if (! able[i]) b[e++] = a[i];
        ans = 0;
        n--;
        DFS(1, 0, 0);
        printf("%I64d\n", ans);
    }
    system("pause");
    return 0;
}
