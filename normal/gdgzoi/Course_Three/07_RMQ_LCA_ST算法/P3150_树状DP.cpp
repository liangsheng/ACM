#include <bits/stdc++.h>
#define repe(i, u) for (int i = head[u]; i != -1; i = nxt[i])
using namespace std;

const int N = 100005, M = N * 2;

int e;
int head[N], pnt[M], nxt[M];

void init(int n) {
    e = 0;
    fill(head, head + n + 1, -1);
}

void add_edge(int u, int v) {
    pnt[e] = v, nxt[e] = head[u], head[u] = e++;
}

int dp[N][2];

void dfs(int u, int fa) {
    dp[u][0] = 0, dp[u][1] = 0;
    repe (i, u) if (pnt[i] != fa) {
        int v = pnt[i];
        dfs(v, u);
        dp[u][0] += dp[v][1];
    }
    bool ok = 0;
    repe (i, u) if (pnt[i] != fa) {
        int v = pnt[i];
        ok = 1;
        dp[u][1] = max(dp[u][1], dp[u][0] - dp[v][1] + dp[v][0]);
    }
    dp[u][1] += ok;
    // cout << "u= " << u << " " << dp[u][0] << " " << dp[u][1] << '\n';
}

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    int T, n, k, x;
    cin >> T;
    while (T--) {
        cin >> n >> k;
        init(n);
        for (int i = 2; i <= n; i++) {
            cin >> x;
            add_edge(i, x), add_edge(x, i);
        }
        dfs(1, -1);
        // for (int i = 1; i <= n; i++) cout << "i= " << i << " " << dp[1][0] << " " << dp[1][1] << '\n';
        if (dp[1][1] * 2 >= k) cout << (k + 1) / 2 << '\n';
        else cout << dp[1][1] + (k - dp[1][1] * 2) << '\n';
        // cout << "over" << '\n';
    }
    return 0;
}