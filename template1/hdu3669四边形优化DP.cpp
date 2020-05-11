#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#define mod 1000000007
#define N 50005
#define inf (1 << 30)
const double eps = 1e-12;
const double pi = acos(-1.0);
using namespace std;

struct Point
{
    __int64 x, y;
    bool operator < (const Point &p1) const
    {
        if (y != p1.y) return y > p1.y;
        return x < p1.x;
    }
};

__int64 n, m, e;
__int64 dp[N][2], s[N][2];
Point p[N];

int main()
{
    __int64 i, j, k, t, pre, cur, x, y, ans;
    while (scanf("%I64d%I64d", &n, &m) != EOF)
    {
        for (i = 1; i <= n; i++) scanf("%I64d%I64d", &p[i].x, &p[i].y);
        sort(p + 1, p + n + 1);
        e = 1, t = 1;
        for (i = 2; i <= n; i++)
        {
            if (p[i].x > p[t].x)
                p[++e] = p[i], t = i;
        }
        n = e;
        if (m > n) m = n;
        pre = 1, cur = 0;
        for (i = 1; i <= n; i++)
        {
            dp[i][cur] = p[1].y * p[i].x;
            s[i][cur] = 1;
        }
        ans = dp[n][cur];
        for (j = 2; j <= m; j++)
        {
            swap(pre, cur);
            s[n + 1][cur] = n - 1;
            for (i = n; i >= j; i--)
            {
                dp[i][cur] = -1;
                x = s[i][pre], y = s[i + 1][cur];
                x = max(j - 1, x), y = min(i - 1, y);
                for (k = x; k <= y; k++)
                {
                    t = p[k + 1].y * p[i].x;
                    if (dp[i][cur] == -1 || dp[i][cur] >= dp[k][pre] + t)
                    {
                         dp[i][cur] = dp[k][pre] + t;
                         s[i][cur] = k;
                    }
                }
            }
            if (dp[n][cur] > ans) break;
            else  ans = dp[n][cur];
        }
        printf("%I64d\n", ans);
    }
    system("pause");
    return 0;
}
