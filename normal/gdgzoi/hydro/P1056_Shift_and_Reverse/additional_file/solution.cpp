#include <bits/stdc++.h>
using namespace std;

// INF 表示 int 的最大值 2147483647
const int INF = numeric_limits<int>::max();
 
int gao(const vector<int>& a, int n, int d) {
    if (n == 1) return 0;
    vector<int> c(2 * n);
    for (int i = 0; i < n; i++) {
        c[i] = a[i];
        c[i + n] = a[i];
    }
 
    int p = -1;
    vector<int> b(2 * n, 1);
    for (int i = 1; i < 2 * n; i++) {
        if (c[i] >= c[i - 1]) b[i] = b[i - 1] + 1;
        if (b[i] == n) p = i;
    }
    if (p == n - 1) return 0;
    if (p == -1) return INF;
    // 前面 l 个数递增, 后 r 个数递增
    // 比如 [3, 4, 5, 1, 2], 前 3 个数递增, 后 2 个数递增
    // 要么把后 r 个数位移, 需要 r 步
    // 要么先翻转, 再把后 l 个数位移, 再翻转, 需要 l + 2 步
    int l = p - n + 1, r = n - l;
    return min(r + d, 2 + l - d);
}
 
int main() {
    // 下面 2 是为了让 cin, cout 更快, 不理解可以先不写
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T, n;
    cin >> T;
    while (T--) {
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        int ans = gao(a, n, 0);

        // 先翻转
        reverse(a.begin(), a.end());
        int res = gao(a, n, 1);
        
        ans = min(ans, res);
        if (ans == INF) ans = -1;
        cout << ans<< '\n';
    }
    return 0;
}