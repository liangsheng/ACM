#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int H, W;
    cin >> H >> W;
    vector g(H * W, 0);
    for (int i = 0; i < H; i++) for (int j = 0; j < W; j++) {
        cin >> g[i * W + j];
    }
    
    map<vector<int>, int> m;
    m[g] = 0;
    priority_queue<pair<int, vector<int>>> q;
    q.push({0, g});
    while (!q.empty()) {
        auto [d, g] = q.top();
        q.pop();
        d = -d;
        // int e = 0;
        // cout << "d= " << d << '\n';
        // for (int i = 0; i < H; i++) {
        //     for (int j = 0; j < W; j++) cout << g[e++] << ' ';
        //     cout << '\n';
        // }
        if (m[g] != d) continue;
        for (int i = 0; i < 2; i++) for (int j = 0; j < 2; j++) {
            vector<int> t = g;
            for (int x = 0; x < H - 1; x++) for (int y = 0; y < W - 1; y++) {
                int u = (x + i) * W + y + j;
                int v = (H - 2 - x + i) * W + W - 2 - y + j;
                t[u] = g[v];
            }
            // int e = 0;
            // for (int u= 0; u < H; u++) {
            //     for (int v = 0; v < W; v++) cout << t[e++] << ' ';
            //     cout << '\n';
            // }
            if (!m.count(t) || m[t] > d + 1) {
                m[t] = d + 1;
                if (d + 1 < 20) q.push({-(d + 1), t});
            }
        }
    }
    for (int i = 0; i < H * W; i++) g[i] = i + 1;
    if (!m.count(g)) cout << -1 << '\n';
    else cout << m[g] << '\n';
    return 0;
}