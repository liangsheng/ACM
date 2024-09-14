#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m, l, r;
    cin >> n >> m;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    // 求最大值
    RMQ<int> rmq_max(n, a, [&](int x, int y) { return max(x, y); });

    // 求最小值
    RMQ<int> rmq_min(n, a, [&](int x, int y) { return min(x, y); });
    while (m--) {
        cin >> l >> r;
        cout << rmq_min.query(l, r) << ' ' << rmq_max.query(l, r) << '\n';
    }
    return 0; 
}