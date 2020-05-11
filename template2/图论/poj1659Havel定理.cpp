/*
Havel定理：我们把序列排成不增序，即d1>=d2>=...>=dn，则d可简单图化当且仅当
d‘=(d2-1, d3-1, ... d(d1+1)-1, d(d1+2), d(d1+3), ... dn)可简单图化。
实际上也就是，我们把d排序以后，找出度最大的点(设度为d1)，把它和度次大的d1个点之间连边，
然后这个点就可以不管了，一直继续这个过程，直到建出完整的图，或出现负度等明显不合理的情况。
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define pause cout << " press any key to continue...", cin >> ch
#define file_r(x) freopen(x, "r", stdin)
#define file_w(x) freopen(x, "w", stdout)
using namespace std;
int ch;

const int N = 105;

struct Node
{
    int p, v;
    bool operator < (const Node& arg0) const
    {
        return v > arg0.v;
    }
} a[N];

int T, n;
int g[N][N];

int main()
{
    int i, j, u, k;
    bool flag;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        for (i = 1; i <= n; i++)
            for (j = 1; j <= n; j++) g[i][j] = 0;
        for (i = 1; i <= n; i++)
        {
            a[i].p = i;
            scanf("%d", &a[i].v);
        }
        flag = 1;
        for (i = 1; i <= n && flag; i++)
        {
            sort(a + 1, a + n + 1);
            u = a[1].p, k = a[1].v;
            a[1].v = 0;
            if (k <= 0) break;
            for (j = 2; j <= k + 1; j++)
            {
                a[j].v--;
                if (a[j].v < 0)
                {
                    flag = 0;
                    break;
                }
                else g[a[1].p][a[j].p] = g[a[j].p][a[1].p] = 1;
            }
        }
        if (flag)
        {
            puts("YES");
            for (i = 1; i <= n; i++)
            {
                for (j = 1; j <= n; j++) printf("%d ", g[i][j]);
                printf("\n");
            }
        }
        else puts("NO");
        printf("\n");
    }
    return 0;
}
