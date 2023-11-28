#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n = 1;
    double ans = 0.0;
    // for 的终止条件如果不写, 表示程序不断运行, 直到 break
    for (int i = 1; ; i++) {
        // 这里不能用 1 / i !!
        ans += 1.0 / i;
        if (ans >= 10) {
            n = i;
            break;
        }
    }
    cout << n << endl;
    return 0;
}