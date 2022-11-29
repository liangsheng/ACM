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

const int N = 25, M = 21;

int T;
char s[10];
double d[N][N], dp[N][N];
map<char, int> q;

int main() {
    int s0, s1, now, pre, t;
    double p0 = 1.0 / 13.0, ans, tmp;
    q['A'] = 1, q['T'] = q['J'] = q['Q'] = q['K'] = 10;
    FOR (i, 2, 9) q[char(i + '0')] = i;
    memset(d, 0, sizeof(d));
    FOR (i, 1, M) FOR (j, 1, i) d[i][j] = 1;
    FORD (i, M - 1, 2) FOR (j, i + 1, M) {
        d[i][j] = 0;
        FOR (k, 1, 13) {
            t = min(k, 10);
            if (i + t > M) break;
            d[i][j] += d[i + t][j] * p0;
        }
    }
    //sc(d[20][21]);
    memset(dp, 0, sizeof(dp));
    FORD (i, M, 2) FOR (j, 2, M) {
        dp[i][j] = 0;
        FOR (k, 1, 13) {
            t = min(k, 10);
            if (i + t > M) break;
            dp[i][j] += dp[i + t][j] * p0;
        }
        dp[i][j] = max(dp[i][j], 1 - d[j][i]);
    }
    scanf("%d", &T);
    while (T--) {
        scanf("%s", s);
        s0 = q[s[0]] + q[s[1]];
        s1 = q[s[2]] + q[s[3]];
        //sc(dp[s0][s1]);
        puts(dp[s0][s1] > 0.5 ? "YES" : "NO");
    }
    return 0;
}
