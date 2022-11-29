#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

LL L, R;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (cin >> L >> R) {
        LL ans = 1;
        for (LL i = L; i <= min(R, L + 1000); i++) for (LL j = R; j >= max(L, R - 1000); j--) {
            if (__gcd(i, j) == 1) ans = max(ans, abs(i - j));
        }
        cout << ans << '\n';
    }
    return 0;
}