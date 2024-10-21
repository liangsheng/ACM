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
        else if (k == 1) cout << n - (n / 2 + 1) + 1 << '\n';
        else {
            i64 r = n / k;
            i64 l = n / (k + 1) + 1;
            // cout << l << ' ' << r << '\n';
            i64 u = n - k * l, v = n - k * r;
            cout << (u - v) / k + 1 << '\n';
            // set<i64> s;
            // for (i64 i = l; i <= r; i++) s.insert(n - k * i);
            // cout << s.size() << '\n'; 
        }
    }
    return 0;
}