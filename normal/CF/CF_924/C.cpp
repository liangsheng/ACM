#include <bits/stdc++.h>
using namespace std;

set<int> s;

void gao(int n, int x) {
    if ((n - x) % 2) return ;
    int d = (n - x) / 2, l = max(x,2), r = n - 1;
    // printf("d= %d\n", d);
    for (int i = 1; i * i <= d; i++) {
        if (d % i) continue;
        int u = i, v = d / u;
        if (u + 1 >= l && u + 1 <= r) {
            int k = u + 1;
            if (n % (2 * k - 2)) s.insert(k);
        }
        if (v != u && v + 1 >= l && v + 1 <= r) {
            int k = v + 1;
            if (n % (2 * k - 2)) s.insert(k);
        }
    }
}

void hao(int n, int x) {
    if ((n +  x) % 2) return ;
    int d = (n + x) / 2 - 1;
    if (d < 0) return ;
    int l = x + 1, r = n - 1;
    for (int i = 1; i * i <= d; i++) {
        if (d % i) continue;
        int u = i, v = d / u;
        if (u + 1 >= l && u + 1 <= r && v - 1 >= 0) {
            int k = u + 1;
            if (n % (2 * k - 2)) s.insert(k);
        }
        if (v != u && v + 1 >= l && v + 1 <= r && v - 1>= 0) {
            int k = v + 1;
            if (n % (2 * k - 2)) s.insert(k);
        }
    }
}

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    int T, n, x;
    cin >> T;
    while (T--) {
        cin >> n >> x;
        s.clear();
        gao(n, x);
        hao(n, x);
        int ans = s.size(), tmp = 0;
        if (x == 2) {
            for (int i = 1; i * i <= n; i++) {
                if (n % i) continue;
                int u = i, v = n / u;
                if (u % 2 == 0) tmp++;
                if (v != u && v % 2 == 0) tmp++;
            }
        }
        // printf("ans= %d, res= %d, tmp= %d\n", ans, res, tmp);
        cout << ans + tmp << '\n';

        // for (int k = 2; k < n; k++) {
        //     int d = n % (2 * k - 2);
        //     if ((d <= k && x == d)) printf("k= %d\n", k);
        //     if ((d > k && d == 2 * k - x)) printf("kkk= %d, d= %d\n", k, d);
        // }
    }
    return 0;
}