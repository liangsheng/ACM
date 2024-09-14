#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int m = 0;
    vector<int> ans(n);
    vector<bool> f(n, false);

    // 等价于声明函数 void dfs(int p)
    // 这么写的好处是, 可以在 dfs() 里直接使用局部变量, 不需要开全局变量
    function<void(int)> dfs = [&](int p) {
        // 第 1 步: 写终止条件
        if (p == n) {
            for (int i = 0; i < n; i++) cout << ans[i] + 1 << " \n"[i == n - 1];
            return ;
        }

        // 第 2 步: 解决当前状态, 然后往下递归
        for (int i = 0; i < n; i++) if (!f[i]) {
            // 找到还没用过的 i, 添加到 ans
            ans[m++] = i;

            // 将 i 标记为使用过
            f[i] = true;

            // 往下递归
            dfs(p + 1);

            // 本次递归结束后, 还原状态
            m--, f[i] = 0;
        }
    };

    dfs(0);
    return 0;
}
