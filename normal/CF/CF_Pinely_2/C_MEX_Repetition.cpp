#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T, n, k;
    cin >> T;
    while (T--) {
        cin >> n >> k;
        vector<int> a(n + 1, 0), f(n + 1, 0), b(n + 1, 0);
        for (int i = 1; i <= n; i++) cin >> a[i], f[a[i]] = 1;
        k %= n + 1;
        for (int i = 0; i <= n; i++) if (!f[i]) {
            a[0] = i;
            break;
        }
        for (int i = 0; i <= n; i++) b[i] = a[(i - k + n + 1) % (n + 1)];
        for (int i = 1; i < n; i++) cout << b[i] << ' ';
        cout << b[n] << '\n';
    }
    return 0;
}
