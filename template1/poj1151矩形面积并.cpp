# include <iostream>
# include <cstdio>
# include <algorithm>
# include <cmath>
# include <cstring>
# define N 201
using namespace std;

struct NODE
{
    int l, r;   //左右边界序号
    int v;      //记录覆盖情况
    double len;  //实际长度
};

struct Line
{
    double y1, y2;
    double x;
    int is_in;
};

int n, cnt;
double ans;
double id[N];
NODE node[N * 3];
Line yline[N];

bool operator < (const Line& k1, const Line& k2)
{
    if (k1.x < k2.x) return 1;
    if (k1.x == k2.x && k1.is_in == 1) return 1;
    return 0;
}

int Build_Tree(int s, int t, int k)
{
    node[k].l = s, node[k].r = t, node[k].v = 0;
    node[k].len = 0;
    if (t - s > 1)
    {
        int mid = (s + t) >> 1;
        Build_Tree(s, mid, k << 1);
        Build_Tree(mid, t, (k << 1) + 1);
    }
    return 1;
}

int get_len(int k)
{
    if (node[k].v) node[k].len = id[node[k].r] - id[node[k].l];
    else
    {
        if (node[k].r - node[k].l > 1)
            node[k].len = node[k << 1].len + node[(k << 1) + 1].len;
        else node[k].len = 0;
    }
    return 1;
}

int insert(int s, int t, int k, int v)
{
    int mid;
    if (node[k].l == s && node[k].r == t)
    {
        node[k].v += v;
        get_len(k);
        return 1;
    }
    mid = (node[k].l + node[k].r) >> 1;
    if (t <= mid) insert(s, t, k << 1, v);
    else if (s >= mid) insert(s, t, (k << 1) + 1, v);
    else insert(s, mid, k << 1, v), insert(mid, t, (k << 1) + 1, v);
    get_len(k);
    return 1;
}

int solve()
{
    int i, j, y1, y2;
    double last;
    ans = 0.0;
    Build_Tree(0, cnt, 1);
    sort(yline, yline + 2 * n);
    last = yline[0].x;
    for (i = 0; i < 2 * n - 1; i++)
    {
        y1 = lower_bound(id, id + cnt, yline[i].y1) - id;
        y2 = lower_bound(id, id + cnt, yline[i].y2) - id;
        insert(y1, y2, 1, yline[i].is_in);
        ans += node[1].len * (yline[i + 1].x - yline[i].x);
        //cout << "y1=" << y1 << " " << y2 << " " << node[1].len << " " << ans, system("pause");
    }
    return 1;
}

int main()
{
    int i, j, cas = 0;
    double x1, x2, y1, y2;
    while (scanf("%d", &n) != EOF && n != 0)
    {
        for (i = 0; i < n; i++)
        {
            scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
            yline[i * 2].y1 = yline[i * 2 + 1].y1 = y1;
            yline[i * 2].y2 = yline[i * 2 + 1].y2 = y2;
            yline[i * 2].x = x1;
            yline[i * 2 + 1].x = x2;
            yline[i * 2].is_in = 1;
            yline[i* 2 + 1].is_in = -1;
            id[i * 2] = y1;
            id[i * 2 + 1]=y2;
        }
        sort(id, id + 2 * n);
        cnt = unique(id, id + 2 * n) - id;
        solve();
        printf("Test case #%d\nTotal explored area: %.2f\n\n", ++cas, ans);
    }
    system("pause");
    return 1;
}
