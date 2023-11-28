#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int MOD = 998244353;

// 返回 x^y
long long power(long long  x, long long y) {
    // 第一步: 递归函数先写终止条件
    if (y == 0) return 1;

    // 第二步: 将问题分解成几个小问题
    long long d = power(x, y / 2);
    // 如果 y 是偶数, 比如: 2^6=(2^3)^2
    if (y % 2 == 0) return d * d % MOD;
    // 如果 y 是奇数, 比如: 2^7=(2^3)^2*2
    return d * d % MOD * x % MOD;
}

long long gao(long long x, long long n) {
    if (x == 1) return n + 1;

    long long ans = power(x, n + 1);
    ans = ((ans - 1) % MOD + MOD) % MOD;
    long long d = power(x - 1, MOD - 2);
    ans = ans * d % MOD;
    return ans;
}

long long solve(long long x, long long n) {
    if (n == 0) return 1;

    long long d = power(x, (n + 1) / 2);
    long long ans = solve(x, n / 2) * (1 + d) % MOD;
    if (n % 2 == 0) {
        ans = ((ans - d) % MOD + MOD) % MOD;
    }
    return ans;
}

int main() {
    long long x, n;
    cin >> x >> n;
    cout << solve(x, n) << endl;
    return 0;
}