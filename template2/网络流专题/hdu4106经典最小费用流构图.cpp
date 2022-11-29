/*
POJ3680加强版
如果两个区间没有交集，那么代表它们的边可以出现在同一增广路上，这一点显然。
否则，它们就在不同的增广路上.
对于每次选取的增广路中总存在一个区间，在每次增广所得区间都与这个区间有交集
否则,对于此增广路中的每一个区间,必然存在另一条路,可以将这个区间插进去.
对于每一种方案,我们必然可以在图中表示出来,并且用上述方式可以保持最多只有k条路。
若此时已经到达了最大流,这求出的答案就是最小费用;若没到达最大流,这也不可能增加区间,
增加必然是费用为0的边,不影响最终答案.
对于此题
poj 3680 是区间对点的限制，而这道题，是点对区间的限制。如果选取取一个数，那么每个包含这个数且长度为 M的连续区间内可以选的数都要减少一个，对吧？
转换模型！点变区间，区间变点！注意是开区间!!!
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

const int N = 1005, M = 2005, INF = ~0U >> 2;

struct NODE
{
    int u, v, flow, cost;
    int next;
};

int n, m, k;
int a[N];

int s, t, e;
int head[N], pre[N], visit[N], dis[N];
NODE edge[M << 1];

int init()
{
    e = 0, s = 0, t = n - m + 3;
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
    int i, j, y1, y2, sum;
    while (scanf("%d%d%d", &n, &m, &k) != EOF)
    {
        init();
        sum = 0;
        for (i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
            sum += a[i];
        }
        if (m == k)
        {
            printf("%d\n", sum);
            continue;
        }
        for (i = s; i < t; i++) add_edge(i, i + 1, k, 0);
        for (i = 1; i <= n; i++)
        {
            y1 = i - m + 1;
            if (y1 < 1) y1 = 1;
            y2 = i;
            if (y2 > n - m + 1) y2 = n - m + 1;
            add_edge(y1, ++y2, 1, -a[i]);
        }
        printf("%d\n", -1 * min_cost());
    }
    return 0;
}
