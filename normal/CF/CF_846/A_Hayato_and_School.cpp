#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T, n, x;
    cin >> T;
    while (T--) {
        cin >> n;
        vector<int> a, b;
        for (int i = 1; i <= n; i++) {
            cin >> x;
            if (x % 2 == 1) a.push_back(i);
            else b.push_back(i);
        }
        if (a.size() >= 3) {
            cout << "YES" << '\n';
            cout << a[0] << ' ' << a[1] << ' ' << a[2] << '\n';
        } else if (a.size() >= 1 && b.size() >= 2) {
            cout << "YES" << '\n';
            cout << a[0] << ' ' << b[0] << ' ' << b[1] << '\n';            
        } else {
            cout << "NO" << '\n';
        }
    }
    return 0;
}