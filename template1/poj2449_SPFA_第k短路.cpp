#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>
#include <algorithm>
#define M 100005
#define N 1005
#define INF 1 << 29
using namespace std;

struct EDGE
{
    int u, v, w;
    int next, next2;   
};

struct NODE
{
    int id, fi, gi;  
    friend bool operator < (NODE x, NODE y)
    {
        if (x.gi != y.gi) return x.gi > y.gi;
        return x.fi < y.fi;   
    }
};
       
int n, m, e, s, t, kth;
int head[N], head2[N], dis[N], visit[N];
EDGE edge[M];
NODE p[2000005];

int add_edge(int u, int v, int w)
{
    edge[e].u = u;
    edge[e].v = v;
    edge[e].w = w;
    edge[e].next2 = head2[v];
    head2[v] = e;    
    edge[e].next = head[u];
    head[u] = e++;
    return 1;    
}

int SPFA()
{
    int i, front, u;
    queue<int> q;
    for (i = 1; i <= n; i++)
    {
        dis[i] = INF;
        visit[i] = 0;
    }
    dis[t] = 0;
    visit[t] = 1;
    q.push(t);
    while (! q.empty())
    {
        front = q.front();
        visit[front] = 0;
        for (i = head2[front]; i != -1; i = edge[i].next2)
        {
            u = edge[i].u;
            if (dis[front] + edge[i].w < dis[u])
            {
                dis[u] = dis[front] + edge[i].w;
                if (! visit[u])
                {
                    visit[u] = 1;
                    q.push(u);  
                }           
            }
        }
        q.pop(); 
    }
    return 1;
}

int solve()
{
    int i, j, id, fi, gi, cnt = 0, ct = 0;
    if (dis[s] == INF) return -1;
    p[ct].id = s;
    p[ct].fi = 0;
    p[ct++].gi = dis[s];
    while (ct)
    {
        id = p[0].id;
        fi = p[0].fi;
        gi = p[0].gi;
        if (id == t) cnt++;
        if (cnt == kth) return fi;
        pop_heap(p, p + ct);
        ct--;
        for (i = head[id]; i != -1; i = edge[i].next)
        {
            p[ct].id = edge[i].v;
            p[ct].fi = fi + edge[i].w;
            p[ct++].gi = p[ct].fi + dis[edge[i].v];
            push_heap(p, p + ct);
        }  
    }
    return -1;
}

int main()
{
    int i, u, v, w, ans;
    scanf("%d%d", &n, &m);
    memset(head, -1, sizeof(head));
    memset(head2, -1, sizeof(head2));
    memset(edge, 0, sizeof(edge));
    memset(p, 0, sizeof(p));
    e = 0;
    for (i = 1; i <= m; i++)
    {
        scanf("%d%d%d", &u, &v, &w);
        add_edge(u, v, w);
    }
    scanf("%d%d%d", &s, &t, &kth);
    if (s == t) kth++;
    SPFA();
    ans = solve();
    printf("%d\n", ans);
    system("pause");
    return 0;
}
