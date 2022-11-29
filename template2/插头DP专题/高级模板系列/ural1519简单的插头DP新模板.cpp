#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define getRP(a, b) ((a) << (b << 1))
using namespace std;

const int mm = 15511, N = 13;
//1(1), 2(2), 4(3), 9(4), 21(5), 51(6), 127(7), 323(8), 835(9), 2188(10), 5798(11), 15511(12), 41835(13)

struct data
{
    int s[mm], h[mm], p[mm], t;
    long long d[mm];

    inline int hash(int x, long long dd)
    {
        int i, c = x % mm;
        for (i = h[c]; i >= 0; i = p[i])
            if (s[i] == x)
            {
                d[i] += dd;
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

int n, m;
int i, j, k, g1, g2, x, y, z, s, ex, ey;
bool g[N][N];

inline int eat(bool f, bool l)
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

inline bool ok(int c)
{
    if (c == 1) return g[i + 1][j];
    if (c == 2) return g[i][j + 1];
    if (c == 3) return g[i + 1][j] && g[i][j + 1];
    return 1;
}

inline void move(long long d)
{
    if (!x && !y)
    {
        if (ok(3)) f[g2].hash(s | getRP(9, j), d);
    }
    else if (x * y == 0)
    {
        z = x + y;
        if (ok(x ? 1 : 2)) f[g2].hash(s, d);
        if (ok(x ? 2 : 1)) f[g2].hash(s ^ getRP(z, j) ^ getRP(z, j + 1), d);
    }
    else if (x == y)
    {
        z = x;
        f[g2].hash(eat(z == 1, 0), d);
    }
    else if (x == 2 && y == 1) f[g2].hash(s ^ getRP(x, j) ^ getRP(y, j + 1), d);
}

inline long long solve()
{
    f[0].clear();
    f[0].hash(0, 1);
    for (g1 = 1, g2 = i = 0; i <= ex; i++)
    {
        for (k = 0; k < f[g2].t; k++) f[g2].s[k] <<= 2;
        for (j = 0; j < m; j++)
        {
            if (! g[i][j]) continue;
            for (g1 = !g1, g2 = !g2, f[g2].clear(), k = 0; k < f[g1].t; k++)
            {
                if (i == ex && j == ey)
                {
                    if (f[g1].s[k] == (9 << (j << 1))) return f[g1].d[k];
                    else continue;
                }
                s = f[g1].s[k], x = (s >> (j << 1)) & 3, y = (s >> ((j + 1) << 1)) & 3;
                move(f[g1].d[k]);
            }
        }
    }
    return 0;
}

int main()
{
    char c;
    memset(g, 0, sizeof(g));
    scanf("%d%d", &n, &m);
    for (i = 0; i < n; ++i)
        for(j = 0; j < m; ++j)
        {
            scanf(" %c", &c);
            g[i][j] = (c == '.');
            if (g[i][j]) ex = i, ey = j;
        }
    printf("%I64d\n", solve());
    return 0;
}
