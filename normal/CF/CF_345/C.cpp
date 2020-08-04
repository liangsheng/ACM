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

const int N = 1000005;

int n, m, tol;
int f[N], b[N], c[N];
pii w[N], v[N];
vi g[N];
queue<pii> q;

void init() {
    tol = n * m;
    rep (i, tol) f[i] = i, g[i].clear();
    memset(c, 0, sizeof(c));
}

int find(int x) {
    return x == f[x] ? f[x] : f[x] = find(f[x]);
}

int main() {
    int x, y, id, l, r, e;
    while (~scanf("%d %d", &n, &m)) {
        init();
        rep (i, n) rep (j, m) scanf("%d", &b[i * m + j]);

        e = 0;
        rep (i, n) {
            rep (j, m) {
                id = i * m + j;
                w[e++] = mp(b[id], id);
            }
            l = i * m, r = (i + 1) * m;
            sort(w + l, w + r);
            FOR (k, l, r - 1) {
                x = find(w[k].Y);
                while (k + 1 < r && w[k + 1].X == w[k].X) f[find(w[++k].Y)] = x;
            }
        }

        e = 0;
        rep (j, m) {
            rep (i, n) {
                id = i * m + j;
                v[e++] = mp(b[id], id);
            }
            l = j * n, r = (j + 1) * n;
            sort(v + l, v + r);
            FOR (k, l, r - 1) {
                x = find(v[k].Y);
                while (k + 1 < r && v[k + 1].X == v[k].X) f[find(v[++k].Y)] = x;
            }
        }

        rep (i, n) {
            l = i * m, r = (i + 1) * m;
            FOR (k, l, r - 2) {
                if (w[k].X == w[k + 1].X) continue;
                x = find(w[k].Y), y = find(w[k + 1].Y);
                g[x].pb(y), c[y]++;
            }
        }

        rep (j, m) {
            l = j * n, r = (j + 1) * n;
            FOR (k, l, r - 2) {
                if (v[k].X == v[k + 1].X) continue;
                x = find(v[k].Y), y = find(v[k + 1].Y);
                g[x].pb(y), c[y]++;
            }
        }

        rep (i, tol) if (find(i) == i && c[i] == 0) q.push(mp(i, 1));

        while (!q.empty()) {
            x = q.front().X, y = q.front().Y;
            q.pop(), b[x] = y;
            repit (it, g[x]) {
                if (--c[*it] == 0) q.push(mp(*it, y + 1));
            }
        }
        rep (i, n) {
            rep (j, m) printf("%d ", b[f[i * m + j]]);
            puts("");
        }
    }
    return 0;
}
