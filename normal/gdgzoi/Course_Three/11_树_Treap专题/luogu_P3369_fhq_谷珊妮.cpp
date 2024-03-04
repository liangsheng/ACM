// http://gdgzoi.com/showsource.php?id=617165
#include<bits/stdc++.h>
using namespace std;
 
const int maxn = 1e5 + 5;
struct node{
    int ch[2];
    int val, siz;
    int d;
}t[maxn];
int rt;
int n;
int opt, tmp;
int tot;
int x, y, z;
 
inline void up(int x)
{
    t[x].siz = t[t[x].ch[0]].siz + t[t[x].ch[1]].siz + 1;   
}
 
inline int build(int x)
{
    t[++tot].val = x;
    t[tot].d = rand(), t[tot].siz = 1;
    return tot;
}
 
inline void split(int nw, int k, int &x, int &y)
{
    if(!nw) x = y = 0;
    else if(k >= t[nw].val)
        x = nw, split(t[nw].ch[1], k, t[nw].ch[1], y);
    else y = nw, split(t[nw].ch[0], k, x, t[nw].ch[0]);
    if(nw) up(nw);
}
 
inline int merge(int x, int y)
{ 
    if(!x or !y) return x + y;
    if(t[x].d < t[y].d) 
    {
        t[x].ch[1] = merge(t[x].ch[1], y);
        up(x);
        return x;
    }
    else
    {
        t[y].ch[0] = merge(x, t[y].ch[0]);
        up(y);
        return y;
    }
}
 
inline int kth(int nw, int x)
{
    while(1)
    {
        if(x <= t[t[nw].ch[0]].siz)
            nw = t[nw].ch[0];
        else if(x == t[t[nw].ch[0]].siz + 1)
            return nw;
        else
            x -= t[t[nw].ch[0]].siz + 1, nw = t[nw].ch[1];
    }
}
 
int main()
{
    srand((unsigned)time(NULL));
    scanf("%d", &n);
    while(n--)
    {
        scanf("%d%d", &opt, &tmp);
        if(opt == 1)
        {
            split(rt, tmp, x, y);
            rt = merge(merge(x, build(tmp)), y);
        }
        if(opt == 2)
        {
            split(rt, tmp, x, z), split(x, tmp - 1, x, y);
            y = merge(t[y].ch[0], t[y].ch[1]);
            rt = merge(merge(x, y), z);
        }
        if(opt == 3)
        {
            split(rt, tmp - 1, x, y);
            printf("%d\n", t[x].siz + 1);
            rt = merge(x, y);
        }
        if(opt == 4) printf("%d\n", t[kth(rt, tmp)].val);
        if(opt == 5)
        {
            split(rt, tmp - 1, x, y);
            printf("%d\n", t[kth(x, t[x].siz)].val);
            merge(x, y);
        }
        if(opt == 6)
        {
            split(rt, tmp, x, y);
            printf("%d\n", t[kth(y, 1)].val);
            merge(x, y);
        }
    }
    return 0;
}
/**************************************************************
    Problem: 2085
    User: 2020gdgzte09015
    Language: C++
    Result: Accepted
    Time:68 ms
    Memory:3992 kb
****************************************************************/