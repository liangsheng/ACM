/*
满足所有下界的情况下，判断是否存在可行流，方法可以转化成上面无源汇上下界判断
方法。只要连一条T → S的边，流量为无穷，没有下界，那么原图就得到一个无源汇的循环流图。
接下来的事情一样：原图中的边的流量设成自由流量ci – bi。新建源点SS汇点TT，求Mi，连边。
然后求SS → TT最大流，判是否满流。
判定有解之后然后求最大流，信息都在上面求得的残留网络里面。满足所有下界时，
从s → t的流量为多少？后悔边s → t的边权！然后在残留网络中s → t可能还有些自由流没有流满，
再做一次s → t的最大流，所得到的最大流就是原问题的最大流(内含两部分：残留的自由流所得到的流+后悔边s → t)。
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 1380, M = 80000, INF = ~0U >> 2, DAY = 370, GIRL = 1005;

struct Node
{
    int v, w, next;
} edge[M];

int e, s, t, NN;
int head[N], pre[N], cur[N], dis[N], gap[N];

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

int n, m, ss, tt;
int in[N], out[N], high[DAY * GIRL], girl[N], day[N];

void init()
{
    //注意sap()函数求的是s到t的最大流,若还有其他源汇点请用ss,tt表示
    e = ss = 0, tt = n + m + 1, s = tt + 1, t = s + 1, NN = t + 1;
    memset(head, -1, sizeof(head));
}

int main()
{
    int i, j, c, v, w, id, sum, max_flow, total, low;
    while (scanf("%d%d", &n, &m) != EOF)
    {
        init();
        memset(in, 0, sizeof(in));
        memset(out, 0, sizeof(out));
        for (i = 1; i <= m; i++) scanf("%d", &girl[i]);
        total = 0;
        for (i = 1; i <= n; i++)
        {
            scanf("%d%d", &c, &day[i]);
            for (j = 1; j <= c; j++)
            {
                scanf("%d%d%d", &id, &low, &high[++total]);
                in[n + id + 1] += low;
                out[i] += low;
                add_edge(i, n + id + 1, high[total] - low);
            }
        }
        for (i = 1; i <= n; i++) add_edge(ss, i, day[i]);
        for (i = 1; i <= m; i++)
        {
            in[tt] += girl[i], out[n + i] += girl[i];
            add_edge(n + i, tt, INF);
        }
        add_edge(tt, ss, INF);
        sum = 0;
        for (i = ss; i <= tt; i++)
        {
            w = in[i] - out[i];
            if (w > 0) add_edge(s, i, w), sum += w;
            if (w < 0) add_edge(i, t, -w);
        }
        max_flow = sap();
        if (max_flow != sum)
        {
            printf("-1\n\n");
            continue;
        }
        for (i = head[s]; i != -1; i = edge[i].next)
        {
            v = edge[i].v;
            head[v] = edge[head[v]].next;
        }
        for (i = head[t]; i != -1; i = edge[i].next)
        {
            v = edge[i].v;
            head[v] = edge[head[v]].next;
        }
        s = 0, t = n + m + 1, NN = t + 1;
        max_flow = sap();
        printf("%d\n", max_flow);
        for (i = 1; i <= total; i++) printf("%d\n", high[i] - edge[i * 2 - 2].w);
        printf("\n");
    }
    return 0;
}
