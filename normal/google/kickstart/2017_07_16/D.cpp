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

const int N = 15, M = 1005;

int T, n, m;
int L[N], K[N];
int A[N][N], C[N][N];
int dp[N][M];

void getMax(int &x, int y) {
    x = max(x, y);
}

int main() {
    file_r("D-small-attempt0.in");
    file_w("D-small-attempt0.out");
    int cas = 0, t, ans;
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &m, &n);
        FOR (i, 1, n) {
            scanf("%d %d", &K[i], &L[i]);
            FOR (j, 1, K[i]) scanf("%d", &A[i][j]);
            FOR (j, 1, K[i] - 1) scanf("%d", &C[i][j]);
        }
        memset(dp, -1, sizeof(dp));
        dp[0][0] = 0;
        FOR (i, 0, n - 1) FOR (j, 0, m) {
            if (dp[i][j] == -1) continue;
            //sc3(i, j, dp[i][j]);
            t = 0;
            FOR (k, L[i + 1], K[i + 1]) {
                if (j + t > m) continue;
                getMax(dp[i + 1][j + t], dp[i][j] + A[i + 1][k]);
                //if (i + 1 == 3 && j + t == 21 && dp[3][21] == 400) sc4(i, j, k, dp[i][j]);
                //if (i == 3 && j == 21) sc2(k, t);
                if (k != K[i + 1]) t += C[i + 1][k];
            }
        }
        ans = 0;
        FOR (j, 0, m) {
            //if (dp[n][j] != -1) sc2(j, dp[n][j]);
            ans = max(ans, dp[n][j]);
        }
        printf("Case #%d: %d\n", ++cas, ans);
    }
    return 0;
}















