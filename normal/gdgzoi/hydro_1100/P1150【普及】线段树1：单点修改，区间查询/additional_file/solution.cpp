#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const LL INF = numeric_limits<LL>::max() / 2;

/*----------------------- 单点修改, 区间查询，线段树 begin -----------------------*/
template<typename Info>
struct SegmentTree {
    int n;
    vector<Info> info;  // 线段树节点中存储的信息

    void up(int k) {
        info[k] = info[k << 1] + info[k << 1 | 1];
    }

    // 初始化 4 被空间
    SegmentTree(int n_, vector<Info>& init_): n(n_) {
        info.assign(n * 4, Info());
        function<void(int, int, int)> build = [&](int k, int s, int t) {
            // 终止条件: 到达叶子节点
            if (s == t) {
                info[k] = init_[s];
                return ;
            }
            // 分别初始化左右儿子
            int mid = (s + t) >> 1;
            build(k << 1, s, mid);
            build(k << 1 | 1, mid + 1, t);
            
            // 初始化左右儿子结束后, 更新父节点
            up(k);
        };
        build(1, 1, n);
    }

    // 单点更新: 将 a[p] 更新为 v
    void update(int k, int s, int t, int p, Info v) {
        // 终止条件: 到达叶子节点
        if (s == t) {
            // 注意: 单点更新的时候, 这里是赋值操作
            // 如果题目是加法操作, 需要修改这里
            info[k] = v;
            return ;
        }
        // 向左右儿子递归
        int mid = (s + t) >> 1;
        if (p <= mid) update(k << 1, s, mid, p, v);
        else update(k << 1 | 1, mid + 1, t, p, v);
    
        // 用更新完后的儿子节点, 来更新父节点
        up(k);
    }

    // 单点更新: 将 a[p] 更新为 v
    void update(int p, Info v) {
        update(1, 1, n, p, v);
    }

    // 区间查询: 查询 [l, r] 的值
    Info query(int k, int s, int t, int l, int r) {
        // 终止条件: 区间不相交, 返回默认值
        if (t < l || s > r) return Info();
        // 终止条件: [s, t] 完全包含在 [l, r] 中
        if (s >= l && t <= r) return info[k];

        // 分别查询左右儿子
        int mid = (s + t) >> 1;
        return query(k << 1, s, mid, l, r) + query(k << 1 | 1, mid + 1, t, l, r);
    }

    // 区间查询
    Info query(int l, int r) {
        return query(1, 1, n, l, r);
    }

    void print(int k, int s, int t, int d = 0) {
        int mid = (s + t) / 2;
        if (s != t) print(k << 1, s, mid, d + 1);
        for (int i = 0; i < d; ++i) cout << '\t';
        cout << info[k].mini << ":" << info[k].maxi <<  ":" << info[k].sum << '\n';  
        if (s != t) print(k << 1 | 1, mid + 1, t, d + 1);      
    }

    // print(1); 打印整个线段树
    void print(int k) {
        print(1, 1, n, 0);
    }
};

// 线段树节点存储的信息
struct Info {
    LL mini = INF, maxi = -INF, sum = 0;
};

// 实现 2 个 Info 的合并, 用在 up() 中
Info operator+(Info a, Info b) {
    return {min(a.mini, b.mini), max(a.maxi, b.maxi), a.sum + b.sum};
}
/*----------------------- 单点修改, 区间查询，线段树 end -------------------------*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m, c, l, r, p, v;
    cin >> n >> m;
    vector<Info> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v;
        a[i] = {v, v, v};
    }

    SegmentTree<Info> seg(n, a);
    while (m--) {
        cin >> c;
        if (c == 1) {
            cin >> p >> v;
            seg.update(p, {v, v, v});
        } else {
            cin >> l >> r;
            Info ans = seg.query(l, r);
            cout << ans.mini << ' ' << ans.maxi << ' ' << ans.sum << '\n';
        }
    }
    return 0; 
}