#include <bits/stdc++.h>
using namespace std;

const int INF = numeric_limits<int>::max() / 2;

int main() {
    // 下面 2 句话是为了让 cin 更快，不理解可以先不写
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    // dp[i] 表示长度为 i + 1 的子序列的最大数的最小值
    // dp[] 必然是单调上升的（思考下为什么）
    vector<int> dp(n, INF);
    for (int i = 0; i < n; i++) {
        *lower_bound(dp.begin(), dp.end(), a[i]) = a[i];
    }
    cout << lower_bound(dp.begin(), dp.end(), INF) - dp.begin() << '\n';
    return 0;
}