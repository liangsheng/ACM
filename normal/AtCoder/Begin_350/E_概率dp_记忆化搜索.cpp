#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    LL n, a, x, y;
    cin >> n >> a >> x >> y;
    
    map<LL, double> dp;
    dp[0] = 0;
    
    function<double(LL)> f = [&](LL n) {
        if (dp.count(n)) return dp[n];
        double u = 1.2 * y + 0.2 * (f(n / 2) + f(n / 3) + f(n / 4) + f(n / 5) + f(n / 6));
        double v = x + f(n / a);
        // cout << "n= " << n << " " << dp[n] << '\n';
        return dp[n] = min(u, v);
    };
    cout << fixed << setprecision(6) << f(n) << '\n';
    return 0;
}