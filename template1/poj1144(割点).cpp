# include <iostream>
# include <cstdio>
# include <vector>
# define MAX 101
using namespace std;

int n,cnt;
int dep[MAX],low[MAX],flag[MAX];
vector<int> map[MAX];

int DFS(int u)
{
    int i,v,num=0;
    dep[u]=++cnt;//cout<<u<<" "<<dep[u];system("pause");
    low[u]=dep[u];
    for (i=0;i<map[u].size();i++)
    {
        v=map[u][i];
        if (dep[v]==0)
        {
           DFS(v);
           num++;
           if (low[v]<low[u])
           low[u]=low[v];
           if (u!=1&&low[v]>=dep[u])
           flag[u]=1; 
           if (u==1&&num>1)
           flag[u]=1;         
        }
        else
        if (dep[v]<low[u])
        low[u]=dep[v];
    }
    return 1;
}

int main()
{
    int i,v,u,ans;
    while (scanf("%d",&n)!=EOF)
    {
        if (n==0)
        break;
        for (i=1;i<=n;i++)
        map[i].clear();
        for (i=1;i<=n;i++)
        {
            dep[i]=0;
            low[i]=0;
            flag[i]=0;
        }  
        while (scanf("%d",&u)!=EOF)
        {
            if (u==0)
            break;
            while (getchar()!='\n')
            {
                scanf("%d",&v);
                map[u].push_back(v);
                map[v].push_back(u);  
            }  
        }
        cnt=0;
        DFS(1);
        ans=0;
        for (i=1;i<=n;i++)
        if (flag[i])
        ans++;
        printf("%d\n",ans);
    }
    system("pause");
    return 1;
}
