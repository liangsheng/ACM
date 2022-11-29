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


const int _N = 50 * 5000, _M = 1500000;

struct Tarjan {
	int n, e, idx;
	int head[_N], dfn[_N], low[_N];
	int so[_M], pnt[_M], wv[_M], nxt[_M];
	int vis[_N], dis[_N];

	int head_[_N], nxt_[_N];
	int vis_[_N], dis_[_N];

	void init() {
		e = 0, idx = 0;
		memset(head_, -1, sizeof(head_));
		memset(head, -1, sizeof(head));
		memset(dfn, 0, sizeof(dfn));
	}

	void add_edge(int u, int v, int w) {
		// printf("u= %d %d %d e= %d\n", u, v, w, e);
		so[e] = u, pnt[e] = v, wv[e] = w;
		nxt[e] = head[u], head[u] = e;

		nxt_[e] = head_[v], head_[v] = e++;
	}

	void tarjan(int u, int fa) {
		low[u] = dfn[u] = ++idx;
		repe (i, u) {
			int v = pnt[i];
			if (v == fa) continue;

			if (dfn[v]) low[u] = min(low[u], dfn[v]);
			else {
				tarjan(v, u);
				low[u] = min(low[u], low[v]);
				if (low[v] > dfn[u]) puts("yes");
			}
		}
	}

	void spfa_dst(int src, int dst) {
		int u, v, w, tmp;
		queue<int> q;
		memset(vis, 0, sizeof(vis));
		memset(dis_, -1, sizeof(dis_));
		vis[dst] = 1, dis_[dst] = 0;
		q.push(dst);
		while (!q.empty()) {
			v = q.front(), q.pop(), vis[v] = 0;

			for (int i = head_[v]; i != -1; i = nxt_[i]) {
				u = so[i], w = wv[i];
				tmp = w + dis_[v];
				if (dis_[u] == -1 || tmp < dis_[u]) {
					dis_[u] = tmp;
					if (!vis[u]) {
						vis[u] = 1;
						q.push(u);
					}
				}
			}
		}
	}

	void spfa_src(int src, int dst) {
		int u, v, w, tmp;
		queue<int> q;
		memset(vis, 0, sizeof(vis));
		memset(dis, -1, sizeof(dis));
		vis[src] = 1, dis[src] = 0;
		q.push(src);
		while (!q.empty()) {
			u = q.front(), q.pop(), vis[u] = 0;

			if ((u - 48) % 49 == 0) continue;
			if (dis_[u + 1] == -1) continue;

			repe (i, u) {
				v = pnt[i], w = wv[i];
				tmp = dis[u] + w;
				if (dis[v] == -1 || tmp < dis[v]) {
					dis[v] = tmp;
					if (!vis[v]) {
						vis[v] = 1;
						q.push(v);
					}
				}
			}
		}
	}

} G;


const int N = 50 * 500, M = 15005;

int n, m, src, dst;
int fr[M], to[M], co[M], st[M], en[M];

int change(string s) {
	int d = (s[0] - '0') * 10  + s[1] - '0';
	return d * 2 + (s[3] == '3');
}

int change(int a, int b) {
	return 49 * (a - 1) + b;
}

int main() {
	int u, v, w;
	string a, b;
	while (~in2(n, m)) {

		rep (i, m) {
			cin >> fr[i] >> to[i] >> co[i] >> a >> b;
			st[i] = change(a);
			en[i] = change(b);
		}
		
		G.init();
		rep (i, m) {
			if (to[i] < n && st[i] == 48) continue;
			if (fr[i] > 1 && st[i] == 0) continue;

			G.add_edge(change(fr[i], st[i] - (fr[i] != 1)), change(to[i], en[i]), co[i]);
		}

		FOR (i, 1, n) rep (j, 48) G.add_edge(change(i, j), change(i, j + 1), 0);

		src = 0, dst = (n - 1) * 49 + 48;
		// G.tarjan(src, -1);

		// rep (i, G.e) {
		// 	if (G.tag[i] && G.wv[i] > 0) printf("u= %d %d %d %d\n", G.so[i], G.pnt[i], G.wv[i], G.tag[i]);
		// 	else G.tag[i] = 0;
		// }

		G.spfa_dst(src, dst);

		// printf("FFF dis[32]= %d dis[33]= %d", G.dis[32], G.dis[33]);

		G.spfa_src(src, dst);
		cout << G.dis[dst] << '\n';
	}
	return 0;
}
