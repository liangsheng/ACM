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

const int N = 300005;

int n;
int a[N];
LL dp[2][3];

void gao() {
    int now = 0, pre = 1;
    LL tmp;
    memset(dp[now], -1, sizeof(dp[now]));
    dp[now][0] = a[1] / 2;
    if (a[1] & 1) dp[now][1] = a[1] / 2;
    FOR (i, 2, n) {
        swap(now, pre);
        memset(dp[now], -1, sizeof(dp[now]));

        if (a[i] & 1) {
            tmp = dp[pre][0] + a[i] / 2;
            if (dp[pre][1] != -1) tmp = max(tmp, dp[pre][1] + a[i] / 2 + 1);
            dp[now][0] = tmp;

            dp[now][1] = dp[pre][0] + a[i] / 2;
            if (dp[pre][1] != -1) dp[now][2] = dp[pre][1] + a[i] / 2 + 1;
        } else {
            dp[now][0] = dp[pre][0] + a[i] / 2;
            if (dp[pre][2] != -1) dp[now][1] = dp[pre][2] + a[i] / 2;
            if (dp[pre][1] != -1) dp[now][2] = dp[pre][1] + a[i] / 2;
        }
    }
    LL ans = dp[now][0];
    ans = max(ans, dp[now][1]);
    ans = max(ans, dp[now][2]);
    cout << ans << '\n';
}

int main() {
    while (cin >> n) {
        FOR (i, 1, n) cin >> a[i];
        gao();
    }
    return 0;
}














