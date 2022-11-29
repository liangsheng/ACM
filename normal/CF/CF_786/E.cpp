#include <bits/stdc++.h>
using namespace std;

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    int n;
    while (cin >> n) {
        vector<int> a(n, 0);
        for (int i = 0; i < n; i++) cin >> a[i];
        int ans = -1, x = 0, y = 1;
        if (a[x] > a[y]) swap(x, y);
        for (int i = 2; i < n; i++) {
            if (a[i] < a[x]) y = x, x = i;
            else if (a[i] < a[y]) y = i;
        }
        // cout << a[x] << ' ' << a[y] << '\n';
        ans = a[x] / 2 + a[x] % 2  + a[y] / 2 + a[y] % 2;
        // cout << "ans1= " << ans << '\n';
        for (int i = 1; i < n - 1; i++) ans = min(ans, max(a[i - 1], a[i + 1]));
        // cout << "ans2= " << ans << '\n';
        for (int i = 0; i < n - 1; i++) {
            x = a[i], y = a[i + 1];
            if (x < y) swap(x, y);
            if (x >= y * 2) ans = min(ans, x / 2 + x % 2);
            else {
                int tmp = x - y;
                x -= tmp * 2;
                tmp += x / 3 * 2;
                x = x % 3;
                if (x == 1) tmp++;
                else if (x == 2) tmp += 2;
                ans = min(ans, tmp);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}