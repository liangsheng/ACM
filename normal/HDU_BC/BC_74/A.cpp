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

const int N = 100005, M = 105, MOD = 1000000007;

int n, m, e, T;
int a[3], b[3];
int c[10], g[10][10], h[10][10];

int main() {
    int x, y, ans, tol;
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &m);
        rep (i, 3) scanf("%d %d", &a[i], &b[i]);
        e = 8;
        c[0] = a[0], c[1] = b[0];
        c[2] = a[1], c[3] = b[1];
        c[4] = a[2], c[5] = b[2];
        rep (i, 6) {
            g[i][i] = 0;
            FOR (j, i + 1, 5) g[i][j] = g[j][i] = abs(c[i] - c[j]);
        }
        g[0][1] = g[1][0] = 1;
        g[2][3] = g[3][2] = 1;
        g[4][5] = g[5][4] = 1;
        FOR (k, 0, 5) FOR (i, 0, 5) FOR (j, 0, 5) g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
        tol = 0;
        FOR (t, 1, m) {
            scanf("%d %d", &x, &y);
            c[6] = x, c[7] = y;
            rep (i, e) rep (j, e) h[i][j] = g[i][j];
            rep (i, 6) h[6][i] = h[i][6] = abs(x - c[i]);
            rep (i, 6) h[7][i] = h[i][7] = abs(y - c[i]);
            h[6][7] = h[7][6] = abs(x - y);
            h[6][6] = h[7][7] = 0;
            FOR (k, 0, 7) FOR (i, 0, 7) FOR (j, 0, 7) h[i][j] = min(h[i][j], h[i][k] + h[k][j]);
            ans = min(abs(x - y), h[6][7]);
            tol = (tol + (LL) t * ans) % MOD;
        }
        printf("%d\n", tol);
    }
    return 0;
}















