#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
 
int main() {
    // 下面 2 句话是为了让 cin 更快，不理解可以先不写
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<LL> a(n + 1, 0);
    vector<int> b(m + 1, 0), sz(m + 1, 0);
    vector<vector<int>> g(n + 1);
    set<int> s;
    for (int i = 1; i <= m; i++) {
        cin >> b[i];
        if (s.count(b[i])) s.erase(b[i]);
        else s.insert(b[i]);
        sz[i] = s.size();
        g[b[i]].push_back(i);
    }

    vector<LL> f(m + 1, 0);
    for (int i = 1; i <= m; i++) f[i] = f[i - 1] + sz[i];

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < (int) g[i].size(); j += 2) {
            int l = g[i][j], r = m;
            if (j != g[i].size() - 1) r = g[i][j + 1] - 1;
            a[i] += f[r] - f[l - 1];
        }
    }
    for (int i = 1; i <= n; i++) cout << a[i] << " \n"[i == n];
    return 0;
}