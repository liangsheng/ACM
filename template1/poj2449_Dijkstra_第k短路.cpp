#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;

const int MAXN=1005;
const int MAXM=100005;
const int INF=1000000000;

int gr[MAXN][MAXN],dist[MAXN],vist[MAXN],head[MAXN];
int n,m,s,t,ct,pos,K;

struct Edge
{
       int to;
       int w;
       int next;
}e[MAXM];

struct node
{
       int id,fi,gi;
       friend bool operator <(node a,node b)
       {
              if(a.gi==b.gi)
                  return a.fi>b.fi;
              return a.gi>b.gi;
       }
}p[2000005];

void addEdge(int x,int y,int z)
{
     e[pos].to=y;
     e[pos].w=z;
     e[pos].next=head[x];
     head[x]=pos++;
}

void Init()
{
    int i,j,k;
    for(i=0;i<=n;i++)
    {
        dist[i]=INF;
        vist[i]=1;
    }
    dist[t-1]=0;
    for(i=0;i<n;i++)
    {
        k=n;
        for(j=0;j<n;j++)
         if(vist[j]&&dist[j]<dist[k])
            k=j;
        if(k==n)
           break;
        vist[k]=0;
        for(j=0;j<n;j++)
          if(vist[j]&&dist[k]+gr[k][j]<dist[j])
            dist[j]=dist[k]+gr[k][j];
    }
}

int solve()
{
    int i,j,id,fi,gi,cnt=0;
    if(dist[s]==INF)
       return -1;
    ct=0;
    p[ct].id=s-1;
    p[ct].fi=0;
    p[ct++].gi=dist[s-1];
    while(ct)
    {
        id=p[0].id;
        fi=p[0].fi;
        gi=p[0].gi;
        if(id==t-1)
           cnt++;
        if(cnt==K)
           return fi;
        pop_heap(p,p+ct);
        ct--;
        for(j=head[id];j;j=e[j].next)
         {
             p[ct].id=e[j].to;
             p[ct].fi=fi+e[j].w;
             p[ct++].gi=p[ct].fi+dist[e[j].to];
             push_heap(p,p+ct);
         }
    }
    return -1;
}

int main()
{
    int i,j,x,y,w,ans;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(i=0;i<n;i++)
         for(j=0;j<n;j++)
          gr[i][j]=INF;
        pos=1;
        memset(head,0,sizeof(head));
        for(i=0;i<m;i++)
        {
           scanf("%d%d%d",&x,&y,&w);
           x--;
           y--;
           if(w<gr[y][x])
             gr[y][x]=w;
           addEdge(x,y,w);
        }
        scanf("%d%d%d",&s,&t,&K);
        if(s==t)
           K++;
        Init();
        ans=solve();
        printf("%d\n",ans);
    }
    system("pause");
    return 0;
}

