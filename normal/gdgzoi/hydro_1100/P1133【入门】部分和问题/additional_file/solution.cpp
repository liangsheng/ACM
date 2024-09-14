#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    // 等价于声明函数 bool dfs(int p)
    // 这么写的好处是, 可以在 dfs() 里直接使用局部变量, 不需要开全局变量
    function<bool(int, int)> dfs = [&](int p, int s) {
        // 第 1 步: 写终止条件
        if (p == n) return s == k;

        // 第 2 步: 解决当前状态, 然后往下递归
        // 选择 a[p]
        if (dfs(p + 1, s + a[p])) return true;

        // 不要 a[p]
        if (dfs(p + 1, s)) return true;

        // 选和不选都不行的话, 就返回 false
        return false;
    };

    cout << (dfs(0, 0) ? "Yes" : "No") << '\n';
    return 0;
}
