#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    LL n, m;;
    while (cin >> n >> m) {
        LL ans = 0;
        if (n > m) swap(n, m);
        while (m % n) {
            LL d = (m - n) / n + 1;
            ans += d;
            m = m - n * d;
            if (n > m) swap(n, m);
            // cout << n << ' ' << m << '\n';
        }
        ans += m / n - 1;
        cout << ans << '\n';
    }
    return 0;
}