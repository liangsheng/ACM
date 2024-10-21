#include <bits/stdc++.h>
using namespace std;

// 并查集(Union-Find Disjoint Sets/DSU)
// jiangly: https://www.cnblogs.com/WIDA/p/17633758.html#02---并查集dsu
// atcoder: https://github.com/atcoder/ac-library/blob/master/atcoder/dsu.hpp
struct DSU {
    int n;
    vector<int> f, sz;
    vector<set<int>> d;

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
    
        for (int i = 0; i <= n; i++) {
            d.push_back({-i});
        }
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
        for (int u : d[y]) {
            d[x].insert(u);
            if (d[x].size() > 10) d[x].erase(--d[x].end());
        }
        sz[x] += sz[y], f[y] = x;
        return x;
    }

    // 返回 x 所在的集合的大小
    int size(int x) {
        return sz[find(x)];
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n, q, c, u, v, k;
    cin >> n >> q;
    DSU dsu(n);
    while (q--) {
        cin >> c;
        if (c == 1) {
            cin >> u >> v;
            dsu.merge(u, v);
        } else {
            cin >> v >> k;
            v = dsu.find(v);
            if (dsu.sz[v] < k) cout << -1 << '\n';
            else {
                auto it = dsu.d[v].begin();
                while (k > 1) it++, k--;
                cout << -(*it) << '\n';
            }
        }
    }
    return 0;
}