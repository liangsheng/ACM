#include <iostream>
#include <cstdio>
#include <cstring>
#define N 250
#define INF 1 << 29
using namespace std;

struct NODE
{
    int u, v, w;
    int next;   
};
       
int test, n, m, c, e, s, t, vs, vt, vn, flag;
int dis[N], row[N], col[N], head[N], d[N], cur[N], pre[N], gap[N];
int low[N][N], up[N][N], f[N][N];
NODE edge[100000];

int Init()
{
    int i, j;
    e = 0;
    flag = 1;
    s = 0;
    t = n + m + 1;
    vs = t + 1;
    vt = vs + 1;
    vn = vt + 1;
    for (i = 1; i <= m; i++)
    {
        for (j = 1; j <= n; j++)
            low[i][j] = 0, up[i][j] = INF;
    }
    return 1;
}

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

int set_flow(int u, int v, char cmd, int w)
{
    if (cmd == '=')
    {
        if (low[u][v] > w || up[u][v] < w)
        {
            flag = 0;
            return 0;          
        }
        low[u][v] = up[u][v] = w;    
    }
    if (cmd == '>')
        low[u][v] = low[u][v] > w + 1 ? low[u][v] : w + 1;
    if (cmd == '<')
        up[u][v] = up[u][v] < w - 1 ? up[u][v] : w - 1;
    if (low[u][v] > up[u][v])
    {
        flag = 0;
        return 0;          
    }   
    return 1;
}

int SAP(int s, int t, int num)
{
    int u, v, i, flow = 0, aug = INF, flag;
    for (i = 0; i <= num; i++)
    {
        cur[i] = head[i];
        gap[i] = dis[i] = 0;
    }
    gap[0] = num;
    pre[s] = u = s;
    while (dis[s] < num)
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
                        f[pre[u]][u] += aug;
                        f[u][pre[u]] -= aug;
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
        int mindis = num;
        for (int j = head[u]; j != -1; j = edge[j].next)
        {
            v = edge[j].v;
            if (edge[j].w > 0 && dis[v] < mindis)
            {
                mindis = dis[v];
                cur[u] = j;          
            }
        }
        if (--gap[dis[u]] == 0) break;
        gap[dis[u] = mindis + 1]++;
        u = pre[u]; 
    }
    return flow;
}

int solve()
{
    int i, j, can = 1;
    memset(head, -1, sizeof(head));
    memset(d, 0, sizeof(d));
    for (i = 1; i <= m; i++)
    {
        for (j = 1; j <= n; j++)
        {
            add_edge(i, j + m, up[i][j] - low[i][j]);
            d[i] -= low[i][j];
            d[j + m] += low[i][j];
        }
    } 
    for (i = 1; i <= m; i++)
    {
        add_edge(s, i, 0);
        d[s] -= row[i];
        d[i] += row[i];
    } 
    for (i = 1; i <= n; i++)
    {
        add_edge(i + m, t, 0);
        d[t] += col[i];
        d[i + m] -= col[i];
    }
    add_edge(t, s, INF);
    for (i = 0; i <= m + n + 1; i++)
    {
        if (d[i] > 0) 
            add_edge(vs, i, d[i]);
        else if (d[i] < 0)
            add_edge(i, vt, -d[i]);
    }
    memset(f, 0, sizeof(f));
    SAP(vs, vt, m + n + 4);
    for (i = head[vs]; i != -1; i = edge[i].next)
    {
        if ((i % 2 == 0) && edge[i].w)
        {
            can = 0;
            break;   
        }
    }
    if (! can)
    {
        printf("IMPOSSIBLE\n");
        return 0;  
    }
    for (i = 1; i <= m; i++)
    {
        for (j = 1; j <= n; j++)
        {
            printf("%d", low[i][j] + f[i][j + m]);
            if (j != n) printf(" ");
        }
        printf("\n");
    }
    return 1;
}

int main()
{
    int i, j, u, v, w;
    char cmd;
    scanf("%d", &test);
    while (test--)
    {
        scanf("%d%d", &m, &n);
        Init();
        for (i = 1; i <= m; i++)
            scanf("%d", &row[i]); 
        for (i = 1; i <= n; i++)
            scanf("%d", &col[i]);
        scanf("%d", &c);
        while (c--)
        {
            scanf("%d%d", &u, &v);
            cin >> cmd;
            scanf("%d", &w);
            if ((! u) && (! v))
            {
                for (i = 1; i <= m; i++)
                {
                    for (j = 1; j <= n; j++)
                        set_flow(i, j, cmd, w);
                }                  
            } 
            if ((! u) && v)
            {
                for (i = 1; i <= m; i++)
                    set_flow(i, v, cmd, w);   
            } 
            if (u && (! v))
            {
                for (i = 1; i <= n; i++)
                    set_flow(u, i, cmd, w);  
            }
            if (u && v)
                set_flow(u, v, cmd, w);
        }
        if (! flag)
            printf("IMPOSSIBLE\n");
        else 
            solve();
        printf("\n");
    }
    system("pause");
    return 0;
}
