#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 12
using namespace std;

typedef __int64 LL;

int n, m;
int g[N][N];
LL dp[N][N][1 << N];

int main()
{
    int i, j, k, T, cas = 0, p, q;
    bool x, y;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d", &n, &m);
        for (i = 1; i <= n; i++)
            for (j = 1; j <= m; j++) scanf("%d", &g[i][j]);
        memset(dp, 0, sizeof(dp));
        dp[1][0][0] = 1;
        for (i = 1; i <= n; i++)
        {
            for (j = 0; j < m; j++)
                for (k = 0; k < (1 << m << 1); k++)
                {
                    if (dp[i][j][k] == 0) continue;
                    q = 1 << j;
                    p = q << 1;
                    x = k & p;
                    y = k & q;
                    if (g[i][j + 1])
                    {
                        dp[i][j + 1][k ^ p ^ q] += dp[i][j][k];
                        if (x != y) dp[i][j + 1][k] += dp[i][j][k];
                    }
                    else
                    {
                        if (x == 0 && y == 0) dp[i][j + 1][k] = dp[i][j][k];
                        else dp[i][j + 1][k] = 0;
                    }
                }
            if (i == n) continue;
            for (j = 0; j < (1 << m); j++) dp[i + 1][0][j << 1] = dp[i][m][j];
        }
        printf("Case %d: There are %I64d ways to eat the trees.\n", ++cas, dp[n][m][0]);
    }
    system("pause");
    return 0;
}
