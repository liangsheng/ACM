#include <bits/stdc++.h>
using namespace std;

// (1 + 2n) * n
// (s + s + n - 1) * n / 2 = (1 + 2n) * n
// s = 3 * (n + 1) / 2
// 10 5
// 12 4
// 14 3
// 16 2
// 18 1
// 11 9
// 13 8
// 15 7
// 17 6

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T, n;
    cin >> T;
    while (T--) {
        cin >> n;
        if (n % 2 == 0) cout << "No" << '\n';
        else {
            cout << "Yes" << '\n';
            int x = (n + 1) / 2, y = n + 1;
            for (int i = x; i >= 1; i--, y += 2) cout << i << ' ' << y << '\n';
            for (int i = n, y = n + 2; i > x; i--, y += 2) cout << i << ' ' << y << '\n';
        }
    }
    return 0;
}