/*
 *  algorithm : dinic Fractional_Programming
 *
 *  Memory 212K Time 80MS   Language G++
 *
 *  code by : zhyu
 *题意：给出一个带权无向图，求割集，且割集的平均边权最小。
 *
 *思路：把问题转化为0-1分数规划，二分进行判断。对于二分的每一个mid，
 *边权小于mid的加入临时解集，剩下的以边权-mid为新边权建图求最小割，
 *所求得的边集就是mid条件下的解集。
 */
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;
typedef double DB;

const int N=200+10;
const int E=1000+10;
const DB oo=1e9;
const DB eps=1e-9;

int node,src,dest,ne;
int head[N],work[N],Q[N],dist[N];
int pnt[E],nxt[E];
DB flow[E];
int a[E],b[E],w[E];

inline void init(int _node,int _src,int _dest) {
    node=_node;
    src=_src;
    dest=_dest;
    for(int i=0; i<node; i++)  head[i]=-1;
    ne=0;
}
inline void add(int u,int v,DB c1,DB c2) {
    pnt[ne]=v,flow[ne]=c1,nxt[ne]=head[u],head[u]=ne++;
    pnt[ne]=u,flow[ne]=c2,nxt[ne]=head[v],head[v]=ne++;
}
bool dinic_bfs(void) {
    int i,u,v,l,r=0;
    for(i=0; i<node; i++)  dist[i]=-1;
    dist[Q[r++]=src]=0;
    for(l=0; l<r; l++) for(i=head[u=Q[l]]; i>=0; i=nxt[i])
            if(flow[i] && dist[v=pnt[i]]<0) {
                dist[Q[r++]=v]=dist[u]+1;
                if(v==dest) return 1;
            }
    return 0;
}
DB dinic_dfs(int u,DB exp) {
    DB tmp;
    if(u==dest) return exp;
    for(int &i=work[u],v; i>=0; i=nxt[i])
        if(flow[i] && dist[v=pnt[i]]==dist[u]+1 && (tmp=dinic_dfs(v,min(exp,flow[i])))>0) {
            flow[i]-=tmp;
            flow[i^1]+=tmp;
            return tmp;
        }
    return 0;
}
DB dinic_flow(void) {
    int i;
    DB res=0,delta;
    while(dinic_bfs()) {
        for(i=0; i<node; i++)  work[i]=head[i];
        while(1) {
            delta=dinic_dfs(src,oo);
            if(delta<eps)    break;
            res+=delta;
        }
    }
    return res;
}
int main(void) {
    int n,m;
    bool blank=0;
    while(scanf("%d%d",&n,&m)==2) {
        if(blank)   puts("");
        else    blank=1;
        DB l=oo,r=1.0,mid,res;
        for(int i=0; i<m; i++) {
            scanf("%d%d%d",a+i,b+i,w+i);
            a[i]--,b[i]--;
            l=min(l,w[i]);
            r=max(r,w[i]);
        }
        while(r-l>eps) {
            init(n,0,n-1);
            mid=(l+r)/2;
            res=0;
            for(int i=0; i<m; i++) {
                if(w[i]<=mid)    res+=w[i]-mid;
                else    add(a[i],b[i],w[i]-mid,w[i]-mid);
            }
            res+=dinic_flow();
            if(res>0)    l=mid;
            else    r=mid;
        }
        init(n,0,n-1);
        for(int i=0; i<m; i++) {
            if(w[i]<=r)  continue;
            else    add(a[i],b[i],w[i]-r,w[i]-r);
        }
        dinic_flow();
        dinic_bfs();
        vector<int>ans;
        for(int i=0; i<m; i++)
            if(w[i]<=r || (dist[a[i]]<0 && dist[b[i]]>=0) || (dist[a[i]]>=0 && dist[b[i]]<0))
                ans.push_back(i+1);
        int num=(int)ans.size();
        printf("%d\n",num);
        for(int i=0; i<num; i++) {
            if(i)   putchar(' ');
            printf("%d",ans[i]);
        }
        puts("");
    }
    return 0;
}
