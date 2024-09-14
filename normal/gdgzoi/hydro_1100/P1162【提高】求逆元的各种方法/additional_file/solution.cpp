#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

// 各种方法求逆元: https://www.luogu.com.cn/article/2ooix0rj

/*--------------------------------- 扩展欧几里得求逆元 begin -----------------------------------------*/
// https://www.luogu.com.cn/record/170717964
// 909ms

using i64 = long long;

// xa + yb = gcd(a, b)
// |x| <= b, |y| <= a
template<typename T>
T extgcd(T a, T b, T &x, T &y) {
    if (!b) {
        x = 1, y = 0;
        return a;
    }
    // x1 = y2
    // y1 = x2 - (a / b) * y2
    // 注意这里 x, y 反过来了
    T g = extgcd(b, a % b, y, x);
    y -= a / b * x;
    return g;
}

template<typename T>
T get_inv(T a, T b) {
    T x, y;
    T d = extgcd(a, b, x, y);
    if (d != 1) return -1;  // a, b 必须互质
    return (x % b + b) % b;
}

// https://leetcode.cn/contest/weekly-contest-410/ranking/
// 来自 leetcode_410, rank_1 Relaxed Visvesvaraya 的代码
template <typename T>
T inverse(T a, T m) {
    T u = 0, v = 1, M = m;
    while (a != 0) {
        T t = m / a;
        m -= t * a; swap(a, m);
        u -= t * v; swap(u, v);
    }
    return (u % M + M) % M;
}
/*--------------------------------- 扩展欧几里得求逆元 end -------------------------------------------*/

/*--------------------------------- 费马小定理求逆元 begin -------------------------------------------*/
// https://www.luogu.com.cn/record/170715949
// 1141ms

// (a ^ (p - 1)) % p = 1, (a, p) = 1, p 是质数
// n > 0
i64 power(i64 x, i64 n, int P = 998244353) {
    i64 ans = x; n--;
    for (; n > 0; n >>= 1, x = x * x % P) if (n & 1) ans = ans * x % P;
    return ans;
}
/*--------------------------------- 费马小定理求逆元 end ---------------------------------------------*/

/*--------------------------------- 线性求逆元 begin ------------------------------------------------*/
// https://www.luogu.com.cn/record/170721077
// 307ms

vector<int> get_inv_linear(int n, int P = 998244353) {
    vector<int> inv(n + 1, 1);
    inv[0] = inv[1] = 1;
    for(int i = 2; i <= n; ++i) {
        inv[i] = (i64) (P - P / i) * inv[P % i] % P;
    }
    return inv;
}

/*--------------------------------- 线性求逆元 end --------------------------------------------------*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, p;
    cin >> n >> p;

    // 扩展欧几里得求逆元, 909ms
    // for (int i = 1; i <= n; i++) cout << get_inv(i, p) << '\n';
    for (int i = 1; i <= n; i++) cout << inverse(i, p)<< '\n';

    // 费马小定理求逆元, 1141ms
    // for (int i = 1; i <= n; i++) cout << power(i, p - 2, p) << '\n';

    // 线性求逆元
    // vector<int> inv = get_inv_linear(n, p);
    // for (int i = 1; i <= n; i++) cout << inv[i] << '\n';
    return 0;
}