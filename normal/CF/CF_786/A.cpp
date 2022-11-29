#include <bits/stdc++.h>
using namespace std;

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    int T, x, y;
    cin >> T;
    while (T--) {
        cin >> x >> y;
        if (x > y || y % x) {
            cout << "0 0" << '\n';
            continue;
        }
        if (x == y) {
            cout << "1 1" << '\n';
            continue;
        }
        cout << 1 << " " << y / x << '\n';
    }
    return 0;
}