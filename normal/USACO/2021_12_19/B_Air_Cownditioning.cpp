#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, x;
    while (cin >> n) {
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) {
            cin >> x;
            a[i] -= x;
        }
        int ans = (a[0] > 0 ? a[0] : -a[0]);
        for (int i = 1; i < n; i++) {
            if (a[i] == 0) continue;
            if (a[i] * a[i - 1] > 0) ans += max(abs(a[i]) - abs(a[i - 1]), 0);
            else ans += abs(a[i]);
        }
        cout << ans << '\n';
    }
    return 0;
}