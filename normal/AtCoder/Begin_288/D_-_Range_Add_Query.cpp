#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

LL n, k, m, l, r;
vector<LL> a;
vector<LL> b;

struct SegTree {
    int n;
    vector<LL> c;

    void init(int N) {
        n = N;
        c = vector<LL>(4 * n, 0);
        build(1, 1, n);
    }

    void build(int k, int s, int t) {
        if (s == t) {
            c[k] = a[s];
            return ;
        }
        int mid = (s + t) >> 1;
        build(k << 1, s, mid);
        build(k << 1 | 1, mid + 1, t);
        c[k] = max(c[k << 1], c[k << 1 | 1]);
    }

    LL query(int k, int s, int t, int l, int r) {
        if (s >= l && t <= r) return c[k];
        if (s > r || t < l) return 0;
        int mid = (s + t) >> 1;
        LL ans = query(k << 1, s, mid, l, r);
        return max(ans, query(k << 1 | 1, mid + 1, t, l, r));
    }

} seg;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
    while (cin >> n >> k) {
        a = vector<LL>(n + 1, 0);
        b = vector<LL>(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            a[i] += k * 1000000000;
            b[i] = b[i - 1] + a[i];
        }
        // seg.init(n);
        cin >> m;
        while (m--) {
            cin >> l >> r;
            LL sum = b[r] - b[l - 1];
            if (sum % k) cout << "No" << '\n';
            else {
                
            }
        }
    }
    return 0;
}