#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, p;
    while (cin >> n >> p) {
        vector<int> a(n), h(p, 0), c(p, 0);
        vector<LL> ans(p, 0);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            a[i] %= p;
            h[a[i]]++;
        }
        for (int i = 0; i < n; i++) for (int j = i + 1; j < n; j++) {
            c[(LL) a[i] * a[j] % p] += 2;
            ans[((LL) a[i] * a[j] + a[i]) % p] -= 2;
            ans[((LL) a[i] * a[j] + a[j]) % p] -= 2;
        }
        // for (int k = 0; k < p; k++) cout << h[k] << ' ';
        // cout << '\n';
        // for (int k = 0; k < p; k++) cout << c[k] << ' ';
        // cout << '\n';
        // for (int k = 0; k < p; k++) cout << ans[k] << ' ';
        // cout << '\n';
        for (int k = 0; k < p; k++) {
            if (c[k] == 0) continue;
            for (int i = 0; i < p; i++) ans[(i + k) % p] += (LL) c[k] * h[i];
        }
        for (int i = 0; i < p - 1; i++) cout << ans[i] << ' ';
        cout << ans[p - 1] << '\n';
    }
    return 0;
}