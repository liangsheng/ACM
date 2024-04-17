#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N = 100005, M = 200005 * 2;
const LL INF = numeric_limits<LL>::max() / 2;

// 黑科技 2 倍空间: https://www.cnblogs.com/chy-2003/p/11815396.html
// 来自 jiangly: https://atcoder.jp/contests/abc343/submissions/50808003
template <typename Info>
struct SegmentTree {
    int n;
    vector<Info> info;
    SegmentTree(): n(0) {}

    // 初始化: 用单个初始值
    SegmentTree(int n_, Info v_ = Info()) {
        init(n_, v_);
    }

    // 初始化: 用单个初始值
    void init(int n_, Info v_ = Info()) {
        init(n_, vector(n_ + 1, v_));
    }

    // 初始化: 用数组初始化
    template<typename T>
    SegmentTree(int n_, vector<T> init_) {
        init(n_, init_);
    }

    inline int idx(int L, int R) { return L + R | L != R; }

    // 初始化: 用数组初始化
    template<typename T>
    void init(int n_, vector<T> init_) {
        // n = init_.size();
        // info.assign(4 << std::__lg(n), Info());
        n = n_;
        info.assign(2 * n + 1, Info());
        function<void(int, int)> build = [&](int s, int t) {
            if (s == t) {
                info[idx(s, t)] = init_[s];
                return ;
            }
            int mid = (s + t) / 2;
            build(s, mid);
            build(mid + 1, t);
            pull(idx(s, t), idx(s, mid), idx(mid + 1, t));
            // cout << "k= " << idx(s, t) << ", " << info[idx(s, t)].sum << '\n';
        };
        build(1, n);
    }

    void pull(int k, int l, int r) {
        info[k] = info[l] + info[r];
    }

    // 单点更新
    void update(int s, int t, int p, const Info& v) {
        if (s == t) {
            info[idx(s, t)] = v;
            return ;
        }
        int mid = (s + t) / 2;
        if (p <= mid) update(s, mid, p, v);
        else update(mid + 1, t, p, v);
        pull(idx(s, t), idx(s, mid), idx(mid + 1, t));
    }

    // 单点更新
    void update(int p, const Info& v) {
        update(1, n, p, v);
    }

    // 区间查询
    Info query(int s, int t, int l, int r) {
        if (t < l || s > r) return Info();
        if (s >= l && t <= r) return info[idx(s, t)];
        int mid = (s + t) / 2;
        return query(s, mid, l, r) + query(mid + 1, t, l, r);
    }

    // 区间查询
    Info query(int l, int r) {
        return query(1, n, l, r);
    }
};

struct Info {
    LL sum = 0;
    Info() {}
    Info(LL sum_): sum(sum_) {};
};

// 实现 2 个 Info 的合并, 用在 pull() 中
Info operator+(Info a, Info b) {
    return Info(a.sum + b.sum);
}

int main() {
    // 下面 2 句话是为了让 cin 更快，不理解可以先不写
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, c, l, r;
    cin >> n >> m;
    vector<LL> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    
    SegmentTree<Info> seg(n, a);
    while (m--) {
        cin >> c >> l >> r;
        if (c == 1) a[l] += r, seg.update(l, Info{a[l]});
        else cout << seg.query(l, r).sum << '\n';
    }
    return 0;
}