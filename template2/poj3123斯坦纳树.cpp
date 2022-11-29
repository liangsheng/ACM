#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <algorithm>
#include <fstream>
#define inf 99999999
#define N 30
#define file_r(x) freopen(x, "r", stdin)
#define file_w(x) freopen(x, "w", stdout)
using namespace std;

int i, j, k, p1, p2, w, sub, b, c, z, x, y;
int n, m;
int e[8], v[N];
int dp[256][30], d[30][30];
string s, t;
map<string, int> q;

int main()
{
    //file_r("ticket.in");
    //file_w("ticket1.out");
    while (cin >> n >> m)
    {
        if (n == 0 && m == 0) break;
        q.clear();
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
                d[i][j] = (i == j ? 0 : inf);
        for (i = 0; i < n; i++)
        {
            cin >> s;
            q[s] = i;
        }
        for (i = 0; i < m; i++)
        {
            cin >> s >> t >> w;
            p1 = q[s];
            p2 = q[t];
            d[p1][p2] = d[p2][p1] = min(d[p1][p2], w);
        }
        for (k = 0; k < n; k++)
            for (i = 0; i < n; i++)
                for (j = 0; j < n; j++)
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
        for (i = 0; i < 8; i++)
        {
            cin >> s;
            e[i] = q[s];
            for (j = 0; j < n; j++)
                dp[1 << i][j] = d[j][e[i]];
        }
        for (i = 1; i < 256; i++)
        {
            if (!(i & (i - 1))) continue;   //只有一个1已经算过
            for (k = 0; k < n; k++)
            {
                dp[i][k] = inf;
                v[k] = 0;
                for (sub = i; sub; sub = (sub - 1) & i)
                    dp[i][k] = min(dp[i][k], dp[sub][k] + dp[i - sub][k]);
            }
            for (j = 0; j < n; j++)
            {
                b = inf;
                for (k = 0; k < n; k++)
                {
                    if (dp[i][k] <= b && v[k] == 0)
                        b = dp[i][k], c = k;
                }
                v[c] = 1;
                for (k = 0; k < n; k++)
                    dp[i][c] = min(dp[i][c], dp[i][k] + d[k][c]);
            }
        }
        b = inf;
        for (i = 0; i < 256; i++)
        {
            z = 0;
            for (j = 0; j < 4; j++)
            {
                y = 0;
                for (k = 0; k < 8; k += 2)
                {
                    if ((i >> k & 3) == j)
                        y += (3 << k), x = e[k];
                }
                z += (y > 0 ? 1 : 0) * dp[y][x];
            }
            b = min(b, z);
        }
        cout << b << endl;
    }
    system("pause");
    return 0;
}

