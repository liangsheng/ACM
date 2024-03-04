#include <bits/stdc++.h>
using namespace std;

/*-------------------------- 线段树 begin ----------------*/
vector<vector<int>> a, b;

void gao(vector<int>& a, vector<int>& b, vector<int>& x, vector<int>& y, vector<int>& c, vector<int>& d) {
    c[0] = max(a[0], x[0]);
    d[0] = (a[0] == c[0]) * b[0] + (x[0] == c[0]) * y[0];

    c[1] = 0, d[1] = 0;
    if (a[0] != c[0] && a[0] > c[1]) c[1] = a[0];
    if (a[1] != c[0] && a[1] > c[1]) c[1] = a[1];
    if (x[0] != c[0] && x[0] > c[1]) c[1] = x[0];
    if (x[1] != c[0] && x[1] > c[1]) c[1] = x[1];
    d[1] += (a[0] == c[1]) * b[0] + (a[1] == c[1]) * b[1];
    d[1] += (x[0] == c[1]) * y[0] + (x[1] == c[1]) * y[1];
}

void push_up(int k) {
    int l = k << 1, r = l + 1;
    gao(a[l], b[l], a[r], b[r], a[k], b[k]);
}

// 初始化线段树
void init(int k, int s, int t, vector<int>& A) {
    if (s == t) {
        a[k][0] = A[s], b[k][0] = 1;
        a[k][1] = 0, b[k][1] = 0;
        return ;
    }
    int mid = (s + t) >> 1;
    init(k << 1, s, mid, A);
    init(k << 1 | 1, mid + 1, t, A);
    // 这里可以写自己的初始化逻辑, 这里是求和
    push_up(k);
}

// 单点更新
void update(int k, int s, int t, int x, int val) {
    if (x < s || x > t) return;
    if (s == t) {
        a[k][0] = val, b[k][0] = 1;
        a[k][1] = 0, b[k][1] = 0;
        return;
    }
    int mid = (s + t) >> 1;
    if (x <= mid) update(k << 1, s, mid, x, val);
    else update(k << 1 | 1, mid + 1, t, x, val);
    push_up(k);
}

// 区间查询
void query(int k, int s, int t, int l, int r, vector<int>& x, vector<int>& y) {
    if (s > r || t < l) return ;
    if (s >= l && t <= r) {
        x = a[k], y = b[k];
        return ;
    }
    int mid = (s + t) >> 1;
    vector<int> c(2, 0), d(2, 0), u(2, 0), v(2, 0);
    query(k << 1, s, mid, l, r, c, d);
    query(k << 1 | 1, mid + 1, t, l, r, u, v);
    gao(c, d, u, v, x, y);
}
/*-------------------------- 线段树 end ------------------*/

int main() {
    // 下面 2 句话是为了让 cin 更快，不理解可以先不写
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, c, p, x;
    cin >> n >> m;
    a = vector<vector<int>>(n << 2, vector<int>(2, 0));
    b = vector<vector<int>>(n << 2, vector<int>(2, 0));
    vector<int> A(n + 1), u(2, 0), v(2, 0);
    for (int i = 1; i <= n; i++) cin >> A[i];
    init(1, 1, n, A);
    while (m--) {
        cin >> c >> p >> x;
        if (c == 1) update(1, 1, n, p, x);
        else {
            query(1, 1, n, p, x, u, v);
            if (u[1] == 0) cout << 0 << '\n';
            else cout << v[1] << '\n';
        }
    }
    return 0;
}