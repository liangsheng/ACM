#include <bits/stdc++.h>
#define lowbit(x) ((x) & (-x))
using namespace std;
typedef long long LL;

const int MOD = 998244353, N = 200001;

int a[N + 5];

void init() {
    memset(a, 0, sizeof(a));
}

void update(int p, int v) {
    if (p >= N) return ;
    for (; p <= N; p += lowbit(p)) a[p] += v;
}

int query(int p) {
    if (p >= N) return 0;
    int ans = 0;
    for (p; p > 0; p -= lowbit(p)) ans += a[p];
    return ans;
}

int gao(int n, int l1, int r1, int l2, int r2) {
    if (l1 + l2 > n || r1 + r2 < n) return 0;
    int d = n - l1, l, r;
    if (d <= r2) {
        l = l1;
        r = min(l1 + d - l2, r1);
    } else {
        l = l1 + d - r2;
        r = min(l + r2 - l2, r1);
    }
    return r - l + 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    while (cin >> n >> m) {
        init();
        LL ans = 0, l, r;
        for (int i = 0; i < m; i++) {
            cin >> l >> r;
            // l = 1, r = 200000;
            ans -= gao(n, l, r, l, r);
            update(l, 1);
            update(r + 1, -1);
        }
        for (int i = 1; i < n; i++) ans = (ans + (LL) query(i) * query(n - i) % MOD) % MOD;
        cout << ans << '\n';
    }
    return 0;
}