#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T, n;
    cin >> T;
    while (T--) {
        cin >> n;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++) cin >> a[i];
        if (n == 1) {
            cout << (a[1] == 1 ? 0 : 1) << '\n';
            continue;
        }
        int d, pre = a[1];
        for (int i = 2; i <= n - 2; i++) pre = __gcd(pre, a[i]);
        d = __gcd(__gcd(pre, a[n - 1]), a[n]);
        if (d == 1) cout << 0 << '\n';
        else {
            int t = __gcd(a[n], n), f = __gcd(a[n - 1], n - 1);
            if (__gcd(__gcd(pre, a[n - 1]), t) == 1) cout << 1 << '\n';
            else if (__gcd(__gcd(pre, f), a[n]) == 1) cout << 2 << '\n';
            else cout << 3 << '\n';
        }
    }
    return 0;
}