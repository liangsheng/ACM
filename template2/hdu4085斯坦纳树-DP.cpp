#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <algorithm>
#include <fstream>
#define inf 99999999
#define N 50
#define M (1 << 10)
#define file_r(x) freopen(x, "r", stdin)
#define file_w(x) freopen(x, "w", stdout)
using namespace std;

int T, n, m, p, NN, p1, p2;
int e[10], v[N];
int d[N][N], dp[M][N];
map<int, int> q;
map<int, int> :: iterator iter1, iter2;

int init()
{
    int i, j, cnt = 0;
    NN = (1 << (2 * p));
    for (i = 0; i < p; i++) e[cnt++] = i;
    for (i = n - p; i < n; i++) e[cnt++] = i;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            d[i][j] = (i == j ? 0 : inf);
    p1 = (1 << p) - 1;
    p2 = p1 << p;
    q.clear();
    return 1;
}

int cal(int x)
{
    int cnt = 0;
    while (x)
    {
        if (x % 2 == 1) cnt++;
        x >>= 1;
    }
    return cnt;
}

int check_min(int &x, int y)
{
    x = min(x, y);
    return 0;
}

int main()
{
    int i, j, k, x, y, w, sub, b, c, mini, ans;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d%d", &n, &m, &p);
        init();
        for (i = 0; i < m; i++)
        {
            scanf("%d%d%d", &x, &y, &w);
            x--, y--;
            d[x][y] = d[y][x] = min(d[x][y], w);
        }
        for (k = 0; k < n; k++)
            for (i = 0; i < n; i++)
                for (j = 0; j < n; j++)
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
        for (i = 0; i < 2 * p; i++)
            for (j = 0; j < n; j++)
                dp[1 << i][j] = d[j][e[i]];
        for (i = 1; i < NN; i++)
        {
            if (!(i & (i - 1))) continue;   //只有一个1已经算过
            for (k = 0; k < n; k++)
            {
                dp[i][k] = inf;
                v[k] = 0;
                for (sub = i; sub; sub = (sub - 1) & i)
                    dp[i][k] = min(dp[i][k], dp[sub][k] + dp[i - sub][k]);
            }
            for (j = 0; j < n; j++)
            {
                b = inf;
                for (k = 0; k < n; k++)
                {
                    if (dp[i][k] <= b && v[k] == 0)
                        b = dp[i][k], c = k;
                }
                v[c] = 1;
                for (k = 0; k < n; k++)
                    dp[i][c] = min(dp[i][c], dp[i][k] + d[k][c]);
            }
            if (cal(i & p1) == cal(i & p2))
            {
                mini = inf;
                for (j = 0; j < n; j++)
                    mini = min(mini, dp[i][j]);
                q[i] = mini;
            }
        }
        for (iter1 = q.begin(); iter1 != q.end(); iter1++)
            for (iter2 = iter1, iter2++; iter2 != q.end(); iter2++)
                if ((iter1 -> first & iter2 -> first) == 0)
                    check_min(q[iter1 -> first | iter2 -> first], iter1 -> second + iter2 -> second);
        ans = q[NN - 1];
        if (ans == inf) printf("No solution\n");
        else printf("%d\n", ans);
    }
    system("pause");
    return 0;
}
