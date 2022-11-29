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
        dp[0][m][0] = 1;
        for (i = 1; i <= n; i++)
        {
            for (j = 0; j < (1 << m); j++) dp[i][0][j << 1] = dp[i - 1][m][j];
            for (j = 1; j <= m; j++)
            {
                for (k = 0; k < (1 << m << 1); k++)
                {
                    p = 1 << j;
                    q = p >> 1;
                    x = p & k;
                    y = q & k;
                    if (g[i][j])
                    {
                        dp[i][j][k] = dp[i][j - 1][k ^ p ^ q];
                        if (x != y) dp[i][j][k] += dp[i][j - 1][k];
                    }
                    else
                    {
                        if (x == 0 && y == 0) dp[i][j][k] = dp[i][j - 1][k];
                        else dp[i][j][k] = 0;
                    }
                }
            }
        }
        printf("Case %d: There are %I64d ways to eat the trees.\n", ++cas, dp[n][m][0]);
    }
    system("pause");
    return 0;
}
