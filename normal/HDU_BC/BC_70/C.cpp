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

const int N = 505, MOD = 5201314;

int T, n, m;
char g[N][N];
int dp[2][N][N];

inline void add(int &x, int y) {
    x = ((LL) x + y) % MOD;
}

int main() {
    int ans, now, pre, x, y, u, v;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        FOR (i, 1, n) scanf("%s", g[i] + 1);
        if (g[1][1] != g[n][n]) {
            puts("0");
            continue;
        }
        now = 0, pre = 1;
        memset(dp[now], 0, sizeof(dp[now]));
        dp[now][1][n] = 1;
        FOR (k, 1, n - 1) {
            swap(now, pre);
            memset(dp[now], 0, sizeof(dp[now]));
            FOR (i, 1, n) FOR (j, i, n) {
                if (!dp[pre][i][j]) continue;
                //sc4(k, i, j, dp[pre][i][j]);
                x = i, y = k + 2 - i - 1;
                u = j, v = 2 * n - j - k + 1;
                if (x + 1 <= n && v - 1 >= 1 && (g[x + 1][y] == g[u][v - 1])) {
                    add(dp[now][x + 1][u], dp[pre][x][u]);
                }
                if (x + 1 <= n && u - 1 >= x + 1 && (g[x + 1][y] == g[u - 1][v])) {
                    add(dp[now][x + 1][u - 1], dp[pre][x][u]);
                }
                //sc4(x, y, u, v);
                if (y + 1 <= n && v - 1 >= y + 1 && (g[x][y + 1] == g[u][v - 1])) {
                    //puts("FFF");
                    add(dp[now][x][u], dp[pre][x][u]);
                }
                if (y + 1 <= n && u - 1 >= 1 && (g[x][y + 1] == g[u - 1][v])) {
                    add(dp[now][x][u - 1], dp[pre][x][u]);
                }
            }
        }
        ans = 0;
        FOR (i, 1, n) add(ans, dp[now][i][i]);
        cout << ans << '\n';
    }
    return 0;
}













