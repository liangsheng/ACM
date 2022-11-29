#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <stack>
#include <algorithm>
#define N (505 * 2)
#define M 500000
using namespace std;

struct NODE
{
    int u, v;
    int next;   
};

int n, m, e, ct, scc;
int head[N], dfn[N], low[N], ins[N], sccf[N], ee[505][2];
NODE edge[M];
stack<int> s;

int Init()
{
    memset(head, -1, sizeof(head));
    memset(edge, 0, sizeof(edge));
    memset(dfn, 0, sizeof(dfn));
    memset(low, 0, sizeof(low));
    memset(ins, 0, sizeof(ins));
    memset(sccf, 0, sizeof(sccf));
    memset(ee, 0, sizeof(ee));   
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

int sat()
{
    int i, flag = 1;
    for (i = 1; i <= 2 * m; i++)
    {
        if (dfn[i] == 0)
            Tarjan(i);
    } 
    for (i = 1; i <= m; i++)
    {
        if (sccf[i] == sccf[i + m])
        {
            flag = 0;
            break;        
        }
    }
    if (flag)
        printf("panda is telling the truth...\n");
    else
        printf("the evil panda is lying again\n");  
    return 1;   
}

int main()
{
    int i, j;
    scanf("%d%d", &n, &m);
    Init();
    for (i = 1; i <= m; i++)
    {
        scanf("%d%d", &ee[i][0], &ee[i][1]);
        if (ee[i][0] > ee[i][1]) swap(ee[i][0], ee[i][1]);
    }
    for (i = 1; i <= m; i++)
    {
        for (j = i + 1; j <= m; j++)
        {
            if ((ee[i][0] < ee[j][0] && ee[i][1] < ee[j][1] && ee[j][0] < ee[i][1])
            || (ee[i][0] > ee[j][0] && ee[i][1] > ee[j][1] && ee[j][1] > ee[i][0]))
            {
                add_edge(i, j + m);
                add_edge(i + m, j);
                add_edge(j, i + m);
                add_edge(j + m, i);
            }
        }
    }
    sat();
    system("pause");
    return 0;
}
