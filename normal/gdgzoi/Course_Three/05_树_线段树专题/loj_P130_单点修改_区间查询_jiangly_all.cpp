#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N = 100005, M = 200005 * 2;
const LL INF = numeric_limits<LL>::max() / 2;

// 黑科技 2 倍空间: https://www.cnblogs.com/chy-2003/p/11815396.html
// 来自 jiangly: https://atcoder.jp/contests/abc265/submissions/34253107
template <typename Info, typename Tag>
struct LazySegmentTree {
    int n;
    vector<Info> info;  // 节点维护的信息
    vector<Tag> tag;    // 节点的懒惰标记

    // 初始化: 用单个初始值
    LazySegmentTree(int n_, Info v_ = Info()) {
        init(n_, v_);
    }

    // 初始化: 用单个初始值
    void init(int n_, Info v_ = Info()) {
        init(n_, vector(n_ + 1, v_));
    }

    // 初始化: 用数组初始化
    template<typename T>
    LazySegmentTree(int n_, vector<T> init_) {
        init(n_, init_);
    }

    // 初始化: 用数组初始化
    template<typename T>
    void init(int n_, vector<T> init_) {
        n = n_;
        // info.assign(4 << std::__lg(n), Info());
        // tag.assign(4 << std::__lg(n), Tag());
        info.assign(4 * n, Info());
        tag.assign(4 * n, Tag());
        function<void(int, int, int)> build = [&](int k, int s, int t) {
            if (s == t) {
                info[k] = init_[s];
                return ;
            }
            int mid = (s + t) / 2;
            build(k << 1, s, mid);
            build(k << 1 | 1, mid + 1, t);
            pull(k);
        };
        build(1, 1, n);
    }

    // 向上更新
    void pull(int k) {
        info[k] = info[k << 1] + info[k << 1 | 1];
    }

    // 用 tag 更新当前节点
    void apply(int k, const Tag& v) {
        info[k].apply(v);
        tag[k].apply(v);
    }

    // 向下更新
    void push(int k) {
        apply(k << 1, tag[k]);
        apply(k << 1 | 1, tag[k]);
        tag[k] = Tag();
    }

    // 单点更新
    void update(int k, int s, int t, int p, const Info& v) {
        if (s == t) {
            info[k] = v;
            return ;
        }
        push(k);
        int mid = (s + t) / 2;
        if (p <= mid) update(k << 1, s, mid, p, v);
        else update(k << 1 | 1, mid + 1, t, p, v);
        pull(k);
    }

    // 单点更新
    void update(int p, const Info& v) {
        update(1, 1, n, p, v);
    }

    // 区间查询
    Info query(int k, int s, int t, int l, int r) {
        if (t < l || s > r) return Info();
        if (s >= l && t <= r) return info[k];
        push(k);
        int mid = (s + t) / 2;
        return query(k << 1, s, mid, l, r) + query(k << 1 | 1, mid + 1, t, l, r);
    }

    // 区间查询
    Info query(int l, int r) {
        return query(1, 1, n, l, r);
    }

    // 区间更新
    void update(int k, int s, int t, int l, int r, const Tag& v) {
        if (s > r || t < l) return ;
        if (s >= l && t <= r) {
            apply(k, v);
            return ;
        }
        push(k);
        int mid = (s + t) / 2;
        update(k << 1, s, mid, l, r, v);
        update(k << 1 | 1, mid + 1, t, l, r, v);
        pull(k);
    }

    // 区间更新
    void update(int l, int r, const Tag& v) {
        update(1, 1, n, l, r, v);
    }

    void print(int k, int s, int t, int d = 0) {
        int mid = (s + t) / 2;
        if (s != t) print(k << 1, s, mid, d + 1);
        for (int i = 0; i < d; ++i) cout << '\t';
        cout << info[k].num << ":" << info[k].sum << '\n';
        if (s != t) print(k << 1 | 1, mid + 1, t, d + 1);      
    }

    void print(int k) {
        print(1, 1, n, 0);
    }
};

// 节点要下放的标记
struct Tag {
    LL add = 0;

    void apply(const Tag& t) {
        add += t.add;
    }
};

// 节点维护的信息
struct Info {
    int num = 0;
    LL sum = 0;
    Info() {}
    Info(int num_, LL sum_): num(num_), sum(sum_) {}

    void apply(const Tag& t) {
        sum += num * t.add;
    }
};

Info operator+(const Info& a, const Info& b) {
    return Info(a.num + b.num, a.sum + b.sum);
}

int main() {
    // 下面 2 句话是为了让 cin 更快，不理解可以先不写
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, c, l, r;
    cin >> n >> m;
    vector<Info> a(n + 1, Info(1, 0));
    for (int i = 1; i <= n; i++) cin >> a[i].sum;
    LazySegmentTree<Info, Tag> seg(n, a);

    while (m--) {
        cin >> c >> l >> r;
        if (c == 1) a[l].sum += r, seg.update(l, a[l]);
        else cout << seg.query(l, r).sum << '\n';
    }
    return 0;
}