#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 1005
using namespace std;

typedef __int64 LL;

struct Point
{
    LL x, y;
    Point() {}
    Point(LL X, LL Y): x(X), y(Y) {}
    bool operator < (const Point &p1) const
    {
        if (y != p1.y) return y > p1.y;
        return x < p1.x;
    }

    Point operator - (const Point P) const
    {
        return Point (x - P.x, y - P.y);
    }

    Point operator + (const Point P) const
    {
        return Point (x + P.x, y + P.y);
    }
};

LL mul(Point a, Point b)
{
    return a.x * b.y - a.y * b.x;
}

struct Line
{
    int sp, i;
    Point point[N];
    Line() {}
    void init()
    {
        sp = -1;
        i = 0;
    }

    void insert(Point P)
    {
        while (sp > i && mul(P - point[sp], P - point[sp - 1]) > 0)    //维护凸包
            sp--;
        point[++sp] = P;
    }

    LL solve(LL k)
    {
        while(i < sp && point[i].y - point[i].x * k >= point[i + 1].y - point[i + 1].x * k)    //斜率优化
            i++;
        return point[i].y - point[i].x * k;
    }
} line;

LL n, m;
LL a[N];
LL dp[N][2], sum[N], w[N][N];

int main()
{
    LL i, j, x, y, pre, now;
    while (scanf("%I64d%I64d", &n, &m) != EOF && n != 0 && m != 0)
    {
        m++;
        for (i = 1; i <= n; i++) scanf("%I64d", &a[i]);
        sum[0] = 0;
        for (i = 1; i <= n; i++)
        {
            sum[i] = sum[i - 1] + a[i];
            w[i][i] = 0;
        }
        for (i = 2; i <= n; i++)
            for (j = 1; j <= n - i + 1; j++)
            {
                x = j, y = x + i - 1;
                w[x][y] = w[x][y - 1] + a[y] * (sum[y - 1] - sum[x - 1]);
            }
        pre = 0, now = 1;
        for (i = 1; i <= n; i++) dp[i][now] = w[1][i];
        for (j = 2; j <= m; j++)
        {
            swap(pre, now);
            line.init();
            for (i = j; i <= n; i++)
            {
                line.insert(Point(sum[i - 1], dp[i - 1][pre] - w[1][i - 1] + sum[i - 1] * sum[i - 1]));
                dp[i][now] = line.solve(sum[i]) + w[1][i];
            }
        }
        printf("%I64d\n", dp[n][now]);
    }
    system("pause");
    return 0;
}
