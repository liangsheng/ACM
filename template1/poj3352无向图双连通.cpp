#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define inf (1 << 30)
#define mod 1000000007
#define N 1005
#define M 1005
const double eps = 1e-12;
const double pi = acos(-1.0);
using namespace std;

struct NODE
{
    int u, v;
    int next;
};

int n, m, e, et, idx, top, cnt, ans;
int head[N], dfn[N], low[N], id[N], vis[N], q[N], size[N];
NODE edge[M * 2], h[M * 2];

int init()
{
    e = et = 0;
    idx = top = cnt = 0;
    memset(head, -1, sizeof(head));
    memset(dfn, 0, sizeof(dfn));
    memset(low, 0, sizeof(low));
    memset(size, 0, sizeof(size));
    return 1;
}

int add_edge(int u, int v)
{
    edge[e].u = u;
    edge[e].v = v;
    edge[e].next = head[u];
    head[u] = e++;
    size[u]++;
    return 1;
}

int Tarjan(int u, int fa)
{
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

int solve()
{
    int i, j, p, ans = 0;
    e = 0;
    for (i = 1; i <= n; i++)
        if (dfn[i] == 0)
        {
            Tarjan(i, i);
            cnt++;
            while (top--) id[q[top]] = cnt;
        }
    memset(size, 0, sizeof(size));
    for (i = 1; i <= et; i++)
    {
        add_edge(id[h[i].u], id[h[i].v]);
        add_edge(id[h[i].v], id[h[i].u]);
    }
    for (i = 1; i <= cnt; i++)
        if (size[i] == 1) ans++;
    printf("%d\n", (ans + 1) / 2);
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
            scanf("%d%d", &u, &v);
            add_edge(u, v), add_edge(v, u);
        }
        solve();
    }
    system("pause");
    return 0;
}
