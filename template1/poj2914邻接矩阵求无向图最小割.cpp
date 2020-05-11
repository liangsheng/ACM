# include <iostream>
# include <cstdio>
# include <cstring>
# include <cmath>
# define N 505
# define inf 999999
using namespace std;

int n,m;
int map[N][N],dis[N],visit[N],die[N];

int Stoer_Wagner()
{
    int i,j,t,k,pre,s,mmax,min_cut=inf;
    s=1;
    memset(die,0,sizeof(die));
    for (t=1;t<n;t++)
    {
        memset(dis,0,sizeof(dis));
        for (i=1;i<=n;i++)
        if (!die[i])
        dis[i]=map[s][i];
        memset(visit,0,sizeof(visit));
        visit[s]=1;
        k=s;
        for (i=1;i<=n-t;i++)
        {
            mmax=-1;
            pre=k;
            k=0;
            for (j=1;j<=n;j++)
            if (!die[j]&&!visit[j]&&dis[j]>mmax)
            {
                k=j;
                mmax=dis[j];                                
            }
            if (!k) return 0;
            visit[k]=1;
            for (j=1;j<=n;j++)
            if (!die[j]&&!visit[j])
            dis[j]+=map[k][j];
        }
        min_cut=min(min_cut,dis[k]);
        die[k]=1;
        for (i=1;i<=n;i++)
        if (!die[i]&&i!=pre)
        {
            map[pre][i]+=map[k][i];
            map[i][pre]=map[pre][i];                
        }
    }
    return min_cut;
}

int main()
{
    int i,u,v,w,ans;
    while (scanf("%d%d",&n,&m)!=EOF)
    {
        memset(map,0,sizeof(map));
        while (m--)
        {
            scanf("%d%d%d",&u,&v,&w);
            map[u+1][v+1]+=w;
            map[v+1][u+1]=map[u+1][v+1];  
        } 
        ans=Stoer_Wagner();
        printf("%d\n",ans);
    }
    system("pause");
    return 1;
}
