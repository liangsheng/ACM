#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 1005, M = 10005, INF = ~0U >> 1;

struct Node
{
    int v, w, next;
} edge[M];

int T, n, m, s, t, e;
int head[N];
int num[N][2], vis[N][2];
int dis[N][2];

void init()
{
    e = 0;
    memset(head, -1, sizeof(head));
}

void add_edge(int u, int v, int w)
{
    edge[e].v = v, edge[e].w = w;
    edge[e].next = head[u], head[u] = e++;
}

void solve()
{
    int i, j, u, v, w, k, ans, mini;
    memset(vis, 0, sizeof(vis));
    memset(num, 0, sizeof(num));
    for (i = 1; i <= n; i++) dis[i][0] = dis[i][1] = INF;
    dis[s][0] = 0, num[s][0] = 1;
    for (i = 1; i < 2 * n; i++)
    {
        mini = INF, u = k = -1;
        for (j = 1; j <= n; j++)
        {
            if (! vis[j][0] && dis[j][0] < mini)
            {
                mini = dis[j][0];
                u = j, k = 0;
            }
            else if (! vis[j][1] && dis[j][1] < mini)
            {
                mini = dis[j][1];
                u = j, k = 1;
            }
        }
        if (u == -1) break;
        vis[u][k] = 1;
        for (j = head[u]; j != -1; j = edge[j].next)
        {
            v = edge[j].v, w = edge[j].w;
            if (mini + w < dis[v][0])
            {
                dis[v][1] = dis[v][0], num[v][1] = num[v][0];
                dis[v][0] = mini + w, num[v][0] = num[u][k];
            }
            else if (dis[v][0] == mini + w) num[v][0] += num[u][k];
            else if (mini + w < dis[v][1])
            {
                dis[v][1] = mini + w;
                num[v][1] = num[u][k];
            }
            else if (mini + w == dis[v][1]) num[v][1] += num[u][k];
        }
    }
    ans = num[t][0];
    if (dis[t][1] == dis[t][0] + 1) ans += num[t][1];
    printf("%d\n", ans);
}

int main()
{
    int i, j, u, v, w;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d", &n, &m);
        init();
        for (i = 1; i <= m; i++)
        {
            scanf("%d%d%d", &u, &v, &w);
            add_edge(u, v, w);
        }
        scanf("%d%d", &s, &t);
        solve();
    }
    return 0;
}
