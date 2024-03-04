#include<bits/stdc++.h>
using namespace std;
 
inline int qread() {
    int ans=0;
    bool f=0;
    char c=getchar();
    while(c<'0'||c>'9') {
        if(c=='-') {
            f=1;
        }
        c=getchar();
    }
    while(c>='0'&&c<='9') {
        ans=ans*10+c-'0';
        c=getchar();
    }
    if(f) {
        return -ans;
    } else {
        return ans;
    }
}
 
const int mxn=100100;
 
int lg[mxn];
int f[mxn][20];
int n,m;
int a[mxn];
 
inline int que(int l,int r) {
    int g=lg[r-l+1];
    int u=f[l][g],v=f[r-(1<<g)+1][g];
    if(a[u]<a[v]) {
        return u;
    } else {
        return v;
    }
}
 
struct A {
    int l,r,h;
};
A ans[mxn];
int ass,tot;
void solve(int l,int r,int c) {

    queue<pair<pair<int, int>, int>> q;
    q.push({{l, r}, c});
    while (!q.empty()) {
        l = q.front().first.first;
        r = q.front().first.second;
        c = q.front().second;
        q.pop();
        if (l > r) continue;
        int mi=que(l,r);
        ans[++ass]= {l,r,a[mi]-c};
        tot+=a[mi]-c;
        q.push({{l, mi - 1}, a[mi]});
        q.push({{mi + 1, r}, a[mi]});
    }
    // if(l>r){
    //     return;
    // }
    // int mi=que(l,r);
    // ans[++ass]= {l,r,a[mi]-c};
    // tot+=a[mi]-c;
    // solve(l,mi-1,a[mi]);
    // solve(mi+1,r,a[mi]);
}
int main() {
    n=qread();
    // n = 100000;
    for(int i=1; i<=n; i++) {
        a[i]=qread();
        // a[i] = i;
        f[i][0]=i;
    }
 
    for(int i=2; i<=n; i++) {
        lg[i]=lg[i>>1]+1;
    }
 
    for(int j=1; (1<<j)<=n; j++) {
        for(int i=1; i+(1<<(j-1))<=n; i++) {
            int u=f[i][j-1],v=f[i+(1<<(j-1))][j-1];
            if(a[u]<a[v]) {
                f[i][j]=u;
            } else {
                f[i][j]=v;
            }
        }
    }
 
//  for(int i=1; i<=n; i++) {
//      for(int j=i; j<=n; j++) {
//          printf("%d %d : %d\n",i,j,a[que(i,j)]);
//      }
//  }
    solve(1,n,0);
 
    printf("%d\n",tot);
    for(int i=1; i<=ass; i++) {
        while(ans[i].h--) {
            printf("%d %d\n",ans[i].l,ans[i].r);
        }
    }
    return 0;
}
