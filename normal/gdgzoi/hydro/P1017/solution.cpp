#include <bits/stdc++.h>
using namespace std;

int e = 0;        // 质数的个数
int p[100000];    // 存储找到的质数
bool f[1000005];  // 1 表示合数, 0 表示质数
int mp[1000005];  // 表示这个数的一个质因子

int main() {
    int n;
    while (cin >> n) {
        // 质数的个数
        e = 0;  
        // 初始 f 都是 0
        for (int i = 2; i <= n; i++) f[i] = 0;

        for (int i = 2; i <= n; i++) {
            // 是合数就 continue
            if (f[i]) continue;
            // 找到 1 个质数
            p[e++] = i;
            // 那么 i 的倍数都是合数
            for (int j = i; j <= n; j += i) {
                f[j] = 1;
                mp[j] = i;
            }
        }
        for (int i = 0; i < e; i++) cout << p[i] << ' ';
        cout << endl;
    }
    return 0;
}