/*
������ֵ
*/
#include <cstdio>
#include <cstring>
#define mm 100007
#define mn 11
#define getRP(a, b) ((a)<<((b)<<1))

struct hash
{
    int h[mm], s[mm], p[mm], d[mm], t;
    int push(int x, int v)
    {
        int i, c = x % mm;
        for (i = h[c]; i >= 0; i = p[i])
            if (s[i] == x)
            {
                if (v > d[i]) d[i] = v;
                return i;
            }
        d[t] = v, s[t] = x, p[t] = h[c], h[c] = t;
        return t++;
    }
    void clear()
    {
        t = 0;
        memset(h, -1, sizeof(h));
    }
} f[2];

int g[mn][mn];
int i, j, k, g1, g2, x, y, z, s, n, m, ans;

int eat(bool f, bool l)
{
    int a = getRP(z, j + f), b = getRP(3 ^ z, j + f), c = getRP(3, j + f), n = 1;
    s = s ^ getRP(x, j) ^ getRP(y, j + 1);
    while (n)
    {
        if (f) a <<= 2, b <<= 2, c <<= 2;
        else a >>= 2, b >>= 2, c >>= 2;
        x = s & c;
        if (x == a) ++n;
        if (x == b) --n;
    }
    return l ? (s | c) : ((s ^ b) | a);
}

bool ok(int c)
{
    if (c == 1) return g[i + 1][j];
    if (c == 2) return g[i][j + 1];
    if (c == 3) return g[i + 1][j] && g[i][j + 1];
    return 0;
}

void move(int v)
{
    int w = v + g[i][j];
    if (!x && !y)
    {
        if (ok(1)) f[g2].push(s | getRP(3, j), w);
        if (ok(2)) f[g2].push(s | getRP(3, j + 1), w);
        if (ok(3)) f[g2].push(s | getRP(9, j), w);
        f[g2].push(s, v);
    }
    else if (!x || !y)
    {
        z = x + y;
        if (ok(x ? 1 : 2)) f[g2].push(s, w);
        if (ok(x ? 2 : 1)) f[g2].push(s ^ getRP(z, j) ^ getRP(z, j + 1), w);
        if (z < 3) f[g2].push(eat(z == 1, 1), w);
        else if ((s ^ getRP(x, j) ^ getRP(y, j + 1)) == 0 && w > ans) ans = w;
    }
    else if (x == y)
    {
        if ((z = x) < 3) f[g2].push(eat(z == 1, 0), w);
        else if ((s ^ getRP(x, j) ^ getRP(y, j + 1)) == 0 && w > ans)ans = w;
    }
    else if (x > 2 || y > 2)
    {
        z = x < y ? x : y;
        f[g2].push(eat(z == 1, 1), w);
    }
    else if (x == 2 && y == 1) f[g2].push(s ^ getRP(x, j) ^ getRP(y, j + 1), w);
}

int PlugDP()
{
    f[0].clear();
    f[0].push(0, 0);
    for (g1 = 1, g2 = i = 0; i < n; ++i)
    {
        for (j = 0; j < f[g2].t; ++j) f[g2].s[j] <<= 2;
        for (j = 0; j < m; ++j)
        {
            if (! g[i][j]) continue;
            for (g1 = !g1, g2 = !g2, f[g2].clear(), k = 0; k < f[g1].t; ++k)
            {
                s = f[g1].s[k], x = (s>> (j << 1)) & 3, y = (s >> ((j + 1) << 1)) & 3;
                move(f[g1].d[k]);
            }
        }
    }
    return ans;
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d", &n, &m);
        memset(g, 0, sizeof(g));
        for (ans = i = 0; i < n; ++i)
            for (j = 0; j < m; ++j)
            {
                scanf("%d", &g[i][j]);
                if (g[i][j] > ans) ans = g[i][j];
            }
        printf("%d\n",PlugDP());
    }
    return 0;
}
