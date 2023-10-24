#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T, n, k;
    cin >> T;
    while (T--) {
        cin >> n >> k;
        vector<int> a(n, 0), f(k + 1, 0), L(n, 0), R(n, 0);
        for (int i = 0; i < n; i++) cin >> a[i], f[a[i]] = 1;
        L[0] = a[0], R[n - 1] = a[n - 1];
        for (int i = 1; i < n; i++) L[i] = max(L[i - 1], a[i]);
        for (int i = n - 2; i >= 0; i--) R[i] = max(R[i + 1], a[i]);
        for (int i = 1; i <= k; i++) {
            int ans = 0;
            if (f[i]) {
                int l = 0, r = n - 1, mid;
                while (l != r) {
                    mid = (l + r) >> 1;
                    if (L[mid] >= i) r = mid;
                    else l = mid + 1;
                }
                int p = l;
                l = 0, r = n - 1;
                while (l != r) {
                    mid = (l + r) / 2 + 1;
                    if (R[mid] >= i) l = mid;
                    else r = mid - 1;
                }
                // cout << "i= " << i << ", p= " << p << ", l= " << l << '\n';
                ans = (l - p + 1) * 2;
            }
            if (i == k) cout << ans << '\n';
            else cout << ans << ' ';
        }
    }
    return 0;
}