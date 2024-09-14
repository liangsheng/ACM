#include <bits/stdc++.h>
using namespace std;

/*--------------------------------- 扩展欧几里得 begin ---------------------------------------------*/
// 来自: https://www.cnblogs.com/WIDA/p/17633758.html#05---%E6%89%A9%E5%B1%95%E6%AC%A7%E5%87%A0%E9%87%8C%E5%BE%97exgcd
// 来自: https://oi-wiki.org/math/number-theory/gcd/#%E6%89%A9%E5%B1%95%E6%AC%A7%E5%87%A0%E9%87%8C%E5%BE%97%E7%AE%97%E6%B3%95

template<typename T>
T gcd(T a, T b) {
    return b ? gcd(b, a % b) : a;
}

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

/*--------------------------------- 扩展欧几里得 end -----------------------------------------------*/

using i64 = long long;

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);

    i64 T, a, b, c, x, y;
    cin >> T;
    while (T--) {
        cin >> a >> b >> c;
        i64 d = extgcd(a, b, x, y);
        if (c % d) cout << -1 << '\n';
        else {
            // x1, y1 是一组解
            i64 x1 = c / d * x, y1 = c / d * y;

            // dx, dy 是通解的步长
            // 通解为: 
            // x = x1 + k * dx
            // y = y1 - k * dy
            i64 dx = b / d, dy = a / d;

            // 将 x1 调整为最小正整数
            i64 k = ceil(1.0 * (1 - x1) / dx);
            x1 += k * dx, y1 -= k * dy;

            // 有正整数解
            if (y1 > 0) {
                // 解的个数
                i64 cnt = (y1 - 1) / dy + 1;

                // x 的最小值就是 x1

                // y 的最小值是 y - cnt * dy

                // x 的最大值是 x1 + cnt * dx

                // y 的最大值是 y1
                
                cout << cnt << ' ' << x1 << ' ' << y1 - (cnt - 1) * dy << ' ' << x1 + (cnt - 1) * dx << ' ' << y1 << '\n';
            } else {
                // 将 y1 调整到最小正整数需要多少 dy
                i64 cnt = ceil(1.0 * (1 - y1) / dy);
                cout << x1 << ' ' << y1 + cnt * dy << '\n';
            }
        }
    }
    return 0;
}