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

#define sc(x) cout << #x" = " << x << endl, pause
#define sc2(x, y) cout << #x" = " << x << " " << #y" = " << y << endl, pause
#define sc3(x, y, z) cout << #x" = " << x << " " << #y" = " << y << " " << #z" = " << z << endl, pause
#define sc4(x, y, z, w) cout << #x" = " << x << " " << #y" = " << y << " " << #z" = " << z << " " << #w" = " << w << endl, pause

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

const int N = 2005;

int T;
int n, ts, tf;
int s[N], f[N], d[N];

int dp[N][N];

void _min(int &x, int y) {
    if (y > tf) return ;
    if (x == -1 || y < x) x = y;
}

int gao() {
    int a, tp, ans;
    memset(dp, -1, sizeof(dp));
    dp[1][0] = 0;
    FOR (i, 1, n - 1) FOR (j, 0, i) {
        if (dp[i][j] == -1) continue;

        // no look
        a = dp[i][j];
        if (a <= s[i]) tp = s[i];
        else {
            tp = s[i] + (a - s[i]) / f[i] * f[i];
            if (tp < a) tp += f[i];  
        }
        tp += d[i];
        _min(dp[i + 1][j], tp);

        //look
        a = dp[i][j] + ts;
        if (a <= s[i]) tp = s[i];
        else {
            tp = s[i] + (a - s[i]) / f[i] * f[i];
            if (tp < a) tp += f[i];
        }
        tp += d[i];
        _min(dp[i + 1][j + 1], tp);       
    }
    ans = -1;
    FOR (i, 0, n - 1) if (dp[n][i] != -1) ans = i;
    return ans;
}

int main() {
    int cas = 0, ans;
    in(T);
    while (T--) {
        in3(n, ts, tf);
        FOR (i, 1, n - 1) in3(s[i], f[i], d[i]);
        ans = gao();
        printf("Case #%d: ", ++cas);
        if (ans == -1) puts("IMPOSSIBLE");
        else printf("%d\n", ans);
    }
    return 0;
}











