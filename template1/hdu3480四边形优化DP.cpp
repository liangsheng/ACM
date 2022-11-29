#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define N 10005
#define M 5005
#define inf (1 << 30)
const double eps = 1e-12;
const double pi = acos(-1.0);
using namespace std;

int T, n, m;
int a[N], s[N][N], dp[N][N];

int cal(int x, int y)
{
    return (a[x] - a[y]) * (a[x] - a[y]);
}

int solve()
{
    int i, j, k, x, y, c;
    for (i = 1; i <= n; i++)
    {
        dp[i][1] = cal(1, i);
        dp[1][i] = 0;
        s[i][1] = 1;
    }
    for (j = 2; j <= m; j++)
    {
        s[n + 1][j] = n - 1;
        for (i = n; i >= j; i--)
        {
            dp[i][j] = inf;
            x = s[i][j - 1], y = s[i + 1][j];
            for (k = x; k <= y; k++)
            {
                c = cal(k + 1, i);
                if (dp[i][j] > dp[k][j - 1] + c)
                {
                    s[i][j] = k;
                    dp[i][j] = dp[k][j - 1] + c;
                }
            }
        }
    }
    return 1;
}

int main()
{
    int i, j, h;
    scanf("%d", &T);
    for (h = 1; h <= T; h++)
    {
        scanf("%d%d", &n, &m);
        for (i = 1; i <= n; i++) scanf("%d", &a[i]);
        sort(a + 1, a + n + 1);
        solve();
        printf("Case %d: %d\n", h, dp[n][m]);
    }
    system("pause");
    return 0;
}
