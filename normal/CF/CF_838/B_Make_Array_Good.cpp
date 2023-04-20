#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T, n;
    cin >> T;
    while (T--) {
        cin >> n;
        vector<pair<int, int>> a(n);
        for (int i = 0; i < n; i++) cin >> a[i].first, a[i].second = i;
        sort(a.begin(), a.end());
        vector<pair<int, int>> ans;
        for (int i = 1; i < n; i++) {
            if (a[i].first == a[i - 1].first) continue;
            if (a[i].first < a[i - 1].first) {
                ans.push_back({a[i].second + 1, a[i - 1].first - a[i].first});
                a[i].first = a[i - 1].first;
            } else {
                int d = a[i].first % a[i - 1].first;
                if (d != 0) {
                    d = a[i - 1].first - d;
                    ans.push_back({a[i].second + 1, d});
                    a[i].first += d;
                }
            }
        }
        cout << ans.size() << '\n';
        sort(ans.begin(), ans.end());
        for (int i = 0; i < ans.size(); i++) cout << ans[i].first << ' ' << ans[i].second << '\n';
    }
    return 0;
}