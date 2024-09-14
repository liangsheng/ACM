#include <bits/stdc++.h>
#define repe(i, u) for (int i = head[u]; i != -1; i = nxt[i])
using namespace std;
typedef pair<int, int> pii;

const int N = 100005, M = 200005 * 2;
const int INF = numeric_limits<int>::max() / 2;

// 并查集(Union-Find Disjoint Sets/DSU)
// jiangly: https://www.cnblogs.com/WIDA/p/17633758.html#02---并查集dsu
// atcoder: https://github.com/atcoder/ac-library/blob/master/atcoder/dsu.hpp
struct DSU {
    int n;
    vector<int> f;

    DSU(int N): n(N) {
        // 将 f 的 size 设置为 n + 1
        f.resize(n + 1);
        for (int i = 0; i <= n; i++) f[i] = i;
    }

    // 递归写法, 更清晰, 建议使用
    int find(int x) {
        return f[x] == x ? f[x] : f[x] = find(f[x]);
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }

    // 合并 x, y, 返回合并后的根
    int merge(int x, int y) {
        x = find(x), y = find(y);
        return x == y ? x : f[y] = x;
    }
};

int main() {
    // 下面 2 句话是为了让 cin 更快，不理解可以先不写
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> u(m), v(m), w(m);
    for (int i = 0; i < m; i++) cin >> u[i] >> v[i] >> w[i];

    auto kruskal = [&]() {
        // 将边按边权从小到大排序
        vector<int> id(m);
        for (int i = 0; i < m; i++) id[i] = i;
        sort(id.begin(), id.end(), [&](const int& x, const int& y) {
            return w[x] < w[y];
        });

        DSU dsu(n);
        int ans = 0, cnt = 0;
        for (int i = 0; i < m; i++) {
            // 如果 u, v 不联通, 就添加边, 并且合并 u, v
            if (!dsu.same(u[id[i]], v[id[i]])) {
                ans += w[id[i]], cnt++;
                dsu.merge(u[id[i]], v[id[i]]);
            }

            // 只需要 n - 1 条边
            if (cnt == n - 1) break;
        }
        return cnt == n - 1 ? ans : -1;
    };

    int ans = kruskal();
    if (ans == -1) cout << "orz" << '\n';
    else cout << ans << '\n';
    return 0;
}