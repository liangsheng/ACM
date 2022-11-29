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

const int N = 10005, M = 500;

int n, e, m;
int head[N], pu[N * 2], pnt[N * 2], nxt[N * 2];

LL ans;
int a[N], tol[N], c[N][M], h[M];
bool f[M];
vi g[M + 5], p;

void de() {
    int x;
    p.clear();
    FOR (i, 2, M) {
        if (f[i]) continue;
        p.pb(i);
        for (int j = i * i; j <= M; j += i) f[j] = 1;

    }
    FOR (i, 1, M) {
        g[i].clear();
        repit (it, p) {
            if (*it > i) break;
            if (i % *it == 0) g[i].pb(*it);
        }
    }
    //repit (it, g[97]) cout << *it << ' ';
}

void init() {
    e = 0;
    memset(head, -1, sizeof(head));
}

void add_edge(int u, int v) {
    pu[e] = u, pnt[e] = v;
    nxt[e] = head[u], head[u] = e++;
}

void dfs(int p, int fa) {
    //sc2(p, fa);
    int v, t = 1, st, sz, f;
    LL tmp;
    FOR (i, 1, m) c[p][i] = 0;
    c[p][a[p]]++;
    repe (i, p) {
        v = pnt[i];
        if (v == fa) continue;
        dfs(v, p);
        FOR (j, 1, m) {
            c[p][j] += c[v][j];
            t += c[v][j];
        }
    }
    ans += (LL) t * (n - t);
    FOR (i, 1, m) h[i] = 0;
    FOR (i, 1, m) for (int j = i; j <= m; j += i) h[i] += tol[j] - c[p][j];

    //FOR (i, 1, m) cout << c[p][i] << ' '; puts("");
    //FOR (i, 1, m) cout << h[i] << ' '; puts(""); system("pause");
    //sc(ans);

    FOR (i, 1, m) {
        if (c[p][i] == 0) continue;
        //sc2(i, c[p][i]);
        sz = SZ(g[i]), st = (1 << sz) - 1;
        tmp = 0;
        FOR (j, 1, st) {
            f = -1, v = 1;
            rep (k, sz) {
                if (!((j >> k) & 1)) continue;
                f *= -1;
                v *= g[i][k];
            }
            tmp += (LL) f * h[v];
        }
        ans -= (LL) c[p][i] * tmp;
    }
    //sc(ans);
}

int main() {
    int u, v;
    de();
    while (~scanf("%d", &n)) {
        memset(tol, 0, sizeof(tol));
        m = 0;
        FOR (i, 1, n) {
            scanf("%d", &a[i]);
            tol[a[i]]++;
            m = max(m, a[i]);
        }
        init();
        rep (i, n - 1) {
            scanf("%d %d", &u, &v);
            add_edge(u, v);
            add_edge(v, u);
        }
        ans = 0;
        repe (i, 1) {
            v = pnt[i];
            dfs(v, 1);
        }
        cout << ans << '\n';
    }
    return 0;
}
