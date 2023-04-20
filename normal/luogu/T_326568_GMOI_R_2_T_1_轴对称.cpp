#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, q;
    while (cin >> n >> m >> q) {
        vector<vector<vector<int>>> g(n, vector<vector<int>>(m, vector<int>(3, 0)));
        int x, y, t, c;
        set<pair<int, int>> s;
        while (q--) {
            cin >> x >> y >> t >> c;
            x--, y--, t--;
            g[x][y][t] += c;
            g[x][y][t] %= 256;
            int d = min(y, m - 1 - y);
            if (g[x][m - 1 - y] != g[x][y]) s.insert({x, min(y, d)});
            else if (s.count({x, d})) s.erase({x, d});
            cout << (s.empty() ? "Yes" : "No") << '\n';
        }
    }
    return 0;
}