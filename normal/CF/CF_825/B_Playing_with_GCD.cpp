#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T, n;
    cin >> T;
    while (T--) {
        cin >> n;
        vector<int> a(n), b(n + 1);
        for (int i = 0; i < n; i++) cin >> a[i];
        b[0] = a[0], b[n] = a[n - 1];
        for (int i = 1; i < n; i++) b[i] = a[i - 1] * a[i] / __gcd(a[i - 1], a[i]);
        bool flag = 1;
        for (int i = 0; i < n; i++) if (__gcd(b[i], b[i + 1]) != a[i]) {
            flag = 0;
            break;
        }
        cout << (flag ? "YES" : "NO") << '\n';
    }
    return 0;
}