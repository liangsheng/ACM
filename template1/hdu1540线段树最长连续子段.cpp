#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <stack>
#define inf (1 << 30)
#define N 50005
using namespace std;

int n, m;

struct NODE
{
    int l, r;
    int len, l_len, r_len;  //最长, 左起, 右起连续未被覆盖长度
    int lz;
    bool cover;             //是否全部被覆盖
    int init()
    {
        len = l_len = r_len = r - l + 1;
        cover = 0;
        return 1;
    }
    int be_cover()
    {
        len = l_len = r_len = 0;
        cover = 1;
        return 1;
    }
    int get_len() { return r - l + 1; }
    int get_mid() { return (l + r) >> 1; }
};

NODE a[N << 2];

int Build_Tree(int s, int t, int k)
{
    int mid = (s + t) >> 1;
    a[k].l = s, a[k].r = t, a[k].lz = -1;
    a[k].init();
    if (s == t) return 1;
    Build_Tree(s, mid, k << 1);
    Build_Tree(mid + 1, t, (k << 1) + 1);
    return 1;
}

int update(int k)
{
    int l = k << 1, r = l + 1;
    a[k].cover = a[l].cover & a[r].cover;
    if (a[k].cover == 1) a[k].len = a[k].l_len = a[k].r_len = 0;
    else
    {
        if (a[l].l_len != a[l].get_len()) a[k].l_len = a[l].l_len;
        else a[k].l_len = a[l].l_len + a[r].l_len;
        if (a[r].r_len != a[r].get_len()) a[k].r_len = a[r].r_len;
        else a[k].r_len = a[r].r_len + a[l].r_len;
        a[k].len = max(a[l].len, a[r].len);
        a[k].len = max(a[k].len, a[l].r_len + a[r].l_len);
    }
    return 1;
}

int down(int k)
{
    int l = k << 1, r = l + 1;
    if (a[k].lz == -1 || a[k].get_len() == 1) return 1;
    if (a[k].lz == 0) a[l].init(), a[r].init();
    else a[l].be_cover(), a[r].cover;
    a[l].lz = a[r].lz = a[k].lz;
    a[k].lz = -1;
    return 1;
}

int insert(int s, int t, int k, int v)
{
    int mid = a[k].get_mid(), l = k << 1, r = l + 1;
    down(k);
    if (a[k].l == s && a[k].r == t)
    {
        if (v) a[k].be_cover();
        else a[k].init();
        a[k].lz = v;
        return 1;
    }
    if (t <= mid) insert(s, t, l, v);
    else if (s > mid) insert(s, t, r, v);
    else insert(s, mid, l, v), insert(mid + 1, t, r, v);
    update(k);
    return 1;
}

int find(int x, int k)
{
    int mid = a[k].get_mid(), l = k << 1, r = l + 1;
    down(k);
    if (a[k].get_len() == 1) return 1 - a[k].cover;
    if ((x <= mid && x >= mid - a[l].r_len + 1) || (x > mid && x <= mid + a[r].l_len))
    {
        return a[l].r_len + a[r].l_len;
    }
    if (x <= mid) return find(x, l);
    return find(x, r);
}

int main()
{
    int i, x, p;
    char ch;
    while (scanf("%d%d", &n, &m) != EOF)
    {
        Build_Tree(1, n, 1);
        stack<int> q;
        for (i = 1; i <= m; i++)
        {
            cin >> ch;
            if (ch == 'D')
            {
                scanf("%d", &x);
                insert(x, x, 1, 1);
                q.push(x);
            }
            else if (ch == 'R')
            {
                p = q.top();
                q.pop();
                insert(p, p, 1, 0);
            }
            else if (ch == 'Q')
            {
                scanf("%d", &x);
                printf("%d\n", find(x, 1));
            }
        }
    }
    system("pause");
    return 0;
}
