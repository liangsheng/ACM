/*
经典题目,有上下界的最小流,做法入下
1.in[v]表示以v为终点的边的下界之和,out[u]表示以u为起点的边的下界之和
2.虚拟出ss,tt,连(ss,in[v])和(out[u],tt)
3.做一次maxflow(ss,tt)
4.加一条t->s的inf边
5.再做一次maxflow(ss,tt)
6.如果两次maxflow之和 < in之和,则不存在可行流
7.最后答案为f[t -> s]既inf – 残余[t -> s]
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 105, M = 22000, INF = ~0U >> 2;

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
    //printf("u= %d v= %d w= %d\n", u, v, w);
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

int in[N], out[N], high[M / 2], low[M / 2];

int main()
{
    int i, j, u, v, w, sum, max_flow;
    scanf("%d%d", &n, &m);
    init();
    memset(in, 0, sizeof(in));
    memset(out, 0, sizeof(out));
    for (i = 1; i <= m; i++)
    {
        scanf("%d%d%d%d", &u, &v, &high[i], &j);
        if (j) low[i] = high[i];
        else low[i] = 0;
        out[u] += low[i], in[v] += low[i];
        add_edge(u, v, high[i] - low[i]);
    }
    sum = 0;
    for (i = 1; i <= n; i++)
    {
        w = in[i] - out[i];
        if (w > 0) add_edge(s, i, w), sum += w;
        if (w < 0) add_edge(i, t, -w);
    }
    max_flow = sap();
    add_edge(n, 1, INF);
    max_flow += sap();
    if (max_flow != sum)
    {
        puts("Impossible");
        return 0;
    }
    printf("%d\n", edge[e - 1].w);
    for (i = 1; i <= m; i++)
    {
        if (i != 1) printf(" ");
        if (low[i] == high[i]) printf("%d", low[i]);
        else printf("%d", edge[i * 2 - 1].w);
    }
    printf("\n");
    return 0;
}
