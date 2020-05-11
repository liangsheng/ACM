#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#define mod 1000000007
#define N 50010
#define inf (1 << 30)
const double eps = 1e-12;
const double pi = acos(-1.0);
using namespace std;

struct Point
{
    __int64 x, y;
    Point() {}
    Point(__int64 X, __int64 Y): x(X), y(Y) {}
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

__int64 mul(Point a, Point b)
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

    bool insert(Point P)
    {
        while (sp > i && mul(P - point[sp], P - point[sp - 1]) < 0)    //维护凸包
            sp--;
        point[++sp] = P;
        return true;
    }

    __int64 solve(__int64 k)
    {
        while(i < sp && point[i].y + point[i].x * k >= point[i + 1].y + point[i + 1].x * k)    //斜率优化
            i++;
        return point[i].y + point[i].x * k;
    }
} line;

__int64 n, m, e;
__int64 dp[N][2];
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
        for (i = 1; i <= n; i++) dp[i][cur] = p[1].y * p[i].x;
        ans = dp[n][cur];
        for (j = 2; j <= m; j++)
        {
            swap(pre, cur);
            line.init();        //左链初始化
            //line.insert(Point(p[j].y, dp[j - 1][pre]));    //预先插入决策点(h[1], dp[x][0])。
            for (i = j; i <= n; i++)
            {
                //cout << "j=" << j << " " << "i=" << i, system("pause");
                line.insert(Point(p[i].y, dp[i - 1][pre]));
                dp[i][cur] = line.solve(p[i].x);    //计算斜率优化出来的dp值
                //line.insert(Point(p[i + 1].y, dp[i][pre]));    //将之前计算的dp值作为可能的决策点插入
            }
            if (dp[n][cur] >= ans) break;
            else  ans = dp[n][cur];
        }
        printf("%I64d\n", ans);
    }
    system("pause");
    return 0;
}
