#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define N 2005
#define M 5005
#define inf (1 << 30)
const double eps = 1e-12;
const double pi = acos(-1.0);
using namespace std;

int n;
int a[N];
int dp[N][N], s[N][N], w[N][N];

int main()
{
    int i, j, k, t, ans;
    while (scanf("%d", &n) != EOF)
    {
        for (i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
            w[i][i] = w[i + n][i + n] = a[i + n] = a[i];
            dp[i][i] = dp[i + n][i + n] = 0;
        }
        for (i = 1; i <= 2 * n; i++)
        {
            s[i][i] = i;
            for (j = i + 1; j <= i + n && j <= 2 * n; j++)
                w[i][j] = w[i][j - 1] + a[j];
        }
        for (k = 2; k <= n; k++)
        {
            for (i = 1; i <= 2 * n - k + 1; i++)
            {
                j = i + k - 1;
                dp[i][j] = inf;
                for (t = s[i][j - 1]; t <= s[i + 1][j]; t++)
                    if (dp[i][j] > dp[i][t] + dp[t + 1][j] + w[i][j])
                    {
                        dp[i][j] = dp[i][t] + dp[t + 1][j] + w[i][j];
                        s[i][j] = t;
                    }
            }
        }
        ans = inf;
        for (i = 1; i <= n; i++) ans = min(ans, dp[i][i + n - 1]);
        printf("%d\n", ans);
    }
    system("pause");
    return 0;
}
