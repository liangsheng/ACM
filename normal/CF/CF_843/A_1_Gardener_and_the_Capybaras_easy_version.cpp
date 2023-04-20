#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T, n;
    string s;
    cin >> T;
    while (T--) {
        cin >> s;
        n = s.size();
        int p = -1;
        for (int i = 0; i < n; i++) if (s[i] == 'a') {
            p = i;
            break;
        }
        if (p == -1) {
            cout << s[0] << ' ' << s.substr(1, n - 2) << ' ' << s[n - 1] << '\n';
        } else {
            int q = -1;
            for (int i = 1; i < n - 1; i++) if (s[i] == 'a') {
                q = i;
                break;
            }
            if (q != -1) {
                cout << s.substr(0, q) << ' ' << s[q] << ' ' << s.substr(q + 1, n - q - 1) << '\n';
            } else {
                cout << s[0] << ' ' << s.substr(1, n - 2) << ' ' << s[n - 1] << '\n';
            }
        }
    }
    return 0;
}