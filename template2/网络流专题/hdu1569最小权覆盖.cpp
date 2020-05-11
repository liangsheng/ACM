/*
最小权点覆盖边=总权值 - 最大权点独立
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 2510, M = 30000, INF = (~0U >> 1) >> 1;

struct Node
{
    int v, w, next;
} edge[M];

int T, n, m, e, s, t, NN;
int head[N], pre[N], cur[N], dis[N], gap[N];

void init()
{
    e = s = 0, t = n * m + 1, NN = t + 1;
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

int dir[4][2] = {-1, 0, 1, 0, 0, -1, 0, 1};

inline int get_id(int i, int j)
{
    if (i < 1 || i > n || j < 1 || j > m) return -1;
    return (i - 1) * m + j;
}

int main()
{
    int i, j, k, x, u, v, sum;
    while (scanf("%d%d", &n, &m) != EOF)
    {
        init();
        sum = 0;
        for (i = 1; i <= n; i++)
            for (j = 1; j <= m; j++)
            {
                u = (i - 1) * m + j;
                scanf("%d", &x);
                sum += x;
                if (i % 2 == j % 2) add_edge(s, u, x);
                else
                {
                    add_edge(u, t, x);
                    continue;
                }
                for (k = 0; k < 4; k++)
                {
                    v = get_id(i + dir[k][0], j + dir[k][1]);
                    if (v == -1) continue;
                    add_edge(u, v, INF);
                }
            }
        printf("%d\n", sum - sap());
    }
    return 0;
}
