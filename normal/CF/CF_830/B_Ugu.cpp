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
        vector<int> L(n + 2, 0), R(n + 2, 0);
        R[n] = 1;
        for (int i = n - 1; i >= 1; i--) {
            if (s[i - 1] == s[i]) R[i] = R[i + 1];
            else R[i] = R[i + 1] + 1;
        }
        L[1] = 1;
        for (int i = 2; i <= n; i++) {
            if (s[i - 1] == s[i - 2]) L[i] = L[i - 1];
            else L[i] = L[i - 1] + 1;
        }
        // for (int i = 1; i <= n; i++) cout << L[i] << ' ';
        // cout << '\n';
        // for (int i = 1; i <= n; i++) cout << R[i] << ' ';
        // cout << '\n';
        int ans = R[1] - 1;
        for (int i = 2; i <= n; i++) {
            int tmp = L[i - 1] - (s[0] == '0');
            int d = (s[i - 1] == '1' && tmp % 2 == 0) | (s[i - 1] == '0' && tmp % 2 == 1);
            tmp += R[i] - d;
            ans = min(ans, tmp);
        }
        cout << ans << '\n';
    }
    return 0;
}