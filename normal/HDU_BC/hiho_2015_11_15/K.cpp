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

const int N = 65, M = 65537 + 5;

int T, m, e;
int a[N];
LL n;
LL dp[2][M];

int main() {
    int now, pre;
    LL tmp, ans;
    scanf("%d", &T);
    while (T--) {
        scanf("%lld %d", &n, &m);
        e = 0, tmp = n;
        while (tmp != 0) {
            a[e++] = tmp & 1;
            tmp >>= 1LL;
        }
        now = 0, pre = 1;
        memset(dp[now], 0, sizeof(dp[now]));
        dp[now][0] = 1, tmp = 1;
        FORD (i, e - 1, 1) {
            swap(now, pre);
            memset(dp[now], 0, sizeof(dp[now]));
            rep (j, m) {
                dp[now][j * 3 % m] += dp[pre][j];
                dp[now][(j * 3 + 1) % m] += dp[pre][j];
            }
            if (a[i - 1] > 0) dp[now][tmp * 3 % m] += 1;
            tmp = (tmp * 3 + a[i - 1]) % m;
        }
        dp[now][0]--, dp[now][tmp]++, ans = 0;
        rep (j, m) ans ^= dp[now][j];
        printf("%lld\n", ans);
    }
    return 0;
}
