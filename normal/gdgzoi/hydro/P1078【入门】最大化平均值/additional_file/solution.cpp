#include <bits/stdc++.h>
using namespace std;

int main() {
    // 下面 2 句话是为了让 cin, cout 更快, 并不理解可以先不写
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    
    int n, k;
    cin >> n >> k;
    vector<int> w(n), v(n);
    for (int i = 0; i < n; i++) cin >> w[i];
    for (int i = 0; i < n; i++) cin >> v[i];

    double l = 0, r = 1000000000, mid;

    // 计算 sum(v_i + mid * w_i) 是否 >= 0
    auto ok = [&](double mid) {
        vector<double> c(n);
        for (int i = 0; i < n; i++) c[i] = w[i] - mid * v[i];
        sort(c.begin(), c.end());
        double sum = 0;
        for (int i = 1; i <= k; i++) sum += c[n - i];
        return sum >= 0;
    };

    // 注意: 浮点数二分时，需要设置二分次数，防止死循环
    // 二分次数可以根据题目数据大小变化,
    // 一般来说 50 到 60 次足以解决大部分问题
    for (int j = 0; j < 60; j++) {
        mid = (l + r) / 2;
        if (ok(mid)) l = mid;
        else r = mid;
    }
    cout << fixed << setprecision(2) << l << '\n';

    // 以下贪心做法是不对的
    // vector<int> c(n);
    // for (int i = 0; i < n; i++) c[i] = i;
    // sort(c.begin(), c.end(), [&](const int& x, const int& y) {
    //     return w[x] * v[y] > w[y] * v[x];
    // });
    // double p = 0, q = 0;
    // for (int i = 0; i < k; i++) p += w[c[i]], q += v[c[i]];
    // cout << fixed << setprecision(2) << p / q << '\n';
    return 0;
}