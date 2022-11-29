# include <iostream>
# include <cstdio>
# include <cstring>
# include <stack>
# define N 105
using namespace std;

struct NODE
{
    int u, v, w;
    int next;   
};

int n, m, s, e = 0;
int head[N], dis[N], visit[N], num[N];
NODE edge[N];

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
    stack<int> q;
    memset(visit, 0, sizeof(visit));
    memset(num, 0, sizeof(num));
    for (i= 0; i < N; i++)
    dis[i] = 999999, visit[i] = 1;
    for (i = 0; i < n + 1; i++)
    q.push(i);     //先把所有点放进去,使被有所有点更新的机会 
    dis[s] = 0;
    q.push(s);
    while (!q.empty())
    {
        front = q.top(); 
        q.pop();
        visit[front] = 0;
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
                    if (++num[v] > n)  //还是最多被更新n次 
                    return 0;  
                }           
            }
        }
    }
    return 1;
}

int Bellman_Ford()
{
    int i, j, flag;
    memset(dis, 0, sizeof(dis));
    for (i = 0; i <= n; i++)     //n+1个点,就执行n+1次 
    {
        flag = 0;
        for (j = 0; j < e; j++)
        {
            if (dis[edge[j].u] + edge[j].w < dis[edge[j].v])
            {
                dis[edge[j].v] = dis[edge[j].u] + edge[j].w;
                flag = 1;             
            }
        }
        if (!flag)
        return 1;
    }
    return 0;
}

int main()
{
    int i, j, u, v, w, ans;
    char ch[5];
    while (scanf("%d", &n) != EOF && n)
    {
         memset(edge, 0, sizeof(edge));
         memset(head, -1, sizeof(head));
         scanf("%d", &m);
         e = 0;    //e记得0
         for (i = 1; i <= m; i++) 
         {
             scanf("%d%d%s%d", &u, &v, ch, &w);
             if (ch[0] == 'g')
             add_edge(u + v, u - 1, -w -1);
             else
             add_edge(u - 1, u + v, w - 1);
         }
         s = 0;
         ans = SPFA();
         if (ans) printf("lamentable kingdom\n");
         else printf("successful conspiracy\n");
    }
    system("pause");
    return 0;
}
