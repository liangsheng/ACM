#include <bits/stdc++.h>
using namespace std;

int solve(int n, string A, string B, string C) {
    // 第一步: 递归函数先写终止条件
    if (n == 1) {
        cout << A << "->" << C << endl;
        return 1;
    }
    // 第二步: 将问题分解成几个小问题
    // 那么必须先将 n-1 个小的圆盘，借助柱子 C，有柱子A 移动到柱子 B
    int ans = solve(n - 1, A, C, B);
    // 在将最大的圆盘从柱子 A，移动到柱子 C
    cout << A << "->" << C << endl; 
    // 最后将 n-1 个小的圆盘，借助柱子 A，由柱子 B移动到柱子 C
    int res = solve(n - 1, B, A, C);
    return ans + 1 + res;
}

int main() {
    int n;
    cin >> n;
    int ans = solve(n, "A", "B", "C");
    cout << ans << endl;
    return 0;
}