#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    LL T, n, k, s;
    cin >> T;
    while (T--) {
        cin >> n >> k >> s;
        if (k < 1 || k > n) cout << "No" << '\n';
        else {
            LL l = (1 + k) * k / 2, r = (n - k + 1 + n) * k / 2;
            if (s >= l && s <= r) cout << "Yes" << '\n';
            else cout << "No" << '\n';
        }
    }
    return 0;
}

