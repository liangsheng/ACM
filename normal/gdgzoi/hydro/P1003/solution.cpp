#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    // 用于交换
    int t;
    // 如果 b < a, 交换 a, b
    if (b < a) {
        t = a;
        a = b;
        b = t;
    }
    // 如果 c < a, 交换 a, c
    if (c < a) {
        t = a;
        a = c;
        c = t;
    }
    // 此时 a 已经是最小值了
    // 如果 c < b, 交换 b, c
    if (c < b) {
        t = b;
        b = c;
        c = t;
    }
    cout << a << ' ' << b << ' ' << c << endl;
    return 0;
}