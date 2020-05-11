#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define sqr(x) ((x) * (x))
using namespace std;

const int N = 300005, M = 4000005, NP = 55, INF = (~0U >> 1) >> 1;

struct Node
{
    int v, w, next;
} edge[M];

int e, s, ss, t, NN;
int head[N], pre[N], cur[N], dis[N], gap[N];

void add_edge(int u, int v, int w)
{
    edge[e].v = v, edge[e].w = w;
    edge[e].next = head[u], head[u] = e++;
    edge[e].v = u, edge[e].w = 0;
    edge[e].next = head[v], head[v] = e++;
}

int sap()
{
    int i, flow = 0, aug = INF, u, v;
    bool flag;
    for (i = 0; i <= NN; i++)
    {
        cur[i] = head[i];
        gap[i] = dis[i] = 0;
    }
    gap[0] = NN;
    u = pre[s] = s;
    while (dis[s] < NN)
    {
        flag = 0;
        for (int &j = cur[u]; j != -1; j = edge[j].next)
        {
            v = edge[j].v;
            if (edge[j].w > 0 && dis[u] == dis[v] + 1)
            {
                flag = 1;
                if (edge[j].w < aug) aug = edge[j].w;
                pre[v] = u;
                u = v;
                if (u == t)
                {
                    flow += aug;
                    while (u != s)
                    {
                        u = pre[u];
                        edge[cur[u]].w -= aug;
                        edge[cur[u] ^ 1].w += aug;
                    }
                    aug = INF;
                }
                break;
            }
        }
        if (flag) continue;
        int mindis = NN;
        for (int j = head[u]; j != -1; j = edge[j].next)
        {
            v = edge[j].v;
            if (edge[j].w > 0 && dis[v] < mindis)
            {
                mindis = dis[v];
                cur[u] = j;
            }
        }
        if ((--gap[dis[u]]) == 0) break;
        gap[dis[u] = mindis + 1]++;
        u = pre[u];
    }
    return flow;
}

int n, m, d, w;
int X[NP], Y[NP], Z[NP];
bool g[NP][NP];
int pa[NP][NP], q[NP], vis[NP];

bool judge()
{
    int i, head, tail, u, v;
    head = tail = 0, vis[0] = 1;
    for (i = 1; i <= n + 1; i++)
    {
        if (g[0][i]) vis[i] = 1, q[tail++] = i;
        else vis[i] = 0;
    }
    while (head != tail)
    {
        u = q[head++];
        for (i = 1; i <= pa[u][0]; i++)
        {
            v = pa[u][i];
            if (vis[v]) continue;
            q[tail++] = v, vis[v] = 1;
        }
    }
    return vis[n + 1];
}

void init(int mid)
{
    e = s = 0, ss = n * 2 * mid + 1, t = ss + 1, NN = t + 1;
    memset(head, -1, sizeof(head));
}

bool solve(int mid)
{
    int i, j, k, u, v, ans;
    init(mid);
    add_edge(s, ss, m);
    for (i = 1; i <= n; i++)
    {
        if (g[0][i])
        {
            for (j = 1; j <= mid; j++)
                add_edge(ss, 2 * n * j - 2 * n + i, INF);
        }
        if (g[i][n + 1])
        {
            for (j = 1; j <= mid; j++)
                add_edge(2 * n * j - 2 * n + i + n, t, INF);
        }
        for (j = 1; j < mid; j++)
        {
            add_edge(2 * n * j - 2 * n + i, 2 * n * j - 2 * n + i + n, Z[i]);
            add_edge(2 * n * j - 2 * n + i + n, 2 * n * (j + 1) - 2 * n + i, INF);
            for (k = 1; k <= pa[i][0]; k++)
            {
                u = pa[i][k];
                if (u == 0 || u == n + 1) continue;
                add_edge(2 * n * j - 2 * n + i + n, 2 * n * (j + 1) - 2 * n + u, INF);
            }
        }
        add_edge(2 * n * mid - 2 * n + i, 2 * n * mid - 2 * n + i + n, Z[i]);
    }
    ans = sap();
    if (ans == m) return 1;
    return 0;
}

int main()
{
    int i, j, head, tail, mid;
    while (scanf("%d%d%d%d", &n, &m, &d, &w) != EOF)
    {
        for (i = 1; i <= n; i++) scanf("%d%d%d", &X[i], &Y[i], &Z[i]);
        if (d >= w)
        {
            printf("1\n");
            continue;
        }
        for (i = 1; i <= n; i++)
        {
            g[i][i] = 0;
            g[0][i] = g[i][0] = (Y[i] <= d);
            g[i][n + 1] = g[n + 1][i] = (w - Y[i] <= d);
            for (j = i + 1; j <= n; j++)
            {
                if (sqr(X[i] - X[j]) + sqr(Y[i] - Y[j]) <= sqr(d)) g[i][j] = g[j][i] = 1;
                else g[i][j] = g[j][i] = 0;
            }
        }
        for (i = 0; i <= n + 1; i++)
        {
            pa[i][0] = 0;
            for (j = 0; j <= n + 1; j++)
                if (g[i][j]) pa[i][++pa[i][0]] = j;
        }
        if (! judge())
        {
            printf("IMPOSSIBLE\n");
            continue;
        }
        head = 1, tail = n + m;
        while (head < tail)
        {
            mid = (head + tail) >> 1;
            if (solve(mid - 1)) tail = mid;
            else head = mid + 1;
        }
        printf("%d\n", head);
    }
    return 0;
}
