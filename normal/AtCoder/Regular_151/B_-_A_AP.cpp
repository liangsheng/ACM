#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int MOD = 998244353, M = 499122177;

template <typename T>
T inverse(T a, T m) {
    T u = 0, v = 1;
    while (a != 0) {
        T t = m / a;
        m -= t * a; swap(a, m);
        u -= t * v; swap(u, v);
  }
  assert(m == 1);
  return u;
}

int main() {
    // cout << inverse(2, MOD) + MOD << '\n';
    ios::sync_with_stdio(false);
    cin.tie(0);
    LL n, m;
    while (cin >> n >> m) {
        vector<int> p(n + 1);
        for (int i = 1; i <= n; i++) cin >> p[i];

        LL d = 1;
        vector<int> f(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            if (f[i]) continue;
            int x = i;
            while (!f[x]) f[x] = 1, x = p[x];
            d = d * m % MOD;
        }
        LL ans = 1;
        for (int i = 1; i <= n; i++) ans = ans * m % MOD;
        ans = ((ans - d) % MOD * M % MOD + MOD) % MOD;
        cout << ans << '\n';
    }
    return 0;
}
