# include <iostream>
# include <cstdio>
# include <memory.h>
# include <cmath>
# define N 101
using namespace std;

int n;
int map[N][N];
int x[N],y[N],match[N],lx[N],ly[N];

int init()
{
    memset(map,0,sizeof(map));
    memset(match,-1,sizeof(match));
    return 1;
}

int make()
{
    int i,j;
    memset(lx,0,sizeof(lx));
    memset(ly,0,sizeof(ly));
    for (i=1;i<=n;i++)
    {
        for (j=1;j<=n;j++)
        lx[i]=max(lx[i],map[i][j]);
    }
    return 1;
}

int Find(int a)
{
    int i;
    x[a]=1;
    for (i=1;i<=n;i++)
    {
        if (y[i]==0&&lx[a]+ly[i]==map[a][i])
        {
           y[i]=1;
           if (match[i]==-1||Find(match[i]))
           {
              match[i]=a;
              return 1;
           }
        }
    }
    return 0;
}

int Kuhn_Munkers()
{
    int i,j,k,d;
    int ans=0;
    for (i=1;i<=n;i++)
    {
        while (1)
        {
            memset(x,0,sizeof(x));
            memset(y,0,sizeof(y));
            if (Find(i))
            break;
            d=999999;
            for (k=1;k<=n;k++)
            {
                if (x[k]==1)
                for (j=1;j<=n;j++)
                {
                    if (y[j]==0)
                    d=min(d,lx[k]+ly[j]-map[k][j]);
                }
            }
            if (d==999999)
            break;
            for (j=1;j<=n;j++)
            {
                if (x[j]==1) lx[j]-=d;
                if (y[j]==1) ly[j]+=d;
            }
        }
    }
    for (i=1;i<=n;i++)
    if (match[i]!=-1)
    ans+=map[match[i]][i];
    return ans;
}

int main()
{
    int i,j,ans;
    scanf("%d",&n);
    init();
    for (i=1;i<=n;i++)
    {
        for (j=1;j<=n;j++)
        scanf("%d",&map[i][j]);
    }
    make();
    ans=Kuhn_Munkers();
    printf("%d\n",ans);
    system("pause");
    return 1;
}
