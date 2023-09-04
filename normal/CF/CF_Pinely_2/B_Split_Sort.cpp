#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T, n, x;
    cin >> T;
    while (T--) {
        cin >> n;
        vector<int> a(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            cin >> x;
            a[x] = i;
        }
        int ans = 0;
        for (int i = 2; i <= n; i++) ans += a[i] < a[i - 1];
        cout << ans << '\n';
    }
    return 0;
}
