// http://gdgzoi.com/showsource.php?id=586651, 张圣皓
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

const int N=200010;
  
inline void read(int &x) {
    x=0;
    int f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {
        if (ch=='-') {
            f=-1;
        }
        ch=getchar();
    }
    while(ch>='0'&&ch<='9') {
        x=x*10+ch-'0';
        ch=getchar();
    }
    x*=f;
}
  
struct note {
    int t;
    int next;
};
  
int cnt;
int head[N];
note e[N<<1];
  
inline void add(int x,int y) {
    e[++cnt].t=y;
    e[cnt].next=head[x];
    head[x]=cnt;
}
  
int n,m,k,q;
char mp[N];
vector<int> g[N];
  
inline int get_y(int id) {
    int tmp=id%m;
    if (tmp==0) {
        return m;
    }
    return tmp;
}
  
inline int get_x(int id) {
    return ((id-1)/m)+1;
}
  
inline int get_id(int x,int y) {
    return (x-1)*m+y;
}
  
inline void connect(int x1,int y1,int x2,int y2) {
    int id2=get_id(x2,y2);
    if (mp[id2]!='#') {
        add(get_id(x1,y1),get_id(x2,y2));
    }
}
  
int ind,scc;
int dfn[N],low[N],ins[N];
int bel[N];
stack<int> s;
  
void tarjan(int p) {
    int u;
    dfn[p]=low[p]=++ind;
    s.push(p);
    ins[p]=1;
    for(int i=head[p];i+1;i=e[i].next) {
        u=e[i].t;
        if (!dfn[u]) {
            tarjan(u);
            low[p]=min(low[u],low[p]);
        } else if (ins[u]) {
            low[p]=min(low[p],dfn[u]);
        }
    }
    if (dfn[p]==low[p]) {
        scc++;
        do {
            u=s.top();
            s.pop();
            ins[u]=0;
            bel[u]=scc;
        } while(u!=p);
    }
}
  
int fnd;
  
void dfs(int p,int x) {
    if (p==x) {
        fnd=1;
        return;
    }
    for(int i=0;i<(int)g[p].size();i++) {
        int t=g[p][i];
        dfs(t,x);
        if (fnd) {
            return;
        }
    }
    return;
}
  
int tpx[N],tpy[N];
  
int main() {
    memset(head,-1,sizeof(head));
    read(n),read(m),read(k),read(q);
    for(int i=1;i<=n*m;i++) {
        char ch=getchar();
        while(ch!='.'&&ch!='#') {
            ch=getchar();
        }
        mp[i]=ch;
    }
    for(int i=1;i<=n*m;i++) {
        if (mp[i]=='#') {
            continue;
        }
        int x=get_x(i),y=get_y(i);
        if (x!=1) {
            connect(x,y,x-1,y);
        }
        if (y!=1) {
            connect(x,y,x,y-1);
        }
        if (x!=n) {
            connect(x,y,x+1,y);
        }
        if (y!=m) {
            connect(x,y,x,y+1);
        }
    }
    for(int i=1;i<=k;i++) {
        int x1,y1,x2,y2;
        read(x1),read(y1),read(x2),read(y2);
        tpx[i]=get_id(x1,y1);
        tpy[i]=get_id(x2,y2);
        connect(x1,y1,x2,y2);
    }
    for(int i=1;i<=n*m;i++) {
        if (!dfn[i]) {
            tarjan(i);
        }
    }
    for(int i=1;i<=k;i++) {
        if (bel[tpx[i]]!=bel[tpy[i]]) {
            g[bel[tpx[i]]].push_back(bel[tpy[i]]);
        }
    }
    for(int i=1;i<=q;i++) {
        int x1,y1,x2,y2;
        read(x1),read(y1),read(x2),read(y2);
        int id1=get_id(x1,y1),id2=get_id(x2,y2);
        id1=bel[id1],id2=bel[id2];
        dfs(id1,id2);
        if (fnd) {
            printf("1\n");
        } else {
            printf("0\n");
        }
        fnd=0;
    }
    return 0;
}
