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

const int N = 1005, INF = 2139062143;

int n, m;
int a[N][N], dp[N][N];

void get_min(int &x, int y) {
    x = min(x, y);
}

int main() {
    while (~scanf("%d %d", &n, &m)) {
        rep (i, n) rep (j, m) scanf("%d", &a[i][j]);
        memset(dp, 127, sizeof(dp));
        if (0 + 1 < m) dp[0][1] = a[0][0] * a[0][1];
        if (0 + 1 < n) dp[1][0] = a[0][0] * a[1][0];
        rep (i, n) rep (j, m) {
            if (dp[i][j] == INF) continue;
            if (j + 2 < m) get_min(dp[i][j + 2], dp[i][j] + a[i][j + 1] * a[i][j + 2]);
            if (i + 2 < n) get_min(dp[i + 2][j], dp[i][j] + a[i + 1][j] * a[i + 2][j]);
            if (i + 1 < n && j + 1 < m) {
                get_min(dp[i + 1][j + 1], dp[i][j] + a[i][j + 1] * a[i + 1][j + 1]);
                get_min(dp[i + 1][j + 1], dp[i][j] + a[i + 1][j] * a[i + 1][j + 1]);
            }
        }
        printf("%d\n", dp[n - 1][m - 1]);
    }
    return 0;
}
