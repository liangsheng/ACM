# include <iostream>
# include <cstdio>
# include <queue>
# include <cmath>
# include <cstring>
# define MAX 55
# define MAX2 105
using namespace std;

int n,m,k,maxflow,mincost,s,t;
int myneed[MAX][MAX],myhave[MAX][MAX],thecost[MAX][MAX][MAX],total[MAX],need[MAX];
int myflow[MAX2][MAX2],flow[MAX2][MAX2],mycost[MAX2][MAX2],visit[MAX2],pre[MAX2],used[MAX2];

int init(int x)//第x种物品 
{
    int i,j;
    memset(myflow,0,sizeof(myflow));
    memset(mycost,0,sizeof(mycost));
    for (i=1;i<=m;i++)
    myflow[0][i]=myhave[i][x];
    for (i=m+1;i<=m+n;i++)
    myflow[i][n+m+1]=myneed[i-m][x];
    for (i=1;i<=m;i++)
    {
        for (j=m+1;j<=m+n;j++)
        {
            myflow[i][j]=myhave[i][x];
            mycost[i][j]=thecost[x][j-m][i];
            mycost[j][i]=-mycost[i][j];
        }
    }
    return 1;
}

int SPFA()
{
    int i,front;
    queue<int> q;
    memset(pre,-1,sizeof(pre));
    memset(visit,0,sizeof(visit));
    for (i=s;i<=t;i++)
    used[i]=999999;
    used[s]=0;
    q.push(s);
    while (!q.empty())
    {
        front=q.front();
        visit[front]=0;
        for (i=s;i<=t;i++)
        {
            if (myflow[front][i]>flow[front][i]&&used[i]>used[front]+mycost[front][i])
            {
               used[i]=used[front]+mycost[front][i];
               pre[i]=front;
               if (visit[i]==0)
               {
                  visit[i]=1;
                  q.push(i);             
               }                                                                         
            }
        }
        q.pop();  
    }
    return 1;
}

int min_cost()
{
    int i,ans=0,mmin;
    memset(flow,0,sizeof(flow));
    while (1)
    {
        SPFA();
        if (pre[t]==-1)
        break;
        mmin=999999;
        for (i=t;i!=s;i=pre[i])
        if (myflow[pre[i]][i]-flow[pre[i]][i]<mmin)
        mmin=myflow[pre[i]][i]-flow[pre[i]][i];
        for (i=t;i!=s;i=pre[i])
        {
            flow[pre[i]][i]+=mmin;
            flow[i][pre[i]]-=mmin;
        }
        maxflow+=mmin; 
        ans+=used[t]*mmin;
    }
    return ans;
}

int main()
{
    int i,j,l,ans,temp;
    while (scanf("%d %d %d",&n,&m,&k)!=EOF)
    {
        memset(total,0,sizeof(total));
        memset(need,0,sizeof(need));
        ans=0;
        s=0;
        t=m+n+1;
        if (n==0&&m==0&&k==0)
        break;
        for (i=1;i<=n;i++)
        {
            for (j=1;j<=k;j++)
            {
                scanf("%d",&myneed[i][j]);
                need[j]+=myneed[i][j];
            }
        }
        for (i=1;i<=m;i++)
        {
            for (j=1;j<=k;j++)
            {
                scanf("%d",&myhave[i][j]);
                total[j]+=myhave[i][j];
            } 
        }
        for (i=1;i<=k;i++)
        {
            for (j=1;j<=n;j++)
            {
                for (l=1;l<=m;l++)
                scanf("%d",&thecost[i][j][l]);//从l处把i商品送到j顾客 
            }
        }
        for (i=1;i<=k;i++)
        {
            if (total[i]<need[i])
            {
               ans=-1;
               printf("-1\n");
               break;                  
            }
        }
        if (ans==-1)
        continue;
        ans=0;
        for (i=1;i<=k;i++) //对每个商品mincost 
        {
            maxflow=0;
            init(i);
            ans+=min_cost();      
        }          
        printf("%d\n",ans);
    }
    system("pause");
    return 1;
}
