# include <iostream>
# include <cstdio>
# include <memory.h>
using namespace std;

int n,m,sx,ey;
int map[101][101],able[101],used[101];

int check()
{
    int i,mmin=999999,point=-1;
    for (i=1;i<=n;i++)
    if (able[i]==0&&used[i]>0&&used[i]<mmin)
    {
        mmin=used[i];
        point=i;                                    
    }
    return point;
}

int dijkstra(int x,int y)
{
    int i,j,k;
    memset(able,0,sizeof(able));
    memset(used,0,sizeof(used));
    for (i=1;i<=n;i++)
    used[i]=map[1][i];
    able[1]=1;
    for (i=1;i<n;i++)
    {
        k=check();
        if (k==-1)
        return -1;
        able[k]=1;
        if (k==y)
        return used[k];
        for (j=1;j<=n;j++)
        if (able[j]==0&&(used[k]+map[k][j]<used[j]||used[j]==0))
        used[j]=used[k]+map[k][j];
    }
    return used[k];
}

int main()
{
    int i,j,x,y,v;
    memset(map,0,sizeof(map));
    scanf("%d %d",&n,&m);
    for (i=1;i<=n;i++)
    {
        for (j=1;j<=n;j++)
        scanf("%d",&map[i][j]);
        map[j][i]=map[i][j];
    }
    scanf("%d %d",&sx,&ey);
    int ans=dijkstra(sx,ey);
    printf("%d\n",ans);
    system("pause");
    return 1;
}
