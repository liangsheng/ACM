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
#include <unordered_map>
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

const int N = 305, M = 100005, INF = 522133279;

int T, n, m;
int lcp[N][N], dp[N][N], sz[N];
string s[N];

int gao(int i, int j) {
    int l = 0;
    while (s[i][l] && s[j][l] && s[i][l] == s[j][l]) l++;
    return l;
}

int main() {
    file_r("text_editor.in");
    int cas = 0, ans, r;
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &m);
        FOR (i, 1, n) cin >> s[i];
        sort(s + 1, s + n + 1);
        FOR (i, 1, n) sz[i] = SZ(s[i]);
        FOR (i, 1, n) lcp[i][i] = SZ(s[i]), lcp[0][i] = 0;
        FOR (i, 1, n - 1) lcp[i][i + 1] = gao(i, i + 1);
        FOR (k, 3, n) FOR (i, 1, n - k + 1) lcp[i][i + k - 1] = min(lcp[i][i + k - 2], lcp[i + 1][i + k - 1]);
        memset(dp, 31, sizeof(dp));
        dp[0][0] = 0, ans = INF;
        FOR (i, 1, n) {
            r = min(i, m);
            FOR (j, 1, r) {
                FOR (k, 0, i - 1) {
                    if (dp[k][j - 1] == INF) continue;
                    dp[i][j] = min(dp[i][j], dp[k][j - 1] - 2 * lcp[k][i] + 2 * sz[i] + 1);
                }
            }
        }
        FOR (i, m, n) ans = min(ans, dp[i][m]);
        printf("Case #%d: %d\n", ++cas, ans);
    }
    return 0;
}
