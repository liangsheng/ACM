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

const int N = 100005, M = N * 2;

int n, m, e;
int head[N], nxt[M], pnt[M], wv[M];
int val[N];

void init() {
    e = 0;
    memset(head, -1, sizeof(head));
}

void add_edge(int u, int v, int f) {
    pnt[e] = v, wv[e] = f, nxt[e] = head[u], head[u] = e++;
}

int T;
LL d0[N], d1[N], ans;
int p0[N], p1[N];

void dfs0(int p, int fa) {
    int u, v;
    LL tmp;
    d0[p] = 0, p0[p] = p;
    d1[p] = 0, p1[p] = p;
    repe (i, p) {
        v = pnt[i];
        if (v == fa) continue;
        dfs0(v, p);
        if (val[v] < val[p]) continue;
        tmp = d0[v] + wv[i];
        if (tmp > d0[p]) {
            d1[p] = d0[p], p1[p] = p0[p];
            d0[p] = tmp, p0[p] = v;
        } else if (tmp > d1[p]) {
            d1[p] = tmp, p1[p] = v;
        }
    }
    ans = max(ans, (LL) val[p] * d0[p]);
}

void dfs1(int p, int fa, int vv) {
    LL tmp, x;
    int y;
    if (p != 1) {
        if (val[p] <= val[fa]) {
            if (d0[fa] == p) x = d1[fa] + vv, y = fa;
            else x = d0[fa] + vv, y = fa;
            if (x > d0[p]) {
                d1[p] = d0[p], p1[p] = d0[p];
                d0[p] = x, p0[p] = y;
            } else if (x > d1[p]) {
                d1[p] = x, p1[p] = y;
            }
        }
    }
    tmp = (d0[p] + d1[p]) * val[p];
    ans = max(ans, tmp);
    repe (i, p) {
        y = pnt[i];
        if (y == fa) continue;
        dfs1(y, p, wv[i]);
    }
}

int main() {
    int u, v, x, y, z;
    scanf("%d", &T);
    while (T--) {
        init();
        scanf("%d", &n);
        FOR (i, 1, n) scanf("%d", &val[i]);
        rep (i, n - 1) {
            scanf("%d %d %d", &x, &y, &z);
            add_edge(x, y, z);
            add_edge(y, x, z);
        }
        memset(d0, -1, sizeof(d0));
        memset(d1, -1, sizeof(d1));
        ans = -1;
        dfs0(1, -1);
        FOR (i, 1, n) {
            printf("p= %d %lld %d %lld %d\n", i, d0[i], p0[i], d1[i], p1[i]);
        } system("pause");
        dfs1(1, -1, 0);
        cout << ans << '\n';
    }
    return 0;
}














