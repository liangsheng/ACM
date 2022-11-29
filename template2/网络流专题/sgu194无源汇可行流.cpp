/*
可如此构造一个只有流量上界的附加网络：增加附加源S'和附加汇T'，
原网络中M(i)非负，则C'(S', i) = M(i)，否则C'(i, T') = -M(i)；
原网络中任意有弧相连的结点u和结点v在附加网络中的弧C'(u, v) = C(u, v) - B(u, v)。
这样，如果附加网络满流，则在原网络中就存在一个与之对应的可行流。
而想判断附加网络能否满流可通过求解附加网络的最大流进行判断。如果满流，则有解；否则无解。
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 205, M = 82000, INF = ~0U >> 2;

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

int in[N], out[N], low[M / 2], high[M / 2];

int main()
{
    int i, j, u, v, w, sum, max_flow;
    scanf("%d%d", &n, &m);
    init();
    memset(in, 0, sizeof(in));
    memset(out, 0, sizeof(out));
    for (i = 1; i <= m; i++)
    {
        scanf("%d%d%d%d", &u, &v, &low[i], &high[i]);
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
    if (max_flow != sum)
    {
        puts("NO\n");
        return 0;
    }
    puts("YES\n");
    for (i = 1; i <= m; i++)
        printf("%d\n", edge[i * 2 - 1].w + low[i]);
    return 0;
}
