#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k, t;
    while (cin >> n >> k >> t) {
        vector<int> a(k), b(n, 0), d(n, 0);  // b: wait time; d: step width
        for (int i = 0; i < k; i++) cin >> a[i];

        // calculate step width
        for (int i = 1; i < k; i++) d[a[i - 1]] = a[i] - a[i - 1];
        d[a[k - 1]] = n - a[k - 1];

        // calculate wait time
        for (int i = 1; i < k; i++) for (int j = a[i - 1] + 1; j < a[i]; j++) {
            b[j] = j - a[i - 1];
            d[j] = d[a[i - 1]];
        }
        for (int j = a[k - 1] + 1; j < n; j++) {
            b[j] = j - a[k - 1];
            d[j] = d[a[k - 1]];
        }
        vector<int> ans(n, 0);
        for (int i = 0; i < n; i++) {
            if (t <= b[i]) ans[i] = i;
            else {
                int p = (i + (t - b[i] + d[i] - 1) / d[i] * d[i]) % n;
                ans[p] = i;
            }
        }
        for (int i = 0; i < n; i++) {
            cout << ans[i] << " \n"[i == n - 1];
        }
    }
    return 0;
}