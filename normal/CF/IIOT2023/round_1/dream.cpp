#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int MOD = 666013;

int gao(int d) {
    vector<int> f;
    while (d != 0) f.push_back(d % 10), d /= 10;
    int ans = 0;
    for (int i = 0; i < f.size(); i++) ans = (ans * 10 + f[i]) % MOD;
    return ans;
}

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    int n, m;
    while (cin >> n >> m) {
        vector<LL> d(m + 1, 1);
        for (int i = 1; i <= m; i++) d[i] = d[i - 1] * 10 % MOD;
        if (m <= 12) {
            int l = 1;
            for (int i = 1; i < m / 2; i++) l *= 10;
            int r = l + n - 1, ans = 0;
            // cout << "l= " << l << ", r= " << r << '\n';
            for (int i = l; i <= r; i++) {
                ans = ans + i * d[m / 2] % MOD + gao(i);
                ans = ans % MOD;
                // cout << "i= " << i << ", " << gao(i) << ", ans= " << ans << '\n';
            }
            cout << ans << '\n';
        } else {
            int ans = (d[m - 1] + 1) * n % MOD;
            // cout << "ans= " << ans << '\n';
            int l = 0, r = n - 1;
            for (int i = l; i <= r; i++) {
                ans = (ans + i * d[m / 2]) % MOD;

                int k = i;
                vector<int> f;
                while (k != 0) f.push_back(k % 10), k /= 10;
                for (int j = 0, t = m / 2 - 1; j < f.size(); j++, t--) ans = (ans + f[j] * d[t]) % MOD;
                // cout << "i= " << i << ", ans= " << ans << '\n';
            }
            cout << ans << '\n';
        }
    }
    return 0;
}