#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int MOD = 998244353;

int main() {
    // 下面 2 句话是为了让 cin 更快，不理解可以先不写
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 0000
    // 0001
    // 0010
    // 0011
    // 0100
    LL n, m, ans = 0;
    cin >> n >> m;
    for (LL i = 0, d = 1; i < 60; i++, d <<= 1) {
        if (!(m >> i & 1)) continue;
        LL t = d << 1, p = n / t, q = n % t;
        
        ans = (ans + p * d % MOD) % MOD;
        ans = (ans + max(q + 1 - d, 0LL) % MOD) % MOD;
        // cout << "i= " << i << ", p= " << p << ", q= " << q << ", ans= " << ans << '\n';;
    }
    cout << ans << '\n';
    return 0;
}