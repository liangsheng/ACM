#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T, n;
    string a, b;
    cin >> T;
    while (T--) {
        cin >> n;
        cin >> a >> b;
        int x = 0, y = 0, z = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] == b[i]) x++;
            else y++;
        }
        if (x != n && y != n) {
            cout << "NO" << '\n';
            continue;
        }
        vector<pair<int, int>> ans;
        for (int i = 0; i < n; i++) if (a[i] == '0') ans.push_back({i + 1, i + 1}), z++;
        if ((x == n && z % 2 == 0) || (y == n && z % 2 == 1)) {
            ans.push_back({1, 1});
            ans.push_back({2, n});
        } else {
            ans.push_back({1, n});
        }
        cout << "YES" << '\n';
        cout << ans.size() << '\n';
        for (int i = 0; i < ans.size(); i++) cout << ans[i].first << ' ' << ans[i].second << '\n';
    }
    return 0;
}