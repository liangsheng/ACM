// https://atcoder.jp/contests/abc374/submissions/58458894
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n, s, t;
    cin >> n >> s >> t;
    vector<vector<int>> x(n, vector<int>(2)), y = x;
    for (int i = 0; i < n; i++) {
        cin >> x[i][0] >> y[i][0] >> x[i][1] >> y[i][1];
    }

    auto cal = [&](int x1, int y1, int x2, int y2, int f) {
        double d = sqrt(1.0 * (x1 - x2) * (x1 - x2) + 1.0 * (y1 - y2) * (y1 - y2));
        return d / f;
    };

    vector<int> id(n);
    iota(id.begin(), id.end(), 0);
    double ans = -1.0;
    do {
        for (int st = 0; st < (1 << n); st++) {
            double tmp = 0.0;
            int u = 0, v = 0;
            for (int i = 0; i < n; i++) {
                int p = (st >> i & 1);
                tmp += cal(u, v, x[id[i]][p], y[id[i]][p], s);
                tmp += cal(x[id[i]][p], y[id[i]][p], x[id[i]][p ^ 1], y[id[i]][p ^ 1], t);
                u = x[id[i]][p ^ 1], v = y[id[i]][p ^ 1];
            }
            if (ans < 0 || tmp < ans) ans = tmp;
        }
    } while (next_permutation(id.begin(), id.end()));
    cout << fixed << setprecision(7) << ans << '\n';

    return 0;
}