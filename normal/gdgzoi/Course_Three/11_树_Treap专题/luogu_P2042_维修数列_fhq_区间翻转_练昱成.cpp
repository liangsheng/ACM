// http://gdgzoi.com/showsource.php?id=618243
#include <bits/stdc++.h>
#define il inline
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
const int N = 1e6 + 10;
mt19937 rnd(233);
struct Fhq
{
    struct Node
    {
        int l, r;
        int val, key;
        int size, sum;
        int ma0, ma1, ma;
        bool lazy0;
        int lazy1;
    } fhq[N];
    int cnt, root;
    int newnode(int val)
    {
        fhq[++cnt].key = rnd();
        fhq[cnt].val = fhq[cnt].sum = fhq[cnt].ma = val;
        fhq[cnt].ma0 = fhq[cnt].ma1 = max(val, 0);
        fhq[cnt].lazy1 = INF;
        fhq[cnt].size = 1;
        return cnt;
    }
    il void update(int u)
    {
        int ls = fhq[u].l, rs = fhq[u].r;
        fhq[u].size = fhq[ls].size + fhq[rs].size + 1;
        fhq[u].sum = fhq[ls].sum + fhq[rs].sum + fhq[u].val;
        fhq[u].ma0 = max(max(fhq[ls].ma0, fhq[ls].sum + fhq[u].val + fhq[rs].ma0), 0);
        fhq[u].ma1 = max(max(fhq[rs].ma1, fhq[rs].sum + fhq[u].val + fhq[ls].ma1), 0);
        fhq[u].ma = fhq[ls].ma1 + fhq[u].val + fhq[rs].ma0;
        if (ls)
            fhq[u].ma = max(fhq[ls].ma, fhq[u].ma);
        if (rs)
            fhq[u].ma = max(fhq[rs].ma, fhq[u].ma);
    }
    il void rever(int u)
    {
        fhq[u].lazy0 ^= 1;
        swap(fhq[u].l, fhq[u].r);
        swap(fhq[u].ma0, fhq[u].ma1);
    }
    il void same(int u, int c)
    {
        fhq[u].lazy1 = c;
        fhq[u].val = c;
        fhq[u].sum = c * fhq[u].size;
        fhq[u].ma = max(c * fhq[u].size, c);
        fhq[u].ma0 = fhq[u].ma1 = max(c * fhq[u].size, 0);
    }
    il void pushdown(int u)
    {
        int ls = fhq[u].l, rs = fhq[u].r;
        if (fhq[u].lazy0)
        {
            rever(ls), rever(rs);
            fhq[u].lazy0 = 0;
        }
        if (fhq[u].lazy1 != INF)
        {
            same(ls, fhq[u].lazy1), same(rs, fhq[u].lazy1);
            fhq[u].lazy1 = INF;
        }
    }
    il void split(int u, int siz, int &x, int &y)
    {
        if (!u)
            x = y = 0;
        else
        {
            pushdown(u);
            if (fhq[fhq[u].l].size < siz)
            {
                x = u;
                split(fhq[u].r, siz - fhq[fhq[u].l].size - 1, fhq[u].r, y);
            }
            else
            {
                y = u;
                split(fhq[u].l, siz, x, fhq[u].l);
            }
            update(u);
        }
    }
    il int merge(int x, int y)
    {
        if (!x || !y)
            return x + y;
        if (fhq[x].key < fhq[y].key)
        {
            pushdown(x);
            fhq[x].r = merge(fhq[x].r, y);
            update(x);
            return x;
        }
        else
        {
            pushdown(y);
            fhq[y].l = merge(x, fhq[y].l);
            update(y);
            return y;
        }
    }
    int x, y, z;
    il void rev(int pos, int tot)
    {
        split(root, pos - 1, x, z);
        split(z, tot, y, z);
        rever(y);
        root = merge(x, merge(y, z));
    }
    il void sam(int pos, int tot, int c)
    {
        split(root, pos - 1, x, z);
        split(z, tot, y, z);
        same(y, c);
        root = merge(x, merge(y, z));
    }
    il void del(int pos, int tot)
    {
        split(root, pos - 1, x, z);
        split(z, tot, y, z);
        root = merge(x, z);
    }
    il int sum(int pos, int tot)
    {
        split(root, pos - 1, x, z);
        split(z, tot, y, z);
        pushdown(y);
        int ret = fhq[y].sum;
        root = merge(x, merge(y, z));
        return ret;
    }
    il int msum()
    {
        pushdown(root);
        return fhq[root].ma;
    }
    void ldr(int u)
    {
        if (!u)
            return;
        pushdown(u);
        ldr(fhq[u].l);
        printf("%d ", fhq[u].val);
        ldr(fhq[u].r);
    }
} fhq;
int n, m;
signed main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1, a; i <= n; i++)
        scanf("%d", &a), fhq.root = fhq.merge(fhq.root, fhq.newnode(a));
    while (m--)
    {
        char s[15];
        int pos, tot, c, x, y, z;
        scanf("%s", s);
        if (s[0] == 'I')
        {
            scanf("%d%d", &pos, &tot);
            fhq.split(fhq.root, pos, x, y);
            fhq.root = x;
            for (int i = 1, a; i <= tot; i++)
                scanf("%d", &a), fhq.root = fhq.merge(fhq.root, fhq.newnode(a));
            fhq.root = fhq.merge(fhq.root, y);
        }
        else if (s[0] == 'D')
            scanf("%d%d", &pos, &tot), fhq.del(pos, tot);
        else if (s[0] == 'R')
            scanf("%d%d", &pos, &tot), fhq.rev(pos, tot);
        else if (s[0] == 'G')
            scanf("%d%d", &pos, &tot), printf("%d\n", fhq.sum(pos, tot));
        else if (s[2] == 'K')
            scanf("%d%d%d", &pos, &tot, &c), fhq.sam(pos, tot, c);
        else
            printf("%d\n", fhq.msum());
        // fhq.ldr(fhq.root);
        // puts("");
    }
    return 0;
}
/**************************************************************
    Problem: 2101
    User: 2023gdgzth04257
    Language: C++
    Result: Accepted
    Time:36 ms
    Memory:45012 kb
****************************************************************/
