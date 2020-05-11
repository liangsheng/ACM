#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
const int N=20010;
int NN;
const int MAXE=200010;
const int inf=1<<30;
int head[N];
struct Edge
{
    int v,next,w;
}edge[MAXE*8];
int cnt,n,m,s,t;
void addedge(int u,int v,int w)
{
    edge[cnt].v=v;
    edge[cnt].w=w;
    edge[cnt].next=head[u];
    head[u]=cnt++;
    edge[cnt].v=u;
    edge[cnt].w=0;
    edge[cnt].next=head[v];
    head[v]=cnt++;
}
int sap()
{
    int pre[N],cur[N],dis[N],gap[N];
    int flow=0,aug=inf,u;
    bool flag;
    for(int i=0;i<=NN;i++)
    {
        cur[i]=head[i];
        gap[i]=dis[i]=0;
    }
    gap[0]=NN;
    u=pre[s]=s;
    while(dis[s]<NN)
    {
        flag=0;
        for(int &j=cur[u];j!=-1;j=edge[j].next)  
        {
            int v=edge[j].v;
            if(edge[j].w>0&&dis[u]==dis[v]+1)
            {
                flag=1;
                if(edge[j].w<aug) aug=edge[j].w;
                pre[v]=u;
                u=v;
                if(u==t)
                {
                    flow+=aug;
                    while(u!=s)
                    {
                        u=pre[u];
                        edge[cur[u]].w-=aug;
                        edge[cur[u]^1].w+=aug;
                    }
                    aug=inf;
                }
                break;
            }
        }
        if(flag)
            continue;
        int mindis=NN;
        for(int j=head[u];j!=-1;j=edge[j].next)
        {
            int v=edge[j].v;
            if(edge[j].w>0&&dis[v]<mindis)
            {
              mindis=dis[v];
              cur[u]=j;
            }
        }
        if((--gap[dis[u]])==0)
            break;
        gap[dis[u]=mindis+1]++;
        u=pre[u];
    }
    return flow;
}
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        s=0;t=n+1;cnt=0;
        memset(head,-1,sizeof(head));
        int a,b,c;
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d",&a,&b);
            addedge(s,i,a);
            addedge(i,t,b);
        }
        for(int i=1;i<=m;i++)
        {
            scanf("%d%d%d",&a,&b,&c);
            addedge(a,b,c);
            addedge(b,a,c);
        }
        int ans=0;
               NN=n+2;
        ans=sap();
        system("pause");
        printf("%d\n",ans);
    }
}
