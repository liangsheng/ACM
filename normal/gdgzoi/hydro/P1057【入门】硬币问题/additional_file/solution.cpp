#include <bits/stdc++.h>
using namespace std;
 
int main() {
    // 下面 2 是为了让 cin, cout 更快, 不理解可以先不写
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n = 6, m;
    vector<int> money = {1, 5, 10, 50, 100, 500};
    vector<int> cnt(n);
    for (int i = 0; i < n; i++) cin >> cnt[i];
    cin >> m;
    int ans = 0;
    
    // 贪心地从面值大的钱开始选择
    for (int i = n - 1; i >= 0; i--) {
        int c = min(m / money[i], cnt[i]);
        ans += c;
        m -= c * money[i];
    }
    cout << ans << '\n';
    return 0;
}