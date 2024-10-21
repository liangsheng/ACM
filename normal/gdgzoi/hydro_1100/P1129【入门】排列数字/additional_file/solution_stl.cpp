#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> ans(n);
    for (int i = 0; i < n; i++) ans[i] = i + 1;

    // 参考 STL 算法: https://oiwiki.org/lang/csl/algorithm/
    // next_permutation(ans.begin(), ans.end())
    // 用于将 ans 处理成字典序变大的下一个排列, 然后返回 true
    // 如果 ans 的字典序已经最大, 就返回 false
    do {
        for (int i = 0; i < n; i++) cout << ans[i] << " \n"[i == n - 1];
    } while (next_permutation(ans.begin(), ans.end()));

    return 0;
}
