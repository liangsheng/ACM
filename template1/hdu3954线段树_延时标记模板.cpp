#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#define N 10005
#define inf (1 << 30)
using namespace std;

struct NODE
{
    int l, r, mx;
    int lz;
    int mn;   //最小的需要升级的第三个参数 
    int mv;      //当前区间的最高等级 
};

int T, n, max_level, m;
int up[15];
NODE a[N * 4];

int update(int k)
{
    a[k].mx = max(a[k << 1].mx, a[(k << 1) + 1].mx);
    a[k].mn = min(a[k << 1].mn, a[(k << 1) + 1].mn);
    a[k].mv = max(a[k << 1].mv, a[(k << 1) + 1].mv); 
    return 1;
}

int Build_Tree(int s, int t, int k)
{
    int mid;
    a[k].l = s, a[k].r = t, a[k].lz = 0;
    if (s == t) 
    {
        a[k].mv = 1;
        a[k].mn = up[1];
        a[k].mx = 0;
        return 1;
    }
    mid = (s + t) >> 1;
    Build_Tree(s, mid, k << 1);
    Build_Tree(mid + 1, t, (k << 1) + 1);
    update(k);
    return 1;
}

int change(int k)   //处理不需要升级的情况 
{
    a[k  << 1].lz += a[k].lz; 
    a[k << 1].mx += a[k].lz * a[k << 1].mv;
    a[k << 1].mn -= a[k].lz;
    a[(k << 1) + 1].lz += a[k].lz; 
    a[(k << 1) + 1].mx += a[k].lz * a[(k << 1) + 1].mv;
    a[(k << 1) + 1].mn -= a[k].lz;
    a[k].lz = 0;
    return 1;
}

int Insert(int s, int t, int ei, int k)
{
    int mid, pre, temp;
    if (a[k].l == a[k].r)
    {
        a[k].mx += a[k].mv * ei;
        while (a[k].mx >= up[a[k].mv]) a[k].mv++;
        a[k].mn = (up[a[k].mv] - a[k].mx) / a[k].mv + ((up[a[k].mv]-a[k].mx) % a[k].mv != 0);
        return 1;        
    } 
    mid = (a[k].l + a[k].r) >> 1;
    if (s == a[k].l && t == a[k].r)
    {
        if (ei < a[k].mn)
        {
            a[k].lz += ei;
            a[k].mn -= ei;
            a[k].mx += a[k].mv * ei;
        }
        else 
        {
            change(k);
            Insert(s, mid, ei, k << 1);
            Insert(mid + 1, t, ei, (k << 1) + 1); 
            update(k);
        }
        return 1;  
    }
    if (a[k].lz != 0) change(k);
    if (t <= mid) Insert(s, t, ei, k << 1);
    else if (s > mid) Insert(s, t, ei, (k << 1) + 1);
    else Insert(s, mid ,ei, k << 1), Insert(mid + 1, t, ei, (k << 1) + 1);
    update(k);
    return 1;
}

int Find(int s, int t, int k)
{
    int mid, ans = -1;
    if (s == a[k].l && t == a[k].r) return a[k].mx;
    if (a[k].lz != 0) change(k);
    mid = (a[k].l + a[k].r) >> 1;
    if (t <= mid) ans = Find(s, t, k << 1);
    else if (s > mid) ans = Find(s, t, (k << 1) + 1);
    else ans = max(Find(s, mid, k << 1), Find(mid + 1, t, (k << 1) + 1));
    return ans;    
}

int main()
{
    int i, h, s, t, ei, ans, j, kk;
    char cmd[5];
    scanf("%d", &T);
    for (h = 1; h <= T; h++)
    {
        printf("Case %d:\n", h);
        scanf("%d%d%d", &n, &max_level, &m);
        for (i = 1; i < max_level; i++)
            scanf("%d", &up[i]);
        up[max_level] = inf;
        Build_Tree(1, n, 1);
        for (i = 1; i <= m; i++)
        {
            scanf("%s%d%d", cmd, &s, &t);
            if (cmd[0] == 'W')
            {
                scanf("%d", &ei);
                Insert(s, t, ei, 1);
            }
            else printf("%d\n", Find(s, t, 1));    
        }
        printf("\n");
    }
    system("pause");
    return 0;
}
