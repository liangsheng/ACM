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
        vector<int> a(n + 2, 0), b(n + 2, 0);
        vector<LL> c(n + 2, 0);
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = 1; i <= n; i++) cin >> b[i];

        vector<int> d(n + 2, 0);
        vector<LL> e(n + 2, 0);
        for (int i = 1; i <= n; i++) c[i] = c[i - 1] + b[i];
        for (int i = n; i >= 1; i--) {
            int l = i, r = n, mid;
            if (c[r] - c[l - 1] <= a[i]) d[i]++;
            else if (a[i] < b[i]) {
                e[i] += a[i];
            } else {
                while (l != r) {
                    mid = (l + r) / 2 + 1;
                    if (c[mid] - c[i - 1] <= a[i]) l = mid;
                    else r = mid - 1;
                }
                d[i]++, d[l + 1]--;
                e[l + 1] += a[i] - (c[l] - c[i - 1]);
            }
        }
        for (int i = 1; i <= n; i++) {
            d[i] += d[i - 1];
            e[i] += (LL) d[i] * b[i];
            cout << e[i];
            cout << (i == n ? '\n' : ' ');
        }
    }
    return 0;
}