#include <bits/stdc++.h>
using namespace std;

// 注意: 比较大的数组(比如 10^5 以上), 只能放在全局变量, 不能放在 main 里面
// 使用 vector 的话, 无论多大的数组都能放在 main 里面
int e = 0;         // 质数的个数
int p[100000];     // 存储找到的质数
bool f[1000005];   // 1 表示合数, 0 表示质数
int mp[1000005];   // 表示这个数的一个质因子
int cnt[1000005];  // 表示每个质因子出现的个数

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

        for (int i = 2; i <= n; i++) cnt[i] = 0;
        for (int i = 2; i <= n; i++) {
            int x = i;
            // mp[x] 表示 x 的 1 个质因子, x 如果是质数, mp[x] 就是 x
            // 比如, mp[10] = 5
            // 不断地将 x 除以 mp[x], 就可以将 x 分解质因数
            while (x != 1) {
                cnt[mp[x]]++; 
                x /= mp[x];
            }
        }
        for (int i = 2; i <= n; i++) if (cnt[i] > 0) {
            cout << i << ' ' << cnt[i] << '\n';
        }
    }
    return 0;
}