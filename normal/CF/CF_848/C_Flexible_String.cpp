#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T, n, k, m;
    string a, b;
    cin >> T;
    while (T--) {
        cin >> n >> k;
        cin >> a >> b;
        vector<char> c;
        for (char ch : a) c.push_back(ch);
        sort(c.begin(), c.end());
        c.erase(unique(c.begin(), c.end()), c.end());
        m = c.size();
        vector<int> sw(26, -1);
        for (int i = 0; i < m; i++) sw[c[i] - 'a'] = i;
        LL ans = 0;
        for (int st = 0; st < (1 << m); st++) {
            int d = 0;
            for (int i = 0; i < m; i++) d += ((st >> i) & 1);
            if (d > k) continue;
            string x = a;
            for (int i = 0; i < n; i++) {
                if ((st >> sw[x[i] - 'a']) & 1) x[i] = b[i];
            }
            // cout << "x= " << x << ", st= " << st << '\n';
            LL tmp = 0;
            for (int i = 0; i < n; i++) if (x[i] == b[i]) {
                int j = i;
                while (i + 1 < n && x[i + 1] == b[i + 1]) i++;
                LL d = i - j + 1;
                // cout << "i= " << i << ", j= " << j << '\n';
                tmp += (d + 1) * d / 2;
                ans = max(ans, tmp);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}