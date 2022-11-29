#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T, n;
    string s;
    cin >> T;
    while (T--) {
        cin >> n;
        cin >> s;
        int x = 0, y = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '0') x++;
            else y++;
        }
        LL ans = (LL) x * y;
        for (int i = 0; i < s.size(); i++) {
            int j = i;
            while (i + 1 < s.size() && s[i + 1] == s[j]) i++;
            ans = max(ans, (LL) (i - j + 1) * (i - j + 1));
        }
        cout << ans << '\n';
    }
    return 0;
}