#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define inf (1 << 30)
#define mod 1000000007
#define N 10005
#define M 100005
const double eps = 1e-12;
const double pi = acos(-1.0);
using namespace std;

struct NODE
{
    int u, v, w;
    int next;
};

int n, m, e, et, idx, top, cnt, ans;
int head[N], dfn[N], low[N], id[N], vis[N], q[N];
NODE edge[M * 2], h[M * 2];

int init()
{
    e = et = 0;
    idx = top = cnt = 0;
    memset(head, -1, sizeof(head));
    memset(dfn, 0, sizeof(dfn));
    memset(low, 0, sizeof(low));
    return 1;
}

int add_edge(int u, int v, int w)
{
    edge[e].u = u;
    edge[e].v = v;
    edge[e].w = w;
    edge[e].next = head[u];
    head[u] = e++;
    return 1;
}

int Tarjan(int u, int fa)
{
    //cout << u, system("pause");
    int i, v;
    dfn[u] = low[u] = ++idx;
    q[top++] = u;
    for(i = head[u]; i != -1; i = edge[i].next)
    {
        v = edge[i].v;
        if (dfn[v] == 0)
        {
            Tarjan(v, u);
            low[u] = min(low[u], low[v]);
            if(dfn[u] < low[v])
            {
                id[v]= ++cnt;
                h[++et] = edge[i];
                while (q[--top] != v) id[q[top]] = cnt;
            }
        }
        else if(v != fa) low[u] = min(low[u], dfn[v]);
    }
    return 1;
}

int find(int u)
{
    int i, v;
    low[u] = inf;
    for (i = head[u]; i!= -1; i = edge[i].next)
    {
        v = edge[i].v;
        if (vis[v]) continue;
        vis[v] = 1;
        find(v);
        low[v] = min(low[v], edge[i].w);
        if (low[v] < low[u]) ans = min(low[u], ans), low[u] = low[v];
        else ans = min(ans, low[v]);
    }
    return 1;
}

int solve()
{
    int i, j, p;
    e = 0;
    for (i = 1; i <= n; i++)
        if (dfn[i] == 0)
        {
            Tarjan(i, i);
            cnt++;
            while (top--) id[q[top]] = cnt;
        }
    p = 1, e = 0;
    memset(head, -1, sizeof(head));
    memset(vis, 0, sizeof(vis));
    for (i = 1; i <= et; i++)
    {
        add_edge(id[h[i].u], id[h[i].v], h[i].w);
        add_edge(id[h[i].v], id[h[i].u], h[i].w);
        if (h[i].w < h[p].w) p = i;
    }
    i = id[h[p].u], j = id[h[p].v];
    vis[i] = vis[j] = 1;
    ans = inf;
    find(i), find(j);
    if (ans == inf) printf("-1\n");
    else printf("%d\n", ans);
    return 1;
}

int main()
{
    int i, j, u, v, w;
    while (scanf("%d%d", &n, &m) != EOF)
    {
        init();
        for (i = 1; i <= m; i++)
        {
            scanf("%d%d%d", &u, &v, &w);
            add_edge(u, v, w), add_edge(v, u, w);
        }
        solve();
    }
    system("pause");
    return 0;
}
