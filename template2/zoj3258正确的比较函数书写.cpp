#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 105, M = 50005;

struct Node
{
    int a, b;
    double x;
    bool operator < (const Node& arg0) const
    {
        return x > arg0.x;
    }
} p[N];

bool cmp (const Node &arg0, const Node &arg1)
{
    return arg0.x > arg1.x;
}

int n, m;
double dp[M];

int main()
{
    int i, j, c, a, b, t, w;
    double ans, tmp;
    while (scanf("%d%d", &n, &m) != EOF)
    {
        c = 0;
        fill(dp, dp + m + 1, -1);
        dp[0] = 0;
        for (i = 1; i <= n; i++)
        {
            scanf("%d%d%d", &a, &b, &t);
            if (t == 1)
            {
                p[++c].a = a, p[c].b = b, p[c].x = b * 1.0 / a;
                continue;
            }
            for (j = m; j >= a; j--)
                if (dp[j - a] != -1) dp[j] = max(dp[j], dp[j - a] + b);
        }
        sort(p + 1, p + c + 1);
        ans = 0;
        for (j = 0; j <= m; j++)
        {
            if (dp[j] == -1) continue;
            w = m - j;
            for (i = 1; i <= c; i++)
            {
                if (w >= p[i].a) dp[j] += p[i].b, w -= p[i].a;
                else
                {
                    dp[j] += w * 1.0 * p[i].b / p[i].a;
                    break;
                }
            }
            ans = max(ans, dp[j]);
        }
        printf("%.2lf\n", ans);
    }
    return 0;
}
