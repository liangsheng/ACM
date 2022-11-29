#include <bits/stdc++.h>
using namespace std;

const int N = 1000005;

int n;
string s;
int dp[N][2];

int gao() {
    int id = s[0] - '0';
    memset(dp, 127, sizeof(dp));
    dp[0][0] = min(id, 11 - id);
    dp[0][1] = min(id + 1, 10 - id);
    for (int i = 1; i < n; i++) {
        int id = s[i] - '0';
        dp[i][0] = dp[i - 1][0] + id;
        dp[i][0] = min(dp[i][0], dp[i - 1][1] + 10 - id);

        dp[i][1] = dp[i - 1][0] + id + 1;
        dp[i][1] = min(dp[i][1], dp[i - 1][1] + 9 - id);
    }
    return dp[n - 1][0];
}

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    while (cin >> s) {
        n = s.size();
        cout << gao() << '\n';    
    }
    return 0;
}