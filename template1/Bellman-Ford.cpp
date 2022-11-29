# include <iostream>
# include <cstdio>
# include <vector>
# include <memory.h>
using namespace std;
#define N 1100
#define MAX 10000000
struct node
{
    int w,len,next;
    node(int a,int b,int c)
    {
        next=a;
        len=b;
        w=c;
    }
};
vector<node> g[N],e[N];
vector<int> ef[N];
int able[N],minl[N],minw[N];
int n,m,st,se;
int min(int a,int b)
{
    if (a<=b) return a;
    return b;
}
void read()
{
    int i;
    int u,v,fuv,fvu,l;
    char ch;
    for (i=0; i<n; i++)
    {
        g[i].clear();
        e[i].clear();
        ef[i].clear();
    }
    for (i=1; i<=m; i++)
    {
        scanf(" %c%d%c%d%c%d%c%d%c%d%c", &ch, &u, &ch, &v, &ch, &fuv, &ch, &l, &ch, &fvu, &ch);
        node temp1(v,l,fuv),temp2(u,l,fvu);
        g[u].push_back(temp1);
        g[v].push_back(temp2);
    }
}
void build()
{
    int i,j,mmin;
    for (i=0; i<n; i++)
    {
        mmin=MAX;
        for (j=0; j<g[i].size(); j++)
            mmin=min(mmin,g[i][j].w);
        for (j=0; j<g[i].size(); j++)
            if (g[i][j].w==mmin)
            {
                e[i].push_back(g[i][j]);
                ef[g[i][j].next].push_back(i);
            }
    }
}
void dfs1(int x)
{
    able[x]=1;
    int i;
    for (i=0; i<e[x].size(); i++)
        if (able[e[x][i].next]==0) dfs1(e[x][i].next);
}
void dfs2(int x)
{
    able[x]=1;
    int i;
    for (i=0; i<ef[x].size(); i++)
        if (able[ef[x][i]]==0) dfs2(ef[x][i]);
}
int bellman_ford()
{
    int i,f,k,j;
    for (i=0; i<n; i++)
    {
        minl[i]=MAX;
        minw[i]=MAX;
    }
    minl[st]=0;
    minw[st]=0;
    for (k=0; k<=n; k++)
    {
        f=1;
        for (i=0; i<=n; i++)
        {
            if (minw[i]==MAX) continue;
            for (j=0; j<e[i].size(); j++)
            {
                int next=e[i][j].next;
                if (able[next]==0) continue;
                if (minw[i]+e[i][j].w<minw[next]||(minw[i]+e[i][j].w==minw[next]&&minl[i]+e[i][j].len<minl[next]))
                {
                    minw[next]=minw[i]+e[i][j].w;
                    minl[next]=minl[i]+e[i][j].len;
                    f=0;
                }
            }
        }
        if (f) break;
    }
    return f;
}
void solve()
{
    read();
    build();
    memset(able,0,sizeof(able));
    dfs1(st);
    if (able[se]==0)
    {
        printf("VOID\n");
        return;
    }
    memset(able,0,sizeof(able));
    dfs2(se);
    int ans=bellman_ford();
    if (ans==0)
        printf("UNBOUND\n");
    else
        printf("%d %d\n", minw[se], minl[se]);
}
int main()
{
    while (scanf("%d %d %d %d",&n,&m,&st,&se)!=EOF)
        solve();
//system("pause");
    return 1;
}
