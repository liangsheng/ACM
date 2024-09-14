#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N = 100005, INF = ~0U >> 2;

/*---------------------------------- st 表 begin -------------------------*/
template<typename T>
struct RMQ {
    int n, D;               // D 是 st 表的深度为 ln[n] + 1
    function<T(T, T)> cmp;  // 比较函数
    vector<int> ln;         // 快速求 ln
    vector<vector<T>> st;   // st 的大小是 (D, n)

    // a[] 是元数组, 从 1 开始编号, [1..n]
    RMQ(int n_, vector<T>& a, function<T(T, T)> cmp_): n(n_), cmp(cmp_) {
        ln.assign(n + 1, -1);

        // ln[i] 是使得 power(2, x) <= i 的最大的 x
        // ln[1] = 0, ln[2] = 1, ln[3] = 1, ln[4] = 2, ln[5] = 2
        for (int i = 1; i <= n; i++) ln[i] = ln[i / 2] + 1;

        D = ln[n] + 1;
        st.assign(D, vector<T>(n + 1));
        for (int i = 1; i <= n; i++) st[0][i] = a[i];
        for (int j = 1, t = 1; j <= ln[n]; j++, t *= 2) {
            for (int i = 1; i + t * 2 - 1 <= n; i++) st[j][i] = cmp(st[j - 1][i], st[j - 1][i + t]);
        }
    }

    T query(int i, int j) {
        if (i == j) return st[0][i];
        if (i > j) swap(i, j);
        int m = ln[j - i];
        // int m = ln[j - i + 1];  // 这个也可以通过
        return cmp(st[m][i], st[m][j - (1 << m) + 1]);
    }
};
/*---------------------------------- st 表 end ---------------------------*/

inline int read() {
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - 48; ch = getchar(); }
	return x * f;
}

template<typename T>
inline void write(T x) {
    if (x < 0) { putchar('-'); x = -x; }
    if (x > 9) write(x / 10);
    putchar( x % 10 + '0');
}

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    
    int n = read(), m = read(), q = read(), l1, r1, l2, r2;
    // cin >> n >> m >> q;
    vector<int> a(n + 1), b(m + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int j = 1; j <= m; j++) cin >> b[j];

    RMQ<int> max_b(m, b, [&](int x, int y) { return max(x, y); });
    RMQ<int> min_b(m, b, [&](int x, int y) { return min(x, y); });

    RMQ<int> max_a(n, a, [&](int x, int y) { return max(x, y); });
    RMQ<int> min_a(n, a, [&](int x, int y) { return min(x, y); });

    // 小于等于 0 里面最大的
    RMQ<int> max_a_l0(n, a, [&](int x, int y) { return max(x <= 0 ? x : -INF, y <= 0 ? y : -INF); });

    // 大于等于 0 里面最小的
    RMQ<int> min_a_g0(n, a, [&](int x, int y) { return min(x >= 0 ? x : INF, y >= 0 ? y : INF); });

    while (q--) {
        cin >> l1 >> r1 >> l2 >> r2;
        LL ans;
        if (min_b.query(l2, r2) >= 0) {                                          // b[l2..r2] >= 0
            if (max_a.query(l1, r1) <= 0) {
                ans = (LL) max_a.query(l1, r1) * max_b.query(l2, r2);  // 负
            } else {
                ans = (LL) max_a.query(l1, r1) * min_b.query(l2, r2);  // 正
            }
        } else if (max_b.query(l2, r2) <= 0) {                                   // b[l2..r2] <= 0
            if (min_a.query(l1, r1) >= 0) {
                ans = (LL) min_a.query(l1, r1) * min_b.query(l2, r2);  // 负
            } else {
                ans = (LL) min_a.query(l1, r1) * max_b.query(l2, r2);  // 正
            }
        } else {
            if (min_a.query(l1, r1) >= 0) {
                ans = (LL) min_a.query(l1, r1) * min_b.query(l2, r2);  // 负
            } else if (max_a.query(l1, r1) <= 0) {
                ans = (LL) max_a.query(l1, r1) * max_b.query(l2, r2);  // 负
            } else {
                ans = (LL) min_a_g0.query(l1, r1) * min_b.query(l2, r2);
                LL res = (LL) max_a_l0.query(l1, r1) * max_b.query(l2, r2);
                ans = max(ans, res);
            }
        }
        // printf("%lld\n", ans);
        write(ans);
        putchar('\n');
    }
    return 0; 
}