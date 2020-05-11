#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define N 2005
#define inf (1 << 30)
const double eps = 1e-12;
const double pi = acos(-1.0);
using namespace std;

struct NODE
{
    int l, r, lz;
    int v;
};

struct Line
{
    int y1, y2;
    int x;
    int is_in;
};

int n, r, cnt, ans;
int id[N];
NODE node[N * 4];
Line yline[N];

bool operator < (const Line& k1, const Line& k2)
{
    if (k1.x < k2.x) return 1;
    if (k1.x == k2.x && k1.is_in == 1) return 1;
    return 0;
}

int Build_Tree(int s, int t, int k)
{
    int mid = (s + t) >> 1;
    node[k].l = s, node[k].r = t, node[k].v = 0, node[k].lz = 0;
    if (s == t) return 1;
    Build_Tree(s, mid, k << 1);
    Build_Tree(mid + 1, t, (k << 1) + 1);
    return 1;
}

int down(int k)
{
    node[k << 1].v += node[k].lz;
    node[(k << 1) + 1].v += node[k].lz;
    node[k << 1].lz += node[k].lz;
    node[(k << 1) + 1].lz += node[k].lz;
    node[k].lz = 0;
    return 1;
}

int insert(int s, int t, int k, int v)
{
    int mid;
    if (node[k].l == s && node[k].r == t)
    {
        node[k].v += v, node[k].lz += v;
        return 1;
    }
    if (node[k].lz != 0) down(k);
    mid = (node[k].l + node[k].r) >> 1;
    if (t <= mid) insert(s, t, k << 1, v);
    else if (s > mid) insert(s, t, (k << 1) + 1, v);
    else insert(s, mid, k << 1, v), insert(mid + 1, t, (k << 1) + 1, v);
    node[k].v = max(node[k << 1].v, node[(k << 1) + 1].v);
    return 1;
}

int solve()
{
    int i, j, y1, y2;
    ans = 0;
    Build_Tree(0, cnt, 1);
    sort(yline, yline + 2 * n);
    for (i = 0; i < 2 * n - 1; i++)
    {
        y1 = lower_bound(id, id + cnt, yline[i].y1) - id;
        y2 = lower_bound(id, id + cnt, yline[i].y2) - id;
        insert(y1, y2, 1, yline[i].is_in);
        ans = max(ans, node[1].v);
    }
    return 1;
}

int main()
{
    int i, j, x1, y1, x2, y2;
    while (scanf("%d%d", &n, &r) != EOF)
    {
        for (i = 0; i < n; i++)
        {
            scanf("%d%d", &x1, &y1);
            x2 = x1 + r, y2 = y1 + r;
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
        cnt = unique(id, id + 2 * n) - id;
        solve();
        printf("%d\n", ans);
    }
    system("pause");
    return 0;
}
