#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

// 统计 0 到 x 合法的数的个数
LL cal(LL x) {
    vector<int> a;
    while (x != 0) a.push_back(x % 10), x /= 10;
    int n = a.size();

    // dp[i][0][j]: 前 i 位数, 第 i 位数是 j, 和 x 相等的合法数
    // dp[i][1][j]: 前 i 位数, 第 i 位数是 j, 比 x 小的合法数
    vector<vector<vector<LL>>> dp(n + 1, vector<vector<LL>>(2, vector<LL>(10, 0)));
    dp[0][0][0] = 1;
    for (int i = 0; i < n; i++) for (int ls = 0; ls < 2; ls++) for (int j = 0; j < 10; j++) {
        if (dp[i][ls][j] == 0) continue;

        // ls = 1, 表示前面已经小了, 那么这一位 0 到 9 都可以
        // ls = 0, 表示前面相等, 那么这一位只能 0 到 a[n - i]
        int lim = (ls ? 9 : a[n - 1 - i]);
        for (int d = 0; d <= lim; d++) {
            if (d == 4 || (j == 6 && d == 2)) continue;  // 不要 62
            dp[i + 1][ls | (d < lim)][d] += dp[i][ls][j];
        }
    }
    // 返回前 n 位比 x 小的合法数
    LL cnt = 0;
    for (int j = 0; j < 10; j++) cnt += dp[n][1][j];
    return cnt;
}

int main() {
    // 下面 2 句话是为了让 cin 更快，不理解可以先不写
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    LL L, R;
    cin >> L >> R;
    LL a = cal(R + 1), b = cal(L);
    cout << a - b << '\n';
    return 0;
}
