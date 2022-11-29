#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T, n;
    string s;
    cin >> T;
    while (T--) {
        cin >> n;
        vector<vector<int>> g(n + 1, vector<int>());
        vector<int> cnt(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            cin >> s;
            for (int j = 1; j <= n; j++) if (s[j - 1] == '1') g[i].push_back(j), cnt[j]++;
        }
        int now = 1;
        queue<int> q;
        vector<set<int>> ans(n + 1, set<int>());
        for (int i = 1; i <= n; i++) if (cnt[i] == 0) q.push(i);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            ans[u].insert(now++);
            for (int v: g[u]) {
                for (int x : ans[u]) ans[v].insert(x);
                if (--cnt[v] == 0) q.push(v);
            }
        }
        for (int i = 1; i <= n; i++) {
            cout << ans[i].size();
            for (int x : ans[i]) cout << ' ' << x;
            cout << '\n';
        }
    }
    return 0;
}