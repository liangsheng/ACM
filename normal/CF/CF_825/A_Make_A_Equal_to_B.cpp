#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T, n;
    cin >> T;
    while (T--) {
        cin >> n;
        vector<int> a(n), b(n);
        int a1 = 0, b1 = 0;
        for (int i = 0; i < n; i++) cin >> a[i], a1 += (a[i] == 1);
        for (int i = 0; i < n; i++) cin >> b[i], b1 += (b[i] == 1);
        int ans = n, tmp = 0;
        for (int i = 0; i < n; i++) tmp += a[i] ^ b[i];
        ans = min(ans, tmp);
        ans = min(ans, abs(a1 - b1) + 1);
        cout << ans << '\n';
    }
    return 0;
}