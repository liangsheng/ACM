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

const int N = 505, M = 8;

int n, m, k, c;
int w[M];
int g[N][M];
int a[N];
double sc[N];
set<int> s;

void solve() {
	int maxi, sum = 0;
	double tmp;
	pair<double, int> p[N];
	FOR (i, 1, n) sc[i] = 0;
	FOR (i, 1, m) sum += w[i];

	FOR (j, 1, m) {
		maxi = 0;
		FOR (i, 1, n) maxi = max(maxi, g[i][j]);
		if (maxi == 0) continue;
		FOR (i, 1, n) sc[i] += g[i][j] * 1.0 / maxi * w[j] / sum;
	}


	FOR (i, 1, n) p[i] = mp(-sc[i], i);
	sort(p + 1, p + n + 1);
	if (p[k].X != p[k + 1].X) {
		FOR (i, 1, k) a[p[i].Y]++;

	} else {
		FOR (i, 1, k) {
			if (p[i].X < p[k].X) a[p[i].Y]++;
			else s.insert(p[i].Y);
		}
		FOR (i, k + 1, n) {
			if (p[i].X == p[k].X) s.insert(p[i].Y);
			else break;
		}
	}
	// FOR (i, 1, n) cout << -p[i].X << ' ' << p[i].Y << '\n';
}

int main() {
	int x, y;
	while (~scanf("%d %d %d %d", &n, &m, &k, &c)) {
		s.clear();
		FOR (i, 1, m) in(w[i]);
		FOR (i, 1, n) FOR (j, 1, m) {
			in(g[i][j]);
			if (g[i][j] == -1) x = i, y = j;
		}
		if (k == n) {
			rep (i, n) puts("1");
			continue;
		}
		memset(a, 0, sizeof(a));
		FOR (i, 0, c) {
			g[x][y] = i;
			solve();
		}
		FOR (i, 1, n) {
			if (a[i] == c + 1) puts("1");
			else if (a[i] > 0 || s.count(i) > 0) puts("3");
			else puts("2");
		}
	}
	return 0;
}
