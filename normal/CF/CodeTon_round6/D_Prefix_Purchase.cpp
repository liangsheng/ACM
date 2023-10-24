#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T, n, k;
    cin >> T;
    while (T--) {
        cin >> n;
        vector<int> c(n + 2, 0), R(n + 2, -1);
        for (int i = 1; i <= n; i++) cin >> c[i];
        cin >> k;
        R[n] = n;
        for (int i = n - 1; i >= 1; i--) {
            R[i] = R[i + 1];
            if (c[i] < c[R[i + 1]]) R[i] = i;
        }
        int p = 1;
        vector<int> b;
        while (p != n + 1) b.push_back(R[p]), p = R[p] + 1;
        // for (int i = 0; i < b.size(); i++) cout << b[i] << ' ';
        // cout << '\n';
        int m = b.size(), d = k % c[b[0]];
        vector<int> ans(m, 0);
        ans[0] = k / c[b[0]];
        for (int i = 1; i < m; i++) {
            if (d == 0) break;
            int t = c[b[i]] - c[b[i - 1]];
            int c = min(d / t, ans[i - 1]);
            ans[i - 1] -= c, ans[i] += c;
            d = d - c * t;
        }
        vector<int> res(n + 1, 0);
        for (int i = 0; i < m; i++) res[b[i]] += ans[i];
        for (int i = n - 1; i >= 1; i--) res[i] += res[i + 1];
        for (int i = 1; i < n; i++) cout << res[i] << ' ';
        cout << res[n] << '\n';
    }
    return 0;
}