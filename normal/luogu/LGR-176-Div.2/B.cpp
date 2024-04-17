#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T, n, m;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        vector<string> s(n);
        for (int i = 0; i < n; i++) cin >> s[i];
        vector<vector<int>> d(n + 1, vector<int>(m + 1, -1));
        vector<vector<int>> p = d;
        queue<pii> q;
        d[1][1] = 0, q.push({1, 1});
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};
        char ch[4] = {'R', 'L', 'D', 'U'};
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            for (int k = 0; k < 4; k++) {
                int u = x + dx[k], v = y + dy[k];
                if (u < 1 || u > n || v < 1 || v > m) continue;
                if (s[x - 1][y - 1] == s[u - 1][v - 1]) continue;
                if (d[u][v] != -1) continue;
                d[u][v] = d[x][y] + 1;
                p[u][v] = k;
                q.push({u, v});
            }
        }
        cout << d[n][m] << '\n';
        if (d[n][m] != -1) {
            string ans;
            int x = n, y = m;
            do {
                int id = p[x][y];
                ans.push_back(ch[id]);
                x += dx[id ^ 1], y += dy[id ^ 1];
            } while (p[x][y] != -1);
            reverse(ans.begin(), ans.end());
            cout << ans << '\n';
        }
    }
    return 0;
}