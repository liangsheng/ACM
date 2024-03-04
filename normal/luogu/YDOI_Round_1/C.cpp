#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int MOD = 1000000007;

int qpow(int x, LL y) {
    int ans = 1;
    while (y) {
        if (y & 1) ans = (LL) ans * x % MOD;
        x = (LL) x * x % MOD;
        y >>= 1;
    }
    return ans;
}

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);

    int n;
    LL s = 0;
    cin >> n;
    vector<int> a(n), v(n);
    for (int i = 0; i < n; i++) cin >> a[i], s += a[i];
    for (int i = 0; i < n; i++) cin >> v[i];
    
    // sum(2^(s - a[i]) * ((1 + v[i])^a[i] - 1))
    int ans = 0;
    for (int i = 0; i < n; i++) {
        LL x = qpow(2, s - a[i]);
        LL y = qpow(1 + v[i], a[i]) - 1;
        if (y < 0) y += MOD;
        ans = (ans + (LL) x * y % MOD) % MOD;
    }
    cout << ans << '\n';
    return 0;
}