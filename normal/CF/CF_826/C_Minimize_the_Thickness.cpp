#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T, n;
    cin >> T;
    while (T--) {
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        int ans = n, sum = accumulate(a.begin(), a.end(), 0);
        for (int k = 2; k <= n; k++) {
            if (sum % k) continue;
            int flag = 1, d = sum / k, p = 0;
            for (int i = 0; i < n; i++) {
                int tmp = a[i], j = i;
                while (tmp < d) tmp += a[++i];
                if (tmp != d) {
                    flag = 0;
                    break;
                }
                p = max(p, i - j + 1);
            }
            // cout << "k= " << k << ' ' << flag << ' ' << d << ' ' << p << '\n';
            if (flag) ans = min(ans, p);
        }
        cout << ans << '\n';
    }
    return 0;
}