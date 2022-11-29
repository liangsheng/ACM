#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long LL;

inline int read() {
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {
        if(ch=='-')f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9') {
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x*f;
}
int T,n,cnt;
int last[200005],v[200005];
bool mark[200005];
struct edge {
    int to,next;
} e[400005];
void insert(int u,int v) {
    e[++cnt].to=v;
    e[cnt].next=last[u];
    last[u]=cnt;
    e[++cnt].to=u;
    e[cnt].next=last[v];
    last[v]=cnt;
}
void dfs(int x,int f) {
    v[x]=1;
    int tot=0;
    for(int i=last[x]; i; i=e[i].next) {
        if(e[i].to==f)continue;
        dfs(e[i].to,x);
        v[x]+=v[e[i].to];
        if(!mark[e[i].to])tot++;
    }
    if(tot>=2)v[x]-=2,mark[x]=1;
    else if(tot==1)v[x]--;
}

int x, y;

int main() {
    while (~scanf("%d %d %d", &n, &x, &y)) {
        cnt=0;
        memset(last,0,sizeof(last));
        memset(v,0,sizeof(v));
        memset(mark,0,sizeof(mark));
        for(int i=1; i<n; i++) {
            int a=read(),b=read();
            insert(a,b);
        }
        if (x >= y) {
            cout << (LL) y * (n - 1) << '\n';
            continue;
        }
        dfs(1,0);
        //printf("%d\n",v[1]);
        cout << (LL) y * (v[1] - 1) + (LL) x * (n - v[1]) << '\n';
    }
    return 0;
}
