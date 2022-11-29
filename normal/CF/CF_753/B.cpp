#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    // int z = -1;
    // cout << "0 " << z << '\n';
    // for (int i = 1; i <= 100; i++) {
    //     if (z % 2 == 0) z -= i;
    //     else z += i;
    //     cout << i << ' ' << z << '\n';
    // }
    int T;
    LL x, y, n, ans;
    cin >> T;
    while (T--) {
        cin >> x >> n;
        y = n / 4 * 4, ans = x;
        for (y = y + 1; y <= n; y++) {
            if (ans % 2) ans += y;
            else ans -= y;
        }
        cout << ans << '\n';
    }
    return 0;
}