#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int r, b, c, d, e;
    while (cin >> r >> b >> c >> d >> e) {
        if (2 * e > c + d) {
            if (r < b) cout << 2 * r * e + (b - r) * d << '\n';
            else cout << 2 * b * e + (r - b) * c << '\n';
        } else {
            cout << r * c + b * d << '\n';
        }
    }
    return 0;
}