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
typedef pair<LL, LL> pll;

const int N = 40, M = 2520;

int T, n, m;
char g[N][N];
LL sum;
pll dp[1 << 15][15];
int f[N][N];
pii h[N];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

LL gcd(LL a, LL b) {
    return a % b ? gcd(b, a % b) : b;
}

void add(pll &a, pll b) {
    pll g = mp(a.X * b.Y + a.Y * b.X, a.Y * b.Y);
    LL d = gcd(g.X, g.Y);
    a = mp(g.X / d, g.Y / d);
}

void sub(pll &a, pll b) {
    pll g = mp(a.X * b.Y - a.Y * b.X, a.Y * b.Y);
    LL d = gcd(g.X, g.Y);
    a = mp(g.X / d, g.Y / d);
}

void mul(pll &a, pll b) {
    pll g = mp(a.X * b.X, a.Y * b.Y);
    LL d = gcd(g.X, g.Y);
    a = mp(g.X / d, g.Y / d);
}

void div(pll &a, pll b) {
    pll g = mp(a.X * b.Y, a.Y * b.X);
    LL d = gcd(g.X, g.Y);
    a = mp(g.X / d, g.Y / d);
}

int main() {
//    LL ff = 1;
//    FOR (i, 1, 30) ff *= 3;
//    cout << 5 * 7 * 8* 9 << '\n';
//    cout << ff * 5 * 7 * 8 * 9 << '\n';
//    cout << (~0ULL >> 1) << '\n' << "1000000000000000000";
    int flag, e, tol, x, y, u, v, id, w, z;
    pll ans;
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &m);
        cin >> sum;
        ans = mp(sum, 1);
        rep (i, n) scanf("%s", g[i]);
        e = 0;
        memset(dp, -1, sizeof(dp));
        rep (i, n) rep (j, m) if (g[i][j] >= '0' && g[i][j] <= '9') {
            f[i][j] = e;
            dp[1 << e][e] = mp(g[i][j] - '0', 1);
            h[e++] = mp(i, j);
        }
        tol = 1 << e, flag = 0;
        rep (i, tol) {
            if (flag) break;
            rep (j, e) {
                if (!((i >> j) & 1)) continue;
                if (dp[i][j].X == -1) continue;
                if (dp[i][j] == ans) {
                    flag = 1;
                    //cout << "i= " << i << " " << j << '\n';
                    break;
                }
                x = h[j].X, y = h[j].Y;
                rep (k, 4) {
                    u = x + dx[k], v = y + dy[k];
                    if (u < 0 || u >= n || v < 0 || v >= m) continue;
                    if (g[u][v] == '#') continue;

                    w = u + dx[k], z = v + dy[k];
                    if (w < 0 || w >= n || z < 0 || z >= m) continue;
                    if (g[w][z] == '#') continue;

                    id = f[w][z];
                    if ((i >> id) & 1) continue;

                    dp[i | (1 << id)][id] = dp[i][j];
                    if (g[u][v] == '+') add(dp[i | (1 << id)][id], mp(g[w][z] - '0', 1));
                    if (g[u][v] == '-') sub(dp[i | (1 << id)][id], mp(g[w][z] - '0', 1));
                    if (g[u][v] == '*') mul(dp[i | (1 << id)][id], mp(g[w][z] - '0', 1));
                    if (g[u][v] == '/') {
                        if (g[w][z] == '0') continue;
                        div(dp[i | (1 << id)][id], mp(g[w][z] - '0', 1));
                    }
                }
            }
        }
        puts(flag ? "Possible" : "Impossible");
    }
    return 0;
}


