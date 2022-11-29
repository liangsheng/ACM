#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    // clock_t startTime, endTime;
    // startTime = clock();
    int T, n = 100000, ans;
    int dp[100001];
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i] = i;
        for (int j = 1; j * 2 <= i; j++) {
            int tmp = dp[j] + 4 + (i - j) / j * 2 + (i - j) % j;
            dp[i] = min(dp[i], tmp);
        }
    }
    // endTime = clock(); //计时结束
    // cout << "The run time is: " <<(double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
    // for (int i = 1; i <= n; i++) cout << dp[i] << ", ";
    cin >> T;
    for (int cas = 1; cas <= T; cas++) {
        cin >> n;
        // vector<int> dp(n + 1, 0);
        // dp[1] = 1;
        // for (int i = 2; i <= n; i++) {
        //     dp[i] = i;
        //     for (int j = 1; j * 2 <= i; j++) {
        //         int tmp = dp[j] + 4 + (i - j) / j * 2 + (i - j) % j;
        //         dp[i] = min(dp[i], tmp);
        //     }
            // cout << "i= " << i << ", dp[i]= " << dp[i] << '\n';
        // } 
        cout << "Case #" << cas << ": " << dp[n] << '\n';
    }
    return 0;
}