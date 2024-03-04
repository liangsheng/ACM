#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int MOD = 1000000007;

int main() {
    // 下面 2 句话是为了让 cin 更快，不理解可以先不写
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, V;
    cin >> n >> V;
    vector<int> v(n + 1), w(n + 1);
    for (int i = 1; i <= n; i++) cin >> v[i] >> w[i];

    // dp(i, j) 表示 [i,..,n] 个物品, 体积不超过 j 的最大价值
    // 为了输出字典序最小的方案, dp(i, j) 反过来定义
    // 因此第一维是 n + 2, 从 1 到 n + 1
    vector<vector<int>> dp(n + 2, vector<int>(V + 1, 0));

    // f(i, j) 表示在 dp(i, j) 中是否取了第 i 个物品
    vector<vector<int>> f(n + 2, vector<int>(V + 1, 0));

    // c(i, j) 表示在达成 dp(i, j) 的方案数
    vector<vector<int>> c(n + 2, vector<int>(V + 1, 0));
    // 由于 dp(i, j) 反过来定义, 需要初始化 c[n + 1] 为 0
    fill(c[n + 1].begin(), c[n + 1].end(), 1);

    for (int i = n; i >= 1; i--) {
        for (int j = 0; j <= V; j++) {
            dp[i][j] = dp[i + 1][j];
            f[i][j] = 0, c[i][j] = c[i + 1][j];  // 第一种情况不取 物品i, f[i][j] = 0
            if (j - v[i] >= 0) {
                int tmp = dp[i + 1][j - v[i]] + w[i];
                if (tmp > dp[i][j]) {           // 第二种情况, 取了 物品i 后最大价值变大
                    dp[i][j] = tmp;
                    f[i][j] = 1, c[i][j] = c[i + 1][j - v[i]];
                } else if (tmp == dp[i][j]) {   // 第三种情况, 取了物品i 后最大价值不变
                    f[i][j] = 1;                // 只要 tmp == dp[i][j], 就优先取物品i, 保证字典序最小
                    c[i][j] = ((LL) c[i][j] + c[i + 1][j - v[i]]) % MOD;
                }
            }
        }
    }
    // 输出最大价值
    cout << dp[1][V] <<'\n';
    
    // 输出最大价值的方案数
    cout << c[1][V] << '\n';
    
    // 输出字典序最小的方案
    vector<int> ans;
    for (int i = 1, j = V; i <= n; i++) {
        if (f[i][j]) ans.push_back(i), j -= v[i];  // 取了 物品i
    }
    for (int i = 0; i < (int) ans.size() ; i++) cout << ans[i] << " \n"[i == (int) ans.size() - 1];
    return 0;
}