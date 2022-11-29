#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int INF = ~0U >> 2;

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    int T, n;
    cin >> T;
    for (int cas = 1; cas <= T; cas++) {
        cin >> n;
        vector<int> a(n + 1), ans(n + 1);
        for (int i = 1; i <= n; i++) cin >> a[i];
        
        vector<int> b, f(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            if (f[i]) continue;
            int cnt = 0, p = i;
            while (!f[p]) {
                // cout << "p= " << p << ", cnt= " << cnt << '\n';
                f[p] = 1, cnt++;
                p = a[p];
            }
            b.push_back(cnt);
        }
        // for (int i = 0; i < b.size(); i++) cout << b[i] << ' ';
        // cout << '\n';
        int m = b.size();
        sort(b.begin(), b.end());

        vector<int> dp(n + 1, INF);
        dp[0] = 0;
        for (int i = 0; i < m; i++) {
            for (int j = n; j >= 0; j--) if (j + b[i] <= n) {
                dp[j + b[i]] = min(dp[j + b[i]], dp[j] + 1);
            }
        }
        // for (int i = 0; i <= n; i++) cout << dp[i] << '\n';
        for (int i = 1; i <= n; i++) {
            int id = lower_bound(b.begin(), b.end(), i) - b.begin();
            if (id < m && b[id] == i) {
                ans[i] = 0;
                continue;
            }
            if (i <= b[m - 1]) {
                ans[i] = 1;
                continue;
            }
            int now = 0;
            for (int j = m - 1; j >= 0; j--) {
                if (now + b[j] < i) now += b[j];
                else if (now + b[j] == i) {
                    ans[i] = m - j - 1;
                    break;
                } else {
                    int p = lower_bound(b.begin(), b.end(), i - now) - b.begin();
                    if (p < m && b[p] == i - now) ans[i] = m - j - 1;
                    else ans[i] = m - j;
                    break;
                }
            }
            ans[i] = min(ans[i], dp[i] - 1);
        }
        cout << "Case #" << cas << ":";
        for (int i = 1; i <= n; i++) cout << " " << ans[i];
        cout << '\n';
    }
    return 0;
}