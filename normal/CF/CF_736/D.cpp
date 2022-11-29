#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N = 200000, D = 20;

int T, n;
LL x[N + 5], a[N + 5][20];
int f[N + 5];

void init() {
    for (int i = 1, d = -1, st = 1; i <= N; i++) {
        if (i == st) d++, st <<= 1;
        f[i] = d;
    }
}

LL gao(int l, int r) {
    if (l == r) return a[l][0];
    int d = r - l + 1, t = f[d];
    return __gcd(a[l][t], a[r - (1 << t) + 1][t]);
}

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    init();
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> x[i];
        bool flag = 0;
        for (int i = 1; i < n; i++) {
            a[i][0] = x[i] - x[i + 1];
            if (a[i][0] < 0) a[i][0] = -a[i][0];
            if (a[i][0] > 1) flag = 1;
            // cout << a[i][0] << ' ';
        }
        // puts("");
        if (flag == 0) {
            puts("1");
            continue;
        }
        for (int d = 1; d < D; d++) {
            for (int i = 1; i < n; i++) {
                a[i][d] = a[i][d - 1];
                if (n - i > (1 << (d - 1))) {
                    int r = min(n - 1, i + (1 << d) - 1);
                    // cout << "r= " << r << ' ' << a[i][d - 1] << ' ' << a[r - (1 << (d - 1)) + 1][d - 1] << '\n';
                    a[i][d] = __gcd(a[i][d - 1], a[r - (1 << (d - 1)) + 1][d - 1]);
                }
                // cout << "i= " << i << " d= " << d << ' ' << a[i][d] << '\n';
            }
        }
        int l = 1, r = n - 1;
        // while (cin >> l >> r) cout << gao(l, r) << '\n';
        while (l != r) {
            int mid = (l + r) / 2 + 1;
            bool flag = 0;
            for (int i = 1; i + mid - 1 <= n - 1; i++) {
                if (gao(i, i + mid - 1) > 1) {
                    flag = 1;
                    break;
                }
            }
            if (flag) l = mid;
            else r = mid - 1;
        }
        cout << l + 1 << '\n';
    }
    return 0;
}