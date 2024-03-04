#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long LL;
 
int main() {
    // 这两句是为了让 cin 和 cout 更快, 可以不写
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T, n;
    string s1, s2;
    cin >> T;
    while (T--) {
        cin >> n;
        cin >> s1 >> s2;
        vector<int> c(2, 0), d(2, 0);
        for (int i = 0; i < n; i++) c[s1[i] - '0']++;
        for (int i = 0; i < n; i++) d[s2[i] - '0']++;
        
        // 你不会把选中同一个位置 2 遍
        // s = 0011
        // 选 i = 3：s = 1110
        // 选 i = 1：s = 1001
        // 选 i = 4：s = 0111
        // 选 i = 3：s = 1010
        // 不如这样:
        // 选 i = 4：s = 1101
        // 选 i = 1：s = 1101
        // 所以每个位置最多选中 1 遍
        // 假设字字符串中 1 的个数是 x, 0 的个数是 y
        // 那么操作一次后 1 的个数是 y + 1, 0 的个数是 x - 1
        // 再操作一次后 1 的个数是 x, 0 的个数是 y
        int ans = n + 1;
        vector<int> f(2, 0);
        // 操作了奇数次
        if (d[1] == c[0] + 1) {
            // 操作了奇数次的话, 没被选中的取反, 选中的不变
            for (int i = 0; i < n; i++) if (s1[i] == s2[i]) f[s1[i] - '0']++;
            // 这些选中的位置在原字符串中应该是 10101 这样, 1 的个数比 0 的个数多 1
            if (f[1] == f[0] + 1) ans = f[0] + f[1];
        }
 
        // 操作了偶数次
        if (d[1] == c[1]) {
            f[0] = 0, f[1] = 0;
            // 操作了偶数次的话, 没被选中的不变, 选中的取反
            for (int i = 0; i < n; i++) if (s1[i] != s2[i]) f[s1[i] - '0']++;
            // 这些选中的位置在原字符串中应该是 1010 这样, 1 的个数和 0 的个数相同
            if (f[1] == f[0]) ans = min(ans, f[0] + f[1]);
        }
 
        if (ans == n + 1) ans = -1;
        cout << ans << '\n';
    }
    return 0;
}