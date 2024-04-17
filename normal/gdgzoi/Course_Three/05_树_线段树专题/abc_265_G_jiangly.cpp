// https://atcoder.jp/contests/abc265/submissions/34253107
#include <bits/stdc++.h>

using i64 = long long;
template<class Info, class Tag>
struct LazySegmentTree {
    const int n;
    std::vector<Info> info;
    std::vector<Tag> tag;
    LazySegmentTree(int n) : n(n), info(4 << std::__lg(n)), tag(4 << std::__lg(n)) {}
    LazySegmentTree(std::vector<Info> init) : LazySegmentTree(init.size()) {
        std::function<void(int, int, int)> build = [&](int p, int l, int r) {
            if (r - l == 1) {
                info[p] = init[l];
                return;
            }
            int m = (l + r) / 2;
            build(2 * p, l, m);
            build(2 * p + 1, m, r);
            pull(p);
        };
        build(1, 0, n);
    }
    void pull(int p) {
        info[p] = info[2 * p] + info[2 * p + 1];
    }
    void apply(int p, const Tag &v) {
        info[p].apply(v);
        tag[p].apply(v);
    }
    void push(int p) {
        apply(2 * p, tag[p]);
        apply(2 * p + 1, tag[p]);
        tag[p] = Tag();
    }
    void modify(int p, int l, int r, int x, const Info &v) {
        if (r - l == 1) {
            info[p] = v;
            return;
        }
        int m = (l + r) / 2;
        push(p);
        if (x < m) {
            modify(2 * p, l, m, x, v);
        } else {
            modify(2 * p + 1, m, r, x, v);
        }
        pull(p);
    }
    void modify(int p, const Info &v) {
        modify(1, 0, n, p, v);
    }
    Info rangeQuery(int p, int l, int r, int x, int y) {
        if (l >= y || r <= x) {
            return Info();
        }
        if (l >= x && r <= y) {
            return info[p];
        }
        int m = (l + r) / 2;
        push(p);
        return rangeQuery(2 * p, l, m, x, y) + rangeQuery(2 * p + 1, m, r, x, y);
    }
    Info rangeQuery(int l, int r) {
        return rangeQuery(1, 0, n, l, r);
    }
    void rangeApply(int p, int l, int r, int x, int y, const Tag &v) {
        if (l >= y || r <= x) {
            return;
        }
        if (l >= x && r <= y) {
            apply(p, v);
            return;
        }
        int m = (l + r) / 2;
        push(p);
        rangeApply(2 * p, l, m, x, y, v);
        rangeApply(2 * p + 1, m, r, x, y, v);
        pull(p);
    }
    void rangeApply(int l, int r, const Tag &v) {
        return rangeApply(1, 0, n, l, r, v);
    }
};

struct Tag {
    std::array<int, 3> to = {0, 1, 2};
    void apply(const Tag &t) {
        for (int i = 0; i < 3; i++) {
            to[i] = t.to[to[i]];
        }
    }
};

struct Info {
    std::array<int, 3> c1;
    std::array<std::array<i64, 3>, 3> c2;
    Info() : c1{}, c2{} {}
    Info(int x) : Info() {
        c1[x] = 1;
    }
    void apply(const Tag &t) {
        std::array<int, 3> nc1{};
        std::array<std::array<i64, 3>, 3> nc2{};
        for (int i = 0; i < 3; i++) {
            nc1[t.to[i]] += c1[i];
            for (int j = 0; j < 3; j++) {
                nc2[t.to[i]][t.to[j]] += c2[i][j];
            }
        }
        c1 = nc1;
        c2 = nc2;
    }
};

Info operator+(const Info &a, const Info &b) {
    Info c;
    for (int i = 0; i < 3; i++) {
        c.c1[i] = a.c1[i] + b.c1[i];
        for (int j = 0; j < 3; j++) {
            c.c2[i][j] = a.c2[i][j] + b.c2[i][j] + 1LL * a.c1[i] * b.c1[j];
        }
    }
    return c;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, q;
    std::cin >> n >> q;
    
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    
    LazySegmentTree<Info, Tag> seg(std::vector<Info>(a.begin(), a.end()));
    
    for (int i = 0; i < q; i++) {
        int o, l, r;
        std::cin >> o >> l >> r;
        l--;
        
        if (o == 1) {
            auto info = seg.rangeQuery(l, r);
            auto ans = info.c2[1][0] + info.c2[2][0] + info.c2[2][1];
            std::cout << ans << "\n";
        } else {
            int a, b, c;
            std::cin >> a >> b >> c;
            
            seg.rangeApply(l, r, {{a, b, c}});
        }
    }
    
    return 0;
}
