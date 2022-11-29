# include <iostream>
# include <cstdio>
# include <queue>
# include <cstring>
# define N 1000005
# define inf 1000000050

using namespace std;

struct NODE
{
    int u,v,w;
    int next;    
};

int test,n,m,e,s;
int head[N],last[N],visit[N];
long long dis[N],sum;
NODE edge[N*2];

int SPFA()
{
    int i,front,v;
    queue<int> q;
    memset(visit,0,sizeof(visit));
    visit[s]=1;
    for (i=1;i<=n;i++)
    dis[i]=inf;
    dis[s]=0;
    q.push(s);
    while (!q.empty())
    {
        front=q.front();
        visit[front]=0;
        for (i=head[front];i!=-1;i=edge[i].next)  
        {
            v=edge[i].v;
            if (dis[front]+edge[i].w<dis[v])
            {
                dis[v]=dis[front]+edge[i].w;
                if (visit[v]==0)
                {
                    visit[v]=1;
                    q.push(v);            
                }                            
            }
        }
        q.pop();
    }
    return 1;
}

int SPFA2()
{
    int i,front,v;
    queue<int> q;
    memset(visit,0,sizeof(visit));
    visit[s]=1;
    for (i=1;i<=n;i++)
    dis[i]=inf;
    dis[s]=0;
    q.push(s);
    while (!q.empty())
    {
        front=q.front();
        visit[front]=0;
        for (i=last[front];i!=-1;i=edge[i].next)  
        {
            v=edge[i].v;
            if (dis[front]+edge[i].w<dis[v])
            {
                dis[v]=dis[front]+edge[i].w;
                if (visit[v]==0)
                {
                    visit[v]=1;
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
    int i,u,v,w,q;
    scanf("%d",&test);
    while (test--)
    {
        memset(edge,0,sizeof(edge));
        memset(head,-1,sizeof(head));
        memset(last,-1,sizeof(last));
        e=0;
        s=1;
        sum=0;
        q=1;
        scanf("%d%d",&n,&m);
        for (i=1;i<=m;i++)
        {
            scanf("%d%d%d",&u,&v,&w);
            edge[e].u=u;
            edge[e].v=v;
            edge[e].w=w;
            edge[e].next=head[u];
            head[u]=e++;
            //another line
            edge[e].u=v;
            edge[e].v=u;
            edge[e].w=w;
            edge[e].next=last[v]; 
            last[v]=e++;         
        } 
        SPFA();
        for (i=1;i<=n;i++)
        if (dis[i]!=inf)
        sum+=dis[i];
        else
        {
            q=0;
            break;
        }
        if (q)
        {
            SPFA2();
            for (i=1;i<=n;i++)
            if (dis[i]!=inf)
            sum+=dis[i];
            else
            {
                q=0;
                break;
            }  
        }
        if (q)
        printf("%lld\n",sum);
        else
        printf("!!!!\n");
    }
    system("pause");
    return 1;
}
