#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;

const int MOD = 998244353;

long long mypow(long long x, long long y, long long mod = MOD){
    long long res=1;
    while(y){
        if(y&1) {
            res = res * x % mod;
        }
        y >>= 1;
        x = x * x % mod;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int h, w;
    while (cin >> h >> w) {
        vector<string> g(h);
        for (int i = 0; i < h; i++) cin >> g[i];

        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};
        vector<vector<int>> f(h, vector<int>(w, -1));
        auto bfs = [&](int i, int j, int id) {
            f[i][j] = id;
            queue<pii> q;
            q.push({i, j});
            while (!q.empty()) {
                auto& [x, y] = q.front();
                q.pop();
                for (int k = 0; k < 4; k++) {
                    int u = x + dx[k], v = y + dy[k];
                    if (u < 0 || u >= h || v < 0 || v >= w) continue;
                    if (g[u][v] == '.' || f[u][v] != -1) continue;
                    f[u][v] = id;
                    q.push({u, v});
                }
            }
        };
        int cnt = 0;
        for (int i = 0; i < h; i++) for (int j = 0; j < w; j++) {
            if (g[i][j] == '#' && f[i][j] == -1) bfs(i, j, cnt++);
        }
        // cout << "cnt= " << cnt << '\n';
        // for (int i = 0; i < h; i++) {
        //     for (int j = 0; j < w; j++) cout << f[i][j] << ' ';
        //     cout << '\n';
        // }
        LL q = 0, p = 0;
        for (int i = 0; i < h; i++) for (int j = 0; j < w; j++) if (g[i][j] == '.') {
            set<int> s;
            for (int k = 0; k < 4; k++) {
                int u = i + dx[k], v = j + dy[k];
                if (u < 0 || u >= h || v < 0 || v >= w) continue;
                if (g[u][v] == '.') continue;
                s.insert(f[u][v]); 
            } 
            q++;
            if (s.size() == 0) p += cnt + 1;
            else if (s.size() == 1) p += cnt;
            else p += cnt - s.size() + 1;
            p = p % MOD;
            // cout << "i= " << i << ", j= " << j << " " << s.size() << '\n';
        }
        // cout << "p= " << p << ", q= " << q << '\n';
        if (q == 0) cout << 1 << '\n';
        else cout << p * mypow(q, MOD - 2) % MOD << '\n';
    }
    return 0;
}