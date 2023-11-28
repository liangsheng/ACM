#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int T;
    long long n;
    cin >> T;
    while (T--) {
        cin >> n;

        // 开始判断素数的逻辑
        bool f = true;
        // 只需要判断到 sqrt(n) 就行了
        for (long long i = 2; i * i <= n; i++) {
            // 找到 n 的一个约数 i, 那么 n 就不是素数
            if (n % i == 0) {
                f = false;
                break;  // 找到一个约数, 就可以提前停止了
            }
        }
        if (f) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}