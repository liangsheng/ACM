#include <bits/stdc++.h>
using namespace std;

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    int T, n, m, k, x, y, cas = 0;
    cin >> T;
    while (T--) {
        cin >> n >> m >> k;
        set<int> s;
        for (int i = 0; i < m; i++) {
            cin >> x >> y;
            s.insert(y);
        }
        cout << "Case #" << ++cas << ": " << s.size() << '\n';
    }
    return 0;
}