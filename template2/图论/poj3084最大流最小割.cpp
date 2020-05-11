#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 25, INF = 999999;

struct Node
{
    int v, w, next;
} edge[N * N * 4];

int T, n, m, e, s, t, NN;
int head[N], pre[N], cur[N], dis[N], gap[N];

void init()
{
    e = s = 0, t = m, NN = n + 1;
    memset(head, -1, sizeof(head));
}

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

int main()
{
    int i, j, u, v, flow;
    char str[5];
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d", &n, &m);
        m++;
        init();
        for (i = 1; i <= n; i++)
        {
            scanf("%s", str);
            if (strcmp(str, "I") == 0) add_edge(s, i, INF);
            scanf("%d", &u);
            for (j = 1; j <= u; j++)
            {
                scanf("%d", &v);
                v++;
                add_edge(i, v, INF), add_edge(v, i, 1);
            }
        }
        flow = sap();
        if (flow >= INF) printf("PANIC ROOM BREACH\n");
        else printf("%d\n", flow);
    }
    system("pause");
    return 0;
}
