#include <bits/stdc++.h>
using namespace std;

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    int T, n, l, r;
    cin >> T;
    while (T--) {
        cin >> n >> l >> r;
        bool flag = 1;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++) {
            int d = l % i;
            if (d == 0) a[i] = l;
            else if (i - d + l <= r) a[i] = i - d + l;
            else {
                flag = 0;
                break;
            }
        }
        if (flag) {
            cout << "YES" << '\n';
            for (int i = 1; i < n; i++) cout << a[i] << ' ';
            cout << a[n] << '\n';
        } else cout << "NO" << '\n';
    }
    return 0;
}