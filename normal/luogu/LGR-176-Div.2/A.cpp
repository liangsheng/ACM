#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    map<char, int> m;
    m['P'] = 3, m['p'] = 2, m['G'] = 1;
    int T, n, l, r, k;
    string s;
    cin >> T;
    while (T--) {
        cin >> s;
        n = s.size();
        vector<int> a(n + 1, 0);
        for (int i = 1; i <= n; i++) a[i] = a[i - 1] + m[s[i - 1]];
        // for (int i = 1; i <= n; i++) cout << a[i] << ' ';
        // cout << '\n';
        cin >> k;
        while (k--) {
            cin >> l >> r;
            cout << a[r] - a[l - 1] << '\n';
        }
    }
    return 0;
}