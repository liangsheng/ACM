#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    int T, n;
    cin >> T;
    while (T--) {
        cin >> n;
        vector<int> a(n, 0), b(n + 1, 0);
        for (int i = 0; i < n; i++) cin >> a[i], b[a[i]]++;
        int ans = 0;
        while (1) {
            // cout << "n= " << n << '\n';
            if (n == 1) {
                ans++;
                break;
            }
            int p = -1;
            for (int i = 0; i < n; i++) {
                int l = (i - 1 + n) % n, r = (i + 1) % n;
                if (a[l] != a[r]) {
                    if (p == -1 || b[a[i]] > b[a[p]]) p = i;
                }
            }
            if (p == -1) {
                ans += n / 2 + 1;
                break;
            } else {
                b[a[p]]--;
                for (int j = p; j < n - 1; j++) a[j] = a[j + 1];
                ans++, n--;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}