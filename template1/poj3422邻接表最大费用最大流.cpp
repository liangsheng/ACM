# include <iostream>
# include <cstdio>
# include <queue>
# include <cstring>
# define INF 999999
using namespace std;

struct NODE
{
    int u,v,flow,cost;
    int next;   
};

int n,k,s,t,cnt=0,e=0;
int map[51][51],id[51][51];
int head[6000],pre[6000],visit[6000],dis[6000];
NODE edge[30000];

int add_edge(int u,int v,int flow,int cost)
{
    edge[e].u=u;
    edge[e].v=v;
    edge[e].flow=flow;
    edge[e].cost=cost;
    edge[e].next=head[u];
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
    for (i=s;i<=t;i++)
    dis[i]=-INF;
    dis[s]=0;
    q.push(s);
    visit[s]=1;
    while (!q.empty())
    {
        front=q.front();
        visit[front]=0;
        for (i=head[front];i!=-1;i=edge[i].next)
        {
            k=edge[i].v;
            if (edge[i].flow>0&&dis[front]+edge[i].cost>dis[k])
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

int max_cost()
{
    int i,j,ans=0,mmin;
    while (1)
    {
        SPFA();
        if (pre[t]==-1)
        break;
        mmin=INF;
        for (i=t;i!=s;i=edge[pre[i]].u)
        if (edge[pre[i]].flow<mmin)
        mmin=edge[pre[i]].flow;
        for (i=t;i!=s;i=edge[pre[i]].u)
        {
            edge[pre[i]].flow-=mmin;
            edge[pre[i]^1].flow+=mmin;           
        }    
        ans+=dis[t]*mmin;
    }
    return ans;
}

int main()
{
    int i,j,temp,ans;
    scanf("%d%d",&n,&k);
    for (i=1;i<=n;i++)
    for (j=1;j<=n;j++)
    {
        scanf("%d",&map[i][j]);
        id[i][j]=++cnt;
    }
    s=0;
    t=cnt*2;
    memset(head,-1,sizeof(head));
    for (i=1;i<n;i++)
    {
        for (j=1;j<n;j++)
        {
            temp=id[i][j]+cnt;
            add_edge(temp,id[i+1][j],INF,0);
            add_edge(temp,id[i][j+1],INF,0);
        }
        add_edge(id[i][n]+cnt,id[i+1][n],INF,0);
        add_edge(id[n][i]+cnt,id[n][i+1],INF,0);
    }
    for (i=1;i<=n;i++)
    for (j=1;j<=n;j++)
    {
        add_edge(id[i][j],id[i][j]+cnt,1,map[i][j]);
        add_edge(id[i][j],id[i][j]+cnt,INF,0);
    }
    add_edge(s,id[1][1],k,0);
    ans=max_cost();
    printf("%d\n",ans);
    system("pause");
    return 1;
}
