#include <bits/stdc++.h>
using namespace std;
typedef pair<double, double> pdd;

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
        // 按价格从大到小排序
        sort(c.begin(), c.end(), greater<int>());

        double ans = 0.0;
        // 只给前 a + b 个用优惠券(只给价格高的用)
        for (int i = a + b; i < n; i++) ans += c[i];
        n = min(n, a + b);

        vector<pdd> A, B;
        for (int i = 0; i < n; i++) {
            double da = 0.01 * x * c[i];
            double db = max(c[i] * 1.0 - y, 0.0);
            double d = abs(da - db);
            if (da < db) A.push_back({d, da});
            else B.push_back({d, db});
        }
        int a_cnt = A.size(), b_cnt = B.size();
        if (a_cnt > a) {
            for (auto it : B) ans += it.second;
            sort(A.begin(), A.end());
            for (int i = 0; i < (int) A.size(); i++) {
                if (i < a_cnt - a) ans += A[i].first + A[i].second;
                else ans += A[i].second;
            }
        } else {
            for (auto it : A) ans += it.second;
            sort(B.begin(), B.end());
            for (int i = 0; i < (int) B.size(); i++) {
                if (i < b_cnt - b) ans += B[i].first + B[i].second;
                else ans += B[i].second;
            }            
        }

        cout << fixed << setprecision(4) << ans << '\n';
    }
    return 0;
}