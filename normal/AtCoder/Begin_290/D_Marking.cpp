#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T, n, d, k;
    cin >> T;
    while (T--) {
        cin >> n >> d >> k;
        int cnt = n / __gcd(n, d);
        // cout << "cnt= " << cnt << '\n';
        if (k % cnt == 0) {
            cout << (k / cnt - 1 + (LL) (cnt - 1) * d) % n << '\n';
        } else {
            int ans = k / cnt;
            k %= cnt;
            ans = (ans + (LL) (k - 1) * d) % n;
            cout << ans << '\n';
        }
    }
    return 0;
}