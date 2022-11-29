#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define inf (1 << 30)
#define N 1005
using namespace std;

struct Point
{
    __int64 x, y, z;
};

struct Rect
{
    Point p1, p2;
};

struct Line
{
    __int64 y1, y2;
    __int64 x;
    __int64 is_in;
};

bool operator < (const Line& k1, const Line& k2)
{
    if (k1.x < k2.x) return 1;
    if (k1.x == k2.x && k1.is_in == 1) return 1;
    return 0;
}

__int64 T, n, cnty, cntz, e;
__int64 id[N * 2], idz[N * 2];
Rect b[N];
Line yline[N * 2];

struct NODE
{
    __int64 l, r;
    __int64 v;
    __int64 len;
    __int64 init() { v = len = 0; }
    __int64 get_len() { return id[r] - id[l]; }
    __int64 get_mid() { return (l + r) >> 1; }
};

NODE a[N * 2 * 4];

__int64 Build_Tree(__int64 s, __int64 t, __int64 k)
{
    a[k].l = s, a[k].r = t;
    a[k].init();
    if (t - s > 1)
    {
        __int64 mid = a[k].get_mid();
        Build_Tree(s, mid, k << 1);
        Build_Tree(mid, t, (k << 1) + 1);
    }
    return 1;
}

__int64 get_len(__int64 k)
{
    //if (k == 6) cout << "kk=" << a[k].v, system("pause");
    __int64 l = k << 1, r = l + 1;
    if (a[k].v >= 1) a[k].len = a[k].get_len();
    else
    {
        if (a[k].r - a[k].l == 1) a[k].len = 0;
        else a[k].len = a[l].len + a[r].len;
    }
    return 1;
}

__int64 insert(__int64 s, __int64 t, __int64 k, __int64 v)
{
    __int64 mid = a[k].get_mid();
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

__int64 solve()
{
    __int64 i, j, y1, y2, ans = 0;
    sort(yline, yline + e);
    yline[e].x = yline[e - 1].x;
    for (i = 0; i < e; i++)
    {
        y1 = lower_bound(id, id + cnty, yline[i].y1) - id;
        y2 = lower_bound(id, id + cnty, yline[i].y2) - id;
        insert(y1, y2, 1, yline[i].is_in);
        ans += a[1].len * (yline[i + 1].x - yline[i].x);
    }
    return ans;
}

__int64 m;
__int64 va[4];

int main()
{
    __int64 i, j, cas = 0, ans, zz;
    scanf("%I64d", &T);
    while (T--)
    {
        ans = 0;
        scanf("%I64dI64d", &n, &m);
        for (i = 1; i <= m; i++) scanf("%I64d", &va[i]);
        for (i = 0; i < n; i++)
        {
            scanf("%I64d%I64d%I64d%I64d%I64d", &b[i].p1.x, &b[i].p1.z, &b[i].p2.x, &b[i].p2.y, &zz);
            if (b[i].p2.x > b[i].p1.x) swap(b[i].p1.x, b[i].p1.x);
            if (b[i].p2.y > b[i].p1.y) swap(b[i].p1.y, b[i].p1.y);
            b[i].p1.z = 1, b[i].p2.z = b[i].p1.z + va[zz];
            idz[i * 2] = b[i].p1.z;
            idz[i * 2 + 1] = b[i].p2.z;
            id[i * 2] = b[i].p1.y;
            id[i * 2 + 1] = b[i].p2.y;
        }
        sort(idz, idz + 2 * n);
        cntz = unique(idz, idz + 2 * n) - idz;
        sort(id, id + 2 * n);
        cnty = unique(id, id + 2 * n) - id;
        Build_Tree(0, 2 * n, 1);
        for (j = 0; j < cntz - 1; j++)
        {
            e = 0;
            for (i = 0; i < n; i++)
            {
                if (!(b[i].p1.z <= idz[j] && b[i].p2.z >= idz[j + 1])) continue;
                yline[e].y1 = yline[e + 1].y1 = b[i].p1.y;
                yline[e].y2 = yline[e + 1].y2 = b[i].p2.y;
                yline[e].x = b[i].p1.x;
                yline[e + 1].x = b[i].p2.x;
                yline[e].is_in = 1;
                yline[e + 1].is_in = -1;
                e += 2;
            }
            //cout << idz[j] << " " << idz[j + 1] << " e=" << e, system("pause");
            ans += (idz[j + 1] - idz[j]) * solve();
        }
        printf("Case %I64d: %I64d\n", ++cas, ans);
    }
    system("pause");
    return 0;
}
