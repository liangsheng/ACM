// http://gdgzoi.com/showsource.php?id=616177
#include <bits/stdc++.h>
 
using namespace std;
 
const int _ = 5e2 + 7;
 
#define i0 a[i].L
 
#define i1 a[i].R
 
struct Node
{
    int L, R, se, tag, z, f, size;
    int sum, max, max0, max1;
} a[_];
 
int nc;
 
int top, S[_];
 
int x, y, z;
 
int New(int z)
{
    int id = top ? S[top--] : ++nc;
    memset(a+id, 0, sizeof(Node));
    a[id].sum = a[id].z = a[id].max = z;
    a[id].max0 = a[id].max1 = max(0, z);
    a[id].size = 1, a[id].se = rand();
    return id;
}
 
void rmv(int i)
{
    S[++top] = i;
    if(i0) rmv(i0);
    if(i1) rmv(i1);
}
 
void cover(int i, int c)
{
    a[i].z =  c;
    a[i].sum = a[i].size * c;
    a[i].max0 = a[i].max1 = max(0, a[i].sum);
    a[i].max = max(c, a[i].sum);
    a[i].tag = 1;
}
 
void reverse(int i)
{
    swap(i0, i1);
    swap(a[i].max0, a[i].max1);
    a[i].f ^= 1;
}
 
void pushtag(int i)
{
    if(!i) return;
    if(a[i].f)
    {
        if (i0) reverse(i0);
        if (i1) reverse(i1);
        a[i].f = 0;
    }
    if(a[i].tag)
    {
        if (i0) cover(i0, a[i].z);
        if (i1) cover(i1, a[i].z);
        a[i].tag = 0;
    }
}
 
void update(int i)
{
    if(!i) return;
    a[i].size = a[i0].size + a[i1].size + 1;
    a[i].sum = a[i0].sum + a[i1].sum + a[i].z;
    a[i].max0 = max(max(a[i0].max0, a[i0].sum + a[i].z + a[i1].max0), 0);
    a[i].max1 = max(max(a[i1].max1, a[i1].sum + a[i].z + a[i0].max1), 0);
    a[i].max = max(a[i0].max1 + a[i1].max0, 0) + a[i].z;
    if(i0) a[i].max = max(a[i].max, a[i0].max);
    if(i1) a[i].max = max(a[i].max, a[i1].max);
}
 
void split(int i, int &x, int &y, int k)
{
    if(!i)
    {
        x = y = 0;
        return;
    }
    pushtag(i);
    if(a[i0].size < k)
        x = i, split(i1, i1, y, k-a[i0].size-1);
    else
        y = i, split(i0, x, i0, k);
    update(i);
}
 
int merge(int x, int y)
{
    if(!x || !y) return x + y;
    if(a[x].se < a[y].se)
    {
        pushtag(x);
        a[x].R = merge(a[x].R, y);
        return update(x), x;
    }
    pushtag(y);
    a[y].L = merge(x, a[y].L);
    return update(y), y;
}
 
int t[_];
 
int add(int L, int R)
{
    if(L != R)
    {
        int mid = (L + R) >> 1;
        return merge(add(L, mid), add(mid + 1, R));
    }
    return New(t[L]);
}
 
int n, m;
 
int root;
 
char str[17];
 
signed main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &t[i]);
        root = merge(root, New(t[i]));
    }
    while(m--)
    {
        scanf("%s", str);
        if(str[2] == 'S')
        {
            int len, pos;
            scanf("%d%d", &pos, &len);
            if(len <= 0)
            {
                continue;
            }
            split(root, x, y, pos);
            for (int i = 1; i <= len; i++)
                scanf("%d", &t[i]);
            root = merge(merge(x, add(1, len)), y);
        }
        else if(str[2] == 'L')
        {
            int pos, len;
            scanf("%d%d", &pos, &len);
            if(len <= 0)
            {
                continue;
            }
            split(root, x, y, pos - 1);
            split(y, y, z, len);
            rmv(y);
            root = merge(x, z);
        }
        else if(str[2] == 'K')
        {
            int pos, len, c;
            scanf("%d%d%d", &pos, &len, &c);
            split(root, x, y, pos - 1);
            split(y, y, z, len);
            cover(y, c);
            root = merge(merge(x, y), z);
        }
        else if(str[2] == 'V')
        {
            int pos, len;
            scanf("%d%d", &pos, &len);
            split(root, x, y, pos - 1);
            split(y, y, z, len);
            reverse(y);
            root = merge(merge(x, y), z);
        }
        else if(str[2] == 'T')
        {
            int pos, len;
            scanf("%d%d", &pos, &len);
            split(root, x, y, pos - 1);
            split(y, y, z, len);
            printf("%d\n", a[y].sum);
            root = merge(merge(x, y), z);
        }
        else
        {
            printf("%d\n", a[root].max);
        }
    }
}
/**************************************************************
    Problem: 2101
    User: 2020gdgzzc09003
    Language: C++
    Result: Accepted
    Time:32 ms
    Memory:2052 kb
****************************************************************/
