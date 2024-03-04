#include<bits/stdc++.h> 

#define int long long
#define mid ((l+r)>>1)
#define lson rt<<1,l,mid
#define rson rt<<1|1,mid+1,r
using namespace std;

inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}

inline void write(int x){
	if(x<0){putchar('-');x=-x;}
	if(x>9)write(x/10);
	int xx=x%10;
	putchar(xx+'0');
}

const int N=2e5+10;
int n,m;
int cnt,head[N],to[N<<1],nex[N<<1],val[N<<1];
//链式前向星

int idx,fa[N],son[N],top[N],dep[N],dfn[N],siz[N],tmp[N],w[N];
//树链剖分 

int sumn[N<<2],maxn[N<<2],minn[N<<2],lz[N<<2];
//线段树 

struct node{
	int x,y;
}id[N];

inline void add(int x,int y,int w){
	nex[++cnt]=head[x];to[cnt]=y;val[cnt]=w;head[x]=cnt;
}

inline void dfs1(int x,int f){
	dep[x]=dep[f]+1;fa[x]=f;siz[x]=1;
	for(int i=head[x];i;i=nex[i]){
		int v=to[i];
		if(v==f) continue;
		dfs1(v,x);
		tmp[v]=val[i];//边权转点权
		siz[x]+=siz[v];
		if(siz[son[x]]<siz[v]) son[x]=v;
	}
}

inline void dfs2(int x,int topf){
	dfn[x]=++idx;w[idx]=tmp[x];top[x]=topf;
	if(son[x]) dfs2(son[x],topf);
	for(int i=head[x];i;i=nex[i]){
		int v=to[i];
		if(v==fa[x]||v==son[x]) continue;
		dfs2(v,v);
	}
}
//以下为线段树 

inline void pushup(int rt){
	sumn[rt]=sumn[rt<<1]+sumn[rt<<1|1];
	maxn[rt]=max(maxn[rt<<1],maxn[rt<<1|1]);
	minn[rt]=min(minn[rt<<1],minn[rt<<1|1]);
}

inline void build(int rt,int l,int r){
	if(l==r){
		sumn[rt]=maxn[rt]=minn[rt]=w[l];
		return;
	}
	build(rt<<1,l,mid);build(rt<<1|1,mid+1,r);
	pushup(rt);
}

inline void pushdown(int rt){
	lz[rt<<1]^=1;lz[rt<<1|1]^=1;
	sumn[rt<<1]=-sumn[rt<<1];sumn[rt<<1|1]=-sumn[rt<<1|1];
	maxn[rt<<1]=-maxn[rt<<1];maxn[rt<<1|1]=-maxn[rt<<1|1];
	minn[rt<<1]=-minn[rt<<1];minn[rt<<1|1]=-minn[rt<<1|1];
	swap(maxn[rt<<1],minn[rt<<1]);
	swap(maxn[rt<<1|1],minn[rt<<1|1]);
	lz[rt]=0;
}

inline void update(int rt,int l,int r,int q,int k){
	if(l==r){
		sumn[rt]=maxn[rt]=minn[rt]=k;
		return;
	}
	if(lz[rt]) pushdown(rt);
	if(q<=mid) update(rt<<1,l,mid,q,k);
	if(q>mid)  update(rt<<1|1,mid+1,r,q,k);
	pushup(rt);
}

inline void change(int rt,int l,int r,int L,int R){
	if(L<=l&&r<=R){
		lz[rt]^=1;
		sumn[rt]=-sumn[rt];
		maxn[rt]=-maxn[rt];
		minn[rt]=-minn[rt];
		swap(maxn[rt],minn[rt]);
		return;
	}
	if(lz[rt]) pushdown(rt);
	if(L<=mid) change(rt<<1,l,mid,L,R);
	if(R>mid)  change(rt<<1|1,mid+1,r,L,R);
	pushup(rt);
}

inline int qsum(int rt,int l,int r,int L,int R){
	int res=0;
	if(L<=l&&r<=R) return sumn[rt];
	if(lz[rt]) pushdown(rt);
	if(L<=mid) res+=qsum(rt<<1,l,mid,L,R);
	if(R>mid)  res+=qsum(rt<<1|1,mid+1,r,L,R);
	pushup(rt);
	return res;
}

inline int qmax(int rt,int l,int r,int L,int R){
	int res=-2147483647;
	if(L<=l&&r<=R) return maxn[rt];
	if(lz[rt]) pushdown(rt);
	if(L<=mid) res=max(res,qmax(rt<<1,l,mid,L,R));
	if(R>mid)  res=max(res,qmax(rt<<1|1,mid+1,r,L,R));
	pushup(rt);
	return res;
}

inline int qmin(int rt,int l,int r,int L,int R){
	int res=2147483647;
	if(L<=l&&r<=R) return minn[rt];
	if(lz[rt]) pushdown(rt);
	if(L<=mid) res=min(res,qmin(rt<<1,l,mid,L,R));
	if(R>mid)  res=min(res,qmin(rt<<1|1,mid+1,r,L,R));
	pushup(rt);
	return res;
}
//以上是线段树
//以下是树链剖分

inline void update(int x,int y){
	while(top[x]!=top[y]){
		if(dep[top[x]]<dep[top[y]]) swap(x,y);
		change(1,1,n,dfn[top[x]],dfn[x]);
		x=fa[top[x]];
	}
	if(dep[x]>dep[y]) swap(x,y);
	if(x!=y) change(1,1,n,dfn[x]+1,dfn[y]);
}

inline int qsum(int x,int y){
	int res=0;
	while(top[x]!=top[y]){
		if(dep[top[x]]<dep[top[y]]) swap(x,y);
		res+=qsum(1,1,n,dfn[top[x]],dfn[x]);
		x=fa[top[x]];
	}
	if(dep[x]>dep[y]) swap(x,y);
	if(x!=y) res+=qsum(1,1,n,dfn[x]+1,dfn[y]);
	return res;
}

inline int qmax(int x,int y){
	int res=-2147483647;
	while(top[x]!=top[y]){
		if(dep[top[x]]<dep[top[y]]) swap(x,y);
		res=max(res,qmax(1,1,n,dfn[top[x]],dfn[x]));
		x=fa[top[x]];
	}
	if(dep[x]>dep[y]) swap(x,y);
	if(x!=y) res=max(res,qmax(1,1,n,dfn[x]+1,dfn[y]));
	return res;
}

inline int qmin(int x,int y){
	int res=2147483647;
	while(top[x]!=top[y]){
		if(dep[top[x]]<dep[top[y]]) swap(x,y);
		res=min(res,qmin(1,1,n,dfn[top[x]],dfn[x]));
		x=fa[top[x]];
	}
	if(dep[x]>dep[y]) swap(x,y);
	if(x!=y) res=min(res,qmin(1,1,n,dfn[x]+1,dfn[y]));
	return res;
}

signed main(){
	n=read();
	for(int i=1;i<n;i++){
		int a,b,c;
		a=read()+1;b=read()+1;c=read();
		add(a,b,c);add(b,a,c);
		id[i].x=a;id[i].y=b;
	}
	dfs1(1,0);dfs2(1,1);
	build(1,1,n);
	m=read();
	while(m--){
		char s[10];int a,b;
		scanf("%s",s);a=read();b=read();
		if(s[0]=='C'){
			int tmpp;
			if(dep[id[a].x]>dep[id[a].y]) tmpp=id[a].x;
			else tmpp=id[a].y;
			update(1,1,n,dfn[tmpp],b);
		}
		else if(s[0]=='N'){
			a++,b++;
			update(a,b);
		}
		else if(s[0]=='S'){
			a++,b++;
			write(qsum(a,b));puts("");
		}
		else if(s[0]=='M'&&s[1]=='A'){
			a++,b++;
			write(qmax(a,b));puts("");
		}
		else if(s[0]=='M'&&s[1]=='I'){
			a++,b++;
			write(qmin(a,b));puts("");
		}
	}
	return 0;
}
