#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 1005
using namespace std;

typedef __int64 LL;

LL n, m;
LL a[N];
LL dp[N][N], s[N][N], sum[N][N], w[N][N];

int main()
{
    LL i, j, x, y, k, c;
    while (scanf("%I64d%I64d", &n, &m) != EOF && n != 0 && m != 0)
    {
        m++;
        for (i = 1; i <= n; i++) scanf("%I64d", &a[i]);
        memset(sum, 0, sizeof(sum));
        for (i = 1; i <= n; i++)
        {
            sum[i][i] = a[i];
            w[i][i] = 0;
        }
        for (i = 2; i <= n; i++)
            for (j = 1; j <= n - i + 1; j++)
            {
                x = j, y = x + i - 1;
                sum[x][y] = sum[x][y - 1] + a[y];
                w[x][y] = w[x][y - 1] + a[y] * sum[x][y - 1];
            }
        for (i = 1; i <= n; i++)
        {
            dp[i][1] = w[1][i];
            s[i][1] = 1;
        }
        for (j = 2; j <= m; j++)
        {
            s[n + 1][j] = n - 1;
            for (i = n; i >= j; i--)
            {
                dp[i][j] = -1;
                x = s[i][j - 1], y = s[i + 1][j];
                for (k = x; k <= y; k++)
                {
                    c = w[k + 1][i];
                    if (dp[i][j] > dp[k][j - 1] + c || dp[i][j] == -1)
                    {
                        s[i][j] = k;
                        dp[i][j] = dp[k][j - 1] + c;
                    }
                }
            }
        }
        printf("%I64d\n", dp[n][m]);
    }
    system("pause");
    return 0;
}
