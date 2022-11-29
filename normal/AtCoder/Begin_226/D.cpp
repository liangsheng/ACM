#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    int n;
    while (cin >> n) {
        vector<int> x(n, 0), y(n, 0);
        for (int i = 0; i < n; i++) cin >> x[i] >> y[i];
        set<pair<int, int>> ans;
        for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
            if (i == j) continue;
            int u = x[i] - x[j], v = y[i] - y[j], d = __gcd(u, v);
            u /= d, v /= d;
            ans.insert(make_pair(u, v));
        }
        cout << ans.size() * 2 << '\n';
    }
    return 0;
}