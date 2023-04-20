#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int MOD = 998244353;
const int COMBINATION_SIZE = 1000005;

long long mypow(long long x, long long y, long long mod = MOD){
    long long res=1;
    while(y){
        if(y&1) {
            res = res * x % mod;
        }
        y >>= 1;
        x = x * x % mod;
    }
    return res;
}

struct Combination {
    long long fac[COMBINATION_SIZE], inv[COMBINATION_SIZE];
    bool built = 0;
    void build(){
        assert(MOD >= COMBINATION_SIZE);
        fac[0] = 1;
        for(int i = 1; i < COMBINATION_SIZE; i++) {
            fac[i] = fac[i - 1] * i % MOD;
        }
        inv[COMBINATION_SIZE - 1] = mypow(fac[COMBINATION_SIZE - 1], MOD - 2);
        for(int i = COMBINATION_SIZE - 2; i >= 0; i--) {
            inv[i] = inv[i + 1] * (i + 1) % MOD;
        }
    }
    // long long C(int x, int y){
    //     if(x < 0 || y < 0 || y > x) {
    //         return 0;
    //     }
    //     if(!built) {
    //         built = 1;
    //         build();
    //     }
    //     return fac[x] * inv[y] % MOD * inv[x-y] % MOD;
    // }
    long long C(int a, int b, int y) {
        int x = a * b;
        if(a < 0 || b < 0 || y < 0 || y > x) {
            return 0;
        }
        if(!built) {
            built = 1;
            build();
        }
        return fac[x] * inv[y] % MOD * inv[x-y] % MOD;
    }
} comb;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, k;
    while (cin >> n >> m >> k) {
        LL ans = 0;
        for (int h = 1; h <= n; h++) for (int w = 1; w <= m; w++) {
            if (h * w < k) continue;
            LL d = (n - h + 1) * (m - w + 1);
            LL tmp = comb.C(h, w, k);
            tmp -= comb.C((h - 1), w, k) * 2 + comb.C(h, (w - 1), k) * 2;
            tmp += comb.C((h - 1), (w - 1), k) * 4 + comb.C((h - 2), w, k) + comb.C(h, (w - 2), k);
            tmp -= comb.C((h - 1), (w - 2), k) * 2 + comb.C((h - 2), (w - 1), k) * 2;
            tmp += comb.C((h - 2), (w - 2), k);
            tmp = (tmp % MOD + MOD) % MOD;
            // cout << "h= " << h << ", w= " << w << ", d= " << d << ", tmp= " << tmp << '\n';
            tmp = tmp * d % MOD * h % MOD * w % MOD;
            ans = (ans + tmp) % MOD;
        }
        // cout << "ans= " << ans << '\n';
        LL d = comb.C(n, m, k);
        d = mypow(d, MOD - 2);
        ans = ans * d % MOD;
        cout << ans << '\n';
    }
    return 0;
}