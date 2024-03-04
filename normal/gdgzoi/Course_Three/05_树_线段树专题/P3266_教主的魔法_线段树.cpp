#include <bits/stdc++.h>
#define repe(i, u) for (int i = head[u]; i != -1; i = nxt[i])
using namespace std;
typedef long long LL;

/*
 * P3266_教主的魔法: http://gdgzoi.com/problem.php?id=3266
 * 题意: 线段树, 区间都加上一个数, 询问区间大于等于某数的数的个数
 */

/*-------------------------- 线段树 begin ----------------*/
const int N = 1000001;

// A[] 是原数组, a[] 是线段树维护的最小值, b[] 是线段树维护的最大值
LL A[N], a[N << 2], b[N << 2], lz[N << 2];

void push_up(int k) {
    a[k] = min(a[k << 1], a[k << 1 | 1]);
    b[k] = max(b[k << 1], b[k << 1 | 1]);
}

void init(int k, int s, int t) {
    lz[k] = 0;
    if (s == t) {
        a[k] = A[s], b[k] = a[k];
        return ;
    }
    int mid = (s + t) >> 1;
    init(k << 1, s, mid);
    init(k << 1 | 1, mid + 1, t);
    push_up(k);
}

void push_down(int k, int s, int t) {
    int l = k << 1, r = l + 1, mid = (s + t) >> 1;
    a[l] += lz[k], b[l] += lz[k], lz[l] += lz[k];
    a[r] += lz[k], b[r] += lz[k], lz[r] += lz[k];
    lz[k] = 0;
}

void update(int k, int s, int t, int l, int r, int v) {
    if (l > t || r < s) return ;
    if (s >= l && t <= r) {
        a[k] += v, b[k] += v;
        lz[k] += v;
        return ;
    }
    push_down(k, s, t);
    int mid = (s + t) >> 1;
    update(k << 1, s, mid, l, r, v);
    update(k << 1 | 1, mid + 1, t, l, r, v);
    push_up(k);
}

int query(int k, int s, int t, int l, int r, int c) {
    if (s > r || t < l) return 0;
    if (s >= l && t <= r) {
        if (b[k] < c) return 0;
        if (a[k] >= c) return t - s + 1;
    }
    push_down(k, s, t);
    int mid = (s + t) >> 1;
    int ans = query(k << 1, s, mid, l, r, c) + query(k << 1 | 1, mid + 1, t, l, r, c);
    return ans;
}
/*-------------------------- 线段树 end ------------------*/

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);

    int n, m, x, y, z;
    string cmd;
    while (cin >> n >> m) {
        for (int i = 1; i <= n; i++) cin >> A[i];
        init(1, 1, n);  // 千万不要忘记 init()
        while (m--) {
            cin >> cmd >> x >> y >> z;
            if (cmd[0] == 'M') update(1, 1, n, x, y, z);
            else cout << query(1, 1, n, x, y, z) << '\n';
        }
    }
    return 0;
}