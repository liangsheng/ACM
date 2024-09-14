#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

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
        // iota(f.begin(), f.end(), 0);
        for (int i = 0; i <= n; i++) f[i] = i;

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

double kruskal(int n, int m, vector<tuple<double, int, int>>& p) {
    DSU dsu(n);
    sort(p.begin(), p.end());
    double ans = 0.0;
    int cnt = 0;
    for (int i = 0; i < m; i++) {
        auto [w, u, v] = p[i];
        if (dsu.same(u, v)) continue;
        int fa = dsu.merge(u, v);
        ans += w;
        if (++cnt == n - 1) break;
    }
    return ans;
}

int main() {
    // 下面 2 句话是为了让 cin 更快，不理解可以先不写
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> x(m), y(m), a(m), b(m);
    for (int i = 0; i < m; i++) cin >> x[i] >> y[i] >> a[i] >> b[i];

    double l = 0, r = 1e8, mid;
    for (int c = 0; c < 60; c++) {
        mid = (l + r) / 2;
        vector<tuple<double, int, int>> p(m);
        for (int i = 0; i < m; i++) {
            p[i] = {a[i] - mid * b[i], x[i], y[i]};
        }
        double ans = kruskal(n, m, p);
        if (ans < 0) r = mid;
        else l = mid;
    }
    cout << setprecision(2) << l << '\n';
    return 0;
}