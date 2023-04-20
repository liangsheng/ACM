#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T, n;
    cin >> T;
    while (T--) {
        cin >> n;
        vector<pair<int, int>> a(n + 1, {-1, -1});
        for (int i = 1; i <= n; i++) cin >> a[i].first >> a[i].second;
        sort(a.begin(), a.end());
        vector<int> R(n + 2, -1);
        for (int i = n; i >= 1; i--) R[i] = max(R[i + 1], a[i].second);
        // for (int i = 1; i <= n; i++) cout << R[i] << ' ';
        // cout << '\n';
        int ans = abs(a[n - 1].first - a[n].second), p = 1;
        set<int> s;
        for (int i = 1; i <= n; i++) {
            while (i + 1 <= n && a[i + 1].first == a[i].first) i++;
            for (; p < i; p++) s.insert(a[p].second);
            // first 有重复的情况
            if (a[i].first == a[i - 1].first) s.insert(a[i].second);
            if (R[i + 1] >= a[i].first) ans = min(ans, R[i + 1] - a[i].first);
            else if (!s.empty()) {
                // for (auto ii : s) cout << ii << ' ';
                // cout << '\n';
                auto it = s.lower_bound(a[i].first);
                if (it != s.end()) ans = min(ans, *it - a[i].first);//, cout << "b_*it= " << *it << '\n';
                if (it != s.begin()) {
                    it--;
                    ans = min(ans, a[i].first - max(*it, R[i + 1]));
                    // cout << "s_*it= " << *it << '\n';
                }
            }
            // cout << "i= " << i << ", ans= " << ans << '\n';
        }
        cout << ans << '\n';
    }
    return 0;
}