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

const int N = 1005, MOD = 1000000007;

int n, T;
int dp[N], d[N], f[N], t[N][N];
vi a[N];
char s[N];

bool ok(int l1, int r1, int l2, int r2) {
    int t1 = (f[r1] - f[l1 - 1]) * d[n - r1];
    int t2 = (f[r2] - f[l2 - 1]) * d[n - r2];
    return t1 == t2;
}

void init() {
    d[0] = 1;
    FOR (i, 1, 1000) d[i] = d[i - 1] * MOD;
    f[0] = 0;
    FOR (i, 1, n) f[i] = f[i - 1] + (s[i] - 'A') * d[i];
    a[1].pb(1);
    FOR (i, 2, 1000) {
        FOR (j, 1, i - 1) if (i % j == 0) a[i].pb(j);
    }

    FOR (i, 1, n) FOR (j, i, n) t[i][j] = j - i + 1;
    FOR (k, 2, n) FOR (i, 1, n - k + 1) {
        int L = i, R = i + k - 1;
        repit (it, a[R - L + 1]) {
            if (*it % t[L + *it][R]) continue;
            if (ok(L, L + *it - 1, L + *it, L + *it + *it - 1)) {
                t[L][R] = *it;
                break;
            }
        }
        // printf("L= %d R= %d %d\n", L, R, t[L][R]);
    }
}

void solve() {
    dp[0] = 1;
    FOR (i, 1, n) {
        dp[i] = 0;
        FOR (j, 1, i - 1) if (t[j][i] < i - j + 1) dp[i] = ((LL) dp[i] + dp[j - 1]) % MOD;
    }
}

int main() {
    in(T);
    while (T--) {
        in(n);
        scanf("%s", s + 1);
        init();
        solve();
        // FOR (i, 1, n) cout << dp[i] << ' ';
        // puts("");
        printf("%d\n", dp[n]);
    }
    return 0;
}
