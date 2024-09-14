#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
typedef long long LL;

// 来自 jiangly: https://ac.nowcoder.com/acm/contest/view-submission?submissionId=63433564

template<class T>
constexpr T power(T a, i64 b) {
    T res = 1;
    for (; b; b /= 2, a *= a) {
        if (b % 2) {
            res *= a;
        }
    }
    return res;
}

constexpr i64 mul(i64 a, i64 b, i64 p) {
    i64 res = a * b - i64(1.L * a * b / p) * p;
    res %= p;
    if (res < 0) {
        res += p;
    }
    return res;
}

template<int P>
struct MInt {
    int x;
    constexpr MInt() : x{} {}
    constexpr MInt(i64 x) : x{norm(x % P)} {}
    
    constexpr int norm(int x) const {
        if (x < 0) {
            x += P;
        }
        if (x >= P) {
            x -= P;
        }
        return x;
    }
    constexpr int val() const {
        return x;
    }
    explicit constexpr operator int() const {
        return x;
    }
    constexpr MInt operator-() const {
        MInt res;
        res.x = norm(P - x);
        return res;
    }
    constexpr MInt inv() const {
        assert(x != 0);
        return power(*this, P - 2);
    }
    constexpr MInt &operator*=(MInt rhs) {
        x = 1LL * x * rhs.x % P;
        return *this;
    }
    constexpr MInt &operator+=(MInt rhs) {
        x = norm(x + rhs.x);
        return *this;
    }
    constexpr MInt &operator-=(MInt rhs) {
        x = norm(x - rhs.x);
        return *this;
    }
    constexpr MInt &operator/=(MInt rhs) {
        return *this *= rhs.inv();
    }
    friend constexpr MInt operator*(MInt lhs, MInt rhs) {
        MInt res = lhs;
        res *= rhs;
        return res;
    }
    friend constexpr MInt operator+(MInt lhs, MInt rhs) {
        MInt res = lhs;
        res += rhs;
        return res;
    }
    friend constexpr MInt operator-(MInt lhs, MInt rhs) {
        MInt res = lhs;
        res -= rhs;
        return res;
    }
    friend constexpr MInt operator/(MInt lhs, MInt rhs) {
        MInt res = lhs;
        res /= rhs;
        return res;
    }
    friend constexpr std::istream &operator>>(std::istream &is, MInt &a) {
        i64 v;
        is >> v;
        a = MInt(v);
        return is;
    }
    friend constexpr std::ostream &operator<<(std::ostream &os, const MInt &a) {
        return os << a.val();
    }
    friend constexpr bool operator==(MInt lhs, MInt rhs) {
        return lhs.val() == rhs.val();
    }
    friend constexpr bool operator!=(MInt lhs, MInt rhs) {
        return lhs.val() != rhs.val();
    }
};
 
template<int V, int P>
constexpr MInt<P> CInv = MInt<P>(V).inv();
 
constexpr int P = 998244353;
using Z = MInt<P>;

// 黑科技 2 倍空间: https://www.cnblogs.com/chy-2003/p/11815396.html
// 来自 jiangly: https://atcoder.jp/contests/abc265/submissions/34253107
template <typename Info, typename Tag>
struct LazySegmentTree {
    int n;
    vector<Info> info;  // 节点维护的信息
    vector<Tag> tag;    // 节点的懒惰标记

    // 向上更新
    void up(int k) {
        info[k] = info[k << 1] + info[k << 1 | 1];
    }

    // 初始化: 记得用 4 倍空间
    LazySegmentTree(int n_, vector<Info>& init_): n(n_) {
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
            up(k);
        };
        build(1, 1, n);
    }

    // 用 tag 更新当前节点
    void apply(int k, const Tag& v) {
        info[k].apply(v);
        tag[k].apply(v);
    }

    // 向下更新
    void down(int k) {
        apply(k << 1, tag[k]);
        apply(k << 1 | 1, tag[k]);
        tag[k] = Tag();  // 更新完, tag[k] 要初始化
    }

    // 单点更新
    void update(int k, int s, int t, int p, const Info& v) {
        if (s == t) {
            info[k] = v;
            return ;
        }
        down(k);
        int mid = (s + t) / 2;
        if (p <= mid) update(k << 1, s, mid, p, v);
        else update(k << 1 | 1, mid + 1, t, p, v);
        up(k);
    }

    // 单点更新
    void update(int p, const Info& v) {
        update(1, 1, n, p, v);
    }

    // 区间查询
    Info query(int k, int s, int t, int l, int r) {
        if (t < l || s > r) return Info();
        if (s >= l && t <= r) return info[k];
        down(k);
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
        down(k);
        int mid = (s + t) / 2;
        update(k << 1, s, mid, l, r, v);
        update(k << 1 | 1, mid + 1, t, l, r, v);
        up(k);
    }

    // 区间更新
    void update(int l, int r, const Tag& v) {
        update(1, 1, n, l, r, v);
    }

    void print(int k, int s, int t, int d = 0) {
        int mid = (s + t) / 2;
        if (s != t) down(k);
        if (s != t) print(k << 1, s, mid, d + 1);
        for (int i = 0; i < d; ++i) cout << '\t';
        cout << info[k].num << ":" << info[k].sa <<  ":" << info[k].sb << ":" << info[k].s << '\n';
        if (s != t) print(k << 1 | 1, mid + 1, t, d + 1);      
    }

    // print(1); 打印整个线段树
    void print(int k) {
        print(1, 1, n, 0);
    }
};

// 节点要下放的标记
struct Tag {
    Z add_a = 0, add_b = 0;

    // tag + tag
    void apply(const Tag& t) {
        add_a = add_a + t.add_a;
        add_b = add_b + t.add_b;
    }
};

// 节点维护的信息
struct Info {
    Z num = 0;
    Z sa = 0, sb = 0, s = 0;

    // info + tag
    void apply(const Tag& t) {
        s = s + t.add_a * sb + t.add_b * sa + t.add_a * t.add_b * num;
        sa = sa + num * t.add_a;
        sb = sb + num * t.add_b;
    }
};

// info + info
Info operator+(const Info& a, const Info& b) {
    return {a.num + b.num, a.sa + b.sa, a.sb + b.sb, a.s + b.s};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, c, l, r, x;
    cin >> n >> m;
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];

    vector<Info> init_(n + 1);
    for (int i = 1; i <= n; i++) init_[i] = {1, a[i], b[i], (LL) a[i] * b[i] % P};
    LazySegmentTree<Info, Tag> seg(n, init_);

    // seg.print(1);
    while (m--) {
        cin >> c >> l >> r;
        if (c == 1) {
            cin >> x;
            seg.update(l, r, {x, 0});
        } else if (c == 2) {
            cin >> x;
            seg.update(l, r, {0, x});
        } else {
            cout << seg.query(l, r).s << '\n';
        }
    }
    return 0;
}