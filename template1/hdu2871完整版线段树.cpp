#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define inf (1 << 30)
#define N 50005
using namespace std;

int n, m, p1, p2;

struct NODE
{
    int l, r;
    int seg;                //被覆盖的段数
    int len, l_len, r_len;  //最长, 左起, 右起连续未被覆盖长度
    int lz;
    bool cover;             //是否全部被覆盖
    int st, en;
    int init()
    {
        len = l_len = r_len = r - l + 1;
        seg = 0;
        cover = 0;
        st = en = 0;
        return 1;
    }
    int be_cover()
    {
        len = l_len = r_len = 0;
        seg = 1;
        cover = 1;
        st = p1, en = p2;
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
    if (v) a[k].seg++;
    else a[k].seg--;
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

int find(int k, int v)
{
    int l = k << 1, r = l + 1;
    down(k);
    if (a[k].len == a[k].get_len() && a[k].len >= v) return a[k].l;
    if (a[l].len >= v) return find(l, v);
    if (a[l].r_len + a[r].l_len >= v) return a[l].r - a[l].r_len + 1;
    if (a[r].len >= v) return find(r, v);
    update(k);
    return -1;
}

int find1(int k, int v)
{
    int l = k << 1, r = l + 1, mid = a[k].get_mid(), t;
    down(k);
    if (a[k].seg < v) return -1;
    if (a[k].seg == 1 && a[k].cover == 1)
    {
        p1 = a[k].st, p2 = a[k].en;
        return 1;
    }
    if (a[l].seg >= v) return find1(l, v);
    if (a[l].seg + a[r].seg == a[k].seg)
        return find1(r, v - a[l].seg);
    else return find1(r, v - a[l].seg + 1);
}

int find2(int k, int v)
{
    int l = k << 1, r = l + 1, mid = a[k].get_mid();
    down(k);
    if (a[k].l == a[k].r && a[k].cover == 0) return -1;
    if (a[k].cover == 1 && a[k].seg == 1)
    {
        p1 = a[k].st, p2 = a[k].en;
        return 1;
    }
    if (v <= mid) return find2(l, v);
    else return find2(r, v);
    update(k);
    return -1;
}

int main()
{
    int i, j, x, p;
    char cmd[10];
    while (scanf("%d%d", &n, &m) != EOF)
    {
        Build_Tree(1, n, 1);
        while (m--)
        {
            scanf("%s", cmd);
            if (cmd[0] == 'G')
            {
                scanf("%d", &x);
                p = find1(1, x);
                if (p == -1)
                {
                    printf("Reject Get\n");
                    continue;
                }
                printf("Get at %d\n", p1);
            }
            else if (cmd[0] == 'R')
            {
                printf("Reset Now\n");
                insert(1, n, 1, 0);
            }
            else if (cmd[0] == 'N')
            {
                scanf("%d", &x);
                p = find(1, x);
                if (p == -1) puts("Reject New");
                else
                {
                    printf("New at %d\n", p);
                    p1 = p, p2 = p + x - 1;
                    insert(p, p + x - 1, 1, 1);
                }
            }
            else if (cmd[0] == 'F')
            {
                scanf("%d", &x);
                p = find2(1, x);
                if (p == -1) puts("Reject Free");
                else
                {
                    printf("Free from %d to %d\n", p1, p2);
                    insert(p1, p2, 1, 0);
                }
            }
        }
        printf("\n");
    }
    system("pause");
    return 0;
}
