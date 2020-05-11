#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define pause cout << " press any key to continue...", cin >> chh
#define file_r(x) freopen(x, "r", stdin)
#define file_w(x) freopen(x, "w", stdout)

using namespace std;
int chh;

typedef long long LL;

const int N = 55;

int T, n, m, k, s;
int a[N], b[N];
LL dp[2][N][N];

int main()
{
    int i, j, h, p, now ,pre;
    LL maxi;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d%d%d", &n, &m, &k, &s);
        for (i = 1; i <= m; i++) scanf("%d%d", &a[i], &b[i]);
        now = 0, pre = 1;
        for (j = 0; j <= k; j++)
            for (h = 1; h <= n; h++) dp[now][j][h] =  0;
        dp[now][0][s] = 1;
        for (i = 0; i < m; i++)
        {
            swap(now, pre);
            for (j = 0; j <= k; j++)
                for (h = 1; h <= n; h++) dp[now][j][h] = 0;
            for (j = 0; j <= k && j <= m; j++)
                for (h = 1; h <= n; h++)
                {
                    if (dp[pre][j][h] == 0) continue;
                    if (a[i + 1] == h) dp[now][j + 1][b[i + 1]] += dp[pre][j][h];
                    else if (b[i + 1] == h) dp[now][j + 1][a[i + 1]] += dp[pre][j][h];
                    else dp[now][j + 1][h] += dp[pre][j][h];
                    dp[now][j][h] += dp[pre][j][h];
                }
        }
        maxi = 0, p = -1;
        for (i = 1; i <= n; i++)
            if (dp[now][k][i] > maxi) maxi = dp[now][k][i], p = i;
        printf("%d\n", p == -1 ? s : p);
    }
    return 0;
}
