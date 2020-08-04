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

const int N = 105, M = 12, T = N * M * 2, INF = ~0U >> 2;

int D, p, q, n, e;
int o[N], a[T];
int dp[T];
set<int> s;
set<int> f[M][M];

void init() {
	int R;
	set<int> t;
	FOR (i, 1, 10) FOR (j, i + 1, 10) {
		f[i][j].clear();
		FOR (k, 1, i - 1) f[i][j].insert(k);
		t.clear();
		FOR (k, 1, 100) {
			if (i * k <= j * (k - 1)) {
				R = j * (k - 1);
				break;
			}
			FOR (l, i * k, j * k) t.insert(l);
		}
		FOR (k, 1, R) if (!t.count(k)) f[i][j].insert(k);
	}
}

bool ok(int x, int y, int p, int q) {
	if (f[p][q].count(y - x)) return 0;
	return 1;
}


int main() {
	init();
	repit (it, f[9][10]) cout << *it << ' ';
	puts("");
	while (~scanf("%d;%d %d;%d;", &D, &p, &q, &n)) {
		e = 0;
		rep (i, q + 1) a[e++] = i;

		s.clear();
		rep (i, n) {
			in(o[i]);
			s.insert(o[i]);
			FOR (j, o[i] - q, o[i] + q) {
				if (j < 0) continue;
				a[e++] = j;
			}
		}
		if (p == q) {
			int ans = 0;
			rep (i, n) ans += (o[i] % p == 0);
			printf("%d\n", ans);
			continue;
		}

		FOR (j, D - q, D + q) {
			if (j < 0) continue;
			a[e++] = j;
		}
		sort(a, a + e);
		e = unique(a, a + e) - a;

		rep (i, e) dp[i]= INF;
		dp[0] = 0;
		FOR (i, 1, e - 1) {
			int d = s.count(a[i]);
			FOR (j, max(i - q, 0), i - 1) {
				if (!ok(a[j], a[i], p, q)) continue;
				dp[i] = min(dp[i], dp[j] + d);
			}
			// cout << "i= " << a[i] << ' ' << dp[i] << '\n';
		}
		int ans = INF;
		rep (i, e) if (a[i] >= D) ans = min(ans, dp[i]);
		printf("%d\n", ans);
	}
    return 0;
}


