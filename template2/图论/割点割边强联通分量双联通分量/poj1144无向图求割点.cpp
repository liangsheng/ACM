#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 105;

struct Node
{
    int v, next;
} edge[N * N];

int n, e, cnt;
int head[N], dfn[N], low[N];
bool f[N];

void init()
{
    e = cnt = 0;
    fill(f + 1, f + n + 1, 0);
    memset(head, -1, sizeof(head));
    memset(dfn, -1, sizeof(dfn));
}

void add_edge(int u, int v)
{
    edge[e].v = v;
    edge[e].next = head[u];
    head[u] = e++;
}

void dfs(int p, int fa)
{
    int i, v, sum = 0;
    dfn[p] = low[p] = ++cnt;
    for (i = head[p]; i != -1; i = edge[i].next)
    {
        v = edge[i].v;
        if (dfn[v] == -1)
        {
            dfs(v, p);
            sum++;
            if (low[v] < low[p]) low[p] = low[v];
            if (p != 1 && low[v] >= dfn[p]) f[p] = 1;
            if (p == 1 && sum > 1) f[p] = 1;
        }
        else if (v != fa) low[p] = min(low[p], dfn[v]);
    }
}

int main()
{
    int i, j, u, v, ans;
    while (scanf("%d", &n) != EOF && n != 0)
    {
        init();
        while(scanf("%d", &u) != EOF && u != 0)
        {
            while (getchar() != '\n')
            {
                scanf("%d", &v);
                add_edge(u, v), add_edge(v, u);
            }
        }
        dfs(1, 1);
        ans = 0;
        for (i = 1; i <= n; i++) if (f[i]) ans++;
        printf("%d\n", ans);
    }
    system("pause");
    return 0;
}
