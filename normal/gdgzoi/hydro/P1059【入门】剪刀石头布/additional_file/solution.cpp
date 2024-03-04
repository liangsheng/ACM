#include <bits/stdc++.h>
using namespace std;

int main() {
    // 下面 2 是为了让 cin, cout 更快, 不理解可以先不写
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T, n;
    string s;
    cin >> T;
    while (T--) {
        cin >> n;
        cin >> s;
        string ans = s;
        int now = 0, m = n / 2 + 1;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'R') now++, ans[i] = 'P';
            else if (s[i] == 'S') {
                if (n - 1 - i + now >= m) ans[i] = 'P';
                else now++, ans[i] = 'R';
            } else if (s[i] == 'P') {
                if (n - 1 - i + now >= m) ans[i] = 'P';
                else now++, ans[i] = 'S';
            }
        }
        cout << ans << '\n';
    }
	return 0;
}