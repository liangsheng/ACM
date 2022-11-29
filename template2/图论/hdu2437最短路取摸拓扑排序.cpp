#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define pause cout << " press any key to continue...", cin >> ch
#define file_r(x) freopen(x, "r", stdin)
#define file_w(x) freopen(x, "w", stdout)
using namespace std;
int ch;

const int N = 1005, M = 20005, K = 1005, INF = ~0U >> 1;

struct NODE
{
    int v, w, next;
} edge[M];

int e;
int head[N];

int T, n, m, s, k, cas = 0;
char str[N];
int dp[N][N], in[N], vis[N];

void init()
{
    e = 0;
    memset(head, -1, sizeof(head));
    memset(in, 0, sizeof(in));
}

void add_edge(int u, int v, int w)
{
    edge[e].v = v, edge[e].w = w, in[v]++;
    edge[e].next = head[u], head[u] = e++;
}

void solve()
{
    int i, j, h, u, v, w, ans, p;
    bool f;
    memset(dp, -1, sizeof(dp));
    memset(vis, 0, sizeof(vis));
    dp[s][0] = 0;
    f = true;
    while (f)
    {
        f = false;
        for (i = 1; i <= n; i++)
        {
            if (vis[i] || in[i] != 0) continue;
            vis[i] = 1, f = true;
            //printf("i= %d", i), pause;
            for (j = head[i]; j != -1; j = edge[j].next) in[edge[j].v]--;
            for (j = 0; j < k; j++)
            {
                if (dp[i][j] == -1) continue;
                for (h = head[i]; h != -1; h = edge[h].next)
                {
                    v = edge[h].v, w = edge[h].w;
                    u = (dp[i][j] + w) % k;
                    if (dp[v][u] == -1 || dp[v][u] > dp[i][j] + w)
                        dp[v][u] = dp[i][j] + w;
                }
            }
        }
    }
    ans = INF;
    for (i = 1; i <= n; i++)
    {
        if (str[i] == 'T') continue;
        if (dp[i][0] != -1 && dp[i][0] < ans) ans = dp[i][0], p = i;
    }
    if (ans == INF) printf("Case %d: -1 -1\n", ++cas);
    else printf("Case %d: %d %d\n", ++cas, ans, p);
}

int main()
{
    int i, j, u, v, w, ans;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d%d%d", &n, &m, &s, &k);
        init();
        getchar();
        scanf("%s", str + 1);
        for (i = 1; i <= m; i++)
        {
            scanf("%d%d%d", &u, &v, &w);
            add_edge(u, v, w);
        }
        solve();
    }
    return 0;
}
