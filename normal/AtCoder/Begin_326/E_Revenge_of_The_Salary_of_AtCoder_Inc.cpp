#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int P = 998244353;

vector<LL> inv, f;

//线性求到a的逆元 
void INV(LL a, LL p) {
    inv[1] = 1;
    for (int i = 2; i <= a; ++i) {
        inv[i] = ((-(p / i)) * inv[p % i] % p + p) % p; 
    }
}

//2、单独求某个值的逆元
LL INV(LL a) {
     if (a == 1) return 1;
     return (((-(P / a) * INV(P % a)) % P) + P) % P;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    while (cin >> n) {
        vector<LL> a(n + 1);
        for (int i = 1; i <= n; i++) cin >> a[i];

        inv = vector<LL>(n + 1);
        INV(n, P);

        f = vector<LL>(n + 1, 0);
        LL t = 1;
        for (int i = 1; i <= n; i++) {
            t = t * inv[n] % P;
            f[i] = f[i - 1] + t;
        }

        vector<LL> dp(n + 1);
        dp[1] = (LL) a[1] * inv[n] % P;
        LL now = 0;
        for (int i = 1; i <= n; i++) {
            dp[i] = (now + f[i] * a[i]) % P;
            now = ((LL) now + dp[i]) % P;
            cout << "i= " << i << ", dp[i]= " << dp[i] << ", now= " << now << '\n';
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            ans = (ans + (LL) dp[i] * inv[n] % P * i % P) % P;
        }
        cout << ans << '\n';
    }
    return 0;
}
