#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N = 400005;

int T, n;
LL a[N], fa[N], ga[N], e[N];
pair<LL, int> b[N];

int c[N * 4];

void init(int k, int s, int t) {
    c[k] = b[s].second;
    if (s == t) return ;
    int mid = (s + t) >> 1;
    init(k << 1, s, mid);
    init(k << 1 | 1, mid + 1, t);
}

void update(int k, int s, int t, int p, int val) {
    if (p < s || p > t) return ;
    if (s == t) {
        c[k] = val;
        return ;
    }
    int mid = (s + t) >> 1;
    update(k << 1, s, mid, p, val);
    update(k << 1 | 1, mid + 1, t, p, val);
    c[k] = min(c[k << 1], c[k << 1 | 1]);
}

int query(int k, int s, int t, int l, int r) {
    if (s > r || t < l) return n + 1;
    if (s >= l && t <= r) return c[k];
    int mid = (s + t) >> 1;
    int ans = query(k << 1, s, mid, l, r);
    ans = min(ans, query(k << 1 | 1, mid + 1, t, l, r));
    return ans;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    for (int cas = 1; cas <= T; cas++) {
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i];
        fa[n + 1] = 0, ga[n + 1] = 0;
        for (int i = n; i >= 1; i--) {
            fa[i] = fa[i + 1] + (n + 1 - i) * a[i];
            ga[i] = ga[i + 1] + a[i];
        }

        b[0].first = 0, b[0].second = 0;
        for (int i = 1; i <= n; i++) {
            b[i].first = b[i - 1].first + a[i];
            b[i].second = i;
        }
        sort(b + 1, b + n + 1);
        vector<int> g(n + 1);
        for (int i = 1; i <= n; i++) g[b[i].second] = i, e[i] = b[i].first;
        // for (int i = 1; i <= n; i++) cout << b[i].first << ' ' << b[i].second << '\n';
        // cout << "Hello World" << '\n';
        init(1, 1, n);
        LL tmp = 0, ans = 0;
        for (int i = 1; i <= n; i++) {
            int id = lower_bound(e + 1, e + n + 1, tmp) - e - 1;
            int p = n;
            if (id >= 1) p = query(1, 1, n, 1, id) - 1;
            if (p >= i) {
                LL g = fa[i] - fa[p + 1];
                LL h = ga[i] - ga[p + 1];
                LL k = g - h * (n - p);
                ans += k;
            }
            // cout << "i= " << i << ", id= " << id << ", tmp= " << tmp << ", p= " << p << ", ans= " << ans << '\n';
            update(1, 1, n, g[i], n + 1);
            tmp += a[i];
        }
        cout << "Case #" << cas << ": " << ans << '\n';
    }
    return 0;
}