#include <bits/stdc++.h>
using namespace std;

//by ei1333
//https://ei1333.github.io/luzhiled/snippets/structure/segment-tree.html
template< typename Monoid >
struct SegmentTree {
    using F = function< Monoid(Monoid, Monoid) >;

    int sz;
    vector< Monoid > seg;

    const F f;
    const Monoid M1;

    SegmentTree(int n, const F f, const Monoid& M1) : f(f), M1(M1) {
        sz = 1;
        while (sz < n) sz <<= 1;
        seg.assign(2 * sz + 1, M1);
    }

    void set(int k, const Monoid& x) {
        seg[k + sz] = x;
    }

    void build() {
        for (int k = sz - 1; k > 0; k--) {
            seg[k] = f(seg[2 * k + 0], seg[2 * k + 1]);
        }
    }

    void update(int k, const Monoid& x) {
        // cout << "update k= " << k << " x= " << x << '\n';
        k += sz;
        seg[k] = x;
        while (k >>= 1) {
            seg[k] = f(seg[2 * k + 0], seg[2 * k + 1]);
        }
    }

    Monoid query(int a, int b) {
        Monoid L = M1, R = M1;
        for (a += sz, b += sz; a < b; a >>= 1, b >>= 1) {
            if (a & 1) L = f(L, seg[a++]);
            if (b & 1) R = f(seg[--b], R);
        }
        return f(L, R);
    }

    Monoid operator[](const int& k) const {
        return seg[k + sz];
    }
};

struct Node {
    int l, r, c, id;
    Node() {}
    Node(int L, int R, int C, int ID): l(L), r(R), c(C), id(ID) {}
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // SegmentTree<int> seg(10, [](int a, int b) { return min(a, b); }, INT_MAX);
    int T, n;
    cin >> T;
    while (T--) {
        cin >> n;
        vector<Node> a(n); 
        for (int i = 0; i < n; i++) cin >> a[i].l >> a[i].r >> a[i].c, a[i].id = i;

        vector<int> ans(n, INT_MAX);

        sort(a.begin(), a.end(), [](const Node& x, const Node& y) {
            if (x.r != y.r) return x.r < y.r;
            return x.l < y.l;
        });
        SegmentTree<int> seg(n, [](int a, int b) { return max(a, b); }, 0);
        seg.update(a[0].c, a[0].r);
        for (int i = 1; i < n; i++) {
            int l = a[i].l, r = a[i].r, c = a[i].c, id = a[i].id;
            int maxi = 0, res;
            if (c > 1) maxi = max(maxi, seg.query(1, c));
            if (c < n) maxi = max(maxi, seg.query(c + 1, n + 1));
            if (maxi == 0) res = INT_MAX;
            else res = max(0, l - maxi);
            // cout << "i= " << i << " id= " << id << " maxi= " << maxi << " res= " << res << '\n';
            ans[id] = min(ans[id], res);
            seg.update(c, r);
        }
        // for (int i = 0; i < n - 1; i++) cout << ans[i] << ' ';
        // cout << ans[n - 1] << '\n';

        reverse(a.begin(), a.end());
        SegmentTree<int> seg_2(n, [](int a, int b) { return min(a, b); }, INT_MAX);
        seg_2.update(a[0].c, a[0].l);
        // cout << "test= " << seg_2.query(2, n + 1) << '\n';
        for (int i = 1; i < n; i++) {
            int l = a[i].l, r = a[i].r, c = a[i].c, id = a[i].id;
            int mini = INT_MAX, res;
            if (c > 1) mini = min(mini, seg_2.query(1, c));
            if (c < n) mini = min(mini, seg_2.query(c + 1, n + 1));
            res = max(0, mini - r);
            // cout << "i= " << i << " id= " << id << " mini= " << mini << " res= " << res << '\n';
            ans[id] = min(ans[id], res);
            seg_2.update(c, l);
        }
        
        for (int i = 0; i < n - 1; i++) cout << ans[i] << ' ';
        cout << ans[n - 1] << '\n';
    }
    return 0;
}