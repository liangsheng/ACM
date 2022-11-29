#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define INF 999999
using namespace std;

typedef long long LL;

const int MAXN = 15, MOD = 99991, MAXS = 6000;  //pow(3, 11)
//1(1), 2(2), 4(3), 9(4), 21(5), 51(6), 127(7), 323(8), 835(9), 2188(10), 5798(11), 15511(12), 41835(13)

int n, m;
int h[MOD], size[2];
int g[MAXN][MAXN];
char a[MAXN][MAXN];

struct State
{
    unsigned mask;    //当前状态,4进制
    int nxt;          //下一个节点
    LL opt;           //当前状态的数目
} s[2][MAXS];

inline void update(int p, unsigned mask, LL opt)
{
    //cout << "opt= " << opt, system("pause");
    int i, val = mask % MOD;
    for (i = h[val]; i != -1; i = s[p][i].nxt)
    {
        if (s[p][i].mask == mask)
        {
            s[p][i].opt  = max(s[p][i].opt, opt);
            return;
        }
    }
    s[p][size[p]].mask = mask;
    s[p][size[p]].opt = opt;
    s[p][size[p]].nxt = h[val];
    h[val] = size[p]++;
}

inline int get(unsigned mask, int x)
{
    return (mask >> (x << 1)) & 3;
}

inline int change(unsigned mask, int x, int val)
{
    mask = mask ^ (get(mask, x) << (x << 1));
    if (val) return mask ^ (val << (x << 1));
    return mask;
}

inline int find(unsigned mask, int x, int val)
{
    int t = (val == 1 ? 1 : -1), b = 1;
    for (x += (val == 1) + t; x >= 0 && x <= m && b; x += t)  //方便在p == q时的寻找
    {
        int p = get(mask, x);
        if (p == val) b++;
        else if (p == 3 - val) b--;
    }
    return b ? x : x - t;
}

inline void init(int p)
{
    memset(h, -1, sizeof(h));
    size[p] = 0;
    memset(s[p], 0, sizeof(s[p]));
    for (int i = 0; i < MAXS; i++) s[p][i].opt = -INF;
}

int main()
{
    int i, j, k, cas = 0;
    int x, y, p, q, t, f;
    while (scanf("%d%d", &m, &n) != EOF)
    {
        memset(g, 0, sizeof(g));
        for (i = 1; i <= m; i++)
            for (j = 1; j <= n; j++) scanf("%d", &g[j + 2][i]);
        for (i = 0; i <= n + 3; i++)
            for (j = 0; j <= m + 3; j++)
            {
                if (i == 0 || j == 0 || i == n + 3 || j == m + 3) a[i][j] = '#';
                else if (i == 1 || j == 1 || i == n + 2 || j == m + 2) a[i][j] = '.';
                else if (i >= 3 && j <= m) a[i][j] = '.';
                else a[i][j] = '#';
            }
        x = n + 2, y = m + 2;
        n += 2, m += 2;
        /*for (i = 0; i <= n + 1; i++)
        {
            for (j = 0; j <= m + 1; j++) cout << a[i][j] << " ";
            cout << endl;
        } cout << x << " " << y, system("pause");*/
        f = 1;
        init(f);
        update(f, 0, 0);
        for (i = 1; i <= n; i++)
        {
            f ^= 1;
            init(f);
            for (k = 0; k < size[f ^ 1]; ++k)
                update(f, s[f ^ 1][k].mask << 2, s[f ^ 1][k].opt);
            for (j = 1; j <= m; j++)
            {
                f ^= 1;
                init(f);
                for (k = 0; k < size[f ^ 1]; ++k)
                {
                    p = get(s[f ^ 1][k].mask, j - 1), q = get(s[f ^ 1][k].mask, j);
                    if (a[i][j] == '.')
                    {
                        if (p == 0 && q == 0)
                        {
                            if (a[i + 1][j] == '.' && a[i][j + 1] == '.')
                                update(f, change(change(s[f ^ 1][k].mask, j - 1, 1), j, 2), s[f ^ 1][k].opt + g[i][j]);
                            if (i >= 3 && j <= m - 2)
                                update(f, change(change(s[f ^ 1][k].mask, j - 1, 0), j, 0), s[f ^ 1][k].opt);
                        }
                        else if (p == 0)
                        {
                            if (a[i][j + 1] == '.') update(f, s[f ^ 1][k].mask, s[f ^ 1][k].opt + g[i][j]);
                            if (a[i + 1][j] == '.')
                                update(f, change(change(s[f ^ 1][k].mask, j - 1, q), j, 0), s[f ^ 1][k].opt + g[i][j]);
                        }
                        else if (q == 0)
                        {
                            if (a[i + 1][j] == '.') update(f, s[f ^ 1][k].mask, s[f ^ 1][k].opt + g[i][j]);
                            if (a[i][j + 1] == '.')
                                update(f, change(change(s[f ^ 1][k].mask, j - 1, 0), j, p), s[f ^ 1][k].opt + g[i][j]);
                        }
                        else if (p == q)
                        {
                            t = find(s[f ^ 1][k].mask, j - 1, p);
                            if (t >= 0 && t <= m)
                                update(f, change(change(change(s[f ^ 1][k].mask, j - 1, 0), j, 0), t, p), s[f ^ 1][k].opt + g[i][j]);
                        }
                        else if (p == 2 || (i == x && j == y))
                            update(f, change(change(s[f ^ 1][k].mask, j - 1, 0), j, 0), s[f ^ 1][k].opt + g[i][j]);
                    }
                    else if (p == 0 && q == 0) update(f, s[f ^ 1][k].mask, s[f ^ 1][k].opt);
                }
            }
        }
        t = h[0];
        while (s[f][t].mask) t = s[f][t].nxt;
        //for (i = 0; i < size[f]; i++) cout << s[f][i].opt << " ";
        //system("pause");
        printf("Case %d: %I64d\n", ++cas, s[f][t].opt);
    }
    system("pause");
    return 0;
}
