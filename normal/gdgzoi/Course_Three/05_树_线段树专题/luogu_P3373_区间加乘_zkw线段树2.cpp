https://www.luogu.com.cn/record/132672003
#include <bits/stdc++.h>
using namespace std;
const int N=1e5+114;
inline int read(){
	int s=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=0;c=getchar();}
	while(c>='0'&&c<='9')s=(s<<1)+(s<<3)+c-48,c=getchar();
	return f?s:-s;
}
#define int long long
struct Xds{
	int v,d,c;
	Xds():v(0),d(0),c(1){}
}a[N<<2];
int n,q,pwp;
constexpr int p=571373;
#define ls i<<1
#define rs i<<1|1
//inline void push_up(int i){
//	a[i].v=a[ls].v+a[rs].v;
//}
inline void push_down(int i){
	if(a[i].d){
		if(a[i].c!=1){
			a[ls].v=a[ls].v%p*a[i].c+(a[i].d<<__builtin_clz(i<<15)),a[ls].d=a[ls].d*a[i].c%p+a[i].d,a[ls].c=a[ls].c*a[i].c%p;
			a[rs].v=a[rs].v%p*a[i].c+(a[i].d<<__builtin_clz(i<<15)),a[rs].d=a[rs].d*a[i].c%p+a[i].d,a[rs].c=a[rs].c*a[i].c%p;
			a[i].d=0,a[i].c=1;
		}
		else{
			a[ls].v+=a[i].d<<__builtin_clz(i<<15),a[ls].d+=a[i].d;
			a[rs].v+=a[i].d<<__builtin_clz(i<<15),a[rs].d+=a[i].d;
			a[i].d=0;
		}
	}
	else if(a[i].c!=1){
		a[ls].v=a[ls].v%p*a[i].c,a[ls].d=a[ls].d*a[i].c%p,a[ls].c=a[ls].c*a[i].c%p;
		a[rs].v=a[rs].v%p*a[i].c,a[rs].d=a[rs].d*a[i].c%p,a[rs].c=a[rs].c*a[i].c%p;
		a[i].c=1;
	}
}
inline void push_down2(int p){
	for(int i=0,j=17;j;--j) push_down(i=(i<<1)|((p>>j)&1));
}
void change1(int l,int r,int c_){
	l|=131072,r|=131072;
	push_down2(l);
	push_down2(r);
	if(l==r){a[l].v=a[l].v*c_%p;return;}
	int t1=l,t2=r;
	a[l].v=a[l].v*c_%p,a[r].v=a[r].v*c_%p;
	for(;(t1^t2)>1;t1>>=1,t2>>=1){
		if(!(t1&1)) a[t1^1].v=a[t1^1].v*c_%p,a[t1^1].d=a[t1^1].d*c_%p,a[t1^1].c=a[t1^1].c*c_%p;
		a[t1>>1].v=a[t1].v+a[t1^1].v;
		if(t2&1) a[t2^1].v=a[t2^1].v*c_%p,a[t2^1].d=a[t2^1].d*c_%p,a[t2^1].c=a[t2^1].c*c_%p;
		a[t2>>1].v=a[t2].v+a[t2^1].v;
	}
//	t1=l,t2=r;
	while(t1){
		a[t1>>1].v=a[t1].v+a[t1^1].v;
		a[t2>>1].v=a[t2].v+a[t2^1].v;
		t1>>=1,t2>>=1;
	}
}
void change2(int l,int r,int d_){
	l|=131072,r|=131072;
	push_down2(l);
	push_down2(r);
	if(l==r){a[l].v+=d_;return;}
	int t1=l,t2=r;
	a[l].v+=d_,a[r].v+=d_;
	for(;(t1^t2)>1;t1>>=1,t2>>=1){
		if(!(t1&1)) a[t1^1].v+=d_<<__builtin_clz(t1<<14),a[t1^1].d+=d_;
		a[t1>>1].v=a[t1].v+a[t1^1].v;
		if(t2&1) a[t2^1].v+=d_<<__builtin_clz(t2<<14),a[t2^1].d+=d_;
		a[t2>>1].v=a[t2].v+a[t2^1].v;
	}
//	t1=l,t2=r;
	while(t1){
		a[t1>>1].v=a[t1].v+a[t1^1].v;
		a[t2>>1].v=a[t2].v+a[t2^1].v;
		t1>>=1,t2>>=1;
	}
}
int query(int l,int r){
	l|=131072,r|=131072;
	push_down2(l);
	push_down2(r);
	if(l==r){return a[l].v%p;}
	int t1=l,t2=r;
	int ans=a[l].v+a[r].v;
	//	cout << ans << endl;
	//	while((t1^t2)>=4){
	//		if(!((t1>>=1)&1)) ans+=a[t1^1].v;
	//		if((t2>>=1)&1) ans+=a[t2^1].v;
	//	}
	for(;(t1^t2)>1;t1>>=1,t2>>=1){
		if(!(t1&1)) ans+=a[t1^1].v;
		if(t2&1) ans+=a[t2^1].v;
	}
	//	cout << ans << endl;
	return ans%p;
}
signed main(){
	//	std::ios_base::sync_with_stdio(0);
	//	cin.tie(0);
	//	cout.tie(0);
	cin >> n >> q >> pwp;
	for(int i=1;i<=n;++i) cin >> a[i|131072].v;
	for(int i=131071;i>=1;--i) a[i].v=a[i<<1].v+a[i<<1|1].v;
	int op,l,r,x;
	while(q--){
		op=read();
		if(op==1){l=read(),r=read(),x=read();change1(l,r,x);}
		if(op==2){l=read(),r=read(),x=read();change2(l,r,x);}
		if(op==3){l=read(),r=read();printf("%lld\n",query(l,r));}
		//		for(int i=1;i<=5;++i) cout << query(i,i) << " ";
		//		cout << endl;
	}
	return 0;
}
/*
  1
  10                  11
  100       101       110       111
  1000 1001 1010 1011 1100 1101 1110 1111
 */