#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define N 1005
#define INF 99999999
using namespace std;

struct EDGE
{
    int u, v, w;
    int next;   
};

int t, n, m, e, s, first, second;
int head[N], dis[N], visit[N], pre[N], maxuv[N][N];
EDGE edge[N * N * 2];

int Init()
{
    e = 0;
    first = INF;
    second = INF;
    memset(edge, 0, sizeof(edge));
    memset(head, -1, sizeof(head));
    memset(maxuv, -1, sizeof(maxuv));
    memset(pre, -1, sizeof(pre));
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

int Prim()
{
    int i, j, k, mini, v, sum = 0;
    s = 1;
    memset(visit, 0, sizeof(visit));
    fill(dis + 1, dis + n + 1, INF);
    visit[s] = 1;
    dis[s] = 0;
    for (i = head[s]; i != -1; i = edge[i].next)
        dis[edge[i].v] = edge[i].w, pre[edge[i].v] = s;
    for (i = 1; i < n; i++)
    {
        mini = INF, k = -1;
        for (j = 1; j <= n; j++)
        {
            if ((! visit[j]) && dis[j] < mini)
                mini = dis[j], k = j;
        }
        if (k == -1) return -1;
        for (j = 1; j <= n; j++)
        {
            if (visit[j])
            {
                maxuv[j][k] = max(maxuv[j][pre[k]], mini);
                maxuv[k][j] = maxuv[j][k];
            }
        }
        sum += mini;
        visit[k] = 1;        
        for (j = head[k]; j != -1; j = edge[j].next)
        {
            v = edge[j].v;
            if ((! visit[v]) && edge[j].w < dis[v])
                dis[v] = edge[j].w, pre[v] = k;
        }
    }
    return sum;
}

int solve()
{
    int i, j, u, v, w, temp;
    first = Prim();
    for (i = 0; i < e; i += 2)
    {
        u = edge[i].u;
        v = edge[i].v;
        w = edge[i].w;
        if (pre[v] == u || pre[u] == v) continue;
        temp = first - maxuv[u][v] + w;
        second = min(second, temp);
    }
    return 1;
}

int main()
{
    int i, j, u, v, w;
    while (scanf("%d", &n) != EOF)
    {
        Init(); 
        for (i = 1; i <= n; i++)
        {
            for (j = 1; j <= n; j++)
            {
                scanf("%d", &w);
                if (j <= i) continue;
                add_edge(i, j, w);
                add_edge(j, i, w);
            }
        }
        solve();
        printf("%d\n", first);
        printf("%d\n", second);
    }
    system("pause");
    return 0;
}
