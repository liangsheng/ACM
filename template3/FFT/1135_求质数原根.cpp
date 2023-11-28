#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int power(int x, int y, int P = 998244353) {
    int res = 1;
    while (y) {
        if (y & 1) res = (LL) res * x % P;
        x = (LL) x * x % P; y >>= 1;
    } 
    return res;
}

/**
 * 计算素数 p 的原根
 * 原根往往不大（一般不会超过 300）, 可以枚举判断, 判断过程
 * 1、对于枚举的 g, 枚举 p - 1 的所有质因子 p_i
 * 2、如果所有的 p_i, g ^ ((p - 1) / p_i) = 1(mod p) 都不成立
 * 3、那么 g 就是原根
 */
int gao(int p) {
    if (p == 2) return 2;
    int x = p - 1;

    // 1、首先计算出 p 的所有质因子 p_i
    vector<int> pi;
    for (int i = 2; i * i <= x; i++) if (x % i == 0) {
        pi.push_back(i);
        while (x % i == 0) x /= i;
    }
    if (x != 1) pi.push_back(x);

    // 2、枚举 g
    // 如果所有的 p_i, g ^ ((p - 1) / p_i) = 1(mod p) 都不成立, 则 g 是元根
    for (int g = 2; g < p; g++) {
        bool f = true;
        for (int p_i : pi) if (power(g, (p - 1) / p_i, p) == 1) {
            f = false;
            break;
        }
        if (f) return g;
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int p;
    while (cin >> p) cout << gao(p) << '\n';
    return 0;
}