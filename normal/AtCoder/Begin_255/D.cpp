#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    LL n, m, x, sum;
    while (cin >> n >> m) {
        vector<LL> a(n), b(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        sort(a.begin(), a.end());
        sum = accumulate(a.begin(), a.end(), 0LL);
        b[0] = a[0];
        for (int i = 1; i < n; i++) b[i] = b[i - 1] + a[i];
        while (m--) {
            cin >> x;
            if (x <= a[0]) cout << sum - x * n << '\n';
            else if (x >= a[n - 1]) cout << x * n - sum << '\n';
            else {
                int id = lower_bound(a.begin(), a.end(), x) - a.begin();
                LL R = b[n - 1] - b[id - 1], L = sum - R;
                LL ans = R - (n - id) * x + id * x - L;
                cout << ans << '\n';
            }
        }
    }
    return 0;
}