#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T, n, m;
    string s;
    cin >> T;
    while (T--) {
        cin >> s >> m;
        n = s.size();

        int e = 0;
        vector<int> R(n, n), a(n, 0);
        a[e++] = 0;
        for (int i = 1; i < n; i++) {
            while (e > 0 && s[i] < s[a[e - 1]]) R[a[--e]] = i;
            a[e++] = i;
        }
        // for (int i = 0; i < n; i++) cout << R[i] << ' ';
        // cout << '\n';
        int p = 0;
        vector<char> ans;
        for (int i = 1; i <= m; i++) {
            if (s[i] != '0' && s[i] < s[p]) p = i;
        }
        ans.push_back(s[p]);
        m -= p;
        // cout << "p= " << p << ", m= " << m << '\n';
        for (int i = p + 1; i < n; i++) {
            // cout << "i= " << i << ", R[i]= " << R[i] << '\n';
            if (m == 0) {
                for (int j = i; j < n; j++) ans.push_back(s[j]);
                break;
            }
            if (R[i] - i > m) ans.push_back(s[i]);
            else {
                m -= R[i] - i;
                i = R[i] - 1;
            }
        }
        for (int i = 0; i < ans.size() - m; i++) cout << ans[i];
        cout << '\n';
    }
    return 0;
}