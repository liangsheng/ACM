#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, x;
    bool f[105];
    while (cin >> n >> m) {
        // 初始 f[i] = 0, 表示都没出圈
        for (int i = 1; i <= n; i++) f[i] = 0;
        
        // now 表示当前编号, cnt 表示已经出圈的人数
        int now = 1;
        for (int k = 1; k <= n; k++) {
            int t = 0;  // 本次人数
            while (true) {
                if (f[now] == 0) t += 1;
                // 找到 m 个没有出圈的人
                if (t == m) {
                    f[now] = 1;
                    cout << now << ' ';
                    break;
                }
                now += 1;
                if (now > n) now = 1;  // 转了一圈
            }
        }
        cout << '\n';
    }
    return 0;
}