#include <bits/stdc++.h>
using namespace std;

const int N = 305;

int n, m;
vector<vector<int>> a, dp;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

// cal(x, y) 用来计算 dp[x][y], 这是一个递归函数
int cal(int x, int y) {
    // 第 1 步: 终止条件, dp[x][y] 已经计算过
    if (dp[x][y] != -1) return dp[x][y];
    
    // 第 2 步: 转移方程
    dp[x][y] = 1;
    for (int k = 0; k < 4; k++) {
        int u = x + dx[k], v = y + dy[k];
        if (u < 0 || u >= n || v < 0 || v >= m) continue;
        if (a[u][v] < a[x][y]) dp[x][y] = max(dp[x][y], cal(u, v) + 1);  // 这里是 cal(u, v)
    }
    return dp[x][y];
};
    
int main() {
    // 下面 2 句话是为了让 cin 更快，不理解可以先不写
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> m;
    a = vector<vector<int>>(n, vector<int>(m));
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> a[i][j];
    
    // dp[i][j] 表示从 (i, j) 出发的最长路
    dp = vector<vector<int>>(n, vector<int>(m, -1));
    int ans = 1;
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
        cal(i, j);
        ans = max(ans, dp[i][j]);
    }

    cout << ans << '\n';
    return 0;
}