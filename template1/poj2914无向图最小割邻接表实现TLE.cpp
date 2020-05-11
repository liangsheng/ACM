# include <iostream>
# include <cstdio>
# include <cstring>
# include <cmath>
# define N 505
# define M 250000
# define inf 999999
using namespace std;

struct NODE
{
    int u,v,w;
    int next;   
};

int n,m,e;
int head[N],last[N],dis[N],visit[N],die[N];
NODE edge[M];

int add_edge(int u,int v,int w)
{
    edge[e].u=u;
    edge[e].v=v;
    edge[e].w=w;
    edge[e].next=head[u];
    if (head[u]==-1)
    last[u]=e;
    head[u]=e++;   
}

int Stoer_Wagner()
{
    int i,j,t,k,v,pre,s,mmax,min_cut=inf;
    s=0;
    memset(die,0,sizeof(die));
    for (t=1;t<n;t++)
    {
        memset(dis,0,sizeof(dis));
        for (i=head[s];i!=-1;i=edge[i].next)
        dis[edge[i].v]+=edge[i].w;
        memset(visit,0,sizeof(visit));
        visit[s]=1;
        k=s;
        for (i=1;i<=n-t;i++)
        {
            mmax=-1;
            pre=k;
            k=-1;
            for (j=0;j<n;j++)
            if (!die[j]&&!visit[j]&&dis[j]>mmax)
            {
                k=j;
                mmax=dis[j];                                
            }
            if (k==-1) return 0;
            visit[k]=1;
            for (j=head[k];j!=-1;j=edge[j].next)
            {
                v=edge[j].v;
                if (!die[v]&&!visit[v])
                dis[v]+=edge[j].w;
            }
        }
        min_cut=min(min_cut,dis[k]);
        die[k]=1;
        for (i=head[k];i!=-1;i=edge[i].next)
        edge[i^1].v=pre;
        edge[last[pre]].next=head[k];
        last[pre]=last[k];            
    }
    return min_cut;
}

int main()
{
    int i,u,v,w,ans;
    while (scanf("%d%d",&n,&m)!=EOF)
    {
        memset(edge,0,sizeof(edge));
        memset(head,-1,sizeof(head));
        memset(last,-1,sizeof(last));
        e=0;
        while (m--)
        {
            scanf("%d%d%d",&u,&v,&w);
            add_edge(u,v,w);
            add_edge(v,u,w); 
        } 
        ans=Stoer_Wagner();
        printf("%d\n",ans);
    }
    system("pause");
    return 1;
}
