#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
 
const int P = 998244353;
 
LL power(LL x, LL y, LL P) {
    LL res = 1;
    while (y) {
        if (y & 1) res = (LL) res * x % P;
        x = (LL) x * x % P; y >>= 1;
    } 
    return res;
}
 
/**
 * 题意：输入 n 和 k, k 是 2 的幂, 求 \sigma{k|i, 0<=i<=n}C(n, i)
 * 结果对 998244353 取模(1 <= n <= 10^15, 1 <= k <= 2^20)
 * Sample Input:
 * 5 2
 * Sample Output:
 * 16
 * 解释: C(5, 0) + C(5, 2) + C(5, 4) = 16
 * 题解: 见 oiwiki 里面的 fft, https://oi-wiki.org/math/poly/fft/
 * 令 f(x) = (1 + x) ^ n, 求 f(x) 在 k 个 k 次单位复根的值, 然后求和, 然后除 k
 */
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
     
    LL n, k;
    while (cin >> n >> k) {
        // k 次原根 v = g ^ ((p - 1) / k)
        int v = power(3, (P - 1) / k, P);
        vector<LL> w(k, 1);
        for (int i = 1; i < k; i++) w[i] = w[i - 1] * v % P;
 
        // (1 + w[i]) ^ n
        LL ans = 0;
        for (int i = 0; i < k; i++) {
            LL tmp = power(1 + w[i], n, P);
            ans = (ans + tmp) % P;
        }
        cout << ans * power(k, P - 2, P) % P << '\n';
    }
    return 0;
}