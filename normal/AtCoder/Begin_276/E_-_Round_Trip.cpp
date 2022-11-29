#include <bits/stdc++.h>
using namespace std;

int h, w, sx, sy;
vector<string> g;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

vector<vector<bool>> bfs(int i, int j) {
    vector<vector<bool>> f(h, vector<bool>(w, 0));
    queue<pair<int, int>> q;
    q.push({i, j});
    f[i][j] = 1;
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for (int k = 0; k < 4; k++) {
            int u = x + dx[k], v = y + dy[k];
            if (u < 0 || u >= h || v < 0 || v >= w || g[u][v] == '#' || f[u][v]) continue;
            f[u][v] = 1;
            q.push({u, v});
        }
    }
    return f;
}

bool gao() {
    for (int i = 0; i < 4; i++) {
        int x = sx + dx[i], y = sy + dy[i];
        if (x < 0 || x >= h || y < 0 || y >= w || g[x][y] == '#') continue;
        g[x][y] = '#';
        vector<vector<bool>> f = bfs(sx, sy);
        for (int j = 0; j < 4; j++) {
            int u = x + dx[j], v = y + dy[j];
            if (u < 0 || u >= h || v < 0 || v >= w || g[u][v] == '#') continue;
            if (u == sx && v == sy) continue;
            if (f[u][v]) return 1;
        } 
        g[x][y] = '.';    
    }
    return 0;
}

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    // multiset<int> a;
    // a.insert(2);
    // a.insert(2);
    // cout << a.size() << '\n';
    // a.erase(a.find(2));
    // cout << a.size() << '\n';
    while (cin >> h >> w) {
        g = vector<string>(h);
        // cout << "h= " << h << ", w= " << w << '\n';
        for (int i = 0; i < h; i++) {
            cin >> g[i];
            for (int j = 0; j < w; j++) if (g[i][j] == 'S') sx = i, sy = j;
        }
        // cout << "Hello World" << '\n';
        if (gao()) cout << "Yes" << '\n';
        else cout << "No" << '\n';
    }
    return 0;
}