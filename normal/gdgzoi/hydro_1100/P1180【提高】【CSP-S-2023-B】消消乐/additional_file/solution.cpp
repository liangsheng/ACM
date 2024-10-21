#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n;
    string s;
    cin >> n >> s;
    
    // p[c][i]: 从 [p[c][i] + 1, i] 是可消除的, s[p[c][i]] 是字符 c
    vector<vector<int>> p(26, vector<int>(n + 1, -1)); 
    
    // cnt[i]: 以 s[i] 结尾的可消除的连续子串的个数, 从 i = 1 开始编号
    vector<int> cnt(n + 1, 0);
    p[s[0] - 'a'][1] = 1;
    for (int i = 2; i <= n; i++) {
        int id = s[i - 1] - 'a';
        // 中间可以消一段
        if (p[id][i - 1] > 0) {
            cnt[i] = 1 + cnt[p[id][i - 1] - 1];
            for (int c = 0; c < 26; c++) p[c][i] = p[c][p[id][i - 1] - 1];
        }
        p[s[i - 1] - 'a'][i] = i;
    }

    i64 ans = 0;
    for (int i = 1; i <= n; i++) ans += cnt[i];
    cout << ans << '\n';

    return 0;
}