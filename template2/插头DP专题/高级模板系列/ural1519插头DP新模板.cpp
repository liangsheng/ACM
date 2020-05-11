#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int mm = 15511;
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

int i, j, g1, g2, u, k, n, m, en, em, a, b, a1, a2, b1, b2;
bool g[13][13];

inline int eat(int s, int a, int b, int c, bool f)
{
    int n = 1, x;
    while (n)
    {
        if (f) a <<= 2, b <<= 2, c <<= 2;
        else a >>= 2, b >>= 2, c >>= 2;
        x = s & c;
        if (x == a) ++n;
        if (x == b) --n;
    }
    return (s ^ b) | a;
}

inline bool ok(int c)
{
    if (c == 1) return g[i + 1][j];
    if (c == 2) return g[i][j + 1];
    if (c == 3) return g[i + 1][j] && g[i][j + 1];
    return 1;
}

inline void work(int S, long long d)
{
    int x, y;
    x = a & S, y = b & S;
    if (x == 0 && y == 0)
    {
        if (ok(3)) f[g2].hash(S | a1 | b2, d);
    }
    else if (x == 0 && y == b1)
    {
        if (ok(2)) f[g2].hash(S, d);
        if (ok(1)) f[g2].hash((S ^ b1) | a1, d);
    }
    else if (x == a1 && y == 0)
    {
        if (ok(1)) f[g2].hash(S, d);
        if (ok(2)) f[g2].hash((S ^ a1) | b1, d);
    }
    else if (x == a1 && y == b1) f[g2].hash(eat(S ^ a1 ^ b1, b1, b2, b, 1), d);
    else if (x == 0 && y == b2)
    {
        if (ok(2)) f[g2].hash(S, d);
        if (ok(1)) f[g2].hash((S ^ b2) | a2, d);
    }
    else if (x == a2 && y == 0)
    {
        if (ok(1)) f[g2].hash(S, d);
        if (ok(2)) f[g2].hash((S ^ a2) | b2, d);
    }
    else if (x == a2 && y == b2) f[g2].hash(eat(S ^ a2 ^ b2, a2, a1, a, 0),d);
    else if (x == a2 && y == b1) f[g2].hash(S ^ a2 ^ b1, d);
}

inline void end()
{
    for (en = n - 1; en >= 0; --en)
        for(em = m - 1; em >= 0; --em)
            if (g[en][em]) return;
}

inline long long DP()
{
    end();
    f[0].clear();
    f[0].hash(0, 1);
    for (g1 = 1, g2 = i = 0; i <= en; ++i)
    {
        for (k = 0; k < f[g2].t; ++k) f[g2].s[k] <<= 2;
        a = 3, b = 3 << 2, a1 = 1, a2 = 2, b1 = 1 << 2, b2 = 2 << 2;
        for (j = 0; j < m; a <<= 2, b <<= 2, a1 <<= 2, a2 <<= 2, b1 <<= 2, b2 <<= 2, ++j)
            if (g[i][j])
                for (g1 = !g1, g2 = !g2, f[g2].clear(), k = 0; k < f[g1].t; ++k)
                {
                    if (i == en && j == em)
                    {
                        if (f[g1].s[k] == (a1 | b2)) return f[g1].d[k];
                        else continue;
                    }
                    work(f[g1].s[k], f[g1].d[k]);
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
            scanf(" %c",&c), g[i][j] = (c == '.');
    printf("%I64d\n", DP());
    return 0;
}
