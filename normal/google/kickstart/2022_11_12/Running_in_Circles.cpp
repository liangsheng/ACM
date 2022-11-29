#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // cout << (~0U >> 1) << '\n' << 2000000000 << '\n';
    LL T, n, m, ans, d, now;
    char ch;
    cin >> T;
    for (int cas = 1; cas <= T; cas++) {
        cin >> m >> n;
        ans = 0, now = 0;
        for (int i = 1; i <= n; i++) {
            cin >> d >> ch;
            if (ch == 'C') {
                now += d;
                if (now >= m) ans += now / m, now = (now % m + m) % m;
            } else {
                now -= d;
                if (now <= -m) {
                    ans += (-now) / m, now = (now % m + m) % m;
                    if (now != 0) now -= m;
                }
            }
        }
        cout << "Case #" << cas << ": " << ans << '\n';
    }
    return 0;
}