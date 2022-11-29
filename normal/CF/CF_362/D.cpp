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

const int N = 205, CH = 26;
const LL INF = 1e18;

typedef LL mat[N][N];

int n;
LL m;
int a[N];
char s[N];

int E;
mat ret, tmp, g;

void mul(mat a, mat b) {
    rep (i, E) rep (j, E) tmp[i][j] = -INF;
    rep (i, E) rep (j, E) rep (k, E) {
        tmp[i][j] = max(tmp[i][j], a[i][k] + b[k][j]);
    }
    rep (i, E) rep (j, E) a[i][j] = tmp[i][j];
}

void power(mat a, LL y)  {
    rep (i, E) rep (j, E) {
        ret[i][j] = -INF;
        g[i][j] = a[i][j];
    }
    rep (i, E) ret[i][i] = 0;
    while (y) {
        if (y & 1) mul(ret, g);
        mul(g, g);
        y >>= 1LL;
    }
}

struct Aho_Corasick {
    int e;
    int chd[N][CH];
    int wv[N], fail[N], q[N];

    void init() {
        e = 1;
        memset(chd[0], -1, sizeof(chd[0]));
        wv[0] = 0;
    }

    void add(char s[], int val) {
        int i, id, p = 0;
        for (i = 0; s[i]; i++) {
            id = s[i] - 'a';
            if (chd[p][id] == -1) {
                memset(chd[e], -1, sizeof(chd[e]));
                wv[e] = 0;
                chd[p][id] = e++;
            }
            p = chd[p][id];
        }
        //   caution!!!
        wv[p] += val;
    }

    void build() {
        int i, p, v, l, r;
        fail[0] = l = r = 0;
        for (i = 0; i < CH; i++) {
            v = chd[0][i];
            if (v != -1) {
                fail[v] = 0;
                q[r++] = v;
            } else chd[0][i] = 0;
        }
        while (l != r) {
            p = q[l++];
            for (i = 0; i < CH; i++) {
                v = chd[p][i];
                if (v != -1) {
                    fail[v] = chd[fail[p]][i];
                    q[r++] = v;
                    wv[v] += wv[fail[v]];
                } else chd[p][i] = chd[fail[p]][i];
            }
        }
    }

    void solve() {
        int v;
        LL ans;
        mat a;
        E = e;
        rep (i, E) rep (j, E) a[i][j] = -INF;
        rep (i, e) rep (j, CH) {
            v = chd[i][j];
            a[i][v] = wv[v];
        }
        power(a, m);
        ans = -INF;
        rep (j, E) ans = max(ans, ret[0][j]);
        printf("%I64d\n", ans);
    }

} AC;

int main() {
    while (cin >> n >> m) {
        rep (i, n) scanf("%d", &a[i]);
        AC.init();
        rep (i, n) {
            scanf("%s", s);
            AC.add(s, a[i]);
        }
        AC.build();
        AC.solve();
    }
    return 0;
}
