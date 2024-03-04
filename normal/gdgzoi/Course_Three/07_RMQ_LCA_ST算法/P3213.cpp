#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int MOD = 998244353;

LL kpow(LL x, LL y) {
    LL ans = 1;
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
    while (cin >> n) {
        vector<LL> a(n + 1, 0), b(n + 2, 0);
        LL pre = 0, inv = kpow(n - 1, MOD - 2);
        // cout << "inv= " << inv << '\n';
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            b[i - 1]= (a[i] + pre) * inv % MOD;
            pre = (pre + b[i - 1]) % MOD;
        }
        for (int i = n - 2; i >= 1; i--) b[i] = (b[i] + b[i + 1]) % MOD;
        for (int i = 1; i <= n; i++) cout << b[i] << " \n"[i == n];
    }
    return 0; 
}