#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T, n;
    string s;
    cin >> T;
    while (T--) {
        cin >> n;
        cin >> s;
        bool flag = 0;
        map<string, int> h;
        for (int i = 1; i < n; i++) {
            string t;
            t.push_back(s[i - 1]);
            t.push_back(s[i]);
            if (h.count(t)) {
                if (h[t] != i - 2) {
                    flag = 1;
                    break;
                }
            } else h[t] = i - 1;
        }
        cout << (flag ? "YES" : "NO") << '\n';
    }
    return 0;
}