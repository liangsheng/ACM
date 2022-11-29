#include <bits/stdc++.h>
using namespace std;

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    int n, ans, x;
    while (cin >> n) {
        ans = 0;
        for (int i = 1; i <= 4 * n - 1; i++) {
            cin >> x;
            ans ^= x;
        }
        cout << ans << '\n';
    }
    return 0;
}