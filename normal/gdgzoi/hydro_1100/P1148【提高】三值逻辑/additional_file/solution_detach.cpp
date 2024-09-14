#include <bits/stdc++.h>
#define repe(i, u) for (int i = head[u]; i != -1; i = nxt[i])
using namespace std;

const int N = 200005;

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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int c, t, n, m, x, y;
    string s;
    cin >> c >> t;
    while (t--) {
        cin >> n >> m;
        int T = 2 * n + 1, F = 2 * n + 2, U = 2 * n + 3;
        vector<int> from(n + 1);
        for (int i = 1; i <= n; i++) from[i] = i;  // i 的最终值来自 from[i] 的原值
        for (int i = 1; i <= m; i++) {
            cin >> s;
            if (s == "+") {
                cin >> x >> y;
                from[x] = from[y];
            } else if (s == "-") {
                cin >> x >> y;
                from[x] = -from[y];
            } else if (s == "T") {
                cin >> x;
                from[x] = T;
            } else if (s == "F") {
                cin >> x;
                from[x] = F;
            } else if (s == "U") {
                cin >> x;
                from[x] = U;
            }
        }

        DSU dsu(2 * n + 3);
        for (int i = 1; i <= n; i++) {
            if (from[i] == i || abs(from[i]) == T || abs(from[i]) == F) continue;
            if (abs(from[i]) == U || from[i] == -i) dsu.merge(i, i + n);
            else {
                int j = abs(from[i]);
                if (from[i] > 0) dsu.merge(i, j), dsu.merge(i + n, j + n);
                else dsu.merge(i, j + n), dsu.merge(i + n, j);
            }
        }
        // for (int i = 1; i <= 2 * n; i++) {
        //     cout << "i= " << i << ", fi= " << find(i) << '\n';
        // }
        int ans = 0;
        for (int i = 1; i <= n; i++) ans += (dsu.find(i) == dsu.find(i + n));
        cout << ans << '\n';
    }
    return 0; 
}