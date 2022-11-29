#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T, n;
    cin >> T;
    while (T--) {
        cin >> n;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++) cin >> a[i];
        if (n % 2) cout << "-1" << '\n';
        else {
            vector<pair<int, int>> ans;
            for (int i = 1; i <= n; i += 2) {
                if (a[i] == a[i + 1]) ans.push_back({i, i + 1});
                else ans.push_back({i, i}), ans.push_back({i + 1, i + 1});
            }
            cout << ans.size() << '\n';
            for (int i = 0; i < ans.size(); i++) {
                cout << ans[i].first << ' ' << ans[i].second << '\n';
            }
        }
    }
    return 0;
}