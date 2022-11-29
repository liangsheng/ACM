#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define inf (1 << 30)
#define N (8005 * 2)
using namespace std;

struct Line
{
    int y1, y2;
    int x;
    int is_in;
    bool operator < (const Line &oth) const { return x < oth.x; }
};

struct NODE
{
    int l, r;
    int v;        //-1: 未被赋值 -2: 混色
    void init() { v = -1; }
    int get_len() { return r - l + 1; }
    int get_mid() { return (l + r) >> 1; }
};

int T, n;
int id[N * 2];
Line yline[N];
NODE a[N << 2];
vector<int> q[N];
vector< int >::iterator it;

int Build_Tree(int s, int t, int k)
{
    a[k].l = s, a[k].r = t;
    a[k].init();
    if (a[k].r - a[k].l > 0)
    {
        int mid = a[k].get_mid();
        Build_Tree(s, mid, k << 1);
        Build_Tree(mid + 1, t, (k << 1) + 1);
    }
    return 1;
}

int down(int k)
{
    int l = k << 1, r = l + 1;
    if (a[k].v >= 0) a[l].v = a[r].v = a[k].v;
    return 1;
}

int get_v(int k)
{
    int l = k << 1, r = l + 1;
    if (a[l].v == a[r].v && a[l].v != -2) a[k].v = a[l].v;
    else a[k].v = -2;
    return 1;
}

int insert(int s, int t, int v, int k)
{
    int l = k << 1, r = l + 1, mid = a[k].get_mid();
    if (s == a[k].l && t == a[k].r && a[k].v != -2)
    {
        if (a[k].v != -1) q[a[k].v].push_back(v);
        a[k].v = v;
        return 1;
    }
    down(k);
    if (t <= mid) insert(s, t, v, l);
    else if (s > mid) insert(s, t, v, r);
    else insert(s, mid, v, l), insert(mid + 1, t, v, r);
    get_v(k);
    return 1;
}

int solve(int mini, int maxi)
{
    int i, j, k, p, ans = 0;
    sort(yline, yline + n);
    Build_Tree(mini, maxi, 1);
    for (i = 0; i < n; i++) q[i].clear();
    for (i = 0; i < n; i++) insert(yline[i].y1, yline[i].y2, i, 1);
    for (i = 0; i < n; i++)
    {
        sort(q[i].begin(), q[i].end());
        it = unique(q[i].begin(), q[i].end());
        q[i].resize(it - q[i].begin());
    }
    for (i = 0; i < n; i++)
    {
        int len = q[i].size();
        for (k = 0; k < len; k++)
        {
            for (j = k + 1; j < len; j++)
            {
                int v1 = q[i][k], v2 = q[i][j];
                if (binary_search(q[v1].begin(), q[v1].end(), v2))
                    ans++;
            }
        }
    }
    printf("%d\n", ans);
    return 1;
}

int main()
{
    int i, j, y1, y2, x, mini, maxi;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        mini = inf, maxi = -1;
        for (i = 0; i < n; i++)
        {
            scanf("%d%d%d", &y1, &y2, &x);
            y1 *= 2, y2 *= 2;
            mini = min(mini, y1), maxi = max(maxi, y2);
            yline[i].y1 = y1;
            yline[i].y2 = y2;
            yline[i].x = x;
        }
        solve(mini, maxi);
    }
    system("pause");
    return 0;
}
