#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define N 10005
#define inf (1 << 30)
#define angle(x) double (x) / 180 * pi
#define sqr(x) ((double)(x) * (x))
#define file_r(x) freopen(x, "r", stdin)
#define file_w(x) freopen(x, "w", stdout)
const double eps = 1e-12;
const double pi = acos(-1.0);
using namespace std;

bool EQ(const double &x, const double &y)
{
    return fabs(x - y) < eps;
}

struct Point
{
    double x, y;
    Point() {}
    Point(double X, double Y): x(X), y(Y) {}
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

struct NODE
{
    int l, r;
    Point p1, p2;
    double agl;
    void get_lr(int L, int R)
    {
        l = L, r = R;
    }
    int get_mid()
    {
        return (l + r) >> 1;
    }
};

int n, m;
Point p[N];
NODE a[N << 2];

int Build_Tree(int s, int t, int k)
{
    a[k].get_lr(s, t);
    a[k].p1 = p[s], a[k].p2 = p[t], a[k].agl = 0;
    if (t - s > 1)
    {
        int mid = a[k].get_mid();
        Build_Tree(s, mid, k << 1);
        Build_Tree(mid, t, (k << 1) + 1);
    }
    return 1;
}

int rotate(int k, double agl)
{
    Point p0 = a[k].p2 - a[k].p1;
    a[k].p2.x = a[k].p1.x + p0.x * cos(agl) - p0.y * sin(agl);
    a[k].p2.y = a[k].p1.y + p0.x * sin(agl) + p0.y * cos(agl);
    return 1;
}

int push_up(int k)
{
    int l = k << 1, r = l + 1;
    a[k].p1 = a[l].p1, a[k].p2 = a[r].p2;
    return 1;
}

int push_down(int k)
{
    int l = k << 1, r = l + 1;
    a[l].p2 = a[l].p2 - a[l].p1 + a[k].p1;
    a[l].p1 = a[k].p1;
    rotate(l, a[k].agl);

    a[r].p2 = a[r].p2 - a[r].p1 + a[l].p2;
    a[r].p1 = a[l].p2;
    rotate(r, a[k].agl);

    a[l].agl += a[k].agl;
    a[r].agl += a[k].agl;
    a[k].agl = 0;
    return 1;
}

int update(int s, int t, double agl, int k)
{
    int l = k << 1, r = l + 1, mid = a[k].get_mid();
    if (s == a[k].l && t == a[k].r)
    {
        rotate(k, agl);
        a[k].agl += agl;
        return 1;
    }
    push_down(k);
    if (s < mid)
    {
        update(s, mid, agl, l);
        a[r].p2 = a[r].p2 - a[r].p1 + a[l].p2;
        a[r].p1 = a[l].p2;
        update(mid, t, agl, r);
    }
    else update(s, t, agl, r);
    push_up(k);
    return 1;
}

double get_agl(Point p0)
{
    double ans = acos(p0.x / sqrt(sqr(p0.x) + sqr(p0.y)));
    if (p0.x < 0 && p0.y < 0) return pi * 2.0 - ans;
    else if (p0.x > 0 && p0.y < 0) return pi * 2 - ans;
    return ans;
}

double find(int s, int t, int k)
{
    int l = k << 1, r = l + 1, mid = a[k].get_mid();
    if (s == a[k].l && t == a[k].r)
    {
        Point tmp = a[k].p2 - a[k].p1;
        return get_agl(tmp);
    }
    push_down(k);
    if (t <= mid) return find(s, t, l);
    else if (s >= mid) return find(s, t, r);
    push_up(k);
}

int main()
{
    //file_r("c.in");
    //file_w("c.out");
    int i, j, id, ag;
    double sum, x, y, agl;
    while (scanf("%d%d", &n, &m) != EOF)
    {
        sum = 0.0;
        p[0].x = p[0].y = 0.0;
        for (i = 1; i <= n; i++)
        {
            scanf("%lf", &x);
            sum += x;
            p[i].x = 0, p[i].y = sum;
        }
        Build_Tree(0, n, 1);
        for (i = 1; i <= m; i++)
        {
            scanf("%d%d", &id, &ag);
            x = y = -1;
            x = find(id - 1, id, 1);
            y = find(id, id + 1, 1);
            agl = x - pi + angle(ag) - y;
            while (agl < 0) agl += 2 * pi;
            while (agl > 2 * pi) agl -= 2 * pi;
            update(id, n, agl, 1);
            printf("%.2lf %.2lf\n", a[1].p2.x, a[1].p2.y);
        }
        printf("\n");
    }
    system("pause");
    return 0;
}
