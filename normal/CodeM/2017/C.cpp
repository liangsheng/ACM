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

const int N = 55;

int T, n, m, ans;
char s[2][N];
int dp[N][N][N][N];

void gao() {
	ans = 1;
	memset(dp, -1, sizeof(dp));
	dp[0][0][n + 1][m + 1] = 0;
	dp[1][0][n + 1][m + 1] = 1;
	dp[0][1][n + 1][m + 1] = 1;
	dp[0][0][n][m + 1] = 1;
	dp[0][0][n + 1][m] = 1;
	FOR (i, 0, n) FOR (j, 0, m) FORD (x, n + 1, i + 1) FORD (y, m + 1, j + 1) {
		if (dp[i][j][x][y] != -1) continue;

		if (i - 1 >= 0) dp[i][j][x][y] = dp[i - 1][j][x][y];
		if (j - 1 >= 0 )dp[i][j][x][y] = max(dp[i][j][x][y], dp[i][j - 1][x][y]);
		if (x + 1 <= n + 1) dp[i][j][x][y] = max(dp[i][j][x][y], dp[i][j][x + 1][y]);
		if (y + 1 <= m) dp[i][j][x][y] = max(dp[i][j][x][y], dp[i][j][x][y + 1]);
		if (i >= 1 && x <= n && s[0][i - 1] == s[0][x - 1]) {
			dp[i][j][x][y] = max(dp[i][j][x][y], dp[i - 1][j][x + 1][y] + 2);
		}
		if (i >= 1 && y <= m && s[0][i - 1] == s[1][y - 1]) {
			dp[i][j][x][y] = max(dp[i][j][x][y], dp[i - 1][j][x][y + 1] + 2);
		}
		if (j >= 1 && x <= n && s[1][j - 1] == s[0][x - 1]) {
			dp[i][j][x][y] = max(dp[i][j][x][y], dp[i][j - 1][x + 1][y] + 2);
		}
		if (j >= 1 && y <= m && s[1][j - 1] == s[1][y - 1]) {
			dp[i][j][x][y] = max(dp[i][j][x][y], dp[i][j - 1][x][y + 1] + 2);
		}

		ans = max(ans, dp[i][j][x][y]);
	}
}

int main() {
	in(T);
	while (T--) {
		scanf("%s", s[0]);
		scanf("%s", s[1]);
		n = strlen(s[0]);
		m = strlen(s[1]);
		gao();
		printf("%d\n", ans);
	}
	return 0;
}
