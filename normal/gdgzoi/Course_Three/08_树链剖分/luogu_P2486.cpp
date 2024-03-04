#include<bits/stdc++.h>
#define ls (p << 1)
#define rs (p << 1 | 1) 
using namespace std;
struct node{
	int ans, tag, lc, rc;
}t[100005 << 2];
struct edg{ 
	int to, nxt;
}e[100005 << 1];
int dfn, w[100005], wt[100005], id[100005], sz[100005], fa[100005], dep[100005], top[100005], son[100005];
int cnt, head[100005], lc, rc;
int n, m, q, pos1, pos2;

void add(int u, int v) {
	e[++cnt].to = v;
	e[cnt].nxt = head[u];
	head[u] = cnt;
}

void pushup(int p) {
	t[p].lc = t[ls].lc; t[p].rc = t[rs].rc; 
	int kkk = t[ls].ans + t[rs].ans;
	if(t[ls].rc == t[rs].lc) kkk--;
	t[p].ans = kkk;
}
void pushdown(int p) {
	if(t[p].tag) {
		t[ls].tag = t[rs].tag = t[p].tag;
		t[ls].lc = t[ls].rc = t[p].tag;
		t[rs].lc = t[rs].rc = t[p].tag;
		t[ls].ans = t[rs].ans = 1;
		t[p].tag = 0;
	}
}
void build(int l, int r, int p) {
	t[p].tag = 0;
	if(l == r) {
		t[p].ans = 1;
		t[p].lc = t[p].rc = wt[l];
		return;
	}
	int mid = l + r >> 1;
	build(l, mid, ls);
	build(mid + 1, r, rs);
	pushup(p);
}
void update(int sl, int sr, int l, int r, int p, int k) {
	if(sl <= l and r <= sr) {
		t[p].ans = 1;
		t[p].tag = k;
		t[p].lc = t[p].rc = k;
		return;
	}
	pushdown(p);
	int mid = l + r >> 1;
	if(mid >= sl) update(sl, sr, l, mid, ls, k);
	if(mid < sr) update(sl, sr, mid + 1, r, rs, k);
	pushup(p);
}
int query(int sl, int sr, int l, int r, int p) {
	if(sl <= l and r <= sr) {
		if(sl == l) lc = t[p].lc;
		if(sr == r) rc = t[p].rc;
		return t[p].ans;
	}
	pushdown(p);
	int mid = l + r >> 1;
	if(mid >= sr) return query(sl, sr, l, mid, ls);
	else if(mid < sl) return query(sl, sr, mid + 1, r, rs);
	else {
		int ans = query(sl, sr, l, mid, ls) + query(sl, sr, mid + 1, r, rs);
		if(t[ls].rc == t[rs].lc) ans--;
		return ans;
	}
}

void dfs1(int u, int f, int deep) {
	sz[u] = 1;
	fa[u] = f;
	dep[u] = deep;
	int mz = 0;
	for(int i = head[u]; i; i = e[i].nxt) {
		int v = e[i].to;
		if(v == f) continue;
		dfs1(v, u, deep + 1);
		sz[u] += sz[v];
		if(sz[v] > mz) {
			son[u] = v;
			mz = sz[v];
		}
	}
}
void dfs2(int u, int topp) {
	id[u] = ++dfn;
	wt[dfn] = w[u];
	top[u] = topp;
	if(!son[u]) return;
	dfs2(son[u], topp);
	for(int i = head[u]; i; i = e[i].nxt) {
		int v = e[i].to;
		if(v == son[u] or v == fa[u]) continue;
		dfs2(v, v);
	}
}
void col(int u, int v, int c) { // color
	while(top[u] != top[v]) {
		if(dep[top[u]] < dep[top[v]]) swap(u, v);
		update(id[top[u]], id[u], 1, n, 1, c);
		u = fa[top[u]];
	}
	if(dep[u] > dep[v]) swap(u, v);
	update(id[u], id[v], 1, n, 1, c);
}
int qcol(int u, int v) {
	int res = 0;
	pos1 = 0, pos2 = 0;
	while(top[u] != top[v]) {
		if(dep[top[u]] < dep[top[v]]) {
			swap(u, v);
			swap(pos1, pos2);
		}
		res += query(id[top[u]], id[u], 1, n, 1);
		if(rc == pos1) res--;
		pos1 = lc;
		u = fa[top[u]];
	}
	if(dep[u] > dep[v]) swap(u, v), swap(pos1, pos2);
	res += query(id[u], id[v], 1, n, 1);
	if(lc == pos1) res--;
	if(rc == pos2) res--;
	return res;
}

int main() {
	cin>>n>>m;
	for(int i = 1; i <= n; i++) 
	    cin>>w[i];
	for(int i = 1; i < n; i++) {
		int u, v;
		cin>>u>>v;
		add(u, v);
		add(v, u);
	}
	dfs1(1, 0, 1);
	dfs2(1, 1);
	build(1, n, 1);
	char op;
	int a, b, c;
	while(m--) {
		cin>>op;
		if(op == 'C') {
			cin>>a>>b>>c;
			col(a, b, c);
		}
		if(op == 'Q') {
			cin>>a>>b;
			cout<<qcol(a, b)<<'\n';
		}
	}
	return 0;
}
