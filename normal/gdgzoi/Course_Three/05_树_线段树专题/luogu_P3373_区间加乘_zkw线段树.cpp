// https://www.luogu.com.cn/record/151454290
#include <bits/stdc++.h>
using namespace std;
constexpr int Spp{1<<20};
char buf[Spp],*p1,*p2;
#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,Spp,stdin),p1==p2)?EOF:*p1++)
template <typename T>
void read(T &x) {
    char c;int f{1};
    do x=(c=getchar())^48;
    while (!isdigit(c)&&c!='-');
    if (x==29) f=-1,x=0;
    while (isdigit(c=getchar()))
        x=(x<<3)+(x<<1)+(c^48);
    x*=f;
}
template <typename T,typename ...Args>
void read(T& x,Args&... args) {read(x);read(args...);}
using LL=long long;
constexpr LL N(1e5),b6e0{571373};
LL t[N<<1],ta[N],tb[N],sz[N<<1];
int n,h;
void upd(int p) {
    t[p]=((t[p<<1]+t[p<<1|1])*ta[p]+tb[p]*sz[p])%b6e0;
}
void up(int x) {
    for (int p{x+n-1};p>>=1;) upd(p);
}
void tag(int p,LL v,LL z) {
    t[p]=(t[p]*v+z*sz[p])%b6e0;
    if (p<n) ta[p]=(ta[p]*v)%b6e0,tb[p]=(tb[p]*v+z)%b6e0;
} 
void down(int x) {
    int p{x+n-1};
    for (int s{h};s>0;--s) {
        int i{p>>s};
        tag(i<<1,ta[i],tb[i]);
        tag(i<<1|1,ta[i],tb[i]);
        ta[i]=1,tb[i]=0;
    }
}
void modify(int l,int r,LL v,LL z) {
    down(l);down(r);
    for (int L{l+n-1},R{r+n-1};L<=R;L>>=1,R>>=1) {
        if (L&1) tag(L++,v,z);
        if (~R&1) tag(R--,v,z);
    }
    up(l);up(r);
}
LL query(int l,int r) {
    down(l);down(r);
    LL ans{0};
    for (int L{l+n-1},R{r+n-1};L<=R;L>>=1,R>>=1) {
        if (L&1) ans+=t[L++];
        if (~R&1) ans+=t[R--];
    }
    return ans;
}
int main() {
    int m,mod;read(n,m,mod);
    h=__lg(n)+1;
    // int N{1<<h};
    // for (int i{N};i<N+n;++i) read(t[i]),sz[i]=1,t[i]%=b6e0;
    // n=N;
    for (int i{n};i<2*n;++i) read(t[i]),sz[i]=1,t[i]%=b6e0;
    for (int i{n-1};i>=0;--i) t[i]=(t[i<<1]+t[i<<1|1])%b6e0,sz[i]=sz[i<<1]+sz[i<<1|1],ta[i]=1;
    while (m--) {
        int op,x,y;read(op,x,y);
        if (op<=2) {
            int k;read(k);
            if (op==1) modify(x,y,k,0);
            else modify(x,y,1,k);
        } else cout<<query(x,y)%mod<<"\n";
    }
    return 0;
}