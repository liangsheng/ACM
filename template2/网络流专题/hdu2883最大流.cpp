/*
很巧的一道题目,附出题人的解题报告:
将所有的到达时间和结束时间按升序排序，得到 x <= 2n-1 个时间区间。
建立网络流模型：s为源，t为汇，每个顾客i作为一个结点并连边（s, i, ni*ti），
每个区间j作为一个结点并连边(j, t, (ej-sj)*M)，其中sj, ej分别表示区间j的起始时间和终止时间。
对任意顾客i和区间j，若 [sj, ej] 完全包含在 [si, ei] 之中，则连边(i, j, INF)。
若最大流等于 ∑ni*ti 则是 Yes，否则是 No。
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 650, M = 400005, INF = (~0U >> 1) >> 1;

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

const int NR = 205;

int n, m;
int si[NR], ni[NR], ei[NR], ti[NR], a[NR << 1];

void init(int cnt)
{
    e = s = 0, t = cnt + n, NN = t + 1;
    memset(head, -1, sizeof(head));
}

int main()
{
    int i, j, cnt, u, v, w, sum, ans;
    while (scanf("%d%d", &n, &m) != EOF)
    {
        cnt = sum = 0;
        for (i = 1; i <= n; i++)
        {
            scanf("%d%d%d%d", &si[i], &ni[i], &ei[i], &ti[i]);
            a[cnt++] = si[i], a[cnt++] = ei[i], sum += ni[i] * ti[i];
        }
        sort(a, a + cnt);
        cnt = unique(a, a + cnt) - a;
        init(cnt);
        for (i = 1; i < cnt; i++)
        {
            u = a[i - 1], v = a[i], w = (v - u) * m;
            add_edge(s, i, w);
            for (j = 1; j <= n; j++)
                if (si[j] <= u && ei[j] >= v) add_edge(i, cnt - 1 + j, INF);
        }
        for (i = 1; i <= n; i++) add_edge(i + cnt - 1, t, ni[i] * ti[i]);
        ans = sap();
        if (ans != sum) puts("No");
        else puts("Yes");
    }
    return 0;
}
