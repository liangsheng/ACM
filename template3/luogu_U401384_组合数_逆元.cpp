#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

/**
 * 题目: https://www.luogu.com.cn/problem/U401384?contestId=156913 
 * 计算组合数
 */
/*----------------------------- 计算组合数 begin -------------------*/
const int MOD = 1000000007;

LL mypow(LL x, LL y, LL mod = MOD){
    LL res = 1;
    while (y){
        if (y & 1) res = res * x % mod;
        y >>= 1;
        x = x * x % mod;
    }
    return res;
}

vector<int> fac, inv;
void init(int n) {
    fac = vector<int>(n + 1, 1), inv = vector<int>(n + 1, 1);
    fac[1] = 1;
    for (int i = 2; i <= n; i++) fac[i] = (LL) fac[i - 1] * i % MOD;
    inv[n] = mypow(fac[n], MOD - 2);
    for (int i = n - 1; i >= 1; i--) {
        inv[i] = (LL) inv[i + 1] * (i + 1) % MOD;
    }
}

int C(int x, int y) {
    return (LL) fac[x] * inv[y] % MOD * inv[x - y] % MOD;
}
/*----------------------------- 计算组合数 end ---------------------*/

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    init(100000);
    // cout << C(4, 2) << '\n';
    int n, q, t, x;
    cin >> n >> q;
    while (q--) {
        cin >> t >> x;
        x = abs(x - n);
        int l = t % 2, r = t;
        if (x > r || (x % 2 != t % 2)) cout << 0 << '\n';
        else {
            int id = t - (r - x) / 2;
            cout << C(t, id) << '\n';
        }
    }
    return 0;
}