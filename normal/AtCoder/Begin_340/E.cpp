#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

/*-------------------------- 线段树 begin ----------------*/
const int N = 200005;

int b[N];
LL a[N << 2], lz[N << 2];

void push_up(int k) {
    a[k] = a[k << 1] + a[k << 1 | 1];
}

void init(int k, int s, int t) {
    if (s == t) {
        a[k] = b[s], lz[k] = 0;
        return ;
    }
    int mid = (s + t) >> 1;
    init(k << 1, s, mid);
    init(k << 1 | 1, mid + 1, t);
    push_up(k);
}

void push_down(int k, int s, int t) {
    int l = k << 1, r = l + 1, mid = (s + t) >> 1;
    a[l] += lz[k] * (mid - s + 1), lz[l] += lz[k];
    a[r] += lz[k] * (t - mid), lz[r] += lz[k];
    lz[k] = 0;
}

void update(int k, int s, int t, int l, int r, LL v) {
    if (l > t || r < s) return ;
    if (s >= l && t <= r) {
        a[k] += (t - s + 1) * v;
        lz[k] += v;
        return ;
    }
    push_down(k, s, t);
    int mid = (s + t) >> 1;
    update(k << 1, s, mid, l, r, v);
    update(k << 1 | 1, mid + 1, t, l, r, v);
    push_up(k);
}

LL query(int k, int s, int t, int l, int r) {
    if (s >= l && t <= r) return a[k];
    if (s > r || t < l) return 0;
    push_down(k, s, t);
    int mid = (s + t) >> 1;
    LL ans = query(k << 1, s, mid, l, r) + query(k << 1 | 1, mid + 1, t, l, r);
    return ans;
}
/*-------------------------- 线段树 end ------------------*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, x;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> b[i];
    init(1, 1, n);
    for (int i = 1; i <= m; i++) {
        cin >> x;
        x++;
        LL c = query(1, 1, n, x, x);
        update(1, 1, n, x, x, -c);
        LL p = c / n, q = c % n;
        if (p > 0) update(1, 1, n, 1, n, p);
        if (n - x >= q) {
            update(1, 1, n, x + 1, x + q, 1);
        } else {
            update(1, 1, n, x + 1, n, 1);
            update(1, 1, n, 1, q - (n - x), 1);
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << query(1, 1, n, i, i) << " \n"[i == n];
    }
    return 0;
}