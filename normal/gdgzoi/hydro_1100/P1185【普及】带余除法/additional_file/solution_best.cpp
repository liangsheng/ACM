#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    i64 T, n, k;
    cin >> T;
    while (T--) {
        cin >> n >> k;
        if (k == 0) cout << 1 << '\n';
        else {
            cout << (n / k) - (n / (k + 1)) << '\n';
        }
    }
    return 0;
}