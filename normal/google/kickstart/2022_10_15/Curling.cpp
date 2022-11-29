#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T, n, m, rs, rh, x, y;
    cin >> T;
    for (int cas = 1; cas <= T; cas++) {
        cin >> rs >> rh;
        cin >> n;
        vector<pii> a;
        int d = (rs + rh) * (rs + rh);
        for (int i = 0; i < n; i++) {
            cin >> x >> y;
            int t = x * x + y * y;
            if (t <= d) a.push_back({t, 0});
        }
        cin >> m;
        for (int i = 0; i < m; i++) {
            cin >> x >> y;
            int t = x * x + y * y;
            if (t <= d) a.push_back({t, 1});
        }
        sort(a.begin(), a.end());
        cout << "Case #" << cas << ": ";
        if (a.size() == 0) {
            cout << "0 0" << '\n';
            continue;
        }
        int res = a.size();
        for (int i = 1; i < a.size(); i++) if (a[i].second != a[i - 1].second) {
            res = i;
            break;
        }
        if (a[0].second == 0) cout << res << " 0" << "\n";
        else cout << "0 " << res << "\n";
    }
    return 0;
}