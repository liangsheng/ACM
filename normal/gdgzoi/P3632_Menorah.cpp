#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long LL;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T, n;
    string s1, s2;
    cin >> T;
    while (T--) {
        cin >> n;
        cin >> s1 >> s2;
        vector<int> c(2, 0), d(2, 0);
        for (int i = 0; i < n; i++) c[s1[i] - '0']++;
        for (int i = 0; i < n; i++) d[s2[i] - '0']++;
        
        // 你不会把选中同一个位置 2 遍
        // s = 0011
        // 选 i = 3：s = 1110
        // 选 i = 1：s = 1001
        // 选 i = 4：s = 0111
        // 选 i = 3：s = 1010
        // 不如这样:
        // 选 i = 4：s = 1101
        // 选 i = 1：s = 1101
        int ans = n + 1;
        vector<int> f(2, 0);
        if (d[1] == c[0] + 1) {
            for (int i = 0; i < n; i++) if (s1[i] == s2[i]) f[s1[i] - '0']++;
            if (f[1] == f[0] + 1) ans = f[0] + f[1];
        }

        if (d[1] == c[1]) {
            f[0] = 0, f[1] = 0;
            for (int i = 0; i < n; i++) if (s1[i] != s2[i]) f[s1[i] - '0']++;
            // cout << s1 << "\n" << s2 << "\n" << f[0] << " " << f[1] << '\n';
            if (f[1] == f[0]) ans = min(ans, f[0] + f[1]);
        }

        if (ans == n + 1) ans = -1;
        cout << ans << '\n';
    }
    return 0;
}