#include <bits/stdc++.h>
using namespace std;
 
int main() {
    // 下面 2 句话是为了让 cin 更快，不理解可以先不写
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string t, s;
    cin >> t;
    int n = t.size(), m, sz;
    cin >> m;
    vector<int> dp(n + 1, -1);
    dp[0] = 0;
    while (m--) {
        cin >> sz;
        vector<string> s(sz);
        for (int i = 0; i < sz; i++) cin >> s[i];
        for (int j = n; j >= 0; j--) {
            for (int i = 0; i < sz; i++) {
                int k = s[i].size();
                if (j - k >= 0 && t.substr(j - k, k) == s[i] && dp[j - k] != -1) {
                    int tmp = dp[j - k] + 1;
                    if (dp[j] == -1 || dp[j] > tmp) dp[j] = tmp;
                }
            }
        }
    }
    cout << dp[n] << '\n';
    return 0;
}