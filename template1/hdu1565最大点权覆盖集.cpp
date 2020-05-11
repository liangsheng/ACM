#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#define inf (1 << 30)
#define mod 1000000007
#define N 410
#define M 50005
const double eps = 1e-12;
const double pi = acos(-1.0);
using namespace std;

struct NODE
{
    int v, w;
    int next;
};

int n, s, t, cnt, NN;
int head[N];
int a[25][25], id[25][25];
NODE edge[(400 + 400 * 4) * 2 + 100];

int init()
{
    s = 0, t = n * n + 1, cnt = 0, NN = n * n + 2;
    memset(head, -1, sizeof(head));
    return 1;
}

void add_edge(int u,int v,int w)
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
                    //cout << "aug=" << aug, system("pause");
                    while(u!=s)
                    {
                        u=pre[u];
                        //cout << "u=" << u, system("pause");
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
    int i, j, tt, sum;
    while (scanf("%d", &n) != EOF)
    {
        init();
        tt = sum = 0;
        for (i = 1; i <= n; i++)
            for (j = 1; j <= n; j++) scanf("%d", &a[i][j]), id[i][j] = ++tt, sum += a[i][j];
        for (i = 1; i <= n; i++)
        {
            if (i % 2)
            {
                for (j = 1; j <= n; j += 2) add_edge(s, id[i][j], a[i][j]);
                for (j = 2; j <= n; j += 2) add_edge(id[i][j], t, a[i][j]);
            }
            else
            {
                for (j = 1; j <= n; j += 2) add_edge(id[i][j], t, a[i][j]);
                for (j = 2; j <= n; j += 2) add_edge(s, id[i][j], a[i][j]);
            }
        }
        for (i = 1; i <= n; i++)
            for (j = i % 2 ? 1 : 2; j <= n; j += 2)
            {
                if (j - 1 > 0) add_edge(id[i][j], id[i][j - 1], inf);
                if (j + 1 <= n) add_edge(id[i][j], id[i][j + 1], inf);
                if (i + 1 <= n) add_edge(id[i][j], id[i + 1][j], inf);
                if (i - 1 > 0) add_edge(id[i][j], id[i - 1][j], inf);
            }
        printf("%d\n", sum - sap());
    }
    system("pause");
    return 0;
}
