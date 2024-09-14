#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<bool> w(n + 1, false);             // 列
    vector<bool> x1(2 * n + 1, false);        // 对角线1
    vector<bool> x2(2 * (n - 1) + 1, false);  // 对角线2

    int cnt = 0;
    vector<int> ans(n + 1);
    // 等价于声明函数 void dfs(int p)
    // 这么写的好处是, 可以在 dfs() 里直接使用局部变量, 不需要开全局变量
    function<void(int)> dfs = [&](int p) {
        // 第 1 步: 写终止条件
        if (p == n + 1) {
            cnt++;
            if (cnt <= 3) {
                for (int i = 1; i <= n; i++) cout << ans[i] << " \n"[i == n];
            }
            return ;
        }

        // 第 2 步: 解决当前状态, 然后往下递归
        for (int i = 1; i <= n; i++) {
            if (w[i]) continue;               // 列重复
            if (x1[p + i]) continue;          // 对角线重复
            if (x2[p - i + n - 1]) continue;  // 对角线重复
            ans[p] = i;

            // 标记第 p 行放在第 i 列
            w[i] = 1, x1[p + i] = 1, x2[p - i + n - 1] = 1;
            
            // 向 p + 1 递归
            dfs(p + 1);

            // 还原
            w[i] = 0, x1[p + i] = 0, x2[p - i + n - 1] = 0;
        }
    };

    dfs(1);
    cout << cnt << '\n';

    return 0;
}
