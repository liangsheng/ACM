#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 2010, M = 1000005, INF = (~0U >> 1) >> 1;

struct Node
{
    int v, w, next;
} edge[M];

int n, e, s, t, NN;
int head[N], pre[N], cur[N], dis[N], gap[N];

void init()
{
    e = s = 0, t = 2 * n + 1, NN = t + 1;
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

int a[N], dp[N];

int main()
{
    int i, j, len;
    while (scanf("%d", &n) != EOF)
    {
        init();
        for (i = 1; i <= n; i++) scanf("%d", &a[i]);
        dp[1] = 1, len = 1;
        for (i = 2; i <= n; i++)
        {
            dp[i] = 1;
            for (j = 1; j < i; j++)
                if (a[j] < a[i]) dp[i] = max(dp[i], dp[j] + 1);
            len = max(len, dp[i]);
        }
        for (i = 1; i <= n; i++)
        {
            add_edge(i, i + n, 1);
            if (dp[i] == 1) add_edge(s, i, INF);
            if (dp[i] == len) add_edge(i + n, t, INF);
            for (j = i + 1; j <= n; j++)
                if (dp[j] == dp[i] + 1) add_edge(i + n, j, 1);
        }
        printf("%d\n%d\n", len, sap());
    }
    return 0;
}
