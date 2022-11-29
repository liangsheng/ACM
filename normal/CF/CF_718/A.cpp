#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int T;
LL n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> n;
        if (n % 2050) cout << "-1\n";
        else {
            n = n / 2050;
            LL ans = 0;
            while (n != 0) ans += n % 10, n /= 10;
            cout << ans << '\n';
        }
    }
    return 0;
}