#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#define N 100005
using namespace std;

struct NODE
{
    int l, r;
    int lb, rb, vb;
    int lw, rw, vw;
    int flag;  
};

int n, m;
int x[N];
NODE node[N * 3];

int max(int x, int y, int z)
{
    x = x > y ? x : y;
    return x > z ? x : z;
}

int Update(int k)
{
    int lp = k << 1, rp = (k << 1) + 1, ll, lr;
    node[k].vb = max(node[lp].vb, node[rp].vb, node[lp].rb + node[rp].lb);
    node[k].vw = max(node[lp].vw, node[rp].vw, node[lp].rw + node[rp].lw);
    ll = node[lp].r - node[lp].l + 1, lr = node[rp].r - node[rp].l + 1;
    if (node[lp].lb == ll) node[k].lb = ll + node[rp].lb; 
    else node[k].lb = node[lp].lb;
    if (node[lp].lw == ll) node[k].lw = ll + node[rp].lw; 
    else node[k].lw = node[lp].lw;
    if (node[rp].rb == lr) node[k].rb = lr + node[lp].rb; 
    else node[k].rb = node[rp].rb;
    if (node[rp].rw == lr) node[k].rw = lr + node[lp].rw; 
    else node[k].rw = node[rp].rw;
    return 1;        
}

int Build_Tree(int s, int t, int k)
{
    int mid;
    node[k].l = s, node[k].r = t, node[k].flag = 0;
    if (s == t)
    {
        node[k].lb = node[k].rb = node[k].vb = x[s]; 
        node[k].lw = node[k].rw = node[k].vw = 1 - x[s];
        return 1; 
    }
    mid = (s + t) >> 1;
    Build_Tree(s, mid, k << 1);
    Build_Tree(mid + 1, t, (k << 1) + 1);
    Update(k);
    return 1;
}

int Change(int k)
{
    swap(node[k].lb, node[k].lw);
    swap(node[k].rb, node[k].rw);
    swap(node[k].vb, node[k].vw);
    node[k].flag ^= 1;
    return 1;
}

int Update(int s, int t, int k)
{
    int mid;
    if (node[k].l == s && node[k].r == t)
    {
        Change(k);
        return 1;          
    }
    if (node[k].flag == 1)
    {
        Change(k << 1);
        Change((k << 1) + 1);
        node[k].flag = 0;          
    }
    mid = (node[k].l + node[k].r) >> 1;
    if (t <= mid) Update(s, t, k << 1);
    else if (s > mid) Update(s, t, (k << 1) + 1);
    else Update(s, mid, k << 1), Update(mid + 1, t, (k << 1) + 1);
    Update(k);
    return 1;
}

int Query(int s, int t, int k)
{
    int mid, ans, ll, lr;
    if (node[k].l == s && node[k].r == t) return node[k].vb;
    if (node[k].flag == 1)
    {
        Change(k << 1);
        Change((k << 1) + 1);
        node[k].flag = 0;           
    }
    mid = (node[k].l + node[k].r) >> 1;
    if (t <= mid) ans = Query(s, t, k << 1);
    else if (s >mid) ans = Query(s, t, (k << 1) + 1);
    else
    {
        ll = Query(s ,mid, k << 1);
        lr = Query(mid + 1, t, (k << 1) + 1);
        ans = max(ll, lr, min(node[k << 1].rb, mid - s + 1) + min(node[(k << 1) + 1].lb, t - mid));
    }
    return ans;
}

int main()
{
    int i, j, a, b, c;
    while (~scanf("%d", &n))
    {
        for (i = 1; i <= n; i++)
            scanf("%d", &x[i]);
        Build_Tree(1, n, 1);
        //for (i = 1; i <= 13; i++)
         //   cout << node[i].l << " " << node[i].r << " " << node[i].lb << " " << node[i].rb << " " << node[i].vb << endl;
         //   system("pause");
        scanf("%d", &m);
        for (i = 1; i <= m; i++)
        {
            scanf("%d%d%d", &a, &b, &c);
            if (a) Update(b, c, 1);
            else printf("%d\n", Query(b, c, 1));
        }          
    }
    //system("pause");
    return 0;
}
