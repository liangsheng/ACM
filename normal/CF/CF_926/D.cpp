#include <bits/stdc++.h>
#define repe(i, u) for (int i = head[u]; i != -1; i = nxt[i])
using namespace std;
typedef long long LL;

const int N = 300005, M = N * 2, MOD = 998244353, INV = 499122177;

/*-------------------------- 邻接表存储 begin -------------*/
int T, n, e;
int head[N], pnt[M], nxt[M], wv[M];

void init(int n) {
    e = 0;
    fill(head, head + n + 1, -1);
}

void add_edge(int u, int v) {
    pnt[e] = v, nxt[e] = head[u], head[u] = e++;
}
/*-------------------------- 邻接表存储 end ---------------*/

LL dp[N][2];

void dfs(int u, int fa) {
    LL sum0 = 0, d = 1, c = 0;
    repe (i, u) {
        int v = pnt[i];
        if (v == fa) continue;
        dfs(v, u);
        sum0 = (sum0 + dp[v][0]) % MOD;
        d = d * (dp[v][1] + 1) % MOD;
        c = (c + dp[v][1]) % MOD;
    }
    // 不能向上扩展
    // 1、不选 u 也不能向上扩展: sum0
    // 2、选中 u 后不能向上扩展: c
    dp[u][0] = (sum0 + c) % MOD;
    // 可以向上扩展
    // 1、只选 u: 1
    // 2、不选 u, 儿子节点之间互相组合: d - 1
    dp[u][1] = d;
}

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    int x, y;
    cin >> T;
    while (T--) {
        cin >> n;
        init(n);
        for (int i = 1; i < n; i++) {
            cin >> x >> y;
            add_edge(x, y);
            add_edge(y, x);
        }
        dfs(1, -1);
        LL ans = (1 + dp[1][0] + dp[1][1]) % MOD;
        cout << ans << '\n';
    }
    return 0;
}