#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int n, m, x, y;
vector<vector<int>> g;
vector<int> c;

void gao() {
    queue<int> q;
    for (int i = 1; i <= n; i++) if (c[i] == 0) q.push(i);
    vector<int> ans;
    for (int k = 0; k < n; k++) {
        if (q.size() > 1) {
            cout << "No" << '\n';
            return ;
        }
        queue<int> t;
        x = q.front(), q.pop();
        ans.push_back(x);
        for (int v : g[x]) if (--c[v] == 0) t.push(v);
        q = t;
    }
    cout << "Yes" << '\n';
    vector<int> res(n);
    for (int i = 0; i < n; i++) res[ans[i] - 1] = i + 1;
    for (int i = 0; i < n - 1; i++) cout << res[i] << ' ';
    cout << res[n - 1] << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    while (cin >> n >> m) {
        g = vector<vector<int>>(n + 1, vector<int>());
        c = vector<int>(n + 1, 0);
        for (int i = 1; i <= m; i++) {
            cin >> x >> y;
            g[x].push_back(y);
            c[y]++;
        }
        gao();
    }
    return 0;
}