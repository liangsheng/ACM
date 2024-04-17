#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N = 100005, M = 200005 * 2;
const LL INF = numeric_limits<LL>::max() / 2;

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

    // 初始化: 用数组初始化
    template<typename T>
    void init(int n_, vector<T> init_) {
        // n = init_.size();
        // info.assign(4 << std::__lg(n), Info());
        n = n_;
        info.assign(4 * n, Info());
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

    void pull(int k) {
        info[k] = info[k << 1] + info[k << 1 | 1];
    }

    // 单点更新
    void update(int k, int s, int t, int p, const Info& v) {
        if (s == t) {
            info[k] = v;
            return ;
        }
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
        int mid = (s + t) / 2;
        return query(k << 1, s, mid, l, r) + query(k << 1 | 1, mid + 1, t, l, r);
    }

    // 区间查询
    Info query(int l, int r) {
        return query(1, 1, n, l, r);
    }
};

struct Info {
    int mx1 = -1;
    int cnt1 = 0;
    int mx2 = -2;
    int cnt2 = 0;
};

Info operator+(Info a, Info b) {
    if (a.mx1 == b.mx1) {
        if (a.mx2 < b.mx2) {
            std::swap(a, b);
        }
        a.cnt1 += b.cnt1;
        if (a.mx2 == b.mx2) {
            a.cnt2 += b.cnt2;
        }
        return a;
    }
    if (a.mx1 < b.mx1) {
        std::swap(a, b);
    }
    if (b.mx1 > a.mx2) {
        a.mx2 = b.mx1;
        a.cnt2 = b.cnt1;
    } else if (b.mx1 == a.mx2) {
        a.cnt2 += b.cnt1;
    }
    return a;
}

int main() {
    // 下面 2 句话是为了让 cin 更快，不理解可以先不写
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, p, x, l, r;
    cin >> n >> m;
    
    SegmentTree<Info> seg(n);
    for (int i = 1; i <= n; i++) {
        cin >> x;
        seg.update(i, Info{x, 1, -1, 0});
    }
    
    while (m--) {
        int o;
        cin >> o;
        
        if (o == 1) {
            cin >> p >> x;
            seg.update(p, Info{x, 1, -1, 0});
        } else {
            cin >> l >> r;
            cout << seg.query(l, r).cnt2 << "\n";
        }
    }
    return 0;
}