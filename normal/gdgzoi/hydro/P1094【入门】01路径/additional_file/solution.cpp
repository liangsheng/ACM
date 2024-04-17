#include <bits/stdc++.h>
using namespace std;
 
int main() {
    // 下面 2 句话是为了让 cin 更快，不理解可以先不写
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T, n;
    cin >> T;
    while (T--) {
        cin >> n;
        vector<string> s(2);
        cin >> s[0] >> s[1];
        int p = 0, ans = 1;
        for (int i = 1; i < n; i++) {
            if (s[0][i] == s[1][i - 1]) ans++;
            else if (s[0][i] < s[1][i - 1]) p = i, ans = 1;
            else break;
        }
        for (int i = 0; i <= p; i++) cout << s[0][i];
        for (int i = p; i < n; i++) cout << s[1][i];
        cout << '\n' << ans << '\n';
    }
    return 0;
}