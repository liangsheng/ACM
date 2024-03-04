#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    string s;
    cin >> s;
    LL n = s.size(), ans = 0;
    vector<int> a;
    if (n == 1) cout << 0 << '\n';
    else {
        LL l = max(1LL, n / 2 - 3), r = min(n / 2 + 3, n - 1);
        for (int i = l; i <= r; i++) {
            vector<int> b;
            vector<int> t(n + 1);
            for (int j = 1; j <= n; j++) t[j] = (s[j - 1] == '1');
            for (int j = 1; j <= i; j++) if (t[j] == 1) {
                b.push_back(j);
                t[j] ^= 1, t[j + 1] ^= 1;
            }
            for (int j = i + 1; j <= n; j++) if (t[j] == 0 && j != n) {
                b.push_back(j);
                t[j] ^= 1, t[j + 1] ^= 1;
            }
            LL tmp = (LL) i * (n - i - (t[n] == 0));
            // printf("i= %d, tmp= %d\n", i, tmp);
            if (tmp > ans) {
                ans = tmp;
                a = b;
            }
        }
        cout << ans << '\n';
        int m = a.size();
        cout << m << '\n';
        for (int i = 0; i < m; i++) cout << a[i] << " \n"[i == m - 1];
    }
    return 0;
}