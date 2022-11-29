#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#define inf (1 << 30)
#define mod 1000000007
#define N 110
#define M 5005
const double eps = 1e-12;
const double pi = acos(-1.0);
using namespace std;

struct NODE
{
    int u, v, flow, cost;
    int next;
};

int n, m, k, s, t, cnt = 0, e = 0, sum;
int head[N], pre[N], visit[N], dis[N];
NODE edge[M * 2 * 5];

int add_edge(int u, int v, int flow, int cost)
{
    edge[e].u = u;
    edge[e].v = v;
    edge[e].flow = flow;
    edge[e].cost = cost;
    edge[e].next = head[u];
    head[u]=e++;
    edge[e].u=v;
    edge[e].v=u;
    edge[e].flow=0;
    edge[e].cost=-cost;
    edge[e].next=head[v];
    head[v]=e++;
}

int SPFA()
{
    int i,k,front;
    queue<int> q;;
    memset(pre,-1,sizeof(pre));
    memset(visit,0,sizeof(visit));
    for (i=s; i<=t; i++)
        dis[i]=inf;
    dis[s]=0;
    q.push(s);
    visit[s]=1;
    while (!q.empty())
    {
        front=q.front();
        visit[front]=0;
        for (i=head[front]; i!=-1; i=edge[i].next)
        {
            k=edge[i].v;
            if (edge[i].flow>0&&dis[front]+edge[i].cost<dis[k])
            {
                dis[k]=dis[front]+edge[i].cost;
                pre[k]=i;
                if (visit[k]==0)
                {
                    visit[k]=1;
                    q.push(k);
                }
            }
        }
        q.pop();
    }
    return 1;
}

int min_cost()
{
    int i,j,ans=0,mmin, flow = 0;
    while (1)
    {
        SPFA();
        if (pre[t]==-1)
            break;
        mmin=inf;
        for (i=t; i!=s; i=edge[pre[i]].u)
            if (edge[pre[i]].flow<mmin)
                mmin=edge[pre[i]].flow;
        for (i=t; i!=s; i=edge[pre[i]].u)
        {
            edge[pre[i]].flow-=mmin;
            edge[pre[i]^1].flow+=mmin;
        }
        flow += mmin;
        ans+=dis[t]*mmin;
    }
    if (flow < k) return -1;
    else return ans;
}

int init()
{
    e = sum = 0, s = 0, t = n;
    memset(head, -1, sizeof(head));
    return 1;
}

int main()
{
    int i, j, u, v, a, c;
    while (scanf("%d%d%d", &n, &m, &k) != EOF)
    {
        init();
        for (i = 1; i <= m; i++)
        {
            scanf("%d%d%d%d", &u, &v, &a, &c);
            for (j = 1; j <= c; j++) add_edge(u, v, 1, (j * 2 - 1) * a);
        }
        add_edge(s, 1, k, 0);
        printf("%d\n", min_cost());
    }
    system("pause");
    return 0;
}
