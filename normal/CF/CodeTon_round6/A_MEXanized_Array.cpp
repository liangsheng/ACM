#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T, n, k, x;
    cin >> T;
    while (T--) {
        cin >> n >> k >> x;
        if (n < k || x < k - 1) {
            cout << -1 << '\n';
            continue;
        }
        cout << k * (k - 1) / 2 + (n - k) * (x - (x == k)) << '\n';
    }
    return 0;
}