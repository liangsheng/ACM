#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, r;
    cin >> n >> r;

    int m = 0;
    vector<int> ans(n);
    vector<bool> f(n, false);

    // 等价于声明函数 void dfs(int p)
    // 这么写的好处是, 可以在 dfs() 里直接使用局部变量, 不需要开全局变量
    function<void(int)> dfs = [&](int p) {
        // 第 1 步: 写终止条件
        if (m == r) {
            for (int i = 0; i < m; i++) cout << ans[i] + 1 << " \n"[i == m - 1];
            return ;
        }

        // 第 2 步: 解决当前状态, 然后往下递归
        // 选择 p, 题目要求按字典序输出, 所以有限选择 p
        if (m < r) {
            ans[m++] = p;  // 选中
            dfs(p + 1);    // 递归下去
            m--;           // 还原
        }

        // 不要 p, 需要判断如果不要 p 的话后面的数够不够 r 个
        if (n - p - 1 + m >= r) {
            dfs(p + 1);  // 如果后面的数够, 就尝试不要 p
        }
    };

    dfs(0);
    return 0;
}
