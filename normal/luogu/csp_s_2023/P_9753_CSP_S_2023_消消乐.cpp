#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int INF = ~0U >> 2;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    string s;
    while (cin >> n) {
        cin >> s;
        vector<int> p(n + 1, 0);
        vector<LL> dp(n + 1, 0);
        for (int i = 2; i <= n; i++) {
            if (s[i - 1] == s[i - 2]) {
                p[i] = 2;
                dp[i] = dp[i - p[i]] + 1;
            } else {
                int x = i - 1;
                while (x > 0 && p[x] != 0) {
                    if (x - p[x] > 0 && s[x - p[x] - 1] == s[i - 1]) {
                        p[i] = i - (x - p[x]) + 1;
                        dp[i] = dp[i - p[i]] + 1;
                        break;
                    }
                    x = x - p[x];
                }
            }
            // cout << "i= " << i << ", p[i]= " << p[i] << ", dp[i]= " << dp[i] << '\n';
        }
        LL ans = 0;
        for (int i = 1; i <= n; i++) ans += dp[i];
        cout << ans << '\n';
    }
    // while (cin >> n) {
    //     cin >> s;
    //     vector<int> dp(n + 1, 0);
    //     vector<vector<int>> p(n + 1, vector<int>(26, 0));
        
    //     LL ans = 0;
    //     for (int i = 2; i <= n; i++) {
    //         int x;
    //         if (s[i - 1] == s[i - 2]) x = i - 1;
    //         else x = p[i - 1][s[i - 1] - 'a'];
    //         if (x > 0) {
    //             dp[i] = dp[x - 1] + 1;
    //             for (int j = 0; j < 26; j++) {
    //                 if (x - 1 > 0 && s[x - 2]  == 'a' + j) p[i][j] = x - 1;
    //                 else p[i][j] = p[x - 1][j];
    //             }
    //         }
    //         // cout << "i= " << i << ' ' << x << ' ' << dp[i] << '\n';
    //         ans += dp[i];
    //     }
    //     cout << ans << '\n';
    // }
    return 0;
}