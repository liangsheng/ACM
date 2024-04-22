#include <bits/stdc++.h>
using namespace std;

const int INF = numeric_limits<int>::max() / 2;

// 解决环形问题的一般套路, 将数组复制一遍拼接在原数组后面
int solve(int n, vector<int>& a, int de, function<int(int, int)> fun) {
    vector<int> f(2 * n + 1, 0);
    for (int i = 1; i <= 2 * n; i++) f[i] = f[i - 1] + a[(i - 1) % n];
    vector<vector<int>> dp(2 * n + 1, vector<int>(2 * n + 1, de));
    for (int i = 1; i <= 2 * n; i++) dp[i][i] = 0;
    for (int d = 2; d <= 2 * n; d++) {
        for (int i = 1; i + d - 1 <= 2 * n; i++) {
            int j = i + d - 1;
            for (int k = i; k < j; k++) {
                dp[i][j] = fun(dp[i][j], dp[i][k] + dp[k + 1][j] + f[j] - f[i - 1]);
            }
        }
    }
    int ans = de;
    for (int i = 1; i <= n; i++) ans = fun(ans, dp[i][i + n - 1]);
    return ans;
}

int main() {
    // 下面 2 句话是为了让 cin 更快，不理解可以先不写
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int mini = solve(n, a, INF, [&](int x, int y) {  return min(x, y); });
    int maxi = solve(n, a, 0, [&](int x, int y) {  return max(x, y); });
    cout << mini << '\n' << maxi << '\n';
    return 0;
}
