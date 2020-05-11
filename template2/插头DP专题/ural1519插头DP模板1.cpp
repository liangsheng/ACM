#include <cstdio>
#include <cstring>

const int MAXN = 14, MOD = 99991, MAXS = 300000;

typedef long long LL;

char a[MAXN][MAXN];
int h[MOD], size[2], n, m;

struct state
{
    unsigned mask;
    int nxt;
    LL opt;
} s[2][MAXS];

inline void update(int p, unsigned mask, LL opt)
{
    int val = mask % MOD;
    for (int i = h[val]; i != -1; i = s[p][i].nxt)
        if (s[p][i].mask == mask)
        {
            s[p][i].opt += opt;
            return;
        }
    s[p][size[p]].mask = mask;
    s[p][size[p]].opt = opt;
    s[p][size[p]].nxt = h[val];
    h[val] = size[p] ++;
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
    int t = val == 1 ? 1 : -1, b = 1;
    for (x += (val == 1) + t; x >= 0 && x <= m && b; x += t)
    {
        int p = get(mask, x);
        if (p == val)
            ++ b;
        else if (p == 3 - val)
            -- b;
    }
    return b ? x : x - t;
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++ i)
        scanf("%s", a[i] + 1);
    int x, y;
    for (int i = 0; i <= n + 1; ++ i)
        for (int j = 0; j <= m + 1; ++ j)
            if (i == 0 || j == 0 || i == n + 1 || j == m + 1)
                a[i][j] = '*';
            else if (a[i][j] == '.')
            {
                x = i;
                y = j;
            }
    memset(h, -1, sizeof h);
    int f = 1;
    size[0] = 0;
    update(0, 0, 1);
    for (int i = 1; i <= n; ++ i)
    {
        f ^= 1;
        size[f ^ 1] = 0;
        memset(s[f ^ 1], 0, sizeof s[f ^ 1]);
        memset(h, -1, sizeof h);
        for (int k = 0; k < size[f]; ++ k)
            update(f ^ 1, s[f][k].mask << 2, s[f][k].opt);
        for (int j = 1; j <= m; ++ j)
        {
            memset(h, -1, sizeof h);
            f = f ^ 1;
            size[f ^ 1] = 0;
            memset(s[f ^ 1], 0, sizeof s[f ^ 1]);
            for (int k = 0; k < size[f]; ++ k)
            {
                int p = get(s[f][k].mask, j - 1), q = get(s[f][k].mask, j);
                if (a[i][j] == '.')
                {
                    if (p == 0 && q == 0)
                    {
                        if (a[i + 1][j] == '.' && a[i][j + 1] == '.')
                            update(f ^ 1, change(change(s[f][k].mask, j - 1, 1), j, 2), s[f][k].opt);
                    }
                    else if (p == 0)
                    {
                        if (a[i][j + 1] == '.')
                            update(f ^ 1, s[f][k].mask, s[f][k].opt);
                        if (a[i + 1][j] == '.')
                            update(f ^ 1, change(change(s[f][k].mask, j - 1, q), j, 0), s[f][k].opt);
                    }
                    else if (q == 0)
                    {
                        if (a[i + 1][j] == '.')
                            update(f ^ 1, s[f][k].mask, s[f][k].opt);
                        if (a[i][j + 1] == '.')
                            update(f ^ 1, change(change(s[f][k].mask, j - 1, 0), j, p), s[f][k].opt);
                    }
                    else if (p == q)
                    {
                        int t = find(s[f][k].mask, j - 1, p);
                        if (t >= 0 && t <= m)
                            update(f ^ 1, change(change(change(s[f][k].mask, j - 1, 0), j, 0), t, p), s[f][k].opt);
                    }
                    else if (p == 2 || i == x && j == y)
                        update(f ^ 1, change(change(s[f][k].mask, j - 1, 0), j, 0), s[f][k].opt);
                }
                else if (p == 0 && q == 0)
                    update(f ^ 1, s[f][k].mask, s[f][k].opt);
            }
        }
    }
    int t = h[0];
    while (s[f ^ 1][t].mask)
        t = s[f ^ 1][t].nxt;
    printf("%I64d\n", s[f ^ 1][t].opt);
    return 0;
}
