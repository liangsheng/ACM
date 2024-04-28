#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

// 计算 0 到 x 之间每个数字出现的次数
vector<LL> cal(LL x) {
    if (x == 0) {
        vector<LL> cnt(10, 0);
        cnt[0] = 1;
        return cnt;
    }
    vector<int> a;
    while (x != 0) a.push_back(x % 10), x /= 10;
    int n = a.size();
    reverse(a.begin(), a.end());

    // c[i][j] 表示所有的 i + 1 位数中, 数字 j 出现的次数
    vector<vector<LL>> c(n - 1, vector<LL>(10, 0));
    for (int j = 0; j < 10; j++) c[0][j] = 1;
    LL d = 10;
    for (int i = 1; i < n - 1; i++) {
        c[i][0] = d * i / 10 * 9;
        for (int j = 1; j < 10; j++) c[i][j] = d * i / 10 * 9 + d;
        d *= 10;
    }
    // for (int i = 0; i < n - 1; i++) {
    //     for (int j = 0; j < 10; j++) cout << "i= " << i << ", j= " << j << " " << c[i][j] << '\n';
    // }

    vector<LL> cnt(10, 0);

    // 先计算位数不到 n 的情况
    for (int i = 1; i < n; i++) for (int j = 0; j < 10; j++) cnt[j] += c[i - 1][j];
    
    // 再计算完全等于 x 的情况
    for (int i = 0; i < n; i++) cnt[a[i]]++;

    // 最后计算恰好为 n 位数的情况
    // dp[i][j] 表示前 i + 1 位数小于 x 的数中, 数字 j 出现的次数
    vector<LL> dp(10, 0), h(10, 0);
    for (int j = 1; j < a[0]; j++) dp[j]++;
    d = a[0] - 1;  // 前 i + 1 位数中比 x 小的数的个数
    h[a[0]] = 1;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < 10; j++) dp[j] = dp[j] * 10 + d;  // 前面已经比 x 小, 后面随意  
        for (int j = 0; j < a[i]; j++) {
            dp[j] += 1;  // 前面和 x 相等, 后面只能取小于 a[i] 的数字
            for (int k = 0; k < 10; k++) dp[k] += h[k];
        }
        h[a[i]]++;
        d = d * 10 + a[i];
    }
    for (int j = 0; j < 10; j++) cnt[j] += dp[j];
    return cnt;
}

int main() {
    // 下面 2 句话是为了让 cin 更快，不理解可以先不写
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    LL L, R;
    cin >> L >> R;
    // cout << "L= " << L << ", R= " << R << '\n';
    vector<LL> a = cal(R), b = cal(L - 1);
    // for (int i = 0; i < 10; i++) cout << a[i] << " \n"[i == 9];
    for (int i = 0; i < 10; i++) cout << a[i] - b[i] << " \n"[i == 9];
    return 0;
}
