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

const int N = 15, M = 105, D = 20005;
const LL INF = ~0ULL >> 1;

int T, n, m, k, t;
int a[M], b[M];
LL dp[D];
LL ans;

bool gao() {
    int id;
    LL res = INF;
    FOR (i, 1, m) if (b[i] >= k) res = min(res, (LL) a[i]);
    //sc(res);
    memset(dp, -1, sizeof(dp));
    dp[0] = 0;
    FOR (i, 1, m) FOR (j, 0, 2 * k) {
        if (dp[j] == -1) continue;
        id = j + b[i];
        if (id <= 2 * k) {
            if (dp[id] == -1 || dp[id] > dp[j] + a[i]) dp[id] = dp[j] + a[i];
        }
    }
    FOR (i, k, 2 * k) if (dp[i] != -1) res = min(res, dp[i]);
    //sc(res);
    if (res == INF) return 0;
    ans += res;
    return 1;
}

int main() {
    int flag;
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d %d", &n, &m, &k, &t);
        FOR (i, 1, m) scanf("%d", &a[i]);
        FOR (i, 1, m) scanf("%d", &b[i]);
        ans = 0,flag = 1;
        rep (i, n) {
            flag = gao();
            if (!flag) break;
            if (i != n - 1) FOR (j, 1, m) b[j] /= t;
        }
        if (!flag) puts("No Answer");
        else cout << ans << '\n';
    }
    return 0;
}
















