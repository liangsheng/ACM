#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T, n, x;
    cin >> T;
    while (T--) {
        cin >> n;
        vector<int> a;
        for (int i = 1; i <= n; i++) {
            cin >> x;
            if (x == 2) a.push_back(i);
        }
        int m = a.size();
        if (m == 0) cout << 1 << '\n';
        else if (m % 2) cout << -1 << '\n';
        else cout << a[m / 2 - 1] << '\n';
    }
    return 0;
}