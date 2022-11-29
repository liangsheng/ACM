# include <iostream>
# include <cstdio>
# include <algorithm>
# include <cmath>
# include <cstring>
# define N (50005 * 2)
using namespace std;

struct NODE
{
    __int64 l, r;   //左右边界序号
    __int64 v;      //记录覆盖情况
    __int64 len;  //实际长度
};

struct Line
{
    __int64 y1, y2;
    __int64 x;
    __int64 is_in;
};

struct Rect
{
    __int64 x1, x2, y1, y2;
};

__int64 w, h, n, m, e, cnt, ans;
__int64 id[N];
NODE node[N * 4];
Line yline[N];
Rect rect[N];

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

__int64 solve()
{
    __int64 i, j, y1, y2, ans = 0;
    sort(id, id + e);
    cnt = unique(id, id + e) - id;
    //cout << cnt, system("pause");
    Build_Tree(0, cnt, 1);
    sort(yline, yline + e);
    for (i = 0; i < e - 1; i++)
    {
        y1 = lower_bound(id, id + cnt, yline[i].y1) - id;
        y2 = lower_bound(id, id + cnt, yline[i].y2) - id;
        insert(y1, y2, 1, yline[i].is_in);
        ans += node[1].len * (yline[i + 1].x - yline[i].x);
    }
    return ans;
}

__int64 add_line(Rect p)
{
    yline[e].y1 = yline[e + 1].y1 = p.y1;
    yline[e].y2 = yline[e + 1].y2 = p.y2;
    yline[e].x = p.x1;
    yline[e + 1].x = min(p.x2 + m - 1, 1 + w);
    yline[e].is_in = 1;
    yline[e + 1].is_in = -1;
    id[e] = p.y1;
    id[e + 1] = p.y2;
    e += 2;
    return 1;
}

__int64 add_line2(Rect p)
{
    __int64 y2 = min(h + 1, p.y2 + m - 1);
    yline[e].y1 = yline[e + 1].y1 = p.y1;
    yline[e].y2 = yline[e + 1].y2 = y2;
    yline[e].x = p.x1;
    yline[e + 1].x = p.x2;
    yline[e].is_in = 1;
    yline[e + 1].is_in = -1;
    id[e] = p.y1;
    id[e + 1] = y2;
    e += 2;
    return 1;
}

int main()
{
    __int64 i, j, cas = 0;
    __int64 x1, x2, y1, y2;
    Rect tmp;
    while (scanf("%I64d%I64d%I64d%I64d", &w, &h, &n, &m) != EOF)
    {
        for (i = 0; i < n; i++)
        {
            scanf("%I64d%I64d%I64d%I64d", &rect[i].x1, &rect[i].y1, &rect[i].x2, &rect[i].y2);
            rect[i].x2++, rect[i].y2++;
        }
        e = ans = 0;
        for (i = 0; i < n; i++) add_line(rect[i]);
        if (m != 1)
        {
            tmp.x1 = tmp.y1 = 1;
            tmp.x2 = 1, tmp.y2 = h + 1;
            add_line(tmp);
        }
        ans += w * h - solve();
        e = 0;
        for (i = 0; i < n; i++) add_line2(rect[i]);
        if (m != 1)
        {
            tmp.x1 = tmp.y1 = 1;
            tmp.x2 = w + 1, tmp.y2 = 1;
            add_line2(tmp);
        }
        ans += w * h - solve();
        if (m == 1) ans /= 2;
        printf("%I64d\n", ans);
    }
    system("pause");
    return 1;
}
