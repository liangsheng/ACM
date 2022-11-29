#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef __int64 LL;
const LL N = 5005, M = 1000005, INF = 1LL << 60;

struct Node
{
    LL v, w, next;
} edge[M];

LL e, s, t, NN;
LL head[N], pre[N], cur[N], dis[N], gap[N];

void init()
{
    e = s = 0, t = 1, NN = 2;
    memset(head, -1, sizeof(head));
}

void add_edge(LL u, LL v, LL w)
{
    edge[e].v = v, edge[e].w = w;
    edge[e].next = head[u], head[u] = e++;
    edge[e].v = u, edge[e].w = 0;
    edge[e].next = head[v], head[v] = e++;
}

LL sap()
{
    LL i, flow = 0, aug = INF, u, v;
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
        for (LL &j = cur[u]; j != -1; j = edge[j].next)
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
        LL mindis = NN;
        for (LL j = head[u]; j != -1; j = edge[j].next)
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

LL T, n, m;
LL id[105][30];

int main()
{
    LL cas = 0, i, j, sum, cnt, u, v, cost, aw, k, x, y;
    scanf("%I64d", &T);
    while (T--)
    {
        sum = 0, cnt = 1;
        init();
        scanf("%I64d", &n);
        for (i = 1; i <= n; i++)
        {
            scanf("%I64d", &m);
            NN += m;
            for (j = 1; j <= m; j++)
            {
                scanf("%I64d%I64d%I64d", &cost, &aw, &k);
                u = id[i][j] = ++cnt;
                sum += aw;
                add_edge(s, u, aw);
                add_edge(u, t, cost);
                while (k--)
                {
                    scanf("%I64d%I64d", &x, &y);
                    v = id[x][y];
                    add_edge(u, v, INF);
                }
            }
        }
        printf("Case #%I64d: %I64d\n", ++cas, sum - sap());
    }
    return 0;
}
