#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    string s, t;
    while (cin >> s >> t) {
        n = s.size(), m = t.size();
        vector<int> L(n + 2, 1), R(n + 2, 1);
        if (s[0] != '?' && t[0] != '?' && s[0] != t[0]) L[1] = 0;
        for (int i = 2; i <= m; i++) {
            if (L[i - 1] == 0) L[i] = 0;
            else {
                if (s[i - 1] != '?' && t[i - 1] != '?' && s[i - 1] != t[i - 1]) L[i] = 0;
                else L[i] = 1;
            }
        }
        if (s[n - 1] != '?' && t[m - 1] != '?' && s[n - 1] != t[m - 1]) R[n] = 0;
        for (int i = n - 1; i >= n - m + 1; i--) {
            if (R[i + 1] == 0) R[i] = 0;
            else {
                // cout << "i= " << i << ' ' << s[i - 1] << ' ' << t[m - n + i - 1] << '\n';
                if (s[i - 1] != '?' && t[m - n + i - 1] != '?' && s[i - 1] != t[m - n + i - 1]) R[i] = 0;
                else R[i] = 1; 
            }
        }
        // cout << L[0] << ' ' << R[2] << ' ' << m - n + 2 - 1 << '\n';
        for (int i = 0; i <= m; i++) {
            if (L[i] && R[n - (m - i) + 1]) cout << "Yes" << '\n';
            else cout << "No" << '\n';
        }
    }
    return 0;
}