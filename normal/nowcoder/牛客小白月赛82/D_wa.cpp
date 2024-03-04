#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T, n, a, b, x, y;
    cin >> T;
    while (T--) {
        cin >> n >> a >> b >> x >> y;
        vector<int> c(n);
        for (int i = 0; i < n; i++) cin >> c[i];
        sort(c.begin(), c.end());
        
        double ans = 0.0;
        for (int i = n - 1; i >= 0; i--) {
            if (a == 0 && b == 0) ans += c[i];
            else {
                double p = max(c[i] - y * 1.0, 0.0), q = c[i] * 0.01 * x;
                if (a == 0) ans += p, b--;
                else if (b == 0) ans += q, a--;
                else if (p < q) ans += p, b--;
                else ans += q, a--;
            }
//             cout << "i= " << i << ", ans= " << ans << ", a= " << a << ", b= " << b << '\n';
        }
        cout << fixed << setprecision(6) << ans << '\n';
    }
    return 0;
}