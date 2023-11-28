#include <bits/stdc++.h>
using namespace std;

const long long INF = 1000000000000000000LL;

// x < y 的情况
long long fun(long long x, long long  y) {
    // // 第一步: 递归函数先写终止条件
    // if (x == y) return 0;

    // // 第一步: 递归函数先写终止条件
    // // 直接全部 +1
    // long long ans = y - x;
    // // 第 1 种情况: 以后不会再 *2 了
    // if (x * 2 > y) return ans;
    // // 第 2 种情况: 直接 * 2
    // ans = min(ans, fun(x * 2, y) + 1);
    // // 第 3 种情况: x = x * 2 + 1
    // if ((x + 1) * 2 <= y) {
    //     ans = min(ans, fun(x * 2 + 1, y) + 2); 
    // }
    // return ans;

    cout << "x= " << x << ", y= " << y << '\n';
    if (x == y) return 0;
    if (x * 2 > y) return y - x;
    if (y & 1) return min(y - x, fun(x, (y - 1) / 2) + 2);
    return min(y - x, fun(x, y / 2) + 1);
}

long long solve(long long x, long long  y) {
    // // 第一步: 递归函数先写终止条件
    // if (x == y) return 0;
    // if (x < y) return fun(x, y);

    // // 第二步: 将问题分解成几个小问题
    // long long ans = INF;
    // // 第 1 种情况: 直接 / 2
    // if (x % 2 == 0) ans = min(ans, solve(x / 2, y) + 1);
    // else {
    //     // 第 2 种情况: 先 +1, 再 / 2
    //     ans = min(ans, solve((x + 1) / 2, y) + 2);
    // }
    // return ans;

    long long d = INF;
    if (x < y) d = fun(x, y);
    if (x % 2 == 0) return min(d, solve(x / 2, y) + 1);
    return min(d, solve((x + 1) / 2, y) + 2);
}

int main() {
    long long T, x, y;
    cin >> T;
    while (T--) {
        cin >> x >> y;
        cout << solve(x, y) << endl;
    }
    return 0;
}