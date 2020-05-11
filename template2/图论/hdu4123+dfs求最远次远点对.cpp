#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define DEP 20
#define N 50005
using namespace std;

struct NODE
{
    int v, w;
    int next;
};

struct MAX
{
    int max1, max2;
    int p;
    void set(int x1, int x2, int x3)
    {
        max1 = x1, max2 = x2, p = x3;
    }
};

int n, m, e;
int head[N], log2[N];
int s_max[DEP][N], s_min[DEP][N];
NODE edge[N * 2];
MAX h[N];

int init()
{
    e = 0;
    memset(head, -1, sizeof(head));
    for (int i = 1; i <= n; i++) h[i].max1 =h[i].max2 = -1;
    return 1;
}

int add_edge(int u, int v, int w)
{
    edge[e].v = v;
    edge[e].w = w;
    edge[e].next = head[u];
    head[u] = e++;
    return 1;
}

int dfs1(int p, int f)
{
    int i, j, v, tmp, max1 = 0, max2 = 0, u;
    for (i = head[p]; i != -1; i = edge[i].next)
    {
        v = edge[i].v;
        if (v == f) continue;
        dfs1(v, p);
        tmp = h[v].max1 + edge[i].w;
        if (max1 <= tmp)
        {
            max2 = max1;
            max1 = tmp;
            u = v;
        }
        else if (max2 <= tmp) max2 = tmp;
    }
    h[p].set(max1, max2, u);
    return 1;
}

int dfs2(int p, int f, int w)
{
    int i, v, max1 = h[p].max1, max2 = h[p].max2, u = h[p].p;
    if (max1 <= w)
    {
        max2 = max1;
        max1 = w;
        u = 0;
    }
    else if (max2 <= w) max2 = w;
    s_max[0][p] = s_min[0][p] = max1;
    for (i = head[p]; i != -1; i = edge[i].next)
    {
        v = edge[i].v;
        if (v == f) continue;
        if (v == u) dfs2(v, p, max2 + edge[i].w);
        else dfs2(v, p, max1 + edge[i].w);
    }
    return 1;
}

int RMQ_Init()
{
     int i, j, t, m;
     m = log2[n];
     for (j = t = 1; j <= m; j++, t *= 2)
     {
         for (i = 1; i <= n - t; i++) s_max[j][i] = max(s_max[j - 1][i], s_max[j - 1][i + t]);
         for (i = n - t + 1; i <= n; i++) s_max[j][i] = s_max[j - 1][i];
     }
     for (j = t = 1; j <= m; j++, t *= 2)
     {
         for (i = 1; i <= n - t; i++) s_min[j][i] = min(s_min[j - 1][i], s_min[j - 1][i + t]);
         for (i = n - t + 1; i <= n; i++) s_min[j][i] = s_min[j - 1][i];
     }
     return 1;
}

int RMQ_Query(int i, int j)
{
     int x1, x2, m = log2[j - i];
     if(i == j) return 0;
     x1 = min(s_min[m][i], s_min[m][j - (1 << m) + 1]);
     x2 = max(s_max[m][i], s_max[m][j - (1 << m) + 1]);
     return x2 - x1;
}

int main()
{
    int i, j, u, v, w, ans, now;
    u = 1;
    for (i = 1; (1 << i) <= N; i++)
    {
        for (j = u; j < (1 << i); j++) log2[j] = i - 1;
        u = (1 << i);
    }
    for (j = u; j <= N; j++) log2[j] = i - 1;
    while (scanf("%d%d", &n, &m) != EOF && n && m)
    {
        init();
        for (i = 1; i < n; i++)
        {
            scanf("%d%d%d", &u, &v, &w);
            add_edge(u, v, w), add_edge(v, u, w);
        }
        dfs1(1, 0);
        dfs2(1, 0, 0);
        RMQ_Init();
        for (i = 1; i <= m; i++)
        {
            scanf("%d", &u);
            ans = 1, now = 1;
            for (j = 2; j <= n; j++)
            {
                while (RMQ_Query(now, j) > u) now++;
                ans = max(ans, j - now + 1);
            }
            printf("%d\n", ans);
        }
    }
    system("pause");
    return 0;
}
