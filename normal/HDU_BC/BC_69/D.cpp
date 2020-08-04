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

int const N = 20005;
int const M = 20;

struct E {
    int v, nxt, id;
    void read(int v, int nxt, int id) {
        this->v = v;
        this->nxt = nxt;
        this->id = id;
    }
} e[N * 2];

int son[N], L[N], R[N], Node;
int dp[N][M], dep[N];
int rcd[N];

void dfs(int x, int id) {
    L[x] = ++Node;
    rcd[id] = x;
    dep[x] = dep[dp[x][0]] + 1;

    for (int i = 1; i < M; i++)
        dp[x][i] = dp[dp[x][i - 1]][i - 1];

    int v;
    for (int t = son[x]; t; t = e[t].nxt) {
        v = e[t].v;
        if (v == dp[x][0])
            continue;
        dp[v][0] = x;
        dfs(v, e[t].id);
    }

    R[x] = ++Node;
}

int LCA(int a, int b) {
    if (dep[a] < dep[b])
        swap(a, b);
    for (int i = M - 1; i >= 0; i--)
        if (dep[dp[a][i]] >= dep[b])
            a = dp[a][i];
    if (a == b)
        return a;
    for (int i = M - 1; i >= 0; i--)
        if (dp[a][i] != dp[b][i]) {
            a = dp[a][i], b = dp[b][i];
        }
    return dp[a][0];
}

int T, n, m;
int g[N][4];

int main() {
    int a, b, cnt, lca, q;
    scanf("%d", &T);
    while (T--) {
        dep[0] = -1;
        scanf("%d", &n);

        cnt = Node = 0;
        memset(son, 0, (n + 1) * sizeof(int));

        for (int i = 1; i < n; i++) {
            scanf("%d%d", &a, &b);
            e[++cnt].read(a, son[b], i);
            son[b] = cnt;
            e[++cnt].read(b, son[a], i);
            son[a] = cnt;
        }
        dfs(1, 0);
        FOR (i, 1, n) rep (j, 4) scanf("%d", &g[i][j]);
        scanf("%d", &q);
        while (q--) {
            scanf("%d %d", &a, &b);
            rep (i, 4) scanf("%d", &h[i]);
        }
    }
    return 0;
}

















