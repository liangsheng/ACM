#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N = 16;

int n, m;
string s[N];
int dp[N][1 << N];
vector<int> f[N];

int gao(int p, int st) {
    if (dp[p][st] != -1) return dp[p][st];
    dp[p][st] = 0;
    for (int j : f[p]) {
        if ((st >> j) & 1) continue;
        if (gao(j, st | (1 << j)) == 0) {
            dp[p][st] = 1;
            break;
        }
    }
    return dp[p][st];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (cin >> n) {
        for (int i = 0; i < n; i++) cin >> s[i];

        m = 1 << n;
        for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) dp[i][j] = -1;
        for (int i = 0; i < n; i++) {
            f[i].clear();
            for (int j = 0; j < n; j++) {
                if (j == i) continue;
                if (s[j][0] == s[i][s[i].size() - 1]) f[i].push_back(j);
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int res = gao(i, 1 << i);
            if (res == 0) {
                ans = 1;
                break;
            }
        }
        cout << (ans ? "First" : "Second") << '\n';
    }
    return 0;
}