#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define N 305
#define M 35
#define inf (1 << 30)
const double eps = 1e-12;
const double pi = acos(-1.0);
using namespace std;

int n, m;
int a[N];
int h1[N][N], h2[N][N];
int dp[N][N], s[N][N];

int cal()
{
    int i, j, k, t1, t2;
    for (i = 1; i <= n; i++) h1[i][i] = 0, h2[i][i] = i;
    for (k = 2; k <= n; k++)
        for (i = 1; i <= n - k + 1; i++)
        {
            j = i + k - 1;
            //cout << i << " " << j, system("pause");
            t1 = h1[i][j - 1] + a[j] - a[h2[i][j - 1]];
            t2 = h1[i + 1][j] + a[h2[i + 1][j]] - a[i];
            if (t1 < t2) h1[i][j] = t1, h2[i][j] = h2[i][j - 1];
            else h1[i][j] = t2, h2[i][j] = h2[i + 1][j];
        }
    //cout << h1[1][10] << " " << h2[1][10], system("pause");
    return 1;
}

int main()
{
    int i, j, t, w;
    while (scanf("%d%d", &n, &m) != EOF)
    {
        a[0] = 0;
        scanf("%d", &a[1]);
        for (i = 2; i <= n; i++)
        {
            scanf("%d", &a[i]);
            a[i] -= a[1];
        }
        a[1] = 0;
        cal();
        for (i = 1; i <= n; i++)
        {
            dp[i][1] = h1[1][i];
            dp[i][i] = 0;
            s[i][1] = 1;
        }
        for (j = 2; j <= m; j++)
        {
            s[n + 1][j] = n;
            for (i = n; i >= j; i--)
            {
                dp[i][j] = inf;
                //cout << s[10][1], system("pause");
                for (t = s[i][j - 1]; t <= s[i + 1][j]; t++)
                {
                    w = h1[t + 1][i];
                    //cout << i << " " << t << " " << j - 1 << " " << dp[t][j - 1], system("pause");
                    if (dp[i][j] >= dp[t][j - 1] + w)
                    {
                        dp[i][j] = dp[t][j - 1] + w;
                        s[i][j] = t;
                    }
                }
                //cout << i << " " << j << " " << dp[i][j] << " " << s[i][j], system("pause");
            }
        }
        printf("%d\n", dp[n][m]);
    }
    system("pause");
    return 0;
}
