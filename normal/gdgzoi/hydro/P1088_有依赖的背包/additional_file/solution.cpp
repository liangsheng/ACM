#include <bits/stdc++.h>
using namespace std;

const int N = 105, M = 105, INF = ~0U >> 2;

int n, V;
int v[N], w[N];
int dp[N][M];
vector<vector<int>> g;  // 二维 vector, 用来存储每个节点的儿子节点

void dfs(int u, int fa) {
    // dp[u][j] 表示以 u 为节点的子树中, 体积恰好为 j （不是不超过 j）的最大价值
    // -1 表示不存在
    for (int i = 0; i <= V; i++) dp[u][i] = -1;
    dp[u][0] = 0;
    if (v[u] <= V) dp[u][v[u]] = w[u];
    // 遍历所有儿子节点
    for (int x : g[u]) {
        dfs(x, u);
        // 类似分组背包的写法, 儿子节点的 dp[v] 就是一组物品, 这一组物品里只能选一个
        for (int i = V; i >= 0; i--) {
            for (int j = 0; j <= i - v[u]; j++) {
                // 由于状态是 "体积恰好为 j", 所以需要判断状态是否存在
                if (dp[u][i - j] >= 0 && dp[x][j] >= 0) {
                    dp[u][i] = max(dp[u][i], dp[u][i - j] + dp[x][j]);
                }
            }
        }
    }
}

int main() {
    // 下面两句是为了让 cin 更快
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int r, x;
    cin >> n >> V;
    g = vector<vector<int>>(n + 1, vector<int>());
    for (int i = 1; i <= n; i++) {
        cin >> v[i] >> w[i] >> x;
        if (x != -1) g[x].push_back(i);
        else r = i;
    }
    dfs(r, -1);

    // 由于状态是 "体积恰好为 j", 所以结果不是 dp[r][V]
    // 而是 dp[r] 里的最大值
    int ans = -INF;
    for (int i = 0; i <= V; i++) ans = max(ans, dp[r][i]);
    cout << ans << '\n';
    return 0;
}