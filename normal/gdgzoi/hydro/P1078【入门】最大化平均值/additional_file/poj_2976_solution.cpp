#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    // 下面 2 句话是为了让 cin, cout 更快, 并不理解可以先不写
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    
    int n, k;
    while (cin >> n >> k) {
        if (n == 0 && k == 0) break;
    k = n - k;
    vector<int> v(n), w(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    for (int i = 0; i < n; i++) cin >> w[i];

    double l = 0, r = 1000000000, mid;

    // 注意: 浮点数二分时，需要设置二分次数，防止死循环
    for (int j = 0; j < 100; j++) {
        mid = (l + r) / 2;
        vector<double> c(n);
        for (int i = 0; i < n; i++) c[i] = v[i] - mid * w[i];
        sort(c.begin(), c.end());
        double sum = 0;
        for (int i = 1; i <= k; i++) sum += c[n - i];
        if (sum >= 0) l = mid;
        else r = mid;
    }
    cout << (int) (l * 100 + 0.5) << '\n';
    }
    // cout << fixed << setprecision(4) << l << '\n';
    return 0;
}