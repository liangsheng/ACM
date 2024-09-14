#include <bits/stdc++.h>
#define repe(i, u) for (int i = head[u]; i != -1; i = nxt[i])
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;

const int N = 505, M = 200005 * 2;
const int INF = numeric_limits<int>::max() / 2;

// 并查集(Union-Find Disjoint Sets/DSU)
// jiangly: https://www.cnblogs.com/WIDA/p/17633758.html#02---并查集dsu
// atcoder: https://github.com/atcoder/ac-library/blob/master/atcoder/dsu.hpp
struct DSU {
    int n;
    vector<int> f, sz;

    DSU(int N): n(N) {
        // 将 f 的 size 设置为 n + 1
        f.resize(n + 1);

        // 相当于 for (int i = 0; i <= n; i++) f[i] = i;
        // 将从 0 开始的一段连续的数赋值给 f.begin() 到 f.end()
        iota(f.begin(), f.end(), 0);

        // 将 sz 的 size 设置为 n + 1, 并初始化为 1
        sz.assign(n + 1, 1);

        // 对于 vector 的初始化
        // 如果只需要设置 size, 不需要设置初值, 用 resize
        // 如果既需要设置 size, 也需要设置初值, 用 assign
    }

    // 递归写法, 更清晰, 建议使用
    int find(int x) {
        return f[x] == x ? f[x] : f[x] = find(f[x]);
    }

    // 非递归写法, 会慢一点, 建议用递归写法
    // int find(int x) {
    //     while (x != f[x]) x = f[x] = f[f[x]];
    //     return x;
    // }

    // 判断 x, y 是否在同一集合
    bool same(int x, int y) {
        return find(x) == find(y);
    }

    // 合并 x, y, 返回合并后的根
    int merge(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return x;
        // 将 sz小的 合并到 sz大的
        if (sz[x] < sz[y]) swap(x, y);
        sz[x] += sz[y], f[y] = x;
        return x;
    }

    // 返回 x 所在的集合的大小
    int size(int x) {
        return sz[find(x)];
    }
};

int g[N][N];

int main() {
    // 下面 2 句话是为了让 cin 更快，不理解可以先不写
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    int dx[2] = {0, 1}, dy[2] = {1, 0};
    vector<tuple<int, int, int>> p;
    cin >> n;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) cin >> g[i][j];
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) for (int k = 0; k < 2; k++) {
        int x = i + dx[k], y = j + dy[k];
        if (x > n || y > n) continue;
        int u = (i - 1) * n + j, v = (x - 1) * n + y, w = abs(g[i][j] - g[x][y]);
        p.push_back({w, u, v});
    }
    int m = p.size();
    DSU dsu(n * n);
    sort(p.begin(), p.end());
    int ans = INF;
    for (int i = 0; i < m; i++) {
        auto [w, u, v] = p[i];
        if (dsu.same(u, v)) continue;
        int fa = dsu.merge(u, v);
        if (dsu.size(fa) * 2 >= n * n) {
            ans = w;
            break;
        }
    }
    cout << ans << '\n';
    return 0;
}