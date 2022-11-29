#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int MOD = 1000000007;

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    int n, m, c, x;
    while (cin >> n) {
        vector<int> g[n];
        for (int i = 0; i < n; i++) {
            cin >> c;
            g[i].resize(c);
            for (int j = 0; j < c; j++) {
                cin >> x;
                g[i][j] = x;
            }
        }
        cin >> m;
        set<vector<int>> s;
        for (int i = 0; i < m; i++) {
            vector<int> tmp;
            for (int j = 0; j < n; j++) cin >> x, tmp.push_back(x - 1);
            s.insert(move(tmp));
        }
        priority_queue<pair<LL, vector<int>>> q;
        set<vector<int>> has;
        LL sum = 0, ans = 0;
        for (int i = 0; i < n; i++) sum += g[i][g[i].size() - 1];
        vector<int> f(n);
        for (int i = 0; i < n; i++) f[i] = g[i].size() - 1;
        q.push({sum, f}), has.insert(f);
        while (!q.empty()) {
            sum = q.top().first, f = q.top().second;
            q.pop(), has.erase(f);
            if (!s.count(f)) break;
            if (q.size() <= m * n) {
                for (int i = 0; i < n; i++) {
                    if (f[i] != 0) {
                        LL tmp = sum - g[i][f[i]] + g[i][f[i] - 1];
                        f[i]--;
                        if (!has.count(f)) q.push({tmp, f}), has.insert(f);
                        f[i]++;
                    } 
                }
            }
        }
        for (int i = 0; i < n - 1; i++) cout << f[i] + 1 << ' ';
        cout << f[n - 1] + 1 << '\n';
    }
}