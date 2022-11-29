#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N = 200005;

int n;
int a[N], b[N], c[N];
LL fb[N], fc[N];
LL ans;

LL gao(int x, int y) {
    if (a[x] == y) return ans;
    if (y < a[x]) {
        if (y >= x) return ans;
        if (x == 1) return ans;
        int l = lower_bound(b + 1, b + x, x) - b;
        int r = x - y;
        if (!(l >= 1 && l <= x - 1)) return ans;
        if (!(r >= l && r <= x - 1)) return ans;
        LL origin = fb[r] - fb[l - 1];
        LL now = (LL) (x - l + x - r) * (r - l + 1) / 2;
        // printf("small ans= %lld, l= %d, r= %d, origin= %lld, now= %lld\n", ans, l, r, origin, now);
        return ans - origin + now;
    }
    if (y > a[x]) {
        if (x == n) return ans;
        int l = lower_bound(b + 1, b + x, x - 1) - b;
        l = max(l, x - y + 1);
        int r = upper_bound(b + 1, b + x, x - 1) - b - 1;
        if (l > r) return ans;
        if (!(l >= 1 && l <= x - 1)) return ans;
        if (!(r >= l && r <= x - 1)) return ans;
        LL origin = fb[r] - fb[l - 1];
        LL now = fc[r] - fc[l - 1];
        // printf("big ans= %lld, l= %d, r= %d, origin= %lld, now= %lld\n", ans, l, r, origin, now);
        return ans - origin + now;
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int m, x, y, p, d;
    while (cin >> n) {
        for (int i = 1; i <= n; i++) cin >> a[i];

        ans = 0, p = 1, fb[0] = 0;
        for (int i = 1; i <= n; i++) {
            while (p + 1 <= n && a[p + 1] >= p + 1 - i + 1) p++;
            b[i] = p, fb[i] = fb[i - 1] + b[i] - i + 1;
            ans += p - i + 1;
        }

        fc[0] = 0, p = 1, d = 0;
        for (int i = 1; i <= n; i++) {
            while (p + 1 <= n && a[p + 1] >= p + 1 - i + 1) p++;
            if (p == n) c[i] = n;
            else {
                // cout << "i= " << i << ' ' << d << '\n';
                if (i > d || i >= d - a[d] + 1) {
                    d = ++p;
                    while (p + 1 <= n && a[p + 1] >= p + 1 - i + 1) p++;
                    c[i] = p;
                } else c[i] = p;
            }
            fc[i] = fc[i - 1] + c[i] - i + 1;
        }
        // for (int i = 1; i <= n; i++) cout << b[i] << ' ';
        // cout << '\n';
        // for (int i = 1; i <= n; i++) cout << fb[i] << ' ';
        // cout << '\n';
        // for (int i = 1; i <= n; i++) cout << c[i] << ' ';
        // cout << '\n';
        // for (int i = 1; i <= n; i++) cout << fc[i] << ' ';
        // cout << '\n';
        cin >> m;
        while (m--) {
            cin >> x >> y;
            cout << gao(x, y) << '\n';
        }
    }
    return 0;
}