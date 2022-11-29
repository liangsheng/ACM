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

const int N = 2005;

int n, k, e;
int head[N], pnt[N * 2], nxt[N * 2];
bool f[N], g[N];

void init() {
    e = 0;
    memset(head, -1, sizeof(head));
}

void add_edge(int u, int v) {
    pnt[e] = v, nxt[e] = head[u], head[u] = e++;
}

void dfs(int u, int fa, int d, int t) {
    //sc4(u, fa, d, t);
    f[u] = 1;
    if (d == t) return ;
    repe (i, u) {
        if (pnt[i] == fa) continue;
        dfs(pnt[i], u, d + 1, t);
    }
}

int main() {
    int u, v, ans, tmp;
    while (~scanf("%d %d", &n, &k)) {
        init();
        rep (i, n - 1) {
            scanf("%d %d", &u, &v);
            add_edge(u, v);
            add_edge(v, u);
        }
        ans = n;
        if (k % 2) {
            FOR (i, 1, n) repe (j, i) {
                u = i, v = pnt[j];
                memset(f, 0, sizeof(f));
                dfs(u, v, 0, (k - 1) / 2);
                memcpy(g, f, sizeof(f));
                dfs(v, u, 0, (k - 1) / 2);
                tmp = 0;
                FOR (l, 1, n) tmp += f[l] | g[l];
                ans = min(ans, n - tmp);
                //sc3(i, j, tmp);
            }
        } else {
            FOR (i, 1, n) {
                memset(f, 0, sizeof(f));
                dfs(i, -1, 0, k / 2);
                tmp = 0;
                FOR (l, 1, n) tmp += f[l];
                ans = min(ans, n - tmp);
                //sc2(i, tmp);
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}






