#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, x, y;
    cin >> n;
    map<int, vector<int>> g;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    int ans = 1;
    queue<int> q;
    set<int> f;
    f.insert(1), q.push(1);
    while (!q.empty()) {
        x = q.front(), q.pop();
        // cout << "x= " << x << '\n';
        ans = max(ans, x);
        for (int v: g[x]) {
            if (f.count(v)) continue;
            f.insert(v);
            q.push(v);
        }
    }
    cout << ans << '\n';
    return 0;
}