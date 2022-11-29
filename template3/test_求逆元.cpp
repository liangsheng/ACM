#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int MOD = 1000000007;
const int COMBINATION_SIZE = 100005;

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
    long long C(int x, int y){
        if(y < 0 || y > x) {
            return 0;
        }
        if(!built) {
            built = 1;
            build();
        }
        return fac[x] * inv[y] % MOD * inv[x-y] % MOD;
    }
} comb;

int INV(int a) {
     if (a == 1) return 1;
     return ((-(MOD / a) * INV(MOD % a)) % MOD);
}

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    int T, n, x, y;
    cin >> T;
    while (T--) {
        cin >> n >> x >> y;
        
        LL ans = 0;
        vector<LL> X(n + 1, 1), Y(n + 1, 1);
        for (int i = 1; i <= n; i++) {
            X[i] = X[i - 1] * x % MOD;
            Y[i] = Y[i - 1] * y % MOD;
        }
        for (int k = 0; k <= n; k++) {
            ans = (ans + comb.C(n, k) * X[k] % MOD * Y[n - k] % MOD) % MOD;
        }
        cout << ans << '\n';
    }
    return 0;
}