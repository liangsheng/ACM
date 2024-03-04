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
        sort(c.begin(), c.end(), greater<int>());
         
        double ans = 0.0;
        for (int i = a + b; i < n; i++) ans += c[i];
        n = min(n, a + b);
        int id = n;
        for (int i = 0; i < n; i++) {
            double p = c[i] * 0.01 * x, q = max(c[i] - y * 1.0, 0.0);
            // 立减券比折扣券优
            if (q < p) {
                id = i;
                break;
            }
        }
        id = min(id, a);
        int m = min(n - id, b);
//         cout << "id= " << id << ", m= " << m << '\n';
        for (int i = 0; i < id; i++) ans += c[i] * 0.01 * x;
        for (int i = id; i < id + m; i++) ans += max(c[i] - y * 1.0, 0.0);
        for (int i = id + m; i < n; i++) ans += c[i] * 0.01 * x;
        cout << fixed << setprecision(6) << ans << '\n';
    }
    return 0;
}