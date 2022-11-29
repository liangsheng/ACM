#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    while (cin >> n) {
        string s, t, a;
        cin >> s >> t;
        a = s;

        vector<int> d;
        for (int i = 0; i < n; i++) {
            if (s[i] != t[i]) d.push_back(i);
            else a[i] = '0';
        }
        if (d.size() % 2) {
            cout << -1 << '\n';
            continue;
        }
        int cs = d.size() / 2, ct = cs;
        for (int p : d) {
            if (cs > 0 && s[p] == '0') a[p] = s[p], cs--;
            else if (ct > 0 && t[p] == '0') a[p] = t[p], ct--;
            else {
                a[p] = '1';
                if (s[p] == '1') cs--;
                else ct--;
            }
        }
        cout << a << '\n';
    }
    return 0;
}