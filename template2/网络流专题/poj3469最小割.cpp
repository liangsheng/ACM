/*
构图:S与所有点连边,容量为费用1,所有点与汇点连边,容量为费用2,若i,j有矛盾,i与j连双向
边,容量为多的花费
原理:割边的意义为该点的花费,和因为不在一起而多余的花费
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 20010, M = 1000000, INF = (~0U >> 1) >> 1;

struct Node
{
    int v, w, next;
} edge[M];

int n, m, e, s, t, NN;
int head[N], pre[N], cur[N], dis[N], gap[N];

void init()
{
    e = s = 0, t = n + 1, NN = t + 1;
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
    int i, j, x, y, z;
    scanf("%d%d", &n, &m);
    init();
    for (i = 1; i <= n; i++)
    {
        scanf("%d%d", &x, &y);
        add_edge(s, i, x), add_edge(i, t, y);
    }
    for (i = 1; i <= m; i++)
    {
        scanf("%d%d%d", &x, &y, &z);
        add_edge(x, y, z), add_edge(y, x, z);
    }
    printf("%d\n", sap());
    return 0;
}
