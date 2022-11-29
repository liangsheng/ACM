#include <bits/stdc++.h>
using namespace std;

int T, n;
string s;

bool ok(string s) {
    int n = s.size();
    for (int i = 0; i < n / 2; i++) {
        if (s[i] != s[n - 1 - i]) return 0;
    }
    return 1;
}

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> s;
        bool flag = 0;
        for (int i = 0; i < s.size(); i++) if (s[i] != 'a') {
            flag = 1;
            break;
        }
        if (!flag) {
            cout << "NO" << '\n';
            continue;
        }
        cout << "YES" << '\n';
        string t = "a" + s;
        if (ok(t)) cout << s + "a" << '\n';
        else cout << "a" + s << '\n';
    }
    return 0;
}