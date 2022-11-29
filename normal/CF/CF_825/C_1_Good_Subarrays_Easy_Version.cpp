#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T, n;
    cin >> T;
    while (T--) {
        cin >> n;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++) cin >> a[i];

        LL ans = 0, p = 1;
        for (int i = 1; i <= n; i++) {
            while (p + 1 <= n && a[p + 1] >= p + 1 - i + 1) p++;
            ans += p - i + 1;
        }
        cout << ans << '\n';
    }
    return 0;
}