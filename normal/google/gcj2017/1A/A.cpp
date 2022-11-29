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

const int N = 30;

int T, n, m;
char g[N][N];

struct Node {
	pii l, r;
	Node() {}
	Node(pii A, pii B): l(A), r(B) {}
};
vector<Node> p;

void step1() {
	int lx, ly, rx, ry;
	p.clear();
	rep (k, 26) {
		lx = 30, ly = 30, rx = -1, ry = -1;
		rep (i, n) rep (j, m) {
			if (g[i][j] != k + 'A') continue;
			if (i < lx || (i == lx && j < ly)) lx = i, ly = j;
			if (i > rx || (i == rx && j > ry)) rx = i, ry = j;
		}
		FOR (i, lx, rx) FOR (j, ly, ry) g[i][j] = k + 'A';
		if (rx != -1) {
			p.pb(Node(mp(lx, ly), mp(rx, ry)));
			// printf("x= %d %d %d %d\n", lx, ly, rx, ry);
		}
	}
}

bool check(int lx, int ly, int rx, int ry) {
	if (lx < 0 || rx < 0) return 0;
	if (lx >= n || rx >= n) return 0;
	if (ly < 0 || ry < 0) return 0;
	if (ly >= m || ry >= m) return 0;
	FOR (i, lx, rx) FOR (j, ly, ry) {
		if (g[i][j] != '?') return 0;
	}
	return 1;
}

void step2() {
	int flag, lx, ly, rx, ry;
	int x, y, u, v, sz = p.size();
	while (1) {
		flag = 0;
		rep (k, sz) {
			lx = p[k].l.X, ly = p[k].l.Y;
			rx = p[k].r.X, ry = p[k].r.Y;
			x = lx - 1, y = ly, u = lx - 1, v = ry;
			if (check(x, y, u, v)) {
				flag = 1;
				p[k] = Node(mp(x, y), mp(rx, ry));
				FOR (i, x, u) FOR (j, y, v) g[i][j] = g[lx][ly];
				break;
			}

			x = rx + 1, y = ly, u = rx + 1, v = ry;
			if (check(x, y, u, v)) {
				flag = 1;
				p[k] = Node(mp(lx, ly), mp(u, v));
				FOR (i, x, u) FOR (j, y, v) g[i][j] = g[lx][ly];
				break;
			}

			x = lx, y = ly - 1, u = rx, v = ly - 1;
			if (check(x, y, u, v)) {
				flag = 1;
				p[k] = Node(mp(x, y), mp(rx, ry));
				FOR (i, x, u) FOR (j, y, v) g[i][j] = g[lx][ly];
				break;
			}

			x = lx, y = ry + 1, u = rx, v = ry + 1;
			if (check(x, y, u, v)) {
				flag = 1;
				p[k] = Node(mp(lx, ly), mp(u, v));
				FOR (i, x, u) FOR (j, y, v) g[i][j] = g[lx][ly];
				break;
			}
		}

		if (!flag) break;
	}
	if (g[0][0] == '?') {
		rep (i, n) rep (j, m) g[i][j] = 'A';
	}
}

int main() {
	int cas = 0;
	in(T);
	while (T--) {
		in2(n, m);
		rep (i, n) scanf("%s", g[i]);
		step1();
		step2();
		printf("Case #%d:\n", ++cas);
		rep (i, n) printf("%s\n", g[i]);
	}
    return 0;
}
