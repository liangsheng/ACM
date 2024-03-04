#include <bits/stdc++.h>
using namespace std;

/*------------------ 扩展 KMP begin ---------------------------------*/
// https://oi-wiki.org/string/z-func/
// 对于个长度为 n 的字符串 s。
// 定义函数 z[i] 表示 s 和 s[i, n-1]（即以 s[i] 开头的后缀）的最长公共前缀（LCP）的长度。
// z 被称为 s 的 Z 函数。特别地，z[0] = 0。
// z(aaaaa) = [0, 4, 3, 2, 1]
// z(aaabaab) = [0, 2, 1, 0, 2, 1, 0]
// z(abacaba) = [0, 0, 1, 0, 3, 0, 1]
vector<int> z_function(string s) {
    int n = (int) s.size();
    vector<int> z(n, 0);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r && z[i - l] < r - i + 1) z[i] = z[i - l];
        else {
            z[i] = max(0, r - i + 1);
            while (i + z[i] < n && s[z[i]] == s[i + z[i]]) ++z[i];
        }
        if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
    }
    return z;
}
/*------------------ 扩展 KMP end ---------------------------------*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s, t;
    int q, p;
    cin >> s >> t;
    string ts = t + '#' + s;
    vector<int> z = z_function(ts);
    cin >> q;
    while (q--) {
        cin >> p;
        cout << z[t.size() + p] << '\n';
    }
    return 0;
}