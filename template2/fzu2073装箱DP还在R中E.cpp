#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

typedef pair<int ,int> PAIR;

const int N = 15, M = 1030, MAXN = 505, INF = 999998, MOD = 1029;

struct Monster
{
    int li, at, de, a_a, a_d;
} a[N];

struct Li_de
{
    int li, de;
    Li_de() {}
    Li_de(int X, int Y)
    {
        li = X, de = Y;
    }
};

void get_min(Li_de &arg0, Li_de arg1)
{
    if (arg1.li < arg0.li || (arg1.li == arg0.li && arg1.de > arg0.de)) arg0 = arg1;
}

struct Hash
{
    int size, head[M], s[M], nxt[M];
    Li_de d[M];

    void init()
    {
        size = 0, memset(head, -1, sizeof(head));
    }

    void update(int x, Li_de tmp)
    {
        int i, p = x % MOD;
        for (i = head[p]; i != -1; i = nxt[i])
            if (s[i] == x)
            {
                get_min(d[i], tmp);
                return;
            }
        s[size] = x, d[size] = tmp, nxt[size] = head[p], head[p] = size++;
    }
} dp[M];

int n, m, p, cnt;
int dir[4][2] = {-1, 0, 1, 0, 0, -1, 0, 1};
int pa[M][N], f[N], mt[N];
char g[MAXN][MAXN];
int vis[MAXN][MAXN], h[N][N];
map<PAIR, int> mp;
map<PAIR, int> :: iterator iter;
queue<PAIR> q;

void solve()
{
    int i, j, k, u, v, x, y, px, py, tmp, at, li, de, ans, state;
    Li_de tmp2;
    memset(h, 0, sizeof(h));
    memset(vis, 0, sizeof(vis));
    for (iter = mp.begin(); iter != mp.end(); iter++)
    {
        i = (iter -> first).first, j = (iter -> first).second;
        u = iter -> second;
        f[0] = 1, f[1] = u;
        vis[i][j] = 1, q.push(PAIR(i, j));
        state = 1 << u;
        while (! q.empty())
        {
            x = q.front().first, y = q.front().second;
            q.pop();
            for (k = 0; k < 4; k++)
            {
                px = x + dir[k][0], py = y + dir[k][1];
                if (px < 1 || px > n || py < 1 || py > m || g[px][py] == '*' || vis[px][py] == 1) continue;
                if (g[px][py] == '.') vis[px][py] = 1, q.push(PAIR(px, py));
                else
                {
                    v = mp[PAIR(px, py)];
                    if (!(state & (1 << v))) f[++f[0]] = v, state |= (1 << v);
                    if (v == 0) q.push(PAIR(px, py));
                }
            }
        }
        //for (i = 1; i <= f[0]; i++) printf("%d ", f[i]); system("pause");
        for (i = 1; i <= f[0]; i++)
            for (j = i + 1; j <= f[0]; j++) h[f[i]][f[j]] = h[f[j]][f[i]] = 1, printf("CON %d %d\n", f[i], f[j]);
    }
    tmp = 1 << cnt;
    pa[0][0] = 0;
    for (i = 1; i <= cnt; i++)
        if (h[0][i]) pa[0][++pa[0][0]] = i;
    for (i = 1; i < tmp; i++)
    {
        memset(f, 0, sizeof(f));
        pa[i][0] = 0;
        for (j = 1; j <= cnt; j++)
        {
            if (!((i >> (j - 1)) & 1)) continue;
            for (k = 1; k <= cnt; k++)
                if (h[j][k] && f[k] == 0 && !((i >> (k - 1)) & 1)) pa[i][++pa[i][0]] = k, f[k] = 1;
        }
    }
    //for (i = 1; i <= cnt; i++) if (h[0][i]) printf("H%d ", i);system("pause");
    //for (i = 1; i <= pa[0][0]; i++) printf("%d ", pa[0][i]);
    //printf("FFFF= %d", pa[0][0]), system("pause");
    for (i = 0; i < tmp; i++) dp[i].init();
    dp[0].update(10, Li_de(0, 10));
    for (i = 0; i < tmp - 1; i++)
    {
        for (k = 0; k < dp[i].size; k++)
        {
            at = dp[i].s[k], li = dp[i].d[k].li, de = dp[i].d[k].de;
            //printf("i= %d at= %d li= %d de= %d\n", i, at, li, de);
            //printf("i= %d size= %d\n", pa[0][0]);
            for (j = 1; j <= pa[i][0]; j++)
            {
                k = mt[pa[i][j]];
                if (at <= a[k].de) continue;
                //printf("k= %d", k);//, system("pause");
                u = i | (1 << (pa[i][j] - 1)), v = at + a[k].a_a, tmp2.de = de + a[k].a_d;
                px = a[k].li / (at - a[k].de);
                py = a[k].li % (at - a[k].de);
                if (py == 0) px--;
                if (a[k].at <= de) tmp2.li = li;
                else tmp2.li = li + (a[k].at - de) * px;
                dp[u].update(v, tmp2);
                //printf("u= %d p= %d\n", u, pa[i][j]);
            }
        }
    }
    if (dp[tmp - 1].size == 0) printf("-1\n");
    else
    {
        ans = dp[tmp - 1].d[0].li;
        for (k = 1; k < dp[tmp - 1].size; k++) ans = min(ans, dp[tmp - 1].d[k].li);
        printf("%d\n", ans);
    }
}

int main()
{
    int i, j;
   // freopen("in.txt", "r", stdin);
   // freopen("out.txt", "w", stdout);
    while (scanf("%d%d%d", &n, &m, &p) != EOF)
    {
        for (i = 1; i <= p; i++)
            scanf("%d%d%d%d%d", &a[i].li, &a[i].at, &a[i].de, &a[i].a_a, &a[i].a_d);
        cnt = 0;
        mp.clear();
        for (i = 1; i <= n; i++)
        {
            getchar();
            for (j = 1; j <= m; j++)
            {
                g[i][j] = getchar();
                if (g[i][j] == '*' || g[i][j] == '.') continue;
                if (g[i][j] == '#') mp[PAIR(i, j)] = 0;
                else mp[PAIR(i, j)] = ++cnt, mt[cnt] = g[i][j] - '0';
            }
        }
        //printf("cnt= %d", cnt), system("pause");
        solve();
    }
    return 0;
}
