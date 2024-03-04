#include<bits/stdc++.h>
#define int long long
#define ls (p << 1)
#define rs (p << 1 | 1)
#define inf 2147483647
#define N 200010
using namespace std;
struct node{
	int ans, tag, mx, mn;
}t[N << 2];
struct edg{ 
	int to, nxt;
}e[N << 1];
struct qwq{
	int u, v;
}a[N];
int res, dfn, w[N], wt[N], id[N], sz[N], fa[N], dep[N], top[N], son[N];
int cnt, head[N];
int tmp[N];
int n, m, q;

void add(int u, int v, int ww) {
	e[++cnt].to = v;
	e[cnt].nxt = head[u];
	w[cnt] = ww;
	head[u] = cnt;
}

void dfs1(int u, int f, int deep) {
	cout << "u= " << u << ", f= " << f << ", deep= " << deep << '\n';
	if (u > 200000) {
		cout << "FFFFFFFFFFFFF" << '\n';
		return ;
	}
	fa[u] = f;
	sz[u] = 1;
	dep[u] = deep;
	int mxsz = -1;
	for(int i = head[u]; i; i = e[i].nxt) {
		int v = e[i].to;
		if(v == f) continue;
		dfs1(v, u, deep + 1);
		sz[u] += sz[v];
		tmp[v] = w[i];//边转点 
		if(sz[v] > mxsz) {
			mxsz = sz[v];
			son[u] = v;
		}
	}
}
void dfs2(int u, int topp) {
	id[u] = ++dfn;
	top[u] = topp;
	wt[dfn] = tmp[u];
	if(!son[u]) return;
	dfs2(son[u], topp);
	for(int i = head[u]; i; i = e[i].nxt) {
		int v = e[i].to;
		if(v == fa[u] or v == son[u]) continue;
		dfs2(v, v);
	}
}

void pushup(int p) {
	t[p].ans = t[ls].ans + t[rs].ans;
	t[p].mx = max(t[ls].mx, t[rs].mx);
	t[p].mn = min(t[ls].mn, t[rs].mn);
}
void pushdown(int l, int r, int p) {
	if(t[p].tag == 1) {
		int lsmn = t[ls].mn, lsmx = t[ls].mx, rsmn = t[rs].mn, rsmx = t[rs].mx;
		t[ls].tag ^= 1;
		t[rs].tag ^= 1;
		t[ls].ans = -t[ls].ans;
		t[rs].ans = -t[rs].ans;
		t[ls].mx = -lsmn;
		t[ls].mn = -lsmx;
		t[rs].mx = -rsmn;
		t[rs].mn = -rsmx;
		t[p].tag = 0;
	}
}
void build(int l, int r, int p) {
	if(l == r) {
		t[p].ans = t[p].mn = t[p].mx = wt[l];
		return;
	}
	int mid = l + r >> 1;
	build(l, mid, ls);
	build(mid + 1, r, rs);
	pushup(p);
}
void update(int sl, int sr, int l, int r, int p) {//区间取反 
	if(sl <= l and r <= sr) {
		t[p].ans = -t[p].ans;
		int pmn = t[p].mn, pmx = t[p].mx;
		t[p].mn = -pmx;
		t[p].mx = -pmn;
		t[p].tag ^= 1;
		return;
	}
	int mid = l + r >> 1;
	pushdown(l, r, p);
	if(mid >= sl) update(sl, sr, l, mid, ls);
	if(mid < sr) update(sl, sr, mid + 1, r, rs);
	pushup(p);
}
void updatec(int sp, int l, int r, int p, int k) {//单点修改 
	if(sp <= l and r <= sp) {
		t[p].ans = t[p].mx = t[p].mn = k;
		return;
	}
	int mid = l + r >> 1;
	pushdown(l, r, p);
	if(mid >= sp) updatec(sp, l, mid, ls, k);
	else updatec(sp, mid + 1, r, rs, k);
	pushup(p);
}
void qsum(int sl, int sr, int l, int r, int p) {//区间和 
	if(sl <= l and r <= sr) {
		res += t[p].ans;
		return;
	}
	int mid = l + r >> 1;
	pushdown(l, r, p);
	if(mid >= sl) qsum(sl, sr, l, mid, ls);
	if(mid < sr) qsum(sl, sr, mid + 1, r, rs);
	pushup(p);
}
void qmax(int sl, int sr, int l, int r, int p) {//区间最大值 
	if(sl <= l and r <= sr) {
		res = max(res, t[p].mx);
		return;
	}
	int mid = l + r >> 1;
	pushdown(l, r, p);
	if(mid >= sl) qmax(sl, sr, l, mid, ls);
	if(mid < sr) qmax(sl, sr, mid + 1, r, rs);
	pushup(p);
}
void qmin(int sl, int sr, int l, int r, int p) {
	if(sl <= l and r <= sr) {
		res = min(res, t[p].mn);
		return;
	}
	int mid = l + r >> 1;
	pushdown(l, r, p);
	if(mid >= sl) qmin(sl, sr, l, mid, ls);
	if(mid < sr) qmin(sl, sr, mid + 1, r, rs);
	pushup(p);
}

void trans(int u, int v) { // 树剖取反 
	while(top[u] != top[v]) {
		if(dep[top[u]] < dep[top[v]]) swap(u, v);
		update(id[top[u]], id[u], 1, n, 1);
		u = fa[top[u]];
	}
	if(dep[u] > dep[v]) swap(u, v);
	if(u == v) return;
	update(id[u] + 1, id[v], 1, n, 1);
}
int query1(int u, int v) { //树剖sum
	int ans = 0;
	while(top[u] != top[v]) { 
		if(dep[top[u]] < dep[top[v]]) swap(u, v);
		res = 0;
		qsum(id[top[u]], id[u], 1, n, 1);
		ans += res;
		u = fa[top[u]];
	}
	if(dep[u] > dep[v]) swap(u, v);
	if(u == v) return ans;
	res = 0;
	qsum(id[u] + 1, id[v], 1, n, 1);
	ans += res;
	return ans;
}
int query2(int u, int v) { //max
	int ans = -inf;
	while(top[u] != top[v]) {
		if(dep[top[u]] < dep[top[v]]) swap(u, v);
		res = -inf;
		qmax(id[top[u]], id[u], 1, n, 1);
		ans = max(ans, res);
		u = fa[top[u]];
	}
	if(dep[u] > dep[v]) swap(u, v);
	if(u == v) return ans;
	res = -inf;
	qmax(id[u] + 1, id[v], 1, n, 1);
	ans = max(ans, res);
	return ans;
}
int query3(int u, int v) { //min
	int ans = inf;
	while(top[u] != top[v]) {
		if(dep[top[u]] < dep[top[v]]) swap(u, v);
		res = inf;
		qmin(id[top[u]], id[u], 1, n, 1);
		ans = min(ans, res);
		u = fa[top[u]];
	}
	if(dep[u] > dep[v]) swap(u, v);
	if(u == v) return ans;
	res = inf;
	qmin(id[u] + 1, id[v], 1, n, 1);
	ans = min(ans, res);
	return ans;
}

signed main() {
	cin>>n;
	for(int i = 1; i < n; i++) {
		int u, v, ww;
		cin>>u>>v>>ww;
		u++, v++;
		a[i].u = u;
		a[i].v = v;
		add(u, v, ww);
		add(v, u, ww);
	}
	dfs1(1, 0, 1);
	// dfs2(1, 1);
	// build(1, n, 1);
	char op[10];
	int x, y;
	cin>>m;
	int cnt = 0;
	while(m--) {
		cin>>op>>x>>y;
		// cout << op << ' ' << x << ' ' << y << '\n';
		// if(op[0] == 'C') {
		// 	int kkk = dep[a[x].u] > dep[a[x].v] ? a[x].u : a[x].v;
		// 	updatec(id[kkk], 1, n, 1, y);
		// }
		// else if(op[0] == 'N') {
		// 	x++, y++;
		// 	trans(x, y);			
		// }
		// else if(op[0] == 'S') {
		// 	// if (++cnt == 5566) cout << op << ' ' << x << ' ' << y << '\n';
		// 	x++, y++;
		// 	cout<<query1(x, y)<<'\n';
		// }
		// else if(op[1] == 'A') {
		// 	// if (++cnt == 5566) cout << op << ' ' << x << ' ' << y << '\n';
		// 	x++, y++;
		// 	cout<<query2(x, y)<<'\n';
		// }
		// else {
		// 	// if (++cnt == 5566) cout << op << ' ' << x << ' ' << y << '\n';
		// 	x++, y++;
		// 	cout<<query3(x, y)<<'\n';
		// }
	}
	return 0;
}
