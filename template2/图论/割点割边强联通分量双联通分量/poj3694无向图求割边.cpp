#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 100005, M = 200005;

struct Node
{
    int v, next;
} edge[M << 1];

int n, m, q, e, cnt, ans;
int head[N], dfn[N], low[N];
int lv[N], pre[N];
bool is_bridge[N];

void init()
{
    e = cnt = ans = 0;
    fill(is_bridge + 1, is_bridge + n + 1, 0);
    memset(head, -1, sizeof(head));
    memset(dfn, -1, sizeof(dfn));
}

void add_edge(int u, int v)
{
    edge[e].v = v;
    edge[e].next = head[u];
    head[u] = e++;
}

void dfs(int p, int fa, int stp)
{
    int i, v;
    dfn[p] = low[p] = ++cnt, lv[p] = stp, pre[p] = fa;
    for (i = head[p]; i != -1; i = edge[i].next)
    {
        v = edge[i].v;
        if (dfn[v] == -1)
        {
            dfs(v, p, stp + 1);
            if (low[v] < low[p]) low[p] = low[v];
            if (low[v] > dfn[p]) is_bridge[v] = 1, ans++;
        }
        else if (v != fa) low[p] = min(low[p], dfn[v]);
    }
}

void solve(int u, int v)
{
    if (lv[v] > lv[u]) swap(u, v);
    while (lv[u] > lv[v])
    {
        if (is_bridge[u]) is_bridge[u] = 0, ans--;
        u = pre[u];
    }
    while (u != v)
    {
        if (is_bridge[u]) is_bridge[u] = 0, ans--;
        u = pre[u];
        if (is_bridge[v]) is_bridge[v] = 0, ans--;
        v = pre[v];
    }
    printf("%d\n", ans);
}

int main()
{
    int i, j, u, v, cas = 0;
    while (scanf("%d%d", &n, &m) != EOF)
    {
        if (n == 0 && m == 0) break;
        init();
        for (i = 1; i <= m; i++)
        {
            scanf("%d%d", &u, &v);
            add_edge(u, v), add_edge(v, u);
        }
        dfs(1, 1, 1);
        printf("Case %d:\n", ++cas);
        scanf("%d", &q);
        for (i = 1; i <= q; i++)
        {
            scanf("%d%d", &u, &v);
            solve(u, v);
        }
    }
    system("pause");
    return 0;
}
