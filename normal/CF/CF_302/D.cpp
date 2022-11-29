#include <bits/stdc++.h>

#define file_r(x) freopen(x, stdin, "r")
#define file_w(x) freopen(x, stdout, "w")
#define rep(i, n) for (int i = 0; i < n; i++)
#define FOR(i, n, m) for (int i = n; i <= m; i++)
#define repe(i, u) for (int i = head[u]; ~i; i = nxt[i])
#define FORD(i, n, m) for (int i = n; i >= m; i--)
#define repit(i, c) for (__typeof__((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define pause cout << " press ant key to continue...", cin >> chh

#define pb push_back
#define mp make_pair
#define ins insert
#define X first
#define Y second
#define be begin
#define nb rbegin
#define er erase
#define SZ(c) c.size()

#define sc(n) cout << #n << "= " << n, system("pause")
#define sc2(n, m) cout << #n << "= " << n << " " << #m << "= " << m, system("pause")
#define sc3(n, m, k) cout << #n << "= " << n << " " << #m << "= " << m << " " << #k << "= " << k, system("pause")
#define sc4(n, m, k, b) cout << #n << "= " << n << " " << #m << "= " << m << " " << #k << "= " << k << " " << #b << "= " << b, system("pause")

using namespace std;
int chh;

typedef long long LL;

const int N = 200005, M = N * 2, MOD = (1e9) + 7;

int n, m, e;
int head[N], pnt[M], nxt[M];

void init() {
    e = 0;
    memset(head, -1, sizeof(head));
}

void add_edge(int u, int v) {
    //sc2(u, v);
    pnt[e] = v, nxt[e] = head[u], head[u] = e++;
}

LL numberReverse_int64(LL a,LL b){
    if (b == 0) return 0;
    LL ret = 1, c = 0, d, p, m = b;
    if (a > b) a = a % b;
    while (a > 1) {
        p = b/a;
        d = a;
        a = b - p * a;
        b = d;

        d = ret;
        ret = c - ret * p;
        c = d;
    }
    if (a == 0) return 0;
    return ((ret % m) + m) % m;
}

LL power(LL x, LL y) {
    LL ans = 1;
    while (y) {
        if (y & 1) ans = ans * x % MOD;
        x = x * x % MOD;
        y >>= 1LL;
    }
    return ans;
}

LL gao(LL x) {
    return power(x, MOD - 2);
}

int dp[N], ans[N];

void dfs1(int p, int fa) {
    int v;
    dp[p] = 1;
    repe (i, p) {
        v = pnt[i];
        if (v == fa) continue;
        dfs1(v, p);
        dp[p] = dp[p] * ((LL) dp[v] + 1) % MOD;
    }
}

void dfs2(int p, int fa, int tmp) {
    int v, t;
    ans[p] = ((LL) tmp + 1) * dp[p] % MOD;
    repe (i, p) {
        v = pnt[i];
        if (v == fa) continue;
        t = gao((LL) dp[v] + 1);
        dfs2(v, p, (LL) ans[p] * t % MOD);
    }
}

int main() {
    int x, tmp;
    while (~scanf("%d", &n)) {
        init();
        rep (i, n - 1) {
            scanf("%d", &x);
            add_edge(x, i + 2);
            add_edge(i + 2, x);
        }
        dfs1(1, -1);
        ans[1] = dp[1];
        //FOR (i, 1, n) printf("%d %d\n", i, dp[i]);
        repe (i, 1) {
            x = pnt[i];
            tmp = (LL) ans[1] * gao((LL) dp[x] + 1) % MOD;
            dfs2(x, 1, tmp);
        }
        FOR (i, 1, n - 1) printf("%d ", ans[i]);
        printf("%d\n", ans[n]);
    }
    return 0;
}
