#pragma comment(linker, "/STACK:102400000,102400000")
#include <iostream>
#include <string>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <ctime>
#include <set>
#include <map>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <cmath>
#include <assert.h>
#include <iomanip>
using namespace std;
#define vi vector<int>
#define pii pair<int,int>
#define x first
#define y second
#define all(x) x.begin(),x.end()
#define pb push_back
#define mp make_pair
#define SZ(x) (int)x.size()
#define rep(i,a,b) for(int i=a;i<b;i++)
#define per(i,a,b) for(int i=b-1;i>=a;i--)
#define pi acos(-1)
#define mod 1000000007
#define inf 1000000007
#define ll long long
#define ull unsigned long long
#define DBG(x) cerr<<(#x)<<"="<<x<<"\n";
#define N 1000010
#define _DEBUG
template <class U,class T> void Max(U &x, T y){if(x<y)x=y;}
template <class U,class T> void Min(U &x, T y){if(x>y)x=y;}
template <class T> void add(int &a,T b){a=(a+b)%mod;}
inline int gcd(int a,int b){return b==0?a:gcd(b,a%b);}
inline ll gcd(ll a,ll b){return b==0?a:gcd(b,a%b);}

int pow(int a,int b){
    int ans=1;
    while(b){
        if(b&1)ans=1LL*ans*a%mod;
        a=1LL*a*a%mod;b>>=1;
    }
    return ans;
}
int pow(int a,int b,int c){
    int ans=1;
    while(b){
        if(b&1)ans=1LL*ans*a%c;
        a=1LL*a*a%c;b>>=1;
    }
    return ans;
}

int a[55][55];
struct node{
    int v,c,w,next;
}g[N];
int head[N],d[N],vis[N],cnt,p[N];
void add(int a,int b,int c,int w=0){
    g[cnt]={b,c,w,head[a]},head[a]=cnt++;
    g[cnt]={a,0,-w,head[b]},head[b]=cnt++;
}
bool bfs(int s,int t){
    rep(i,0,t+1)d[i]=inf,vis[i]=0;d[s]=0;
    queue<int>q;q.push(s);
    while(!q.empty()){
        int u=q.front();q.pop();vis[u]=0;
        for(int i=head[u];~i;i=g[i].next){
            int j=g[i].v;
            if(g[i].c&&d[j]>d[u]+g[i].w){
                d[j]=d[u]+g[i].w;
                p[j]=i;
                if(!vis[j])vis[j]=1,q.push(j);
            }
        }
    }
    return d[t]<inf;
}
ll max_flow(int s,int t){
    ll ans=0;
    while(bfs(s,t)){
        int x=t,f=inf;
        while(x!=s){
            Min(f,g[p[x]].c),x=g[p[x]^1].v;
        }
        ans+=1LL*d[t]*f;
        x=t;
        while(x!=s){
            g[p[x]].c-=f,g[p[x]^1].c+=f;x=g[p[x]^1].v;
        }
    }
    return ans;
}
int dx[]={0,0,-1,1},dy[]={-1,1,0,0};
int main(){
    //srand(time(NULL)+clock());
    int T,ca=0,k,i,j,m=0,K,n;
    //double start=clock();
    scanf("%d%d",&n,&m);
    int s=0,t;
    rep(i,0,n)rep(j,0,m){
        scanf("%d",&a[i][j]);
        s+=a[i][j];
    }
    assert(s%(n*m)==0);
    K=s/n/m;
    s=n*m,t=s+1;
    cnt=0;
    memset(head,-1,sizeof(head));
    rep(i,0,n)rep(j,0,m){
        if(a[i][j]>K){
            add(s,i*m+j,a[i][j]-K);
        }
        else if(a[i][j]<K){
            add(i*m+j,t,K-a[i][j]);
        }
    }
    rep(i,0,n)rep(j,0,m){
        int u=i*m+j;
        rep(k,0,4){
            int x=i+dx[k],y=j+dy[k],v=x*m+y;
            if(x>=0&&x<n&&y>=0&&y<m){
                add(u,v,inf,1);
            }
        }
    }
    ll ans=max_flow(s,t);
    printf("%lld\n",ans);
    //cerr<<(1.*clock()-start)/CLOCKS_PER_SEC<<"\n";
}
