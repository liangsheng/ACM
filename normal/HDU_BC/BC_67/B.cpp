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

const int N = 10, M = 30;

int T, s0, s1;
char s[N];
double dp1[M], dp[2][M];
map<char, int> q;

int main() {
    q['A'] = 1, q['T'] = 10, q['J'] = 10, q['Q'] = 10, q['K'] = 10;
    FOR (i, 2, 9) q[char(i + '0')] = i;
    double ans, tmp;
    int now, pre;
    scanf("%d", &T);
    while (T--) {
        scanf("%s", s);
        s0 = q[s[0]] + q[s[1]];
        s1 = q[s[2]] + q[s[3]];
        FOR (i, 2, 21) dp1[i] = 0.0;
        dp1[s1] = 1;
        //sc2(s0, s1);
        FOR (i, 2, 20) {
            FOR (j, 1, 9) if (i + j <= 21) {
                dp1[i + j] += dp1[i] * 1.0 / 13.0;
            }
            if (i + 10 <= 21) dp1[i + 10] += dp1[i] * 4.0 / 13.0;
        }
        FOR (i, 2, 21) cout << "i= " << i << ' ' << dp1[i] << '\n';
        FORD (i, 20, 1) dp1[i] += dp1[i + 1];
        ans = 0, now = 0, pre = 1;
        FOR (i, 2, 21) dp[now][i] = 0.0;
        dp[now][s0] = 1;
        ans = 1.0 - dp1[s0];
        sc(ans);
        FOR (k, 1, 21) {
            swap(now, pre);
            FOR (i, 2, 21) dp[now][i] = 0;
            FOR (i, 2, 20) {
                FOR (j, 1, 9) if (i + j <= 21) {
                    dp[now][i + j] += dp[pre][i] * 1.0 / 13.0;
                }
                if (i + 10 <= 21) dp[now][i + 10] += dp[pre][i] * 4.0 / 13.0;
            }
            tmp = 0;
            FOR (i, 2, 21) {
                tmp += dp[now][i] * (1.0 - dp1[i]);
            }
            ans = max(ans, tmp);
        }
        puts(ans > 0.5 ? "YES" : "NO");
    }
    return 0;
}
