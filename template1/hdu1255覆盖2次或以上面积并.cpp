#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define inf (1 << 30)
#define N 1005
using namespace std;

struct Point
{
    double x, y;
};

struct Rect
{
    Point p1, p2;
};

struct Line
{
    double y1, y2;
    double x;
    int is_in;
};

bool operator < (const Line& k1, const Line& k2)
{
    if (k1.x < k2.x) return 1;
    if (k1.x == k2.x && k1.is_in == 1) return 1;
    return 0;
}

int T, n, cnty;
double id[N * 2];
Rect b[N];
Line yline[N * 2];

struct NODE
{
    int l, r;
    int v;
    double once, twice;
    double init() { v = once = twice = 0.0; }
    double get_len() { return id[r] - id[l]; }
    int get_mid() { return (l + r) >> 1; }
};

NODE a[N * 2 * 4];

int Build_Tree(int s, int t, int k)
{
    a[k].l = s, a[k].r = t;
    a[k].init();
    if (t - s > 1)
    {
        int mid = a[k].get_mid();
        Build_Tree(s, mid, k << 1);
        Build_Tree(mid, t, (k << 1) + 1);
    }
    return 1;
}

int get_len(int k)
{
    int l = k << 1, r = l + 1;
    if (a[k].v >= 2)
    {
        a[k].once = 0.0;
        a[k].twice = a[k].get_len();
    }
    else if (a[k].v == 1)
    {
        if (a[k].r - a[k].l == 1)
        {
            a[k].twice = 0;
            a[k].once = a[k].get_len();
        }
        else
        {
            a[k].twice = a[l].once + a[r].once + a[l].twice + a[r].twice;
            a[k].once = a[k].get_len() - a[k].twice;
        }
    }
    else if (a[k].v == 0)
    {
        if (a[k].r - a[k].l == 1)
            a[k].once = a[k].twice = 0;
        else
        {
            a[k].once = a[l].once + a[r].once;
            a[k].twice = a[l].twice + a[r].twice;
        }
    }
    return 1;
}

int insert(int s, int t, int k, int v)
{
    int mid = a[k].get_mid();
    if (a[k].l == s && a[k].r == t)
    {
        a[k].v += v;
        get_len(k);
        return 1;
    }
    if (t <= mid) insert(s, t, k << 1, v);
    else if (s >= mid) insert(s, t, (k << 1) + 1, v);
    else insert(s, mid, k << 1, v), insert(mid, t, (k << 1) + 1, v);
    get_len(k);
    return 1;
}

double solve()
{
    int i, j, y1, y2;
    double ans = 0.0;
    sort(yline, yline + 2 * n);
    for (i = 0; i < 2 * n -  1; i++)
    {
        y1 = lower_bound(id, id + cnty, yline[i].y1) - id;
        y2 = lower_bound(id, id + cnty, yline[i].y2) - id;
        insert(y1, y2, 1, yline[i].is_in);
        ans += a[1].twice * (yline[i + 1].x - yline[i].x);
    }
    return ans;
}

int main()
{
    int i, j, cas = 0;
    double ans, x1, x2, y1, y2;
    scanf("%d", &T);
    while (T--)
    {
        ans = 0;
        scanf("%d", &n);
        for (i = 0; i < n; i++)
        {
            scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
            yline[i * 2].y1 = yline[i * 2 + 1].y1 = y1;
            yline[i * 2].y2 = yline[i * 2 + 1].y2 = y2;
            yline[i * 2].x = x1;
            yline[i * 2 + 1].x = x2;
            yline[i * 2].is_in = 1;
            yline[i * 2 + 1].is_in = -1;
            id[i * 2] = y1;
            id[i * 2 + 1] = y2;
        }
        sort(id, id + 2 * n);
        cnty = unique(id, id + 2 * n) - id;
        Build_Tree(0, cnty, 1);
        ans = solve();
        printf("%.2lf\n", ans);
    }
    system("pause");
    return 0;
}
