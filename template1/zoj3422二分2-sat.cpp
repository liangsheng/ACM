#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <stack>
#include <algorithm>
#define N 405
#define M 10005
using namespace std;

struct NODE
{
    int u, v;
    int next;
};

int T, n, m, e, ct, scc;;
int a[M], b[M], c[M];
int head[N], dfn[N], low[N], ins[N], sccf[N];
NODE edge[N * N];
stack<int> s;

int init()
{
    memset(head, -1, sizeof(head));
    memset(edge, 0, sizeof(edge));
    memset(dfn, 0, sizeof(dfn));
    memset(low, 0, sizeof(low));
    memset(ins, 0, sizeof(ins));
    memset(sccf, 0, sizeof(sccf));
    e = 0;
    ct = 0;
    scc = 0;
    return 1;
}

int add_edge(int u, int v)
{
    edge[e].u = u;
    edge[e].v = v;
    edge[e].next = head[u];
    head[u] = e++;
    return 1;
}

int Tarjan(int u)
{
    int i, v;
    low[u] = dfn[u] = ++ct;
    s.push(u);
    ins[u] = 1;
    for (i = head[u]; i != -1; i = edge[i].next)
    {
        v = edge[i].v;
        if (dfn[v] == 0)
        {
            Tarjan(v);
            low[u] = low[u] < low[v] ? low[u] : low[v];
        }
        else if (ins[v] && dfn[v] < low[u]) low[u] = dfn[v];
    }
    if (low[u] == dfn[u])
    {
        scc++;
        do
        {
            v = s.top();
            s.pop();
            ins[v] = 0;
            sccf[v] = scc;
        }  while(u != v);
    }
    return 1;
}

int solve(int mid)
{
    int i, j, x1, x2, x3, flag = 1;
    for (i = 0; i < mid; i++)
    {
        x1 = a[i], x2 = b[i], x3 = c[i];
        if (c[i] == 0)
        {
            add_edge(x1 * 2, x2 * 2 + 1);
            if (x1 != x2) add_edge(x2 * 2, x1 * 2 + 1);
        }
        else if (c[i] == 2)
        {
            add_edge(x1 * 2 + 1, x2 * 2);
            if (x1 != x2) add_edge(x2 * 2 + 1, x1 * 2);
        }
        else if (c[i] == 1)
        {
            if (x1 == x2) continue;
            add_edge(x1 * 2, x2 * 2);
            add_edge(x2 * 2, x1 * 2);
            add_edge(x1 * 2 + 1, x2 * 2 + 1);
            add_edge(x2 * 2 + 1, x1 * 2 + 1);
        }
    }
    for (i = 0; i < 2 * n; i++)
    {
        if (dfn[i] == 0)
            Tarjan(i);
    }
    for (i = 1; i < 2 * n; i += 2)
    {
        if (sccf[i] == sccf[i - 1])
        {
            flag = 0;
            break;
        }
    }
    return flag;
}

int main()
{
    int i, j, low, high, mid;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d", &n, &m);
        for (i = 0;i < m; i++) scanf("%d%d%d", &a[i], &b[i], &c[i]);
        low = 1, high = m;
        while (low < high)
        {
            mid = (low + high + 1) >> 1;
            init();
            if (solve(mid)) low = mid;
            else high = mid - 1;
        }
        printf("%d\n", low);
    }
    system("pause");
    return 0;
}
