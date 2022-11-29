#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N = 105;

int T, n, k;
LL a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> n >> k;
        LL ans = 0, now = 0, tmp;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (i == 0) now = a[i];
            else {
                if (a[i] * 100 > now * k) {
                    tmp = ceil(a[i] * 100.0 / k) - now;
                    ans += tmp, now += tmp + a[i];
                } else now += a[i];
            }
            // cout << i << ' ' << now << ' ' << ans << ' ' << a[i] * 1.0 * 100 / k << ' ' << ceil(a[i] * 100 / k) << '\n';
        }
        cout << ans << '\n';
    }
    return 0;
}