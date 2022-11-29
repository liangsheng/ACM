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

        int sum = 0;
        for (int i = 1; i <= n; i++) sum += abs(a[i]);
        if (sum % 2) cout << "-1" << '\n';
        else {
            vector<pair<int, int>> ans;
            for (int i = 1; i <= n; i++) {
                int j = i;
                if (a[i] == 0) {
                    while (i + 1 <= n && a[i + 1] == 0) i++;
                    ans.push_back({j, i});
                    continue;
                }
                while (i + 1 <= n && a[i + 1] == 0) i++;
                i++;
                if (a[i] + a[j] == 0) {
                    ans.push_back({j, i - 1});
                    ans.push_back({i, i});
                } else if (j + 1 == i) {
                    ans.push_back({j, i});
                } else {
                    ans.push_back({j, i - 2});
                    ans.push_back({i - 1, i});
                }
            }
            cout << ans.size() << '\n';
            for (int i = 0; i < ans.size(); i++) {
                cout << ans[i].first << ' ' << ans[i].second << '\n';
            }
        }
    }
    return 0;
}