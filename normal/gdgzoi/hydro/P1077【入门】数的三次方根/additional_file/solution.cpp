#include <bits/stdc++.h>
using namespace std;

// eps = 0.00000001
const double eps = 1e-8;

int main() {
    // 下面 2 句话是为了让 cin, cout 更快, 并不理解可以先不写
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    double n;
    cin >> n;

    double l = -1000, r = 1000, mid;

    // 注意: 浮点数二分时，需要设置二分次数，防止死循环
    for (int i = 0; i < 100; i++) {
        mid = (l + r) / 2;
        if (mid * mid * mid < n) l = mid;
        else r = mid;
    }
    cout << fixed << setprecision(8) << l << '\n';
    return 0;
}