#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T, n, k;
    string s;
    cin >> T;
    while (T--) {
        cin >> n >> k;
        cin >> s;
        vector<int> f0(n + 1, 0), f1(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            f0[i] = f0[i - 1] + (s[i - 1] == '0');
            f1[i] = f1[i - 1] + (s[i - 1] == '1');
        }
        auto gao = [&](int l, int r, int v) {
            if (l > r) return 0;
            if (v == 0) return f0[r] - f0[l - 1];
            if (v == 1) return f1[r] - f1[l - 1];
            return r - (l - 1) - (f0[r] - f0[l - 1]) - (f1[r] - f1[l - 1]);
        };
        int ans = 0;
        for (int i = 1; i + k - 1 <= n; i++) {
            char ch = s[i - 1];
            if (ch == 0) continue;
            int l = i, r = i + k - 1;
            if (gao(1, l - 1, 1) > 0) continue;
            if (gao(r + 1, n, 1) > 0) continue;
            if (gao(l, r, 0) > 0) continue;
            ans++;
        }
        if (ans == 1) cout << "Yes" << '\n';
        else cout << "No" << '\n';
    }
    return 0;
}