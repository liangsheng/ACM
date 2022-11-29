#include <bits/stdc++.h>
using namespace std;

int T, c, d;

int gao() {
    // cout << "c= " << c << " d= " << d << ' ' << (c == d) << '\n';
    if (c == 0 && d == 0) return 0;
    if (c == d) return 1;
    if (abs(c - d) & 1) return -1;
    return 2;
}

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> c >> d;
        cout << gao() << '\n';
    }
    return 0;
}