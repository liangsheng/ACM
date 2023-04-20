#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    LL L, n1, n2, v, l;
    while (cin >> L >> n1 >> n2) {
        map<int, vector<pair<LL, LL>>> q1, q2;
        LL now = 0;
        for (int i = 0; i < n1; i++) {
            cin >> v >> l;
            q1[v].push_back({now + 1, now + l});
            now += l;
        }
        now = 0;
        for (int i = 0; i < n2; i++) {
            cin >> v >> l;
            q2[v].push_back({now + 1, now + l});
            now += l;
        }

        LL ans = 0;
        for (auto it : q1) {
            v = it.first;
            vector<pair<LL, LL>> a = it.second;
            if (!q2.count(v)) continue;
            vector<pair<LL, LL>> b = q2[v];
            int j = 0;
            // cout << "v= " << v << '\n';
            for (int i = 0; i < a.size(); i++) {
                // cout << "i= " << i << ' ' << a[i].first << ' ' << a[i].second << '\n';
                while (b[j].second < a[i].first && j + 1 < b.size()) j++;
                if (b[j].second < a[i].first) break;
                if (b[j].first > a[i].second) continue;
                ans += min(a[i].second, b[j].second) - max(a[i].first, b[j].first) + 1;
                while (j + 1 < b.size() && b[j + 1].first <= a[i].second) {
                    j++;
                    ans += min(a[i].second, b[j].second) - max(a[i].first, b[j].first) + 1;
                    // cout << "j= " << j << ' ' << b[j].first << ' ' << b[j].second << ' ' << ans << '\n';
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}