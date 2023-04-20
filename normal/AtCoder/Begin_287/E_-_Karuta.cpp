#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    while (cin >> n) {
        vector<pair<string, int>> a;
        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            a.push_back({s, i});
        }
        sort(a.begin(), a.end());
        // cout << a[0].first << '\n';
        vector<int> h(n + 2, -1);
        h[1] = 0, h[n + 1] = 0;
        for (int i = 2; i <= n; i++) {
            int d = min(a[i - 2].first.size(), a[i - 1].first.size());
            for (int j = 0; j < d; j++) {
                if (a[i - 2].first[j] != a[i - 1].first[j]) {
                    h[i] = j;
                    // cout << "i= " << i << ' ' << h[i] << '\n';
                    break;
                }
            }
            if (h[i] == -1) h[i] = d;
        }
        vector<int> ans(n, 0);
        for (int i = 0; i < n; i++) ans[a[i].second] = max(h[i + 1], h[i + 2]);
        for (int i = 0; i < n; i++) cout << ans[i] << '\n';
    }
    return 0;
}