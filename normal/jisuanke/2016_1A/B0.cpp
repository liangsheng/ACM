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

const int N = 505, M = N * 2, DEP = 20;

struct NODE {
    int v, w, next;
} edge[M];

int T, n, m, e;
int head[N], dis[N], dp[N][DEP], dep[N];

void init() {
    e = 0;
    memset(head, -1, sizeof(head));
}

void add_edge(int u, int v, int w) {
    edge[e].v = v, edge[e].w = w;
    edge[e].next = head[u], head[u] = e++;
}

void dfs(int u, int fa, int d, int s) {
    int i, v, w;
    dis[u] = d, dep[u] = s;
    dp[u][0] = fa;
    for (i = 1; i < DEP; i++) dp[u][i] = dp[dp[u][i - 1]][i - 1];
    for (i = head[u]; i != -1; i = edge[i].next) {
        v = edge[i].v;
        if (v == fa) continue;
        w = d + edge[i].w;
        dfs(v, u, w, s + 1);
    }
}

int LCA(int a, int b) {
    if (dep[a] < dep[b])swap(a, b);
    for (int i = DEP - 1; i >= 0; i--)
        if (dep[dp[a][i]] >= dep[b]) a = dp[a][i];
    if (a == b) return a;
    for (int i = DEP - 1; i >= 0; i--)
        if (dp[a][i] != dp[b][i]) {
            a = dp[a][i], b = dp[b][i];
        }
    return dp[a][0];
}

int a[N];

int gcd(int x, int y) {
    return x % y ? gcd(y, x % y) : y;
}

int main() {
    int u, v, ans;
    while (~scanf("%d", &n)) {
        FOR (i, 1, n) scanf("%d", &a[i]);
        init();
        rep (i, n - 1) {
            scanf("%d %d", &u, &v);
            add_edge(u, v, 1);
            add_edge(v, u, 1);
        }
        dfs(1, 1, 0, 1);
        ans = 0;
        FOR (i, 1, n) FOR (j, i + 1, n) {
            u = gcd(a[i], a[j]);
            if (u != 1) continue;
            v = LCA(i, j);
            ans += dep[i] + dep[j] - 2 * dep[v];
        }
        printf("%d\n", ans);
    }
    return 0;
}
