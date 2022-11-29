#include <bits/stdc++.h>
using namespace std;

const int N = 2005;

int n, m;
vector<int> g[N];
bool f[N];

void bfs(int p) {
    queue<int> q;
    q.push(p);
    f[p] = 1;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (auto y: g[x]) {
            if (f[y]) continue;
            f[y] = 1;
            q.push(y);
        }
    }
}

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    int x, y, ans;
    while (cin >> n >> m) {
        for (int i = 1; i <= n; i++) g[i].clear();
        for (int i = 1; i <= m; i++) {
            cin >> x >> y;
            g[x].push_back(y);
        }
        ans = 0;
        for (int i = 1; i <= n; i++) {
            memset(f, 0, sizeof(f));
            bfs(i);
            for (int j = 1; j <= n; j++) ans += f[j];
        }
        cout << ans << '\n';
    }
    return 0;
}