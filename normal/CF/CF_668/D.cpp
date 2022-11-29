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

const int N = 300005;

int T, n, a, b, da, db;

const int _N = 100005, _M = _N * 2, D = 20;

struct Graph {
	int e;
	int head[_N], f[_N];
	int fr[_M], pnt[_M], nxt[_M];

	// for lca
	int dp[N][D], dep[N];

	void init() {
		e = 0, dep[0] = -1, dp[1][0] = 0;
		FOR (i, 1, n) head[i] = -1;
	}

	void add_edge(int u, int v) {
		fr[e] = u, pnt[e] = v;
		nxt[e] = head[u], head[u] = e++;
	}

	void dfs(int x, int id) {
	    dep[x] = dep[dp[x][0]] + 1;

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
	    if (a == b) return a;
	    for (int i = D - 1; i >= 0; i--) {
	        if (dp[a][i] != dp[b][i]) a = dp[a][i], b = dp[b][i];
	    }
	    return dp[a][0];
	}

    int cal(int p, int fa) {
        int now = p;
        f[p] = 0;
	    repe (i, p) {
	        int v = pnt[i];
	        if (v == fa) continue;
	        int t = cal(v, p);
            if (f[v] + 1 > f[p]) now = t, f[p] = f[v] + 1;
	    } 
        return now;
    }
} G;

bool gao() {
    G.dfs(1, -1);
    int lca = G.LCA(a, b);
    int dis = G.dep[a] + G.dep[b] - 2 * G.dep[lca];
    // printf("dis= %d a= %d b= %d\n", dis, a, b);
    if (dis <= da) return 1;
    int u = G.cal(1, -1);
    int v = G.cal(u, -1);
    // printf("u= %d v= %d %d\n", u, v, G.f[u]);
    if (db >= 2 * da + 1 && G.f[u] >= 2 * da + 1) return 0;
    return 1;
}

int main() {
    int x, y;
    in(T);
    while (T--) {
        scanf("%d %d %d %d %d", &n, &a, &b, &da, &db);
        G.init();
        rep (i, n - 1) {
            in2(x, y);
            G.add_edge(x, y);
            G.add_edge(y, x);
        }
        puts(gao() ? "Alice" : "Bob");
    }
    return 0;
}
