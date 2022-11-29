#include <bits/stdc++.h>
using namespace std;

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    int n;
    while (~scanf("%d", &n)) {
        vector<int> x(n), y(n);
        for (int i = 0; i < n; i++) scanf("%d %d", &x[i], &y[i]);
        auto f = [&](int i, int j) {
            return sqrt((x[i] - x[j]) * (x[i] - x[j]) * 1.0 + (y[i] - y[j]) * (y[i] - y[j]));
        };
        double ans = 0.0;
        for (int i = 0; i < n; i++) for (int j = i + 1; j < n; j++) ans = max(ans, f(i, j));
        printf("%.7f\n", ans);
    }
    return 0;
}