#include <bits/stdc++.h>
using namespace std;

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    int T, n;
    string s;
    cin >> T;
    while (T--) {
        cin >> s;
        n = s.size();
        int p = -1;
        for (int i = 0; i < n - 1; i++) if (s[i] + s[i + 1] - '0' * 2 >= 10) p = i;
        // cout << "p= " << p << '\n';
        if (p != -1) {
            string ans = s;
            int d = s[p] + s[p + 1] - '0' * 2;
            ans[p] = '1';
            ans[p + 1] = d % 10 + '0';
            cout << ans << '\n';
            continue;
        }
        string ans = s.substr(2, n - 2), d;
        d.push_back(s[0] + s[1] - '0');
        cout << d + ans << '\n';
    }
    return 0;
}