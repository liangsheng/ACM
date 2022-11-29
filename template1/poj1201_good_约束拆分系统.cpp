#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>
#define N 50005
# define INF 20000000
using namespace std;

struct NODE
{
    int u, v, w;
    int next;   
};

int n, e = 0, s;
int head[N], dis[N], visit[N];
NODE edge[N * 4];

int add_edge(int u, int v, int w)
{
    edge[e].u = u;
    edge[e].v = v;
    edge[e].w = w;
    edge[e].next = head[u];
    head[u] = e++;
    return 1;
    
}

int SPFA()
{
    int i, k ,front, v;
    queue<int> q;
    memset(visit, 0, sizeof(visit));
    for (i= 0; i < N; i++)
    dis[i] = 999999;
    dis[s] = 0;
    q.push(s);
    visit[s] = 1;
    while (!q.empty())
    {
        front = q.front();
        visit[front]=0;
        for (i = head[front]; i != -1; i = edge[i].next)  
        {
            v = edge[i].v;
            if (dis[front] + edge[i].w < dis[v])
            {
                dis[v] = dis[front] + edge[i].w;
                if (! visit[v])
                {
                    visit[v] = 1;
                    q.push(v);  
                }           
            }
        }
        q.pop();
    }
    return 1;
}

int main()
{
    int i, j, u, v, w, mini = 999999, maxi = -1;
    scanf("%d", &n);
    memset(head, -1, sizeof(head));
    for (i = 1; i <= n; i++)
    {
        scanf("%d%d%d", &u, &v, &w);
        mini = min(mini, u + 1);
        maxi = max(maxi, v + 2);
        add_edge(v + 2, u + 1, -w);
    }
    for (i = mini; i < maxi; i++)
    {
        add_edge(i + 1, i, 0);
        add_edge(i, i + 1, 1);
        //add_edge(s, i, 0);
    }
    s = maxi;
    //add_edge(s, maxi, 0);
    SPFA();
    printf("%d\n", -dis[mini]);
    system("pause");
    return 0;
}

