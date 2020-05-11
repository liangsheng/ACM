/*
(1)如果一个双连通分量内的某些顶点在一个奇圈中（即双连通分量含有奇圈），
那么这个双连通分量的其他顶点也在某个奇圈中；
(2)如果一个双连通分量含有奇圈，则他必定不是一个二分图。反过来也成立，这是一个充要条件。
由于双连通分量也是一个图，那么要判断双连通分量是否为奇圈，只需判断这个双连通分量是否
为一个二分图，而要判断一个图是否为二分图，就用交叉染色法！
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define pause cout << " press any key to continue...", cin >> ch
#define file_r(x) freopen(x, "r", stdin)
#define file_w(x) freopen(x, "w", stdout)
using namespace std;
int ch;

const int N = 1005, M = 1000000 * 2 + 5;

struct NODE
{
    int v, next;
};

int n, m, e, idx, top, cnt;
int head[N], dfn[N], low[N], id[N], q[N], num[N];
NODE edge[M];
int col[N];
int vis[N];

int init()
{
    e = 0;
    idx = top = cnt = 0;
    memset(head, -1, sizeof(head));
    memset(dfn, 0, sizeof(dfn));
    memset(low, 0, sizeof(low));
    memset(id, -1, sizeof(id));
    return 1;
}

void add_edge(int u, int v)
{
    edge[e].v = v;
    edge[e].next = head[u];
    head[u] = e++;
}

bool dfs(int p, int x)
{
    int i, v;
    col[p] = x;
    for (i = head[p]; i != -1; i = edge[i].next)
    {
        v = edge[i].v;
        if (id[v] != cnt) continue;
        if (col[v] == -1)
        {
            if (dfs(v, x ^ 1)) return 1;
        }
        else if (col[v] == x) return 1;
    }
    return 0;
}

int Tarjan(int u, int fa)
{
    int i, j, v, sum, t;
    dfn[u] = low[u] = ++idx;
    q[++top] = u;
    for(i = head[u]; i != -1; i = edge[i].next)
    {
        v = edge[i].v;
        if (dfn[v] == 0)
        {
            Tarjan(v, u);
            low[u] = min(low[u], low[v]);
            if(dfn[u] <= low[v])
            {
                cnt++, sum = 0;
                do
                {
                    t = q[top--];
                    id[t] = cnt;
                    sum++;
                } while (t != v);
                id[u] = cnt, sum++;
                memset(col, -1, sizeof(col));
                if (sum >= 3 && dfs(u, 0))
                {
                    for (j = 1; j <= n; j++)
                        if (id[j] == cnt) vis[j] = 1;
                }   //对于题目添加的函数

            }
        }
        else if (v != fa) low[u] = min(low[u], dfn[v]);
    }
    return 1;
}

int g[N][N];

void solve()
{
    int i, ans = 0;
    for (i = 1; i <= n; i++)
        if (dfn[i] == 0) Tarjan(i, i);
    for (i = 1; i <= n; i++) if (!vis[i]) ans++;
    printf("%d\n", ans);
}

int main()
{
    int i, j, u, v;
    while (scanf("%d%d", &n, &m) != EOF)
    {
        if (n == 0 && m == 0) break;
        init();
        memset(g, 0, sizeof(g));
        for (i = 1; i <= m; i++)
        {
            scanf("%d%d", &u, &v);
            g[u][v] = g[v][u] = 1;
        }
        for (i = 1; i <= n; i++)
        {
            for (j = 1; j <= n; j++)
                if (! g[i][j] && i != j) add_edge(i, j);
        }
        memset(vis ,0, sizeof(vis));
        solve();
    }
    return 0;
}
