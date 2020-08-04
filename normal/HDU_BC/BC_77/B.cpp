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

const int N = 505;

int T, n, m, q;
char g[N][N];
int t[N][N];
bool f[N][N];
queue<pii> h;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

bool judge(int i, int j, int tim) {
    if (g[i][j] == '1') return 1;
    if (t[i][j] != -1 && t[i][j] <= tim) return 1;
    return 0;
}

bool ok(int tim) {
    int u, v, x, y;
    memset(f, 0, sizeof(f));
    rep (i, 1) rep (j, m) {
        if (judge(i, j, tim)) continue;
        if (f[i][j]) continue;
        h.push(mp(i, j));
        while (!h.empty()) {
            x = h.front().X, y = h.front().Y, h.pop();
            rep (i, 4) {
                u = x + dx[i], v = y + dy[i];
                if (u < 0 || u >= n || v < 0 || v >= m) continue;
                if (judge(u, v, tim)) continue;
                if (f[u][v]) continue;
                f[u][v] = 1;
                h.push(mp(u, v));
            }
        }
    }
    rep (j, m) if (f[n - 1][j]) return 1;
    return 0;
}

int main() {
    int x, y, l, r, mid, ans;
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &m);
        rep (i, n) scanf("%s", g[i]);
        memset(t, -1, sizeof(t));
        scanf("%d", &q);
        rep (i, q) {
            scanf("%d %d", &x, &y);
            t[x][y] = i + 1;
        }
        l = 0, r = q;
        while (l != r) {
            mid = (l + r) >> 1;
            if (ok(mid)) l = mid + 1;
            else r = mid;
        }
        if (ok(l)) puts("-1");
        else printf("%d\n", l);
    }
    return 0;
}















