#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#define inf (1 << 30)
const double eps=1e-12;
const double pi=acos(-1.0);
using namespace std;

struct NODE
{
    int u, l, c;
};

bool operator < (const NODE& p1, const NODE& p2)
{
    if (p1.u != p2.u) return p1.u < p2.u;
    return p1.c > p2.c;
}

int T, n, m, qq;
int maxi, flag[500005];
long long tt[500005];
NODE  q[500005];

int solve()
{
    int i, j, u;
    sort(q + 1, q + m + 1);
    maxi = -1;
    flag[q[1].u] = 1;
    for (i = 2; i <= m; i++)
        if (q[i].u != q[i - 1].u) flag[q[i].u] = i;
    for (i = 1; i <= m; i++)
    {
        tt[i - flag[q[i].u] + 1] += q[i].l;
        maxi = max(maxi, i - flag[q[i].u] + 1);
    }
    for (i = 2; i <= maxi; i++) tt[i] += tt[i - 1];
    return 1;
}

int main()
{
    int i, j, k, size, e;
    long long u, c, l, ans;
    NODE temp;
    scanf("%d", &T);
    for (e = 1; e <= T; e++)
    {
        scanf("%d%d%d", &n, &m, &qq);
        for (i = 1; i <= m; i++)
            scanf("%d%d%d", &q[i].u, &q[i].c, &q[i].l);
        solve();
        printf("Case #%d:\n", e);
        for (i = 1; i <= qq; i++)
        {
            scanf("%d", &k);
            if (k >= maxi) k = maxi;
            printf("%I64d\n", tt[k]);
        }
        for (i = 1; i <= maxi; i++) tt[i] = 0;
    }
    system("pause");
    return 0;
}
