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

const int N = 55, INF = ~0U >> 2;

int n, m;
char g[N][N];
int dp[N][N][N][N];
bool f[N][N][N][N];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int gao() {
	if (n == 1 && m == 1) return 0;
	int u, v, x, y, w, a, b, c, d, tmp;
	dp[0][0][n - 1][m - 1] = 0;
	f[0][0][n - 1][m - 1] = 1;
	queue< pair<pii, pii> > q;
	q.push(mp(mp(0, 0), mp(n - 1, m - 1)));
	while (!q.empty()) {
		u = q.front().X. X, v = q.front().X.Y;
		x = q.front().Y.X, y = q.front().Y.Y;
		q.pop();
		f[u][v][x][y] = 0;
		w = dp[u][v][x][y];
		rep (k, 4)  {
			a = u + dx[k], b = v + dy[k];
			c = x - dx[k], d = y - dy[k];
			if (a < 0) a = 0;
			if (a == n) a = n - 1;
			if (c < 0) c = 0;
			if (c == n) c = n - 1;
			if (b < 0) b = 0;
			if (b == m) b = m - 1;
			if (d < 0) d = 0;
			if (d == m) d = m - 1;
			
			if (g[a][b] == '1') a = u, b = v;
			if (g[c][d] == '1') c = x, d = y;
			
			if (a == c && b == d) continue;
			if (a == x && b == y && c == u && d == v) continue;

			tmp = w + 1;
			if (dp[a][b][c][d] == 0 || tmp < dp[a][b][c][d]) {
				dp[a][b][c][d] = tmp;
				if (!f[a][b][c][d]) {
					f[a][b][c][d] = 1;
					q.push(mp(mp(a, b), mp(c, d)));
				}
			}
		}
	}
	if (dp[n - 1][m - 1][0][0] != 0) return dp[n - 1][m - 1][0][0];
	return -1;
}

int main() {
	int ans;
	in2(n, m);
	rep (i, n) scanf("%s", g[i]);
	ans = gao();
	printf("%d\n", ans);
	return 0;
}
