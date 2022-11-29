#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 11, mm = 15511, INF = 999999;
//1(1), 2(2), 4(3), 9(4), 21(5), 51(6), 127(7), 323(8), 835(9), 2188(10), 5798(11), 15511(12), 41835(13)

struct data
{
    int s[mm], h[mm], p[mm], t;
    int d[mm];

    inline int hash(int x, int dd)
    {
        int i, c = x % mm;
        for (i = h[c]; i >= 0; i = p[i])
            if (s[i] == x)
            {
                d[i] = min(d[i], dd);
                return i;
            }
        s[t] = x, p[t] = h[c], h[c] = t, d[t] = dd;
        return t++;
    }

    void clear()
    {
        t = 0, memset(h, -1, sizeof(h));
    }

} f[2];

int i, j, g1, g2;

int n, m;
int g[N][N];

inline bool ok(int c)
{
    if (c == 1) return g[i + 1][j] != 1;
    if (c == 2) return g[i][j + 1] != 1;
    if (c == 3) return g[i + 1][j] != 1 && g[i][j + 1] != 1;
    return 1;
}

void work(int s, int d)
{
    int x, y, v = j << 1, u = v + 2;;
    x = 3 & (s >> v), y = 3 & (s >> u), s = s ^ (x << v) ^ (y << u);
    if (x == 0 && y == 0)
    {
        if (g[i][j] == 0)
        {
            f[g2].hash(s, d);
            if (ok(3)) f[g2].hash(s | (10 << v), d + 1), f[g2].hash(s | (15 << v), d + 1);
        }
        else
        {
            if (ok(1)) f[g2].hash(s | (g[i][j] << v), d + 1);
            if (ok(2)) f[g2].hash(s | (g[i][j] << u), d + 1);
        }
    }
    else if (x * y == 0)
    {
        if (g[i][j] == 0)
        {
            x += y;
            if (ok(1)) f[g2].hash(s | (x << v), d + 1);
            if (ok(2)) f[g2].hash(s | (x << u), d + 1);
        }
        else if (x + y == g[i][j]) f[g2].hash(s, d + 1);
    }
    else if (x == y && g[i][j] == 0) f[g2].hash(s, d + 1);
}

void solve()
{
    int k, ans = INF;
    f[0].clear();
    f[0].hash(0, 0);
    for (g1 = 1, g2 = i = 0; i < n; i++)
    {
        for (k = 0; k < f[g2].t; k++) f[g2].s[k] <<= 2;
        for (j = 0; j < m; j++)
        {
            if (g[i][j] == 1) continue;
            for (g1 = !g1, g2 = !g2, k = 0, f[g2].clear(); k < f[g1].t; k++)
                work(f[g1].s[k], f[g1].d[k]);
        }
    }
    for (k = 0; k < f[g2].t; k++)
        if (f[g2].s[k] == 0) ans = min(ans, f[g2].d[k] - 2);
    if (ans == INF) ans = 0;
    printf("%d\n", ans);
}

int main()
{
    while (scanf("%d%d", &n, &m) != EOF)
    {
        if (n == 0 && m == 0) break;
        for (i = 0; i < n; i++)
            for (j = 0; j < m; j++) scanf("%d", &g[i][j]);
        for (i = 0; i < n; i++) g[i][m] = 1;
        for (j = 0; j < m; j++) g[n][m] = 1;
        solve();
    }
    return 0;
}
