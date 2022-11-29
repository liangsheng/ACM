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

const int N = 1005;

vi a;

void gao(int x) {
    a.clear();
    for (int i = 2; i * i <= x; ++i) {
        if (x % i) continue;
        a.pb(i);
    }
}

int T, n, m, cnt, sx, sy;
int g[N][N];
char s[N];
vpii b;

bool ok(int x, int y) {
    if (x < 1 || y < 1) return 0;
    //sc2(x, y);
    int u, v;
    repit (it, b) {
        u = it->X, v = it->Y;
        if ((u - 1 + x) * (v - 1 + y) != g[u][v]) return 0;
    }
    return 1;
}

bool solve() {
    if (cnt == 0) return 1;
    int d = g[sx][sy], x, y;
    gao(d);
    repit (it, a) {
        x = *it, y = d / *it;
        x -= (sx - 1), y -= (sy - 1);
        if (ok(x, y)) return 1;

        x = d / *it, y = *it;
        x -= (sx - 1), y -= (sy - 1);
        if (ok(x, y)) return 1;
    }
    return 0;
}

int main() {
    int cas = 0, x, flag;
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &m);
        cnt = 0, sx = -1, b.clear();
        rep (i, n) rep (j, m) {
            scanf("%s", s);
            if (s[0] == '?') g[i + 1][j + 1] = -1;
            else {
                x = 0;
                for (int k = 0; s[k]; k++) x = x * 10 + s[k] - '0';
                g[i + 1][j + 1] = x, cnt++;
                if (sx == -1 || x < g[sx][sy]) sx = i + 1, sy = j + 1;
                b.pb(mp(i + 1, j + 1));
            }
        }
        flag = solve();
        printf("Case #%d: ", ++cas);
        puts(flag ? "Yes" : "No");
    }
    return 0;
}
