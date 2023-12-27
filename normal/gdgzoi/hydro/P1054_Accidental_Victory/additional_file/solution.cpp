#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long LL;

int main() {
    // 这两句话是为了让 cin 和 cout 操作更快
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T, n;
    cin >> T;
    while (T--) {
        cin >> n;
        vector<pii> a(n);
        map<int, LL> q;
        for (int i = 0; i < n; i++) {
            cin >> a[i].first;
            a[i].second = i + 1;
            q[a[i].first] += a[i].first;
        }

        sort(a.begin(), a.end());
        map<int, LL> m;
        LL now = 0;
        for (auto it : q) {
            now += q[it.first];
            m[it.first] = now;
        }
        vector<int> ans;
        ans.push_back(a[n - 1].second);
        for (int i = n - 2; i >= 0; i--) {
            if (m[a[i].first] >= a[i + 1].first) ans.push_back(a[i].second);
            else break;
        }
        sort(ans.begin(), ans.end());
        cout << ans.size() << '\n';
        for (int i = 0; i < (int) ans.size(); i++) {
            cout << ans[i] << " \n"[i == ans.size() - 1];
        }
    }
    return 0;
}