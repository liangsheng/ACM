#include <bits/stdc++.h>
using namespace std;
 
int main() {
    // 用来统计有多少个水仙花数 
    int cnt = 0;
    // 从 100 到 999 枚举所有的三位数 
    for (int i = 100; i <= 999; i++) {
        // 个位数, 直接模 10, 比如 125 % 10 = 5
        int x = i % 10;
        // 十位数, 先除 10 再模 10, 比如 125 / 10 % 10 = 2
        int y = i / 10 % 10;
        // 十位数, 先除 100 再模 10, 比如 125 / 100 % 10 = 2
        int z = i / 100 % 10;
         
        // 找到 1 个水仙花数 
        if (x * x * x + y * y * y + z * z * z == i) {
            cnt = cnt + 1;
            // 如果是第一个水仙花数, 直接输出 i
            if (cnt == 1) cout << i;
            // 如果不是第一个水仙花数, 先输出空格, 在输出 i 
            else cout << ' ' << i;
        }
    }
    cout << endl;
    return 0;
}