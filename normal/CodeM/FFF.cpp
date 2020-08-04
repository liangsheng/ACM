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
#define repe(i, u) for (int i = head[u]; i != -1; i = edge[i].next)
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
#define SZ(c) int((c).size())
#define ALL(c) (c).begin(), (c).end()
#define sqr(r) ((r) * (r))
#define dis(x1, y1, x2, y2) (((x1) - (x2)) * ((x1) - (x2)) + ((y1) - (y2)) * ((y1) - (y2)))
#define FASTIO ios::sync_with_stdio(false);cin.tie(0)

#define sc(x) cout << #x" = " << x << endl
#define sc2(x, y) cout << #x" = " << x << " " << #y" = " << y << endl
#define sc3(x, y, z) cout << #x" = " << x << " " << #y" = " << y << " " << #z" = " << z << endl
#define sc4(x, y, z, w) cout << #x" = " << x << " " << #y" = " << y << " " << #z" = " << z << " " << #w" = " << w << endl

#define in(n) scanf("%d", &n)
#define in2(n, m) scanf("%d %d", &n, &m)
#define in3(x, y, z) scanf("%d %d %d", &x, &y, &z)

using namespace std;
int chh;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef set<int> si;
typedef map<int, int> mii;
typedef pair<int, int> pii;
typedef pair<int, pii> pi3;
typedef vector< pair<int, int> > vpii;
typedef long long LL;

const int N = 1005, M = 100005;

int vis[N], match[N], h[N];

struct Node {
    int u, v, cost;

    Node() {}
    Node(int A, int B, int C): u(A), v(B), cost(C) {}

    bool operator <(const Node& arg) const {
        return cost < arg.cost;
    }
} edge[M];


int gao(int idx) {
    int u = edge[idx].u, v = edge[idx].v;
    if (vis[v]) return 0;
    vis[v] = 1;
    if (match[v] == -1 || gao(match[v])) {
        match[v] = idx;
        return 1;
    }
    return 0;
}

const int INF = 2139062143;

int n, m;
int g[N][N];

int main() {
    int u, v, w, e, cnt;
    int ans[N];
    while (~in2(n, m)) {
        memset(g, 127, sizeof(g));
        rep (i, m) {
            in3(u, v, w);
            g[u][v] = min(g[u][v], w);
        }
        e = 0;
        FOR (i, 1, n) FOR (j, 1, n) {
            if (g[i][j] == INF) continue;
            edge[e++] = Node(i, j, g[i][j]);
        }
        sort(edge, edge + e);

        cnt = 0;
        memset(ans, -1, sizeof(ans));
        memset(match, -1, sizeof(match));
        memset(h, -1, sizeof(h));
        rep (i, e) {
            memset(vis, 0, sizeof(vis));
            if (gao(i)) cnt++;
            if (ans[cnt] == -1) ans[cnt] = edge[i].cost;
        }
        FOR (i, 1, n - 1) printf("%d ", ans[i]);
        printf("%d\n", ans[n]);
    }
	return 0;
}
