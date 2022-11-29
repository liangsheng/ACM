#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <cmath>
#include <cfloat>
#define zero(x) (((x)>0?(x):-(x))<eps)

#define pause cout << " press ansy key to continue...",  cin >> chh
#define file_r(x) freopen(x,  "r",  stdin)
#define file_w(x) freopen(x,  "w",  stdout)
#define lowbit(x) ((x) & (-x))
#define repit(i, c) for (__typeof__((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repe(i, u) for (int i = head[u]; i != -1; i = nxt[i])
#define repd(i, n) for (int i = (n - 1); i >= 0; i--)
#define FOR(i, n, m) for (int i = (n); i <= (m); i++)
#define FORD(i, n, m) for (int i = (n); i >= (m); i--)
#define pb push_back
#define X first
#define Y second
#define ins insert
#define rb rbegin
#define be begin
#define er erase
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define SZ(c) (c).size()
#define ALL(c) (c).begin(), (c).end()
#define sqr(r) ((r) * (r))
#define dis(x1, y1, x2, y2) (((x1) - (x2)) * ((x1) - (x2)) + ((y1) - (y2)) * ((y1) - (y2)))
#define FASTIO ios::sync_with_stdio(false);cin.tie(0)

#define sc(x) cout << #x" = " << x << endl, pause
#define sc2(x, y) cout << #x" = " << x << " " << #y" = " << y << endl, pause
#define sc3(x, y, z) cout << #x" = " << x << " " << #y" = " << y << " " << #z" = " << z << endl, pause
#define sc4(x, y, z, w) cout << #x" = " << x << " " << #y" = " << y << " " << #z" = " << z << " " << #w" = " << w << endl, pause

#define in(n) scanf("%d", &n)
#define in2(n, m) scanf("%d %d", &n, &m)
#define in3(x, y, z) scanf("%d %d %d", &x, &y, &z)

using namespace std;
int chh;

typedef vector<int> vi;
typedef set<int> si;
typedef map<int, int> mii;
typedef pair<int, int> pii;
typedef pair<int, pii> pi3;
typedef vector< pair<int, int> > vpii;
typedef long long LL;

const int N = 100005, INF = ~0U >> 2;

int n, m;
int val[N];
vi g[N];

int e;
int L[N], R[N], b[N];
int a[N * 4];

void dfs(int p) {
	int v;
	L[p] = ++e;
	b[e] = val[p];
	repit (it, g[p]) {
		v = *it;
		dfs(v);
	}
	R[p] = e;
}

void init(int k, int s, int t) {
	int mid = (s + t) >> 1;
	if (s == t) a[k] = b[s];
	else {
		init(k << 1, s, mid);
		init(k << 1 | 1, mid + 1, t);
		a[k] = min(a[k << 1], a[k << 1 | 1]);
	}
}

void update(int k, int s, int t, int p, int val) {
	//sc4(k, s, t, p);
	int mid = (s + t) >> 1;
	if (t < p || s > p) return ;
	if (s == t) a[k] = val;
	else {
		update(k << 1, s, mid, p, val);
		update(k << 1 | 1, mid + 1, t, p, val);
		a[k] = min(a[k << 1], a[k << 1 | 1]);
	}
}

int gao(int k, int s, int t, int l, int r) {
	int mid = (s + t) >> 1, ans;
	if (s > r || t < l) return INF;
	if (s >= l && t <= r) return a[k];
	ans = gao(k << 1, s, mid, l, r);
	ans = min(ans, gao(k << 1 | 1, mid + 1, t, l, r));
	return ans;
}

int main() {
	int u, v, cmd;
	while (~in(n)) {
		FOR (i, 1, n) in(val[i]);
		FOR (i, 1, n) g[i].clear();
		FOR (i, 2, n) {
			in(u);
			g[u].pb(i);
		}
		e = 0;
		dfs(1);
		init(1, 1, n);
		in(m);
		while (m--) {
			in(cmd);
			if (cmd == 1) {
				in2(u, v);
				update(1, 1, n, L[u], v);
			} else {
				in(u);
				printf("%d\n", gao(1, 1, n, L[u], R[u]));
			}
		}
	}
	return 0;
}
