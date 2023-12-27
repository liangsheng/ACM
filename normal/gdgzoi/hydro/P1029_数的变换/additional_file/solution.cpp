#include <bits/stdc++.h>
using namespace std;
typedef long long LL;  // typedef 表示 long long 简写成 LL

// INF = 9223372036854775807, 是 long long 的最大值
// const 表示变量 INF 不可变
// 不可变的变量一般用全大写表示
const LL INF = numeric_limits<LL>::max();

// 当 x < y 时需要的最少次数
LL fun(LL x, LL y) {
    // 第一步: 递归函数先写终止条件
    if (x == y) return 0;
 
    // 第一步: 递归函数先写终止条件
    // 直接全部 +1
    LL ans = y - x;
    // 以后不会再 *2 了
    if (x * 2 > y) return ans;
    // 当 y 是奇数时: 最后 2 步是 *2 和 +1
    if (y % 2 == 1) {
      LL tmp = fun(x, (y - 1) / 2) + 2;
      ans = min(ans, tmp);
    } else {
        // 当 y 是偶数时: 最后 1 步是 *2
        LL tmp = fun(x, y / 2) + 1;
        ans = min(ans, tmp);
    }
    return ans;
}

// 将 x 变换 y 的最少次数
LL solve(LL x, LL y) {
    // 第一步: 递归函数先写终止条件
    if (x == y) return 0;
    if (x == 1) return fun(x, y);
    LL ans = INF;
    if (x < y) ans = fun(x, y);  // 当 x < y 时, 调用 fun(x, y)

    // 第二步: 将问题分解成几个小问题
    // 第 1 种情况: 直接 / 2
    if (x % 2 == 0) {
        LL tmp = solve(x / 2, y) + 1;
        return min(ans, tmp);
    }
    // 第 2 种情况: 先 +1, 再 / 2
    LL tmp = solve((x + 1) / 2, y) + 2;
    return min(ans, tmp);
}

LL gao(LL x, LL y) {
    LL ans = INF;

    // 情况 1、从 x 一直 +1 直到 y
    if (x <= y) ans = min(ans, y - x);

    if (y % 2 == 0) ans = min(ans, solve(x, y / 2) + 1);
    else ans = min(ans, solve(x, (y + 1) / 2) + 2);

    if (x % 2 == 0) ans = min(ans, solve(x / 2, y) + 1);
    else ans = min(ans, solve((x + 1) / 2, y) + 2);
    return ans;
}

int main() {
    LL T, x, y;
    cin >> T;
    while (T--) {
        cin >> x >> y;
        cout << gao(x, y) << endl;
    }
    return 0;
}