/*
无向图边联通度:
    去掉最少的边,让图不连通
    任选1原点,枚举汇点求最大流的最小值
无向图点联通度:
    去掉最少的点,让图不连通
    拆点A位A1, A2,A1到A2连权值为1的边,图中原来的边为INF,
    两两枚举原汇点,求A2到B1的最大流的最小值
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair<int, int> PAIR;

const int N = 105, INF = 999999;

struct Node
{
    int v, w, next;
} edge[N * N * 2];

int T, n, m, e, s, t, NN;
int head[N], pre[N], cur[N], dis[N], gap[N];

void init()
{
    e = 0, NN = n << 1;
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

vector<PAIR> q;

int main()
{
    int i, j, k, u, v, size, ans;
    while (scanf("%d%d", &n, &m) != EOF)
    {
        q.clear();
        for (i = 1; i <= m; i++)
        {
            scanf(" (%d,%d)", &u, &v);
            q.push_back(PAIR(u, v));
        }
        ans = INF;
        for (i = 0; i < n; i++)
        {
            for (j = i + 1; j < n; j++)
            {
                init();
                s = i << 1 | 1, t = j << 1;
                for (k = 0; k < n; k++)
                {
                    if (k == i || k == j) continue;
                    add_edge(k << 1, k << 1 | 1, 1);
                }
                size = q.size();
                for (k = 0; k < size; k++)
                {
                    u = q[k].first, v = q[k].second;
                    add_edge(u << 1 | 1, v << 1, INF);
                    add_edge(v << 1 | 1, u << 1, INF);
                }
                ans = min(ans, sap());
            }
        }
        if (ans > n) ans = n;
        printf("%d\n", ans);
    }
    system("pause");
    return 0;
}
