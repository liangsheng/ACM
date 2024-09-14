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
    // 下面 2 句话是为了让 cin 更快，不理解可以先不写
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x, y, w;
    while (cin >> n) {
        vector<tuple<int, int, int>> a(n - 1);
        for (int i = 0; i < n - 1; i++) {
            cin >> x >> y >> w;
            a[i] = {-w, x, y};
        } 
        
        DSU dsu(n);
        sort(a.begin(), a.end());
        vector<LL> b(n + 1, 0);
        for (int i = 0; i < n - 1; i++) {
            auto [w, x, y] = a[i];
            w = -w;
            int fx = dsu.find(x), fy = dsu.find(y);
            int sx = dsu.size(x), sy = dsu.size(y);
            LL tmp = max(b[fx] + (LL) w * sy, b[fy] + (LL) w * sx);
            int f = dsu.merge(x, y);
            b[f] = tmp;
        }
        cout << *max_element(b.begin(), b.end()) << '\n';
    }
    return 0;
}