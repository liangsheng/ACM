#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

/*
 * loj132: https://loj.ac/p/132
 * 区间更新, 区间求和, 分块
 */

template <typename T, typename Info, typename Tag>
struct Block {
    int n, m, d;        // [0, ..., n - 1], d = sqrt(n), m = (n + d - 1) / d;
    vector<int> id;     // 块号, 
    vector<T> a;        // 原序列维护的信息
    vector<Info> info;  // 区间维护的信息
    vector<Tag> tag;    // 区间要更新的信息

    Block(int n_, vector<T>& a_) {
        // 计算块大小
        n = n_, d = sqrt(n), m = (n + d - 1) / 2;
        
        // 分配块号, 从 0 到 n - 1
        id.assign(n, -1);
        for (int i = 0; i < n; i++) id[i] = i / d;

        // 计算区间维护信息 
        a = move(a_);
        info.assign(m, Info());
        tag.assign(m, Tag());
        for (int i = 0; i < n; i++) info[id[i]].apply(Tag(a[i].x));
        // for (int i = 0; i < n; i++) cout << a[i].x << " \n"[i == n - 1];
        // for (int i = 0; i < m; i++) cout << info[i].sum << " \n"[i == m - 1];
    }

    void apply(int p, const Tag& v, bool is_point) {
        if (is_point) info[id[p]].apply(v), a[p].apply(v);  // 单点更新
        else info[p].apply(v), tag[p].apply(v);             // 区间更新
    }

    // 区间更新, [l..r] += v
    void update(int l, int r, const Tag& v) {
        if (id[l] == id[r]) {
            for (int i = l; i <= r; i++) apply(i, v, true);
        } else {
            for (int i = l; id[i] == id[l]; i++) apply(i, v, true);
            for (int i = r; id[i] == id[r]; i--) apply(i, v, true);
            for (int i = id[l] + 1; i < id[r]; i++) apply(i, v, false);
        }
        for (int i = 0; i < n; i++) cout << a[i].x << " \n"[i == n - 1];
        for (int i = 0; i < m; i++) cout << info[i].sum << " \n"[i == m - 1];
        for (int i = 0; i < m; i++) cout << tag[i].add << " \n"[i == m - 1];
    }

    // 区间查询
    Info query(int l, int r) {
        Info ans;
        if (id[l] == id[r]) {
            for (int i = l; i <= r; i++) ans = ans + a[i].get(tag[id[i]]);
        } else {
            for (int i = l; id[i] == id[l]; i++) ans = ans + a[i].get(tag[id[i]]);
            for (int i = r; id[i] == id[r]; i--) ans = ans + a[i].get(tag[id[i]]);
            for (int i = id[l] + 1; i < id[r]; i++) ans = ans + info[id[i]];
        }
        return ans;
    }
};

// 区间都要加上的信息
struct Tag {
    LL add = 0;
    Tag() { add = 0; }
    Tag(LL add_): add(add_) {}

    // 用 t 更新区间的 tag
    void apply(const Tag& t) {
        add += t.add;
    }
};

// 区间里维护的信息
struct Info {
    LL sum = 0;
    Info() { sum = 0; }
    Info(LL sum_): sum(sum_) {}

    // 用 t 更新区间
    void apply(const Tag& t, int l, int r) {
        sum += (r - l + 1) * t.add;
    }

    // 用 a[l, r) 来更新区间信息
    void apply(const vector<T>& a, int l, int r) {
        for (int i = l; i < r; i++)
    }

    // 两个区间合并时维护的信息
    Info operator +(const Info& t) {
        return Info(sum + t.sum);
    }
};

// 单个信息
struct T {
    LL x = 0;
    T() { x = 0; }
    T(LL x_): x(x_) {}

    // 用 t 更新单点
    void apply(const Tag& t) {
        x += t.add;
    }

    // 将 t 作用在 v 后得到的 info
    Info get(const Tag& t) {
        return Info(x + t.add);
    }
};

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);

    int n, m, opt, l, r, c;
    cin >> n >> m;
    vector<T> a(n);
    for (int i = 0; i < n; i++) cin >> a[i].x;

    Block<T, Info, Tag> block(n, a);
    for (int t = 0; t < m; t++) {
        cin >> opt >> l >> r;
        l--, r--;  // 从 0 开始编号, 左闭右闭 [l, r]
        if (opt == 1) {
            cin >> c;
            block.update(l, r, Tag(c));
        } else {
            Info ans = block.query(l, r);
            cout << ans.sum << '\n';
        }
    }
    return 0;
}