# include <iostream>
# include <cstdio>
# include <cstring>
# include <cmath>
# define N 1005
# define M 2005
# define inf 999999
using namespace std;

struct NODE
{
    int u,v,w;
    int next;   
};

int n,m,e,s,t;
int dis[N],visit[N],head[N];
NODE edge[M*2];

int add_edge(int u,int v,int w)
{
    edge[e].u=u;
    edge[e].v=v;
    edge[e].w=w;
    edge[e].next=head[u];
    head[u]=e++;   
}

int Dijkstra()
{
    int i,k,l,v,mmin;
    memset(visit,0,sizeof(visit));
    for (i=1;i<=n;i++)
    dis[i]=inf;
    visit[s]=1;
    dis[s]=0;
    for (i=head[s];i!=-1;i=edge[i].next)
    dis[edge[i].v]=min(dis[edge[i].v],edge[i].w);
    for (l=1;l<n;l++)
    {
        mmin=999999;
        k=-1;
        for (i=1;i<=n;i++)
        if (!visit[i]&&dis[i]!=0&&dis[i]<mmin)
        {
            mmin=dis[i];
            k=i;                                  
        }
        if (k==-1) 
        break;
        if (k==t)
        return dis[t];
        visit[k]=1;
        for (i=head[k];i!=-1;i=edge[i].next)
        {
            v=edge[i].v;
            if (!visit[v]&&dis[v]>dis[k]+edge[i].w)
            dis[v]=dis[k]+edge[i].w;
        }
    }
    return -1;
}

int main()
{
    int i,u,v,w,ans;
    while (scanf("%d%d",&m,&n)!=EOF)
    {
        if (n==0&&m==0)
        break;
        e=0;
        memset(edge,0,sizeof(edge));
        memset(head,-1,sizeof(head));
        for (i=1;i<=m;i++)
        {
            scanf("%d%d%d",&u,&v,&w);
            add_edge(u,v,w);
            add_edge(v,u,w);
        }  
        s=1;
        t=n;
        ans=Dijkstra();
        printf("%d\n",ans);
    }
    system("pause");
    return 1;
}
