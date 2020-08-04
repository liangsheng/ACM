#include <iostream>
#include <cstring>

using namespace std;

int n;
int a[10005], dp[10005][2];

int main() {
    int ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    memset(dp, -1, sizeof(dp));
    dp[0][0] = 0;
    for (int i = 0; i < n; i++) {
        if (dp[i][0] != -1) {
            dp[i + 1][0] = max(dp[i + 1][0], dp[i][0]);
            dp[i + 1][1] = max(dp[i + 1][1], dp[i][0] + a[i + 1]);
        }
        if (dp[i][1] != -1) {
            dp[i + 1][0] = max(dp[i + 1][0], dp[i][1]);
        }
    }
    ans = max(dp[n][0], dp[n][1]);
    cout << ans << '\n';
    return 0;
}
