#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int MOD = 998244353;
const int COMBINATION_SIZE = 100005;
int N;

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
    void build(){
        fac[0] = 1;
        for(int i = 1; i < N; i++) {
            fac[i] = fac[i - 1] * i % MOD;
        }
        inv[N - 1] = mypow(fac[N - 1], MOD - 2);
        for(int i = N - 2; i >= 0; i--) {
            inv[i] = inv[i + 1] * (i + 1) % MOD;
        }
    }
    long long C(int x, int y){
        if(y < 0 || y > x) {
            return 0;
        }
        return fac[x] * inv[y] % MOD * inv[x-y] % MOD;
    }
} comb;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    LL n;
    while (cin >> n) {
        vector<LL> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        N = n / 3 + 1;
        comb.build();
        // cout << comb.C(4, 2) << '\n';
        LL ans = comb.C(n / 3, n / 3 / 2);
        for (int i = 0; i < n / 3; i++) {
            vector<LL> b(3);
            b[0] = a[i * 3];
            b[1] = a[i * 3 + 1];
            b[2] = a[i * 3 + 2];
            sort(b.begin(), b.end(), greater<int>());
            // cout << b[0] << ' ' << b[1] << ' ' << b[2] << '\n';
            if (b[1] > b[2]) continue;
            if (b[0] == b[1]) ans = ans * 3 % MOD;
            else if (b[1] == b[2]) ans = ans * 2 % MOD;
        }
        cout << ans << '\n';
    }
    return 0;
}