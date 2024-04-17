#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

const int N = 10005, K = 105, INF = 2139062143;

// dp(i, j): 在 %k=j 时刻到达 i 点的最短时间
int d[N][K];
vector<pii> g[N];

int main() {
    // 下面 2 句话是为了让 cin 更快，不理解可以先不写
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k, x, y, z;
    cin >> n >> m >> k;
    // vector<vector<pair<int, int>>> g(n + 1, vector<pair<int, int>>());
    for (int i = 1; i <= m; i++) {
        cin >> x >> y >> z;
        g[x].push_back({y, z});
    }

    
    memset(d, 127, sizeof(d));  // 相当于把 dp 数组初始化成正无穷

    // 每次找最小的, 所以插入 q 的时候用负数
    priority_queue<tuple<int, int, int>> q;
    d[1][0] = 0, q.push({-d[1][0], 1, 0});
    while (!q.empty()) {
        auto [w, u, c] = q.top();
        q.pop();

        w = -w;
        if (d[u][c] != w) continue;
        for (auto& [v, t] : g[u]) {
            int tmp = w + 1;
            if (w < t) tmp = w + (t - w + k - 1) / k * k + 1;
            z = tmp % k;
            if (tmp < d[v][z]) q.push({-(d[v][z] = tmp), v, z});
        }
    }
    if (d[n][0] == INF) cout << -1 << '\n';
    else cout << d[n][0] << '\n';
    return 0;
}