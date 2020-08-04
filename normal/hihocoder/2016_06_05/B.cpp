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

const int N = 205, MOD = 1000000007;

int n;
int a[N];
int dp[2][N][2];

void add(int &x, int y) {
    x = ((LL) x + y) % MOD;
}

int main() {
    int now, pre, ans;
    while (~scanf("%d", &n)) {
        rep (i, n) scanf("%d", &a[i]);
        now = 0, pre = 1;
        memset(dp[now], 0, sizeof(dp[now]));
        dp[now][0][0] = 1;
        rep (i, n) {
            swap(now, pre);
            memset(dp[now], 0, sizeof(dp[now]));
            rep (j, i + 1) {
                if (dp[pre][j][0] != 0) {
                    //printf("GG0 %d %d\n", j, dp[pre][j][0]);
                    //add(dp[now][j][0], dp[pre][j][0]);
                    //sc2(j, dp[now][j][0]);
                    add(dp[now][j + 1][0], (LL) dp[pre][j][0] * (2 - a[i]) % MOD);
                    add(dp[now][j + 1][1], (LL) dp[pre][j][0] * a[i] % MOD);
                }
                if (dp[pre][j][1] != 0) {
                    //printf("GG1 %d %d\n", j, dp[pre][j][1]);
                    add(dp[now][j][1], dp[pre][j][1]);
                    add(dp[now][j + 1][1], (LL) dp[pre][j][1] * a[i] % MOD);
                }
            }
            add(dp[now][1][0], dp[pre][i][1]);
            printf("i= %d\n", i);
            //sc2(dp[now][0][0], dp[now][1][0]);
            rep (j, n + 1) {
                if (dp[now][j][0] != 0) printf("j= %d 0 %d\n", j, dp[now][j][0]);
                if (dp[now][j][1] != 0) printf("j= %d 1 %d\n", j, dp[now][j][1]);
            } system("pause");
        }
        ans = 0;
        FOR (i, 1, n) {
            add(ans, (LL) dp[now][i][0] * i % MOD);
            add(ans, (LL) dp[now][i][1] * i % MOD);
        }
        printf("%d\n", ans);
    }
    return 0;
}











