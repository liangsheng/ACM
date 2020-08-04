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

const int N = 5005;

int T, n, num, e;
pii a[N][4], p[4];
int b[4] = {0, 1, 2, 3};
int d[24][4], f[24];
int dp[2][24];

void dfs(int p) {
    if (p == 4) {
        rep (i, 4) d[e][i] = b[i];
        e++;
        return ;
    }
    FOR (i, p, 3) {
        swap(b[i], b[p]);
        dfs(p + 1);
        swap(b[i], b[p]);
    }
}

bool ok(pii a[4]) {
    if (a[0].Y > a[1].Y || a[1].Y > a[2].Y || a[2].Y > a[3].Y) return 0;
    return 1;
}

int main() {
    e = 0;
    dfs(0);
    int cas = 0, ans, now, pre, flag, tmp;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        rep (i, n) rep (j, 4) scanf("%d %d", &a[i][j].X, &a[i][j].Y);
        now = 0, pre = 1;
        memset(dp[now], -1, sizeof(dp[now]));
        rep (i, e) {
            rep (j, 4) p[j] = a[0][d[i][j]];
            flag = ok(p);
            if (!flag) continue;
            tmp = 0;
            rep (j, 4) tmp += abs(p[j].Y - j - 1) + abs(p[j].X);
            dp[now][i] = tmp;
        }
        rep (i, n - 1) {
            swap(now, pre);
            memset(dp[now], -1, sizeof(dp[now]));
            memset(f, 0, sizeof(f));
            rep (j, e) {
                rep (k, 4) p[k] = a[i + 1][d[j][k]];
                f[j] = ok(p);
            }
            rep (j, e) {
                if (dp[pre][j] == -1) continue;
                rep (k, e) {
                    if (!f[k]) continue;
                    tmp = dp[pre][j];
                    rep (l, 4) tmp += abs(a[i + 1][d[k][l]].Y - a[i][d[j][l]].Y) + abs(a[i + 1][d[k][l]].X - a[i][d[j][l]].X);
                    if ((dp[now][k] == -1) || (dp[now][k] > tmp)) dp[now][k] = tmp;
                }
            }
        }
        ans = ~0U >> 2;
        rep (j, e) if (dp[now][j] != -1) ans = min(ans, dp[now][j]);
        printf("Case #%d:\n%d\n", ++cas, ans);
    }
    return 0;
}
