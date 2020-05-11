#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>
#include <algorithm>
#define inf (1 << 30)
#define N 30
const double eps = 1e-12;
const double pi = acos(-1.0);
using namespace std;

int T, n, k, m;
int h1[30], h2[30];
char s[35][10001];

int g[N][N];
int x[N], y[N], match[N], lx[N], ly[N];

int init()
{
    memset(g,0,sizeof(g));
    memset(match,-1,sizeof(match));
    return 1;
}

int make()
{
    int i, j;
    memset(lx, 0, sizeof(lx));
    memset(ly, 0, sizeof(ly));
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++) lx[i] = max(lx[i], g[i][j]);
    return 1;
}

int Find(int a)
{
    int i;
    x[a] = 1;
    for (i = 1; i <= n; i++)
    {
        if (y[i] == 0 && lx[a] + ly[i] == g[a][i])
        {
           y[i] = 1;
           if (match[i] == -1 || Find(match[i]))
           {
              match[i] = a;
              return 1;
           }
        }
    }
    return 0;
}

int Kuhn_Munkers()
{
    int i, j, k, d;
    int ans = 0;
    for (i = 1; i <= n; i++)
    {
        while (1)
        {
            memset(x, 0, sizeof(x));
            memset(y, 0, sizeof(y));
            if (Find(i)) break;
            d = inf;
            for (k = 1; k <= n; k++)
            {
                if (x[k] != 1) continue;
                for (j = 1; j <= n; j++)
                {
                    if (y[j] == 0)
                        d = min(d, lx[k] + ly[j] - g[k][j]);
                }
            }
            if (d == inf) break;
            for (j = 1; j <= n; j++)
            {
                if (x[j] == 1) lx[j] -= d;
                if (y[j] == 1) ly[j] += d;
            }
        }
    }
    for (i = 1; i <= n; i++)
        if (match[i] != -1) ans += g[match[i]][i];
    return ans;
}

int main()
{
    int i, j, h, e1, e2;
    double ans;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d%d", &k, &n, &m);
        for (i = 0; i <= m; i++)
            for (j = 1; j <= k; j++) cin >> s[i][j];
        for (h = 1; h <= m; h++)
        {
            init();
            e1 = e2 = 0;
            memset(h1, -1, sizeof(h1));
            memset(h2, -1, sizeof(h2));
            for (j = 1; j <= k; j++)
            {
                if (h1[s[0][j] - 'A'] == -1) h1[s[0][j] - 'A'] = ++e1;
                if (h2[s[h][j] - 'A'] == -1) h2[s[h][j] - 'A'] = ++e2;
                g[h1[s[0][j] - 'A']][h2[s[h][j] - 'A']]++;
            }
            make();
            ans = Kuhn_Munkers() / double(k);
            printf("%.4lf\n", ans);
        }
    }
    system("pause");
    return 0;
}
