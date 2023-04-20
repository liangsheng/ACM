#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int MOD = 998244353;

void add(int &x, int y) {
    x = x + y;
    if (x >= MOD) x -= MOD;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    string s;
    while (cin >> n) {
        cin >> s;

        vector<vector<vector<int>>> dp(2, vector<vector<int>>(27, vector<int>(27, 0)));
        int now = 0, pre = 1;
        dp[now][26][26] = 1;
        for (int i = 0; i < n; i++) {
            swap(now, pre);
            for (int x = 0; x < 27; x++) for (int y = 0; y < 27; y++) dp[now][x][y] = 0;
            int l = 0, r = 25;
            if (s[i] != '?') l = s[i] - 'a', r = l;
            for (int x = 0; x < 27; x++) for (int y = 0; y < 27; y++) {
                if (dp[pre][x][y] == 0) continue;
                for (int z = l; z <= r; z++) {
                    if (z == x || z == y) continue;
                    add(dp[now][y][z], dp[pre][x][y]);
                }
            }
        }
        int ans = 0;
        for (int x = 0; x < 26; x++) for (int y = 0; y < 26; y++) add(ans, dp[now][x][y]);
        cout << ans << '\n';
    }
    return 0;
}