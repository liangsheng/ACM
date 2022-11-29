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

const int N = 105;

int T, n;
char s[N];
int a[N], b[N], c[N];

int gao(int x[N]) {
    int ans = 0, t = 1;
    rep (i, n) ans += t * x[i], t <<= 1;
    return ans;
}

void fgao(int x) {
    int e = 0;
    memset(b, 0, sizeof(b));
    while (x != 0) b[e++] = x & 1, x >>= 1;
    rep (i, n) swap(b[i], b[n - 1 - i]);
}

int main() {
    file_r("B-large.in");
    file_w("B.out");
    int cas = 0, ans;
    scanf("%d", &T);
    while (T--) {
        scanf("%s", s);
        printf("Case #%d: ", ++cas);

        ans = 0;
        n = strlen(s);
        rep (i, n) a[i] = (s[i] == '+');
//        FORD (i, n - 1, 0) {
//            if (a[i]) continue;
//            ans++;
//            if (a[0]) a[0] = 0, ans++;
//            rep (j, (i + 1) / 2) swap(a[j], a[i - j]);
//            rep (j, i + 1) a[j] ^= 1;
//            //sc2(i, s);
//        }
//
        ans = !a[n - 1];
        rep (i, n - 1) ans += a[i] ^ a[i + 1];
        printf("%d\n", ans);
//        int res = 0, x, y, dp[1 << n], vis[1 << n];
//        memset(dp, 127, sizeof(dp));
//        memset(vis, 0, sizeof(vis));
//        queue<int> q;
//        rep (i, n) a[i] = (s[i] == '+');
//        x = gao(a);
//        vis[x] = 1, dp[x] = 0, q.push(x);
//        while (!q.empty()) {
//            x = q.front(), q.pop(), vis[x] = 0;
//            fgao(x);
//            //rep (i, n) cout << b[i] << ' ';
//            //sc2(x, dp[x]);
//            rep (k, n) {
//                rep (i, n) c[i] = b[i];
//                rep (i, (k + 1) / 2) swap(c[i], c[k - i]);
//                rep (i, k + 1) c[i] ^= 1;
//                y = gao(c);
//                //sc2(k ,y);
//                if (dp[x] + 1 < dp[y]) {
//                    dp[y] = dp[x] + 1;
//                    if (!vis[y]) vis[y] = 1, q.push(y);
//                }
//            }
//        }
//        printf("%d %d\n", ans, dp[(1 << n) - 1]);
    }
    return 0;
}



















