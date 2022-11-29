#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int n, m;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (cin >> n) {
        vector<LL> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        cin >> m;
        vector<LL> x(m), y(m);
        for (int i = 0; i < m; i++) cin >> x[i] >> y[i];
        sort(a.begin(), a.end());
        LL sum = accumulate(a.begin(), a.end(), 0LL);
        for (int i = 0; i < m; i++) {
            if (a[n - 1] <= x[i]) {
                cout << x[i] - a[n - 1] + max(y[i] - (sum - a[n - 1]), 0LL) << '\n';
            } else if (a[0] >= x[i]) {
                cout << max(y[i] - (sum - a[0]), 0LL) << '\n';
            }
            else {
                int u = lower_bound(a.begin(), a.end(), x[i]) - a.begin(), v = u - 1;
                LL ans = max(y[i] - (sum - a[u]), 0LL);
                LL res = x[i] - a[v] + max(y[i] - (sum - a[v]), 0LL);
                cout << min(ans, res) << '\n';
            }
        }
    }
}