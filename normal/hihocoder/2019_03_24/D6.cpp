#include <bits/stdc++.h>
#define MP make_pair
#define PB emplace_back
using namespace std;
typedef long long ll;
template<typename T>
inline T read(T&x){
    x=0;int f=0;char ch=getchar();
    while (ch<'0' || ch>'9') f|=(ch=='-'),ch=getchar();
    while (ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
    return x=f?-x:x;
}
const int maxn=50*50+10;
const int INF=2e9;
struct Edge{
    int from,to,cap,flow,cost;
    Edge(){}
    Edge(int f,int t,int c,int fl,int co):from(f),to(t),cap(c),flow(fl),cost(co){}
};
struct MCMF{
    int n,m,s,t,k;
    vector<Edge> edges;
    vector<int> G[maxn];
    bool inq[maxn];
    int d[maxn];
    int p[maxn];
    int a[maxn];

    void init(int n,int s,int t){
        this->n=n, this->s=s, this->t=t;
        edges.clear();
        for(int i=0;i<=n;++i) G[i].clear();
    }

    void AddEdge(int from,int to,int cap,int cost){
        edges.push_back(Edge(from,to,cap,0,cost));
        edges.push_back(Edge(to,from,0,0,-cost));
        m=edges.size();
        G[from].push_back(m-2);
        G[to].push_back(m-1);
    }

    bool SPFA(int &flow,int &cost){
        for(int i=0;i<n;++i) d[i]=INF;
        queue<int> Q;
        memset(inq,0,sizeof(inq));
        d[s]=0, Q.push(s), a[s]=INF, p[s]=0, inq[s]=true;
        while(!Q.empty()){
            int u=Q.front(); Q.pop();
            inq[u]=false;
            for(int i=0;i<G[u].size();++i){
                Edge &e=edges[G[u][i]];
                if(e.cap>e.flow && d[e.to]>d[u]+e.cost){
                    d[e.to]=d[u]+e.cost;
                    p[e.to]=G[u][i];
                    a[e.to]=min(a[u],e.cap-e.flow);
                    if(!inq[e.to]){ Q.push(e.to); inq[e.to]=true; }
                }
            }
        }
        if(d[t]==INF) return false;
        flow+=a[t];
        int u=t;
        while(u!=s){
            edges[p[u]].flow+=a[t];
            edges[p[u]^1].flow-=a[t];
            cost+=a[t]*edges[p[u]].cost;
            u=edges[p[u]].from;
        }
        return true;
    }

    int solve(){
        int flow=0,cost=0;
        while(SPFA(flow,cost));
        return cost;
    }
} G;;

const int NN = 55;

int n, m;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    int i, j, k, ans = 0, h;
    read(n), read(m);
	G.init(n*m+2,0,n*m+1);
	for (i=1;i<=n;++i){
		for (j=1;j<=m;++j){
			read(h);
			ans+=h;
			G.AddEdge(0,m*(i-1)+j,h,0);
			for (k=0;k<4;++k){
				int tx=i+dx[k];
				int ty=j+dy[k];
				if (tx<1 || tx>n || ty<1 || ty>m) continue;
				G.AddEdge(m*(i-1)+j,m*(tx-1)+ty,INF,1);
			}
		}
	}
	ans/=n*m;
	for (i=1;i<=n;++i){
		for (j=1;j<=m;++j){
			G.AddEdge(m*(i-1)+j,n*m+1,ans,0);
		}
	}
	printf("%d\n",G.solve());
	return 0;
}
