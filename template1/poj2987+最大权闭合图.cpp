/* 
 * File:   poj2987.cpp
 * Author: peach
 *
 * Created on 2011年4月13日, 上午10:00
 */

#include <iostream>
#include <cstdio>
#include <cstring>
#define N 5005
#define M 60005
#define INF 1 << 30
using namespace std;

struct NODE
{
    int u, v , w;
    int next;
};

int n, m, s, t, e = 0;
int head[N], pre[N], dis[N], cur[N], gap[N], is_f[N];
NODE edge[M*2];

int add_edge(int u, int v, int w)
{
    edge[e].u = u;
    edge[e].v = v;
    edge[e].w = w;
    edge[e].next = head[u];
    head[u] = e++;
    edge[e].u = v;
    edge[e].v = u;
    edge[e].w = 0;
    edge[e].next = head[v];
    head[v] = e++;
    return 1;
}

long long SAP()
{
    int i, v, mindis;
    long long flow = 0,aug = INF, u;
    bool flag;
    for (i = s; i <= t; i++)
    {
        cur[i] = head[i];
        gap[i] = dis[i] =0;
    }
    gap[s] = n + 2;
    u = pre[s] = s;
    while (dis[s] < n + 2)
    {
        flag = 0;
        for (int & j = cur[u]; j != -1; j = edge[j].next)
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
        if (flag)
            continue;
        mindis = n + 2;
        for (int j = head[u]; j != -1; j = edge[j].next)
        {
            v = edge[j].v;
            if (edge[j].w > 0 && dis[v] < mindis)
            {
                mindis = dis[v];
                cur[u] = j;
            }
        }
        if ((--gap[dis[u]]) == 0)
            break;
        gap[dis[u] = mindis + 1]++;
        u = pre[u];
    }
    return flow;
}

int DFS(int u)
{
    int i;
    if (u == t) return 1;
    is_f[u] = 1;
    for (i = head[u]; i != -1; i = edge[i].next)
    {
        if (edge[i].w > 0 && ! is_f[edge[i].v])
            DFS(edge[i].v);
    }
    return 1;
}

int main(int argc, char** argv)
{
    int i, u, v, value, num = 0;
    long long sum = 0, ans;
    memset(head, -1, sizeof(head));
    memset(edge, 0, sizeof(edge));
    scanf("%d%d", &n, &m);
    s = 0;
    t = n + 1;
    for (i = 1; i <= n; i++)
    {
        scanf("%d", &value);
        if (value <= 0)
            add_edge(i, t, -value);
        else
        {
            add_edge(s, i, value);
            sum += value;
        }
    }
    for (i = 1; i <= m; i++)
    {
        scanf("%d%d", &u, &v);
        add_edge(u, v, INF);
    }
    ans = sum - SAP();
    memset(is_f, 0, sizeof(is_f));
    DFS(s);
    for (i = 1; i <= n; i++)
        if (is_f[i]) num++;
    cout << num << " " << ans << endl;
    cout << "it is the end!!" << endl;
    return 0;
}

