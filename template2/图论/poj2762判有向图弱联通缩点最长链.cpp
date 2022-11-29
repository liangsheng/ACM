#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <stack>
#define pause cout << " press any key to continue...", cin >> ch
#define file_r(x) freopen(x, "r", stdin)
#define file_w(x) freopen(x, "w", stdout)
using namespace std;
int ch;

typedef pair<int, int> PAIR;

const int N = 1005, M = 6005;

struct NODE
{
    int u, v;
    int next;
};

int n, m, e, ct, scc;
int head[N], dfn[N], low[N], ins[N], sccf[N], vis[N], in[N];
NODE edge[M];
PAIR ed[M];
stack<int> s;

int init()
{
    memset(head, -1, sizeof(head));
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

bool get_ans()
{
    int i, j, k, v, cnt = 0, num, p;
    for (i = 1; i <= n; i++)
    {
        for (j = head[i]; j != -1; j = edge[j].next)
        {
            v = edge[j].v;
            if (sccf[i] != sccf[v]) ed[cnt++] = PAIR(sccf[i], sccf[v]);
        }
    }
    e = 0;
    memset(head, -1, sizeof(head));
    memset(in, 0, sizeof(in));
    for (i = 0; i < cnt; i++)
    {
        add_edge(ed[i].first, ed[i].second);
        in[ed[i].second]++;
    }
    memset(vis ,0, sizeof(vis));
    for (i = 0; i < scc; i++)
    {
        num = 0, p = -1;
        for (j = 1; j <= scc; j++)
            if (in[j] == 0 && vis[j] == 0) num++, p = j;
        if (num != 1) return 0;
        vis[p] = 1;
        for (k = head[p]; k != -1; k = edge[k].next)
            if (! vis[edge[k].v]) in[edge[k].v]--;
    }
    return 1;
}

int T;

int main()
{
    int i, j, u, v;
    bool ans;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d", &n, &m);
        init();
        for (i = 1; i <= m; i++)
        {
            scanf("%d%d", &u, &v);
            add_edge(u, v);
        }
        for (i = 1; i <= n; i++)
            if (dfn[i] == 0) Tarjan(i);
        ans = get_ans();;
        if (ans) puts("Yes");
        else puts("No");
    }
    return 0;
}
