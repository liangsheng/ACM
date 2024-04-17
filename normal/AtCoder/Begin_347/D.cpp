#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
 
int main() {
    // 下面 2 句话是为了让 cin 更快，不理解可以先不写
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    LL a, b, c, d = 60;
    cin >> a >> b >> c;
    vector<int> x(d, -1), y(d, -1);

    auto gao = [&]() {
        vector<int> p;
        for (int i = 0; i < d; i++) if ((c >> i) & 1) p.push_back(i);
        int n = p.size();
        if (a - b + n < 0 || (a - b + n) % 2) return false;
        int u = (a - b + n) / 2;
        if (u > n || u > a) return false;
        // cout << "u= " << u << ", v= " << v << '\n';
        for (int i = 0; i < u; i++) x[p[i]] = 1, y[p[i]] = 0;
        for (int i = u; i < n; i++) y[p[i]] = 1, x[p[i]] = 0;
        int w = a - u;
        for (int i = 0; w > 0 && i < d; i++) if (x[i] == -1) {
            w--;
            x[i] = 1, y[i] = 1;
        }
        if (w > 0) return false;
        for (int i = 0; i < d; i++) {
            if (x[i] == -1) x[i] = 0;
            if (y[i] == -1) y[i] = 0;
        }
        return true;
    };

    bool f = gao();
    if (f) {
        LL u = 0, v = 0, cu = 0, cv = 0;
        for (int i = d - 1; i >= 0; i--) u = u * 2 + x[i], cu += x[i];
        for (int i = d - 1; i >= 0; i--) v = v * 2 + y[i], cv += y[i];
        cout << u << ' ' << v << '\n';
        cout << cu << ' ' << cv << ' ' << (u ^ v) << '\n';
    } else cout << -1 << '\n';

    return 0;
}