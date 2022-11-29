#include <bits/stdc++.h>
using namespace std;

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    int n, m;
    while (cin >> n >> m) {
        vector<pair<int, int>> a(n), b(m);
        for (int i = 0; i < n; i++) cin >> a[i].first;
        for (int i = 0; i < n; i++) cin >> a[i].second;
        for (int i = 0; i < m; i++) cin >> b[i].first;
        for (int i = 0; i < m; i++) cin >> b[i].second;
        auto cmp = [](const pair<int, int>& x, const pair<int, int>& y) {
            if (x.first != y.first) return x.first > y.first;
            return x.second > y.second;
        };
        sort(a.begin(), a.end(), cmp);
        sort(b.begin(), b.end(), cmp);
        int p = -1, flag = 1;
        multiset<int> s;
        for (int i = 0; i < n; i++) {
            while (p + 1 < m && b[p + 1].first >= a[i].first) {
                s.insert(b[p + 1].second);
                p++;
            }
            // cout << "i= " << i << " " << a[i].first << ' ' << a[i].second << '\n';
            // for (auto ii : s) cout << ii << ' ';
            // cout << '\n';
            auto it = s.lower_bound(a[i].second);
            if (it == s.end()) {
                flag = 0;
                break;
            }
            s.erase(it);
        }
        if (flag) cout << "Yes" << '\n';
        else cout << "No" << '\n';
    }
    return 0;
}