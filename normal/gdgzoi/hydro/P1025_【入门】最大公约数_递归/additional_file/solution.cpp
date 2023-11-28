#include <bits/stdc++.h>
using namespace std;

// 用递归函数求最大公约数
int gcd(int x, int y) {
    // 第一步: 递归函数先写终止条件
    if (x % y == 0) return y;

    // 第二步: 将问题分解成几个小问题
    return gcd(y, x % y);
}

int main() {
    int x, y;
    cin >> x >> y;
    cout << gcd(x, y) << endl;
    return 0;
}