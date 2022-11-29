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

int n, m;
int x[N], y[N];
double dp[N][N];

double gao(int i, int j, int k) {
    double a,b,c,p,s;
    double x1 = x[i], y1 = y[i];
    double x2 = x[j], y2 = y[j];
    double x3 = x[k], y3 = y[k];
    a=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
    b=sqrt((x1-x3)*(x1-x3)+(y1-y3)*(y1-y3));
    c=sqrt((x3-x2)*(x3-x2)+(y3-y2)*(y3-y2));
    p=(a+b+c)/2;
    s=sqrt(p*(p-a)*(p-b)*(p-c));
    return s;
}

int main() {
    int u, v, r;
    double ans, tmp;
    while (~scanf("%d %d", &n, &m)) {
        rep (i, n) scanf("%d %d", &x[i], &y[i]);
        ans = 0.0;
        rep (k, n) {
            u = x[0], v = y[0];
            FOR (i, 1, n - 1) x[i - 1] = x[i], y[i - 1] = y[i];
            x[n - 1] = u, y[n - 1] = v;
            memset(dp, -1, sizeof(dp));
            dp[0][1] = 0;
            dp[1][2] = 0;
            FOR (i, 2, n - 1) {
                dp[i][2] = 0;
                r = min(m, i + 1);
                tmp = 0;
                FOR (j, 3, r) {
                    FOR (k, j - 2, i - 1) tmp = max(tmp, dp[k][j - 1] + gao(0, k, i));
                    dp[i][j] = tmp;
                    ans = max(ans, tmp);
                }
            }
        }
        printf("%.2f\n", ans);
    }
    return 0;
}
