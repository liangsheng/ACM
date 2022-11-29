#include <bits/stdc++.h>
using namespace std;

int T, n;

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> n;
        if (n % 2 == 0) cout << n / 2 << ' ' << n / 2 - 1 << ' ' << 1 << '\n';
        else {
            if ((n / 2 + 1) & 1) cout << n / 2 + 1 << ' ' << n / 2 - 1 << ' ' << 1 << '\n';
            else cout << n / 2 + 2 << ' ' << n / 2 - 2 << ' ' << 1 << '\n';
        }
    }
    return 0;
}