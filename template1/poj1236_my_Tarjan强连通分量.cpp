#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>
#include <cmath>
#define N 105
using namespace std;

struct NODE
{
    int u, v;
    int next;
};

int n, e, ct, scc;
int head[N], dfn[N], low[N], ins[N], sccf[N], indegree[N], outdegree[N];;
NODE edge[N *N *2];
stack<int> s;

int Init()
{
    memset(head, -1, sizeof(head));
    memset(edge, 0, sizeof(edge));
    memset(dfn, 0, sizeof(dfn));
    memset(low, 0, sizeof(low));
    memset(ins, 0, sizeof(ins));
    memset(sccf, 0, sizeof(sccf));
    memset(indegree, 0, sizeof(indegree));
    memset(outdegree, 0, sizeof(outdegree));     
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

int get_ans()
{
    int i, j, ind, outd, v;
    ind = outd = 0;
    for (i = 1; i <= n; i++)
    {
        for (j = head[i]; j != -1; j =edge[j].next)
        {
            v = edge[j].v;
            if (sccf[i] != sccf[v])
                indegree[sccf[v]]++, outdegree[sccf[i]]++;
        }
    }
    for (i = 1; i <= scc; i++)
    {
        if (indegree[i] == 0) ind++;
        if (outdegree[i] == 0) outd++;
    } 
    printf("%d\n%d\n", ind, max(ind, outd));
    return 1;
}

int main()
{
    int i, v;
    scanf("%d", &n);
    Init();
    for (i = 1; i <= n; i++)
    {
        while (scanf("%d", &v) && v != 0)
            add_edge(i, v);
    }
    for (i = 1; i <= n; i++)
    {
        if (dfn[i] == 0)
            Tarjan(i);
    }
    if (scc == 1)
        printf("1\n0\n");
    else
        get_ans();
    system("pause");
    return 0;
}
