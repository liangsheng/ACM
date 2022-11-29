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
#define eps 1e-8
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
#define sqr(r) ((LL) (r) * (r))
#define dis(x1, y1, x2, y2) (((x1) - (x2)) * ((x1) - (x2)) + ((y1) - (y2)) * ((y1) - (y2)))
#define FASTIO ios::sync_with_stdio(false);cin.tie(0)

#define sc(x) cout << #x" = " << x << endl, system("pause")
#define sc2(x, y) cout << #x" = " << x << " " << #y" = " << y << endl, system("pause")
#define sc3(x, y, z) cout << #x" = " << x << " " << #y" = " << y << " " << #z" = " << z << endl, system("pause")
#define sc4(x, y, z, w) cout << #x" = " << x << " " << #y" = " << y << " " << #z" = " << z << " " << #w" = " << w << endl, system("pause")

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

const int N = 100005, M = N * 2, MOD = 1000000007, D = 20;

int n, m, e;
int head[N];
int fr[M], pnt[M], nxt[M], wv[M], tm[M];

int dp[N][D], dep[N];
int val0[N], val1[N];

void add(int &x, int y) {
	x = ((LL) x + y) % MOD;
}

int mul(int x, int y) {
	return (LL) x * y % MOD;
}

void init() {
	e = 0, dep[0] = -1, dp[1][0] = 0;
	val0[0] = val1[0] = 0;
	memset(head, -1, sizeof(head));
}

void add_edge(int u, int v, int w, int t) {
	fr[e] = u, pnt[e] = v, wv[e] = w, tm[e] = t;
	nxt[e] = head[u], head[u] = e++;
}

void dfs(int x, int id) {
    dep[x] = dep[dp[x][0]] + 1;
    if (x == 1) val0[1] = val1[1] = 0;
    else {
    	add(val1[x], val1[fr[id]]);
    	add(val0[x], val0[fr[id]]);
    	if (tm[id] % 2) add(val1[x], wv[id]);
    	else add(val0[x], wv[id]);
    }

    for (int i = 1; i < D; i++)
        dp[x][i] = dp[dp[x][i - 1]][i - 1];

    int v;
    repe (i, x) {
        v = pnt[i];
        if (v == dp[x][0]) continue;
        dp[v][0] = x;
        dfs(v, i);
    }
}

int LCA(int a, int b) {
    if (dep[a] < dep[b]) swap(a, b);
    for (int i = D - 1; i >= 0; i--) {
        if (dep[dp[a][i]] >= dep[b]) a = dp[a][i];
    }
    // cout << "a= " << a << ' ' << b << '\n';
    // cout << dp[4][0] << ' ' << dp[5][0] << '\n';c
    if (a == b) return a;
    for (int i = D - 1; i >= 0; i--) {
        if (dp[a][i] != dp[b][i]) a = dp[a][i], b = dp[b][i];
    }
    return dp[a][0];
}

int main() {
	int u, v, w, t, r0, r1, lca;
	int tol0, tol1, ans, res;
	while (~in(n)) {
		init();
		tol0 = tol1 = ans = 0;
		rep (i, n - 1) {
			scanf("%d %d %d %d", &u, &v, &w, &t);
			add_edge(u, v, w, t);
			add_edge(v, u, w, t);
			if (t % 2) add(tol1, w);
			else add(tol0, w);
			add(ans, mul(w, t));
		}
		dfs(1, -1);
		// FOR (i, 1, n) cout << "i= " << i << dep[i] << '\n';
		in(m);
		// cout << ans << ' ' << tol0 << ' ' << tol1 << '\n';
		while (m--) {
			in2(u, v);
			lca = LCA(u, v);
			// cout << "lca= " << lca << '\n';
			r0 = (((LL) val0[u] + val0[v] - 2LL * val0[lca]) % MOD + MOD) % MOD;
			r1 = (((LL) val1[u] + val1[v] - 2LL * val1[lca]) % MOD + MOD) % MOD;
			res = (((LL) ans + r0 + tol1 - r1) % MOD + MOD) % MOD;
			// cout << "r0= " << r0 << ' ' << r1 << ' ' << lca << '\n';
			printf("%d\n", res);
		}
	}
	return 0;
}























