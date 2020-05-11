#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

const int N = 720001, M = 3000000, INF = ~0U >> 2;

struct NODE
{
    int u, v, flow, cost;
    int next;
};

int n;
int a[605][605];

int s, t, e;
int head[N], pre[N], visit[N], dis[N];
NODE edge[M];

int init()
{
    e = 0, s = 1, t = n * n * 2;
    memset(head, -1, sizeof(head));
    return 1;
}

int add_edge(int u, int v, int flow, int cost)
{
    edge[e].u = u;
    edge[e].v = v;
    edge[e].flow = flow;
    edge[e].cost = cost;
    edge[e].next = head[u];
    head[u]=e++;
    edge[e].u=v;
    edge[e].v=u;
    edge[e].flow=0;
    edge[e].cost=-cost;
    edge[e].next=head[v];
    head[v]=e++;
    return 1;
}

int SPFA()
{
    int i, k, front;
    queue<int> q;
    memset(pre, -1, sizeof(pre));
    memset(visit, 0, sizeof(visit));
    for (i = s; i <= t; i++) dis[i] = INF;
    dis[s] = 0;
    q.push(s);
    visit[s] = 1;
    while (!q.empty())
    {
        front = q.front();
        visit[front] = 0;
        for (i = head[front]; i != -1; i = edge[i].next)
        {
            k = edge[i].v;
            if (edge[i].flow > 0 && dis[front] + edge[i].cost < dis[k])
            {
                dis[k] = dis[front] + edge[i].cost;
                pre[k] = i;
                if (visit[k] == 0)
                {
                    visit[k] = 1;
                    q.push(k);
                }
            }
        }
        q.pop();
    }
    return 1;
}

int min_cost()
{
    int i, j, ans = 0, mmin;
    while (1)
    {
        SPFA();
        if (pre[t] == -1) break;
        mmin = INF;
        for (i = t; i != s; i = edge[pre[i]].u)
            if (edge[pre[i]].flow < mmin) mmin = edge[pre[i]].flow;
        for (i = t; i != s; i = edge[pre[i]].u)
        {
            edge[pre[i]].flow -= mmin;
            edge[pre[i] ^ 1].flow += mmin;
        }
        ans += dis[t]*mmin;
    }
    return ans;
}

int main()
{
    int i, j, u, v;
    while (scanf("%d", &n) != EOF)
    {
        init();
        for (i = 1; i <= n; i++)
            for (j = 1; j <= n; j++) scanf("%d", &a[i][j]);
        if (n == 1)
        {
            printf("%d\n", a[1][1]);
            continue;
        }
        for (i = 1; i <= n; i++)
            for (j = 1; j <= n; j++)
            {
                u = (i - 1) * n + j, v = u + n * n;
                if (u == 1 || u == n * n) add_edge(u, v, 2, -a[i][j]);
                else add_edge(u, v, 1, -a[i][j]);
                if (i + 1 <= n) add_edge(v, i * n + j, INF, 0);
                if (j + 1 <= n) add_edge(v, u + 1, INF, 0);
            }
        printf("%d\n", -1 * min_cost() - a[1][1] - a[n][n]);
    }
    return 0;
}
