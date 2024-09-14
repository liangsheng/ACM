#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int MOD;
const LL INF = numeric_limits<LL>::max() / 2;

/*----------------------- 区间修改, 区间查询，线段树 begin -----------------------*/
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
            // 注意: 单点更新的时候, 这里是赋值操作
            // 如果题目是加法操作, 需要修改这里
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

/*-------------------------- 一般来说, 你只需要修改下面的内容 ------------------*/
// 节点要下放的标记
struct Tag {
    int mul = 1, add = 0;

    // tag + tag
    void apply(const Tag& t) {
        // 注意: 这里一定要先更新 add, 再更新 mul
        add = ((LL) add * t.mul % MOD + t.add) % MOD;
        mul = (LL) mul * t.mul % MOD;
    }
};

// 节点维护的信息
struct Info {
    int num = 0, sum = 0;

    // info + tag
    void apply(const Tag& t) {
        sum = ((LL) sum * t.mul + (LL) num * t.add) % MOD;
    }
};

// info + info
Info operator+(const Info& a, const Info& b) {
    return {a.num + b.num, (a.sum + b.sum) % MOD};
}
/*----------------------- 区间修改, 区间查询，线段树 end -------------------------*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m, c, l, r, v;
    cin >> n >> m >> MOD;
    vector<Info> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v;
        a[i] = {1, v};  // num, sum
    }

    LazySegmentTree<Info, Tag> seg(n, a);
    while (m--) {
        cin >> c >> l >> r;
        if (c == 1) {
            cin >> v;
            seg.update(l, r, {v, 0});
        } else if (c == 2) {
            cin >> v;
            seg.update(l, r, {1, v});
        } else {
            cout << seg.query(l, r).sum << '\n';
        }
    }
    return 0; 
}