#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T, n, k, x;
    cin >> T;
    while (T--) {
        cin >> n >> k;
        LL m = 1;
        for (int i = 0; i < n; i++) {
            cin >> x;
            m *= x;
        }
        if (2023 % m) cout << "NO" << '\n';
        else {
            cout << "YES" << '\n';
            for (int i = 1; i < k; i++) cout << "1 ";
            cout << 2023 / m << '\n';
        }
    }
    return 0;
}