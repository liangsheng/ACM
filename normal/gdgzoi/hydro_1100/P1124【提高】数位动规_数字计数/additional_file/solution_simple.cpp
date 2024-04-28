#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

vector<LL> dp(13, 0);
vector<LL> mi(13, 1);

// 计算 1 到 x - 1 之间每个数字出现的次数
// 注意不是从 0 开始, 是从 1 到 x - 1
vector<LL> cal(LL x) {
    // cout << "x= " << x << '\n';
    LL t = x;
    vector<int> a;
    while (x > 0) a.push_back(x % 10), x /= 10;
    int n = a.size();

    vector<LL> ans(10, 0);
    for (int i = n; i >= 1; i--) {
        int y = a[i - 1];

        // 这一位比 y 小, 先不考虑前导 0
        for (int j = 0; j < 10; j++) ans[j] += dp[i - 1] * y;
        for (int j = 0; j < y; j++) ans[j] += mi[i - 1];

        // 这一位等于 y
        t -= y * mi[i - 1], ans[y] += t;

        // 减去这一位的前导 0
        ans[0] -= mi[i - 1];
    }
    // for (int j = 0; j < 10; j++) cout << ans[j] << " \n"[j == 9];
    return ans;
}

int main() {
    // 下面 2 句话是为了让 cin 更快，不理解可以先不写
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    LL L, R;
    cin >> L >> R;

    // dp[i] 表示 i 位数中每个数字出现的次数, 可以有前导 0
    // 这样的话, 每个数字出现的次数都一样, 都是 dp[i]
    for (int i = 1; i <= 12; i++) {
        dp[i] = dp[i - 1] * 10 + mi[i - 1];
        mi[i] = mi[i - 1] * 10;
    }

    vector<LL> a = cal(R + 1), b = cal(L);
    for (int i = 0; i < 10; i++) cout << a[i] - b[i] << " \n"[i == 9];
    return 0;
}
