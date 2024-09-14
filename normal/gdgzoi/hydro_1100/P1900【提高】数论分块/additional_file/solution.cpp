#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    LL T, n;
    cin >> T;
    while (T--) {
        cin >> n;
        LL ans = 0;
        for (LL l = 1; l <= n; l++) {
            LL k = n / l, r = n / k;
            ans += (LL) k * (r - l + 1);
            l = r;
        }
        cout << ans << '\n';
        // for (LL i = 1, j; i <= n; i = j + 1) {
        //     j = n / (n / i);
        //     ans += (n / i) * (j - i + 1);
        // }
        // cout << ans << '\n';
    }
    return 0;
}