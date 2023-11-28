#include <bits/stdc++.h>
using namespace std;

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

int main() {
    long long x, y;
    cin >> x >> y;
    cout << power(x, y) << endl;
    return 0;
}