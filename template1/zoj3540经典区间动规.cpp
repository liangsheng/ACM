#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#define inf (1 << 30)
#define mod 1000000007
#define N 210
const double eps = 1e-12;
const double pi = acos(-1.0);
using namespace std;

int n;
int tim[N], dis[N];
int dp[N][N][2], pre[N][N][2];

int gao(int l, int r, int p)
{
    //cout << l << " " << r << " " << p, system("pause");
    int i, tmp, add, &ret = dp[l][r][p];
    if (ret == -1)
    {
        if (l == r) ret = 0;
        else
        {
            ret = inf;
            tmp = gao(l + 1, r, 0) + dis[l + 1] - dis[l];
            add = p == 0 ? 0 : dis[r] - dis[l];
            if (tim[l] > tmp && ret > tmp + add)
            {
                ret = tmp + add;
                pre[l][r][p] = 0;
            }
            tmp = gao(l, r - 1, 1) + dis[r] - dis[r - 1];
            add = p == 1 ? 0 : dis[r] - dis[l];
            if (tim[r] > tmp && ret > tmp + add)
            {
                ret = tmp + add;
                pre[l][r][p] = 1;
            }
        }
    }
    return ret;
}

void dump(int l, int r, int p)
{
    if (l == r) printf("%d\n", l);
    else if (pre[l][r][p] == 0)
    {
        printf("%d ", l);
        dump(l + 1, r, 0);
    }
    else
    {
        printf("%d ", r);
        dump(l, r - 1, 1);
    }
}

int main()
{
    int i, j, k;
    while (scanf("%d", &n) != EOF)
    {
        for (i = 1; i <= n; i++) scanf("%d", &tim[i]);
        for (i = 1; i <= n; i++) scanf("%d", &dis[i]);
        memset(dp, -1, sizeof(dp));
        if (gao(1, n, 0) == inf)
        {
            memset(dp, -1, sizeof(dp));
            if (gao(1, n, 1) == inf) puts("Mission Impossible");
            else dump(1, n, 1);
        }
        else dump(1, n, 0);
    }
    system("pause");
    return 0;
}
