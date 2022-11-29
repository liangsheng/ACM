#include <cstdio>
#include <cstring>
using namespace std;

const int mm = 100007;

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

int i, j, g1, g2, u, k, n, m, a, b, a1, a2, b1, b2;
char g[15][15];
bool v[15][15];

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
    if (c == 1) return g[i + 1][j] != 'X';
    if (c == 2) return g[i][j + 1] != 'X';
    if (c == 3) return (g[i + 1][j] != 'X') && (g[i][j + 1] != 'X');
    return 1;
}

inline void work(int S, long long d)
{
    int x, y;
    x = a & S, y = b & S;
    if (x == 0 && y == 0)
    {
        if (ok(3)) f[g2].hash(S | a1 | b2, d);
        if (g[i][j] == '*') f[g2].hash(S, d);
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
    memset(v, 0, sizeof(v));
    for (int i = n - 1; i >= 0; --i)
        for (int j = m - 1; j >= 0; --j)
            if (g[i][j] != 'X')
            {
                v[i][j] = 1;
                if (g[i][j] == 'O') return;
            }
}

inline long long DP()
{
    end();
    f[0].clear();
    f[0].hash(0, 1);
    long long ans = 0;
    for (g1 = 1, g2 = i = 0; i < n; ++i)
    {
        for (k = 0; k < f[g2].t; ++k) f[g2].s[k] <<= 2;
        a = 3, b = 3 << 2, a1 = 1, a2 = 2, b1 = 1 << 2, b2 = 2 << 2;
        for (j = 0; j < m; a <<= 2, b <<= 2, a1 <<= 2, a2 <<= 2, b1 <<= 2, b2 <<= 2, ++j)
            if (g[i][j] != 'X')
                for (g1 = !g1, g2 = !g2, f[g2].clear(), k = 0; k < f[g1].t; ++k)
                {
                    if (v[i][j] && f[g1].s[k] == (a1 | b2))
                    {
                        ans += f[g1].d[k];
                        continue;
                    }
                    work(f[g1].s[k], f[g1].d[k]);
                }
    }
    return ans;
}
int main()
{
    int t, c = 0;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d", &n, &m);
        for (i = 0; i < n; ++i) scanf("%s", g[i]);
        for (i = 0; i < n; ++i) g[i][m] = 'X';
        for (j = 0; j < m; ++j) g[n][j] = 'X';
        printf("Case %d: %I64d\n", ++c, DP());
    }
    return 0;
}
