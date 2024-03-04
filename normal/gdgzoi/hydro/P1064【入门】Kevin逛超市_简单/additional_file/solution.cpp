#include <bits/stdc++.h>
using namespace std;
typedef pair<double, double> pdd;

const int N = 200005;

int main() {
    // 下面 2 句话是为了让 cin, cout 更快, 不理解可以先不写
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T, n, x, y;
    cin >> T;
    while (T--) {
        cin >> n >> x >> y;

        vector<int> c(n);
        for (int i = 0; i < n; i++) cin >> c[i];
        sort(c.begin(), c.end(), greater<int>());
        double ans = 0.0;
        for (int i = 2; i < n; i++) ans += c[i];  // 只给前 2 名用券, 剩下的原价买

        if (n == 1) {
            double a = 0.01 * x * c[0];
            double b = max(c[0] * 1.0 - y, 0.0);
            cout << fixed << setprecision(4) << ans + min(a, b) << '\n'; 
        } else {
            double a = 0.01 * x * c[0] + max(c[1] * 1.0 - y, 0.0);
            double b = 0.01 * x * c[1] + max(c[0] * 1.0 - y, 0.0);
            cout << fixed << setprecision(4) << ans + min(a, b) << '\n';
        }
    }
    return 0;
}