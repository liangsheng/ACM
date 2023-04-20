#include <bits/stdc++.h>
using namespace std;

double gao(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4) {
    double tol = (x2 - x1) * (y2 - y1) + (x4 - x3) * (y4 - y3);
    double x5 = max(x1, x3);
    double y5 = max(y1, y3);
    double x6 = min(x2, x4);
    double y6 = min(y2, y4);
    // cout << x5 << ' ' << y5 << ' ' << x6 << ' ' << y6 << '\n';
    double now = 0.0;
    if (x6 > x5 && y6 > y5) {
        now = (x6 - x5) * (y6 - y5);
    }
    return now / (tol - now);
}

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    int T;
    double x, y, xp, yp;
    // cin >> T;
    scanf("%d", &T);
    while (T--) {
        // cin >> x >> y >> xp >> yp;
        scanf("%lf %lf %lf %lf", &x, &y, &xp, &yp);
        double ans = gao(0.0, 0.0, x, y, min(xp, 0.0), min(yp, 0.0), max(xp, 0.0), max(yp, 0.0));
        // cout << "ans= " << ans << '\n';
        double res = gao(0.0, 0.0, x, y, min(xp, x), min(yp, 0.0), max(xp, x), max(yp, 0.0));
        // cout << "res= " << res << '\n';
        ans = max(ans, res);
        res = gao(0.0, 0.0, x, y, min(xp, 0.0), min(yp, y), max(xp, 0.0), max(yp, y));
        // cout << "res= " << res << '\n';
        ans = max(ans, res);
        res = gao(0.0, 0.0, x, y, min(xp, x), min(yp, y), max(xp, x), max(yp, y));
        // cout << "res= " << res << '\n';
        ans = max(ans, res);
        printf("%.9f\n", ans);
    }
    return 0;
}