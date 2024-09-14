#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T, n, m;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        LL ans = 0;
        for (int i = 1, j; i <= min(n, m); i = j + 1) {
            j = min(n / (n / i), m / (m / i));
            ans += (LL) (n / i) * (m / i) * (j - i + 1);
        }
        cout << ans << '\n';
    }
    return 0;
}