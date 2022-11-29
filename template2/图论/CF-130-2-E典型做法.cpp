#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>

#define all(c) (c).begin(), c.end()
#define sz(c) (c).size()
#define mp make_pair
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define X first
#define Y second
#define vi vector < int >
#define pii pair < int, int >
#define LL long long
#define mem(v, i) memset(v, i, sizeof(v))
#define rep(i, a) for (int i = 0; i <= (a); i++)
#define repu(i, a, b) for (int i = (a); i <= (b); i++)
#define repd(i, a, b) for (int i = (a); i >= (b); i--)
#define repit(it, v) for (typeof(v.begin()) it = v.begin(); it != v.end(); it++)
#define repitd(it, v) for (typeof(v.rbegin()) it = v.rbegin(); it != v.rend(); it++)
#define file_r(x) freopen(x,  "r",  stdin)
#define file_w(x) freopen(x,  "w",  stdout)
#define lowbit(x) ((x) & (-(x)))
#define pause cout << " press any key to continue...",  cin >> chh

using namespace std;
int chh;

inline void in(int &t) {
    int n = 0, s = 1;
    char ch = getchar();
    while (ch != '-' && (ch < '0' || ch > '9')) ch = getchar();
    if (ch == '-') s = -1, ch = getchar();
    while (ch >= '0' && ch <= '9') n = n * 10 + ch - '0', ch = getchar();
    t = n * s;
}

const int N = 100005, M = 20;

int n, m, e, ct;
int f[N], head[N], pnt[N], nxt[N];
int dp[N][M], dep[N], L[N], R[N];
vi d[N];

void init() {
    e = ct = 0;
    mem(head, -1);
}

void add_edge(int u, int v) {
    pnt[e] = v, nxt[e] = head[u], head[u] = e++;
}

void dfs(int x) {
    int v;
    dep[x] = dep[dp[x][0]] + 1;
    d[dep[x]].pb(ct);
    L[x] = ct++;
    repu (i, 1, M - 1) dp[x][i] = dp[dp[x][i - 1]][i - 1];
    for (int i = head[x]; i != -1; i = nxt[i]) {
        v = pnt[i];
        dp[v][0] = x;
        dfs(v);
    }
    R[x] = ct;
}

int lca(int a, int k) {
    if (dep[a] < k) return -1;
    repd (i, M - 1, 0) {
        if ((1 << i) > k) continue;
        k -= 1 << i, a = dp[a][i];
        if (k == 0) break;
    }
    return a;
}

int main() {
    int u, k, v, ans;
    while (~scanf("%d", &n)) {
        init();
        repu (i, 1, n) {
            in(f[i]);
            add_edge(f[i], i);
        }
        rep (i, n - 1) d[i].clear();
        dep[0] = -1;
        repu (i, 1, n) {
            if (f[i] != 0) continue;
            dfs(i);
        }
        in(m);
        rep (i, m - 1) {
            in(u), in(k);
            v = lca(u, k);
            if (v == -1) printf("%d%c", 0, i == m - 1 ? '\n' : ' ');
            else {
                ans = lb(all(d[dep[u]]), R[v]) - lb(all(d[dep[u]]), L[v]) - 1;
                printf("%d%c", ans, i == m - 1 ? '\n' : ' ');
            }
        }
    }
    return 0;
}
