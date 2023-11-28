#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n;
    int cnt = 0;  // 质因数的个数
    cin >> n;
    cout << n << "=";
    // 枚举 sqrt(n) 以内的数直到 n == 1
    for (int i = 2; i * i <= n && n != 1; i++) {
        while (n % i == 0) {
            cnt++;
            // 第一个质因数不用输出 *
            if (cnt == 1) cout << i;
            else cout << "*" << i;
            n /= i;
        }
    }
    if (n != 1) {
        cnt++;
        if (cnt == 1) cout << n;
        else cout << "*" << n << endl;
    }
    return 0;
}