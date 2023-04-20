#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T, n, m;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        vector<int> a(n, 0);
        for (int i = 0; i < n; i++) cin >> a[i];
        sort(a.begin(), a.end());
        a.erase(unique(a.begin(), a.end()), a.end());
        n = a.size();

        int ans = 0;
        for (int k = 0; k < 30; k++) {
            vector<int> c(2, 0);
            for (int i = 0; i < n; i++) c[(a[i] >> k) & 1] = 1;
            if (c[0] + c[1] >= 2) {
                // cout << "k= " << k << '\n';
                if ((m >> k) & 1) {
                    ans = max(ans, (m >> (k + 1) << (k + 1)) + (1 << k) - 1);
                } else {
                    ans = m;
                    break;
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}