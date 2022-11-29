# include <iostream>
# include <cstdio>
# include <cstring>
# include <vector>
# include <algorithm>
# define MAX 10010
using namespace std;

typedef pair<int,int> PAIR;

int test,n,m,cnt,num;
int low[MAX],dep[MAX],ans[MAX];
vector<PAIR> map[MAX];

int DFS(int parent,int u)
{//cout<<parent<<" "<<u;system("pause");
    int i,v,r;
    low[u]=++cnt,dep[u]=low[u];
    for (i=0;i<map[u].size();i++)
    {
        v=map[u][i].first,r=map[u][i].second;
        if (low[v]==0)
        {
           DFS(r,v);
           if (low[v]<low[u]) low[u]=low[v];//if (u==5){cout<<"asdfgfh"<<v;system("pause");}}
           if (low[v]>dep[u]) ans[++num]=r;//cout<<"zxcvbn"<<v<<" "<<u;system("pause");}
        }
        else
        if (r!=parent&&low[v]<low[u])
        low[u]=low[v];//if (u==5){cout<<"qwerty"<<v;system("pause");}}
    }
    return 1;
}

int main()
{
    int i,k,x,y;
    scanf("%d",&test);
    for (k=1;k<=test;k++)
    {
        scanf("%d%d",&n,&m);
        for (i=1;i<=n;i++)
        map[i].clear();
        for (i=1;i<=m;i++)
        {
            scanf("%d%d",&x,&y);
            map[x].push_back(PAIR(y,i));
            map[y].push_back(PAIR(x,i));
        }
        cnt=0,num=0;
        memset(low,0,sizeof(low));
        memset(dep,0,sizeof(dep));
        DFS(0,1);
        sort(ans+1,ans+num+1);
        //for (i=1;i<=n;i++)
        //cout<<low[i]<<" ";system("pause");
        printf("%d\n",num);
        if (num)
        {
           for (i=1;i<num;i++)
           printf("%d ",ans[i]);
           printf("%d\n",ans[num]);
        }
        if (k<test) printf("\n");
    }
    system("pause");
    return 1;
}
