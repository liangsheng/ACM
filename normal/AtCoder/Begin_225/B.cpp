#include <bits/stdc++.h>
using namespace std;

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    int n, x, y;
    while (cin >> n) {
        vector<int> f(n + 1, 0);
        for (int i = 1; i < n; i++) {
            cin >> x >> y;
            f[x]++, f[y]++;
        }
        if (n == 3) {
            cout << "Yes" << '\n';
            continue;
        }
        int c1 = 0, c2 = 0;
        for (int i = 1; i <= n; i++) {
            if (f[i] == 1) c1++;
            if (f[i] == n - 1) c2++;
        }
        // cout << c1 << ' ' << c2 << '\n';
        if (c1 == n - 1 && c2 == 1) cout << "Yes" << '\n';
        else cout << "No" << '\n';
    }
    return 0;
}