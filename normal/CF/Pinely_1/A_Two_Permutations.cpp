#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T, n, p, q;
    cin >> T;
    while (T--) {
        cin >> n >> p >> q;
        if (p + q >= n) {
            cout << (p == n && q == n ? "Yes" : "No") << '\n';
        } else {
            cout << (n - p - q > 1 ? "Yes" : "No") << '\n';
        }
    }
    return 0;
}