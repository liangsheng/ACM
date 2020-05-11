#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>
#define N (1005 * 2)
#define M 4000005
using namespace std;

struct NODE
{
    int u, v;
    int next;       
};

struct Wedding
{
    int s, e, dt;       
};

int n, m, e, ct, scc;
int head[N], dfn[N], low[N], ins[N], sccf[N], ind[N], cf[N], col[N], path[N][N];
NODE edge[M];
Wedding tt[1005];
stack<int> s;

int Init()
{
    memset(head, -1, sizeof(head));
    memset(cf, -1, sizeof(cf));
    memset(edge, 0, sizeof(edge));
    memset(dfn, 0, sizeof(dfn));
    memset(low, 0, sizeof(low));
    memset(ins, 0, sizeof(ins));
    memset(sccf, 0, sizeof(sccf)); 
    memset(tt, 0, sizeof(tt));
    memset(ind, 0, sizeof(ind));
    memset(col, 0, sizeof(col));
    memset(path, 0, sizeof(path));
    e = 0;
    ct = 0;
    scc = 0;
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

int judge(int x, int y, int z)
{
    if (z == x) return 1;
    if ((z - x) * (z - y) < 0) return 1;
    return 0;
}

int add_edge(int u, int v)
{
    edge[e].u = u;
    edge[e].v = v;
    edge[e].next = head[u];
    head[u] = e++;
    return 1;
}

int Build_Map()
{
    int i, j;
    for (i = 1; i <= n; i++)
    {
        for (j = i + 1; j <= n; j++)
        {       
            if (judge(tt[j].s, tt[j].s + tt[j].dt, tt[i].s) || judge(tt[i].s, tt[i].s + tt[i].dt, tt[j].s))
                add_edge(i, j + n), add_edge(j, i + n);
            if (judge(tt[j].e - tt[j].dt, tt[j].e, tt[i].s) || judge(tt[i].s, tt[i].s + tt[i].dt, tt[j].e - tt[j].dt))
                add_edge(i, j), add_edge(j + n, i + n);       
            if (judge(tt[j].s, tt[j].s + tt[j].dt, tt[i].e - tt[i].dt) || judge(tt[i].e - tt[i].dt, tt[i].e, tt[j].s))
                add_edge(i + n, j + n), add_edge(j, i);
            if (judge(tt[j].e - tt[j].dt, tt[j].e, tt[i].e - tt[i].dt) || judge(tt[i].e - tt[i].dt, tt[i].e, tt[j].e - tt[j].dt))        
                add_edge(i + n, j), add_edge(j + n, i);
        }
    }
    return 1;
}

int topsort()
{
    int i, j, top, v;
    for (i = 1; i <= scc; i++)
        if (ind[i] == 0) s.push(i);
    while (! s.empty())
    {
        top = s.top();
        s.pop();
        if (! col[top])
        {
            col[top] = 1;
            col[cf[top]] = 2;  
        }   
        for (j = 1; j <= scc; j++)
        {
            if (j != top && path[top][j])
            {
                if (--ind[j] == 0)
                    s.push(j);  
            }
        }
    } 
    return 1;   
}

int sat()
{
    int i, j, v, s, t, flag = 1;
    for (i = 1; i <= 2 * n; i++)
    {
        if (dfn[i] == 0)
            Tarjan(i);
    } 
    for (i = 1; i <= n; i++)
    {
        if (sccf[i] == sccf[i + n])
        {
            flag = 0;
            break;        
        }
        cf[sccf[i]] = sccf[i + n];
        cf[sccf[i + n]] = sccf[i];
    }
    if (flag)
        printf("YES\n");
    else
        printf("NO\n");
    for (i = 1; i <= 2 * n; i++)
    {
        for (j = head[i]; j != -1; j = edge[j].next)
        {
            v = edge[j].v;
            if (sccf[i] != sccf[v])
                path[sccf[v]][sccf[i]] = 1;
        }
    } 
    for (i = 1; i <= scc; i++)
    {
        for (j = 1; j <= scc; j++)
        {
            if (path[i][j]) ind[j]++;
        }
    }
    topsort();
    for (i = 1; i <= n; i++)
    {
        if (col[sccf[i]] == 1)
            s = tt[i].s, t = tt[i].s + tt[i].dt;
        else s = tt[i].e - tt[i].dt, t = tt[i].e;
        if ((s / 60) < 10)
            printf("0");
        printf("%d:", s / 60);
        if ((s % 60) < 10)
            printf("0");
        printf("%d ", s % 60); 
        if ((t / 60) < 10)
            printf("0");
        printf("%d:", t / 60);
        if ((t % 60) < 10)
            printf("0");
        printf("%d\n", t % 60);                
    }
    return 1;     
}

int main()
{
    int i, t;  
    char s[20];
    scanf("%d", &n);
    Init();
    for (i = 1; i <= n; i++)
    {
        scanf("%s", &s);
        t = ((s[0] - '0') * 10 + s[1] - '0') * 60 + (s[3] - '0' ) * 10 + s[4] - '0';      
        tt[i].s = t;
        scanf("%s", &s);
        t = ((s[0] - '0') * 10 + s[1] - '0') * 60 + (s[3] - '0' ) * 10 + s[4] - '0';
        tt[i].e = t;
        scanf("%d", &tt[i].dt);               
    }
    Build_Map();
    sat();
    system("pause");
    return 0;
}
